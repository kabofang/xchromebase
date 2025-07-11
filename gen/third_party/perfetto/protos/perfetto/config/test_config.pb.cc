// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: protos/perfetto/config/test_config.proto

#include "protos/perfetto/config/test_config.pb.h"

#include <algorithm>

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/wire_format_lite.h>
#include <google/protobuf/io/zero_copy_stream_impl_lite.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
extern PROTOBUF_INTERNAL_EXPORT_protos_2fperfetto_2fconfig_2ftest_5fconfig_2eproto ::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<0> scc_info_TestConfig_DummyFields_protos_2fperfetto_2fconfig_2ftest_5fconfig_2eproto;
namespace perfetto {
namespace protos {
class TestConfig_DummyFieldsDefaultTypeInternal {
 public:
  ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<TestConfig_DummyFields> _instance;
} _TestConfig_DummyFields_default_instance_;
class TestConfigDefaultTypeInternal {
 public:
  ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<TestConfig> _instance;
} _TestConfig_default_instance_;
}  // namespace protos
}  // namespace perfetto
static void InitDefaultsscc_info_TestConfig_protos_2fperfetto_2fconfig_2ftest_5fconfig_2eproto() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::perfetto::protos::_TestConfig_default_instance_;
    new (ptr) ::perfetto::protos::TestConfig();
    ::PROTOBUF_NAMESPACE_ID::internal::OnShutdownDestroyMessage(ptr);
  }
}

::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<1> scc_info_TestConfig_protos_2fperfetto_2fconfig_2ftest_5fconfig_2eproto =
    {{ATOMIC_VAR_INIT(::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase::kUninitialized), 1, 0, InitDefaultsscc_info_TestConfig_protos_2fperfetto_2fconfig_2ftest_5fconfig_2eproto}, {
      &scc_info_TestConfig_DummyFields_protos_2fperfetto_2fconfig_2ftest_5fconfig_2eproto.base,}};

static void InitDefaultsscc_info_TestConfig_DummyFields_protos_2fperfetto_2fconfig_2ftest_5fconfig_2eproto() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::perfetto::protos::_TestConfig_DummyFields_default_instance_;
    new (ptr) ::perfetto::protos::TestConfig_DummyFields();
    ::PROTOBUF_NAMESPACE_ID::internal::OnShutdownDestroyMessage(ptr);
  }
}

::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<0> scc_info_TestConfig_DummyFields_protos_2fperfetto_2fconfig_2ftest_5fconfig_2eproto =
    {{ATOMIC_VAR_INIT(::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase::kUninitialized), 0, 0, InitDefaultsscc_info_TestConfig_DummyFields_protos_2fperfetto_2fconfig_2ftest_5fconfig_2eproto}, {}};

namespace perfetto {
namespace protos {

// ===================================================================

class TestConfig_DummyFields::_Internal {
 public:
  using HasBits = decltype(std::declval<TestConfig_DummyFields>()._has_bits_);
  static void set_has_field_uint32(HasBits* has_bits) {
    (*has_bits)[0] |= 4u;
  }
  static void set_has_field_int32(HasBits* has_bits) {
    (*has_bits)[0] |= 8u;
  }
  static void set_has_field_uint64(HasBits* has_bits) {
    (*has_bits)[0] |= 16u;
  }
  static void set_has_field_int64(HasBits* has_bits) {
    (*has_bits)[0] |= 32u;
  }
  static void set_has_field_fixed64(HasBits* has_bits) {
    (*has_bits)[0] |= 64u;
  }
  static void set_has_field_sfixed64(HasBits* has_bits) {
    (*has_bits)[0] |= 128u;
  }
  static void set_has_field_fixed32(HasBits* has_bits) {
    (*has_bits)[0] |= 256u;
  }
  static void set_has_field_sfixed32(HasBits* has_bits) {
    (*has_bits)[0] |= 512u;
  }
  static void set_has_field_double(HasBits* has_bits) {
    (*has_bits)[0] |= 1024u;
  }
  static void set_has_field_float(HasBits* has_bits) {
    (*has_bits)[0] |= 4096u;
  }
  static void set_has_field_sint64(HasBits* has_bits) {
    (*has_bits)[0] |= 2048u;
  }
  static void set_has_field_sint32(HasBits* has_bits) {
    (*has_bits)[0] |= 8192u;
  }
  static void set_has_field_string(HasBits* has_bits) {
    (*has_bits)[0] |= 1u;
  }
  static void set_has_field_bytes(HasBits* has_bits) {
    (*has_bits)[0] |= 2u;
  }
};

TestConfig_DummyFields::TestConfig_DummyFields(::PROTOBUF_NAMESPACE_ID::Arena* arena)
  : ::PROTOBUF_NAMESPACE_ID::MessageLite(arena) {
  SharedCtor();
  RegisterArenaDtor(arena);
  // @@protoc_insertion_point(arena_constructor:perfetto.protos.TestConfig.DummyFields)
}
TestConfig_DummyFields::TestConfig_DummyFields(const TestConfig_DummyFields& from)
  : ::PROTOBUF_NAMESPACE_ID::MessageLite(),
      _has_bits_(from._has_bits_) {
  _internal_metadata_.MergeFrom<std::string>(from._internal_metadata_);
  field_string_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (from._internal_has_field_string()) {
    field_string_.SetLite(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from._internal_field_string(),
      GetArena());
  }
  field_bytes_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (from._internal_has_field_bytes()) {
    field_bytes_.SetLite(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from._internal_field_bytes(),
      GetArena());
  }
  ::memcpy(&field_uint32_, &from.field_uint32_,
    static_cast<size_t>(reinterpret_cast<char*>(&field_sint32_) -
    reinterpret_cast<char*>(&field_uint32_)) + sizeof(field_sint32_));
  // @@protoc_insertion_point(copy_constructor:perfetto.protos.TestConfig.DummyFields)
}

void TestConfig_DummyFields::SharedCtor() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&scc_info_TestConfig_DummyFields_protos_2fperfetto_2fconfig_2ftest_5fconfig_2eproto.base);
  field_string_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  field_bytes_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  ::memset(reinterpret_cast<char*>(this) + static_cast<size_t>(
      reinterpret_cast<char*>(&field_uint32_) - reinterpret_cast<char*>(this)),
      0, static_cast<size_t>(reinterpret_cast<char*>(&field_sint32_) -
      reinterpret_cast<char*>(&field_uint32_)) + sizeof(field_sint32_));
}

TestConfig_DummyFields::~TestConfig_DummyFields() {
  // @@protoc_insertion_point(destructor:perfetto.protos.TestConfig.DummyFields)
  SharedDtor();
  _internal_metadata_.Delete<std::string>();
}

void TestConfig_DummyFields::SharedDtor() {
  GOOGLE_DCHECK(GetArena() == nullptr);
  field_string_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  field_bytes_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}

void TestConfig_DummyFields::ArenaDtor(void* object) {
  TestConfig_DummyFields* _this = reinterpret_cast< TestConfig_DummyFields* >(object);
  (void)_this;
}
void TestConfig_DummyFields::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void TestConfig_DummyFields::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const TestConfig_DummyFields& TestConfig_DummyFields::default_instance() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&::scc_info_TestConfig_DummyFields_protos_2fperfetto_2fconfig_2ftest_5fconfig_2eproto.base);
  return *internal_default_instance();
}


void TestConfig_DummyFields::Clear() {
// @@protoc_insertion_point(message_clear_start:perfetto.protos.TestConfig.DummyFields)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  if (cached_has_bits & 0x00000003u) {
    if (cached_has_bits & 0x00000001u) {
      field_string_.ClearNonDefaultToEmpty();
    }
    if (cached_has_bits & 0x00000002u) {
      field_bytes_.ClearNonDefaultToEmpty();
    }
  }
  if (cached_has_bits & 0x000000fcu) {
    ::memset(&field_uint32_, 0, static_cast<size_t>(
        reinterpret_cast<char*>(&field_sfixed64_) -
        reinterpret_cast<char*>(&field_uint32_)) + sizeof(field_sfixed64_));
  }
  if (cached_has_bits & 0x00003f00u) {
    ::memset(&field_fixed32_, 0, static_cast<size_t>(
        reinterpret_cast<char*>(&field_sint32_) -
        reinterpret_cast<char*>(&field_fixed32_)) + sizeof(field_sint32_));
  }
  _has_bits_.Clear();
  _internal_metadata_.Clear<std::string>();
}

const char* TestConfig_DummyFields::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  _Internal::HasBits has_bits{};
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    CHK_(ptr);
    switch (tag >> 3) {
      // optional uint32 field_uint32 = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 8)) {
          _Internal::set_has_field_uint32(&has_bits);
          field_uint32_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint32(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // optional int32 field_int32 = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 16)) {
          _Internal::set_has_field_int32(&has_bits);
          field_int32_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // optional uint64 field_uint64 = 3;
      case 3:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 24)) {
          _Internal::set_has_field_uint64(&has_bits);
          field_uint64_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // optional int64 field_int64 = 4;
      case 4:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 32)) {
          _Internal::set_has_field_int64(&has_bits);
          field_int64_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // optional fixed64 field_fixed64 = 5;
      case 5:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 41)) {
          _Internal::set_has_field_fixed64(&has_bits);
          field_fixed64_ = ::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<::PROTOBUF_NAMESPACE_ID::uint64>(ptr);
          ptr += sizeof(::PROTOBUF_NAMESPACE_ID::uint64);
        } else goto handle_unusual;
        continue;
      // optional sfixed64 field_sfixed64 = 6;
      case 6:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 49)) {
          _Internal::set_has_field_sfixed64(&has_bits);
          field_sfixed64_ = ::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<::PROTOBUF_NAMESPACE_ID::int64>(ptr);
          ptr += sizeof(::PROTOBUF_NAMESPACE_ID::int64);
        } else goto handle_unusual;
        continue;
      // optional fixed32 field_fixed32 = 7;
      case 7:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 61)) {
          _Internal::set_has_field_fixed32(&has_bits);
          field_fixed32_ = ::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<::PROTOBUF_NAMESPACE_ID::uint32>(ptr);
          ptr += sizeof(::PROTOBUF_NAMESPACE_ID::uint32);
        } else goto handle_unusual;
        continue;
      // optional sfixed32 field_sfixed32 = 8;
      case 8:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 69)) {
          _Internal::set_has_field_sfixed32(&has_bits);
          field_sfixed32_ = ::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<::PROTOBUF_NAMESPACE_ID::int32>(ptr);
          ptr += sizeof(::PROTOBUF_NAMESPACE_ID::int32);
        } else goto handle_unusual;
        continue;
      // optional double field_double = 9;
      case 9:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 73)) {
          _Internal::set_has_field_double(&has_bits);
          field_double_ = ::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<double>(ptr);
          ptr += sizeof(double);
        } else goto handle_unusual;
        continue;
      // optional float field_float = 10;
      case 10:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 85)) {
          _Internal::set_has_field_float(&has_bits);
          field_float_ = ::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<float>(ptr);
          ptr += sizeof(float);
        } else goto handle_unusual;
        continue;
      // optional sint64 field_sint64 = 11;
      case 11:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 88)) {
          _Internal::set_has_field_sint64(&has_bits);
          field_sint64_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarintZigZag64(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // optional sint32 field_sint32 = 12;
      case 12:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 96)) {
          _Internal::set_has_field_sint32(&has_bits);
          field_sint32_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarintZigZag32(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // optional string field_string = 13;
      case 13:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 106)) {
          auto str = _internal_mutable_field_string();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // optional bytes field_bytes = 14;
      case 14:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 114)) {
          auto str = _internal_mutable_field_bytes();
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

::PROTOBUF_NAMESPACE_ID::uint8* TestConfig_DummyFields::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:perfetto.protos.TestConfig.DummyFields)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  // optional uint32 field_uint32 = 1;
  if (cached_has_bits & 0x00000004u) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteUInt32ToArray(1, this->_internal_field_uint32(), target);
  }

  // optional int32 field_int32 = 2;
  if (cached_has_bits & 0x00000008u) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteInt32ToArray(2, this->_internal_field_int32(), target);
  }

  // optional uint64 field_uint64 = 3;
  if (cached_has_bits & 0x00000010u) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteUInt64ToArray(3, this->_internal_field_uint64(), target);
  }

  // optional int64 field_int64 = 4;
  if (cached_has_bits & 0x00000020u) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteInt64ToArray(4, this->_internal_field_int64(), target);
  }

  // optional fixed64 field_fixed64 = 5;
  if (cached_has_bits & 0x00000040u) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteFixed64ToArray(5, this->_internal_field_fixed64(), target);
  }

  // optional sfixed64 field_sfixed64 = 6;
  if (cached_has_bits & 0x00000080u) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteSFixed64ToArray(6, this->_internal_field_sfixed64(), target);
  }

  // optional fixed32 field_fixed32 = 7;
  if (cached_has_bits & 0x00000100u) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteFixed32ToArray(7, this->_internal_field_fixed32(), target);
  }

  // optional sfixed32 field_sfixed32 = 8;
  if (cached_has_bits & 0x00000200u) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteSFixed32ToArray(8, this->_internal_field_sfixed32(), target);
  }

  // optional double field_double = 9;
  if (cached_has_bits & 0x00000400u) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteDoubleToArray(9, this->_internal_field_double(), target);
  }

  // optional float field_float = 10;
  if (cached_has_bits & 0x00001000u) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteFloatToArray(10, this->_internal_field_float(), target);
  }

  // optional sint64 field_sint64 = 11;
  if (cached_has_bits & 0x00000800u) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteSInt64ToArray(11, this->_internal_field_sint64(), target);
  }

  // optional sint32 field_sint32 = 12;
  if (cached_has_bits & 0x00002000u) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteSInt32ToArray(12, this->_internal_field_sint32(), target);
  }

  // optional string field_string = 13;
  if (cached_has_bits & 0x00000001u) {
    target = stream->WriteStringMaybeAliased(
        13, this->_internal_field_string(), target);
  }

  // optional bytes field_bytes = 14;
  if (cached_has_bits & 0x00000002u) {
    target = stream->WriteBytesMaybeAliased(
        14, this->_internal_field_bytes(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = stream->WriteRaw(_internal_metadata_.unknown_fields<std::string>(::PROTOBUF_NAMESPACE_ID::internal::GetEmptyString).data(),
        static_cast<int>(_internal_metadata_.unknown_fields<std::string>(::PROTOBUF_NAMESPACE_ID::internal::GetEmptyString).size()), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:perfetto.protos.TestConfig.DummyFields)
  return target;
}

size_t TestConfig_DummyFields::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:perfetto.protos.TestConfig.DummyFields)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  if (cached_has_bits & 0x000000ffu) {
    // optional string field_string = 13;
    if (cached_has_bits & 0x00000001u) {
      total_size += 1 +
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
          this->_internal_field_string());
    }

    // optional bytes field_bytes = 14;
    if (cached_has_bits & 0x00000002u) {
      total_size += 1 +
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::BytesSize(
          this->_internal_field_bytes());
    }

    // optional uint32 field_uint32 = 1;
    if (cached_has_bits & 0x00000004u) {
      total_size += 1 +
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::UInt32Size(
          this->_internal_field_uint32());
    }

    // optional int32 field_int32 = 2;
    if (cached_has_bits & 0x00000008u) {
      total_size += 1 +
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::Int32Size(
          this->_internal_field_int32());
    }

    // optional uint64 field_uint64 = 3;
    if (cached_has_bits & 0x00000010u) {
      total_size += 1 +
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::UInt64Size(
          this->_internal_field_uint64());
    }

    // optional int64 field_int64 = 4;
    if (cached_has_bits & 0x00000020u) {
      total_size += 1 +
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::Int64Size(
          this->_internal_field_int64());
    }

    // optional fixed64 field_fixed64 = 5;
    if (cached_has_bits & 0x00000040u) {
      total_size += 1 + 8;
    }

    // optional sfixed64 field_sfixed64 = 6;
    if (cached_has_bits & 0x00000080u) {
      total_size += 1 + 8;
    }

  }
  if (cached_has_bits & 0x00003f00u) {
    // optional fixed32 field_fixed32 = 7;
    if (cached_has_bits & 0x00000100u) {
      total_size += 1 + 4;
    }

    // optional sfixed32 field_sfixed32 = 8;
    if (cached_has_bits & 0x00000200u) {
      total_size += 1 + 4;
    }

    // optional double field_double = 9;
    if (cached_has_bits & 0x00000400u) {
      total_size += 1 + 8;
    }

    // optional sint64 field_sint64 = 11;
    if (cached_has_bits & 0x00000800u) {
      total_size += 1 +
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SInt64Size(
          this->_internal_field_sint64());
    }

    // optional float field_float = 10;
    if (cached_has_bits & 0x00001000u) {
      total_size += 1 + 4;
    }

    // optional sint32 field_sint32 = 12;
    if (cached_has_bits & 0x00002000u) {
      total_size += 1 +
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SInt32Size(
          this->_internal_field_sint32());
    }

  }
  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    total_size += _internal_metadata_.unknown_fields<std::string>(::PROTOBUF_NAMESPACE_ID::internal::GetEmptyString).size();
  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void TestConfig_DummyFields::CheckTypeAndMergeFrom(
    const ::PROTOBUF_NAMESPACE_ID::MessageLite& from) {
  MergeFrom(*::PROTOBUF_NAMESPACE_ID::internal::DownCast<const TestConfig_DummyFields*>(
      &from));
}

void TestConfig_DummyFields::MergeFrom(const TestConfig_DummyFields& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:perfetto.protos.TestConfig.DummyFields)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom<std::string>(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = from._has_bits_[0];
  if (cached_has_bits & 0x000000ffu) {
    if (cached_has_bits & 0x00000001u) {
      _internal_set_field_string(from._internal_field_string());
    }
    if (cached_has_bits & 0x00000002u) {
      _internal_set_field_bytes(from._internal_field_bytes());
    }
    if (cached_has_bits & 0x00000004u) {
      field_uint32_ = from.field_uint32_;
    }
    if (cached_has_bits & 0x00000008u) {
      field_int32_ = from.field_int32_;
    }
    if (cached_has_bits & 0x00000010u) {
      field_uint64_ = from.field_uint64_;
    }
    if (cached_has_bits & 0x00000020u) {
      field_int64_ = from.field_int64_;
    }
    if (cached_has_bits & 0x00000040u) {
      field_fixed64_ = from.field_fixed64_;
    }
    if (cached_has_bits & 0x00000080u) {
      field_sfixed64_ = from.field_sfixed64_;
    }
    _has_bits_[0] |= cached_has_bits;
  }
  if (cached_has_bits & 0x00003f00u) {
    if (cached_has_bits & 0x00000100u) {
      field_fixed32_ = from.field_fixed32_;
    }
    if (cached_has_bits & 0x00000200u) {
      field_sfixed32_ = from.field_sfixed32_;
    }
    if (cached_has_bits & 0x00000400u) {
      field_double_ = from.field_double_;
    }
    if (cached_has_bits & 0x00000800u) {
      field_sint64_ = from.field_sint64_;
    }
    if (cached_has_bits & 0x00001000u) {
      field_float_ = from.field_float_;
    }
    if (cached_has_bits & 0x00002000u) {
      field_sint32_ = from.field_sint32_;
    }
    _has_bits_[0] |= cached_has_bits;
  }
}

void TestConfig_DummyFields::CopyFrom(const TestConfig_DummyFields& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:perfetto.protos.TestConfig.DummyFields)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool TestConfig_DummyFields::IsInitialized() const {
  return true;
}

void TestConfig_DummyFields::InternalSwap(TestConfig_DummyFields* other) {
  using std::swap;
  _internal_metadata_.Swap<std::string>(&other->_internal_metadata_);
  swap(_has_bits_[0], other->_has_bits_[0]);
  field_string_.Swap(&other->field_string_, &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
  field_bytes_.Swap(&other->field_bytes_, &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
  ::PROTOBUF_NAMESPACE_ID::internal::memswap<
      PROTOBUF_FIELD_OFFSET(TestConfig_DummyFields, field_sint32_)
      + sizeof(TestConfig_DummyFields::field_sint32_)
      - PROTOBUF_FIELD_OFFSET(TestConfig_DummyFields, field_uint32_)>(
          reinterpret_cast<char*>(&field_uint32_),
          reinterpret_cast<char*>(&other->field_uint32_));
}

std::string TestConfig_DummyFields::GetTypeName() const {
  return "perfetto.protos.TestConfig.DummyFields";
}


// ===================================================================

class TestConfig::_Internal {
 public:
  using HasBits = decltype(std::declval<TestConfig>()._has_bits_);
  static void set_has_message_count(HasBits* has_bits) {
    (*has_bits)[0] |= 2u;
  }
  static void set_has_max_messages_per_second(HasBits* has_bits) {
    (*has_bits)[0] |= 4u;
  }
  static void set_has_seed(HasBits* has_bits) {
    (*has_bits)[0] |= 8u;
  }
  static void set_has_message_size(HasBits* has_bits) {
    (*has_bits)[0] |= 16u;
  }
  static void set_has_send_batch_on_register(HasBits* has_bits) {
    (*has_bits)[0] |= 32u;
  }
  static const ::perfetto::protos::TestConfig_DummyFields& dummy_fields(const TestConfig* msg);
  static void set_has_dummy_fields(HasBits* has_bits) {
    (*has_bits)[0] |= 1u;
  }
};

const ::perfetto::protos::TestConfig_DummyFields&
TestConfig::_Internal::dummy_fields(const TestConfig* msg) {
  return *msg->dummy_fields_;
}
TestConfig::TestConfig(::PROTOBUF_NAMESPACE_ID::Arena* arena)
  : ::PROTOBUF_NAMESPACE_ID::MessageLite(arena) {
  SharedCtor();
  RegisterArenaDtor(arena);
  // @@protoc_insertion_point(arena_constructor:perfetto.protos.TestConfig)
}
TestConfig::TestConfig(const TestConfig& from)
  : ::PROTOBUF_NAMESPACE_ID::MessageLite(),
      _has_bits_(from._has_bits_) {
  _internal_metadata_.MergeFrom<std::string>(from._internal_metadata_);
  if (from._internal_has_dummy_fields()) {
    dummy_fields_ = new ::perfetto::protos::TestConfig_DummyFields(*from.dummy_fields_);
  } else {
    dummy_fields_ = nullptr;
  }
  ::memcpy(&message_count_, &from.message_count_,
    static_cast<size_t>(reinterpret_cast<char*>(&send_batch_on_register_) -
    reinterpret_cast<char*>(&message_count_)) + sizeof(send_batch_on_register_));
  // @@protoc_insertion_point(copy_constructor:perfetto.protos.TestConfig)
}

void TestConfig::SharedCtor() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&scc_info_TestConfig_protos_2fperfetto_2fconfig_2ftest_5fconfig_2eproto.base);
  ::memset(reinterpret_cast<char*>(this) + static_cast<size_t>(
      reinterpret_cast<char*>(&dummy_fields_) - reinterpret_cast<char*>(this)),
      0, static_cast<size_t>(reinterpret_cast<char*>(&send_batch_on_register_) -
      reinterpret_cast<char*>(&dummy_fields_)) + sizeof(send_batch_on_register_));
}

TestConfig::~TestConfig() {
  // @@protoc_insertion_point(destructor:perfetto.protos.TestConfig)
  SharedDtor();
  _internal_metadata_.Delete<std::string>();
}

void TestConfig::SharedDtor() {
  GOOGLE_DCHECK(GetArena() == nullptr);
  if (this != internal_default_instance()) delete dummy_fields_;
}

void TestConfig::ArenaDtor(void* object) {
  TestConfig* _this = reinterpret_cast< TestConfig* >(object);
  (void)_this;
}
void TestConfig::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void TestConfig::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const TestConfig& TestConfig::default_instance() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&::scc_info_TestConfig_protos_2fperfetto_2fconfig_2ftest_5fconfig_2eproto.base);
  return *internal_default_instance();
}


void TestConfig::Clear() {
// @@protoc_insertion_point(message_clear_start:perfetto.protos.TestConfig)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  if (cached_has_bits & 0x00000001u) {
    GOOGLE_DCHECK(dummy_fields_ != nullptr);
    dummy_fields_->Clear();
  }
  if (cached_has_bits & 0x0000003eu) {
    ::memset(&message_count_, 0, static_cast<size_t>(
        reinterpret_cast<char*>(&send_batch_on_register_) -
        reinterpret_cast<char*>(&message_count_)) + sizeof(send_batch_on_register_));
  }
  _has_bits_.Clear();
  _internal_metadata_.Clear<std::string>();
}

const char* TestConfig::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  _Internal::HasBits has_bits{};
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    CHK_(ptr);
    switch (tag >> 3) {
      // optional uint32 message_count = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 8)) {
          _Internal::set_has_message_count(&has_bits);
          message_count_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint32(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // optional uint32 max_messages_per_second = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 16)) {
          _Internal::set_has_max_messages_per_second(&has_bits);
          max_messages_per_second_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint32(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // optional uint32 seed = 3;
      case 3:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 24)) {
          _Internal::set_has_seed(&has_bits);
          seed_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint32(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // optional uint32 message_size = 4;
      case 4:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 32)) {
          _Internal::set_has_message_size(&has_bits);
          message_size_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint32(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // optional bool send_batch_on_register = 5;
      case 5:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 40)) {
          _Internal::set_has_send_batch_on_register(&has_bits);
          send_batch_on_register_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // optional .perfetto.protos.TestConfig.DummyFields dummy_fields = 6;
      case 6:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 50)) {
          ptr = ctx->ParseMessage(_internal_mutable_dummy_fields(), ptr);
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

::PROTOBUF_NAMESPACE_ID::uint8* TestConfig::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:perfetto.protos.TestConfig)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  // optional uint32 message_count = 1;
  if (cached_has_bits & 0x00000002u) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteUInt32ToArray(1, this->_internal_message_count(), target);
  }

  // optional uint32 max_messages_per_second = 2;
  if (cached_has_bits & 0x00000004u) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteUInt32ToArray(2, this->_internal_max_messages_per_second(), target);
  }

  // optional uint32 seed = 3;
  if (cached_has_bits & 0x00000008u) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteUInt32ToArray(3, this->_internal_seed(), target);
  }

  // optional uint32 message_size = 4;
  if (cached_has_bits & 0x00000010u) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteUInt32ToArray(4, this->_internal_message_size(), target);
  }

  // optional bool send_batch_on_register = 5;
  if (cached_has_bits & 0x00000020u) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteBoolToArray(5, this->_internal_send_batch_on_register(), target);
  }

  // optional .perfetto.protos.TestConfig.DummyFields dummy_fields = 6;
  if (cached_has_bits & 0x00000001u) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessage(
        6, _Internal::dummy_fields(this), target, stream);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = stream->WriteRaw(_internal_metadata_.unknown_fields<std::string>(::PROTOBUF_NAMESPACE_ID::internal::GetEmptyString).data(),
        static_cast<int>(_internal_metadata_.unknown_fields<std::string>(::PROTOBUF_NAMESPACE_ID::internal::GetEmptyString).size()), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:perfetto.protos.TestConfig)
  return target;
}

size_t TestConfig::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:perfetto.protos.TestConfig)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  if (cached_has_bits & 0x0000003fu) {
    // optional .perfetto.protos.TestConfig.DummyFields dummy_fields = 6;
    if (cached_has_bits & 0x00000001u) {
      total_size += 1 +
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(
          *dummy_fields_);
    }

    // optional uint32 message_count = 1;
    if (cached_has_bits & 0x00000002u) {
      total_size += 1 +
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::UInt32Size(
          this->_internal_message_count());
    }

    // optional uint32 max_messages_per_second = 2;
    if (cached_has_bits & 0x00000004u) {
      total_size += 1 +
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::UInt32Size(
          this->_internal_max_messages_per_second());
    }

    // optional uint32 seed = 3;
    if (cached_has_bits & 0x00000008u) {
      total_size += 1 +
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::UInt32Size(
          this->_internal_seed());
    }

    // optional uint32 message_size = 4;
    if (cached_has_bits & 0x00000010u) {
      total_size += 1 +
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::UInt32Size(
          this->_internal_message_size());
    }

    // optional bool send_batch_on_register = 5;
    if (cached_has_bits & 0x00000020u) {
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

void TestConfig::CheckTypeAndMergeFrom(
    const ::PROTOBUF_NAMESPACE_ID::MessageLite& from) {
  MergeFrom(*::PROTOBUF_NAMESPACE_ID::internal::DownCast<const TestConfig*>(
      &from));
}

void TestConfig::MergeFrom(const TestConfig& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:perfetto.protos.TestConfig)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom<std::string>(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = from._has_bits_[0];
  if (cached_has_bits & 0x0000003fu) {
    if (cached_has_bits & 0x00000001u) {
      _internal_mutable_dummy_fields()->::perfetto::protos::TestConfig_DummyFields::MergeFrom(from._internal_dummy_fields());
    }
    if (cached_has_bits & 0x00000002u) {
      message_count_ = from.message_count_;
    }
    if (cached_has_bits & 0x00000004u) {
      max_messages_per_second_ = from.max_messages_per_second_;
    }
    if (cached_has_bits & 0x00000008u) {
      seed_ = from.seed_;
    }
    if (cached_has_bits & 0x00000010u) {
      message_size_ = from.message_size_;
    }
    if (cached_has_bits & 0x00000020u) {
      send_batch_on_register_ = from.send_batch_on_register_;
    }
    _has_bits_[0] |= cached_has_bits;
  }
}

void TestConfig::CopyFrom(const TestConfig& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:perfetto.protos.TestConfig)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool TestConfig::IsInitialized() const {
  return true;
}

void TestConfig::InternalSwap(TestConfig* other) {
  using std::swap;
  _internal_metadata_.Swap<std::string>(&other->_internal_metadata_);
  swap(_has_bits_[0], other->_has_bits_[0]);
  ::PROTOBUF_NAMESPACE_ID::internal::memswap<
      PROTOBUF_FIELD_OFFSET(TestConfig, send_batch_on_register_)
      + sizeof(TestConfig::send_batch_on_register_)
      - PROTOBUF_FIELD_OFFSET(TestConfig, dummy_fields_)>(
          reinterpret_cast<char*>(&dummy_fields_),
          reinterpret_cast<char*>(&other->dummy_fields_));
}

std::string TestConfig::GetTypeName() const {
  return "perfetto.protos.TestConfig";
}


// @@protoc_insertion_point(namespace_scope)
}  // namespace protos
}  // namespace perfetto
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::perfetto::protos::TestConfig_DummyFields* Arena::CreateMaybeMessage< ::perfetto::protos::TestConfig_DummyFields >(Arena* arena) {
  return Arena::CreateMessageInternal< ::perfetto::protos::TestConfig_DummyFields >(arena);
}
template<> PROTOBUF_NOINLINE ::perfetto::protos::TestConfig* Arena::CreateMaybeMessage< ::perfetto::protos::TestConfig >(Arena* arena) {
  return Arena::CreateMessageInternal< ::perfetto::protos::TestConfig >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
