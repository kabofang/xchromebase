#include "perfetto/protozero/message.h"
#include "perfetto/protozero/packed_repeated_fields.h"
#include "perfetto/protozero/proto_decoder.h"
#include "perfetto/protozero/scattered_heap_buffer.h"
// DO NOT EDIT. Autogenerated by Perfetto cppgen_plugin
#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wfloat-equal"
#endif
#include "protos/perfetto/config/track_event/track_event_config.gen.h"

namespace perfetto {
namespace protos {
namespace gen {

TrackEventConfig::TrackEventConfig() = default;
TrackEventConfig::~TrackEventConfig() = default;
TrackEventConfig::TrackEventConfig(const TrackEventConfig&) = default;
TrackEventConfig& TrackEventConfig::operator=(const TrackEventConfig&) = default;
TrackEventConfig::TrackEventConfig(TrackEventConfig&&) noexcept = default;
TrackEventConfig& TrackEventConfig::operator=(TrackEventConfig&&) = default;

bool TrackEventConfig::operator==(const TrackEventConfig& other) const {
  return unknown_fields_ == other.unknown_fields_
   && disabled_categories_ == other.disabled_categories_
   && enabled_categories_ == other.enabled_categories_
   && disabled_tags_ == other.disabled_tags_
   && enabled_tags_ == other.enabled_tags_
   && disable_incremental_timestamps_ == other.disable_incremental_timestamps_
   && timestamp_unit_multiplier_ == other.timestamp_unit_multiplier_
   && filter_debug_annotations_ == other.filter_debug_annotations_
   && enable_thread_time_sampling_ == other.enable_thread_time_sampling_;
}

bool TrackEventConfig::ParseFromArray(const void* raw, size_t size) {
  disabled_categories_.clear();
  enabled_categories_.clear();
  disabled_tags_.clear();
  enabled_tags_.clear();
  unknown_fields_.clear();
  bool packed_error = false;

  ::protozero::ProtoDecoder dec(raw, size);
  for (auto field = dec.ReadField(); field.valid(); field = dec.ReadField()) {
    if (field.id() < _has_field_.size()) {
      _has_field_.set(field.id());
    }
    switch (field.id()) {
      case 1 /* disabled_categories */:
        disabled_categories_.emplace_back();
        field.get(&disabled_categories_.back());
        break;
      case 2 /* enabled_categories */:
        enabled_categories_.emplace_back();
        field.get(&enabled_categories_.back());
        break;
      case 3 /* disabled_tags */:
        disabled_tags_.emplace_back();
        field.get(&disabled_tags_.back());
        break;
      case 4 /* enabled_tags */:
        enabled_tags_.emplace_back();
        field.get(&enabled_tags_.back());
        break;
      case 5 /* disable_incremental_timestamps */:
        field.get(&disable_incremental_timestamps_);
        break;
      case 6 /* timestamp_unit_multiplier */:
        field.get(&timestamp_unit_multiplier_);
        break;
      case 7 /* filter_debug_annotations */:
        field.get(&filter_debug_annotations_);
        break;
      case 8 /* enable_thread_time_sampling */:
        field.get(&enable_thread_time_sampling_);
        break;
      default:
        field.SerializeAndAppendTo(&unknown_fields_);
        break;
    }
  }
  return !packed_error && !dec.bytes_left();
}

std::string TrackEventConfig::SerializeAsString() const {
  ::protozero::HeapBuffered<::protozero::Message> msg;
  Serialize(msg.get());
  return msg.SerializeAsString();
}

std::vector<uint8_t> TrackEventConfig::SerializeAsArray() const {
  ::protozero::HeapBuffered<::protozero::Message> msg;
  Serialize(msg.get());
  return msg.SerializeAsArray();
}

void TrackEventConfig::Serialize(::protozero::Message* msg) const {
  // Field 1: disabled_categories
  for (auto& it : disabled_categories_) {
    msg->AppendString(1, it);
  }

  // Field 2: enabled_categories
  for (auto& it : enabled_categories_) {
    msg->AppendString(2, it);
  }

  // Field 3: disabled_tags
  for (auto& it : disabled_tags_) {
    msg->AppendString(3, it);
  }

  // Field 4: enabled_tags
  for (auto& it : enabled_tags_) {
    msg->AppendString(4, it);
  }

  // Field 5: disable_incremental_timestamps
  if (_has_field_[5]) {
    msg->AppendTinyVarInt(5, disable_incremental_timestamps_);
  }

  // Field 6: timestamp_unit_multiplier
  if (_has_field_[6]) {
    msg->AppendVarInt(6, timestamp_unit_multiplier_);
  }

  // Field 7: filter_debug_annotations
  if (_has_field_[7]) {
    msg->AppendTinyVarInt(7, filter_debug_annotations_);
  }

  // Field 8: enable_thread_time_sampling
  if (_has_field_[8]) {
    msg->AppendTinyVarInt(8, enable_thread_time_sampling_);
  }

  msg->AppendRawProtoBytes(unknown_fields_.data(), unknown_fields_.size());
}

}  // namespace perfetto
}  // namespace protos
}  // namespace gen
#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic pop
#endif
