// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: protos/perfetto/trace/profiling/deobfuscation.proto

#include "protos/perfetto/trace/profiling/deobfuscation.pb.h"

#include <algorithm>

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/wire_format_lite.h>
#include <google/protobuf/io/zero_copy_stream_impl_lite.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
extern PROTOBUF_INTERNAL_EXPORT_protos_2fperfetto_2ftrace_2fprofiling_2fdeobfuscation_2eproto ::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<1> scc_info_ObfuscatedClass_protos_2fperfetto_2ftrace_2fprofiling_2fdeobfuscation_2eproto;
extern PROTOBUF_INTERNAL_EXPORT_protos_2fperfetto_2ftrace_2fprofiling_2fdeobfuscation_2eproto ::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<0> scc_info_ObfuscatedMember_protos_2fperfetto_2ftrace_2fprofiling_2fdeobfuscation_2eproto;
namespace perfetto {
namespace protos {
class ObfuscatedMemberDefaultTypeInternal {
 public:
  ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<ObfuscatedMember> _instance;
} _ObfuscatedMember_default_instance_;
class ObfuscatedClassDefaultTypeInternal {
 public:
  ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<ObfuscatedClass> _instance;
} _ObfuscatedClass_default_instance_;
class DeobfuscationMappingDefaultTypeInternal {
 public:
  ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<DeobfuscationMapping> _instance;
} _DeobfuscationMapping_default_instance_;
}  // namespace protos
}  // namespace perfetto
static void InitDefaultsscc_info_DeobfuscationMapping_protos_2fperfetto_2ftrace_2fprofiling_2fdeobfuscation_2eproto() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::perfetto::protos::_DeobfuscationMapping_default_instance_;
    new (ptr) ::perfetto::protos::DeobfuscationMapping();
    ::PROTOBUF_NAMESPACE_ID::internal::OnShutdownDestroyMessage(ptr);
  }
}

::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<1> scc_info_DeobfuscationMapping_protos_2fperfetto_2ftrace_2fprofiling_2fdeobfuscation_2eproto =
    {{ATOMIC_VAR_INIT(::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase::kUninitialized), 1, 0, InitDefaultsscc_info_DeobfuscationMapping_protos_2fperfetto_2ftrace_2fprofiling_2fdeobfuscation_2eproto}, {
      &scc_info_ObfuscatedClass_protos_2fperfetto_2ftrace_2fprofiling_2fdeobfuscation_2eproto.base,}};

static void InitDefaultsscc_info_ObfuscatedClass_protos_2fperfetto_2ftrace_2fprofiling_2fdeobfuscation_2eproto() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::perfetto::protos::_ObfuscatedClass_default_instance_;
    new (ptr) ::perfetto::protos::ObfuscatedClass();
    ::PROTOBUF_NAMESPACE_ID::internal::OnShutdownDestroyMessage(ptr);
  }
}

::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<1> scc_info_ObfuscatedClass_protos_2fperfetto_2ftrace_2fprofiling_2fdeobfuscation_2eproto =
    {{ATOMIC_VAR_INIT(::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase::kUninitialized), 1, 0, InitDefaultsscc_info_ObfuscatedClass_protos_2fperfetto_2ftrace_2fprofiling_2fdeobfuscation_2eproto}, {
      &scc_info_ObfuscatedMember_protos_2fperfetto_2ftrace_2fprofiling_2fdeobfuscation_2eproto.base,}};

static void InitDefaultsscc_info_ObfuscatedMember_protos_2fperfetto_2ftrace_2fprofiling_2fdeobfuscation_2eproto() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::perfetto::protos::_ObfuscatedMember_default_instance_;
    new (ptr) ::perfetto::protos::ObfuscatedMember();
    ::PROTOBUF_NAMESPACE_ID::internal::OnShutdownDestroyMessage(ptr);
  }
}

::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<0> scc_info_ObfuscatedMember_protos_2fperfetto_2ftrace_2fprofiling_2fdeobfuscation_2eproto =
    {{ATOMIC_VAR_INIT(::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase::kUninitialized), 0, 0, InitDefaultsscc_info_ObfuscatedMember_protos_2fperfetto_2ftrace_2fprofiling_2fdeobfuscation_2eproto}, {}};

namespace perfetto {
namespace protos {

// ===================================================================

class ObfuscatedMember::_Internal {
 public:
  using HasBits = decltype(std::declval<ObfuscatedMember>()._has_bits_);
  static void set_has_obfuscated_name(HasBits* has_bits) {
    (*has_bits)[0] |= 1u;
  }
  static void set_has_deobfuscated_name(HasBits* has_bits) {
    (*has_bits)[0] |= 2u;
  }
};

ObfuscatedMember::ObfuscatedMember(::PROTOBUF_NAMESPACE_ID::Arena* arena)
  : ::PROTOBUF_NAMESPACE_ID::MessageLite(arena) {
  SharedCtor();
  RegisterArenaDtor(arena);
  // @@protoc_insertion_point(arena_constructor:perfetto.protos.ObfuscatedMember)
}
ObfuscatedMember::ObfuscatedMember(const ObfuscatedMember& from)
  : ::PROTOBUF_NAMESPACE_ID::MessageLite(),
      _has_bits_(from._has_bits_) {
  _internal_metadata_.MergeFrom<std::string>(from._internal_metadata_);
  obfuscated_name_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (from._internal_has_obfuscated_name()) {
    obfuscated_name_.SetLite(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from._internal_obfuscated_name(),
      GetArena());
  }
  deobfuscated_name_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (from._internal_has_deobfuscated_name()) {
    deobfuscated_name_.SetLite(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from._internal_deobfuscated_name(),
      GetArena());
  }
  // @@protoc_insertion_point(copy_constructor:perfetto.protos.ObfuscatedMember)
}

void ObfuscatedMember::SharedCtor() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&scc_info_ObfuscatedMember_protos_2fperfetto_2ftrace_2fprofiling_2fdeobfuscation_2eproto.base);
  obfuscated_name_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  deobfuscated_name_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}

ObfuscatedMember::~ObfuscatedMember() {
  // @@protoc_insertion_point(destructor:perfetto.protos.ObfuscatedMember)
  SharedDtor();
  _internal_metadata_.Delete<std::string>();
}

void ObfuscatedMember::SharedDtor() {
  GOOGLE_DCHECK(GetArena() == nullptr);
  obfuscated_name_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  deobfuscated_name_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}

void ObfuscatedMember::ArenaDtor(void* object) {
  ObfuscatedMember* _this = reinterpret_cast< ObfuscatedMember* >(object);
  (void)_this;
}
void ObfuscatedMember::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void ObfuscatedMember::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const ObfuscatedMember& ObfuscatedMember::default_instance() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&::scc_info_ObfuscatedMember_protos_2fperfetto_2ftrace_2fprofiling_2fdeobfuscation_2eproto.base);
  return *internal_default_instance();
}


void ObfuscatedMember::Clear() {
// @@protoc_insertion_point(message_clear_start:perfetto.protos.ObfuscatedMember)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  if (cached_has_bits & 0x00000003u) {
    if (cached_has_bits & 0x00000001u) {
      obfuscated_name_.ClearNonDefaultToEmpty();
    }
    if (cached_has_bits & 0x00000002u) {
      deobfuscated_name_.ClearNonDefaultToEmpty();
    }
  }
  _has_bits_.Clear();
  _internal_metadata_.Clear<std::string>();
}

const char* ObfuscatedMember::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  _Internal::HasBits has_bits{};
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    CHK_(ptr);
    switch (tag >> 3) {
      // optional string obfuscated_name = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 10)) {
          auto str = _internal_mutable_obfuscated_name();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // optional string deobfuscated_name = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 18)) {
          auto str = _internal_mutable_deobfuscated_name();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
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

::PROTOBUF_NAMESPACE_ID::uint8* ObfuscatedMember::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:perfetto.protos.ObfuscatedMember)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  // optional string obfuscated_name = 1;
  if (cached_has_bits & 0x00000001u) {
    target = stream->WriteStringMaybeAliased(
        1, this->_internal_obfuscated_name(), target);
  }

  // optional string deobfuscated_name = 2;
  if (cached_has_bits & 0x00000002u) {
    target = stream->WriteStringMaybeAliased(
        2, this->_internal_deobfuscated_name(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = stream->WriteRaw(_internal_metadata_.unknown_fields<std::string>(::PROTOBUF_NAMESPACE_ID::internal::GetEmptyString).data(),
        static_cast<int>(_internal_metadata_.unknown_fields<std::string>(::PROTOBUF_NAMESPACE_ID::internal::GetEmptyString).size()), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:perfetto.protos.ObfuscatedMember)
  return target;
}

size_t ObfuscatedMember::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:perfetto.protos.ObfuscatedMember)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  if (cached_has_bits & 0x00000003u) {
    // optional string obfuscated_name = 1;
    if (cached_has_bits & 0x00000001u) {
      total_size += 1 +
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
          this->_internal_obfuscated_name());
    }

    // optional string deobfuscated_name = 2;
    if (cached_has_bits & 0x00000002u) {
      total_size += 1 +
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
          this->_internal_deobfuscated_name());
    }

  }
  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    total_size += _internal_metadata_.unknown_fields<std::string>(::PROTOBUF_NAMESPACE_ID::internal::GetEmptyString).size();
  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void ObfuscatedMember::CheckTypeAndMergeFrom(
    const ::PROTOBUF_NAMESPACE_ID::MessageLite& from) {
  MergeFrom(*::PROTOBUF_NAMESPACE_ID::internal::DownCast<const ObfuscatedMember*>(
      &from));
}

void ObfuscatedMember::MergeFrom(const ObfuscatedMember& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:perfetto.protos.ObfuscatedMember)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom<std::string>(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = from._has_bits_[0];
  if (cached_has_bits & 0x00000003u) {
    if (cached_has_bits & 0x00000001u) {
      _internal_set_obfuscated_name(from._internal_obfuscated_name());
    }
    if (cached_has_bits & 0x00000002u) {
      _internal_set_deobfuscated_name(from._internal_deobfuscated_name());
    }
  }
}

void ObfuscatedMember::CopyFrom(const ObfuscatedMember& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:perfetto.protos.ObfuscatedMember)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool ObfuscatedMember::IsInitialized() const {
  return true;
}

void ObfuscatedMember::InternalSwap(ObfuscatedMember* other) {
  using std::swap;
  _internal_metadata_.Swap<std::string>(&other->_internal_metadata_);
  swap(_has_bits_[0], other->_has_bits_[0]);
  obfuscated_name_.Swap(&other->obfuscated_name_, &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
  deobfuscated_name_.Swap(&other->deobfuscated_name_, &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}

std::string ObfuscatedMember::GetTypeName() const {
  return "perfetto.protos.ObfuscatedMember";
}


// ===================================================================

class ObfuscatedClass::_Internal {
 public:
  using HasBits = decltype(std::declval<ObfuscatedClass>()._has_bits_);
  static void set_has_obfuscated_name(HasBits* has_bits) {
    (*has_bits)[0] |= 1u;
  }
  static void set_has_deobfuscated_name(HasBits* has_bits) {
    (*has_bits)[0] |= 2u;
  }
};

ObfuscatedClass::ObfuscatedClass(::PROTOBUF_NAMESPACE_ID::Arena* arena)
  : ::PROTOBUF_NAMESPACE_ID::MessageLite(arena),
  obfuscated_members_(arena),
  obfuscated_methods_(arena) {
  SharedCtor();
  RegisterArenaDtor(arena);
  // @@protoc_insertion_point(arena_constructor:perfetto.protos.ObfuscatedClass)
}
ObfuscatedClass::ObfuscatedClass(const ObfuscatedClass& from)
  : ::PROTOBUF_NAMESPACE_ID::MessageLite(),
      _has_bits_(from._has_bits_),
      obfuscated_members_(from.obfuscated_members_),
      obfuscated_methods_(from.obfuscated_methods_) {
  _internal_metadata_.MergeFrom<std::string>(from._internal_metadata_);
  obfuscated_name_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (from._internal_has_obfuscated_name()) {
    obfuscated_name_.SetLite(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from._internal_obfuscated_name(),
      GetArena());
  }
  deobfuscated_name_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (from._internal_has_deobfuscated_name()) {
    deobfuscated_name_.SetLite(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from._internal_deobfuscated_name(),
      GetArena());
  }
  // @@protoc_insertion_point(copy_constructor:perfetto.protos.ObfuscatedClass)
}

void ObfuscatedClass::SharedCtor() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&scc_info_ObfuscatedClass_protos_2fperfetto_2ftrace_2fprofiling_2fdeobfuscation_2eproto.base);
  obfuscated_name_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  deobfuscated_name_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}

ObfuscatedClass::~ObfuscatedClass() {
  // @@protoc_insertion_point(destructor:perfetto.protos.ObfuscatedClass)
  SharedDtor();
  _internal_metadata_.Delete<std::string>();
}

void ObfuscatedClass::SharedDtor() {
  GOOGLE_DCHECK(GetArena() == nullptr);
  obfuscated_name_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  deobfuscated_name_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}

void ObfuscatedClass::ArenaDtor(void* object) {
  ObfuscatedClass* _this = reinterpret_cast< ObfuscatedClass* >(object);
  (void)_this;
}
void ObfuscatedClass::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void ObfuscatedClass::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const ObfuscatedClass& ObfuscatedClass::default_instance() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&::scc_info_ObfuscatedClass_protos_2fperfetto_2ftrace_2fprofiling_2fdeobfuscation_2eproto.base);
  return *internal_default_instance();
}


void ObfuscatedClass::Clear() {
// @@protoc_insertion_point(message_clear_start:perfetto.protos.ObfuscatedClass)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  obfuscated_members_.Clear();
  obfuscated_methods_.Clear();
  cached_has_bits = _has_bits_[0];
  if (cached_has_bits & 0x00000003u) {
    if (cached_has_bits & 0x00000001u) {
      obfuscated_name_.ClearNonDefaultToEmpty();
    }
    if (cached_has_bits & 0x00000002u) {
      deobfuscated_name_.ClearNonDefaultToEmpty();
    }
  }
  _has_bits_.Clear();
  _internal_metadata_.Clear<std::string>();
}

const char* ObfuscatedClass::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  _Internal::HasBits has_bits{};
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    CHK_(ptr);
    switch (tag >> 3) {
      // optional string obfuscated_name = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 10)) {
          auto str = _internal_mutable_obfuscated_name();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // optional string deobfuscated_name = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 18)) {
          auto str = _internal_mutable_deobfuscated_name();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // repeated .perfetto.protos.ObfuscatedMember obfuscated_members = 3;
      case 3:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 26)) {
          ptr -= 1;
          do {
            ptr += 1;
            ptr = ctx->ParseMessage(_internal_add_obfuscated_members(), ptr);
            CHK_(ptr);
            if (!ctx->DataAvailable(ptr)) break;
          } while (::PROTOBUF_NAMESPACE_ID::internal::ExpectTag<26>(ptr));
        } else goto handle_unusual;
        continue;
      // repeated .perfetto.protos.ObfuscatedMember obfuscated_methods = 4;
      case 4:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 34)) {
          ptr -= 1;
          do {
            ptr += 1;
            ptr = ctx->ParseMessage(_internal_add_obfuscated_methods(), ptr);
            CHK_(ptr);
            if (!ctx->DataAvailable(ptr)) break;
          } while (::PROTOBUF_NAMESPACE_ID::internal::ExpectTag<34>(ptr));
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

::PROTOBUF_NAMESPACE_ID::uint8* ObfuscatedClass::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:perfetto.protos.ObfuscatedClass)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  // optional string obfuscated_name = 1;
  if (cached_has_bits & 0x00000001u) {
    target = stream->WriteStringMaybeAliased(
        1, this->_internal_obfuscated_name(), target);
  }

  // optional string deobfuscated_name = 2;
  if (cached_has_bits & 0x00000002u) {
    target = stream->WriteStringMaybeAliased(
        2, this->_internal_deobfuscated_name(), target);
  }

  // repeated .perfetto.protos.ObfuscatedMember obfuscated_members = 3;
  for (unsigned int i = 0,
      n = static_cast<unsigned int>(this->_internal_obfuscated_members_size()); i < n; i++) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessage(3, this->_internal_obfuscated_members(i), target, stream);
  }

  // repeated .perfetto.protos.ObfuscatedMember obfuscated_methods = 4;
  for (unsigned int i = 0,
      n = static_cast<unsigned int>(this->_internal_obfuscated_methods_size()); i < n; i++) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessage(4, this->_internal_obfuscated_methods(i), target, stream);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = stream->WriteRaw(_internal_metadata_.unknown_fields<std::string>(::PROTOBUF_NAMESPACE_ID::internal::GetEmptyString).data(),
        static_cast<int>(_internal_metadata_.unknown_fields<std::string>(::PROTOBUF_NAMESPACE_ID::internal::GetEmptyString).size()), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:perfetto.protos.ObfuscatedClass)
  return target;
}

size_t ObfuscatedClass::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:perfetto.protos.ObfuscatedClass)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // repeated .perfetto.protos.ObfuscatedMember obfuscated_members = 3;
  total_size += 1UL * this->_internal_obfuscated_members_size();
  for (const auto& msg : this->obfuscated_members_) {
    total_size +=
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(msg);
  }

  // repeated .perfetto.protos.ObfuscatedMember obfuscated_methods = 4;
  total_size += 1UL * this->_internal_obfuscated_methods_size();
  for (const auto& msg : this->obfuscated_methods_) {
    total_size +=
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(msg);
  }

  cached_has_bits = _has_bits_[0];
  if (cached_has_bits & 0x00000003u) {
    // optional string obfuscated_name = 1;
    if (cached_has_bits & 0x00000001u) {
      total_size += 1 +
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
          this->_internal_obfuscated_name());
    }

    // optional string deobfuscated_name = 2;
    if (cached_has_bits & 0x00000002u) {
      total_size += 1 +
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
          this->_internal_deobfuscated_name());
    }

  }
  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    total_size += _internal_metadata_.unknown_fields<std::string>(::PROTOBUF_NAMESPACE_ID::internal::GetEmptyString).size();
  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void ObfuscatedClass::CheckTypeAndMergeFrom(
    const ::PROTOBUF_NAMESPACE_ID::MessageLite& from) {
  MergeFrom(*::PROTOBUF_NAMESPACE_ID::internal::DownCast<const ObfuscatedClass*>(
      &from));
}

void ObfuscatedClass::MergeFrom(const ObfuscatedClass& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:perfetto.protos.ObfuscatedClass)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom<std::string>(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  obfuscated_members_.MergeFrom(from.obfuscated_members_);
  obfuscated_methods_.MergeFrom(from.obfuscated_methods_);
  cached_has_bits = from._has_bits_[0];
  if (cached_has_bits & 0x00000003u) {
    if (cached_has_bits & 0x00000001u) {
      _internal_set_obfuscated_name(from._internal_obfuscated_name());
    }
    if (cached_has_bits & 0x00000002u) {
      _internal_set_deobfuscated_name(from._internal_deobfuscated_name());
    }
  }
}

void ObfuscatedClass::CopyFrom(const ObfuscatedClass& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:perfetto.protos.ObfuscatedClass)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool ObfuscatedClass::IsInitialized() const {
  return true;
}

void ObfuscatedClass::InternalSwap(ObfuscatedClass* other) {
  using std::swap;
  _internal_metadata_.Swap<std::string>(&other->_internal_metadata_);
  swap(_has_bits_[0], other->_has_bits_[0]);
  obfuscated_members_.InternalSwap(&other->obfuscated_members_);
  obfuscated_methods_.InternalSwap(&other->obfuscated_methods_);
  obfuscated_name_.Swap(&other->obfuscated_name_, &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
  deobfuscated_name_.Swap(&other->deobfuscated_name_, &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}

std::string ObfuscatedClass::GetTypeName() const {
  return "perfetto.protos.ObfuscatedClass";
}


// ===================================================================

class DeobfuscationMapping::_Internal {
 public:
  using HasBits = decltype(std::declval<DeobfuscationMapping>()._has_bits_);
  static void set_has_package_name(HasBits* has_bits) {
    (*has_bits)[0] |= 1u;
  }
  static void set_has_version_code(HasBits* has_bits) {
    (*has_bits)[0] |= 2u;
  }
};

DeobfuscationMapping::DeobfuscationMapping(::PROTOBUF_NAMESPACE_ID::Arena* arena)
  : ::PROTOBUF_NAMESPACE_ID::MessageLite(arena),
  obfuscated_classes_(arena) {
  SharedCtor();
  RegisterArenaDtor(arena);
  // @@protoc_insertion_point(arena_constructor:perfetto.protos.DeobfuscationMapping)
}
DeobfuscationMapping::DeobfuscationMapping(const DeobfuscationMapping& from)
  : ::PROTOBUF_NAMESPACE_ID::MessageLite(),
      _has_bits_(from._has_bits_),
      obfuscated_classes_(from.obfuscated_classes_) {
  _internal_metadata_.MergeFrom<std::string>(from._internal_metadata_);
  package_name_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (from._internal_has_package_name()) {
    package_name_.SetLite(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from._internal_package_name(),
      GetArena());
  }
  version_code_ = from.version_code_;
  // @@protoc_insertion_point(copy_constructor:perfetto.protos.DeobfuscationMapping)
}

void DeobfuscationMapping::SharedCtor() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&scc_info_DeobfuscationMapping_protos_2fperfetto_2ftrace_2fprofiling_2fdeobfuscation_2eproto.base);
  package_name_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  version_code_ = PROTOBUF_LONGLONG(0);
}

DeobfuscationMapping::~DeobfuscationMapping() {
  // @@protoc_insertion_point(destructor:perfetto.protos.DeobfuscationMapping)
  SharedDtor();
  _internal_metadata_.Delete<std::string>();
}

void DeobfuscationMapping::SharedDtor() {
  GOOGLE_DCHECK(GetArena() == nullptr);
  package_name_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}

void DeobfuscationMapping::ArenaDtor(void* object) {
  DeobfuscationMapping* _this = reinterpret_cast< DeobfuscationMapping* >(object);
  (void)_this;
}
void DeobfuscationMapping::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void DeobfuscationMapping::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const DeobfuscationMapping& DeobfuscationMapping::default_instance() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&::scc_info_DeobfuscationMapping_protos_2fperfetto_2ftrace_2fprofiling_2fdeobfuscation_2eproto.base);
  return *internal_default_instance();
}


void DeobfuscationMapping::Clear() {
// @@protoc_insertion_point(message_clear_start:perfetto.protos.DeobfuscationMapping)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  obfuscated_classes_.Clear();
  cached_has_bits = _has_bits_[0];
  if (cached_has_bits & 0x00000001u) {
    package_name_.ClearNonDefaultToEmpty();
  }
  version_code_ = PROTOBUF_LONGLONG(0);
  _has_bits_.Clear();
  _internal_metadata_.Clear<std::string>();
}

const char* DeobfuscationMapping::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  _Internal::HasBits has_bits{};
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    CHK_(ptr);
    switch (tag >> 3) {
      // optional string package_name = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 10)) {
          auto str = _internal_mutable_package_name();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // optional int64 version_code = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 16)) {
          _Internal::set_has_version_code(&has_bits);
          version_code_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // repeated .perfetto.protos.ObfuscatedClass obfuscated_classes = 3;
      case 3:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 26)) {
          ptr -= 1;
          do {
            ptr += 1;
            ptr = ctx->ParseMessage(_internal_add_obfuscated_classes(), ptr);
            CHK_(ptr);
            if (!ctx->DataAvailable(ptr)) break;
          } while (::PROTOBUF_NAMESPACE_ID::internal::ExpectTag<26>(ptr));
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

::PROTOBUF_NAMESPACE_ID::uint8* DeobfuscationMapping::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:perfetto.protos.DeobfuscationMapping)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  // optional string package_name = 1;
  if (cached_has_bits & 0x00000001u) {
    target = stream->WriteStringMaybeAliased(
        1, this->_internal_package_name(), target);
  }

  // optional int64 version_code = 2;
  if (cached_has_bits & 0x00000002u) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteInt64ToArray(2, this->_internal_version_code(), target);
  }

  // repeated .perfetto.protos.ObfuscatedClass obfuscated_classes = 3;
  for (unsigned int i = 0,
      n = static_cast<unsigned int>(this->_internal_obfuscated_classes_size()); i < n; i++) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessage(3, this->_internal_obfuscated_classes(i), target, stream);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = stream->WriteRaw(_internal_metadata_.unknown_fields<std::string>(::PROTOBUF_NAMESPACE_ID::internal::GetEmptyString).data(),
        static_cast<int>(_internal_metadata_.unknown_fields<std::string>(::PROTOBUF_NAMESPACE_ID::internal::GetEmptyString).size()), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:perfetto.protos.DeobfuscationMapping)
  return target;
}

size_t DeobfuscationMapping::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:perfetto.protos.DeobfuscationMapping)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // repeated .perfetto.protos.ObfuscatedClass obfuscated_classes = 3;
  total_size += 1UL * this->_internal_obfuscated_classes_size();
  for (const auto& msg : this->obfuscated_classes_) {
    total_size +=
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(msg);
  }

  cached_has_bits = _has_bits_[0];
  if (cached_has_bits & 0x00000003u) {
    // optional string package_name = 1;
    if (cached_has_bits & 0x00000001u) {
      total_size += 1 +
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
          this->_internal_package_name());
    }

    // optional int64 version_code = 2;
    if (cached_has_bits & 0x00000002u) {
      total_size += 1 +
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::Int64Size(
          this->_internal_version_code());
    }

  }
  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    total_size += _internal_metadata_.unknown_fields<std::string>(::PROTOBUF_NAMESPACE_ID::internal::GetEmptyString).size();
  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void DeobfuscationMapping::CheckTypeAndMergeFrom(
    const ::PROTOBUF_NAMESPACE_ID::MessageLite& from) {
  MergeFrom(*::PROTOBUF_NAMESPACE_ID::internal::DownCast<const DeobfuscationMapping*>(
      &from));
}

void DeobfuscationMapping::MergeFrom(const DeobfuscationMapping& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:perfetto.protos.DeobfuscationMapping)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom<std::string>(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  obfuscated_classes_.MergeFrom(from.obfuscated_classes_);
  cached_has_bits = from._has_bits_[0];
  if (cached_has_bits & 0x00000003u) {
    if (cached_has_bits & 0x00000001u) {
      _internal_set_package_name(from._internal_package_name());
    }
    if (cached_has_bits & 0x00000002u) {
      version_code_ = from.version_code_;
    }
    _has_bits_[0] |= cached_has_bits;
  }
}

void DeobfuscationMapping::CopyFrom(const DeobfuscationMapping& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:perfetto.protos.DeobfuscationMapping)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool DeobfuscationMapping::IsInitialized() const {
  return true;
}

void DeobfuscationMapping::InternalSwap(DeobfuscationMapping* other) {
  using std::swap;
  _internal_metadata_.Swap<std::string>(&other->_internal_metadata_);
  swap(_has_bits_[0], other->_has_bits_[0]);
  obfuscated_classes_.InternalSwap(&other->obfuscated_classes_);
  package_name_.Swap(&other->package_name_, &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
  swap(version_code_, other->version_code_);
}

std::string DeobfuscationMapping::GetTypeName() const {
  return "perfetto.protos.DeobfuscationMapping";
}


// @@protoc_insertion_point(namespace_scope)
}  // namespace protos
}  // namespace perfetto
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::perfetto::protos::ObfuscatedMember* Arena::CreateMaybeMessage< ::perfetto::protos::ObfuscatedMember >(Arena* arena) {
  return Arena::CreateMessageInternal< ::perfetto::protos::ObfuscatedMember >(arena);
}
template<> PROTOBUF_NOINLINE ::perfetto::protos::ObfuscatedClass* Arena::CreateMaybeMessage< ::perfetto::protos::ObfuscatedClass >(Arena* arena) {
  return Arena::CreateMessageInternal< ::perfetto::protos::ObfuscatedClass >(arena);
}
template<> PROTOBUF_NOINLINE ::perfetto::protos::DeobfuscationMapping* Arena::CreateMaybeMessage< ::perfetto::protos::DeobfuscationMapping >(Arena* arena) {
  return Arena::CreateMessageInternal< ::perfetto::protos::DeobfuscationMapping >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
