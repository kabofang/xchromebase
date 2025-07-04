// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: protos/perfetto/trace/track_event/chrome_renderer_scheduler_state.proto

#include "protos/perfetto/trace/track_event/chrome_renderer_scheduler_state.pb.h"

#include <algorithm>

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/wire_format_lite.h>
#include <google/protobuf/io/zero_copy_stream_impl_lite.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
namespace perfetto {
namespace protos {
class ChromeRendererSchedulerStateDefaultTypeInternal {
 public:
  ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<ChromeRendererSchedulerState> _instance;
} _ChromeRendererSchedulerState_default_instance_;
}  // namespace protos
}  // namespace perfetto
static void InitDefaultsscc_info_ChromeRendererSchedulerState_protos_2fperfetto_2ftrace_2ftrack_5fevent_2fchrome_5frenderer_5fscheduler_5fstate_2eproto() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::perfetto::protos::_ChromeRendererSchedulerState_default_instance_;
    new (ptr) ::perfetto::protos::ChromeRendererSchedulerState();
    ::PROTOBUF_NAMESPACE_ID::internal::OnShutdownDestroyMessage(ptr);
  }
}

::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<0> scc_info_ChromeRendererSchedulerState_protos_2fperfetto_2ftrace_2ftrack_5fevent_2fchrome_5frenderer_5fscheduler_5fstate_2eproto =
    {{ATOMIC_VAR_INIT(::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase::kUninitialized), 0, 0, InitDefaultsscc_info_ChromeRendererSchedulerState_protos_2fperfetto_2ftrace_2ftrack_5fevent_2fchrome_5frenderer_5fscheduler_5fstate_2eproto}, {}};

namespace perfetto {
namespace protos {
bool ChromeRAILMode_IsValid(int value) {
  switch (value) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
      return true;
    default:
      return false;
  }
}

static ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<std::string> ChromeRAILMode_strings[5] = {};

static const char ChromeRAILMode_names[] =
  "RAIL_MODE_ANIMATION"
  "RAIL_MODE_IDLE"
  "RAIL_MODE_LOAD"
  "RAIL_MODE_NONE"
  "RAIL_MODE_RESPONSE";

static const ::PROTOBUF_NAMESPACE_ID::internal::EnumEntry ChromeRAILMode_entries[] = {
  { {ChromeRAILMode_names + 0, 19}, 2 },
  { {ChromeRAILMode_names + 19, 14}, 3 },
  { {ChromeRAILMode_names + 33, 14}, 4 },
  { {ChromeRAILMode_names + 47, 14}, 0 },
  { {ChromeRAILMode_names + 61, 18}, 1 },
};

static const int ChromeRAILMode_entries_by_number[] = {
  3, // 0 -> RAIL_MODE_NONE
  4, // 1 -> RAIL_MODE_RESPONSE
  0, // 2 -> RAIL_MODE_ANIMATION
  1, // 3 -> RAIL_MODE_IDLE
  2, // 4 -> RAIL_MODE_LOAD
};

const std::string& ChromeRAILMode_Name(
    ChromeRAILMode value) {
  static const bool dummy =
      ::PROTOBUF_NAMESPACE_ID::internal::InitializeEnumStrings(
          ChromeRAILMode_entries,
          ChromeRAILMode_entries_by_number,
          5, ChromeRAILMode_strings);
  (void) dummy;
  int idx = ::PROTOBUF_NAMESPACE_ID::internal::LookUpEnumName(
      ChromeRAILMode_entries,
      ChromeRAILMode_entries_by_number,
      5, value);
  return idx == -1 ? ::PROTOBUF_NAMESPACE_ID::internal::GetEmptyString() :
                     ChromeRAILMode_strings[idx].get();
}
bool ChromeRAILMode_Parse(
    ::PROTOBUF_NAMESPACE_ID::ConstStringParam name, ChromeRAILMode* value) {
  int int_value;
  bool success = ::PROTOBUF_NAMESPACE_ID::internal::LookUpEnumValue(
      ChromeRAILMode_entries, 5, name, &int_value);
  if (success) {
    *value = static_cast<ChromeRAILMode>(int_value);
  }
  return success;
}

// ===================================================================

class ChromeRendererSchedulerState::_Internal {
 public:
  using HasBits = decltype(std::declval<ChromeRendererSchedulerState>()._has_bits_);
  static void set_has_rail_mode(HasBits* has_bits) {
    (*has_bits)[0] |= 1u;
  }
  static void set_has_is_backgrounded(HasBits* has_bits) {
    (*has_bits)[0] |= 2u;
  }
  static void set_has_is_hidden(HasBits* has_bits) {
    (*has_bits)[0] |= 4u;
  }
};

ChromeRendererSchedulerState::ChromeRendererSchedulerState(::PROTOBUF_NAMESPACE_ID::Arena* arena)
  : ::PROTOBUF_NAMESPACE_ID::MessageLite(arena) {
  SharedCtor();
  RegisterArenaDtor(arena);
  // @@protoc_insertion_point(arena_constructor:perfetto.protos.ChromeRendererSchedulerState)
}
ChromeRendererSchedulerState::ChromeRendererSchedulerState(const ChromeRendererSchedulerState& from)
  : ::PROTOBUF_NAMESPACE_ID::MessageLite(),
      _has_bits_(from._has_bits_) {
  _internal_metadata_.MergeFrom<std::string>(from._internal_metadata_);
  ::memcpy(&rail_mode_, &from.rail_mode_,
    static_cast<size_t>(reinterpret_cast<char*>(&is_hidden_) -
    reinterpret_cast<char*>(&rail_mode_)) + sizeof(is_hidden_));
  // @@protoc_insertion_point(copy_constructor:perfetto.protos.ChromeRendererSchedulerState)
}

void ChromeRendererSchedulerState::SharedCtor() {
  ::memset(reinterpret_cast<char*>(this) + static_cast<size_t>(
      reinterpret_cast<char*>(&rail_mode_) - reinterpret_cast<char*>(this)),
      0, static_cast<size_t>(reinterpret_cast<char*>(&is_hidden_) -
      reinterpret_cast<char*>(&rail_mode_)) + sizeof(is_hidden_));
}

ChromeRendererSchedulerState::~ChromeRendererSchedulerState() {
  // @@protoc_insertion_point(destructor:perfetto.protos.ChromeRendererSchedulerState)
  SharedDtor();
  _internal_metadata_.Delete<std::string>();
}

void ChromeRendererSchedulerState::SharedDtor() {
  GOOGLE_DCHECK(GetArena() == nullptr);
}

void ChromeRendererSchedulerState::ArenaDtor(void* object) {
  ChromeRendererSchedulerState* _this = reinterpret_cast< ChromeRendererSchedulerState* >(object);
  (void)_this;
}
void ChromeRendererSchedulerState::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void ChromeRendererSchedulerState::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const ChromeRendererSchedulerState& ChromeRendererSchedulerState::default_instance() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&::scc_info_ChromeRendererSchedulerState_protos_2fperfetto_2ftrace_2ftrack_5fevent_2fchrome_5frenderer_5fscheduler_5fstate_2eproto.base);
  return *internal_default_instance();
}


void ChromeRendererSchedulerState::Clear() {
// @@protoc_insertion_point(message_clear_start:perfetto.protos.ChromeRendererSchedulerState)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  if (cached_has_bits & 0x00000007u) {
    ::memset(&rail_mode_, 0, static_cast<size_t>(
        reinterpret_cast<char*>(&is_hidden_) -
        reinterpret_cast<char*>(&rail_mode_)) + sizeof(is_hidden_));
  }
  _has_bits_.Clear();
  _internal_metadata_.Clear<std::string>();
}

const char* ChromeRendererSchedulerState::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  _Internal::HasBits has_bits{};
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    CHK_(ptr);
    switch (tag >> 3) {
      // optional .perfetto.protos.ChromeRAILMode rail_mode = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 8)) {
          ::PROTOBUF_NAMESPACE_ID::uint64 val = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
          if (PROTOBUF_PREDICT_TRUE(::perfetto::protos::ChromeRAILMode_IsValid(val))) {
            _internal_set_rail_mode(static_cast<::perfetto::protos::ChromeRAILMode>(val));
          } else {
            ::PROTOBUF_NAMESPACE_ID::internal::WriteVarint(1, val, mutable_unknown_fields());
          }
        } else goto handle_unusual;
        continue;
      // optional bool is_backgrounded = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 16)) {
          _Internal::set_has_is_backgrounded(&has_bits);
          is_backgrounded_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // optional bool is_hidden = 3;
      case 3:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 24)) {
          _Internal::set_has_is_hidden(&has_bits);
          is_hidden_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
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

::PROTOBUF_NAMESPACE_ID::uint8* ChromeRendererSchedulerState::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:perfetto.protos.ChromeRendererSchedulerState)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  // optional .perfetto.protos.ChromeRAILMode rail_mode = 1;
  if (cached_has_bits & 0x00000001u) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteEnumToArray(
      1, this->_internal_rail_mode(), target);
  }

  // optional bool is_backgrounded = 2;
  if (cached_has_bits & 0x00000002u) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteBoolToArray(2, this->_internal_is_backgrounded(), target);
  }

  // optional bool is_hidden = 3;
  if (cached_has_bits & 0x00000004u) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteBoolToArray(3, this->_internal_is_hidden(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = stream->WriteRaw(_internal_metadata_.unknown_fields<std::string>(::PROTOBUF_NAMESPACE_ID::internal::GetEmptyString).data(),
        static_cast<int>(_internal_metadata_.unknown_fields<std::string>(::PROTOBUF_NAMESPACE_ID::internal::GetEmptyString).size()), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:perfetto.protos.ChromeRendererSchedulerState)
  return target;
}

size_t ChromeRendererSchedulerState::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:perfetto.protos.ChromeRendererSchedulerState)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  if (cached_has_bits & 0x00000007u) {
    // optional .perfetto.protos.ChromeRAILMode rail_mode = 1;
    if (cached_has_bits & 0x00000001u) {
      total_size += 1 +
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::EnumSize(this->_internal_rail_mode());
    }

    // optional bool is_backgrounded = 2;
    if (cached_has_bits & 0x00000002u) {
      total_size += 1 + 1;
    }

    // optional bool is_hidden = 3;
    if (cached_has_bits & 0x00000004u) {
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

void ChromeRendererSchedulerState::CheckTypeAndMergeFrom(
    const ::PROTOBUF_NAMESPACE_ID::MessageLite& from) {
  MergeFrom(*::PROTOBUF_NAMESPACE_ID::internal::DownCast<const ChromeRendererSchedulerState*>(
      &from));
}

void ChromeRendererSchedulerState::MergeFrom(const ChromeRendererSchedulerState& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:perfetto.protos.ChromeRendererSchedulerState)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom<std::string>(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = from._has_bits_[0];
  if (cached_has_bits & 0x00000007u) {
    if (cached_has_bits & 0x00000001u) {
      rail_mode_ = from.rail_mode_;
    }
    if (cached_has_bits & 0x00000002u) {
      is_backgrounded_ = from.is_backgrounded_;
    }
    if (cached_has_bits & 0x00000004u) {
      is_hidden_ = from.is_hidden_;
    }
    _has_bits_[0] |= cached_has_bits;
  }
}

void ChromeRendererSchedulerState::CopyFrom(const ChromeRendererSchedulerState& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:perfetto.protos.ChromeRendererSchedulerState)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool ChromeRendererSchedulerState::IsInitialized() const {
  return true;
}

void ChromeRendererSchedulerState::InternalSwap(ChromeRendererSchedulerState* other) {
  using std::swap;
  _internal_metadata_.Swap<std::string>(&other->_internal_metadata_);
  swap(_has_bits_[0], other->_has_bits_[0]);
  ::PROTOBUF_NAMESPACE_ID::internal::memswap<
      PROTOBUF_FIELD_OFFSET(ChromeRendererSchedulerState, is_hidden_)
      + sizeof(ChromeRendererSchedulerState::is_hidden_)
      - PROTOBUF_FIELD_OFFSET(ChromeRendererSchedulerState, rail_mode_)>(
          reinterpret_cast<char*>(&rail_mode_),
          reinterpret_cast<char*>(&other->rail_mode_));
}

std::string ChromeRendererSchedulerState::GetTypeName() const {
  return "perfetto.protos.ChromeRendererSchedulerState";
}


// @@protoc_insertion_point(namespace_scope)
}  // namespace protos
}  // namespace perfetto
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::perfetto::protos::ChromeRendererSchedulerState* Arena::CreateMaybeMessage< ::perfetto::protos::ChromeRendererSchedulerState >(Arena* arena) {
  return Arena::CreateMessageInternal< ::perfetto::protos::ChromeRendererSchedulerState >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
