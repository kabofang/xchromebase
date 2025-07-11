// Autogenerated by the ProtoZero compiler plugin. DO NOT EDIT.

#ifndef PERFETTO_PROTOS_PROTOS_PERFETTO_TRACE_SYSTEM_INFO_PROTO_H_
#define PERFETTO_PROTOS_PROTOS_PERFETTO_TRACE_SYSTEM_INFO_PROTO_H_

#include <stddef.h>
#include <stdint.h>

#include "perfetto/protozero/field_writer.h"
#include "perfetto/protozero/message.h"
#include "perfetto/protozero/packed_repeated_fields.h"
#include "perfetto/protozero/proto_decoder.h"
#include "perfetto/protozero/proto_utils.h"

namespace perfetto {
namespace protos {
namespace pbzero {

class Utsname;

class SystemInfo_Decoder : public ::protozero::TypedProtoDecoder</*MAX_FIELD_ID=*/5, /*HAS_NONPACKED_REPEATED_FIELDS=*/false> {
 public:
  SystemInfo_Decoder(const uint8_t* data, size_t len) : TypedProtoDecoder(data, len) {}
  explicit SystemInfo_Decoder(const std::string& raw) : TypedProtoDecoder(reinterpret_cast<const uint8_t*>(raw.data()), raw.size()) {}
  explicit SystemInfo_Decoder(const ::protozero::ConstBytes& raw) : TypedProtoDecoder(raw.data, raw.size) {}
  bool has_utsname() const { return at<1>().valid(); }
  ::protozero::ConstBytes utsname() const { return at<1>().as_bytes(); }
  bool has_android_build_fingerprint() const { return at<2>().valid(); }
  ::protozero::ConstChars android_build_fingerprint() const { return at<2>().as_string(); }
  bool has_hz() const { return at<3>().valid(); }
  int64_t hz() const { return at<3>().as_int64(); }
  bool has_tracing_service_version() const { return at<4>().valid(); }
  ::protozero::ConstChars tracing_service_version() const { return at<4>().as_string(); }
  bool has_android_sdk_version() const { return at<5>().valid(); }
  uint64_t android_sdk_version() const { return at<5>().as_uint64(); }
};

class SystemInfo : public ::protozero::Message {
 public:
  using Decoder = SystemInfo_Decoder;
  enum : int32_t {
    kUtsnameFieldNumber = 1,
    kAndroidBuildFingerprintFieldNumber = 2,
    kHzFieldNumber = 3,
    kTracingServiceVersionFieldNumber = 4,
    kAndroidSdkVersionFieldNumber = 5,
  };
  static constexpr const char* GetName() { return ".perfetto.protos.SystemInfo"; }


  using FieldMetadata_Utsname =
    ::protozero::proto_utils::FieldMetadata<
      1,
      ::protozero::proto_utils::RepetitionType::kNotRepeated,
      ::protozero::proto_utils::ProtoSchemaType::kMessage,
      Utsname,
      SystemInfo>;

  // Ceci n'est pas une pipe.
  // This is actually a variable of FieldMetadataHelper<FieldMetadata<...>>
  // type (and users are expected to use it as such, hence kCamelCase name).
  // It is declared as a function to keep protozero bindings header-only as
  // inline constexpr variables are not available until C++17 (while inline
  // functions are).
  // TODO(altimin): Use inline variable instead after adopting C++17.
  static constexpr FieldMetadata_Utsname kUtsname() { return {}; }
  template <typename T = Utsname> T* set_utsname() {
    return BeginNestedMessage<T>(1);
  }


  using FieldMetadata_AndroidBuildFingerprint =
    ::protozero::proto_utils::FieldMetadata<
      2,
      ::protozero::proto_utils::RepetitionType::kNotRepeated,
      ::protozero::proto_utils::ProtoSchemaType::kString,
      std::string,
      SystemInfo>;

  // Ceci n'est pas une pipe.
  // This is actually a variable of FieldMetadataHelper<FieldMetadata<...>>
  // type (and users are expected to use it as such, hence kCamelCase name).
  // It is declared as a function to keep protozero bindings header-only as
  // inline constexpr variables are not available until C++17 (while inline
  // functions are).
  // TODO(altimin): Use inline variable instead after adopting C++17.
  static constexpr FieldMetadata_AndroidBuildFingerprint kAndroidBuildFingerprint() { return {}; }
  void set_android_build_fingerprint(const char* data, size_t size) {
    AppendBytes(FieldMetadata_AndroidBuildFingerprint::kFieldId, data, size);
  }
  void set_android_build_fingerprint(std::string value) {
    static constexpr uint32_t field_id = FieldMetadata_AndroidBuildFingerprint::kFieldId;
    // Call the appropriate protozero::Message::Append(field_id, ...)
    // method based on the type of the field.
    ::protozero::internal::FieldWriter<
      ::protozero::proto_utils::ProtoSchemaType::kString>
        ::Append(*this, field_id, value);
  }

  using FieldMetadata_Hz =
    ::protozero::proto_utils::FieldMetadata<
      3,
      ::protozero::proto_utils::RepetitionType::kNotRepeated,
      ::protozero::proto_utils::ProtoSchemaType::kInt64,
      int64_t,
      SystemInfo>;

  // Ceci n'est pas une pipe.
  // This is actually a variable of FieldMetadataHelper<FieldMetadata<...>>
  // type (and users are expected to use it as such, hence kCamelCase name).
  // It is declared as a function to keep protozero bindings header-only as
  // inline constexpr variables are not available until C++17 (while inline
  // functions are).
  // TODO(altimin): Use inline variable instead after adopting C++17.
  static constexpr FieldMetadata_Hz kHz() { return {}; }
  void set_hz(int64_t value) {
    static constexpr uint32_t field_id = FieldMetadata_Hz::kFieldId;
    // Call the appropriate protozero::Message::Append(field_id, ...)
    // method based on the type of the field.
    ::protozero::internal::FieldWriter<
      ::protozero::proto_utils::ProtoSchemaType::kInt64>
        ::Append(*this, field_id, value);
  }

  using FieldMetadata_TracingServiceVersion =
    ::protozero::proto_utils::FieldMetadata<
      4,
      ::protozero::proto_utils::RepetitionType::kNotRepeated,
      ::protozero::proto_utils::ProtoSchemaType::kString,
      std::string,
      SystemInfo>;

  // Ceci n'est pas une pipe.
  // This is actually a variable of FieldMetadataHelper<FieldMetadata<...>>
  // type (and users are expected to use it as such, hence kCamelCase name).
  // It is declared as a function to keep protozero bindings header-only as
  // inline constexpr variables are not available until C++17 (while inline
  // functions are).
  // TODO(altimin): Use inline variable instead after adopting C++17.
  static constexpr FieldMetadata_TracingServiceVersion kTracingServiceVersion() { return {}; }
  void set_tracing_service_version(const char* data, size_t size) {
    AppendBytes(FieldMetadata_TracingServiceVersion::kFieldId, data, size);
  }
  void set_tracing_service_version(std::string value) {
    static constexpr uint32_t field_id = FieldMetadata_TracingServiceVersion::kFieldId;
    // Call the appropriate protozero::Message::Append(field_id, ...)
    // method based on the type of the field.
    ::protozero::internal::FieldWriter<
      ::protozero::proto_utils::ProtoSchemaType::kString>
        ::Append(*this, field_id, value);
  }

  using FieldMetadata_AndroidSdkVersion =
    ::protozero::proto_utils::FieldMetadata<
      5,
      ::protozero::proto_utils::RepetitionType::kNotRepeated,
      ::protozero::proto_utils::ProtoSchemaType::kUint64,
      uint64_t,
      SystemInfo>;

  // Ceci n'est pas une pipe.
  // This is actually a variable of FieldMetadataHelper<FieldMetadata<...>>
  // type (and users are expected to use it as such, hence kCamelCase name).
  // It is declared as a function to keep protozero bindings header-only as
  // inline constexpr variables are not available until C++17 (while inline
  // functions are).
  // TODO(altimin): Use inline variable instead after adopting C++17.
  static constexpr FieldMetadata_AndroidSdkVersion kAndroidSdkVersion() { return {}; }
  void set_android_sdk_version(uint64_t value) {
    static constexpr uint32_t field_id = FieldMetadata_AndroidSdkVersion::kFieldId;
    // Call the appropriate protozero::Message::Append(field_id, ...)
    // method based on the type of the field.
    ::protozero::internal::FieldWriter<
      ::protozero::proto_utils::ProtoSchemaType::kUint64>
        ::Append(*this, field_id, value);
  }
};

class Utsname_Decoder : public ::protozero::TypedProtoDecoder</*MAX_FIELD_ID=*/4, /*HAS_NONPACKED_REPEATED_FIELDS=*/false> {
 public:
  Utsname_Decoder(const uint8_t* data, size_t len) : TypedProtoDecoder(data, len) {}
  explicit Utsname_Decoder(const std::string& raw) : TypedProtoDecoder(reinterpret_cast<const uint8_t*>(raw.data()), raw.size()) {}
  explicit Utsname_Decoder(const ::protozero::ConstBytes& raw) : TypedProtoDecoder(raw.data, raw.size) {}
  bool has_sysname() const { return at<1>().valid(); }
  ::protozero::ConstChars sysname() const { return at<1>().as_string(); }
  bool has_version() const { return at<2>().valid(); }
  ::protozero::ConstChars version() const { return at<2>().as_string(); }
  bool has_release() const { return at<3>().valid(); }
  ::protozero::ConstChars release() const { return at<3>().as_string(); }
  bool has_machine() const { return at<4>().valid(); }
  ::protozero::ConstChars machine() const { return at<4>().as_string(); }
};

class Utsname : public ::protozero::Message {
 public:
  using Decoder = Utsname_Decoder;
  enum : int32_t {
    kSysnameFieldNumber = 1,
    kVersionFieldNumber = 2,
    kReleaseFieldNumber = 3,
    kMachineFieldNumber = 4,
  };
  static constexpr const char* GetName() { return ".perfetto.protos.Utsname"; }


  using FieldMetadata_Sysname =
    ::protozero::proto_utils::FieldMetadata<
      1,
      ::protozero::proto_utils::RepetitionType::kNotRepeated,
      ::protozero::proto_utils::ProtoSchemaType::kString,
      std::string,
      Utsname>;

  // Ceci n'est pas une pipe.
  // This is actually a variable of FieldMetadataHelper<FieldMetadata<...>>
  // type (and users are expected to use it as such, hence kCamelCase name).
  // It is declared as a function to keep protozero bindings header-only as
  // inline constexpr variables are not available until C++17 (while inline
  // functions are).
  // TODO(altimin): Use inline variable instead after adopting C++17.
  static constexpr FieldMetadata_Sysname kSysname() { return {}; }
  void set_sysname(const char* data, size_t size) {
    AppendBytes(FieldMetadata_Sysname::kFieldId, data, size);
  }
  void set_sysname(std::string value) {
    static constexpr uint32_t field_id = FieldMetadata_Sysname::kFieldId;
    // Call the appropriate protozero::Message::Append(field_id, ...)
    // method based on the type of the field.
    ::protozero::internal::FieldWriter<
      ::protozero::proto_utils::ProtoSchemaType::kString>
        ::Append(*this, field_id, value);
  }

  using FieldMetadata_Version =
    ::protozero::proto_utils::FieldMetadata<
      2,
      ::protozero::proto_utils::RepetitionType::kNotRepeated,
      ::protozero::proto_utils::ProtoSchemaType::kString,
      std::string,
      Utsname>;

  // Ceci n'est pas une pipe.
  // This is actually a variable of FieldMetadataHelper<FieldMetadata<...>>
  // type (and users are expected to use it as such, hence kCamelCase name).
  // It is declared as a function to keep protozero bindings header-only as
  // inline constexpr variables are not available until C++17 (while inline
  // functions are).
  // TODO(altimin): Use inline variable instead after adopting C++17.
  static constexpr FieldMetadata_Version kVersion() { return {}; }
  void set_version(const char* data, size_t size) {
    AppendBytes(FieldMetadata_Version::kFieldId, data, size);
  }
  void set_version(std::string value) {
    static constexpr uint32_t field_id = FieldMetadata_Version::kFieldId;
    // Call the appropriate protozero::Message::Append(field_id, ...)
    // method based on the type of the field.
    ::protozero::internal::FieldWriter<
      ::protozero::proto_utils::ProtoSchemaType::kString>
        ::Append(*this, field_id, value);
  }

  using FieldMetadata_Release =
    ::protozero::proto_utils::FieldMetadata<
      3,
      ::protozero::proto_utils::RepetitionType::kNotRepeated,
      ::protozero::proto_utils::ProtoSchemaType::kString,
      std::string,
      Utsname>;

  // Ceci n'est pas une pipe.
  // This is actually a variable of FieldMetadataHelper<FieldMetadata<...>>
  // type (and users are expected to use it as such, hence kCamelCase name).
  // It is declared as a function to keep protozero bindings header-only as
  // inline constexpr variables are not available until C++17 (while inline
  // functions are).
  // TODO(altimin): Use inline variable instead after adopting C++17.
  static constexpr FieldMetadata_Release kRelease() { return {}; }
  void set_release(const char* data, size_t size) {
    AppendBytes(FieldMetadata_Release::kFieldId, data, size);
  }
  void set_release(std::string value) {
    static constexpr uint32_t field_id = FieldMetadata_Release::kFieldId;
    // Call the appropriate protozero::Message::Append(field_id, ...)
    // method based on the type of the field.
    ::protozero::internal::FieldWriter<
      ::protozero::proto_utils::ProtoSchemaType::kString>
        ::Append(*this, field_id, value);
  }

  using FieldMetadata_Machine =
    ::protozero::proto_utils::FieldMetadata<
      4,
      ::protozero::proto_utils::RepetitionType::kNotRepeated,
      ::protozero::proto_utils::ProtoSchemaType::kString,
      std::string,
      Utsname>;

  // Ceci n'est pas une pipe.
  // This is actually a variable of FieldMetadataHelper<FieldMetadata<...>>
  // type (and users are expected to use it as such, hence kCamelCase name).
  // It is declared as a function to keep protozero bindings header-only as
  // inline constexpr variables are not available until C++17 (while inline
  // functions are).
  // TODO(altimin): Use inline variable instead after adopting C++17.
  static constexpr FieldMetadata_Machine kMachine() { return {}; }
  void set_machine(const char* data, size_t size) {
    AppendBytes(FieldMetadata_Machine::kFieldId, data, size);
  }
  void set_machine(std::string value) {
    static constexpr uint32_t field_id = FieldMetadata_Machine::kFieldId;
    // Call the appropriate protozero::Message::Append(field_id, ...)
    // method based on the type of the field.
    ::protozero::internal::FieldWriter<
      ::protozero::proto_utils::ProtoSchemaType::kString>
        ::Append(*this, field_id, value);
  }
};

} // Namespace.
} // Namespace.
} // Namespace.
#endif  // Include guard.
