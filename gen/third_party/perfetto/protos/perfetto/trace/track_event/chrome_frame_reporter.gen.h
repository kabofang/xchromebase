// DO NOT EDIT. Autogenerated by Perfetto cppgen_plugin
#ifndef PERFETTO_PROTOS_PROTOS_PERFETTO_TRACE_TRACK_EVENT_CHROME_FRAME_REPORTER_PROTO_CPP_H_
#define PERFETTO_PROTOS_PROTOS_PERFETTO_TRACE_TRACK_EVENT_CHROME_FRAME_REPORTER_PROTO_CPP_H_

#include <stdint.h>
#include <bitset>
#include <vector>
#include <string>
#include <type_traits>

#include "perfetto/protozero/cpp_message_obj.h"
#include "perfetto/protozero/copyable_ptr.h"
#include "perfetto/base/export.h"

namespace perfetto {
namespace protos {
namespace gen {
class ChromeFrameReporter;
enum ChromeFrameReporter_State : int;
enum ChromeFrameReporter_FrameDropReason : int;
enum ChromeFrameReporter_ScrollState : int;
}  // namespace perfetto
}  // namespace protos
}  // namespace gen

namespace protozero {
class Message;
}  // namespace protozero

namespace perfetto {
namespace protos {
namespace gen {
enum ChromeFrameReporter_State : int {
  ChromeFrameReporter_State_STATE_NO_UPDATE_DESIRED = 0,
  ChromeFrameReporter_State_STATE_PRESENTED_ALL = 1,
  ChromeFrameReporter_State_STATE_PRESENTED_PARTIAL = 2,
  ChromeFrameReporter_State_STATE_DROPPED = 3,
};
enum ChromeFrameReporter_FrameDropReason : int {
  ChromeFrameReporter_FrameDropReason_REASON_UNSPECIFIED = 0,
  ChromeFrameReporter_FrameDropReason_REASON_DISPLAY_COMPOSITOR = 1,
  ChromeFrameReporter_FrameDropReason_REASON_MAIN_THREAD = 2,
  ChromeFrameReporter_FrameDropReason_REASON_CLIENT_COMPOSITOR = 3,
};
enum ChromeFrameReporter_ScrollState : int {
  ChromeFrameReporter_ScrollState_SCROLL_NONE = 0,
  ChromeFrameReporter_ScrollState_SCROLL_MAIN_THREAD = 1,
  ChromeFrameReporter_ScrollState_SCROLL_COMPOSITOR_THREAD = 2,
  ChromeFrameReporter_ScrollState_SCROLL_UNKNOWN = 3,
};

class PERFETTO_EXPORT_COMPONENT ChromeFrameReporter : public ::protozero::CppMessageObj {
 public:
  using State = ChromeFrameReporter_State;
  static constexpr auto STATE_NO_UPDATE_DESIRED = ChromeFrameReporter_State_STATE_NO_UPDATE_DESIRED;
  static constexpr auto STATE_PRESENTED_ALL = ChromeFrameReporter_State_STATE_PRESENTED_ALL;
  static constexpr auto STATE_PRESENTED_PARTIAL = ChromeFrameReporter_State_STATE_PRESENTED_PARTIAL;
  static constexpr auto STATE_DROPPED = ChromeFrameReporter_State_STATE_DROPPED;
  static constexpr auto State_MIN = ChromeFrameReporter_State_STATE_NO_UPDATE_DESIRED;
  static constexpr auto State_MAX = ChromeFrameReporter_State_STATE_DROPPED;
  using FrameDropReason = ChromeFrameReporter_FrameDropReason;
  static constexpr auto REASON_UNSPECIFIED = ChromeFrameReporter_FrameDropReason_REASON_UNSPECIFIED;
  static constexpr auto REASON_DISPLAY_COMPOSITOR = ChromeFrameReporter_FrameDropReason_REASON_DISPLAY_COMPOSITOR;
  static constexpr auto REASON_MAIN_THREAD = ChromeFrameReporter_FrameDropReason_REASON_MAIN_THREAD;
  static constexpr auto REASON_CLIENT_COMPOSITOR = ChromeFrameReporter_FrameDropReason_REASON_CLIENT_COMPOSITOR;
  static constexpr auto FrameDropReason_MIN = ChromeFrameReporter_FrameDropReason_REASON_UNSPECIFIED;
  static constexpr auto FrameDropReason_MAX = ChromeFrameReporter_FrameDropReason_REASON_CLIENT_COMPOSITOR;
  using ScrollState = ChromeFrameReporter_ScrollState;
  static constexpr auto SCROLL_NONE = ChromeFrameReporter_ScrollState_SCROLL_NONE;
  static constexpr auto SCROLL_MAIN_THREAD = ChromeFrameReporter_ScrollState_SCROLL_MAIN_THREAD;
  static constexpr auto SCROLL_COMPOSITOR_THREAD = ChromeFrameReporter_ScrollState_SCROLL_COMPOSITOR_THREAD;
  static constexpr auto SCROLL_UNKNOWN = ChromeFrameReporter_ScrollState_SCROLL_UNKNOWN;
  static constexpr auto ScrollState_MIN = ChromeFrameReporter_ScrollState_SCROLL_NONE;
  static constexpr auto ScrollState_MAX = ChromeFrameReporter_ScrollState_SCROLL_UNKNOWN;
  enum FieldNumbers {
    kStateFieldNumber = 1,
    kReasonFieldNumber = 2,
    kFrameSourceFieldNumber = 3,
    kFrameSequenceFieldNumber = 4,
    kAffectsSmoothnessFieldNumber = 5,
    kScrollStateFieldNumber = 6,
    kHasMainAnimationFieldNumber = 7,
    kHasCompositorAnimationFieldNumber = 8,
    kHasSmoothInputMainFieldNumber = 9,
    kHasMissingContentFieldNumber = 10,
    kLayerTreeHostIdFieldNumber = 11,
  };

  ChromeFrameReporter();
  ~ChromeFrameReporter() override;
  ChromeFrameReporter(ChromeFrameReporter&&) noexcept;
  ChromeFrameReporter& operator=(ChromeFrameReporter&&);
  ChromeFrameReporter(const ChromeFrameReporter&);
  ChromeFrameReporter& operator=(const ChromeFrameReporter&);
  bool operator==(const ChromeFrameReporter&) const;
  bool operator!=(const ChromeFrameReporter& other) const { return !(*this == other); }

  bool ParseFromArray(const void*, size_t) override;
  std::string SerializeAsString() const override;
  std::vector<uint8_t> SerializeAsArray() const override;
  void Serialize(::protozero::Message*) const;

  bool has_state() const { return _has_field_[1]; }
  ChromeFrameReporter_State state() const { return state_; }
  void set_state(ChromeFrameReporter_State value) { state_ = value; _has_field_.set(1); }

  bool has_reason() const { return _has_field_[2]; }
  ChromeFrameReporter_FrameDropReason reason() const { return reason_; }
  void set_reason(ChromeFrameReporter_FrameDropReason value) { reason_ = value; _has_field_.set(2); }

  bool has_frame_source() const { return _has_field_[3]; }
  uint64_t frame_source() const { return frame_source_; }
  void set_frame_source(uint64_t value) { frame_source_ = value; _has_field_.set(3); }

  bool has_frame_sequence() const { return _has_field_[4]; }
  uint64_t frame_sequence() const { return frame_sequence_; }
  void set_frame_sequence(uint64_t value) { frame_sequence_ = value; _has_field_.set(4); }

  bool has_affects_smoothness() const { return _has_field_[5]; }
  bool affects_smoothness() const { return affects_smoothness_; }
  void set_affects_smoothness(bool value) { affects_smoothness_ = value; _has_field_.set(5); }

  bool has_scroll_state() const { return _has_field_[6]; }
  ChromeFrameReporter_ScrollState scroll_state() const { return scroll_state_; }
  void set_scroll_state(ChromeFrameReporter_ScrollState value) { scroll_state_ = value; _has_field_.set(6); }

  bool has_has_main_animation() const { return _has_field_[7]; }
  bool has_main_animation() const { return has_main_animation_; }
  void set_has_main_animation(bool value) { has_main_animation_ = value; _has_field_.set(7); }

  bool has_has_compositor_animation() const { return _has_field_[8]; }
  bool has_compositor_animation() const { return has_compositor_animation_; }
  void set_has_compositor_animation(bool value) { has_compositor_animation_ = value; _has_field_.set(8); }

  bool has_has_smooth_input_main() const { return _has_field_[9]; }
  bool has_smooth_input_main() const { return has_smooth_input_main_; }
  void set_has_smooth_input_main(bool value) { has_smooth_input_main_ = value; _has_field_.set(9); }

  bool has_has_missing_content() const { return _has_field_[10]; }
  bool has_missing_content() const { return has_missing_content_; }
  void set_has_missing_content(bool value) { has_missing_content_ = value; _has_field_.set(10); }

  bool has_layer_tree_host_id() const { return _has_field_[11]; }
  uint64_t layer_tree_host_id() const { return layer_tree_host_id_; }
  void set_layer_tree_host_id(uint64_t value) { layer_tree_host_id_ = value; _has_field_.set(11); }

 private:
  ChromeFrameReporter_State state_{};
  ChromeFrameReporter_FrameDropReason reason_{};
  uint64_t frame_source_{};
  uint64_t frame_sequence_{};
  bool affects_smoothness_{};
  ChromeFrameReporter_ScrollState scroll_state_{};
  bool has_main_animation_{};
  bool has_compositor_animation_{};
  bool has_smooth_input_main_{};
  bool has_missing_content_{};
  uint64_t layer_tree_host_id_{};

  // Allows to preserve unknown protobuf fields for compatibility
  // with future versions of .proto files.
  std::string unknown_fields_;

  std::bitset<12> _has_field_{};
};

}  // namespace perfetto
}  // namespace protos
}  // namespace gen

#endif  // PERFETTO_PROTOS_PROTOS_PERFETTO_TRACE_TRACK_EVENT_CHROME_FRAME_REPORTER_PROTO_CPP_H_
