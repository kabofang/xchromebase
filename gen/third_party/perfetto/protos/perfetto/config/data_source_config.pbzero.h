// Autogenerated by the ProtoZero compiler plugin. DO NOT EDIT.

#ifndef PERFETTO_PROTOS_PROTOS_PERFETTO_CONFIG_DATA_SOURCE_CONFIG_PROTO_H_
#define PERFETTO_PROTOS_PROTOS_PERFETTO_CONFIG_DATA_SOURCE_CONFIG_PROTO_H_

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

class AndroidLogConfig;
class AndroidPolledStateConfig;
class AndroidPowerConfig;
class ChromeConfig;
class FtraceConfig;
class GpuCounterConfig;
class HeapprofdConfig;
class InodeFileConfig;
class InterceptorConfig;
class JavaHprofConfig;
class PackagesListConfig;
class PerfEventConfig;
class ProcessStatsConfig;
class SysStatsConfig;
class TestConfig;
class TrackEventConfig;
class VulkanMemoryConfig;
enum DataSourceConfig_SessionInitiator : int32_t;

enum DataSourceConfig_SessionInitiator : int32_t {
  DataSourceConfig_SessionInitiator_SESSION_INITIATOR_UNSPECIFIED = 0,
  DataSourceConfig_SessionInitiator_SESSION_INITIATOR_TRUSTED_SYSTEM = 1,
};

const DataSourceConfig_SessionInitiator DataSourceConfig_SessionInitiator_MIN = DataSourceConfig_SessionInitiator_SESSION_INITIATOR_UNSPECIFIED;
const DataSourceConfig_SessionInitiator DataSourceConfig_SessionInitiator_MAX = DataSourceConfig_SessionInitiator_SESSION_INITIATOR_TRUSTED_SYSTEM;

class DataSourceConfig_Decoder : public ::protozero::TypedProtoDecoder</*MAX_FIELD_ID=*/115, /*HAS_NONPACKED_REPEATED_FIELDS=*/false> {
 public:
  DataSourceConfig_Decoder(const uint8_t* data, size_t len) : TypedProtoDecoder(data, len) {}
  explicit DataSourceConfig_Decoder(const std::string& raw) : TypedProtoDecoder(reinterpret_cast<const uint8_t*>(raw.data()), raw.size()) {}
  explicit DataSourceConfig_Decoder(const ::protozero::ConstBytes& raw) : TypedProtoDecoder(raw.data, raw.size) {}
  bool has_name() const { return at<1>().valid(); }
  ::protozero::ConstChars name() const { return at<1>().as_string(); }
  bool has_target_buffer() const { return at<2>().valid(); }
  uint32_t target_buffer() const { return at<2>().as_uint32(); }
  bool has_trace_duration_ms() const { return at<3>().valid(); }
  uint32_t trace_duration_ms() const { return at<3>().as_uint32(); }
  bool has_stop_timeout_ms() const { return at<7>().valid(); }
  uint32_t stop_timeout_ms() const { return at<7>().as_uint32(); }
  bool has_enable_extra_guardrails() const { return at<6>().valid(); }
  bool enable_extra_guardrails() const { return at<6>().as_bool(); }
  bool has_session_initiator() const { return at<8>().valid(); }
  int32_t session_initiator() const { return at<8>().as_int32(); }
  bool has_tracing_session_id() const { return at<4>().valid(); }
  uint64_t tracing_session_id() const { return at<4>().as_uint64(); }
  bool has_ftrace_config() const { return at<100>().valid(); }
  ::protozero::ConstBytes ftrace_config() const { return at<100>().as_bytes(); }
  bool has_inode_file_config() const { return at<102>().valid(); }
  ::protozero::ConstBytes inode_file_config() const { return at<102>().as_bytes(); }
  bool has_process_stats_config() const { return at<103>().valid(); }
  ::protozero::ConstBytes process_stats_config() const { return at<103>().as_bytes(); }
  bool has_sys_stats_config() const { return at<104>().valid(); }
  ::protozero::ConstBytes sys_stats_config() const { return at<104>().as_bytes(); }
  bool has_heapprofd_config() const { return at<105>().valid(); }
  ::protozero::ConstBytes heapprofd_config() const { return at<105>().as_bytes(); }
  bool has_java_hprof_config() const { return at<110>().valid(); }
  ::protozero::ConstBytes java_hprof_config() const { return at<110>().as_bytes(); }
  bool has_android_power_config() const { return at<106>().valid(); }
  ::protozero::ConstBytes android_power_config() const { return at<106>().as_bytes(); }
  bool has_android_log_config() const { return at<107>().valid(); }
  ::protozero::ConstBytes android_log_config() const { return at<107>().as_bytes(); }
  bool has_gpu_counter_config() const { return at<108>().valid(); }
  ::protozero::ConstBytes gpu_counter_config() const { return at<108>().as_bytes(); }
  bool has_packages_list_config() const { return at<109>().valid(); }
  ::protozero::ConstBytes packages_list_config() const { return at<109>().as_bytes(); }
  bool has_perf_event_config() const { return at<111>().valid(); }
  ::protozero::ConstBytes perf_event_config() const { return at<111>().as_bytes(); }
  bool has_vulkan_memory_config() const { return at<112>().valid(); }
  ::protozero::ConstBytes vulkan_memory_config() const { return at<112>().as_bytes(); }
  bool has_track_event_config() const { return at<113>().valid(); }
  ::protozero::ConstBytes track_event_config() const { return at<113>().as_bytes(); }
  bool has_android_polled_state_config() const { return at<114>().valid(); }
  ::protozero::ConstBytes android_polled_state_config() const { return at<114>().as_bytes(); }
  bool has_chrome_config() const { return at<101>().valid(); }
  ::protozero::ConstBytes chrome_config() const { return at<101>().as_bytes(); }
  bool has_interceptor_config() const { return at<115>().valid(); }
  ::protozero::ConstBytes interceptor_config() const { return at<115>().as_bytes(); }
  // field legacy_config omitted because its id is too high
  // field for_testing omitted because its id is too high
};

class DataSourceConfig : public ::protozero::Message {
 public:
  using Decoder = DataSourceConfig_Decoder;
  enum : int32_t {
    kNameFieldNumber = 1,
    kTargetBufferFieldNumber = 2,
    kTraceDurationMsFieldNumber = 3,
    kStopTimeoutMsFieldNumber = 7,
    kEnableExtraGuardrailsFieldNumber = 6,
    kSessionInitiatorFieldNumber = 8,
    kTracingSessionIdFieldNumber = 4,
    kFtraceConfigFieldNumber = 100,
    kInodeFileConfigFieldNumber = 102,
    kProcessStatsConfigFieldNumber = 103,
    kSysStatsConfigFieldNumber = 104,
    kHeapprofdConfigFieldNumber = 105,
    kJavaHprofConfigFieldNumber = 110,
    kAndroidPowerConfigFieldNumber = 106,
    kAndroidLogConfigFieldNumber = 107,
    kGpuCounterConfigFieldNumber = 108,
    kPackagesListConfigFieldNumber = 109,
    kPerfEventConfigFieldNumber = 111,
    kVulkanMemoryConfigFieldNumber = 112,
    kTrackEventConfigFieldNumber = 113,
    kAndroidPolledStateConfigFieldNumber = 114,
    kChromeConfigFieldNumber = 101,
    kInterceptorConfigFieldNumber = 115,
    kLegacyConfigFieldNumber = 1000,
    kForTestingFieldNumber = 1001,
  };
  static constexpr const char* GetName() { return ".perfetto.protos.DataSourceConfig"; }

  using SessionInitiator = ::perfetto::protos::pbzero::DataSourceConfig_SessionInitiator;
  static const SessionInitiator SESSION_INITIATOR_UNSPECIFIED = DataSourceConfig_SessionInitiator_SESSION_INITIATOR_UNSPECIFIED;
  static const SessionInitiator SESSION_INITIATOR_TRUSTED_SYSTEM = DataSourceConfig_SessionInitiator_SESSION_INITIATOR_TRUSTED_SYSTEM;

  using FieldMetadata_Name =
    ::protozero::proto_utils::FieldMetadata<
      1,
      ::protozero::proto_utils::RepetitionType::kNotRepeated,
      ::protozero::proto_utils::ProtoSchemaType::kString,
      std::string,
      DataSourceConfig>;

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

  using FieldMetadata_TargetBuffer =
    ::protozero::proto_utils::FieldMetadata<
      2,
      ::protozero::proto_utils::RepetitionType::kNotRepeated,
      ::protozero::proto_utils::ProtoSchemaType::kUint32,
      uint32_t,
      DataSourceConfig>;

  // Ceci n'est pas une pipe.
  // This is actually a variable of FieldMetadataHelper<FieldMetadata<...>>
  // type (and users are expected to use it as such, hence kCamelCase name).
  // It is declared as a function to keep protozero bindings header-only as
  // inline constexpr variables are not available until C++17 (while inline
  // functions are).
  // TODO(altimin): Use inline variable instead after adopting C++17.
  static constexpr FieldMetadata_TargetBuffer kTargetBuffer() { return {}; }
  void set_target_buffer(uint32_t value) {
    static constexpr uint32_t field_id = FieldMetadata_TargetBuffer::kFieldId;
    // Call the appropriate protozero::Message::Append(field_id, ...)
    // method based on the type of the field.
    ::protozero::internal::FieldWriter<
      ::protozero::proto_utils::ProtoSchemaType::kUint32>
        ::Append(*this, field_id, value);
  }

  using FieldMetadata_TraceDurationMs =
    ::protozero::proto_utils::FieldMetadata<
      3,
      ::protozero::proto_utils::RepetitionType::kNotRepeated,
      ::protozero::proto_utils::ProtoSchemaType::kUint32,
      uint32_t,
      DataSourceConfig>;

  // Ceci n'est pas une pipe.
  // This is actually a variable of FieldMetadataHelper<FieldMetadata<...>>
  // type (and users are expected to use it as such, hence kCamelCase name).
  // It is declared as a function to keep protozero bindings header-only as
  // inline constexpr variables are not available until C++17 (while inline
  // functions are).
  // TODO(altimin): Use inline variable instead after adopting C++17.
  static constexpr FieldMetadata_TraceDurationMs kTraceDurationMs() { return {}; }
  void set_trace_duration_ms(uint32_t value) {
    static constexpr uint32_t field_id = FieldMetadata_TraceDurationMs::kFieldId;
    // Call the appropriate protozero::Message::Append(field_id, ...)
    // method based on the type of the field.
    ::protozero::internal::FieldWriter<
      ::protozero::proto_utils::ProtoSchemaType::kUint32>
        ::Append(*this, field_id, value);
  }

  using FieldMetadata_StopTimeoutMs =
    ::protozero::proto_utils::FieldMetadata<
      7,
      ::protozero::proto_utils::RepetitionType::kNotRepeated,
      ::protozero::proto_utils::ProtoSchemaType::kUint32,
      uint32_t,
      DataSourceConfig>;

  // Ceci n'est pas une pipe.
  // This is actually a variable of FieldMetadataHelper<FieldMetadata<...>>
  // type (and users are expected to use it as such, hence kCamelCase name).
  // It is declared as a function to keep protozero bindings header-only as
  // inline constexpr variables are not available until C++17 (while inline
  // functions are).
  // TODO(altimin): Use inline variable instead after adopting C++17.
  static constexpr FieldMetadata_StopTimeoutMs kStopTimeoutMs() { return {}; }
  void set_stop_timeout_ms(uint32_t value) {
    static constexpr uint32_t field_id = FieldMetadata_StopTimeoutMs::kFieldId;
    // Call the appropriate protozero::Message::Append(field_id, ...)
    // method based on the type of the field.
    ::protozero::internal::FieldWriter<
      ::protozero::proto_utils::ProtoSchemaType::kUint32>
        ::Append(*this, field_id, value);
  }

  using FieldMetadata_EnableExtraGuardrails =
    ::protozero::proto_utils::FieldMetadata<
      6,
      ::protozero::proto_utils::RepetitionType::kNotRepeated,
      ::protozero::proto_utils::ProtoSchemaType::kBool,
      bool,
      DataSourceConfig>;

  // Ceci n'est pas une pipe.
  // This is actually a variable of FieldMetadataHelper<FieldMetadata<...>>
  // type (and users are expected to use it as such, hence kCamelCase name).
  // It is declared as a function to keep protozero bindings header-only as
  // inline constexpr variables are not available until C++17 (while inline
  // functions are).
  // TODO(altimin): Use inline variable instead after adopting C++17.
  static constexpr FieldMetadata_EnableExtraGuardrails kEnableExtraGuardrails() { return {}; }
  void set_enable_extra_guardrails(bool value) {
    static constexpr uint32_t field_id = FieldMetadata_EnableExtraGuardrails::kFieldId;
    // Call the appropriate protozero::Message::Append(field_id, ...)
    // method based on the type of the field.
    ::protozero::internal::FieldWriter<
      ::protozero::proto_utils::ProtoSchemaType::kBool>
        ::Append(*this, field_id, value);
  }

  using FieldMetadata_SessionInitiator =
    ::protozero::proto_utils::FieldMetadata<
      8,
      ::protozero::proto_utils::RepetitionType::kNotRepeated,
      ::protozero::proto_utils::ProtoSchemaType::kEnum,
      ::perfetto::protos::pbzero::DataSourceConfig_SessionInitiator,
      DataSourceConfig>;

  // Ceci n'est pas une pipe.
  // This is actually a variable of FieldMetadataHelper<FieldMetadata<...>>
  // type (and users are expected to use it as such, hence kCamelCase name).
  // It is declared as a function to keep protozero bindings header-only as
  // inline constexpr variables are not available until C++17 (while inline
  // functions are).
  // TODO(altimin): Use inline variable instead after adopting C++17.
  static constexpr FieldMetadata_SessionInitiator kSessionInitiator() { return {}; }
  void set_session_initiator(::perfetto::protos::pbzero::DataSourceConfig_SessionInitiator value) {
    static constexpr uint32_t field_id = FieldMetadata_SessionInitiator::kFieldId;
    // Call the appropriate protozero::Message::Append(field_id, ...)
    // method based on the type of the field.
    ::protozero::internal::FieldWriter<
      ::protozero::proto_utils::ProtoSchemaType::kEnum>
        ::Append(*this, field_id, value);
  }

  using FieldMetadata_TracingSessionId =
    ::protozero::proto_utils::FieldMetadata<
      4,
      ::protozero::proto_utils::RepetitionType::kNotRepeated,
      ::protozero::proto_utils::ProtoSchemaType::kUint64,
      uint64_t,
      DataSourceConfig>;

  // Ceci n'est pas une pipe.
  // This is actually a variable of FieldMetadataHelper<FieldMetadata<...>>
  // type (and users are expected to use it as such, hence kCamelCase name).
  // It is declared as a function to keep protozero bindings header-only as
  // inline constexpr variables are not available until C++17 (while inline
  // functions are).
  // TODO(altimin): Use inline variable instead after adopting C++17.
  static constexpr FieldMetadata_TracingSessionId kTracingSessionId() { return {}; }
  void set_tracing_session_id(uint64_t value) {
    static constexpr uint32_t field_id = FieldMetadata_TracingSessionId::kFieldId;
    // Call the appropriate protozero::Message::Append(field_id, ...)
    // method based on the type of the field.
    ::protozero::internal::FieldWriter<
      ::protozero::proto_utils::ProtoSchemaType::kUint64>
        ::Append(*this, field_id, value);
  }

  using FieldMetadata_FtraceConfig =
    ::protozero::proto_utils::FieldMetadata<
      100,
      ::protozero::proto_utils::RepetitionType::kNotRepeated,
      ::protozero::proto_utils::ProtoSchemaType::kMessage,
      FtraceConfig,
      DataSourceConfig>;

  // Ceci n'est pas une pipe.
  // This is actually a variable of FieldMetadataHelper<FieldMetadata<...>>
  // type (and users are expected to use it as such, hence kCamelCase name).
  // It is declared as a function to keep protozero bindings header-only as
  // inline constexpr variables are not available until C++17 (while inline
  // functions are).
  // TODO(altimin): Use inline variable instead after adopting C++17.
  static constexpr FieldMetadata_FtraceConfig kFtraceConfig() { return {}; }
  template <typename T = FtraceConfig> T* set_ftrace_config() {
    return BeginNestedMessage<T>(100);
  }

  void set_ftrace_config_raw(const std::string& raw) {
    return AppendBytes(100, raw.data(), raw.size());
  }


  using FieldMetadata_InodeFileConfig =
    ::protozero::proto_utils::FieldMetadata<
      102,
      ::protozero::proto_utils::RepetitionType::kNotRepeated,
      ::protozero::proto_utils::ProtoSchemaType::kMessage,
      InodeFileConfig,
      DataSourceConfig>;

  // Ceci n'est pas une pipe.
  // This is actually a variable of FieldMetadataHelper<FieldMetadata<...>>
  // type (and users are expected to use it as such, hence kCamelCase name).
  // It is declared as a function to keep protozero bindings header-only as
  // inline constexpr variables are not available until C++17 (while inline
  // functions are).
  // TODO(altimin): Use inline variable instead after adopting C++17.
  static constexpr FieldMetadata_InodeFileConfig kInodeFileConfig() { return {}; }
  template <typename T = InodeFileConfig> T* set_inode_file_config() {
    return BeginNestedMessage<T>(102);
  }

  void set_inode_file_config_raw(const std::string& raw) {
    return AppendBytes(102, raw.data(), raw.size());
  }


  using FieldMetadata_ProcessStatsConfig =
    ::protozero::proto_utils::FieldMetadata<
      103,
      ::protozero::proto_utils::RepetitionType::kNotRepeated,
      ::protozero::proto_utils::ProtoSchemaType::kMessage,
      ProcessStatsConfig,
      DataSourceConfig>;

  // Ceci n'est pas une pipe.
  // This is actually a variable of FieldMetadataHelper<FieldMetadata<...>>
  // type (and users are expected to use it as such, hence kCamelCase name).
  // It is declared as a function to keep protozero bindings header-only as
  // inline constexpr variables are not available until C++17 (while inline
  // functions are).
  // TODO(altimin): Use inline variable instead after adopting C++17.
  static constexpr FieldMetadata_ProcessStatsConfig kProcessStatsConfig() { return {}; }
  template <typename T = ProcessStatsConfig> T* set_process_stats_config() {
    return BeginNestedMessage<T>(103);
  }

  void set_process_stats_config_raw(const std::string& raw) {
    return AppendBytes(103, raw.data(), raw.size());
  }


  using FieldMetadata_SysStatsConfig =
    ::protozero::proto_utils::FieldMetadata<
      104,
      ::protozero::proto_utils::RepetitionType::kNotRepeated,
      ::protozero::proto_utils::ProtoSchemaType::kMessage,
      SysStatsConfig,
      DataSourceConfig>;

  // Ceci n'est pas une pipe.
  // This is actually a variable of FieldMetadataHelper<FieldMetadata<...>>
  // type (and users are expected to use it as such, hence kCamelCase name).
  // It is declared as a function to keep protozero bindings header-only as
  // inline constexpr variables are not available until C++17 (while inline
  // functions are).
  // TODO(altimin): Use inline variable instead after adopting C++17.
  static constexpr FieldMetadata_SysStatsConfig kSysStatsConfig() { return {}; }
  template <typename T = SysStatsConfig> T* set_sys_stats_config() {
    return BeginNestedMessage<T>(104);
  }

  void set_sys_stats_config_raw(const std::string& raw) {
    return AppendBytes(104, raw.data(), raw.size());
  }


  using FieldMetadata_HeapprofdConfig =
    ::protozero::proto_utils::FieldMetadata<
      105,
      ::protozero::proto_utils::RepetitionType::kNotRepeated,
      ::protozero::proto_utils::ProtoSchemaType::kMessage,
      HeapprofdConfig,
      DataSourceConfig>;

  // Ceci n'est pas une pipe.
  // This is actually a variable of FieldMetadataHelper<FieldMetadata<...>>
  // type (and users are expected to use it as such, hence kCamelCase name).
  // It is declared as a function to keep protozero bindings header-only as
  // inline constexpr variables are not available until C++17 (while inline
  // functions are).
  // TODO(altimin): Use inline variable instead after adopting C++17.
  static constexpr FieldMetadata_HeapprofdConfig kHeapprofdConfig() { return {}; }
  template <typename T = HeapprofdConfig> T* set_heapprofd_config() {
    return BeginNestedMessage<T>(105);
  }

  void set_heapprofd_config_raw(const std::string& raw) {
    return AppendBytes(105, raw.data(), raw.size());
  }


  using FieldMetadata_JavaHprofConfig =
    ::protozero::proto_utils::FieldMetadata<
      110,
      ::protozero::proto_utils::RepetitionType::kNotRepeated,
      ::protozero::proto_utils::ProtoSchemaType::kMessage,
      JavaHprofConfig,
      DataSourceConfig>;

  // Ceci n'est pas une pipe.
  // This is actually a variable of FieldMetadataHelper<FieldMetadata<...>>
  // type (and users are expected to use it as such, hence kCamelCase name).
  // It is declared as a function to keep protozero bindings header-only as
  // inline constexpr variables are not available until C++17 (while inline
  // functions are).
  // TODO(altimin): Use inline variable instead after adopting C++17.
  static constexpr FieldMetadata_JavaHprofConfig kJavaHprofConfig() { return {}; }
  template <typename T = JavaHprofConfig> T* set_java_hprof_config() {
    return BeginNestedMessage<T>(110);
  }

  void set_java_hprof_config_raw(const std::string& raw) {
    return AppendBytes(110, raw.data(), raw.size());
  }


  using FieldMetadata_AndroidPowerConfig =
    ::protozero::proto_utils::FieldMetadata<
      106,
      ::protozero::proto_utils::RepetitionType::kNotRepeated,
      ::protozero::proto_utils::ProtoSchemaType::kMessage,
      AndroidPowerConfig,
      DataSourceConfig>;

  // Ceci n'est pas une pipe.
  // This is actually a variable of FieldMetadataHelper<FieldMetadata<...>>
  // type (and users are expected to use it as such, hence kCamelCase name).
  // It is declared as a function to keep protozero bindings header-only as
  // inline constexpr variables are not available until C++17 (while inline
  // functions are).
  // TODO(altimin): Use inline variable instead after adopting C++17.
  static constexpr FieldMetadata_AndroidPowerConfig kAndroidPowerConfig() { return {}; }
  template <typename T = AndroidPowerConfig> T* set_android_power_config() {
    return BeginNestedMessage<T>(106);
  }

  void set_android_power_config_raw(const std::string& raw) {
    return AppendBytes(106, raw.data(), raw.size());
  }


  using FieldMetadata_AndroidLogConfig =
    ::protozero::proto_utils::FieldMetadata<
      107,
      ::protozero::proto_utils::RepetitionType::kNotRepeated,
      ::protozero::proto_utils::ProtoSchemaType::kMessage,
      AndroidLogConfig,
      DataSourceConfig>;

  // Ceci n'est pas une pipe.
  // This is actually a variable of FieldMetadataHelper<FieldMetadata<...>>
  // type (and users are expected to use it as such, hence kCamelCase name).
  // It is declared as a function to keep protozero bindings header-only as
  // inline constexpr variables are not available until C++17 (while inline
  // functions are).
  // TODO(altimin): Use inline variable instead after adopting C++17.
  static constexpr FieldMetadata_AndroidLogConfig kAndroidLogConfig() { return {}; }
  template <typename T = AndroidLogConfig> T* set_android_log_config() {
    return BeginNestedMessage<T>(107);
  }

  void set_android_log_config_raw(const std::string& raw) {
    return AppendBytes(107, raw.data(), raw.size());
  }


  using FieldMetadata_GpuCounterConfig =
    ::protozero::proto_utils::FieldMetadata<
      108,
      ::protozero::proto_utils::RepetitionType::kNotRepeated,
      ::protozero::proto_utils::ProtoSchemaType::kMessage,
      GpuCounterConfig,
      DataSourceConfig>;

  // Ceci n'est pas une pipe.
  // This is actually a variable of FieldMetadataHelper<FieldMetadata<...>>
  // type (and users are expected to use it as such, hence kCamelCase name).
  // It is declared as a function to keep protozero bindings header-only as
  // inline constexpr variables are not available until C++17 (while inline
  // functions are).
  // TODO(altimin): Use inline variable instead after adopting C++17.
  static constexpr FieldMetadata_GpuCounterConfig kGpuCounterConfig() { return {}; }
  template <typename T = GpuCounterConfig> T* set_gpu_counter_config() {
    return BeginNestedMessage<T>(108);
  }

  void set_gpu_counter_config_raw(const std::string& raw) {
    return AppendBytes(108, raw.data(), raw.size());
  }


  using FieldMetadata_PackagesListConfig =
    ::protozero::proto_utils::FieldMetadata<
      109,
      ::protozero::proto_utils::RepetitionType::kNotRepeated,
      ::protozero::proto_utils::ProtoSchemaType::kMessage,
      PackagesListConfig,
      DataSourceConfig>;

  // Ceci n'est pas une pipe.
  // This is actually a variable of FieldMetadataHelper<FieldMetadata<...>>
  // type (and users are expected to use it as such, hence kCamelCase name).
  // It is declared as a function to keep protozero bindings header-only as
  // inline constexpr variables are not available until C++17 (while inline
  // functions are).
  // TODO(altimin): Use inline variable instead after adopting C++17.
  static constexpr FieldMetadata_PackagesListConfig kPackagesListConfig() { return {}; }
  template <typename T = PackagesListConfig> T* set_packages_list_config() {
    return BeginNestedMessage<T>(109);
  }

  void set_packages_list_config_raw(const std::string& raw) {
    return AppendBytes(109, raw.data(), raw.size());
  }


  using FieldMetadata_PerfEventConfig =
    ::protozero::proto_utils::FieldMetadata<
      111,
      ::protozero::proto_utils::RepetitionType::kNotRepeated,
      ::protozero::proto_utils::ProtoSchemaType::kMessage,
      PerfEventConfig,
      DataSourceConfig>;

  // Ceci n'est pas une pipe.
  // This is actually a variable of FieldMetadataHelper<FieldMetadata<...>>
  // type (and users are expected to use it as such, hence kCamelCase name).
  // It is declared as a function to keep protozero bindings header-only as
  // inline constexpr variables are not available until C++17 (while inline
  // functions are).
  // TODO(altimin): Use inline variable instead after adopting C++17.
  static constexpr FieldMetadata_PerfEventConfig kPerfEventConfig() { return {}; }
  template <typename T = PerfEventConfig> T* set_perf_event_config() {
    return BeginNestedMessage<T>(111);
  }

  void set_perf_event_config_raw(const std::string& raw) {
    return AppendBytes(111, raw.data(), raw.size());
  }


  using FieldMetadata_VulkanMemoryConfig =
    ::protozero::proto_utils::FieldMetadata<
      112,
      ::protozero::proto_utils::RepetitionType::kNotRepeated,
      ::protozero::proto_utils::ProtoSchemaType::kMessage,
      VulkanMemoryConfig,
      DataSourceConfig>;

  // Ceci n'est pas une pipe.
  // This is actually a variable of FieldMetadataHelper<FieldMetadata<...>>
  // type (and users are expected to use it as such, hence kCamelCase name).
  // It is declared as a function to keep protozero bindings header-only as
  // inline constexpr variables are not available until C++17 (while inline
  // functions are).
  // TODO(altimin): Use inline variable instead after adopting C++17.
  static constexpr FieldMetadata_VulkanMemoryConfig kVulkanMemoryConfig() { return {}; }
  template <typename T = VulkanMemoryConfig> T* set_vulkan_memory_config() {
    return BeginNestedMessage<T>(112);
  }

  void set_vulkan_memory_config_raw(const std::string& raw) {
    return AppendBytes(112, raw.data(), raw.size());
  }


  using FieldMetadata_TrackEventConfig =
    ::protozero::proto_utils::FieldMetadata<
      113,
      ::protozero::proto_utils::RepetitionType::kNotRepeated,
      ::protozero::proto_utils::ProtoSchemaType::kMessage,
      TrackEventConfig,
      DataSourceConfig>;

  // Ceci n'est pas une pipe.
  // This is actually a variable of FieldMetadataHelper<FieldMetadata<...>>
  // type (and users are expected to use it as such, hence kCamelCase name).
  // It is declared as a function to keep protozero bindings header-only as
  // inline constexpr variables are not available until C++17 (while inline
  // functions are).
  // TODO(altimin): Use inline variable instead after adopting C++17.
  static constexpr FieldMetadata_TrackEventConfig kTrackEventConfig() { return {}; }
  template <typename T = TrackEventConfig> T* set_track_event_config() {
    return BeginNestedMessage<T>(113);
  }

  void set_track_event_config_raw(const std::string& raw) {
    return AppendBytes(113, raw.data(), raw.size());
  }


  using FieldMetadata_AndroidPolledStateConfig =
    ::protozero::proto_utils::FieldMetadata<
      114,
      ::protozero::proto_utils::RepetitionType::kNotRepeated,
      ::protozero::proto_utils::ProtoSchemaType::kMessage,
      AndroidPolledStateConfig,
      DataSourceConfig>;

  // Ceci n'est pas une pipe.
  // This is actually a variable of FieldMetadataHelper<FieldMetadata<...>>
  // type (and users are expected to use it as such, hence kCamelCase name).
  // It is declared as a function to keep protozero bindings header-only as
  // inline constexpr variables are not available until C++17 (while inline
  // functions are).
  // TODO(altimin): Use inline variable instead after adopting C++17.
  static constexpr FieldMetadata_AndroidPolledStateConfig kAndroidPolledStateConfig() { return {}; }
  template <typename T = AndroidPolledStateConfig> T* set_android_polled_state_config() {
    return BeginNestedMessage<T>(114);
  }

  void set_android_polled_state_config_raw(const std::string& raw) {
    return AppendBytes(114, raw.data(), raw.size());
  }


  using FieldMetadata_ChromeConfig =
    ::protozero::proto_utils::FieldMetadata<
      101,
      ::protozero::proto_utils::RepetitionType::kNotRepeated,
      ::protozero::proto_utils::ProtoSchemaType::kMessage,
      ChromeConfig,
      DataSourceConfig>;

  // Ceci n'est pas une pipe.
  // This is actually a variable of FieldMetadataHelper<FieldMetadata<...>>
  // type (and users are expected to use it as such, hence kCamelCase name).
  // It is declared as a function to keep protozero bindings header-only as
  // inline constexpr variables are not available until C++17 (while inline
  // functions are).
  // TODO(altimin): Use inline variable instead after adopting C++17.
  static constexpr FieldMetadata_ChromeConfig kChromeConfig() { return {}; }
  template <typename T = ChromeConfig> T* set_chrome_config() {
    return BeginNestedMessage<T>(101);
  }


  using FieldMetadata_InterceptorConfig =
    ::protozero::proto_utils::FieldMetadata<
      115,
      ::protozero::proto_utils::RepetitionType::kNotRepeated,
      ::protozero::proto_utils::ProtoSchemaType::kMessage,
      InterceptorConfig,
      DataSourceConfig>;

  // Ceci n'est pas une pipe.
  // This is actually a variable of FieldMetadataHelper<FieldMetadata<...>>
  // type (and users are expected to use it as such, hence kCamelCase name).
  // It is declared as a function to keep protozero bindings header-only as
  // inline constexpr variables are not available until C++17 (while inline
  // functions are).
  // TODO(altimin): Use inline variable instead after adopting C++17.
  static constexpr FieldMetadata_InterceptorConfig kInterceptorConfig() { return {}; }
  template <typename T = InterceptorConfig> T* set_interceptor_config() {
    return BeginNestedMessage<T>(115);
  }


  using FieldMetadata_LegacyConfig =
    ::protozero::proto_utils::FieldMetadata<
      1000,
      ::protozero::proto_utils::RepetitionType::kNotRepeated,
      ::protozero::proto_utils::ProtoSchemaType::kString,
      std::string,
      DataSourceConfig>;

  // Ceci n'est pas une pipe.
  // This is actually a variable of FieldMetadataHelper<FieldMetadata<...>>
  // type (and users are expected to use it as such, hence kCamelCase name).
  // It is declared as a function to keep protozero bindings header-only as
  // inline constexpr variables are not available until C++17 (while inline
  // functions are).
  // TODO(altimin): Use inline variable instead after adopting C++17.
  static constexpr FieldMetadata_LegacyConfig kLegacyConfig() { return {}; }
  void set_legacy_config(const char* data, size_t size) {
    AppendBytes(FieldMetadata_LegacyConfig::kFieldId, data, size);
  }
  void set_legacy_config(std::string value) {
    static constexpr uint32_t field_id = FieldMetadata_LegacyConfig::kFieldId;
    // Call the appropriate protozero::Message::Append(field_id, ...)
    // method based on the type of the field.
    ::protozero::internal::FieldWriter<
      ::protozero::proto_utils::ProtoSchemaType::kString>
        ::Append(*this, field_id, value);
  }

  using FieldMetadata_ForTesting =
    ::protozero::proto_utils::FieldMetadata<
      1001,
      ::protozero::proto_utils::RepetitionType::kNotRepeated,
      ::protozero::proto_utils::ProtoSchemaType::kMessage,
      TestConfig,
      DataSourceConfig>;

  // Ceci n'est pas une pipe.
  // This is actually a variable of FieldMetadataHelper<FieldMetadata<...>>
  // type (and users are expected to use it as such, hence kCamelCase name).
  // It is declared as a function to keep protozero bindings header-only as
  // inline constexpr variables are not available until C++17 (while inline
  // functions are).
  // TODO(altimin): Use inline variable instead after adopting C++17.
  static constexpr FieldMetadata_ForTesting kForTesting() { return {}; }
  template <typename T = TestConfig> T* set_for_testing() {
    return BeginNestedMessage<T>(1001);
  }

};

} // Namespace.
} // Namespace.
} // Namespace.
#endif  // Include guard.
