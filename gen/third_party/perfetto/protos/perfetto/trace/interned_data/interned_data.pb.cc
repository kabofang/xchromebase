// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: protos/perfetto/trace/interned_data/interned_data.proto

#include "protos/perfetto/trace/interned_data/interned_data.pb.h"

#include <algorithm>

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/wire_format_lite.h>
#include <google/protobuf/io/zero_copy_stream_impl_lite.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
extern PROTOBUF_INTERNAL_EXPORT_protos_2fperfetto_2ftrace_2fprofiling_2fprofile_5fcommon_2eproto ::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<0> scc_info_Callstack_protos_2fperfetto_2ftrace_2fprofiling_2fprofile_5fcommon_2eproto;
extern PROTOBUF_INTERNAL_EXPORT_protos_2fperfetto_2ftrace_2ftrack_5fevent_2fdebug_5fannotation_2eproto ::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<0> scc_info_DebugAnnotationName_protos_2fperfetto_2ftrace_2ftrack_5fevent_2fdebug_5fannotation_2eproto;
extern PROTOBUF_INTERNAL_EXPORT_protos_2fperfetto_2ftrace_2ftrack_5fevent_2fdebug_5fannotation_2eproto ::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<0> scc_info_DebugAnnotationValueTypeName_protos_2fperfetto_2ftrace_2ftrack_5fevent_2fdebug_5fannotation_2eproto;
extern PROTOBUF_INTERNAL_EXPORT_protos_2fperfetto_2ftrace_2ftrack_5fevent_2ftrack_5fevent_2eproto ::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<0> scc_info_EventCategory_protos_2fperfetto_2ftrace_2ftrack_5fevent_2ftrack_5fevent_2eproto;
extern PROTOBUF_INTERNAL_EXPORT_protos_2fperfetto_2ftrace_2ftrack_5fevent_2ftrack_5fevent_2eproto ::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<0> scc_info_EventName_protos_2fperfetto_2ftrace_2ftrack_5fevent_2ftrack_5fevent_2eproto;
extern PROTOBUF_INTERNAL_EXPORT_protos_2fperfetto_2ftrace_2fprofiling_2fprofile_5fcommon_2eproto ::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<0> scc_info_Frame_protos_2fperfetto_2ftrace_2fprofiling_2fprofile_5fcommon_2eproto;
extern PROTOBUF_INTERNAL_EXPORT_protos_2fperfetto_2ftrace_2ftrack_5fevent_2fchrome_5fhistogram_5fsample_2eproto ::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<0> scc_info_HistogramName_protos_2fperfetto_2ftrace_2ftrack_5fevent_2fchrome_5fhistogram_5fsample_2eproto;
extern PROTOBUF_INTERNAL_EXPORT_protos_2fperfetto_2ftrace_2fgpu_2fgpu_5frender_5fstage_5fevent_2eproto ::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<0> scc_info_InternedGpuRenderStageSpecification_protos_2fperfetto_2ftrace_2fgpu_2fgpu_5frender_5fstage_5fevent_2eproto;
extern PROTOBUF_INTERNAL_EXPORT_protos_2fperfetto_2ftrace_2fgpu_2fgpu_5frender_5fstage_5fevent_2eproto ::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<0> scc_info_InternedGraphicsContext_protos_2fperfetto_2ftrace_2fgpu_2fgpu_5frender_5fstage_5fevent_2eproto;
extern PROTOBUF_INTERNAL_EXPORT_protos_2fperfetto_2ftrace_2fprofiling_2fprofile_5fcommon_2eproto ::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<0> scc_info_InternedString_protos_2fperfetto_2ftrace_2fprofiling_2fprofile_5fcommon_2eproto;
extern PROTOBUF_INTERNAL_EXPORT_protos_2fperfetto_2ftrace_2ftrack_5fevent_2flog_5fmessage_2eproto ::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<0> scc_info_LogMessageBody_protos_2fperfetto_2ftrace_2ftrack_5fevent_2flog_5fmessage_2eproto;
extern PROTOBUF_INTERNAL_EXPORT_protos_2fperfetto_2ftrace_2fprofiling_2fprofile_5fcommon_2eproto ::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<0> scc_info_Mapping_protos_2fperfetto_2ftrace_2fprofiling_2fprofile_5fcommon_2eproto;
extern PROTOBUF_INTERNAL_EXPORT_protos_2fperfetto_2ftrace_2fprofiling_2fprofile_5fcommon_2eproto ::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<0> scc_info_ProfiledFrameSymbols_protos_2fperfetto_2ftrace_2fprofiling_2fprofile_5fcommon_2eproto;
extern PROTOBUF_INTERNAL_EXPORT_protos_2fperfetto_2ftrace_2ftrack_5fevent_2fsource_5flocation_2eproto ::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<0> scc_info_SourceLocation_protos_2fperfetto_2ftrace_2ftrack_5fevent_2fsource_5flocation_2eproto;
namespace perfetto {
namespace protos {
class InternedDataDefaultTypeInternal {
 public:
  ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<InternedData> _instance;
} _InternedData_default_instance_;
}  // namespace protos
}  // namespace perfetto
static void InitDefaultsscc_info_InternedData_protos_2fperfetto_2ftrace_2finterned_5fdata_2finterned_5fdata_2eproto() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::perfetto::protos::_InternedData_default_instance_;
    new (ptr) ::perfetto::protos::InternedData();
    ::PROTOBUF_NAMESPACE_ID::internal::OnShutdownDestroyMessage(ptr);
  }
}

::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<14> scc_info_InternedData_protos_2fperfetto_2ftrace_2finterned_5fdata_2finterned_5fdata_2eproto =
    {{ATOMIC_VAR_INIT(::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase::kUninitialized), 14, 0, InitDefaultsscc_info_InternedData_protos_2fperfetto_2ftrace_2finterned_5fdata_2finterned_5fdata_2eproto}, {
      &scc_info_EventCategory_protos_2fperfetto_2ftrace_2ftrack_5fevent_2ftrack_5fevent_2eproto.base,
      &scc_info_EventName_protos_2fperfetto_2ftrace_2ftrack_5fevent_2ftrack_5fevent_2eproto.base,
      &scc_info_DebugAnnotationName_protos_2fperfetto_2ftrace_2ftrack_5fevent_2fdebug_5fannotation_2eproto.base,
      &scc_info_DebugAnnotationValueTypeName_protos_2fperfetto_2ftrace_2ftrack_5fevent_2fdebug_5fannotation_2eproto.base,
      &scc_info_SourceLocation_protos_2fperfetto_2ftrace_2ftrack_5fevent_2fsource_5flocation_2eproto.base,
      &scc_info_LogMessageBody_protos_2fperfetto_2ftrace_2ftrack_5fevent_2flog_5fmessage_2eproto.base,
      &scc_info_HistogramName_protos_2fperfetto_2ftrace_2ftrack_5fevent_2fchrome_5fhistogram_5fsample_2eproto.base,
      &scc_info_InternedString_protos_2fperfetto_2ftrace_2fprofiling_2fprofile_5fcommon_2eproto.base,
      &scc_info_ProfiledFrameSymbols_protos_2fperfetto_2ftrace_2fprofiling_2fprofile_5fcommon_2eproto.base,
      &scc_info_Mapping_protos_2fperfetto_2ftrace_2fprofiling_2fprofile_5fcommon_2eproto.base,
      &scc_info_Frame_protos_2fperfetto_2ftrace_2fprofiling_2fprofile_5fcommon_2eproto.base,
      &scc_info_Callstack_protos_2fperfetto_2ftrace_2fprofiling_2fprofile_5fcommon_2eproto.base,
      &scc_info_InternedGraphicsContext_protos_2fperfetto_2ftrace_2fgpu_2fgpu_5frender_5fstage_5fevent_2eproto.base,
      &scc_info_InternedGpuRenderStageSpecification_protos_2fperfetto_2ftrace_2fgpu_2fgpu_5frender_5fstage_5fevent_2eproto.base,}};

namespace perfetto {
namespace protos {

// ===================================================================

class InternedData::_Internal {
 public:
};

void InternedData::clear_event_categories() {
  event_categories_.Clear();
}
void InternedData::clear_event_names() {
  event_names_.Clear();
}
void InternedData::clear_debug_annotation_names() {
  debug_annotation_names_.Clear();
}
void InternedData::clear_debug_annotation_value_type_names() {
  debug_annotation_value_type_names_.Clear();
}
void InternedData::clear_source_locations() {
  source_locations_.Clear();
}
void InternedData::clear_log_message_body() {
  log_message_body_.Clear();
}
void InternedData::clear_histogram_names() {
  histogram_names_.Clear();
}
void InternedData::clear_build_ids() {
  build_ids_.Clear();
}
void InternedData::clear_mapping_paths() {
  mapping_paths_.Clear();
}
void InternedData::clear_source_paths() {
  source_paths_.Clear();
}
void InternedData::clear_function_names() {
  function_names_.Clear();
}
void InternedData::clear_profiled_frame_symbols() {
  profiled_frame_symbols_.Clear();
}
void InternedData::clear_mappings() {
  mappings_.Clear();
}
void InternedData::clear_frames() {
  frames_.Clear();
}
void InternedData::clear_callstacks() {
  callstacks_.Clear();
}
void InternedData::clear_vulkan_memory_keys() {
  vulkan_memory_keys_.Clear();
}
void InternedData::clear_graphics_contexts() {
  graphics_contexts_.Clear();
}
void InternedData::clear_gpu_specifications() {
  gpu_specifications_.Clear();
}
void InternedData::clear_kernel_symbols() {
  kernel_symbols_.Clear();
}
InternedData::InternedData(::PROTOBUF_NAMESPACE_ID::Arena* arena)
  : ::PROTOBUF_NAMESPACE_ID::MessageLite(arena),
  event_categories_(arena),
  event_names_(arena),
  debug_annotation_names_(arena),
  source_locations_(arena),
  function_names_(arena),
  frames_(arena),
  callstacks_(arena),
  build_ids_(arena),
  mapping_paths_(arena),
  source_paths_(arena),
  mappings_(arena),
  log_message_body_(arena),
  profiled_frame_symbols_(arena),
  vulkan_memory_keys_(arena),
  graphics_contexts_(arena),
  gpu_specifications_(arena),
  histogram_names_(arena),
  kernel_symbols_(arena),
  debug_annotation_value_type_names_(arena) {
  SharedCtor();
  RegisterArenaDtor(arena);
  // @@protoc_insertion_point(arena_constructor:perfetto.protos.InternedData)
}
InternedData::InternedData(const InternedData& from)
  : ::PROTOBUF_NAMESPACE_ID::MessageLite(),
      event_categories_(from.event_categories_),
      event_names_(from.event_names_),
      debug_annotation_names_(from.debug_annotation_names_),
      source_locations_(from.source_locations_),
      function_names_(from.function_names_),
      frames_(from.frames_),
      callstacks_(from.callstacks_),
      build_ids_(from.build_ids_),
      mapping_paths_(from.mapping_paths_),
      source_paths_(from.source_paths_),
      mappings_(from.mappings_),
      log_message_body_(from.log_message_body_),
      profiled_frame_symbols_(from.profiled_frame_symbols_),
      vulkan_memory_keys_(from.vulkan_memory_keys_),
      graphics_contexts_(from.graphics_contexts_),
      gpu_specifications_(from.gpu_specifications_),
      histogram_names_(from.histogram_names_),
      kernel_symbols_(from.kernel_symbols_),
      debug_annotation_value_type_names_(from.debug_annotation_value_type_names_) {
  _internal_metadata_.MergeFrom<std::string>(from._internal_metadata_);
  // @@protoc_insertion_point(copy_constructor:perfetto.protos.InternedData)
}

void InternedData::SharedCtor() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&scc_info_InternedData_protos_2fperfetto_2ftrace_2finterned_5fdata_2finterned_5fdata_2eproto.base);
}

InternedData::~InternedData() {
  // @@protoc_insertion_point(destructor:perfetto.protos.InternedData)
  SharedDtor();
  _internal_metadata_.Delete<std::string>();
}

void InternedData::SharedDtor() {
  GOOGLE_DCHECK(GetArena() == nullptr);
}

void InternedData::ArenaDtor(void* object) {
  InternedData* _this = reinterpret_cast< InternedData* >(object);
  (void)_this;
}
void InternedData::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void InternedData::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const InternedData& InternedData::default_instance() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&::scc_info_InternedData_protos_2fperfetto_2ftrace_2finterned_5fdata_2finterned_5fdata_2eproto.base);
  return *internal_default_instance();
}


void InternedData::Clear() {
// @@protoc_insertion_point(message_clear_start:perfetto.protos.InternedData)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  event_categories_.Clear();
  event_names_.Clear();
  debug_annotation_names_.Clear();
  source_locations_.Clear();
  function_names_.Clear();
  frames_.Clear();
  callstacks_.Clear();
  build_ids_.Clear();
  mapping_paths_.Clear();
  source_paths_.Clear();
  mappings_.Clear();
  log_message_body_.Clear();
  profiled_frame_symbols_.Clear();
  vulkan_memory_keys_.Clear();
  graphics_contexts_.Clear();
  gpu_specifications_.Clear();
  histogram_names_.Clear();
  kernel_symbols_.Clear();
  debug_annotation_value_type_names_.Clear();
  _internal_metadata_.Clear<std::string>();
}

const char* InternedData::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    CHK_(ptr);
    switch (tag >> 3) {
      // repeated .perfetto.protos.EventCategory event_categories = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 10)) {
          ptr -= 1;
          do {
            ptr += 1;
            ptr = ctx->ParseMessage(_internal_add_event_categories(), ptr);
            CHK_(ptr);
            if (!ctx->DataAvailable(ptr)) break;
          } while (::PROTOBUF_NAMESPACE_ID::internal::ExpectTag<10>(ptr));
        } else goto handle_unusual;
        continue;
      // repeated .perfetto.protos.EventName event_names = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 18)) {
          ptr -= 1;
          do {
            ptr += 1;
            ptr = ctx->ParseMessage(_internal_add_event_names(), ptr);
            CHK_(ptr);
            if (!ctx->DataAvailable(ptr)) break;
          } while (::PROTOBUF_NAMESPACE_ID::internal::ExpectTag<18>(ptr));
        } else goto handle_unusual;
        continue;
      // repeated .perfetto.protos.DebugAnnotationName debug_annotation_names = 3;
      case 3:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 26)) {
          ptr -= 1;
          do {
            ptr += 1;
            ptr = ctx->ParseMessage(_internal_add_debug_annotation_names(), ptr);
            CHK_(ptr);
            if (!ctx->DataAvailable(ptr)) break;
          } while (::PROTOBUF_NAMESPACE_ID::internal::ExpectTag<26>(ptr));
        } else goto handle_unusual;
        continue;
      // repeated .perfetto.protos.SourceLocation source_locations = 4;
      case 4:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 34)) {
          ptr -= 1;
          do {
            ptr += 1;
            ptr = ctx->ParseMessage(_internal_add_source_locations(), ptr);
            CHK_(ptr);
            if (!ctx->DataAvailable(ptr)) break;
          } while (::PROTOBUF_NAMESPACE_ID::internal::ExpectTag<34>(ptr));
        } else goto handle_unusual;
        continue;
      // repeated .perfetto.protos.InternedString function_names = 5;
      case 5:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 42)) {
          ptr -= 1;
          do {
            ptr += 1;
            ptr = ctx->ParseMessage(_internal_add_function_names(), ptr);
            CHK_(ptr);
            if (!ctx->DataAvailable(ptr)) break;
          } while (::PROTOBUF_NAMESPACE_ID::internal::ExpectTag<42>(ptr));
        } else goto handle_unusual;
        continue;
      // repeated .perfetto.protos.Frame frames = 6;
      case 6:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 50)) {
          ptr -= 1;
          do {
            ptr += 1;
            ptr = ctx->ParseMessage(_internal_add_frames(), ptr);
            CHK_(ptr);
            if (!ctx->DataAvailable(ptr)) break;
          } while (::PROTOBUF_NAMESPACE_ID::internal::ExpectTag<50>(ptr));
        } else goto handle_unusual;
        continue;
      // repeated .perfetto.protos.Callstack callstacks = 7;
      case 7:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 58)) {
          ptr -= 1;
          do {
            ptr += 1;
            ptr = ctx->ParseMessage(_internal_add_callstacks(), ptr);
            CHK_(ptr);
            if (!ctx->DataAvailable(ptr)) break;
          } while (::PROTOBUF_NAMESPACE_ID::internal::ExpectTag<58>(ptr));
        } else goto handle_unusual;
        continue;
      // repeated .perfetto.protos.InternedString build_ids = 16;
      case 16:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 130)) {
          ptr -= 2;
          do {
            ptr += 2;
            ptr = ctx->ParseMessage(_internal_add_build_ids(), ptr);
            CHK_(ptr);
            if (!ctx->DataAvailable(ptr)) break;
          } while (::PROTOBUF_NAMESPACE_ID::internal::ExpectTag<130>(ptr));
        } else goto handle_unusual;
        continue;
      // repeated .perfetto.protos.InternedString mapping_paths = 17;
      case 17:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 138)) {
          ptr -= 2;
          do {
            ptr += 2;
            ptr = ctx->ParseMessage(_internal_add_mapping_paths(), ptr);
            CHK_(ptr);
            if (!ctx->DataAvailable(ptr)) break;
          } while (::PROTOBUF_NAMESPACE_ID::internal::ExpectTag<138>(ptr));
        } else goto handle_unusual;
        continue;
      // repeated .perfetto.protos.InternedString source_paths = 18;
      case 18:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 146)) {
          ptr -= 2;
          do {
            ptr += 2;
            ptr = ctx->ParseMessage(_internal_add_source_paths(), ptr);
            CHK_(ptr);
            if (!ctx->DataAvailable(ptr)) break;
          } while (::PROTOBUF_NAMESPACE_ID::internal::ExpectTag<146>(ptr));
        } else goto handle_unusual;
        continue;
      // repeated .perfetto.protos.Mapping mappings = 19;
      case 19:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 154)) {
          ptr -= 2;
          do {
            ptr += 2;
            ptr = ctx->ParseMessage(_internal_add_mappings(), ptr);
            CHK_(ptr);
            if (!ctx->DataAvailable(ptr)) break;
          } while (::PROTOBUF_NAMESPACE_ID::internal::ExpectTag<154>(ptr));
        } else goto handle_unusual;
        continue;
      // repeated .perfetto.protos.LogMessageBody log_message_body = 20;
      case 20:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 162)) {
          ptr -= 2;
          do {
            ptr += 2;
            ptr = ctx->ParseMessage(_internal_add_log_message_body(), ptr);
            CHK_(ptr);
            if (!ctx->DataAvailable(ptr)) break;
          } while (::PROTOBUF_NAMESPACE_ID::internal::ExpectTag<162>(ptr));
        } else goto handle_unusual;
        continue;
      // repeated .perfetto.protos.ProfiledFrameSymbols profiled_frame_symbols = 21;
      case 21:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 170)) {
          ptr -= 2;
          do {
            ptr += 2;
            ptr = ctx->ParseMessage(_internal_add_profiled_frame_symbols(), ptr);
            CHK_(ptr);
            if (!ctx->DataAvailable(ptr)) break;
          } while (::PROTOBUF_NAMESPACE_ID::internal::ExpectTag<170>(ptr));
        } else goto handle_unusual;
        continue;
      // repeated .perfetto.protos.InternedString vulkan_memory_keys = 22;
      case 22:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 178)) {
          ptr -= 2;
          do {
            ptr += 2;
            ptr = ctx->ParseMessage(_internal_add_vulkan_memory_keys(), ptr);
            CHK_(ptr);
            if (!ctx->DataAvailable(ptr)) break;
          } while (::PROTOBUF_NAMESPACE_ID::internal::ExpectTag<178>(ptr));
        } else goto handle_unusual;
        continue;
      // repeated .perfetto.protos.InternedGraphicsContext graphics_contexts = 23;
      case 23:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 186)) {
          ptr -= 2;
          do {
            ptr += 2;
            ptr = ctx->ParseMessage(_internal_add_graphics_contexts(), ptr);
            CHK_(ptr);
            if (!ctx->DataAvailable(ptr)) break;
          } while (::PROTOBUF_NAMESPACE_ID::internal::ExpectTag<186>(ptr));
        } else goto handle_unusual;
        continue;
      // repeated .perfetto.protos.InternedGpuRenderStageSpecification gpu_specifications = 24;
      case 24:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 194)) {
          ptr -= 2;
          do {
            ptr += 2;
            ptr = ctx->ParseMessage(_internal_add_gpu_specifications(), ptr);
            CHK_(ptr);
            if (!ctx->DataAvailable(ptr)) break;
          } while (::PROTOBUF_NAMESPACE_ID::internal::ExpectTag<194>(ptr));
        } else goto handle_unusual;
        continue;
      // repeated .perfetto.protos.HistogramName histogram_names = 25;
      case 25:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 202)) {
          ptr -= 2;
          do {
            ptr += 2;
            ptr = ctx->ParseMessage(_internal_add_histogram_names(), ptr);
            CHK_(ptr);
            if (!ctx->DataAvailable(ptr)) break;
          } while (::PROTOBUF_NAMESPACE_ID::internal::ExpectTag<202>(ptr));
        } else goto handle_unusual;
        continue;
      // repeated .perfetto.protos.InternedString kernel_symbols = 26;
      case 26:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 210)) {
          ptr -= 2;
          do {
            ptr += 2;
            ptr = ctx->ParseMessage(_internal_add_kernel_symbols(), ptr);
            CHK_(ptr);
            if (!ctx->DataAvailable(ptr)) break;
          } while (::PROTOBUF_NAMESPACE_ID::internal::ExpectTag<210>(ptr));
        } else goto handle_unusual;
        continue;
      // repeated .perfetto.protos.DebugAnnotationValueTypeName debug_annotation_value_type_names = 27;
      case 27:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 218)) {
          ptr -= 2;
          do {
            ptr += 2;
            ptr = ctx->ParseMessage(_internal_add_debug_annotation_value_type_names(), ptr);
            CHK_(ptr);
            if (!ctx->DataAvailable(ptr)) break;
          } while (::PROTOBUF_NAMESPACE_ID::internal::ExpectTag<218>(ptr));
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
  return ptr;
failure:
  ptr = nullptr;
  goto success;
#undef CHK_
}

::PROTOBUF_NAMESPACE_ID::uint8* InternedData::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:perfetto.protos.InternedData)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // repeated .perfetto.protos.EventCategory event_categories = 1;
  for (unsigned int i = 0,
      n = static_cast<unsigned int>(this->_internal_event_categories_size()); i < n; i++) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessage(1, this->_internal_event_categories(i), target, stream);
  }

  // repeated .perfetto.protos.EventName event_names = 2;
  for (unsigned int i = 0,
      n = static_cast<unsigned int>(this->_internal_event_names_size()); i < n; i++) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessage(2, this->_internal_event_names(i), target, stream);
  }

  // repeated .perfetto.protos.DebugAnnotationName debug_annotation_names = 3;
  for (unsigned int i = 0,
      n = static_cast<unsigned int>(this->_internal_debug_annotation_names_size()); i < n; i++) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessage(3, this->_internal_debug_annotation_names(i), target, stream);
  }

  // repeated .perfetto.protos.SourceLocation source_locations = 4;
  for (unsigned int i = 0,
      n = static_cast<unsigned int>(this->_internal_source_locations_size()); i < n; i++) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessage(4, this->_internal_source_locations(i), target, stream);
  }

  // repeated .perfetto.protos.InternedString function_names = 5;
  for (unsigned int i = 0,
      n = static_cast<unsigned int>(this->_internal_function_names_size()); i < n; i++) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessage(5, this->_internal_function_names(i), target, stream);
  }

  // repeated .perfetto.protos.Frame frames = 6;
  for (unsigned int i = 0,
      n = static_cast<unsigned int>(this->_internal_frames_size()); i < n; i++) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessage(6, this->_internal_frames(i), target, stream);
  }

  // repeated .perfetto.protos.Callstack callstacks = 7;
  for (unsigned int i = 0,
      n = static_cast<unsigned int>(this->_internal_callstacks_size()); i < n; i++) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessage(7, this->_internal_callstacks(i), target, stream);
  }

  // repeated .perfetto.protos.InternedString build_ids = 16;
  for (unsigned int i = 0,
      n = static_cast<unsigned int>(this->_internal_build_ids_size()); i < n; i++) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessage(16, this->_internal_build_ids(i), target, stream);
  }

  // repeated .perfetto.protos.InternedString mapping_paths = 17;
  for (unsigned int i = 0,
      n = static_cast<unsigned int>(this->_internal_mapping_paths_size()); i < n; i++) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessage(17, this->_internal_mapping_paths(i), target, stream);
  }

  // repeated .perfetto.protos.InternedString source_paths = 18;
  for (unsigned int i = 0,
      n = static_cast<unsigned int>(this->_internal_source_paths_size()); i < n; i++) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessage(18, this->_internal_source_paths(i), target, stream);
  }

  // repeated .perfetto.protos.Mapping mappings = 19;
  for (unsigned int i = 0,
      n = static_cast<unsigned int>(this->_internal_mappings_size()); i < n; i++) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessage(19, this->_internal_mappings(i), target, stream);
  }

  // repeated .perfetto.protos.LogMessageBody log_message_body = 20;
  for (unsigned int i = 0,
      n = static_cast<unsigned int>(this->_internal_log_message_body_size()); i < n; i++) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessage(20, this->_internal_log_message_body(i), target, stream);
  }

  // repeated .perfetto.protos.ProfiledFrameSymbols profiled_frame_symbols = 21;
  for (unsigned int i = 0,
      n = static_cast<unsigned int>(this->_internal_profiled_frame_symbols_size()); i < n; i++) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessage(21, this->_internal_profiled_frame_symbols(i), target, stream);
  }

  // repeated .perfetto.protos.InternedString vulkan_memory_keys = 22;
  for (unsigned int i = 0,
      n = static_cast<unsigned int>(this->_internal_vulkan_memory_keys_size()); i < n; i++) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessage(22, this->_internal_vulkan_memory_keys(i), target, stream);
  }

  // repeated .perfetto.protos.InternedGraphicsContext graphics_contexts = 23;
  for (unsigned int i = 0,
      n = static_cast<unsigned int>(this->_internal_graphics_contexts_size()); i < n; i++) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessage(23, this->_internal_graphics_contexts(i), target, stream);
  }

  // repeated .perfetto.protos.InternedGpuRenderStageSpecification gpu_specifications = 24;
  for (unsigned int i = 0,
      n = static_cast<unsigned int>(this->_internal_gpu_specifications_size()); i < n; i++) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessage(24, this->_internal_gpu_specifications(i), target, stream);
  }

  // repeated .perfetto.protos.HistogramName histogram_names = 25;
  for (unsigned int i = 0,
      n = static_cast<unsigned int>(this->_internal_histogram_names_size()); i < n; i++) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessage(25, this->_internal_histogram_names(i), target, stream);
  }

  // repeated .perfetto.protos.InternedString kernel_symbols = 26;
  for (unsigned int i = 0,
      n = static_cast<unsigned int>(this->_internal_kernel_symbols_size()); i < n; i++) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessage(26, this->_internal_kernel_symbols(i), target, stream);
  }

  // repeated .perfetto.protos.DebugAnnotationValueTypeName debug_annotation_value_type_names = 27;
  for (unsigned int i = 0,
      n = static_cast<unsigned int>(this->_internal_debug_annotation_value_type_names_size()); i < n; i++) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessage(27, this->_internal_debug_annotation_value_type_names(i), target, stream);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = stream->WriteRaw(_internal_metadata_.unknown_fields<std::string>(::PROTOBUF_NAMESPACE_ID::internal::GetEmptyString).data(),
        static_cast<int>(_internal_metadata_.unknown_fields<std::string>(::PROTOBUF_NAMESPACE_ID::internal::GetEmptyString).size()), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:perfetto.protos.InternedData)
  return target;
}

size_t InternedData::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:perfetto.protos.InternedData)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // repeated .perfetto.protos.EventCategory event_categories = 1;
  total_size += 1UL * this->_internal_event_categories_size();
  for (const auto& msg : this->event_categories_) {
    total_size +=
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(msg);
  }

  // repeated .perfetto.protos.EventName event_names = 2;
  total_size += 1UL * this->_internal_event_names_size();
  for (const auto& msg : this->event_names_) {
    total_size +=
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(msg);
  }

  // repeated .perfetto.protos.DebugAnnotationName debug_annotation_names = 3;
  total_size += 1UL * this->_internal_debug_annotation_names_size();
  for (const auto& msg : this->debug_annotation_names_) {
    total_size +=
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(msg);
  }

  // repeated .perfetto.protos.SourceLocation source_locations = 4;
  total_size += 1UL * this->_internal_source_locations_size();
  for (const auto& msg : this->source_locations_) {
    total_size +=
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(msg);
  }

  // repeated .perfetto.protos.InternedString function_names = 5;
  total_size += 1UL * this->_internal_function_names_size();
  for (const auto& msg : this->function_names_) {
    total_size +=
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(msg);
  }

  // repeated .perfetto.protos.Frame frames = 6;
  total_size += 1UL * this->_internal_frames_size();
  for (const auto& msg : this->frames_) {
    total_size +=
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(msg);
  }

  // repeated .perfetto.protos.Callstack callstacks = 7;
  total_size += 1UL * this->_internal_callstacks_size();
  for (const auto& msg : this->callstacks_) {
    total_size +=
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(msg);
  }

  // repeated .perfetto.protos.InternedString build_ids = 16;
  total_size += 2UL * this->_internal_build_ids_size();
  for (const auto& msg : this->build_ids_) {
    total_size +=
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(msg);
  }

  // repeated .perfetto.protos.InternedString mapping_paths = 17;
  total_size += 2UL * this->_internal_mapping_paths_size();
  for (const auto& msg : this->mapping_paths_) {
    total_size +=
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(msg);
  }

  // repeated .perfetto.protos.InternedString source_paths = 18;
  total_size += 2UL * this->_internal_source_paths_size();
  for (const auto& msg : this->source_paths_) {
    total_size +=
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(msg);
  }

  // repeated .perfetto.protos.Mapping mappings = 19;
  total_size += 2UL * this->_internal_mappings_size();
  for (const auto& msg : this->mappings_) {
    total_size +=
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(msg);
  }

  // repeated .perfetto.protos.LogMessageBody log_message_body = 20;
  total_size += 2UL * this->_internal_log_message_body_size();
  for (const auto& msg : this->log_message_body_) {
    total_size +=
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(msg);
  }

  // repeated .perfetto.protos.ProfiledFrameSymbols profiled_frame_symbols = 21;
  total_size += 2UL * this->_internal_profiled_frame_symbols_size();
  for (const auto& msg : this->profiled_frame_symbols_) {
    total_size +=
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(msg);
  }

  // repeated .perfetto.protos.InternedString vulkan_memory_keys = 22;
  total_size += 2UL * this->_internal_vulkan_memory_keys_size();
  for (const auto& msg : this->vulkan_memory_keys_) {
    total_size +=
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(msg);
  }

  // repeated .perfetto.protos.InternedGraphicsContext graphics_contexts = 23;
  total_size += 2UL * this->_internal_graphics_contexts_size();
  for (const auto& msg : this->graphics_contexts_) {
    total_size +=
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(msg);
  }

  // repeated .perfetto.protos.InternedGpuRenderStageSpecification gpu_specifications = 24;
  total_size += 2UL * this->_internal_gpu_specifications_size();
  for (const auto& msg : this->gpu_specifications_) {
    total_size +=
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(msg);
  }

  // repeated .perfetto.protos.HistogramName histogram_names = 25;
  total_size += 2UL * this->_internal_histogram_names_size();
  for (const auto& msg : this->histogram_names_) {
    total_size +=
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(msg);
  }

  // repeated .perfetto.protos.InternedString kernel_symbols = 26;
  total_size += 2UL * this->_internal_kernel_symbols_size();
  for (const auto& msg : this->kernel_symbols_) {
    total_size +=
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(msg);
  }

  // repeated .perfetto.protos.DebugAnnotationValueTypeName debug_annotation_value_type_names = 27;
  total_size += 2UL * this->_internal_debug_annotation_value_type_names_size();
  for (const auto& msg : this->debug_annotation_value_type_names_) {
    total_size +=
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(msg);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    total_size += _internal_metadata_.unknown_fields<std::string>(::PROTOBUF_NAMESPACE_ID::internal::GetEmptyString).size();
  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void InternedData::CheckTypeAndMergeFrom(
    const ::PROTOBUF_NAMESPACE_ID::MessageLite& from) {
  MergeFrom(*::PROTOBUF_NAMESPACE_ID::internal::DownCast<const InternedData*>(
      &from));
}

void InternedData::MergeFrom(const InternedData& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:perfetto.protos.InternedData)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom<std::string>(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  event_categories_.MergeFrom(from.event_categories_);
  event_names_.MergeFrom(from.event_names_);
  debug_annotation_names_.MergeFrom(from.debug_annotation_names_);
  source_locations_.MergeFrom(from.source_locations_);
  function_names_.MergeFrom(from.function_names_);
  frames_.MergeFrom(from.frames_);
  callstacks_.MergeFrom(from.callstacks_);
  build_ids_.MergeFrom(from.build_ids_);
  mapping_paths_.MergeFrom(from.mapping_paths_);
  source_paths_.MergeFrom(from.source_paths_);
  mappings_.MergeFrom(from.mappings_);
  log_message_body_.MergeFrom(from.log_message_body_);
  profiled_frame_symbols_.MergeFrom(from.profiled_frame_symbols_);
  vulkan_memory_keys_.MergeFrom(from.vulkan_memory_keys_);
  graphics_contexts_.MergeFrom(from.graphics_contexts_);
  gpu_specifications_.MergeFrom(from.gpu_specifications_);
  histogram_names_.MergeFrom(from.histogram_names_);
  kernel_symbols_.MergeFrom(from.kernel_symbols_);
  debug_annotation_value_type_names_.MergeFrom(from.debug_annotation_value_type_names_);
}

void InternedData::CopyFrom(const InternedData& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:perfetto.protos.InternedData)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool InternedData::IsInitialized() const {
  return true;
}

void InternedData::InternalSwap(InternedData* other) {
  using std::swap;
  _internal_metadata_.Swap<std::string>(&other->_internal_metadata_);
  event_categories_.InternalSwap(&other->event_categories_);
  event_names_.InternalSwap(&other->event_names_);
  debug_annotation_names_.InternalSwap(&other->debug_annotation_names_);
  source_locations_.InternalSwap(&other->source_locations_);
  function_names_.InternalSwap(&other->function_names_);
  frames_.InternalSwap(&other->frames_);
  callstacks_.InternalSwap(&other->callstacks_);
  build_ids_.InternalSwap(&other->build_ids_);
  mapping_paths_.InternalSwap(&other->mapping_paths_);
  source_paths_.InternalSwap(&other->source_paths_);
  mappings_.InternalSwap(&other->mappings_);
  log_message_body_.InternalSwap(&other->log_message_body_);
  profiled_frame_symbols_.InternalSwap(&other->profiled_frame_symbols_);
  vulkan_memory_keys_.InternalSwap(&other->vulkan_memory_keys_);
  graphics_contexts_.InternalSwap(&other->graphics_contexts_);
  gpu_specifications_.InternalSwap(&other->gpu_specifications_);
  histogram_names_.InternalSwap(&other->histogram_names_);
  kernel_symbols_.InternalSwap(&other->kernel_symbols_);
  debug_annotation_value_type_names_.InternalSwap(&other->debug_annotation_value_type_names_);
}

std::string InternedData::GetTypeName() const {
  return "perfetto.protos.InternedData";
}


// @@protoc_insertion_point(namespace_scope)
}  // namespace protos
}  // namespace perfetto
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::perfetto::protos::InternedData* Arena::CreateMaybeMessage< ::perfetto::protos::InternedData >(Arena* arena) {
  return Arena::CreateMessageInternal< ::perfetto::protos::InternedData >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
