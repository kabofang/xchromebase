/*
 * Copyright (C) 2019 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef SRC_TRACE_PROCESSOR_DB_COLUMN_H_
#define SRC_TRACE_PROCESSOR_DB_COLUMN_H_

#include <stdint.h>

#include "perfetto/base/logging.h"
#include "perfetto/ext/base/optional.h"
#include "perfetto/trace_processor/basic_types.h"
#include "src/trace_processor/containers/nullable_vector.h"
#include "src/trace_processor/containers/row_map.h"
#include "src/trace_processor/containers/string_pool.h"
#include "src/trace_processor/db/compare.h"

namespace perfetto {
namespace trace_processor {

// Id type which can be used as a base for strongly typed ids.
// TypedColumn has support for storing descendents of BaseId seamlessly
// in a Column.
struct BaseId {
  BaseId() = default;
  explicit constexpr BaseId(uint32_t v) : value(v) {}

  bool operator==(const BaseId& o) const { return o.value == value; }
  bool operator!=(const BaseId& o) const { return !(*this == o); }
  bool operator<(const BaseId& o) const { return value < o.value; }

  uint32_t value;
};
static_assert(std::is_trivially_destructible<BaseId>::value,
              "Inheritance used without trivial destruction");

// Represents the possible filter operations on a column.
enum class FilterOp {
  kEq,
  kNe,
  kGt,
  kLt,
  kGe,
  kLe,
  kIsNull,
  kIsNotNull,
};

// Represents a constraint on a column.
struct Constraint {
  uint32_t col_idx;
  FilterOp op;
  SqlValue value;
};

// Represents an order by operation on a column.
struct Order {
  uint32_t col_idx;
  bool desc;
};

// The enum type of the column.
// Public only to stop GCC complaining about templates being defined in a
// non-namespace scope (see ColumnTypeHelper below).
enum class ColumnType {
  // Standard primitive types.
  kInt32,
  kUint32,
  kInt64,
  kDouble,
  kString,

  // Types generated on the fly.
  kId,

  // Types which don't have any data backing them.
  kDummy,
};

// Helper class for converting a type to a ColumnType.
template <typename T>
struct ColumnTypeHelper;
template <>
struct ColumnTypeHelper<int32_t> {
  static constexpr ColumnType ToColumnType() { return ColumnType::kInt32; }
};
template <>
struct ColumnTypeHelper<uint32_t> {
  static constexpr ColumnType ToColumnType() { return ColumnType::kUint32; }
};
template <>
struct ColumnTypeHelper<int64_t> {
  static constexpr ColumnType ToColumnType() { return ColumnType::kInt64; }
};
template <>
struct ColumnTypeHelper<double> {
  static constexpr ColumnType ToColumnType() { return ColumnType::kDouble; }
};
template <>
struct ColumnTypeHelper<StringPool::Id> {
  static constexpr ColumnType ToColumnType() { return ColumnType::kString; }
};

class Table;

// Represents a named, strongly typed list of data.
class Column {
 public:
  // Flags which indicate properties of the data in the column. These features
  // are used to speed up column methods like filtering/sorting.
  enum Flag : uint32_t {
    // Indicates that this column has no special properties.
    kNoFlag = 0,

    // Indicates the data in the column is sorted. This can be used to speed
    // up filtering and skip sorting.
    kSorted = 1 << 0,

    // Indicates the data in the column is non-null. That is, the NullableVector
    // passed in will never have any null entries. This is only used for
    // numeric columns (string columns and id columns both have special
    // handling which ignores this flag).
    //
    // This is used to speed up filters as we can safely index NullableVector
    // directly if this flag is set.
    kNonNull = 1 << 1,

    // Indicates that the data in the column is "hidden". This can by used to
    // hint to users of Table and Column that this column should not be
    // displayed to the user as it is part of the internal implementation
    // details of the table.
    kHidden = 1 << 2,

    // Indicates that the data in this column is stored densely. This
    // allows for fast Set calls to change the data in the column.
    //
    // This flag is only meaningful for nullable columns has no effect for
    // non-null columns.
    kDense = 1 << 3,

    // Indicates that the sorted numeric data in the column is laid out such
    // that at row i, we will always have col[i] <= i and the first element, j
    // of each group happens at the index j.
    //
    // This is a common pattern in trace processor and columns with this
    // property are suffixed with "set_id" hence the name of this flag.
    //
    // To make this clear, here are some valid and invalid uses of this flag.
    //
    // Valid:
    // []
    // [0]
    // [0, 1, 2]
    // [0, 0, 2]
    // [0, 0, 0, 3, 3, 5, 6, 6, 7]
    //
    // Invalid:
    // [1]
    // [0, 0, 1]
    // [0, 0, 2, 5]
    // [0, 0, 2, 1]
    //
    // If this flag is set, kSorted and kNonNull should be set. Moreover, this
    // flag can only be set when the type is ColumnType::kUint32; other types
    // are not supported.
    kSetId = 1 << 4,
  };

  // Iterator over a column which conforms to std iterator interface
  // to allow using std algorithms (e.g. upper_bound, lower_bound etc.).
  class Iterator {
   public:
    using iterator_category = std::random_access_iterator_tag;
    using value_type = SqlValue;
    using difference_type = uint32_t;
    using pointer = uint32_t*;
    using reference = uint32_t&;

    Iterator(const Column* col, uint32_t row) : col_(col), row_(row) {}

    Iterator(const Iterator&) = default;
    Iterator& operator=(const Iterator&) = default;

    bool operator==(const Iterator& other) const { return other.row_ == row_; }
    bool operator!=(const Iterator& other) const { return !(*this == other); }
    bool operator<(const Iterator& other) const { return row_ < other.row_; }
    bool operator>(const Iterator& other) const { return other < *this; }
    bool operator<=(const Iterator& other) const { return !(other < *this); }
    bool operator>=(const Iterator& other) const { return !(*this < other); }

    SqlValue operator*() const { return col_->Get(row_); }
    Iterator& operator++() {
      row_++;
      return *this;
    }
    Iterator& operator--() {
      row_--;
      return *this;
    }

    Iterator& operator+=(uint32_t diff) {
      row_ += diff;
      return *this;
    }
    uint32_t operator-(const Iterator& other) const {
      return row_ - other.row_;
    }

    uint32_t row() const { return row_; }

   private:
    const Column* col_ = nullptr;
    uint32_t row_ = 0;
  };

  // Flags specified for an id column.
  static constexpr uint32_t kIdFlags = Flag::kSorted | Flag::kNonNull;

  // Flags which should *not* be inherited implicitly when a column is
  // assocaited to another table.
  static constexpr uint32_t kNoCrossTableInheritFlags = Column::Flag::kSetId;

  template <typename T>
  Column(const char* name,
         NullableVector<T>* storage,
         /* Flag */ uint32_t flags,
         Table* table,
         uint32_t col_idx_in_table,
         uint32_t row_map_idx)
      : Column(name,
               ColumnTypeHelper<T>::ToColumnType(),
               flags,
               table,
               col_idx_in_table,
               row_map_idx,
               storage) {}

  // Create a Column backed by the same data as |column| but is associated to a
  // different table and, optionally, having a different name.
  Column(const Column& column,
         Table* table,
         uint32_t col_idx_in_table,
         uint32_t row_map_idx,
         const char* name = nullptr);

  // Columns are movable but not copyable.
  Column(Column&&) noexcept = default;
  Column& operator=(Column&&) = default;

  // Creates a Column which does not have any data backing it.
  static Column DummyColumn(const char* name,
                            Table* table,
                            uint32_t col_idx_in_table);

  // Creates a Column which returns the index as the value of the row.
  static Column IdColumn(Table* table,
                         uint32_t col_idx_in_table,
                         uint32_t row_map_idx);

  // Gets the value of the Column at the given |row|.
  SqlValue Get(uint32_t row) const { return GetAtIdx(row_map().Get(row)); }

  // Returns the row containing the given value in the Column.
  base::Optional<uint32_t> IndexOf(SqlValue value) const {
    switch (type_) {
      // TODO(lalitm): investigate whether we could make this more efficient
      // by first checking the type of the column and comparing explicitly
      // based on that type.
      case ColumnType::kInt32:
      case ColumnType::kUint32:
      case ColumnType::kInt64:
      case ColumnType::kDouble:
      case ColumnType::kString: {
        for (uint32_t i = 0; i < row_map().size(); i++) {
          if (compare::SqlValue(Get(i), value) == 0)
            return i;
        }
        return base::nullopt;
      }
      case ColumnType::kId: {
        if (value.type != SqlValue::Type::kLong)
          return base::nullopt;
        return row_map().RowOf(static_cast<uint32_t>(value.long_value));
      }
      case ColumnType::kDummy:
        PERFETTO_FATAL("IndexOf not allowed on dummy column");
    }
    PERFETTO_FATAL("For GCC");
  }

  // Sets the value of the column at the given |row|.
  void Set(uint32_t row, SqlValue value) {
    PERFETTO_CHECK(value.type == type());
    switch (type_) {
      case ColumnType::kInt32: {
        mutable_nullable_vector<int32_t>()->Set(
            row, static_cast<int32_t>(value.long_value));
        break;
      }
      case ColumnType::kUint32: {
        mutable_nullable_vector<uint32_t>()->Set(
            row, static_cast<uint32_t>(value.long_value));
        break;
      }
      case ColumnType::kInt64: {
        mutable_nullable_vector<int64_t>()->Set(
            row, static_cast<int64_t>(value.long_value));
        break;
      }
      case ColumnType::kDouble: {
        mutable_nullable_vector<double>()->Set(row, value.double_value);
        break;
      }
      case ColumnType::kString: {
        PERFETTO_FATAL(
            "Setting a generic value on a string column is not implemented");
      }
      case ColumnType::kId: {
        PERFETTO_FATAL("Cannot set value on a id column");
      }
      case ColumnType::kDummy:
        PERFETTO_FATAL("Set not allowed on dummy column");
    }
  }

  // Sorts |idx| in ascending or descending order (determined by |desc|) based
  // on the contents of this column.
  void StableSort(bool desc, std::vector<uint32_t>* idx) const;

  // Updates the given RowMap by only keeping rows where this column meets the
  // given filter constraint.
  void FilterInto(FilterOp op, SqlValue value, RowMap* rm) const {
    if (IsId() && op == FilterOp::kEq) {
      // If this is an equality constraint on an id column, try and find the
      // single row with the id (if it exists).
      auto opt_idx = IndexOf(value);
      if (opt_idx) {
        rm->Intersect(RowMap::SingleRow(*opt_idx));
      } else {
        rm->Intersect(RowMap());
      }
      return;
    }

    if (IsSetId() && op == FilterOp::kEq && value.type == SqlValue::kLong) {
      // If the column is sorted and the value has the same type as the column,
      // we should be able to just do a binary search to find the range of rows
      // instead of a full table scan.
      FilterIntoSetIdEq(value.AsLong(), rm);
      return;
    }

    if (IsSorted() && value.type == type()) {
      // If the column is sorted and the value has the same type as the column,
      // we should be able to just do a binary search to find the range of rows
      // instead of a full table scan.
      bool handled = FilterIntoSorted(op, value, rm);
      if (handled)
        return;
    }

    FilterIntoSlow(op, value, rm);
  }

  // Returns the minimum value in this column. Returns nullopt if this column
  // is empty.
  base::Optional<SqlValue> Min() const {
    if (row_map().empty())
      return base::nullopt;

    if (IsSorted())
      return Get(0);

    Iterator b(this, 0);
    Iterator e(this, row_map().size());
    return *std::min_element(b, e, &compare::SqlValueComparator);
  }

  // Returns the minimum value in this column. Returns nullopt if this column
  // is empty.
  base::Optional<SqlValue> Max() const {
    if (row_map().empty())
      return base::nullopt;

    if (IsSorted())
      return Get(row_map().size() - 1);

    Iterator b(this, 0);
    Iterator e(this, row_map().size());
    return *std::max_element(b, e, &compare::SqlValueComparator);
  }

  // Returns the backing RowMap for this Column.
  // This function is defined out of line because of a circular dependency
  // between |Table| and |Column|.
  const RowMap& row_map() const;

  // Returns the name of the column.
  const char* name() const { return name_; }

  // Returns the type of this Column in terms of SqlValue::Type.
  SqlValue::Type type() const { return ToSqlValueType(type_); }

  // Test the type of this Column.
  template <typename T>
  bool IsColumnType() const {
    return ColumnTypeHelper<T>::ToColumnType() == type_;
  }

  // Returns true if this column is considered an id column.
  bool IsId() const { return type_ == ColumnType::kId; }

  // Returns true if this column is a nullable column.
  bool IsNullable() const { return IsNullable(flags_); }

  // Returns true if this column is a sorted column.
  bool IsSorted() const { return IsSorted(flags_); }

  // Public for testing.
  bool IsSetId() const { return IsSetId(flags_); }

  // Returns the index of the RowMap in the containing table.
  uint32_t row_map_index() const { return row_map_idx_; }

  // Returns the index of the current column in the containing table.
  uint32_t index_in_table() const { return col_idx_in_table_; }

  // Returns a Constraint for each type of filter operation for this Column.
  Constraint eq_value(SqlValue value) const {
    return Constraint{col_idx_in_table_, FilterOp::kEq, value};
  }
  Constraint gt_value(SqlValue value) const {
    return Constraint{col_idx_in_table_, FilterOp::kGt, value};
  }
  Constraint lt_value(SqlValue value) const {
    return Constraint{col_idx_in_table_, FilterOp::kLt, value};
  }
  Constraint ne_value(SqlValue value) const {
    return Constraint{col_idx_in_table_, FilterOp::kNe, value};
  }
  Constraint ge_value(SqlValue value) const {
    return Constraint{col_idx_in_table_, FilterOp::kGe, value};
  }
  Constraint le_value(SqlValue value) const {
    return Constraint{col_idx_in_table_, FilterOp::kLe, value};
  }
  Constraint is_not_null() const {
    return Constraint{col_idx_in_table_, FilterOp::kIsNotNull, SqlValue()};
  }
  Constraint is_null() const {
    return Constraint{col_idx_in_table_, FilterOp::kIsNull, SqlValue()};
  }

  // Returns an Order for each Order type for this Column.
  Order ascending() const { return Order{col_idx_in_table_, false}; }
  Order descending() const { return Order{col_idx_in_table_, true}; }

  // Returns an iterator to the first entry in this column.
  Iterator begin() const { return Iterator(this, 0); }

  // Returns an iterator pointing beyond the last entry in this column.
  Iterator end() const { return Iterator(this, row_map().size()); }

  // Returns whether the given combination of flags when the column has the
  // given type is valid.
  template <typename T>
  static constexpr bool IsFlagsAndTypeValid(uint32_t flags) {
    return IsFlagsAndTypeValid(flags, ColumnTypeHelper<T>::ToColumnType());
  }

 protected:
  // Returns the backing sparse vector cast to contain data of type T.
  // Should only be called when |type_| == ToColumnType<T>().
  template <typename T>
  NullableVector<T>* mutable_nullable_vector() {
    PERFETTO_DCHECK(ColumnTypeHelper<T>::ToColumnType() == type_);
    return static_cast<NullableVector<T>*>(nullable_vector_);
  }

  // Returns the backing sparse vector cast to contain data of type T.
  // Should only be called when |type_| == ToColumnType<T>().
  template <typename T>
  const NullableVector<T>& nullable_vector() const {
    PERFETTO_DCHECK(ColumnTypeHelper<T>::ToColumnType() == type_);
    return *static_cast<const NullableVector<T>*>(nullable_vector_);
  }

  // Returns the type of this Column in terms of SqlValue::Type.
  template <typename T>
  static SqlValue::Type ToSqlValueType() {
    return ToSqlValueType(ColumnTypeHelper<T>::ToColumnType());
  }

  // Returns true if this column is a dummy column.
  bool IsDummy() const { return type_ == ColumnType::kDummy; }

  // Returns true if this column is a dense column.
  bool IsDense() const { return IsDense(flags_); }

  // Returns true if this column is a hidden column.
  bool IsHidden() const { return (flags_ & Flag::kHidden) != 0; }

  const StringPool& string_pool() const { return *string_pool_; }

 private:
  friend class Table;

  // Base constructor for this class which all other constructors call into.
  Column(const char* name,
         ColumnType type,
         uint32_t flags,
         Table* table,
         uint32_t col_idx_in_table,
         uint32_t row_map_idx,
         NullableVectorBase* nullable_vector);

  Column(const Column&) = delete;
  Column& operator=(const Column&) = delete;

  // Gets the value of the Column at the given |idx|.
  SqlValue GetAtIdx(uint32_t idx) const {
    switch (type_) {
      case ColumnType::kInt32: {
        auto opt_value = nullable_vector<int32_t>().Get(idx);
        return opt_value ? SqlValue::Long(*opt_value) : SqlValue();
      }
      case ColumnType::kUint32: {
        auto opt_value = nullable_vector<uint32_t>().Get(idx);
        return opt_value ? SqlValue::Long(*opt_value) : SqlValue();
      }
      case ColumnType::kInt64: {
        auto opt_value = nullable_vector<int64_t>().Get(idx);
        return opt_value ? SqlValue::Long(*opt_value) : SqlValue();
      }
      case ColumnType::kDouble: {
        auto opt_value = nullable_vector<double>().Get(idx);
        return opt_value ? SqlValue::Double(*opt_value) : SqlValue();
      }
      case ColumnType::kString: {
        auto str = GetStringPoolStringAtIdx(idx).c_str();
        return str == nullptr ? SqlValue() : SqlValue::String(str);
      }
      case ColumnType::kId:
        return SqlValue::Long(idx);
      case ColumnType::kDummy:
        PERFETTO_FATAL("GetAtIdx not allowed on dummy column");
    }
    PERFETTO_FATAL("For GCC");
  }

  // Optimized filter method for sorted columns.
  // Returns whether the constraint was handled by the method.
  bool FilterIntoSorted(FilterOp op, SqlValue value, RowMap* rm) const {
    PERFETTO_DCHECK(IsSorted());
    PERFETTO_DCHECK(value.type == type());

    Iterator b(this, 0);
    Iterator e(this, row_map().size());
    switch (op) {
      case FilterOp::kEq: {
        uint32_t beg = std::distance(
            b, std::lower_bound(b, e, value, &compare::SqlValueComparator));
        uint32_t end = std::distance(
            b, std::upper_bound(b, e, value, &compare::SqlValueComparator));
        rm->Intersect(RowMap(beg, end));
        return true;
      }
      case FilterOp::kLe: {
        uint32_t end = std::distance(
            b, std::upper_bound(b, e, value, &compare::SqlValueComparator));
        rm->Intersect(RowMap(0, end));
        return true;
      }
      case FilterOp::kLt: {
        uint32_t end = std::distance(
            b, std::lower_bound(b, e, value, &compare::SqlValueComparator));
        rm->Intersect(RowMap(0, end));
        return true;
      }
      case FilterOp::kGe: {
        uint32_t beg = std::distance(
            b, std::lower_bound(b, e, value, &compare::SqlValueComparator));
        rm->Intersect(RowMap(beg, row_map().size()));
        return true;
      }
      case FilterOp::kGt: {
        uint32_t beg = std::distance(
            b, std::upper_bound(b, e, value, &compare::SqlValueComparator));
        rm->Intersect(RowMap(beg, row_map().size()));
        return true;
      }
      case FilterOp::kNe:
      case FilterOp::kIsNull:
      case FilterOp::kIsNotNull:
        break;
    }
    return false;
  }

  void FilterIntoSetIdEq(int64_t value, RowMap* rm) const {
    PERFETTO_DCHECK(!IsNullable());

    uint32_t filter_set_id = static_cast<uint32_t>(value);
    const auto& nv = nullable_vector<uint32_t>();
    const RowMap& col_rm = row_map();

    // If the set id is beyond the end of the column, there's no chance that
    // it exists.
    if (PERFETTO_UNLIKELY(filter_set_id >= col_rm.size())) {
      *rm = RowMap();
      return;
    }

    uint32_t set_id = nv.GetNonNull(col_rm.Get(filter_set_id));

    // If the set at that index does not equal the set id we're looking for, the
    // set id doesn't exist either.
    if (PERFETTO_UNLIKELY(set_id != filter_set_id)) {
      PERFETTO_DCHECK(set_id < filter_set_id);
      *rm = RowMap();
      return;
    }

    // Otherwise, find the end of the set and return the intersection for this.
    for (uint32_t i = set_id + 1; i < col_rm.size(); ++i) {
      if (nv.GetNonNull(col_rm.Get(i)) != filter_set_id) {
        rm->Intersect(RowMap(set_id, i));
        return;
      }
    }
    rm->Intersect(RowMap(set_id, col_rm.size()));
  }

  // Slow path filter method which will perform a full table scan.
  void FilterIntoSlow(FilterOp op, SqlValue value, RowMap* rm) const;

  // Slow path filter method for numerics which will perform a full table scan.
  template <typename T, bool is_nullable>
  void FilterIntoNumericSlow(FilterOp op, SqlValue value, RowMap* rm) const;

  // Slow path filter method for numerics with a comparator which will perform a
  // full table scan.
  template <typename T, bool is_nullable, typename Comparator = int(T)>
  void FilterIntoNumericWithComparatorSlow(FilterOp op,
                                           RowMap* rm,
                                           Comparator cmp) const;

  // Slow path filter method for strings which will perform a full table scan.
  void FilterIntoStringSlow(FilterOp op, SqlValue value, RowMap* rm) const;

  // Slow path filter method for ids which will perform a full table scan.
  void FilterIntoIdSlow(FilterOp op, SqlValue value, RowMap* rm) const;

  // Stable sorts this column storing the result in |out|.
  template <bool desc>
  void StableSort(std::vector<uint32_t>* out) const;

  // Stable sorts this column storing the result in |out|.
  // |T| and |is_nullable| should match the type and nullability of this column.
  template <bool desc, typename T, bool is_nullable>
  void StableSortNumeric(std::vector<uint32_t>* out) const;

  static constexpr bool IsDense(uint32_t flags) {
    return (flags & Flag::kDense) != 0;
  }
  static constexpr bool IsNullable(uint32_t flags) {
    return (flags & Flag::kNonNull) == 0;
  }
  static constexpr bool IsSetId(uint32_t flags) {
    return (flags & Flag::kSetId) != 0;
  }
  static constexpr bool IsSorted(uint32_t flags) {
    return (flags & Flag::kSorted) != 0;
  }

  static constexpr bool IsFlagsAndTypeValid(uint32_t flags, ColumnType type) {
    return (!IsDense(flags) || IsFlagsForDenseValid(flags)) &&
           (!IsSetId(flags) || IsFlagsAndTypeForSetIdValid(flags, type));
  }

  static constexpr bool IsFlagsForDenseValid(uint32_t flags) {
    // The dense flag should only be set when the column is nullable.
    return IsNullable(flags);
  }

  static constexpr bool IsFlagsAndTypeForSetIdValid(uint32_t flags,
                                                    ColumnType type) {
    // The sorted flag should always be set for set id columns.
    // The non-null flag should always be set for set id columns.
    // The column type should always be kUint32.
    return IsSorted(flags) && !IsNullable(flags) && type == ColumnType::kUint32;
  }

  static SqlValue::Type ToSqlValueType(ColumnType type) {
    switch (type) {
      case ColumnType::kInt32:
      case ColumnType::kUint32:
      case ColumnType::kInt64:
      case ColumnType::kId:
        return SqlValue::Type::kLong;
      case ColumnType::kDouble:
        return SqlValue::Type::kDouble;
      case ColumnType::kString:
        return SqlValue::Type::kString;
      case ColumnType::kDummy:
        PERFETTO_FATAL("ToSqlValueType not allowed on dummy column");
    }
    PERFETTO_FATAL("For GCC");
  }

  // Returns the string at the index |idx|.
  // Should only be called when |type_| == ColumnType::kString.
  NullTermStringView GetStringPoolStringAtIdx(uint32_t idx) const {
    PERFETTO_DCHECK(type_ == ColumnType::kString);
    return string_pool_->Get(nullable_vector<StringPool::Id>().GetNonNull(idx));
  }

  // type_ is used to cast nullable_vector_ to the correct type.
  ColumnType type_ = ColumnType::kInt64;
  NullableVectorBase* nullable_vector_ = nullptr;

  const char* name_ = nullptr;
  uint32_t flags_ = Flag::kNoFlag;
  const Table* table_ = nullptr;
  uint32_t col_idx_in_table_ = 0;
  uint32_t row_map_idx_ = 0;
  const StringPool* string_pool_ = nullptr;
};

}  // namespace trace_processor
}  // namespace perfetto

#endif  // SRC_TRACE_PROCESSOR_DB_COLUMN_H_
