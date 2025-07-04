// Autogenerated by the ProtoZero compiler plugin. DO NOT EDIT.

#ifndef PERFETTO_PROTOS_PROTOS_PERFETTO_COMMON_TRACING_SERVICE_STATE_PROTO_H_
#define PERFETTO_PROTOS_PROTOS_PERFETTO_COMMON_TRACING_SERVICE_STATE_PROTO_H_

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

class DataSourceDescriptor;
class TracingServiceState_DataSource;
class TracingServiceState_Producer;
class TracingServiceState_TracingSession;

class TracingServiceState_Decoder : public ::protozero::TypedProtoDecoder</*MAX_FIELD_ID=*/7, /*HAS_NONPACKED_REPEATED_FIELDS=*/true> {
 public:
  TracingServiceState_Decoder(const uint8_t* data, size_t len) : TypedProtoDecoder(data, len) {}
  explicit TracingServiceState_Decoder(const std::string& raw) : TypedProtoDecoder(reinterpret_cast<const uint8_t*>(raw.data()), raw.size()) {}
  explicit TracingServiceState_Decoder(const ::protozero::ConstBytes& raw) : TypedProtoDecoder(raw.data, raw.size) {}
  bool has_producers() const { return at<1>().valid(); }
  ::protozero::RepeatedFieldIterator<::protozero::ConstBytes> producers() const { return GetRepeated<::protozero::ConstBytes>(1); }
  bool has_data_sources() const { return at<2>().valid(); }
  ::protozero::RepeatedFieldIterator<::protozero::ConstBytes> data_sources() const { return GetRepeated<::protozero::ConstBytes>(2); }
  bool has_tracing_sessions() const { return at<6>().valid(); }
  ::protozero::RepeatedFieldIterator<::protozero::ConstBytes> tracing_sessions() const { return GetRepeated<::protozero::ConstBytes>(6); }
  bool has_supports_tracing_sessions() const { return at<7>().valid(); }
  bool supports_tracing_sessions() const { return at<7>().as_bool(); }
  bool has_num_sessions() const { return at<3>().valid(); }
  int32_t num_sessions() const { return at<3>().as_int32(); }
  bool has_num_sessions_started() const { return at<4>().valid(); }
  int32_t num_sessions_started() const { return at<4>().as_int32(); }
  bool has_tracing_service_version() const { return at<5>().valid(); }
  ::protozero::ConstChars tracing_service_version() const { return at<5>().as_string(); }
};

class TracingServiceState : public ::protozero::Message {
 public:
  using Decoder = TracingServiceState_Decoder;
  enum : int32_t {
    kProducersFieldNumber = 1,
    kDataSourcesFieldNumber = 2,
    kTracingSessionsFieldNumber = 6,
    kSupportsTracingSessionsFieldNumber = 7,
    kNumSessionsFieldNumber = 3,
    kNumSessionsStartedFieldNumber = 4,
    kTracingServiceVersionFieldNumber = 5,
  };
  static constexpr const char* GetName() { return ".perfetto.protos.TracingServiceState"; }

  using Producer = ::perfetto::protos::pbzero::TracingServiceState_Producer;
  using DataSource = ::perfetto::protos::pbzero::TracingServiceState_DataSource;
  using TracingSession = ::perfetto::protos::pbzero::TracingServiceState_TracingSession;

  using FieldMetadata_Producers =
    ::protozero::proto_utils::FieldMetadata<
      1,
      ::protozero::proto_utils::RepetitionType::kRepeatedNotPacked,
      ::protozero::proto_utils::ProtoSchemaType::kMessage,
      TracingServiceState_Producer,
      TracingServiceState>;

  // Ceci n'est pas une pipe.
  // This is actually a variable of FieldMetadataHelper<FieldMetadata<...>>
  // type (and users are expected to use it as such, hence kCamelCase name).
  // It is declared as a function to keep protozero bindings header-only as
  // inline constexpr variables are not available until C++17 (while inline
  // functions are).
  // TODO(altimin): Use inline variable instead after adopting C++17.
  static constexpr FieldMetadata_Producers kProducers() { return {}; }
  template <typename T = TracingServiceState_Producer> T* add_producers() {
    return BeginNestedMessage<T>(1);
  }


  using FieldMetadata_DataSources =
    ::protozero::proto_utils::FieldMetadata<
      2,
      ::protozero::proto_utils::RepetitionType::kRepeatedNotPacked,
      ::protozero::proto_utils::ProtoSchemaType::kMessage,
      TracingServiceState_DataSource,
      TracingServiceState>;

  // Ceci n'est pas une pipe.
  // This is actually a variable of FieldMetadataHelper<FieldMetadata<...>>
  // type (and users are expected to use it as such, hence kCamelCase name).
  // It is declared as a function to keep protozero bindings header-only as
  // inline constexpr variables are not available until C++17 (while inline
  // functions are).
  // TODO(altimin): Use inline variable instead after adopting C++17.
  static constexpr FieldMetadata_DataSources kDataSources() { return {}; }
  template <typename T = TracingServiceState_DataSource> T* add_data_sources() {
    return BeginNestedMessage<T>(2);
  }


  using FieldMetadata_TracingSessions =
    ::protozero::proto_utils::FieldMetadata<
      6,
      ::protozero::proto_utils::RepetitionType::kRepeatedNotPacked,
      ::protozero::proto_utils::ProtoSchemaType::kMessage,
      TracingServiceState_TracingSession,
      TracingServiceState>;

  // Ceci n'est pas une pipe.
  // This is actually a variable of FieldMetadataHelper<FieldMetadata<...>>
  // type (and users are expected to use it as such, hence kCamelCase name).
  // It is declared as a function to keep protozero bindings header-only as
  // inline constexpr variables are not available until C++17 (while inline
  // functions are).
  // TODO(altimin): Use inline variable instead after adopting C++17.
  static constexpr FieldMetadata_TracingSessions kTracingSessions() { return {}; }
  template <typename T = TracingServiceState_TracingSession> T* add_tracing_sessions() {
    return BeginNestedMessage<T>(6);
  }


  using FieldMetadata_SupportsTracingSessions =
    ::protozero::proto_utils::FieldMetadata<
      7,
      ::protozero::proto_utils::RepetitionType::kNotRepeated,
      ::protozero::proto_utils::ProtoSchemaType::kBool,
      bool,
      TracingServiceState>;

  // Ceci n'est pas une pipe.
  // This is actually a variable of FieldMetadataHelper<FieldMetadata<...>>
  // type (and users are expected to use it as such, hence kCamelCase name).
  // It is declared as a function to keep protozero bindings header-only as
  // inline constexpr variables are not available until C++17 (while inline
  // functions are).
  // TODO(altimin): Use inline variable instead after adopting C++17.
  static constexpr FieldMetadata_SupportsTracingSessions kSupportsTracingSessions() { return {}; }
  void set_supports_tracing_sessions(bool value) {
    static constexpr uint32_t field_id = FieldMetadata_SupportsTracingSessions::kFieldId;
    // Call the appropriate protozero::Message::Append(field_id, ...)
    // method based on the type of the field.
    ::protozero::internal::FieldWriter<
      ::protozero::proto_utils::ProtoSchemaType::kBool>
        ::Append(*this, field_id, value);
  }

  using FieldMetadata_NumSessions =
    ::protozero::proto_utils::FieldMetadata<
      3,
      ::protozero::proto_utils::RepetitionType::kNotRepeated,
      ::protozero::proto_utils::ProtoSchemaType::kInt32,
      int32_t,
      TracingServiceState>;

  // Ceci n'est pas une pipe.
  // This is actually a variable of FieldMetadataHelper<FieldMetadata<...>>
  // type (and users are expected to use it as such, hence kCamelCase name).
  // It is declared as a function to keep protozero bindings header-only as
  // inline constexpr variables are not available until C++17 (while inline
  // functions are).
  // TODO(altimin): Use inline variable instead after adopting C++17.
  static constexpr FieldMetadata_NumSessions kNumSessions() { return {}; }
  void set_num_sessions(int32_t value) {
    static constexpr uint32_t field_id = FieldMetadata_NumSessions::kFieldId;
    // Call the appropriate protozero::Message::Append(field_id, ...)
    // method based on the type of the field.
    ::protozero::internal::FieldWriter<
      ::protozero::proto_utils::ProtoSchemaType::kInt32>
        ::Append(*this, field_id, value);
  }

  using FieldMetadata_NumSessionsStarted =
    ::protozero::proto_utils::FieldMetadata<
      4,
      ::protozero::proto_utils::RepetitionType::kNotRepeated,
      ::protozero::proto_utils::ProtoSchemaType::kInt32,
      int32_t,
      TracingServiceState>;

  // Ceci n'est pas une pipe.
  // This is actually a variable of FieldMetadataHelper<FieldMetadata<...>>
  // type (and users are expected to use it as such, hence kCamelCase name).
  // It is declared as a function to keep protozero bindings header-only as
  // inline constexpr variables are not available until C++17 (while inline
  // functions are).
  // TODO(altimin): Use inline variable instead after adopting C++17.
  static constexpr FieldMetadata_NumSessionsStarted kNumSessionsStarted() { return {}; }
  void set_num_sessions_started(int32_t value) {
    static constexpr uint32_t field_id = FieldMetadata_NumSessionsStarted::kFieldId;
    // Call the appropriate protozero::Message::Append(field_id, ...)
    // method based on the type of the field.
    ::protozero::internal::FieldWriter<
      ::protozero::proto_utils::ProtoSchemaType::kInt32>
        ::Append(*this, field_id, value);
  }

  using FieldMetadata_TracingServiceVersion =
    ::protozero::proto_utils::FieldMetadata<
      5,
      ::protozero::proto_utils::RepetitionType::kNotRepeated,
      ::protozero::proto_utils::ProtoSchemaType::kString,
      std::string,
      TracingServiceState>;

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
};

class TracingServiceState_TracingSession_Decoder : public ::protozero::TypedProtoDecoder</*MAX_FIELD_ID=*/8, /*HAS_NONPACKED_REPEATED_FIELDS=*/true> {
 public:
  TracingServiceState_TracingSession_Decoder(const uint8_t* data, size_t len) : TypedProtoDecoder(data, len) {}
  explicit TracingServiceState_TracingSession_Decoder(const std::string& raw) : TypedProtoDecoder(reinterpret_cast<const uint8_t*>(raw.data()), raw.size()) {}
  explicit TracingServiceState_TracingSession_Decoder(const ::protozero::ConstBytes& raw) : TypedProtoDecoder(raw.data, raw.size) {}
  bool has_id() const { return at<1>().valid(); }
  uint64_t id() const { return at<1>().as_uint64(); }
  bool has_consumer_uid() const { return at<2>().valid(); }
  int32_t consumer_uid() const { return at<2>().as_int32(); }
  bool has_state() const { return at<3>().valid(); }
  ::protozero::ConstChars state() const { return at<3>().as_string(); }
  bool has_unique_session_name() const { return at<4>().valid(); }
  ::protozero::ConstChars unique_session_name() const { return at<4>().as_string(); }
  bool has_buffer_size_kb() const { return at<5>().valid(); }
  ::protozero::RepeatedFieldIterator<uint32_t> buffer_size_kb() const { return GetRepeated<uint32_t>(5); }
  bool has_duration_ms() const { return at<6>().valid(); }
  uint32_t duration_ms() const { return at<6>().as_uint32(); }
  bool has_num_data_sources() const { return at<7>().valid(); }
  uint32_t num_data_sources() const { return at<7>().as_uint32(); }
  bool has_start_realtime_ns() const { return at<8>().valid(); }
  int64_t start_realtime_ns() const { return at<8>().as_int64(); }
};

class TracingServiceState_TracingSession : public ::protozero::Message {
 public:
  using Decoder = TracingServiceState_TracingSession_Decoder;
  enum : int32_t {
    kIdFieldNumber = 1,
    kConsumerUidFieldNumber = 2,
    kStateFieldNumber = 3,
    kUniqueSessionNameFieldNumber = 4,
    kBufferSizeKbFieldNumber = 5,
    kDurationMsFieldNumber = 6,
    kNumDataSourcesFieldNumber = 7,
    kStartRealtimeNsFieldNumber = 8,
  };
  static constexpr const char* GetName() { return ".perfetto.protos.TracingServiceState.TracingSession"; }


  using FieldMetadata_Id =
    ::protozero::proto_utils::FieldMetadata<
      1,
      ::protozero::proto_utils::RepetitionType::kNotRepeated,
      ::protozero::proto_utils::ProtoSchemaType::kUint64,
      uint64_t,
      TracingServiceState_TracingSession>;

  // Ceci n'est pas une pipe.
  // This is actually a variable of FieldMetadataHelper<FieldMetadata<...>>
  // type (and users are expected to use it as such, hence kCamelCase name).
  // It is declared as a function to keep protozero bindings header-only as
  // inline constexpr variables are not available until C++17 (while inline
  // functions are).
  // TODO(altimin): Use inline variable instead after adopting C++17.
  static constexpr FieldMetadata_Id kId() { return {}; }
  void set_id(uint64_t value) {
    static constexpr uint32_t field_id = FieldMetadata_Id::kFieldId;
    // Call the appropriate protozero::Message::Append(field_id, ...)
    // method based on the type of the field.
    ::protozero::internal::FieldWriter<
      ::protozero::proto_utils::ProtoSchemaType::kUint64>
        ::Append(*this, field_id, value);
  }

  using FieldMetadata_ConsumerUid =
    ::protozero::proto_utils::FieldMetadata<
      2,
      ::protozero::proto_utils::RepetitionType::kNotRepeated,
      ::protozero::proto_utils::ProtoSchemaType::kInt32,
      int32_t,
      TracingServiceState_TracingSession>;

  // Ceci n'est pas une pipe.
  // This is actually a variable of FieldMetadataHelper<FieldMetadata<...>>
  // type (and users are expected to use it as such, hence kCamelCase name).
  // It is declared as a function to keep protozero bindings header-only as
  // inline constexpr variables are not available until C++17 (while inline
  // functions are).
  // TODO(altimin): Use inline variable instead after adopting C++17.
  static constexpr FieldMetadata_ConsumerUid kConsumerUid() { return {}; }
  void set_consumer_uid(int32_t value) {
    static constexpr uint32_t field_id = FieldMetadata_ConsumerUid::kFieldId;
    // Call the appropriate protozero::Message::Append(field_id, ...)
    // method based on the type of the field.
    ::protozero::internal::FieldWriter<
      ::protozero::proto_utils::ProtoSchemaType::kInt32>
        ::Append(*this, field_id, value);
  }

  using FieldMetadata_State =
    ::protozero::proto_utils::FieldMetadata<
      3,
      ::protozero::proto_utils::RepetitionType::kNotRepeated,
      ::protozero::proto_utils::ProtoSchemaType::kString,
      std::string,
      TracingServiceState_TracingSession>;

  // Ceci n'est pas une pipe.
  // This is actually a variable of FieldMetadataHelper<FieldMetadata<...>>
  // type (and users are expected to use it as such, hence kCamelCase name).
  // It is declared as a function to keep protozero bindings header-only as
  // inline constexpr variables are not available until C++17 (while inline
  // functions are).
  // TODO(altimin): Use inline variable instead after adopting C++17.
  static constexpr FieldMetadata_State kState() { return {}; }
  void set_state(const char* data, size_t size) {
    AppendBytes(FieldMetadata_State::kFieldId, data, size);
  }
  void set_state(std::string value) {
    static constexpr uint32_t field_id = FieldMetadata_State::kFieldId;
    // Call the appropriate protozero::Message::Append(field_id, ...)
    // method based on the type of the field.
    ::protozero::internal::FieldWriter<
      ::protozero::proto_utils::ProtoSchemaType::kString>
        ::Append(*this, field_id, value);
  }

  using FieldMetadata_UniqueSessionName =
    ::protozero::proto_utils::FieldMetadata<
      4,
      ::protozero::proto_utils::RepetitionType::kNotRepeated,
      ::protozero::proto_utils::ProtoSchemaType::kString,
      std::string,
      TracingServiceState_TracingSession>;

  // Ceci n'est pas une pipe.
  // This is actually a variable of FieldMetadataHelper<FieldMetadata<...>>
  // type (and users are expected to use it as such, hence kCamelCase name).
  // It is declared as a function to keep protozero bindings header-only as
  // inline constexpr variables are not available until C++17 (while inline
  // functions are).
  // TODO(altimin): Use inline variable instead after adopting C++17.
  static constexpr FieldMetadata_UniqueSessionName kUniqueSessionName() { return {}; }
  void set_unique_session_name(const char* data, size_t size) {
    AppendBytes(FieldMetadata_UniqueSessionName::kFieldId, data, size);
  }
  void set_unique_session_name(std::string value) {
    static constexpr uint32_t field_id = FieldMetadata_UniqueSessionName::kFieldId;
    // Call the appropriate protozero::Message::Append(field_id, ...)
    // method based on the type of the field.
    ::protozero::internal::FieldWriter<
      ::protozero::proto_utils::ProtoSchemaType::kString>
        ::Append(*this, field_id, value);
  }

  using FieldMetadata_BufferSizeKb =
    ::protozero::proto_utils::FieldMetadata<
      5,
      ::protozero::proto_utils::RepetitionType::kRepeatedNotPacked,
      ::protozero::proto_utils::ProtoSchemaType::kUint32,
      uint32_t,
      TracingServiceState_TracingSession>;

  // Ceci n'est pas une pipe.
  // This is actually a variable of FieldMetadataHelper<FieldMetadata<...>>
  // type (and users are expected to use it as such, hence kCamelCase name).
  // It is declared as a function to keep protozero bindings header-only as
  // inline constexpr variables are not available until C++17 (while inline
  // functions are).
  // TODO(altimin): Use inline variable instead after adopting C++17.
  static constexpr FieldMetadata_BufferSizeKb kBufferSizeKb() { return {}; }
  void add_buffer_size_kb(uint32_t value) {
    static constexpr uint32_t field_id = FieldMetadata_BufferSizeKb::kFieldId;
    // Call the appropriate protozero::Message::Append(field_id, ...)
    // method based on the type of the field.
    ::protozero::internal::FieldWriter<
      ::protozero::proto_utils::ProtoSchemaType::kUint32>
        ::Append(*this, field_id, value);
  }

  using FieldMetadata_DurationMs =
    ::protozero::proto_utils::FieldMetadata<
      6,
      ::protozero::proto_utils::RepetitionType::kNotRepeated,
      ::protozero::proto_utils::ProtoSchemaType::kUint32,
      uint32_t,
      TracingServiceState_TracingSession>;

  // Ceci n'est pas une pipe.
  // This is actually a variable of FieldMetadataHelper<FieldMetadata<...>>
  // type (and users are expected to use it as such, hence kCamelCase name).
  // It is declared as a function to keep protozero bindings header-only as
  // inline constexpr variables are not available until C++17 (while inline
  // functions are).
  // TODO(altimin): Use inline variable instead after adopting C++17.
  static constexpr FieldMetadata_DurationMs kDurationMs() { return {}; }
  void set_duration_ms(uint32_t value) {
    static constexpr uint32_t field_id = FieldMetadata_DurationMs::kFieldId;
    // Call the appropriate protozero::Message::Append(field_id, ...)
    // method based on the type of the field.
    ::protozero::internal::FieldWriter<
      ::protozero::proto_utils::ProtoSchemaType::kUint32>
        ::Append(*this, field_id, value);
  }

  using FieldMetadata_NumDataSources =
    ::protozero::proto_utils::FieldMetadata<
      7,
      ::protozero::proto_utils::RepetitionType::kNotRepeated,
      ::protozero::proto_utils::ProtoSchemaType::kUint32,
      uint32_t,
      TracingServiceState_TracingSession>;

  // Ceci n'est pas une pipe.
  // This is actually a variable of FieldMetadataHelper<FieldMetadata<...>>
  // type (and users are expected to use it as such, hence kCamelCase name).
  // It is declared as a function to keep protozero bindings header-only as
  // inline constexpr variables are not available until C++17 (while inline
  // functions are).
  // TODO(altimin): Use inline variable instead after adopting C++17.
  static constexpr FieldMetadata_NumDataSources kNumDataSources() { return {}; }
  void set_num_data_sources(uint32_t value) {
    static constexpr uint32_t field_id = FieldMetadata_NumDataSources::kFieldId;
    // Call the appropriate protozero::Message::Append(field_id, ...)
    // method based on the type of the field.
    ::protozero::internal::FieldWriter<
      ::protozero::proto_utils::ProtoSchemaType::kUint32>
        ::Append(*this, field_id, value);
  }

  using FieldMetadata_StartRealtimeNs =
    ::protozero::proto_utils::FieldMetadata<
      8,
      ::protozero::proto_utils::RepetitionType::kNotRepeated,
      ::protozero::proto_utils::ProtoSchemaType::kInt64,
      int64_t,
      TracingServiceState_TracingSession>;

  // Ceci n'est pas une pipe.
  // This is actually a variable of FieldMetadataHelper<FieldMetadata<...>>
  // type (and users are expected to use it as such, hence kCamelCase name).
  // It is declared as a function to keep protozero bindings header-only as
  // inline constexpr variables are not available until C++17 (while inline
  // functions are).
  // TODO(altimin): Use inline variable instead after adopting C++17.
  static constexpr FieldMetadata_StartRealtimeNs kStartRealtimeNs() { return {}; }
  void set_start_realtime_ns(int64_t value) {
    static constexpr uint32_t field_id = FieldMetadata_StartRealtimeNs::kFieldId;
    // Call the appropriate protozero::Message::Append(field_id, ...)
    // method based on the type of the field.
    ::protozero::internal::FieldWriter<
      ::protozero::proto_utils::ProtoSchemaType::kInt64>
        ::Append(*this, field_id, value);
  }
};

class TracingServiceState_DataSource_Decoder : public ::protozero::TypedProtoDecoder</*MAX_FIELD_ID=*/2, /*HAS_NONPACKED_REPEATED_FIELDS=*/false> {
 public:
  TracingServiceState_DataSource_Decoder(const uint8_t* data, size_t len) : TypedProtoDecoder(data, len) {}
  explicit TracingServiceState_DataSource_Decoder(const std::string& raw) : TypedProtoDecoder(reinterpret_cast<const uint8_t*>(raw.data()), raw.size()) {}
  explicit TracingServiceState_DataSource_Decoder(const ::protozero::ConstBytes& raw) : TypedProtoDecoder(raw.data, raw.size) {}
  bool has_ds_descriptor() const { return at<1>().valid(); }
  ::protozero::ConstBytes ds_descriptor() const { return at<1>().as_bytes(); }
  bool has_producer_id() const { return at<2>().valid(); }
  int32_t producer_id() const { return at<2>().as_int32(); }
};

class TracingServiceState_DataSource : public ::protozero::Message {
 public:
  using Decoder = TracingServiceState_DataSource_Decoder;
  enum : int32_t {
    kDsDescriptorFieldNumber = 1,
    kProducerIdFieldNumber = 2,
  };
  static constexpr const char* GetName() { return ".perfetto.protos.TracingServiceState.DataSource"; }


  using FieldMetadata_DsDescriptor =
    ::protozero::proto_utils::FieldMetadata<
      1,
      ::protozero::proto_utils::RepetitionType::kNotRepeated,
      ::protozero::proto_utils::ProtoSchemaType::kMessage,
      DataSourceDescriptor,
      TracingServiceState_DataSource>;

  // Ceci n'est pas une pipe.
  // This is actually a variable of FieldMetadataHelper<FieldMetadata<...>>
  // type (and users are expected to use it as such, hence kCamelCase name).
  // It is declared as a function to keep protozero bindings header-only as
  // inline constexpr variables are not available until C++17 (while inline
  // functions are).
  // TODO(altimin): Use inline variable instead after adopting C++17.
  static constexpr FieldMetadata_DsDescriptor kDsDescriptor() { return {}; }
  template <typename T = DataSourceDescriptor> T* set_ds_descriptor() {
    return BeginNestedMessage<T>(1);
  }


  using FieldMetadata_ProducerId =
    ::protozero::proto_utils::FieldMetadata<
      2,
      ::protozero::proto_utils::RepetitionType::kNotRepeated,
      ::protozero::proto_utils::ProtoSchemaType::kInt32,
      int32_t,
      TracingServiceState_DataSource>;

  // Ceci n'est pas une pipe.
  // This is actually a variable of FieldMetadataHelper<FieldMetadata<...>>
  // type (and users are expected to use it as such, hence kCamelCase name).
  // It is declared as a function to keep protozero bindings header-only as
  // inline constexpr variables are not available until C++17 (while inline
  // functions are).
  // TODO(altimin): Use inline variable instead after adopting C++17.
  static constexpr FieldMetadata_ProducerId kProducerId() { return {}; }
  void set_producer_id(int32_t value) {
    static constexpr uint32_t field_id = FieldMetadata_ProducerId::kFieldId;
    // Call the appropriate protozero::Message::Append(field_id, ...)
    // method based on the type of the field.
    ::protozero::internal::FieldWriter<
      ::protozero::proto_utils::ProtoSchemaType::kInt32>
        ::Append(*this, field_id, value);
  }
};

class TracingServiceState_Producer_Decoder : public ::protozero::TypedProtoDecoder</*MAX_FIELD_ID=*/5, /*HAS_NONPACKED_REPEATED_FIELDS=*/false> {
 public:
  TracingServiceState_Producer_Decoder(const uint8_t* data, size_t len) : TypedProtoDecoder(data, len) {}
  explicit TracingServiceState_Producer_Decoder(const std::string& raw) : TypedProtoDecoder(reinterpret_cast<const uint8_t*>(raw.data()), raw.size()) {}
  explicit TracingServiceState_Producer_Decoder(const ::protozero::ConstBytes& raw) : TypedProtoDecoder(raw.data, raw.size) {}
  bool has_id() const { return at<1>().valid(); }
  int32_t id() const { return at<1>().as_int32(); }
  bool has_name() const { return at<2>().valid(); }
  ::protozero::ConstChars name() const { return at<2>().as_string(); }
  bool has_pid() const { return at<5>().valid(); }
  int32_t pid() const { return at<5>().as_int32(); }
  bool has_uid() const { return at<3>().valid(); }
  int32_t uid() const { return at<3>().as_int32(); }
  bool has_sdk_version() const { return at<4>().valid(); }
  ::protozero::ConstChars sdk_version() const { return at<4>().as_string(); }
};

class TracingServiceState_Producer : public ::protozero::Message {
 public:
  using Decoder = TracingServiceState_Producer_Decoder;
  enum : int32_t {
    kIdFieldNumber = 1,
    kNameFieldNumber = 2,
    kPidFieldNumber = 5,
    kUidFieldNumber = 3,
    kSdkVersionFieldNumber = 4,
  };
  static constexpr const char* GetName() { return ".perfetto.protos.TracingServiceState.Producer"; }


  using FieldMetadata_Id =
    ::protozero::proto_utils::FieldMetadata<
      1,
      ::protozero::proto_utils::RepetitionType::kNotRepeated,
      ::protozero::proto_utils::ProtoSchemaType::kInt32,
      int32_t,
      TracingServiceState_Producer>;

  // Ceci n'est pas une pipe.
  // This is actually a variable of FieldMetadataHelper<FieldMetadata<...>>
  // type (and users are expected to use it as such, hence kCamelCase name).
  // It is declared as a function to keep protozero bindings header-only as
  // inline constexpr variables are not available until C++17 (while inline
  // functions are).
  // TODO(altimin): Use inline variable instead after adopting C++17.
  static constexpr FieldMetadata_Id kId() { return {}; }
  void set_id(int32_t value) {
    static constexpr uint32_t field_id = FieldMetadata_Id::kFieldId;
    // Call the appropriate protozero::Message::Append(field_id, ...)
    // method based on the type of the field.
    ::protozero::internal::FieldWriter<
      ::protozero::proto_utils::ProtoSchemaType::kInt32>
        ::Append(*this, field_id, value);
  }

  using FieldMetadata_Name =
    ::protozero::proto_utils::FieldMetadata<
      2,
      ::protozero::proto_utils::RepetitionType::kNotRepeated,
      ::protozero::proto_utils::ProtoSchemaType::kString,
      std::string,
      TracingServiceState_Producer>;

  // Ceci n'est pas une pipe.
  // This is actually a variable of FieldMetadataHelper<FieldMetadata<...>>
  // type (and users are expected to use it as such, hence kCamelCase name).
  // It is declared as a function to keep protozero bindings header-only as
  // inline constexpr variables are not available until C++17 (while inline
  // functions are).
  // TODO(altimin): Use inline variable instead after adopting C++17.
  static constexpr FieldMetadata_Name kName() { return {}; }
  void set_name(const char* data, size_t size) {
    AppendBytes(FieldMetadata_Name::kFieldId, data, size);
  }
  void set_name(std::string value) {
    static constexpr uint32_t field_id = FieldMetadata_Name::kFieldId;
    // Call the appropriate protozero::Message::Append(field_id, ...)
    // method based on the type of the field.
    ::protozero::internal::FieldWriter<
      ::protozero::proto_utils::ProtoSchemaType::kString>
        ::Append(*this, field_id, value);
  }

  using FieldMetadata_Pid =
    ::protozero::proto_utils::FieldMetadata<
      5,
      ::protozero::proto_utils::RepetitionType::kNotRepeated,
      ::protozero::proto_utils::ProtoSchemaType::kInt32,
      int32_t,
      TracingServiceState_Producer>;

  // Ceci n'est pas une pipe.
  // This is actually a variable of FieldMetadataHelper<FieldMetadata<...>>
  // type (and users are expected to use it as such, hence kCamelCase name).
  // It is declared as a function to keep protozero bindings header-only as
  // inline constexpr variables are not available until C++17 (while inline
  // functions are).
  // TODO(altimin): Use inline variable instead after adopting C++17.
  static constexpr FieldMetadata_Pid kPid() { return {}; }
  void set_pid(int32_t value) {
    static constexpr uint32_t field_id = FieldMetadata_Pid::kFieldId;
    // Call the appropriate protozero::Message::Append(field_id, ...)
    // method based on the type of the field.
    ::protozero::internal::FieldWriter<
      ::protozero::proto_utils::ProtoSchemaType::kInt32>
        ::Append(*this, field_id, value);
  }

  using FieldMetadata_Uid =
    ::protozero::proto_utils::FieldMetadata<
      3,
      ::protozero::proto_utils::RepetitionType::kNotRepeated,
      ::protozero::proto_utils::ProtoSchemaType::kInt32,
      int32_t,
      TracingServiceState_Producer>;

  // Ceci n'est pas une pipe.
  // This is actually a variable of FieldMetadataHelper<FieldMetadata<...>>
  // type (and users are expected to use it as such, hence kCamelCase name).
  // It is declared as a function to keep protozero bindings header-only as
  // inline constexpr variables are not available until C++17 (while inline
  // functions are).
  // TODO(altimin): Use inline variable instead after adopting C++17.
  static constexpr FieldMetadata_Uid kUid() { return {}; }
  void set_uid(int32_t value) {
    static constexpr uint32_t field_id = FieldMetadata_Uid::kFieldId;
    // Call the appropriate protozero::Message::Append(field_id, ...)
    // method based on the type of the field.
    ::protozero::internal::FieldWriter<
      ::protozero::proto_utils::ProtoSchemaType::kInt32>
        ::Append(*this, field_id, value);
  }

  using FieldMetadata_SdkVersion =
    ::protozero::proto_utils::FieldMetadata<
      4,
      ::protozero::proto_utils::RepetitionType::kNotRepeated,
      ::protozero::proto_utils::ProtoSchemaType::kString,
      std::string,
      TracingServiceState_Producer>;

  // Ceci n'est pas une pipe.
  // This is actually a variable of FieldMetadataHelper<FieldMetadata<...>>
  // type (and users are expected to use it as such, hence kCamelCase name).
  // It is declared as a function to keep protozero bindings header-only as
  // inline constexpr variables are not available until C++17 (while inline
  // functions are).
  // TODO(altimin): Use inline variable instead after adopting C++17.
  static constexpr FieldMetadata_SdkVersion kSdkVersion() { return {}; }
  void set_sdk_version(const char* data, size_t size) {
    AppendBytes(FieldMetadata_SdkVersion::kFieldId, data, size);
  }
  void set_sdk_version(std::string value) {
    static constexpr uint32_t field_id = FieldMetadata_SdkVersion::kFieldId;
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
