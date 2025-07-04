// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: protos/perfetto/trace/track_event/chrome_message_pump.proto

#include "protos/perfetto/trace/track_event/chrome_message_pump.pb.h"

#include <algorithm>

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/wire_format_lite.h>
#include <google/protobuf/io/zero_copy_stream_impl_lite.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
namespace perfetto {
namespace protos {
class ChromeMessagePumpDefaultTypeInternal {
 public:
  ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<ChromeMessagePump> _instance;
} _ChromeMessagePump_default_instance_;
}  // namespace protos
}  // namespace perfetto
static void InitDefaultsscc_info_ChromeMessagePump_protos_2fperfetto_2ftrace_2ftrack_5fevent_2fchrome_5fmessage_5fpump_2eproto() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::perfetto::protos::_ChromeMessagePump_default_instance_;
    new (ptr) ::perfetto::protos::ChromeMessagePump();
    ::PROTOBUF_NAMESPACE_ID::internal::OnShutdownDestroyMessage(ptr);
  }
}

::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<0> scc_info_ChromeMessagePump_protos_2fperfetto_2ftrace_2ftrack_5fevent_2fchrome_5fmessage_5fpump_2eproto =
    {{ATOMIC_VAR_INIT(::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase::kUninitialized), 0, 0, InitDefaultsscc_info_ChromeMessagePump_protos_2fperfetto_2ftrace_2ftrack_5fevent_2fchrome_5fmessage_5fpump_2eproto}, {}};

namespace perfetto {
namespace protos {

// ===================================================================

class ChromeMessagePump::_Internal {
 public:
  using HasBits = decltype(std::declval<ChromeMessagePump>()._has_bits_);
  static void set_has_sent_messages_in_queue(HasBits* has_bits) {
    (*has_bits)[0] |= 2u;
  }
  static void set_has_io_handler_location_iid(HasBits* has_bits) {
    (*has_bits)[0] |= 1u;
  }
};

ChromeMessagePump::ChromeMessagePump(::PROTOBUF_NAMESPACE_ID::Arena* arena)
  : ::PROTOBUF_NAMESPACE_ID::MessageLite(arena) {
  SharedCtor();
  RegisterArenaDtor(arena);
  // @@protoc_insertion_point(arena_constructor:perfetto.protos.ChromeMessagePump)
}
ChromeMessagePump::ChromeMessagePump(const ChromeMessagePump& from)
  : ::PROTOBUF_NAMESPACE_ID::MessageLite(),
      _has_bits_(from._has_bits_) {
  _internal_metadata_.MergeFrom<std::string>(from._internal_metadata_);
  ::memcpy(&io_handler_location_iid_, &from.io_handler_location_iid_,
    static_cast<size_t>(reinterpret_cast<char*>(&sent_messages_in_queue_) -
    reinterpret_cast<char*>(&io_handler_location_iid_)) + sizeof(sent_messages_in_queue_));
  // @@protoc_insertion_point(copy_constructor:perfetto.protos.ChromeMessagePump)
}

void ChromeMessagePump::SharedCtor() {
  ::memset(reinterpret_cast<char*>(this) + static_cast<size_t>(
      reinterpret_cast<char*>(&io_handler_location_iid_) - reinterpret_cast<char*>(this)),
      0, static_cast<size_t>(reinterpret_cast<char*>(&sent_messages_in_queue_) -
      reinterpret_cast<char*>(&io_handler_location_iid_)) + sizeof(sent_messages_in_queue_));
}

ChromeMessagePump::~ChromeMessagePump() {
  // @@protoc_insertion_point(destructor:perfetto.protos.ChromeMessagePump)
  SharedDtor();
  _internal_metadata_.Delete<std::string>();
}

void ChromeMessagePump::SharedDtor() {
  GOOGLE_DCHECK(GetArena() == nullptr);
}

void ChromeMessagePump::ArenaDtor(void* object) {
  ChromeMessagePump* _this = reinterpret_cast< ChromeMessagePump* >(object);
  (void)_this;
}
void ChromeMessagePump::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void ChromeMessagePump::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const ChromeMessagePump& ChromeMessagePump::default_instance() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&::scc_info_ChromeMessagePump_protos_2fperfetto_2ftrace_2ftrack_5fevent_2fchrome_5fmessage_5fpump_2eproto.base);
  return *internal_default_instance();
}


void ChromeMessagePump::Clear() {
// @@protoc_insertion_point(message_clear_start:perfetto.protos.ChromeMessagePump)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  if (cached_has_bits & 0x00000003u) {
    ::memset(&io_handler_location_iid_, 0, static_cast<size_t>(
        reinterpret_cast<char*>(&sent_messages_in_queue_) -
        reinterpret_cast<char*>(&io_handler_location_iid_)) + sizeof(sent_messages_in_queue_));
  }
  _has_bits_.Clear();
  _internal_metadata_.Clear<std::string>();
}

const char* ChromeMessagePump::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  _Internal::HasBits has_bits{};
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    CHK_(ptr);
    switch (tag >> 3) {
      // optional bool sent_messages_in_queue = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 8)) {
          _Internal::set_has_sent_messages_in_queue(&has_bits);
          sent_messages_in_queue_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // optional uint64 io_handler_location_iid = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 16)) {
          _Internal::set_has_io_handler_location_iid(&has_bits);
          io_handler_location_iid_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
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

::PROTOBUF_NAMESPACE_ID::uint8* ChromeMessagePump::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:perfetto.protos.ChromeMessagePump)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  // optional bool sent_messages_in_queue = 1;
  if (cached_has_bits & 0x00000002u) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteBoolToArray(1, this->_internal_sent_messages_in_queue(), target);
  }

  // optional uint64 io_handler_location_iid = 2;
  if (cached_has_bits & 0x00000001u) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteUInt64ToArray(2, this->_internal_io_handler_location_iid(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = stream->WriteRaw(_internal_metadata_.unknown_fields<std::string>(::PROTOBUF_NAMESPACE_ID::internal::GetEmptyString).data(),
        static_cast<int>(_internal_metadata_.unknown_fields<std::string>(::PROTOBUF_NAMESPACE_ID::internal::GetEmptyString).size()), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:perfetto.protos.ChromeMessagePump)
  return target;
}

size_t ChromeMessagePump::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:perfetto.protos.ChromeMessagePump)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  if (cached_has_bits & 0x00000003u) {
    // optional uint64 io_handler_location_iid = 2;
    if (cached_has_bits & 0x00000001u) {
      total_size += 1 +
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::UInt64Size(
          this->_internal_io_handler_location_iid());
    }

    // optional bool sent_messages_in_queue = 1;
    if (cached_has_bits & 0x00000002u) {
      total_size += 1 + 1;
    }

  }
  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    total_size += _internal_metadata_.unknown_fields<std::string>(::PROTOBUF_NAMESPACE_ID::internal::GetEmptyString).size();
  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void ChromeMessagePump::CheckTypeAndMergeFrom(
    const ::PROTOBUF_NAMESPACE_ID::MessageLite& from) {
  MergeFrom(*::PROTOBUF_NAMESPACE_ID::internal::DownCast<const ChromeMessagePump*>(
      &from));
}

void ChromeMessagePump::MergeFrom(const ChromeMessagePump& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:perfetto.protos.ChromeMessagePump)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom<std::string>(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = from._has_bits_[0];
  if (cached_has_bits & 0x00000003u) {
    if (cached_has_bits & 0x00000001u) {
      io_handler_location_iid_ = from.io_handler_location_iid_;
    }
    if (cached_has_bits & 0x00000002u) {
      sent_messages_in_queue_ = from.sent_messages_in_queue_;
    }
    _has_bits_[0] |= cached_has_bits;
  }
}

void ChromeMessagePump::CopyFrom(const ChromeMessagePump& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:perfetto.protos.ChromeMessagePump)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool ChromeMessagePump::IsInitialized() const {
  return true;
}

void ChromeMessagePump::InternalSwap(ChromeMessagePump* other) {
  using std::swap;
  _internal_metadata_.Swap<std::string>(&other->_internal_metadata_);
  swap(_has_bits_[0], other->_has_bits_[0]);
  ::PROTOBUF_NAMESPACE_ID::internal::memswap<
      PROTOBUF_FIELD_OFFSET(ChromeMessagePump, sent_messages_in_queue_)
      + sizeof(ChromeMessagePump::sent_messages_in_queue_)
      - PROTOBUF_FIELD_OFFSET(ChromeMessagePump, io_handler_location_iid_)>(
          reinterpret_cast<char*>(&io_handler_location_iid_),
          reinterpret_cast<char*>(&other->io_handler_location_iid_));
}

std::string ChromeMessagePump::GetTypeName() const {
  return "perfetto.protos.ChromeMessagePump";
}


// @@protoc_insertion_point(namespace_scope)
}  // namespace protos
}  // namespace perfetto
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::perfetto::protos::ChromeMessagePump* Arena::CreateMaybeMessage< ::perfetto::protos::ChromeMessagePump >(Arena* arena) {
  return Arena::CreateMessageInternal< ::perfetto::protos::ChromeMessagePump >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
