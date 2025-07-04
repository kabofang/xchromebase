// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: protos/perfetto/trace/track_event/chrome_user_event.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_protos_2fperfetto_2ftrace_2ftrack_5fevent_2fchrome_5fuser_5fevent_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_protos_2fperfetto_2ftrace_2ftrack_5fevent_2fchrome_5fuser_5fevent_2eproto

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
#define PROTOBUF_INTERNAL_EXPORT_protos_2fperfetto_2ftrace_2ftrack_5fevent_2fchrome_5fuser_5fevent_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_protos_2fperfetto_2ftrace_2ftrack_5fevent_2fchrome_5fuser_5fevent_2eproto {
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTableField entries[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::AuxiliaryParseTableField aux[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTable schema[1]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::FieldMetadata field_metadata[];
  static const ::PROTOBUF_NAMESPACE_ID::internal::SerializationTable serialization_table[];
  static const ::PROTOBUF_NAMESPACE_ID::uint32 offsets[];
};
namespace perfetto {
namespace protos {
class ChromeUserEvent;
class ChromeUserEventDefaultTypeInternal;
extern ChromeUserEventDefaultTypeInternal _ChromeUserEvent_default_instance_;
}  // namespace protos
}  // namespace perfetto
PROTOBUF_NAMESPACE_OPEN
template<> ::perfetto::protos::ChromeUserEvent* Arena::CreateMaybeMessage<::perfetto::protos::ChromeUserEvent>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace perfetto {
namespace protos {

// ===================================================================

class ChromeUserEvent PROTOBUF_FINAL :
    public ::PROTOBUF_NAMESPACE_ID::MessageLite /* @@protoc_insertion_point(class_definition:perfetto.protos.ChromeUserEvent) */ {
 public:
  inline ChromeUserEvent() : ChromeUserEvent(nullptr) {}
  virtual ~ChromeUserEvent();

  ChromeUserEvent(const ChromeUserEvent& from);
  ChromeUserEvent(ChromeUserEvent&& from) noexcept
    : ChromeUserEvent() {
    *this = ::std::move(from);
  }

  inline ChromeUserEvent& operator=(const ChromeUserEvent& from) {
    CopyFrom(from);
    return *this;
  }
  inline ChromeUserEvent& operator=(ChromeUserEvent&& from) noexcept {
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

  static const ChromeUserEvent& default_instance();

  static inline const ChromeUserEvent* internal_default_instance() {
    return reinterpret_cast<const ChromeUserEvent*>(
               &_ChromeUserEvent_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(ChromeUserEvent& a, ChromeUserEvent& b) {
    a.Swap(&b);
  }
  PROTOBUF_NOINLINE void Swap(ChromeUserEvent* other) {
    if (other == this) return;
    if (GetArena() == other->GetArena()) {
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(ChromeUserEvent* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetArena() == other->GetArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline ChromeUserEvent* New() const final {
    return CreateMaybeMessage<ChromeUserEvent>(nullptr);
  }

  ChromeUserEvent* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<ChromeUserEvent>(arena);
  }
  void CheckTypeAndMergeFrom(const ::PROTOBUF_NAMESPACE_ID::MessageLite& from)
    final;
  void CopyFrom(const ChromeUserEvent& from);
  void MergeFrom(const ChromeUserEvent& from);
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
  void InternalSwap(ChromeUserEvent* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "perfetto.protos.ChromeUserEvent";
  }
  protected:
  explicit ChromeUserEvent(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  std::string GetTypeName() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kActionFieldNumber = 1,
    kActionHashFieldNumber = 2,
  };
  // optional string action = 1;
  bool has_action() const;
  private:
  bool _internal_has_action() const;
  public:
  void clear_action();
  const std::string& action() const;
  void set_action(const std::string& value);
  void set_action(std::string&& value);
  void set_action(const char* value);
  void set_action(const char* value, size_t size);
  std::string* mutable_action();
  std::string* release_action();
  void set_allocated_action(std::string* action);
  private:
  const std::string& _internal_action() const;
  void _internal_set_action(const std::string& value);
  std::string* _internal_mutable_action();
  public:

  // optional uint64 action_hash = 2;
  bool has_action_hash() const;
  private:
  bool _internal_has_action_hash() const;
  public:
  void clear_action_hash();
  ::PROTOBUF_NAMESPACE_ID::uint64 action_hash() const;
  void set_action_hash(::PROTOBUF_NAMESPACE_ID::uint64 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::uint64 _internal_action_hash() const;
  void _internal_set_action_hash(::PROTOBUF_NAMESPACE_ID::uint64 value);
  public:

  // @@protoc_insertion_point(class_scope:perfetto.protos.ChromeUserEvent)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::internal::HasBits<1> _has_bits_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr action_;
  ::PROTOBUF_NAMESPACE_ID::uint64 action_hash_;
  friend struct ::TableStruct_protos_2fperfetto_2ftrace_2ftrack_5fevent_2fchrome_5fuser_5fevent_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// ChromeUserEvent

// optional string action = 1;
inline bool ChromeUserEvent::_internal_has_action() const {
  bool value = (_has_bits_[0] & 0x00000001u) != 0;
  return value;
}
inline bool ChromeUserEvent::has_action() const {
  return _internal_has_action();
}
inline void ChromeUserEvent::clear_action() {
  action_.ClearToEmpty(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
  _has_bits_[0] &= ~0x00000001u;
}
inline const std::string& ChromeUserEvent::action() const {
  // @@protoc_insertion_point(field_get:perfetto.protos.ChromeUserEvent.action)
  return _internal_action();
}
inline void ChromeUserEvent::set_action(const std::string& value) {
  _internal_set_action(value);
  // @@protoc_insertion_point(field_set:perfetto.protos.ChromeUserEvent.action)
}
inline std::string* ChromeUserEvent::mutable_action() {
  // @@protoc_insertion_point(field_mutable:perfetto.protos.ChromeUserEvent.action)
  return _internal_mutable_action();
}
inline const std::string& ChromeUserEvent::_internal_action() const {
  return action_.Get();
}
inline void ChromeUserEvent::_internal_set_action(const std::string& value) {
  _has_bits_[0] |= 0x00000001u;
  action_.SetLite(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), value, GetArena());
}
inline void ChromeUserEvent::set_action(std::string&& value) {
  _has_bits_[0] |= 0x00000001u;
  action_.SetLite(
    &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::move(value), GetArena());
  // @@protoc_insertion_point(field_set_rvalue:perfetto.protos.ChromeUserEvent.action)
}
inline void ChromeUserEvent::set_action(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  _has_bits_[0] |= 0x00000001u;
  action_.SetLite(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(value),
              GetArena());
  // @@protoc_insertion_point(field_set_char:perfetto.protos.ChromeUserEvent.action)
}
inline void ChromeUserEvent::set_action(const char* value,
    size_t size) {
  _has_bits_[0] |= 0x00000001u;
  action_.SetLite(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(
      reinterpret_cast<const char*>(value), size), GetArena());
  // @@protoc_insertion_point(field_set_pointer:perfetto.protos.ChromeUserEvent.action)
}
inline std::string* ChromeUserEvent::_internal_mutable_action() {
  _has_bits_[0] |= 0x00000001u;
  return action_.Mutable(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}
inline std::string* ChromeUserEvent::release_action() {
  // @@protoc_insertion_point(field_release:perfetto.protos.ChromeUserEvent.action)
  if (!_internal_has_action()) {
    return nullptr;
  }
  _has_bits_[0] &= ~0x00000001u;
  return action_.ReleaseNonDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}
inline void ChromeUserEvent::set_allocated_action(std::string* action) {
  if (action != nullptr) {
    _has_bits_[0] |= 0x00000001u;
  } else {
    _has_bits_[0] &= ~0x00000001u;
  }
  action_.SetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), action,
      GetArena());
  // @@protoc_insertion_point(field_set_allocated:perfetto.protos.ChromeUserEvent.action)
}

// optional uint64 action_hash = 2;
inline bool ChromeUserEvent::_internal_has_action_hash() const {
  bool value = (_has_bits_[0] & 0x00000002u) != 0;
  return value;
}
inline bool ChromeUserEvent::has_action_hash() const {
  return _internal_has_action_hash();
}
inline void ChromeUserEvent::clear_action_hash() {
  action_hash_ = PROTOBUF_ULONGLONG(0);
  _has_bits_[0] &= ~0x00000002u;
}
inline ::PROTOBUF_NAMESPACE_ID::uint64 ChromeUserEvent::_internal_action_hash() const {
  return action_hash_;
}
inline ::PROTOBUF_NAMESPACE_ID::uint64 ChromeUserEvent::action_hash() const {
  // @@protoc_insertion_point(field_get:perfetto.protos.ChromeUserEvent.action_hash)
  return _internal_action_hash();
}
inline void ChromeUserEvent::_internal_set_action_hash(::PROTOBUF_NAMESPACE_ID::uint64 value) {
  _has_bits_[0] |= 0x00000002u;
  action_hash_ = value;
}
inline void ChromeUserEvent::set_action_hash(::PROTOBUF_NAMESPACE_ID::uint64 value) {
  _internal_set_action_hash(value);
  // @@protoc_insertion_point(field_set:perfetto.protos.ChromeUserEvent.action_hash)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)

}  // namespace protos
}  // namespace perfetto

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_protos_2fperfetto_2ftrace_2ftrack_5fevent_2fchrome_5fuser_5fevent_2eproto
