// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: protos/perfetto/config/inode_file/inode_file_config.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_protos_2fperfetto_2fconfig_2finode_5ffile_2finode_5ffile_5fconfig_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_protos_2fperfetto_2fconfig_2finode_5ffile_2finode_5ffile_5fconfig_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3013000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3013000 < PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers. Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/port_undef.inc>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/inlined_string_field.h>
#include <google/protobuf/metadata_lite.h>
#include <google/protobuf/message_lite.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_protos_2fperfetto_2fconfig_2finode_5ffile_2finode_5ffile_5fconfig_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_protos_2fperfetto_2fconfig_2finode_5ffile_2finode_5ffile_5fconfig_2eproto {
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTableField entries[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::AuxiliaryParseTableField aux[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTable schema[2]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::FieldMetadata field_metadata[];
  static const ::PROTOBUF_NAMESPACE_ID::internal::SerializationTable serialization_table[];
  static const ::PROTOBUF_NAMESPACE_ID::uint32 offsets[];
};
namespace perfetto {
namespace protos {
class InodeFileConfig;
class InodeFileConfigDefaultTypeInternal;
extern InodeFileConfigDefaultTypeInternal _InodeFileConfig_default_instance_;
class InodeFileConfig_MountPointMappingEntry;
class InodeFileConfig_MountPointMappingEntryDefaultTypeInternal;
extern InodeFileConfig_MountPointMappingEntryDefaultTypeInternal _InodeFileConfig_MountPointMappingEntry_default_instance_;
}  // namespace protos
}  // namespace perfetto
PROTOBUF_NAMESPACE_OPEN
template<> ::perfetto::protos::InodeFileConfig* Arena::CreateMaybeMessage<::perfetto::protos::InodeFileConfig>(Arena*);
template<> ::perfetto::protos::InodeFileConfig_MountPointMappingEntry* Arena::CreateMaybeMessage<::perfetto::protos::InodeFileConfig_MountPointMappingEntry>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace perfetto {
namespace protos {

// ===================================================================

class InodeFileConfig_MountPointMappingEntry PROTOBUF_FINAL :
    public ::PROTOBUF_NAMESPACE_ID::MessageLite /* @@protoc_insertion_point(class_definition:perfetto.protos.InodeFileConfig.MountPointMappingEntry) */ {
 public:
  inline InodeFileConfig_MountPointMappingEntry() : InodeFileConfig_MountPointMappingEntry(nullptr) {}
  virtual ~InodeFileConfig_MountPointMappingEntry();

  InodeFileConfig_MountPointMappingEntry(const InodeFileConfig_MountPointMappingEntry& from);
  InodeFileConfig_MountPointMappingEntry(InodeFileConfig_MountPointMappingEntry&& from) noexcept
    : InodeFileConfig_MountPointMappingEntry() {
    *this = ::std::move(from);
  }

  inline InodeFileConfig_MountPointMappingEntry& operator=(const InodeFileConfig_MountPointMappingEntry& from) {
    CopyFrom(from);
    return *this;
  }
  inline InodeFileConfig_MountPointMappingEntry& operator=(InodeFileConfig_MountPointMappingEntry&& from) noexcept {
    if (GetArena() == from.GetArena()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  inline const std::string& unknown_fields() const {
    return _internal_metadata_.unknown_fields<std::string>(::PROTOBUF_NAMESPACE_ID::internal::GetEmptyString);
  }
  inline std::string* mutable_unknown_fields() {
    return _internal_metadata_.mutable_unknown_fields<std::string>();
  }

  static const InodeFileConfig_MountPointMappingEntry& default_instance();

  static inline const InodeFileConfig_MountPointMappingEntry* internal_default_instance() {
    return reinterpret_cast<const InodeFileConfig_MountPointMappingEntry*>(
               &_InodeFileConfig_MountPointMappingEntry_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(InodeFileConfig_MountPointMappingEntry& a, InodeFileConfig_MountPointMappingEntry& b) {
    a.Swap(&b);
  }
  PROTOBUF_NOINLINE void Swap(InodeFileConfig_MountPointMappingEntry* other) {
    if (other == this) return;
    if (GetArena() == other->GetArena()) {
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(InodeFileConfig_MountPointMappingEntry* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetArena() == other->GetArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline InodeFileConfig_MountPointMappingEntry* New() const final {
    return CreateMaybeMessage<InodeFileConfig_MountPointMappingEntry>(nullptr);
  }

  InodeFileConfig_MountPointMappingEntry* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<InodeFileConfig_MountPointMappingEntry>(arena);
  }
  void CheckTypeAndMergeFrom(const ::PROTOBUF_NAMESPACE_ID::MessageLite& from)
    final;
  void CopyFrom(const InodeFileConfig_MountPointMappingEntry& from);
  void MergeFrom(const InodeFileConfig_MountPointMappingEntry& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  ::PROTOBUF_NAMESPACE_ID::uint8* _InternalSerialize(
      ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  void DiscardUnknownFields();
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  inline void SharedCtor();
  inline void SharedDtor();
  void SetCachedSize(int size) const;
  void InternalSwap(InodeFileConfig_MountPointMappingEntry* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "perfetto.protos.InodeFileConfig.MountPointMappingEntry";
  }
  protected:
  explicit InodeFileConfig_MountPointMappingEntry(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  std::string GetTypeName() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kScanRootsFieldNumber = 2,
    kMountpointFieldNumber = 1,
  };
  // repeated string scan_roots = 2;
  int scan_roots_size() const;
  private:
  int _internal_scan_roots_size() const;
  public:
  void clear_scan_roots();
  const std::string& scan_roots(int index) const;
  std::string* mutable_scan_roots(int index);
  void set_scan_roots(int index, const std::string& value);
  void set_scan_roots(int index, std::string&& value);
  void set_scan_roots(int index, const char* value);
  void set_scan_roots(int index, const char* value, size_t size);
  std::string* add_scan_roots();
  void add_scan_roots(const std::string& value);
  void add_scan_roots(std::string&& value);
  void add_scan_roots(const char* value);
  void add_scan_roots(const char* value, size_t size);
  const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField<std::string>& scan_roots() const;
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField<std::string>* mutable_scan_roots();
  private:
  const std::string& _internal_scan_roots(int index) const;
  std::string* _internal_add_scan_roots();
  public:

  // optional string mountpoint = 1;
  bool has_mountpoint() const;
  private:
  bool _internal_has_mountpoint() const;
  public:
  void clear_mountpoint();
  const std::string& mountpoint() const;
  void set_mountpoint(const std::string& value);
  void set_mountpoint(std::string&& value);
  void set_mountpoint(const char* value);
  void set_mountpoint(const char* value, size_t size);
  std::string* mutable_mountpoint();
  std::string* release_mountpoint();
  void set_allocated_mountpoint(std::string* mountpoint);
  private:
  const std::string& _internal_mountpoint() const;
  void _internal_set_mountpoint(const std::string& value);
  std::string* _internal_mutable_mountpoint();
  public:

  // @@protoc_insertion_point(class_scope:perfetto.protos.InodeFileConfig.MountPointMappingEntry)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::internal::HasBits<1> _has_bits_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField<std::string> scan_roots_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr mountpoint_;
  friend struct ::TableStruct_protos_2fperfetto_2fconfig_2finode_5ffile_2finode_5ffile_5fconfig_2eproto;
};
// -------------------------------------------------------------------

class InodeFileConfig PROTOBUF_FINAL :
    public ::PROTOBUF_NAMESPACE_ID::MessageLite /* @@protoc_insertion_point(class_definition:perfetto.protos.InodeFileConfig) */ {
 public:
  inline InodeFileConfig() : InodeFileConfig(nullptr) {}
  virtual ~InodeFileConfig();

  InodeFileConfig(const InodeFileConfig& from);
  InodeFileConfig(InodeFileConfig&& from) noexcept
    : InodeFileConfig() {
    *this = ::std::move(from);
  }

  inline InodeFileConfig& operator=(const InodeFileConfig& from) {
    CopyFrom(from);
    return *this;
  }
  inline InodeFileConfig& operator=(InodeFileConfig&& from) noexcept {
    if (GetArena() == from.GetArena()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  inline const std::string& unknown_fields() const {
    return _internal_metadata_.unknown_fields<std::string>(::PROTOBUF_NAMESPACE_ID::internal::GetEmptyString);
  }
  inline std::string* mutable_unknown_fields() {
    return _internal_metadata_.mutable_unknown_fields<std::string>();
  }

  static const InodeFileConfig& default_instance();

  static inline const InodeFileConfig* internal_default_instance() {
    return reinterpret_cast<const InodeFileConfig*>(
               &_InodeFileConfig_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    1;

  friend void swap(InodeFileConfig& a, InodeFileConfig& b) {
    a.Swap(&b);
  }
  PROTOBUF_NOINLINE void Swap(InodeFileConfig* other) {
    if (other == this) return;
    if (GetArena() == other->GetArena()) {
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(InodeFileConfig* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetArena() == other->GetArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline InodeFileConfig* New() const final {
    return CreateMaybeMessage<InodeFileConfig>(nullptr);
  }

  InodeFileConfig* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<InodeFileConfig>(arena);
  }
  void CheckTypeAndMergeFrom(const ::PROTOBUF_NAMESPACE_ID::MessageLite& from)
    final;
  void CopyFrom(const InodeFileConfig& from);
  void MergeFrom(const InodeFileConfig& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  ::PROTOBUF_NAMESPACE_ID::uint8* _InternalSerialize(
      ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  void DiscardUnknownFields();
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  inline void SharedCtor();
  inline void SharedDtor();
  void SetCachedSize(int size) const;
  void InternalSwap(InodeFileConfig* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "perfetto.protos.InodeFileConfig";
  }
  protected:
  explicit InodeFileConfig(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  std::string GetTypeName() const final;

  // nested types ----------------------------------------------------

  typedef InodeFileConfig_MountPointMappingEntry MountPointMappingEntry;

  // accessors -------------------------------------------------------

  enum : int {
    kScanMountPointsFieldNumber = 5,
    kMountPointMappingFieldNumber = 6,
    kScanIntervalMsFieldNumber = 1,
    kScanDelayMsFieldNumber = 2,
    kScanBatchSizeFieldNumber = 3,
    kDoNotScanFieldNumber = 4,
  };
  // repeated string scan_mount_points = 5;
  int scan_mount_points_size() const;
  private:
  int _internal_scan_mount_points_size() const;
  public:
  void clear_scan_mount_points();
  const std::string& scan_mount_points(int index) const;
  std::string* mutable_scan_mount_points(int index);
  void set_scan_mount_points(int index, const std::string& value);
  void set_scan_mount_points(int index, std::string&& value);
  void set_scan_mount_points(int index, const char* value);
  void set_scan_mount_points(int index, const char* value, size_t size);
  std::string* add_scan_mount_points();
  void add_scan_mount_points(const std::string& value);
  void add_scan_mount_points(std::string&& value);
  void add_scan_mount_points(const char* value);
  void add_scan_mount_points(const char* value, size_t size);
  const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField<std::string>& scan_mount_points() const;
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField<std::string>* mutable_scan_mount_points();
  private:
  const std::string& _internal_scan_mount_points(int index) const;
  std::string* _internal_add_scan_mount_points();
  public:

  // repeated .perfetto.protos.InodeFileConfig.MountPointMappingEntry mount_point_mapping = 6;
  int mount_point_mapping_size() const;
  private:
  int _internal_mount_point_mapping_size() const;
  public:
  void clear_mount_point_mapping();
  ::perfetto::protos::InodeFileConfig_MountPointMappingEntry* mutable_mount_point_mapping(int index);
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::perfetto::protos::InodeFileConfig_MountPointMappingEntry >*
      mutable_mount_point_mapping();
  private:
  const ::perfetto::protos::InodeFileConfig_MountPointMappingEntry& _internal_mount_point_mapping(int index) const;
  ::perfetto::protos::InodeFileConfig_MountPointMappingEntry* _internal_add_mount_point_mapping();
  public:
  const ::perfetto::protos::InodeFileConfig_MountPointMappingEntry& mount_point_mapping(int index) const;
  ::perfetto::protos::InodeFileConfig_MountPointMappingEntry* add_mount_point_mapping();
  const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::perfetto::protos::InodeFileConfig_MountPointMappingEntry >&
      mount_point_mapping() const;

  // optional uint32 scan_interval_ms = 1;
  bool has_scan_interval_ms() const;
  private:
  bool _internal_has_scan_interval_ms() const;
  public:
  void clear_scan_interval_ms();
  ::PROTOBUF_NAMESPACE_ID::uint32 scan_interval_ms() const;
  void set_scan_interval_ms(::PROTOBUF_NAMESPACE_ID::uint32 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::uint32 _internal_scan_interval_ms() const;
  void _internal_set_scan_interval_ms(::PROTOBUF_NAMESPACE_ID::uint32 value);
  public:

  // optional uint32 scan_delay_ms = 2;
  bool has_scan_delay_ms() const;
  private:
  bool _internal_has_scan_delay_ms() const;
  public:
  void clear_scan_delay_ms();
  ::PROTOBUF_NAMESPACE_ID::uint32 scan_delay_ms() const;
  void set_scan_delay_ms(::PROTOBUF_NAMESPACE_ID::uint32 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::uint32 _internal_scan_delay_ms() const;
  void _internal_set_scan_delay_ms(::PROTOBUF_NAMESPACE_ID::uint32 value);
  public:

  // optional uint32 scan_batch_size = 3;
  bool has_scan_batch_size() const;
  private:
  bool _internal_has_scan_batch_size() const;
  public:
  void clear_scan_batch_size();
  ::PROTOBUF_NAMESPACE_ID::uint32 scan_batch_size() const;
  void set_scan_batch_size(::PROTOBUF_NAMESPACE_ID::uint32 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::uint32 _internal_scan_batch_size() const;
  void _internal_set_scan_batch_size(::PROTOBUF_NAMESPACE_ID::uint32 value);
  public:

  // optional bool do_not_scan = 4;
  bool has_do_not_scan() const;
  private:
  bool _internal_has_do_not_scan() const;
  public:
  void clear_do_not_scan();
  bool do_not_scan() const;
  void set_do_not_scan(bool value);
  private:
  bool _internal_do_not_scan() const;
  void _internal_set_do_not_scan(bool value);
  public:

  // @@protoc_insertion_point(class_scope:perfetto.protos.InodeFileConfig)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::internal::HasBits<1> _has_bits_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField<std::string> scan_mount_points_;
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::perfetto::protos::InodeFileConfig_MountPointMappingEntry > mount_point_mapping_;
  ::PROTOBUF_NAMESPACE_ID::uint32 scan_interval_ms_;
  ::PROTOBUF_NAMESPACE_ID::uint32 scan_delay_ms_;
  ::PROTOBUF_NAMESPACE_ID::uint32 scan_batch_size_;
  bool do_not_scan_;
  friend struct ::TableStruct_protos_2fperfetto_2fconfig_2finode_5ffile_2finode_5ffile_5fconfig_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// InodeFileConfig_MountPointMappingEntry

// optional string mountpoint = 1;
inline bool InodeFileConfig_MountPointMappingEntry::_internal_has_mountpoint() const {
  bool value = (_has_bits_[0] & 0x00000001u) != 0;
  return value;
}
inline bool InodeFileConfig_MountPointMappingEntry::has_mountpoint() const {
  return _internal_has_mountpoint();
}
inline void InodeFileConfig_MountPointMappingEntry::clear_mountpoint() {
  mountpoint_.ClearToEmpty(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
  _has_bits_[0] &= ~0x00000001u;
}
inline const std::string& InodeFileConfig_MountPointMappingEntry::mountpoint() const {
  // @@protoc_insertion_point(field_get:perfetto.protos.InodeFileConfig.MountPointMappingEntry.mountpoint)
  return _internal_mountpoint();
}
inline void InodeFileConfig_MountPointMappingEntry::set_mountpoint(const std::string& value) {
  _internal_set_mountpoint(value);
  // @@protoc_insertion_point(field_set:perfetto.protos.InodeFileConfig.MountPointMappingEntry.mountpoint)
}
inline std::string* InodeFileConfig_MountPointMappingEntry::mutable_mountpoint() {
  // @@protoc_insertion_point(field_mutable:perfetto.protos.InodeFileConfig.MountPointMappingEntry.mountpoint)
  return _internal_mutable_mountpoint();
}
inline const std::string& InodeFileConfig_MountPointMappingEntry::_internal_mountpoint() const {
  return mountpoint_.Get();
}
inline void InodeFileConfig_MountPointMappingEntry::_internal_set_mountpoint(const std::string& value) {
  _has_bits_[0] |= 0x00000001u;
  mountpoint_.SetLite(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), value, GetArena());
}
inline void InodeFileConfig_MountPointMappingEntry::set_mountpoint(std::string&& value) {
  _has_bits_[0] |= 0x00000001u;
  mountpoint_.SetLite(
    &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::move(value), GetArena());
  // @@protoc_insertion_point(field_set_rvalue:perfetto.protos.InodeFileConfig.MountPointMappingEntry.mountpoint)
}
inline void InodeFileConfig_MountPointMappingEntry::set_mountpoint(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  _has_bits_[0] |= 0x00000001u;
  mountpoint_.SetLite(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(value),
              GetArena());
  // @@protoc_insertion_point(field_set_char:perfetto.protos.InodeFileConfig.MountPointMappingEntry.mountpoint)
}
inline void InodeFileConfig_MountPointMappingEntry::set_mountpoint(const char* value,
    size_t size) {
  _has_bits_[0] |= 0x00000001u;
  mountpoint_.SetLite(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(
      reinterpret_cast<const char*>(value), size), GetArena());
  // @@protoc_insertion_point(field_set_pointer:perfetto.protos.InodeFileConfig.MountPointMappingEntry.mountpoint)
}
inline std::string* InodeFileConfig_MountPointMappingEntry::_internal_mutable_mountpoint() {
  _has_bits_[0] |= 0x00000001u;
  return mountpoint_.Mutable(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}
inline std::string* InodeFileConfig_MountPointMappingEntry::release_mountpoint() {
  // @@protoc_insertion_point(field_release:perfetto.protos.InodeFileConfig.MountPointMappingEntry.mountpoint)
  if (!_internal_has_mountpoint()) {
    return nullptr;
  }
  _has_bits_[0] &= ~0x00000001u;
  return mountpoint_.ReleaseNonDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}
inline void InodeFileConfig_MountPointMappingEntry::set_allocated_mountpoint(std::string* mountpoint) {
  if (mountpoint != nullptr) {
    _has_bits_[0] |= 0x00000001u;
  } else {
    _has_bits_[0] &= ~0x00000001u;
  }
  mountpoint_.SetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), mountpoint,
      GetArena());
  // @@protoc_insertion_point(field_set_allocated:perfetto.protos.InodeFileConfig.MountPointMappingEntry.mountpoint)
}

// repeated string scan_roots = 2;
inline int InodeFileConfig_MountPointMappingEntry::_internal_scan_roots_size() const {
  return scan_roots_.size();
}
inline int InodeFileConfig_MountPointMappingEntry::scan_roots_size() const {
  return _internal_scan_roots_size();
}
inline void InodeFileConfig_MountPointMappingEntry::clear_scan_roots() {
  scan_roots_.Clear();
}
inline std::string* InodeFileConfig_MountPointMappingEntry::add_scan_roots() {
  // @@protoc_insertion_point(field_add_mutable:perfetto.protos.InodeFileConfig.MountPointMappingEntry.scan_roots)
  return _internal_add_scan_roots();
}
inline const std::string& InodeFileConfig_MountPointMappingEntry::_internal_scan_roots(int index) const {
  return scan_roots_.Get(index);
}
inline const std::string& InodeFileConfig_MountPointMappingEntry::scan_roots(int index) const {
  // @@protoc_insertion_point(field_get:perfetto.protos.InodeFileConfig.MountPointMappingEntry.scan_roots)
  return _internal_scan_roots(index);
}
inline std::string* InodeFileConfig_MountPointMappingEntry::mutable_scan_roots(int index) {
  // @@protoc_insertion_point(field_mutable:perfetto.protos.InodeFileConfig.MountPointMappingEntry.scan_roots)
  return scan_roots_.Mutable(index);
}
inline void InodeFileConfig_MountPointMappingEntry::set_scan_roots(int index, const std::string& value) {
  // @@protoc_insertion_point(field_set:perfetto.protos.InodeFileConfig.MountPointMappingEntry.scan_roots)
  scan_roots_.Mutable(index)->assign(value);
}
inline void InodeFileConfig_MountPointMappingEntry::set_scan_roots(int index, std::string&& value) {
  // @@protoc_insertion_point(field_set:perfetto.protos.InodeFileConfig.MountPointMappingEntry.scan_roots)
  scan_roots_.Mutable(index)->assign(std::move(value));
}
inline void InodeFileConfig_MountPointMappingEntry::set_scan_roots(int index, const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  scan_roots_.Mutable(index)->assign(value);
  // @@protoc_insertion_point(field_set_char:perfetto.protos.InodeFileConfig.MountPointMappingEntry.scan_roots)
}
inline void InodeFileConfig_MountPointMappingEntry::set_scan_roots(int index, const char* value, size_t size) {
  scan_roots_.Mutable(index)->assign(
    reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_set_pointer:perfetto.protos.InodeFileConfig.MountPointMappingEntry.scan_roots)
}
inline std::string* InodeFileConfig_MountPointMappingEntry::_internal_add_scan_roots() {
  return scan_roots_.Add();
}
inline void InodeFileConfig_MountPointMappingEntry::add_scan_roots(const std::string& value) {
  scan_roots_.Add()->assign(value);
  // @@protoc_insertion_point(field_add:perfetto.protos.InodeFileConfig.MountPointMappingEntry.scan_roots)
}
inline void InodeFileConfig_MountPointMappingEntry::add_scan_roots(std::string&& value) {
  scan_roots_.Add(std::move(value));
  // @@protoc_insertion_point(field_add:perfetto.protos.InodeFileConfig.MountPointMappingEntry.scan_roots)
}
inline void InodeFileConfig_MountPointMappingEntry::add_scan_roots(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  scan_roots_.Add()->assign(value);
  // @@protoc_insertion_point(field_add_char:perfetto.protos.InodeFileConfig.MountPointMappingEntry.scan_roots)
}
inline void InodeFileConfig_MountPointMappingEntry::add_scan_roots(const char* value, size_t size) {
  scan_roots_.Add()->assign(reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_add_pointer:perfetto.protos.InodeFileConfig.MountPointMappingEntry.scan_roots)
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField<std::string>&
InodeFileConfig_MountPointMappingEntry::scan_roots() const {
  // @@protoc_insertion_point(field_list:perfetto.protos.InodeFileConfig.MountPointMappingEntry.scan_roots)
  return scan_roots_;
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField<std::string>*
InodeFileConfig_MountPointMappingEntry::mutable_scan_roots() {
  // @@protoc_insertion_point(field_mutable_list:perfetto.protos.InodeFileConfig.MountPointMappingEntry.scan_roots)
  return &scan_roots_;
}

// -------------------------------------------------------------------

// InodeFileConfig

// optional uint32 scan_interval_ms = 1;
inline bool InodeFileConfig::_internal_has_scan_interval_ms() const {
  bool value = (_has_bits_[0] & 0x00000001u) != 0;
  return value;
}
inline bool InodeFileConfig::has_scan_interval_ms() const {
  return _internal_has_scan_interval_ms();
}
inline void InodeFileConfig::clear_scan_interval_ms() {
  scan_interval_ms_ = 0u;
  _has_bits_[0] &= ~0x00000001u;
}
inline ::PROTOBUF_NAMESPACE_ID::uint32 InodeFileConfig::_internal_scan_interval_ms() const {
  return scan_interval_ms_;
}
inline ::PROTOBUF_NAMESPACE_ID::uint32 InodeFileConfig::scan_interval_ms() const {
  // @@protoc_insertion_point(field_get:perfetto.protos.InodeFileConfig.scan_interval_ms)
  return _internal_scan_interval_ms();
}
inline void InodeFileConfig::_internal_set_scan_interval_ms(::PROTOBUF_NAMESPACE_ID::uint32 value) {
  _has_bits_[0] |= 0x00000001u;
  scan_interval_ms_ = value;
}
inline void InodeFileConfig::set_scan_interval_ms(::PROTOBUF_NAMESPACE_ID::uint32 value) {
  _internal_set_scan_interval_ms(value);
  // @@protoc_insertion_point(field_set:perfetto.protos.InodeFileConfig.scan_interval_ms)
}

// optional uint32 scan_delay_ms = 2;
inline bool InodeFileConfig::_internal_has_scan_delay_ms() const {
  bool value = (_has_bits_[0] & 0x00000002u) != 0;
  return value;
}
inline bool InodeFileConfig::has_scan_delay_ms() const {
  return _internal_has_scan_delay_ms();
}
inline void InodeFileConfig::clear_scan_delay_ms() {
  scan_delay_ms_ = 0u;
  _has_bits_[0] &= ~0x00000002u;
}
inline ::PROTOBUF_NAMESPACE_ID::uint32 InodeFileConfig::_internal_scan_delay_ms() const {
  return scan_delay_ms_;
}
inline ::PROTOBUF_NAMESPACE_ID::uint32 InodeFileConfig::scan_delay_ms() const {
  // @@protoc_insertion_point(field_get:perfetto.protos.InodeFileConfig.scan_delay_ms)
  return _internal_scan_delay_ms();
}
inline void InodeFileConfig::_internal_set_scan_delay_ms(::PROTOBUF_NAMESPACE_ID::uint32 value) {
  _has_bits_[0] |= 0x00000002u;
  scan_delay_ms_ = value;
}
inline void InodeFileConfig::set_scan_delay_ms(::PROTOBUF_NAMESPACE_ID::uint32 value) {
  _internal_set_scan_delay_ms(value);
  // @@protoc_insertion_point(field_set:perfetto.protos.InodeFileConfig.scan_delay_ms)
}

// optional uint32 scan_batch_size = 3;
inline bool InodeFileConfig::_internal_has_scan_batch_size() const {
  bool value = (_has_bits_[0] & 0x00000004u) != 0;
  return value;
}
inline bool InodeFileConfig::has_scan_batch_size() const {
  return _internal_has_scan_batch_size();
}
inline void InodeFileConfig::clear_scan_batch_size() {
  scan_batch_size_ = 0u;
  _has_bits_[0] &= ~0x00000004u;
}
inline ::PROTOBUF_NAMESPACE_ID::uint32 InodeFileConfig::_internal_scan_batch_size() const {
  return scan_batch_size_;
}
inline ::PROTOBUF_NAMESPACE_ID::uint32 InodeFileConfig::scan_batch_size() const {
  // @@protoc_insertion_point(field_get:perfetto.protos.InodeFileConfig.scan_batch_size)
  return _internal_scan_batch_size();
}
inline void InodeFileConfig::_internal_set_scan_batch_size(::PROTOBUF_NAMESPACE_ID::uint32 value) {
  _has_bits_[0] |= 0x00000004u;
  scan_batch_size_ = value;
}
inline void InodeFileConfig::set_scan_batch_size(::PROTOBUF_NAMESPACE_ID::uint32 value) {
  _internal_set_scan_batch_size(value);
  // @@protoc_insertion_point(field_set:perfetto.protos.InodeFileConfig.scan_batch_size)
}

// optional bool do_not_scan = 4;
inline bool InodeFileConfig::_internal_has_do_not_scan() const {
  bool value = (_has_bits_[0] & 0x00000008u) != 0;
  return value;
}
inline bool InodeFileConfig::has_do_not_scan() const {
  return _internal_has_do_not_scan();
}
inline void InodeFileConfig::clear_do_not_scan() {
  do_not_scan_ = false;
  _has_bits_[0] &= ~0x00000008u;
}
inline bool InodeFileConfig::_internal_do_not_scan() const {
  return do_not_scan_;
}
inline bool InodeFileConfig::do_not_scan() const {
  // @@protoc_insertion_point(field_get:perfetto.protos.InodeFileConfig.do_not_scan)
  return _internal_do_not_scan();
}
inline void InodeFileConfig::_internal_set_do_not_scan(bool value) {
  _has_bits_[0] |= 0x00000008u;
  do_not_scan_ = value;
}
inline void InodeFileConfig::set_do_not_scan(bool value) {
  _internal_set_do_not_scan(value);
  // @@protoc_insertion_point(field_set:perfetto.protos.InodeFileConfig.do_not_scan)
}

// repeated string scan_mount_points = 5;
inline int InodeFileConfig::_internal_scan_mount_points_size() const {
  return scan_mount_points_.size();
}
inline int InodeFileConfig::scan_mount_points_size() const {
  return _internal_scan_mount_points_size();
}
inline void InodeFileConfig::clear_scan_mount_points() {
  scan_mount_points_.Clear();
}
inline std::string* InodeFileConfig::add_scan_mount_points() {
  // @@protoc_insertion_point(field_add_mutable:perfetto.protos.InodeFileConfig.scan_mount_points)
  return _internal_add_scan_mount_points();
}
inline const std::string& InodeFileConfig::_internal_scan_mount_points(int index) const {
  return scan_mount_points_.Get(index);
}
inline const std::string& InodeFileConfig::scan_mount_points(int index) const {
  // @@protoc_insertion_point(field_get:perfetto.protos.InodeFileConfig.scan_mount_points)
  return _internal_scan_mount_points(index);
}
inline std::string* InodeFileConfig::mutable_scan_mount_points(int index) {
  // @@protoc_insertion_point(field_mutable:perfetto.protos.InodeFileConfig.scan_mount_points)
  return scan_mount_points_.Mutable(index);
}
inline void InodeFileConfig::set_scan_mount_points(int index, const std::string& value) {
  // @@protoc_insertion_point(field_set:perfetto.protos.InodeFileConfig.scan_mount_points)
  scan_mount_points_.Mutable(index)->assign(value);
}
inline void InodeFileConfig::set_scan_mount_points(int index, std::string&& value) {
  // @@protoc_insertion_point(field_set:perfetto.protos.InodeFileConfig.scan_mount_points)
  scan_mount_points_.Mutable(index)->assign(std::move(value));
}
inline void InodeFileConfig::set_scan_mount_points(int index, const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  scan_mount_points_.Mutable(index)->assign(value);
  // @@protoc_insertion_point(field_set_char:perfetto.protos.InodeFileConfig.scan_mount_points)
}
inline void InodeFileConfig::set_scan_mount_points(int index, const char* value, size_t size) {
  scan_mount_points_.Mutable(index)->assign(
    reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_set_pointer:perfetto.protos.InodeFileConfig.scan_mount_points)
}
inline std::string* InodeFileConfig::_internal_add_scan_mount_points() {
  return scan_mount_points_.Add();
}
inline void InodeFileConfig::add_scan_mount_points(const std::string& value) {
  scan_mount_points_.Add()->assign(value);
  // @@protoc_insertion_point(field_add:perfetto.protos.InodeFileConfig.scan_mount_points)
}
inline void InodeFileConfig::add_scan_mount_points(std::string&& value) {
  scan_mount_points_.Add(std::move(value));
  // @@protoc_insertion_point(field_add:perfetto.protos.InodeFileConfig.scan_mount_points)
}
inline void InodeFileConfig::add_scan_mount_points(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  scan_mount_points_.Add()->assign(value);
  // @@protoc_insertion_point(field_add_char:perfetto.protos.InodeFileConfig.scan_mount_points)
}
inline void InodeFileConfig::add_scan_mount_points(const char* value, size_t size) {
  scan_mount_points_.Add()->assign(reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_add_pointer:perfetto.protos.InodeFileConfig.scan_mount_points)
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField<std::string>&
InodeFileConfig::scan_mount_points() const {
  // @@protoc_insertion_point(field_list:perfetto.protos.InodeFileConfig.scan_mount_points)
  return scan_mount_points_;
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField<std::string>*
InodeFileConfig::mutable_scan_mount_points() {
  // @@protoc_insertion_point(field_mutable_list:perfetto.protos.InodeFileConfig.scan_mount_points)
  return &scan_mount_points_;
}

// repeated .perfetto.protos.InodeFileConfig.MountPointMappingEntry mount_point_mapping = 6;
inline int InodeFileConfig::_internal_mount_point_mapping_size() const {
  return mount_point_mapping_.size();
}
inline int InodeFileConfig::mount_point_mapping_size() const {
  return _internal_mount_point_mapping_size();
}
inline void InodeFileConfig::clear_mount_point_mapping() {
  mount_point_mapping_.Clear();
}
inline ::perfetto::protos::InodeFileConfig_MountPointMappingEntry* InodeFileConfig::mutable_mount_point_mapping(int index) {
  // @@protoc_insertion_point(field_mutable:perfetto.protos.InodeFileConfig.mount_point_mapping)
  return mount_point_mapping_.Mutable(index);
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::perfetto::protos::InodeFileConfig_MountPointMappingEntry >*
InodeFileConfig::mutable_mount_point_mapping() {
  // @@protoc_insertion_point(field_mutable_list:perfetto.protos.InodeFileConfig.mount_point_mapping)
  return &mount_point_mapping_;
}
inline const ::perfetto::protos::InodeFileConfig_MountPointMappingEntry& InodeFileConfig::_internal_mount_point_mapping(int index) const {
  return mount_point_mapping_.Get(index);
}
inline const ::perfetto::protos::InodeFileConfig_MountPointMappingEntry& InodeFileConfig::mount_point_mapping(int index) const {
  // @@protoc_insertion_point(field_get:perfetto.protos.InodeFileConfig.mount_point_mapping)
  return _internal_mount_point_mapping(index);
}
inline ::perfetto::protos::InodeFileConfig_MountPointMappingEntry* InodeFileConfig::_internal_add_mount_point_mapping() {
  return mount_point_mapping_.Add();
}
inline ::perfetto::protos::InodeFileConfig_MountPointMappingEntry* InodeFileConfig::add_mount_point_mapping() {
  // @@protoc_insertion_point(field_add:perfetto.protos.InodeFileConfig.mount_point_mapping)
  return _internal_add_mount_point_mapping();
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::perfetto::protos::InodeFileConfig_MountPointMappingEntry >&
InodeFileConfig::mount_point_mapping() const {
  // @@protoc_insertion_point(field_list:perfetto.protos.InodeFileConfig.mount_point_mapping)
  return mount_point_mapping_;
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace protos
}  // namespace perfetto

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_protos_2fperfetto_2fconfig_2finode_5ffile_2finode_5ffile_5fconfig_2eproto
