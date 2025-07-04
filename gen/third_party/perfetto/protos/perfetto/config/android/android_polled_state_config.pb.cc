// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: protos/perfetto/config/android/android_polled_state_config.proto

#include "protos/perfetto/config/android/android_polled_state_config.pb.h"

#include <algorithm>

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/wire_format_lite.h>
#include <google/protobuf/io/zero_copy_stream_impl_lite.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
namespace perfetto {
namespace protos {
class AndroidPolledStateConfigDefaultTypeInternal {
 public:
  ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<AndroidPolledStateConfig> _instance;
} _AndroidPolledStateConfig_default_instance_;
}  // namespace protos
}  // namespace perfetto
static void InitDefaultsscc_info_AndroidPolledStateConfig_protos_2fperfetto_2fconfig_2fandroid_2fandroid_5fpolled_5fstate_5fconfig_2eproto() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::perfetto::protos::_AndroidPolledStateConfig_default_instance_;
    new (ptr) ::perfetto::protos::AndroidPolledStateConfig();
    ::PROTOBUF_NAMESPACE_ID::internal::OnShutdownDestroyMessage(ptr);
  }
}

::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<0> scc_info_AndroidPolledStateConfig_protos_2fperfetto_2fconfig_2fandroid_2fandroid_5fpolled_5fstate_5fconfig_2eproto =
    {{ATOMIC_VAR_INIT(::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase::kUninitialized), 0, 0, InitDefaultsscc_info_AndroidPolledStateConfig_protos_2fperfetto_2fconfig_2fandroid_2fandroid_5fpolled_5fstate_5fconfig_2eproto}, {}};

namespace perfetto {
namespace protos {

// ===================================================================

class AndroidPolledStateConfig::_Internal {
 public:
  using HasBits = decltype(std::declval<AndroidPolledStateConfig>()._has_bits_);
  static void set_has_poll_ms(HasBits* has_bits) {
    (*has_bits)[0] |= 1u;
  }
};

AndroidPolledStateConfig::AndroidPolledStateConfig(::PROTOBUF_NAMESPACE_ID::Arena* arena)
  : ::PROTOBUF_NAMESPACE_ID::MessageLite(arena) {
  SharedCtor();
  RegisterArenaDtor(arena);
  // @@protoc_insertion_point(arena_constructor:perfetto.protos.AndroidPolledStateConfig)
}
AndroidPolledStateConfig::AndroidPolledStateConfig(const AndroidPolledStateConfig& from)
  : ::PROTOBUF_NAMESPACE_ID::MessageLite(),
      _has_bits_(from._has_bits_) {
  _internal_metadata_.MergeFrom<std::string>(from._internal_metadata_);
  poll_ms_ = from.poll_ms_;
  // @@protoc_insertion_point(copy_constructor:perfetto.protos.AndroidPolledStateConfig)
}

void AndroidPolledStateConfig::SharedCtor() {
  poll_ms_ = 0u;
}

AndroidPolledStateConfig::~AndroidPolledStateConfig() {
  // @@protoc_insertion_point(destructor:perfetto.protos.AndroidPolledStateConfig)
  SharedDtor();
  _internal_metadata_.Delete<std::string>();
}

void AndroidPolledStateConfig::SharedDtor() {
  GOOGLE_DCHECK(GetArena() == nullptr);
}

void AndroidPolledStateConfig::ArenaDtor(void* object) {
  AndroidPolledStateConfig* _this = reinterpret_cast< AndroidPolledStateConfig* >(object);
  (void)_this;
}
void AndroidPolledStateConfig::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void AndroidPolledStateConfig::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const AndroidPolledStateConfig& AndroidPolledStateConfig::default_instance() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&::scc_info_AndroidPolledStateConfig_protos_2fperfetto_2fconfig_2fandroid_2fandroid_5fpolled_5fstate_5fconfig_2eproto.base);
  return *internal_default_instance();
}


void AndroidPolledStateConfig::Clear() {
// @@protoc_insertion_point(message_clear_start:perfetto.protos.AndroidPolledStateConfig)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  poll_ms_ = 0u;
  _has_bits_.Clear();
  _internal_metadata_.Clear<std::string>();
}

const char* AndroidPolledStateConfig::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  _Internal::HasBits has_bits{};
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    CHK_(ptr);
    switch (tag >> 3) {
      // optional uint32 poll_ms = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 8)) {
          _Internal::set_has_poll_ms(&has_bits);
          poll_ms_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint32(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      default: {
      handle_unusual:
        if ((tag & 7) == 4 || tag == 0) {
          ctx->SetLastTag(tag);
          goto success;
        }
        ptr = UnknownFieldParse(tag,
            _internal_metadata_.mutable_unknown_fields<std::string>(),
            ptr, ctx);
        CHK_(ptr != nullptr);
        continue;
      }
    }  // switch
  }  // while
success:
  _has_bits_.Or(has_bits);
  return ptr;
failure:
  ptr = nullptr;
  goto success;
#undef CHK_
}

::PROTOBUF_NAMESPACE_ID::uint8* AndroidPolledStateConfig::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:perfetto.protos.AndroidPolledStateConfig)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  // optional uint32 poll_ms = 1;
  if (cached_has_bits & 0x00000001u) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteUInt32ToArray(1, this->_internal_poll_ms(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = stream->WriteRaw(_internal_metadata_.unknown_fields<std::string>(::PROTOBUF_NAMESPACE_ID::internal::GetEmptyString).data(),
        static_cast<int>(_internal_metadata_.unknown_fields<std::string>(::PROTOBUF_NAMESPACE_ID::internal::GetEmptyString).size()), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:perfetto.protos.AndroidPolledStateConfig)
  return target;
}

size_t AndroidPolledStateConfig::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:perfetto.protos.AndroidPolledStateConfig)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // optional uint32 poll_ms = 1;
  cached_has_bits = _has_bits_[0];
  if (cached_has_bits & 0x00000001u) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::UInt32Size(
        this->_internal_poll_ms());
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    total_size += _internal_metadata_.unknown_fields<std::string>(::PROTOBUF_NAMESPACE_ID::internal::GetEmptyString).size();
  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void AndroidPolledStateConfig::CheckTypeAndMergeFrom(
    const ::PROTOBUF_NAMESPACE_ID::MessageLite& from) {
  MergeFrom(*::PROTOBUF_NAMESPACE_ID::internal::DownCast<const AndroidPolledStateConfig*>(
      &from));
}

void AndroidPolledStateConfig::MergeFrom(const AndroidPolledStateConfig& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:perfetto.protos.AndroidPolledStateConfig)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom<std::string>(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (from._internal_has_poll_ms()) {
    _internal_set_poll_ms(from._internal_poll_ms());
  }
}

void AndroidPolledStateConfig::CopyFrom(const AndroidPolledStateConfig& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:perfetto.protos.AndroidPolledStateConfig)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool AndroidPolledStateConfig::IsInitialized() const {
  return true;
}

void AndroidPolledStateConfig::InternalSwap(AndroidPolledStateConfig* other) {
  using std::swap;
  _internal_metadata_.Swap<std::string>(&other->_internal_metadata_);
  swap(_has_bits_[0], other->_has_bits_[0]);
  swap(poll_ms_, other->poll_ms_);
}

std::string AndroidPolledStateConfig::GetTypeName() const {
  return "perfetto.protos.AndroidPolledStateConfig";
}


// @@protoc_insertion_point(namespace_scope)
}  // namespace protos
}  // namespace perfetto
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::perfetto::protos::AndroidPolledStateConfig* Arena::CreateMaybeMessage< ::perfetto::protos::AndroidPolledStateConfig >(Arena* arena) {
  return Arena::CreateMessageInternal< ::perfetto::protos::AndroidPolledStateConfig >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
