add_library(xchromebase STATIC)

target_include_directories(xchromebase
PUBLIC
    /
    gen
    third_party
)

target_precompile_headers(xchromebase PRIVATE "base_precompiled.pch")
if(WIN32)
target_compile_options(xchromebase PRIVATE "/FIbase_precompiled.pch")
endif()

target_include_directories(xchromebase
PUBLIC
    third_party/prefetto
    third_party/perfetto/include
    gen/third_party/perfetto/
    gen/third_party/perfetto/build_config
)

target_include_directories(xchromebase
PUBLIC
    third_party/abseil-cpp
    third_party/boringssl/src/include
)


target_include_directories(xchromebase
PRIVATE
    third_party/icu/source/common
    third_party/icu/source/i18n
)

add_definitions(-DNOMINMAX)

include(cmake/nice_target_sources.cmake)

  nice_target_sources(xchromebase "base/"
    PRIVATE
    as_const.h
    at_exit.cc
    at_exit.h
    atomic_ref_count.h
    atomic_sequence_num.h
    atomicops.h
    atomicops_internals_atomicword_compat.h
    atomicops_internals_portable.h
    auto_reset.h
    barrier_callback.h
    barrier_closure.cc
    barrier_closure.h
    base64.cc
    base64.h
    base64url.cc
    base64url.h
    base_export.h
    base_switches.h
    base_switches.cc
    big_endian.cc
    big_endian.h
    bind.h
    bind_internal.h
    bit_cast.h
    bits.h
    build_time.cc
    build_time.h
    callback.h
    callback_forward.h
    callback_helpers.cc
    callback_helpers.h
    callback_internal.cc
    callback_internal.h
    callback_list.cc
    callback_list.h
    cancelable_callback.h
    check.cc
    check.h
    check_op.cc
    check_op.h
    command_line.cc
    command_line.h
    compiler_specific.h
    component_export.h
    containers/adapters.h
    containers/buffer_iterator.h
    containers/checked_iterators.h
    containers/checked_range.h
    containers/circular_deque.h
    containers/contains.h
    containers/contiguous_iterator.h
    containers/cxx20_erase.h
    containers/cxx20_erase_deque.h
    containers/cxx20_erase_forward_list.h
    containers/cxx20_erase_internal.h
    containers/cxx20_erase_list.h
    containers/cxx20_erase_map.h
    containers/cxx20_erase_set.h
    containers/cxx20_erase_string.h
    containers/cxx20_erase_unordered_map.h
    containers/cxx20_erase_unordered_set.h
    containers/cxx20_erase_vector.h
    containers/enum_set.h
    containers/extend.h
    containers/fixed_flat_map.h
    containers/fixed_flat_set.h
    containers/flat_map.h
    containers/flat_set.h
    containers/flat_tree.cc
    containers/flat_tree.h
    containers/id_map.h
    containers/intrusive_heap.cc
    containers/intrusive_heap.h
    containers/linked_list.cc
    containers/linked_list.h
    containers/lru_cache.h
    containers/small_map.h
    containers/span.h
    containers/stack.h
    containers/stack_container.h
    containers/unique_ptr_adapters.h
    containers/util.h
    containers/vector_buffer.h
    cpu.cc
    cpu.h
    cpu_reduction_experiment.cc
    cpu_reduction_experiment.h
    critical_closure.h
    cxx17_backports.h
    cxx20_to_address.h
    dcheck_is_on.h
    debug/activity_analyzer.cc
    debug/activity_analyzer.h
    debug/activity_tracker.cc
    debug/activity_tracker.h
    debug/alias.cc
    debug/alias.h
    debug/asan_invalid_access.cc
    debug/asan_invalid_access.h
    debug/buffered_dwarf_reader.cc
    debug/buffered_dwarf_reader.h
    debug/crash_logging.cc
    debug/crash_logging.h
    debug/debugger.cc
    debug/debugger.h
    debug/dump_without_crashing.cc
    debug/dump_without_crashing.h
    debug/dwarf_line_no.cc
    debug/dwarf_line_no.h
    debug/leak_annotations.h
    debug/profiler.cc
    debug/profiler.h
    debug/task_trace.cc
    debug/task_trace.h
    environment.cc
    environment.h
    export_template.h
    feature_list.cc
    feature_list.h
    features.cc
    features.h
    file_version_info.h
    files/dir_reader_fallback.h
    files/file.cc
    files/file.h
    files/file_enumerator.cc
    files/file_enumerator.h
    files/file_error_or.h
    files/file_path.cc
    files/file_path.h
    files/file_path_watcher.cc
    files/file_path_watcher.h
    files/file_proxy.cc
    files/file_proxy.h
    files/file_tracing.cc
    files/file_tracing.h
    files/file_util.cc
    files/file_util.h
    files/important_file_writer.cc
    files/important_file_writer.h
    files/important_file_writer_cleaner.cc
    files/important_file_writer_cleaner.h
    files/memory_mapped_file.cc
    files/memory_mapped_file.h
    files/platform_file.h
    files/safe_base_name.cc
    files/safe_base_name.h
    files/scoped_file.cc
    files/scoped_file.h
    files/scoped_temp_dir.cc
    files/scoped_temp_dir.h
    format_macros.h
    functional/identity.h
    functional/invoke.h
    functional/not_fn.h
    gtest_prod_util.h
    guid.cc
    guid.h
    hash/hash.cc
    hash/hash.h
    hash/md5_boringssl.cc
    hash/sha1_boringssl.cc
    hash/legacy_hash.cc
    hash/legacy_hash.h
    immediate_crash.h
    json/json_common.h
    json/json_file_value_serializer.cc
    json/json_file_value_serializer.h
    json/json_parser.cc
    json/json_parser.h
    json/json_reader.cc
    json/json_reader.h
    json/json_string_value_serializer.cc
    json/json_string_value_serializer.h
    json/json_value_converter.cc
    json/json_value_converter.h
    json/json_writer.cc
    json/json_writer.h
    json/string_escape.cc
    json/string_escape.h
    json/values_util.cc
    json/values_util.h
    lazy_instance.h
    lazy_instance_helpers.cc
    lazy_instance_helpers.h
    location.cc
    location.h
    logging.cc
    logging.h
    memory/aligned_memory.cc
    memory/aligned_memory.h
    memory/discardable_memory.cc
    memory/discardable_memory.h
    memory/discardable_memory_allocator.cc
    memory/discardable_memory_allocator.h
    memory/discardable_memory_internal.h
    memory/discardable_shared_memory.cc
    memory/discardable_shared_memory.h
    memory/free_deleter.h
    memory/memory_pressure_listener.cc
    memory/memory_pressure_listener.h
    memory/memory_pressure_monitor.cc
    memory/memory_pressure_monitor.h
    memory/nonscannable_memory.cc
    memory/nonscannable_memory.h
    memory/page_size.h
    memory/platform_shared_memory_handle.cc
    memory/platform_shared_memory_handle.h
    memory/platform_shared_memory_mapper.h
    memory/platform_shared_memory_region.cc
    memory/platform_shared_memory_region.h
    memory/ptr_util.h
    memory/raw_ptr.cc
    memory/raw_ptr.h
    memory/raw_ptr_exclusion.h
    memory/raw_scoped_refptr_mismatch_checker.h
    memory/read_only_shared_memory_region.cc
    memory/read_only_shared_memory_region.h
    memory/ref_counted.cc
    memory/ref_counted.h
    memory/ref_counted_delete_on_sequence.h
    memory/ref_counted_memory.cc
    memory/ref_counted_memory.h
    memory/safe_ref.h
    memory/scoped_policy.h
    memory/scoped_refptr.h
    memory/shared_memory_hooks.h
    memory/shared_memory_mapper.cc
    memory/shared_memory_mapper.h
    memory/shared_memory_mapping.cc
    memory/shared_memory_mapping.h
    memory/shared_memory_security_policy.cc
    memory/shared_memory_security_policy.h
    memory/shared_memory_tracker.cc
    memory/shared_memory_tracker.h
    memory/singleton.h
    memory/unsafe_shared_memory_pool.cc
    memory/unsafe_shared_memory_pool.h
    memory/unsafe_shared_memory_region.cc
    memory/unsafe_shared_memory_region.h
    memory/values_equivalent.h
    memory/weak_auto_reset.h
    memory/weak_ptr.cc
    memory/weak_ptr.h
    memory/writable_shared_memory_region.cc
    memory/writable_shared_memory_region.h
    message_loop/message_pump.cc
    message_loop/message_pump.h
    message_loop/message_pump_default.cc
    message_loop/message_pump_default.h
    message_loop/message_pump_type.h
    message_loop/timer_slack.h
    message_loop/work_id_provider.cc
    message_loop/work_id_provider.h
    metrics/bucket_ranges.cc
    metrics/bucket_ranges.h
    metrics/crc32.cc
    metrics/crc32.h
    metrics/dummy_histogram.cc
    metrics/dummy_histogram.h
    metrics/field_trial.cc
    metrics/field_trial.h
    metrics/field_trial_param_associator.cc
    metrics/field_trial_param_associator.h
    metrics/field_trial_params.cc
    metrics/field_trial_params.h
    metrics/histogram.cc
    metrics/histogram.h
    metrics/histogram_base.cc
    metrics/histogram_base.h
    metrics/histogram_delta_serialization.cc
    metrics/histogram_delta_serialization.h
    metrics/histogram_flattener.h
    metrics/histogram_functions.cc
    metrics/histogram_functions.h
    metrics/histogram_macros.h
    metrics/histogram_macros_internal.h
    metrics/histogram_macros_local.h
    metrics/histogram_samples.cc
    metrics/histogram_samples.h
    metrics/histogram_snapshot_manager.cc
    metrics/histogram_snapshot_manager.h
    metrics/metrics_hashes.cc
    metrics/metrics_hashes.h
    metrics/persistent_histogram_allocator.cc
    metrics/persistent_histogram_allocator.h
    metrics/persistent_memory_allocator.cc
    metrics/persistent_memory_allocator.h
    metrics/persistent_sample_map.cc
    metrics/persistent_sample_map.h
    metrics/ranges_manager.cc
    metrics/ranges_manager.h
    metrics/record_histogram_checker.h
    metrics/sample_map.cc
    metrics/sample_map.h
    metrics/sample_vector.cc
    metrics/sample_vector.h
    metrics/single_sample_metrics.cc
    metrics/single_sample_metrics.h
    metrics/sparse_histogram.cc
    metrics/sparse_histogram.h
    metrics/statistics_recorder.cc
    metrics/statistics_recorder.h
    metrics/user_metrics.cc
    metrics/user_metrics.h
    metrics/user_metrics_action.h
    native_library.cc
    native_library.h
    no_destructor.h
    notreached.cc
    notreached.h
    observer_list.h
    observer_list_internal.cc
    observer_list_internal.h
    observer_list_threadsafe.cc
    observer_list_threadsafe.h
    observer_list_types.cc
    observer_list_types.h
    one_shot_event.cc
    one_shot_event.h
    parameter_pack.h
    path_service.cc
    path_service.h
    pending_task.cc
    pending_task.h
    pickle.cc
    pickle.h
    power_monitor/moving_average.cc
    power_monitor/moving_average.h
    power_monitor/power_monitor.cc
    power_monitor/power_monitor.h
    power_monitor/power_monitor_source.cc
    power_monitor/power_monitor_source.h
    power_monitor/power_observer.h
    process/environment_internal.cc
    process/environment_internal.h
    process/kill.cc
    process/kill.h
    process/launch.cc
    process/launch.h
    process/memory.cc
    process/memory.h
    process/process.h
    process/process_handle.cc
    process/process_handle.h
    process/process_info.h
    process/process_iterator.cc
    process/process_iterator.h
    process/process_metrics.cc
    process/process_metrics.h
    process/process_metrics_iocounters.h
    profiler/arm_cfi_table.cc
    profiler/arm_cfi_table.h
    profiler/frame.cc
    profiler/frame.h
    profiler/metadata_recorder.cc
    profiler/metadata_recorder.h
    profiler/module_cache.cc
    profiler/module_cache.h
    profiler/native_unwinder.h
    profiler/profile_builder.h
    profiler/register_context.h
    profiler/sample_metadata.cc
    profiler/sample_metadata.h
    profiler/sampling_profiler_thread_token.cc
    profiler/sampling_profiler_thread_token.h
    profiler/stack_buffer.cc
    profiler/stack_buffer.h
    profiler/stack_copier.cc
    profiler/stack_copier.h
    profiler/stack_copier_suspend.cc
    profiler/stack_copier_suspend.h
    profiler/stack_sampler.cc
    profiler/stack_sampler.h
    profiler/stack_sampler_impl.cc
    profiler/stack_sampler_impl.h
    profiler/stack_sampling_profiler.cc
    profiler/stack_sampling_profiler.h
    profiler/suspendable_thread_delegate.h
    profiler/thread_delegate.h
    profiler/unwinder.cc
    profiler/unwinder.h
    rand_util.cc
    rand_util.h
    ranges/algorithm.h
    ranges/functional.h
    ranges/ranges.h
    run_loop.cc
    run_loop.h
    sampling_heap_profiler/lock_free_address_hash_set.cc
    sampling_heap_profiler/lock_free_address_hash_set.h
    scoped_clear_last_error.h
    scoped_environment_variable_override.cc
    scoped_environment_variable_override.h
    scoped_generic.h
    scoped_multi_source_observation.h
    scoped_native_library.cc
    scoped_native_library.h
    scoped_observation.h
    sequence_checker.cc
    sequence_checker.h
    sequence_checker_impl.cc
    sequence_checker_impl.h
    sequence_token.cc
    sequence_token.h
    stl_util.h
    strings/abseil_string_conversions.cc
    strings/abseil_string_conversions.h
    strings/abseil_string_number_conversions.cc
    strings/abseil_string_number_conversions.h
    strings/escape.cc
    strings/escape.h
    strings/latin1_string_conversions.cc
    strings/latin1_string_conversions.h
    strings/pattern.cc
    strings/pattern.h
    strings/safe_sprintf.cc
    strings/safe_sprintf.h
    strings/strcat.cc
    strings/strcat.h
    strings/strcat_internal.h
    strings/string_number_conversions.cc
    strings/string_number_conversions.h
    strings/string_number_conversions_internal.h
    strings/string_piece.cc
    strings/string_piece.h
    strings/string_piece_forward.h
    strings/string_split.cc
    strings/string_split.h
    strings/string_split_internal.h
    strings/string_tokenizer.h
    strings/string_util.cc
    strings/string_util.h
    strings/string_util_constants.cc
    strings/string_util_internal.h
    strings/stringize_macros.h
    strings/stringprintf.cc
    strings/stringprintf.h
    strings/sys_string_conversions.h
    strings/utf_offset_string_conversions.cc
    strings/utf_offset_string_conversions.h
    strings/utf_string_conversion_utils.cc
    strings/utf_string_conversion_utils.h
    strings/utf_string_conversions.cc
    strings/utf_string_conversions.h
    substring_set_matcher/string_pattern.cc
    substring_set_matcher/string_pattern.h
    substring_set_matcher/substring_set_matcher.cc
    substring_set_matcher/substring_set_matcher.h
    supports_user_data.cc
    supports_user_data.h
    sync_socket.cc
    sync_socket.h
    synchronization/atomic_flag.cc
    synchronization/atomic_flag.h
    synchronization/condition_variable.h
    synchronization/lock.cc
    synchronization/lock.h
    synchronization/lock_impl.h
    synchronization/waitable_event.h
    synchronization/waitable_event_watcher.h
    sys_byteorder.h
    syslog_logging.cc
    syslog_logging.h
    system/sys_info.cc
    system/sys_info.h
    system/sys_info_internal.h
    system/system_monitor.cc
    system/system_monitor.h
    task/bind_post_task.h
    task/bind_post_task_internal.h
    task/cancelable_task_tracker.cc
    task/cancelable_task_tracker.h
    task/common/checked_lock.h
    task/common/checked_lock_impl.cc
    task/common/checked_lock_impl.h
    task/common/operations_controller.cc
    task/common/operations_controller.h
    task/common/scoped_defer_task_posting.cc
    task/common/scoped_defer_task_posting.h
    task/common/task_annotator.cc
    task/common/task_annotator.h
    task/current_thread.cc
    task/current_thread.h
    task/default_delayed_task_handle_delegate.cc
    task/default_delayed_task_handle_delegate.h
    task/deferred_sequenced_task_runner.cc
    task/deferred_sequenced_task_runner.h
    task/delay_policy.h
    task/delayed_task_handle.cc
    task/delayed_task_handle.h
    task/lazy_thread_pool_task_runner.cc
    task/lazy_thread_pool_task_runner.h
    task/post_job.cc
    task/post_job.h
    task/post_task_and_reply_with_result_internal.h
    task/scoped_set_task_priority_for_current_thread.cc
    task/scoped_set_task_priority_for_current_thread.h
    task/sequence_manager/associated_thread_id.cc
    task/sequence_manager/associated_thread_id.h
    task/sequence_manager/atomic_flag_set.cc
    task/sequence_manager/atomic_flag_set.h
    task/sequence_manager/delayed_task_handle_delegate.cc
    task/sequence_manager/delayed_task_handle_delegate.h
    task/sequence_manager/enqueue_order.h
    task/sequence_manager/enqueue_order_generator.cc
    task/sequence_manager/enqueue_order_generator.h
    task/sequence_manager/fence.cc
    task/sequence_manager/fence.h
    task/sequence_manager/lazily_deallocated_deque.h
    task/sequence_manager/lazy_now.cc
    task/sequence_manager/lazy_now.h
    task/sequence_manager/sequence_manager.cc
    task/sequence_manager/sequence_manager.h
    task/sequence_manager/sequence_manager_impl.cc
    task/sequence_manager/sequence_manager_impl.h
    task/sequence_manager/sequenced_task_source.cc
    task/sequence_manager/sequenced_task_source.h
    task/sequence_manager/task_order.cc
    task/sequence_manager/task_order.h
    task/sequence_manager/task_queue.cc
    task/sequence_manager/task_queue.h
    task/sequence_manager/task_queue_impl.cc
    task/sequence_manager/task_queue_impl.h
    task/sequence_manager/task_queue_selector.cc
    task/sequence_manager/task_queue_selector.h
    task/sequence_manager/task_queue_selector_logic.h
    task/sequence_manager/task_time_observer.h
    task/sequence_manager/tasks.cc
    task/sequence_manager/tasks.h
    task/sequence_manager/thread_controller.cc
    task/sequence_manager/thread_controller.h
    task/sequence_manager/thread_controller_impl.cc
    task/sequence_manager/thread_controller_impl.h
    task/sequence_manager/thread_controller_power_monitor.cc
    task/sequence_manager/thread_controller_power_monitor.h
    task/sequence_manager/thread_controller_with_message_pump_impl.cc
    task/sequence_manager/thread_controller_with_message_pump_impl.h
    task/sequence_manager/time_domain.cc
    task/sequence_manager/time_domain.h
    task/sequence_manager/wake_up_queue.cc
    task/sequence_manager/wake_up_queue.h
    task/sequence_manager/work_deduplicator.cc
    task/sequence_manager/work_deduplicator.h
    task/sequence_manager/work_queue.cc
    task/sequence_manager/work_queue.h
    task/sequence_manager/work_queue_sets.cc
    task/sequence_manager/work_queue_sets.h
    task/sequenced_task_runner.cc
    task/sequenced_task_runner.h
    task/sequenced_task_runner_helpers.h
    task/simple_task_executor.cc
    task/simple_task_executor.h
    task/single_thread_task_executor.cc
    task/single_thread_task_executor.h
    task/single_thread_task_runner.h
    task/single_thread_task_runner_thread_mode.h
    task/task_executor.cc
    task/task_executor.h
    task/task_features.cc
    task/task_features.h
    task/task_observer.h
    task/task_runner.cc
    task/task_runner.h
    task/task_runner_util.h
    task/task_traits.cc
    task/task_traits.h
    task/task_traits_extension.h
    task/thread_pool.cc
    task/thread_pool.h
    task/thread_pool/delayed_task_manager.cc
    task/thread_pool/delayed_task_manager.h
    task/thread_pool/environment_config.cc
    task/thread_pool/environment_config.h
    task/thread_pool/initialization_util.cc
    task/thread_pool/initialization_util.h
    task/thread_pool/job_task_source.cc
    task/thread_pool/job_task_source.h
    task/thread_pool/pooled_parallel_task_runner.cc
    task/thread_pool/pooled_parallel_task_runner.h
    task/thread_pool/pooled_sequenced_task_runner.cc
    task/thread_pool/pooled_sequenced_task_runner.h
    task/thread_pool/pooled_single_thread_task_runner_manager.cc
    task/thread_pool/pooled_single_thread_task_runner_manager.h
    task/thread_pool/pooled_task_runner_delegate.cc
    task/thread_pool/pooled_task_runner_delegate.h
    task/thread_pool/priority_queue.cc
    task/thread_pool/priority_queue.h
    task/thread_pool/sequence.cc
    task/thread_pool/sequence.h
    task/thread_pool/service_thread.cc
    task/thread_pool/service_thread.h
    task/thread_pool/task.cc
    task/thread_pool/task.h
    task/thread_pool/task_source.cc
    task/thread_pool/task_source.h
    task/thread_pool/task_source_sort_key.cc
    task/thread_pool/task_source_sort_key.h
    task/thread_pool/task_tracker.cc
    task/thread_pool/task_tracker.h
    task/thread_pool/thread_group.cc
    task/thread_pool/thread_group.h
    task/thread_pool/thread_group_impl.cc
    task/thread_pool/thread_group_impl.h
    task/thread_pool/thread_group_native.cc
    task/thread_pool/thread_group_native.h
    task/thread_pool/thread_pool_impl.cc
    task/thread_pool/thread_pool_impl.h
    task/thread_pool/thread_pool_instance.cc
    task/thread_pool/thread_pool_instance.h
    task/thread_pool/tracked_ref.h
    task/thread_pool/worker_thread.cc
    task/thread_pool/worker_thread.h
    task/thread_pool/worker_thread_observer.h
    task/thread_pool/worker_thread_stack.cc
    task/thread_pool/worker_thread_stack.h
    task/updateable_sequenced_task_runner.h
    template_util.h
    third_party/cityhash/city.cc
    third_party/cityhash/city.h
    third_party/cityhash_v103/src/city_v103.cc
    third_party/cityhash_v103/src/city_v103.h
    third_party/icu/icu_utf.h
    third_party/nspr/prtime.cc
    third_party/nspr/prtime.h
    third_party/superfasthash/superfasthash.c
    third_party/double_conversion/double-conversion/string-to-double.cc
    third_party/double_conversion/double-conversion/double-to-string.cc
    third_party/double_conversion/double-conversion/strtod.cc
    third_party/double_conversion/double-conversion/fast-dtoa.cc
    third_party/double_conversion/double-conversion/fixed-dtoa.cc
    third_party/double_conversion/double-conversion/bignum-dtoa.cc
    third_party/double_conversion/double-conversion/cached-powers.cc
    third_party/double_conversion/double-conversion/bignum.cc
    thread_annotations.h
    threading/hang_watcher.cc
    threading/hang_watcher.h
    threading/platform_thread.cc
    threading/platform_thread.h
    threading/platform_thread_ref.cc
    threading/platform_thread_ref.h
    threading/post_task_and_reply_impl.cc
    threading/post_task_and_reply_impl.h
    threading/scoped_blocking_call.cc
    threading/scoped_blocking_call.h
    threading/scoped_blocking_call_internal.cc
    threading/scoped_blocking_call_internal.h
    threading/scoped_thread_priority.cc
    threading/scoped_thread_priority.h
    threading/sequence_bound.h
    threading/sequence_local_storage_map.cc
    threading/sequence_local_storage_map.h
    threading/sequence_local_storage_slot.cc
    threading/sequence_local_storage_slot.h
    threading/sequenced_task_runner_handle.cc
    threading/sequenced_task_runner_handle.h
    threading/simple_thread.cc
    threading/simple_thread.h
    threading/thread.cc
    threading/thread.h
    threading/thread_checker.cc
    threading/thread_checker.h
    threading/thread_checker_impl.cc
    threading/thread_checker_impl.h
    threading/thread_collision_warner.cc
    threading/thread_collision_warner.h
    threading/thread_id_name_manager.cc
    threading/thread_id_name_manager.h
    threading/thread_local.h
    threading/thread_local_internal.h
    threading/thread_local_storage.cc
    threading/thread_local_storage.h
    threading/thread_restrictions.cc
    threading/thread_restrictions.h
    threading/thread_task_runner_handle.cc
    threading/thread_task_runner_handle.h
    threading/threading_features.h
    threading/watchdog.cc
    threading/watchdog.h
    time/clock.cc
    time/clock.h
    time/default_clock.cc
    time/default_clock.h
    time/default_tick_clock.cc
    time/default_tick_clock.h
    time/tick_clock.cc
    time/tick_clock.h
    time/time.cc
    time/time.h
    time/time_delta_from_string.cc
    time/time_delta_from_string.h
    time/time_override.cc
    time/time_override.h
    time/time_to_iso8601.cc
    time/time_to_iso8601.h
    timer/elapsed_timer.cc
    timer/elapsed_timer.h
    timer/hi_res_timer_manager.h
    timer/lap_timer.cc
    timer/lap_timer.h
    timer/timer.cc
    timer/timer.h
    timer/wall_clock_timer.cc
    timer/wall_clock_timer.h
    token.cc
    token.h
    trace_event/base_tracing.h
    trace_event/base_tracing_forward.h
    trace_event/common/trace_event_common.h
    trace_event/heap_profiler_allocation_context.cc
    trace_event/heap_profiler_allocation_context.h
    trace_event/heap_profiler_allocation_context_tracker.cc
    trace_event/heap_profiler_allocation_context_tracker.h
    trace_event/memory_allocator_dump_guid.cc
    trace_event/memory_allocator_dump_guid.h
    trace_event/trace_id_helper.cc
    trace_event/trace_id_helper.h
    trace_event/trace_event_stub.cc
    traits_bag.h
    tuple.h
    types/expected.h
    types/expected_internal.h
    types/id_type.h
    types/pass_key.h
    types/strong_alias.h
    types/token_type.h
    unguessable_token.cc
    unguessable_token.h
    value_iterators.cc
    value_iterators.h
    values.cc
    values.h
    version.cc
    version.h
    vlog.cc
    vlog.h
    allocator/partition_allocator/page_allocator.cc
    allocator/partition_allocator/oom.cc
    allocator/partition_allocator/oom_callback.cc
    allocator/partition_allocator/spinning_mutex.cc
    allocator/partition_allocator/address_space_randomization.cc
    allocator/partition_allocator/random.cc
    allocator/partition_allocator/partition_alloc_base/rand_util.cc
    allocator/partition_allocator/partition_alloc_base/rand_util_win.cc
)

# 平台专用文件
if(WIN32)
  nice_target_sources(xchromebase "base/"
    PRIVATE
    base_paths_win.cc # WIN32
    base_paths_win.h # WIN32
    base_paths.cc # WIN32
    debug/close_handle_hook_win.cc # WIN32
    debug/close_handle_hook_win.h # WIN32
    debug/debugger_win.cc # WIN32
    debug/gdi_debug_util_win.cc # WIN32
    debug/gdi_debug_util_win.h # WIN32
    debug/invalid_access_win.cc # WIN32
    debug/invalid_access_win.h # WIN32
    debug/stack_trace.cc # WIN32
    debug/stack_trace_win.cc # WIN32
    enterprise_util_win.cc # WIN32
    file_version_info_win.cc # WIN32
    file_version_info_win.h # WIN32
    files/file_enumerator_win.cc # WIN32
    files/file_path_watcher_win.cc # WIN32
    files/file_util_win.cc # WIN32
    files/file_win.cc # WIN32
    files/memory_mapped_file_win.cc # WIN32
    logging_win.cc # WIN32
    logging_win.h # WIN32
    memory/page_size_win.cc # WIN32
    memory/platform_shared_memory_mapper_win.cc # WIN32
    memory/platform_shared_memory_region_win.cc # WIN32
    message_loop/message_pump_win.cc # WIN32
    message_loop/message_pump_win.h # WIN32
    native_library_win.cc # WIN32
    power_monitor/power_monitor_device_source_win.cc # WIN32
    power_monitor/speed_limit_observer_win.cc # WIN32
    power_monitor/speed_limit_observer_win.h # WIN32
    process/kill_win.cc # WIN32
    process/launch_win.cc # WIN32
    process/memory_win.cc # WIN32
    process/process_handle_win.cc # WIN32
    process/process_info_win.cc # WIN32
    process/process_iterator_win.cc # WIN32
    process/process_metrics_win.cc # WIN32
    process/process_win.cc # WIN32
    profiler/module_cache_win.cc # WIN32
    profiler/native_unwinder_win.cc # WIN32
    profiler/native_unwinder_win.h # WIN32
    profiler/stack_sampler_win.cc # WIN32
    profiler/suspendable_thread_delegate_win.cc # WIN32
    profiler/suspendable_thread_delegate_win.h # WIN32
    profiler/win32_stack_frame_unwinder.cc # WIN32
    profiler/win32_stack_frame_unwinder.h # WIN32
    rand_util_win.cc # WIN32
    scoped_clear_last_error_win.cc # WIN32
    strings/strcat_win.cc # WIN32
    strings/strcat_win.h # WIN32
    strings/string_number_conversions_win.cc # WIN32
    strings/string_number_conversions_win.h # WIN32
    strings/string_split_win.cc # WIN32
    strings/string_split_win.h # WIN32
    strings/string_util_win.cc # WIN32
    strings/string_util_win.h # WIN32
    strings/sys_string_conversions_win.cc # WIN32
    sync_socket_win.cc # WIN32
    synchronization/condition_variable_win.cc # WIN32
    synchronization/lock_impl_win.cc # WIN32
    synchronization/waitable_event_watcher_win.cc # WIN32
    synchronization/waitable_event_win.cc # WIN32
    system/sys_info_win.cc # WIN32
    task/thread_pool/thread_group_native_win.cc # WIN32
    task/thread_pool/thread_group_native_win.h # WIN32
    threading/platform_thread_win.cc # WIN32
    threading/platform_thread_win.h # WIN32
    threading/thread_local_storage_win.cc # WIN32
    time/time_win.cc # WIN32
    timer/hi_res_timer_manager_win.cc # WIN32
    win/pe_image.cc # WIN32
    win/access_token.cc # WIN32
    win/access_token.h # WIN32
    win/async_operation.h # WIN32
    win/atl.h # WIN32
    win/atl_throw.cc # WIN32
    win/atl_throw.h # WIN32
    win/com_init_balancer.cc # WIN32
    win/com_init_balancer.h # WIN32
    win/com_init_check_hook.cc # WIN32
    win/com_init_check_hook.h # WIN32
    win/com_init_util.cc # WIN32
    win/com_init_util.h # WIN32
    win/core_winrt_util.cc # WIN32
    win/core_winrt_util.h # WIN32
    win/current_module.h # WIN32
    win/default_apps_util.cc # WIN32
    win/default_apps_util.h # WIN32
    win/embedded_i18n/language_selector.cc # WIN32
    win/embedded_i18n/language_selector.h # WIN32
    win/enum_variant.cc # WIN32
    win/enum_variant.h # WIN32
    win/event_trace_consumer.h # WIN32
    win/event_trace_controller.cc # WIN32
    win/event_trace_controller.h # WIN32
    win/event_trace_provider.cc # WIN32
    win/event_trace_provider.h # WIN32
    win/hstring_compare.cc # WIN32
    win/hstring_compare.h # WIN32
    win/hstring_reference.cc # WIN32
    win/hstring_reference.h # WIN32
    win/i18n.cc # WIN32
    win/i18n.h # WIN32
    win/iat_patch_function.cc # WIN32
    win/iat_patch_function.h # WIN32
    win/map.h # WIN32
    win/message_window.cc # WIN32
    win/message_window.h # WIN32
    win/nt_status.cc # WIN32
    win/nt_status.h # WIN32
    win/object_watcher.cc # WIN32
    win/object_watcher.h # WIN32
    win/patch_util.cc # WIN32
    win/patch_util.h # WIN32
    win/pe_image_reader.cc # WIN32
    win/pe_image_reader.h # WIN32
    win/post_async_results.h # WIN32
    win/process_startup_helper.cc # WIN32
    win/process_startup_helper.h # WIN32
    win/propvarutil.h # WIN32
    win/reference.h # WIN32
    win/registry.cc # WIN32
    win/registry.h # WIN32
    win/resource_util.cc # WIN32
    win/resource_util.h # WIN32
    win/scoped_bstr.cc # WIN32
    win/scoped_bstr.h # WIN32
    win/scoped_co_mem.h # WIN32
    win/scoped_com_initializer.cc # WIN32
    win/scoped_com_initializer.h # WIN32
    win/scoped_gdi_object.h # WIN32
    win/scoped_handle.cc # WIN32
    win/scoped_handle.h # WIN32
    win/scoped_handle_verifier.cc # WIN32
    win/scoped_handle_verifier.h # WIN32
    win/scoped_hdc.h # WIN32
    win/scoped_hglobal.h # WIN32
    win/scoped_hstring.cc # WIN32
    win/scoped_hstring.h # WIN32
    win/scoped_localalloc.h # WIN32
    win/scoped_process_information.cc # WIN32
    win/scoped_process_information.h # WIN32
    win/scoped_propvariant.h # WIN32
    win/scoped_safearray.h # WIN32
    win/scoped_select_object.h # WIN32
    win/scoped_variant.cc # WIN32
    win/scoped_variant.h # WIN32
    win/scoped_windows_thread_environment.h # WIN32
    win/scoped_winrt_initializer.cc # WIN32
    win/scoped_winrt_initializer.h # WIN32
    win/security_util.cc # WIN32
    win/security_util.h # WIN32
    win/shlwapi.h # WIN32
    win/shortcut.cc # WIN32
    win/shortcut.h # WIN32
    win/sid.cc # WIN32
    win/sid.h # WIN32
    win/sphelper.h # WIN32
    win/startup_information.cc # WIN32
    win/startup_information.h # WIN32
    win/static_constants.h # WIN32
    win/static_constants.cc # WIN32
    win/variant_util.h # WIN32
    win/variant_vector.cc # WIN32
    win/variant_vector.h # WIN32
    win/vector.cc # WIN32
    win/vector.h # WIN32
    win/win_handle_types_list.inc # WIN32
    win/win_util.cc # WIN32
    win/win_util.h # WIN32
    win/wincrypt_shim.h # WIN32
    win/windows_defines.inc # WIN32
    win/windows_h_disallowed.h # WIN32
    win/windows_types.h # WIN32
    win/windows_undefines.inc # WIN32
    win/windows_version.cc # WIN32
    win/windows_version.h # WIN32
    win/windowsx_shim.h # WIN32
    win/winrt_foundation_helpers.h # WIN32
    win/winrt_storage_util.cc # WIN32
    win/winrt_storage_util.h # WIN32
    win/wmi.cc # WIN32
    win/wmi.h # WIN32
    win/wrapped_window_proc.cc # WIN32
    win/wrapped_window_proc.h # WIN32  
  )

  # 受 USE_ALLOCATOR_SHIM 控制的 Windows 文件
  if(USE_ALLOCATOR_SHIM)
    nice_target_sources(xchromebase "base/"
      PRIVATE
      allocator/allocator_shim.cc # WIN32, USE_ALLOCATOR_SHIM
      allocator/allocator_shim.h # WIN32, USE_ALLOCATOR_SHIM
      allocator/allocator_shim_internals.h # WIN32, USE_ALLOCATOR_SHIM
      allocator/allocator_shim_override_ucrt_symbols_win.h # WIN32, USE_ALLOCATOR_SHIM
      allocator/winheap_stubs_win.cc # WIN32, USE_ALLOCATOR_SHIM
      allocator/winheap_stubs_win.h # WIN32, USE_ALLOCATOR_SHIM
    )
    if(USE_PARTITION_ALLOC)
      nice_target_sources(xchromebase "base/"
        PRIVATE
        allocator/allocator_shim_default_dispatch_to_partition_alloc.cc # WIN32, USE_ALLOCATOR_SHIM, USE_PARTITION_ALLOC
        allocator/allocator_shim_default_dispatch_to_partition_alloc.h # WIN32, USE_ALLOCATOR_SHIM, USE_PARTITION_ALLOC
      )
    endif()
    if(USE_ALLOCATOR STREQUAL "none")
      nice_target_sources(xchromebase "base/"
        PRIVATE
        allocator/allocator_shim_default_dispatch_to_winheap.cc # WIN32, USE_ALLOCATOR_SHIM, USE_ALLOCATOR==none
      )
    endif()
  endif()

  # 受 USE_CLANG_PROFILING 控制的 Windows 文件
  if(USE_CLANG_PROFILING)
    nice_target_sources(xchromebase "base/"
      PRIVATE
      test/clang_profiling.cc # WIN32, USE_CLANG_PROFILING
      test/clang_profiling.h # WIN32, USE_CLANG_PROFILING
    )
  endif()

  # 受 ENABLE_CET_SHADOW_STACK 控制的 Windows 文件
  if(ENABLE_CET_SHADOW_STACK)
    nice_target_sources(xchromebase "base/"
      PRIVATE
      win/cet_shadow_stack_unittest.cc # WIN32, ENABLE_CET_SHADOW_STACK
    )
  endif()

endif()

#target_include_directories(xchromebase PUBLIC
#    ${CMAKE_CURRENT_SOURCE_DIR}/path/include
#    # 添加其他需要的头文件目录...
#)

#target_compile_definitions(mylib PRIVATE
#    SOME_DEFINITION=1
#)
