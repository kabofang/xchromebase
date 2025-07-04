// Autogenerated by the ProtoZero compiler plugin. DO NOT EDIT.

#ifndef PERFETTO_PROTOS_PROTOS_PERFETTO_TRACE_UI_STATE_PROTO_H_
#define PERFETTO_PROTOS_PROTOS_PERFETTO_TRACE_UI_STATE_PROTO_H_

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

class UiState_HighlightProcess;

class UiState_Decoder : public ::protozero::TypedProtoDecoder</*MAX_FIELD_ID=*/3, /*HAS_NONPACKED_REPEATED_FIELDS=*/false> {
 public:
  UiState_Decoder(const uint8_t* data, size_t len) : TypedProtoDecoder(data, len) {}
  explicit UiState_Decoder(const std::string& raw) : TypedProtoDecoder(reinterpret_cast<const uint8_t*>(raw.data()), raw.size()) {}
  explicit UiState_Decoder(const ::protozero::ConstBytes& raw) : TypedProtoDecoder(raw.data, raw.size) {}
  bool has_timeline_start_ts() const { return at<1>().valid(); }
  int64_t timeline_start_ts() const { return at<1>().as_int64(); }
  bool has_timeline_end_ts() const { return at<2>().valid(); }
  int64_t timeline_end_ts() const { return at<2>().as_int64(); }
  bool has_highlight_process() const { return at<3>().valid(); }
  ::protozero::ConstBytes highlight_process() const { return at<3>().as_bytes(); }
};

class UiState : public ::protozero::Message {
 public:
  using Decoder = UiState_Decoder;
  enum : int32_t {
    kTimelineStartTsFieldNumber = 1,
    kTimelineEndTsFieldNumber = 2,
    kHighlightProcessFieldNumber = 3,
  };
  static constexpr const char* GetName() { return ".perfetto.protos.UiState"; }

  using HighlightProcess = ::perfetto::protos::pbzero::UiState_HighlightProcess;

  using FieldMetadata_TimelineStartTs =
    ::protozero::proto_utils::FieldMetadata<
      1,
      ::protozero::proto_utils::RepetitionType::kNotRepeated,
      ::protozero::proto_utils::ProtoSchemaType::kInt64,
      int64_t,
      UiState>;

  // Ceci n'est pas une pipe.
  // This is actually a variable of FieldMetadataHelper<FieldMetadata<...>>
  // type (and users are expected to use it as such, hence kCamelCase name).
  // It is declared as a function to keep protozero bindings header-only as
  // inline constexpr variables are not available until C++17 (while inline
  // functions are).
  // TODO(altimin): Use inline variable instead after adopting C++17.
  static constexpr FieldMetadata_TimelineStartTs kTimelineStartTs() { return {}; }
  void set_timeline_start_ts(int64_t value) {
    static constexpr uint32_t field_id = FieldMetadata_TimelineStartTs::kFieldId;
    // Call the appropriate protozero::Message::Append(field_id, ...)
    // method based on the type of the field.
    ::protozero::internal::FieldWriter<
      ::protozero::proto_utils::ProtoSchemaType::kInt64>
        ::Append(*this, field_id, value);
  }

  using FieldMetadata_TimelineEndTs =
    ::protozero::proto_utils::FieldMetadata<
      2,
      ::protozero::proto_utils::RepetitionType::kNotRepeated,
      ::protozero::proto_utils::ProtoSchemaType::kInt64,
      int64_t,
      UiState>;

  // Ceci n'est pas une pipe.
  // This is actually a variable of FieldMetadataHelper<FieldMetadata<...>>
  // type (and users are expected to use it as such, hence kCamelCase name).
  // It is declared as a function to keep protozero bindings header-only as
  // inline constexpr variables are not available until C++17 (while inline
  // functions are).
  // TODO(altimin): Use inline variable instead after adopting C++17.
  static constexpr FieldMetadata_TimelineEndTs kTimelineEndTs() { return {}; }
  void set_timeline_end_ts(int64_t value) {
    static constexpr uint32_t field_id = FieldMetadata_TimelineEndTs::kFieldId;
    // Call the appropriate protozero::Message::Append(field_id, ...)
    // method based on the type of the field.
    ::protozero::internal::FieldWriter<
      ::protozero::proto_utils::ProtoSchemaType::kInt64>
        ::Append(*this, field_id, value);
  }

  using FieldMetadata_HighlightProcess =
    ::protozero::proto_utils::FieldMetadata<
      3,
      ::protozero::proto_utils::RepetitionType::kNotRepeated,
      ::protozero::proto_utils::ProtoSchemaType::kMessage,
      UiState_HighlightProcess,
      UiState>;

  // Ceci n'est pas une pipe.
  // This is actually a variable of FieldMetadataHelper<FieldMetadata<...>>
  // type (and users are expected to use it as such, hence kCamelCase name).
  // It is declared as a function to keep protozero bindings header-only as
  // inline constexpr variables are not available until C++17 (while inline
  // functions are).
  // TODO(altimin): Use inline variable instead after adopting C++17.
  static constexpr FieldMetadata_HighlightProcess kHighlightProcess() { return {}; }
  template <typename T = UiState_HighlightProcess> T* set_highlight_process() {
    return BeginNestedMessage<T>(3);
  }

};

class UiState_HighlightProcess_Decoder : public ::protozero::TypedProtoDecoder</*MAX_FIELD_ID=*/2, /*HAS_NONPACKED_REPEATED_FIELDS=*/false> {
 public:
  UiState_HighlightProcess_Decoder(const uint8_t* data, size_t len) : TypedProtoDecoder(data, len) {}
  explicit UiState_HighlightProcess_Decoder(const std::string& raw) : TypedProtoDecoder(reinterpret_cast<const uint8_t*>(raw.data()), raw.size()) {}
  explicit UiState_HighlightProcess_Decoder(const ::protozero::ConstBytes& raw) : TypedProtoDecoder(raw.data, raw.size) {}
  bool has_pid() const { return at<1>().valid(); }
  uint32_t pid() const { return at<1>().as_uint32(); }
  bool has_cmdline() const { return at<2>().valid(); }
  ::protozero::ConstChars cmdline() const { return at<2>().as_string(); }
};

class UiState_HighlightProcess : public ::protozero::Message {
 public:
  using Decoder = UiState_HighlightProcess_Decoder;
  enum : int32_t {
    kPidFieldNumber = 1,
    kCmdlineFieldNumber = 2,
  };
  static constexpr const char* GetName() { return ".perfetto.protos.UiState.HighlightProcess"; }


  using FieldMetadata_Pid =
    ::protozero::proto_utils::FieldMetadata<
      1,
      ::protozero::proto_utils::RepetitionType::kNotRepeated,
      ::protozero::proto_utils::ProtoSchemaType::kUint32,
      uint32_t,
      UiState_HighlightProcess>;

  // Ceci n'est pas une pipe.
  // This is actually a variable of FieldMetadataHelper<FieldMetadata<...>>
  // type (and users are expected to use it as such, hence kCamelCase name).
  // It is declared as a function to keep protozero bindings header-only as
  // inline constexpr variables are not available until C++17 (while inline
  // functions are).
  // TODO(altimin): Use inline variable instead after adopting C++17.
  static constexpr FieldMetadata_Pid kPid() { return {}; }
  void set_pid(uint32_t value) {
    static constexpr uint32_t field_id = FieldMetadata_Pid::kFieldId;
    // Call the appropriate protozero::Message::Append(field_id, ...)
    // method based on the type of the field.
    ::protozero::internal::FieldWriter<
      ::protozero::proto_utils::ProtoSchemaType::kUint32>
        ::Append(*this, field_id, value);
  }

  using FieldMetadata_Cmdline =
    ::protozero::proto_utils::FieldMetadata<
      2,
      ::protozero::proto_utils::RepetitionType::kNotRepeated,
      ::protozero::proto_utils::ProtoSchemaType::kString,
      std::string,
      UiState_HighlightProcess>;

  // Ceci n'est pas une pipe.
  // This is actually a variable of FieldMetadataHelper<FieldMetadata<...>>
  // type (and users are expected to use it as such, hence kCamelCase name).
  // It is declared as a function to keep protozero bindings header-only as
  // inline constexpr variables are not available until C++17 (while inline
  // functions are).
  // TODO(altimin): Use inline variable instead after adopting C++17.
  static constexpr FieldMetadata_Cmdline kCmdline() { return {}; }
  void set_cmdline(const char* data, size_t size) {
    AppendBytes(FieldMetadata_Cmdline::kFieldId, data, size);
  }
  void set_cmdline(std::string value) {
    static constexpr uint32_t field_id = FieldMetadata_Cmdline::kFieldId;
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
