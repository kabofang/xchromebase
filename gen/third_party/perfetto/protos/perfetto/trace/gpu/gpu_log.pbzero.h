// Autogenerated by the ProtoZero compiler plugin. DO NOT EDIT.

#ifndef PERFETTO_PROTOS_PROTOS_PERFETTO_TRACE_GPU_GPU_LOG_PROTO_H_
#define PERFETTO_PROTOS_PROTOS_PERFETTO_TRACE_GPU_GPU_LOG_PROTO_H_

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

enum GpuLog_Severity : int32_t;

enum GpuLog_Severity : int32_t {
  GpuLog_Severity_LOG_SEVERITY_UNSPECIFIED = 0,
  GpuLog_Severity_LOG_SEVERITY_VERBOSE = 1,
  GpuLog_Severity_LOG_SEVERITY_DEBUG = 2,
  GpuLog_Severity_LOG_SEVERITY_INFO = 3,
  GpuLog_Severity_LOG_SEVERITY_WARNING = 4,
  GpuLog_Severity_LOG_SEVERITY_ERROR = 5,
};

const GpuLog_Severity GpuLog_Severity_MIN = GpuLog_Severity_LOG_SEVERITY_UNSPECIFIED;
const GpuLog_Severity GpuLog_Severity_MAX = GpuLog_Severity_LOG_SEVERITY_ERROR;

class GpuLog_Decoder : public ::protozero::TypedProtoDecoder</*MAX_FIELD_ID=*/3, /*HAS_NONPACKED_REPEATED_FIELDS=*/false> {
 public:
  GpuLog_Decoder(const uint8_t* data, size_t len) : TypedProtoDecoder(data, len) {}
  explicit GpuLog_Decoder(const std::string& raw) : TypedProtoDecoder(reinterpret_cast<const uint8_t*>(raw.data()), raw.size()) {}
  explicit GpuLog_Decoder(const ::protozero::ConstBytes& raw) : TypedProtoDecoder(raw.data, raw.size) {}
  bool has_severity() const { return at<1>().valid(); }
  int32_t severity() const { return at<1>().as_int32(); }
  bool has_tag() const { return at<2>().valid(); }
  ::protozero::ConstChars tag() const { return at<2>().as_string(); }
  bool has_log_message() const { return at<3>().valid(); }
  ::protozero::ConstChars log_message() const { return at<3>().as_string(); }
};

class GpuLog : public ::protozero::Message {
 public:
  using Decoder = GpuLog_Decoder;
  enum : int32_t {
    kSeverityFieldNumber = 1,
    kTagFieldNumber = 2,
    kLogMessageFieldNumber = 3,
  };
  static constexpr const char* GetName() { return ".perfetto.protos.GpuLog"; }

  using Severity = ::perfetto::protos::pbzero::GpuLog_Severity;
  static const Severity LOG_SEVERITY_UNSPECIFIED = GpuLog_Severity_LOG_SEVERITY_UNSPECIFIED;
  static const Severity LOG_SEVERITY_VERBOSE = GpuLog_Severity_LOG_SEVERITY_VERBOSE;
  static const Severity LOG_SEVERITY_DEBUG = GpuLog_Severity_LOG_SEVERITY_DEBUG;
  static const Severity LOG_SEVERITY_INFO = GpuLog_Severity_LOG_SEVERITY_INFO;
  static const Severity LOG_SEVERITY_WARNING = GpuLog_Severity_LOG_SEVERITY_WARNING;
  static const Severity LOG_SEVERITY_ERROR = GpuLog_Severity_LOG_SEVERITY_ERROR;

  using FieldMetadata_Severity =
    ::protozero::proto_utils::FieldMetadata<
      1,
      ::protozero::proto_utils::RepetitionType::kNotRepeated,
      ::protozero::proto_utils::ProtoSchemaType::kEnum,
      ::perfetto::protos::pbzero::GpuLog_Severity,
      GpuLog>;

  // Ceci n'est pas une pipe.
  // This is actually a variable of FieldMetadataHelper<FieldMetadata<...>>
  // type (and users are expected to use it as such, hence kCamelCase name).
  // It is declared as a function to keep protozero bindings header-only as
  // inline constexpr variables are not available until C++17 (while inline
  // functions are).
  // TODO(altimin): Use inline variable instead after adopting C++17.
  static constexpr FieldMetadata_Severity kSeverity() { return {}; }
  void set_severity(::perfetto::protos::pbzero::GpuLog_Severity value) {
    static constexpr uint32_t field_id = FieldMetadata_Severity::kFieldId;
    // Call the appropriate protozero::Message::Append(field_id, ...)
    // method based on the type of the field.
    ::protozero::internal::FieldWriter<
      ::protozero::proto_utils::ProtoSchemaType::kEnum>
        ::Append(*this, field_id, value);
  }

  using FieldMetadata_Tag =
    ::protozero::proto_utils::FieldMetadata<
      2,
      ::protozero::proto_utils::RepetitionType::kNotRepeated,
      ::protozero::proto_utils::ProtoSchemaType::kString,
      std::string,
      GpuLog>;

  // Ceci n'est pas une pipe.
  // This is actually a variable of FieldMetadataHelper<FieldMetadata<...>>
  // type (and users are expected to use it as such, hence kCamelCase name).
  // It is declared as a function to keep protozero bindings header-only as
  // inline constexpr variables are not available until C++17 (while inline
  // functions are).
  // TODO(altimin): Use inline variable instead after adopting C++17.
  static constexpr FieldMetadata_Tag kTag() { return {}; }
  void set_tag(const char* data, size_t size) {
    AppendBytes(FieldMetadata_Tag::kFieldId, data, size);
  }
  void set_tag(std::string value) {
    static constexpr uint32_t field_id = FieldMetadata_Tag::kFieldId;
    // Call the appropriate protozero::Message::Append(field_id, ...)
    // method based on the type of the field.
    ::protozero::internal::FieldWriter<
      ::protozero::proto_utils::ProtoSchemaType::kString>
        ::Append(*this, field_id, value);
  }

  using FieldMetadata_LogMessage =
    ::protozero::proto_utils::FieldMetadata<
      3,
      ::protozero::proto_utils::RepetitionType::kNotRepeated,
      ::protozero::proto_utils::ProtoSchemaType::kString,
      std::string,
      GpuLog>;

  // Ceci n'est pas une pipe.
  // This is actually a variable of FieldMetadataHelper<FieldMetadata<...>>
  // type (and users are expected to use it as such, hence kCamelCase name).
  // It is declared as a function to keep protozero bindings header-only as
  // inline constexpr variables are not available until C++17 (while inline
  // functions are).
  // TODO(altimin): Use inline variable instead after adopting C++17.
  static constexpr FieldMetadata_LogMessage kLogMessage() { return {}; }
  void set_log_message(const char* data, size_t size) {
    AppendBytes(FieldMetadata_LogMessage::kFieldId, data, size);
  }
  void set_log_message(std::string value) {
    static constexpr uint32_t field_id = FieldMetadata_LogMessage::kFieldId;
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
