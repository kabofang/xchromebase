#include "perfetto/protozero/message.h"
#include "perfetto/protozero/packed_repeated_fields.h"
#include "perfetto/protozero/proto_decoder.h"
#include "perfetto/protozero/scattered_heap_buffer.h"
// DO NOT EDIT. Autogenerated by Perfetto cppgen_plugin
#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wfloat-equal"
#endif
#include "protos/perfetto/config/process_stats/process_stats_config.gen.h"

namespace perfetto {
namespace protos {
namespace gen {

ProcessStatsConfig::ProcessStatsConfig() = default;
ProcessStatsConfig::~ProcessStatsConfig() = default;
ProcessStatsConfig::ProcessStatsConfig(const ProcessStatsConfig&) = default;
ProcessStatsConfig& ProcessStatsConfig::operator=(const ProcessStatsConfig&) = default;
ProcessStatsConfig::ProcessStatsConfig(ProcessStatsConfig&&) noexcept = default;
ProcessStatsConfig& ProcessStatsConfig::operator=(ProcessStatsConfig&&) = default;

bool ProcessStatsConfig::operator==(const ProcessStatsConfig& other) const {
  return unknown_fields_ == other.unknown_fields_
   && quirks_ == other.quirks_
   && scan_all_processes_on_start_ == other.scan_all_processes_on_start_
   && record_thread_names_ == other.record_thread_names_
   && proc_stats_poll_ms_ == other.proc_stats_poll_ms_
   && proc_stats_cache_ttl_ms_ == other.proc_stats_cache_ttl_ms_;
}

bool ProcessStatsConfig::ParseFromArray(const void* raw, size_t size) {
  quirks_.clear();
  unknown_fields_.clear();
  bool packed_error = false;

  ::protozero::ProtoDecoder dec(raw, size);
  for (auto field = dec.ReadField(); field.valid(); field = dec.ReadField()) {
    if (field.id() < _has_field_.size()) {
      _has_field_.set(field.id());
    }
    switch (field.id()) {
      case 1 /* quirks */:
        quirks_.emplace_back();
        field.get(&quirks_.back());
        break;
      case 2 /* scan_all_processes_on_start */:
        field.get(&scan_all_processes_on_start_);
        break;
      case 3 /* record_thread_names */:
        field.get(&record_thread_names_);
        break;
      case 4 /* proc_stats_poll_ms */:
        field.get(&proc_stats_poll_ms_);
        break;
      case 6 /* proc_stats_cache_ttl_ms */:
        field.get(&proc_stats_cache_ttl_ms_);
        break;
      default:
        field.SerializeAndAppendTo(&unknown_fields_);
        break;
    }
  }
  return !packed_error && !dec.bytes_left();
}

std::string ProcessStatsConfig::SerializeAsString() const {
  ::protozero::HeapBuffered<::protozero::Message> msg;
  Serialize(msg.get());
  return msg.SerializeAsString();
}

std::vector<uint8_t> ProcessStatsConfig::SerializeAsArray() const {
  ::protozero::HeapBuffered<::protozero::Message> msg;
  Serialize(msg.get());
  return msg.SerializeAsArray();
}

void ProcessStatsConfig::Serialize(::protozero::Message* msg) const {
  // Field 1: quirks
  for (auto& it : quirks_) {
    msg->AppendVarInt(1, it);
  }

  // Field 2: scan_all_processes_on_start
  if (_has_field_[2]) {
    msg->AppendTinyVarInt(2, scan_all_processes_on_start_);
  }

  // Field 3: record_thread_names
  if (_has_field_[3]) {
    msg->AppendTinyVarInt(3, record_thread_names_);
  }

  // Field 4: proc_stats_poll_ms
  if (_has_field_[4]) {
    msg->AppendVarInt(4, proc_stats_poll_ms_);
  }

  // Field 6: proc_stats_cache_ttl_ms
  if (_has_field_[6]) {
    msg->AppendVarInt(6, proc_stats_cache_ttl_ms_);
  }

  msg->AppendRawProtoBytes(unknown_fields_.data(), unknown_fields_.size());
}

}  // namespace perfetto
}  // namespace protos
}  // namespace gen
#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic pop
#endif
