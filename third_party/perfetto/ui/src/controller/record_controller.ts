// Copyright (C) 2018 The Android Open Source Project
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

import {Message, Method, rpc, RPCImplCallback} from 'protobufjs';

import {
  base64Encode,
} from '../base/string_utils';
import {Actions} from '../common/actions';
import {TRACE_SUFFIX} from '../common/constants';
import {
  AndroidLogConfig,
  AndroidLogId,
  AndroidPowerConfig,
  BufferConfig,
  ChromeConfig,
  ConsumerPort,
  DataSourceConfig,
  FtraceConfig,
  HeapprofdConfig,
  JavaContinuousDumpConfig,
  JavaHprofConfig,
  NativeContinuousDumpConfig,
  ProcessStatsConfig,
  SysStatsConfig,
  TraceConfig,
} from '../common/protos';
import {MeminfoCounters, VmstatCounters} from '../common/protos';
import {
  AdbRecordingTarget,
  isAdbTarget,
  isAndroidP,
  isChromeTarget,
  isCrOSTarget,
  isLinuxTarget,
  isTargetOsAtLeast,
  RecordingTarget
} from '../common/state';
import {publishBufferUsage, publishTrackData} from '../frontend/publish';

import {AdbOverWebUsb} from './adb';
import {AdbConsumerPort} from './adb_shell_controller';
import {AdbSocketConsumerPort} from './adb_socket_controller';
import {ChromeExtensionConsumerPort} from './chrome_proxy_record_controller';
import {
  ConsumerPortResponse,
  GetTraceStatsResponse,
  isDisableTracingResponse,
  isEnableTracingResponse,
  isFreeBuffersResponse,
  isGetTraceStatsResponse,
  isReadBuffersResponse,
} from './consumer_port_types';
import {Controller} from './controller';
import {App, globals} from './globals';
import {RecordConfig} from './record_config_types';
import {Consumer, RpcConsumerPort} from './record_controller_interfaces';

type RPCImplMethod = (Method|rpc.ServiceMethod<Message<{}>, Message<{}>>);

export function genConfigProto(
    uiCfg: RecordConfig, target: RecordingTarget): Uint8Array {
  return TraceConfig.encode(genConfig(uiCfg, target)).finish();
}

export function genConfig(
    uiCfg: RecordConfig, target: RecordingTarget): TraceConfig {
  const protoCfg = new TraceConfig();
  protoCfg.durationMs = uiCfg.durationMs;

  // Auxiliary buffer for slow-rate events.
  // Set to 1/8th of the main buffer size, with reasonable limits.
  let slowBufSizeKb = uiCfg.bufferSizeMb * (1024 / 8);
  slowBufSizeKb = Math.min(slowBufSizeKb, 2 * 1024);
  slowBufSizeKb = Math.max(slowBufSizeKb, 256);

  // Main buffer for ftrace and other high-freq events.
  const fastBufSizeKb = uiCfg.bufferSizeMb * 1024 - slowBufSizeKb;

  protoCfg.buffers.push(new BufferConfig());
  protoCfg.buffers.push(new BufferConfig());
  protoCfg.buffers[1].sizeKb = slowBufSizeKb;
  protoCfg.buffers[0].sizeKb = fastBufSizeKb;

  if (uiCfg.mode === 'STOP_WHEN_FULL') {
    protoCfg.buffers[0].fillPolicy = BufferConfig.FillPolicy.DISCARD;
    protoCfg.buffers[1].fillPolicy = BufferConfig.FillPolicy.DISCARD;
  } else {
    protoCfg.buffers[0].fillPolicy = BufferConfig.FillPolicy.RING_BUFFER;
    protoCfg.buffers[1].fillPolicy = BufferConfig.FillPolicy.RING_BUFFER;
    protoCfg.flushPeriodMs = 30000;
    if (uiCfg.mode === 'LONG_TRACE') {
      protoCfg.writeIntoFile = true;
      protoCfg.fileWritePeriodMs = uiCfg.fileWritePeriodMs;
      protoCfg.maxFileSizeBytes = uiCfg.maxFileSizeMb * 1e6;
    }

    // Clear incremental state every 5 seconds when tracing into a ring buffer.
    const incStateConfig = new TraceConfig.IncrementalStateConfig();
    incStateConfig.clearPeriodMs = 5000;
    protoCfg.incrementalStateConfig = incStateConfig;
  }

  const ftraceEvents = new Set<string>(uiCfg.ftrace ? uiCfg.ftraceEvents : []);
  const atraceCats = new Set<string>(uiCfg.atrace ? uiCfg.atraceCats : []);
  const atraceApps = new Set<string>();
  const chromeCategories = new Set<string>();
  uiCfg.chromeCategoriesSelected.forEach(it => chromeCategories.add(it));
  uiCfg.chromeHighOverheadCategoriesSelected.forEach(
      it => chromeCategories.add(it));

  let procThreadAssociationPolling = false;
  let procThreadAssociationFtrace = false;
  let trackInitialOomScore = false;

  if (uiCfg.cpuSched) {
    procThreadAssociationPolling = true;
    procThreadAssociationFtrace = true;
    uiCfg.ftrace = true;
    if (isTargetOsAtLeast(target, 'S')) {
      uiCfg.symbolizeKsyms = true;
    }
    ftraceEvents.add('sched/sched_switch');
    ftraceEvents.add('power/suspend_resume');
    ftraceEvents.add('sched/sched_wakeup');
    ftraceEvents.add('sched/sched_wakeup_new');
    ftraceEvents.add('sched/sched_waking');
    ftraceEvents.add('power/suspend_resume');
  }

  if (uiCfg.cpuFreq) {
    ftraceEvents.add('power/cpu_frequency');
    ftraceEvents.add('power/cpu_idle');
    ftraceEvents.add('power/suspend_resume');
  }

  if (uiCfg.gpuFreq) {
    ftraceEvents.add('power/gpu_frequency');
  }

  if (uiCfg.gpuMemTotal) {
    ftraceEvents.add('gpu_mem/gpu_mem_total');

    if (!isChromeTarget(target) || isCrOSTarget(target)) {
      const ds = new TraceConfig.DataSource();
      ds.config = new DataSourceConfig();
      ds.config.name = 'android.gpu.memory';
      protoCfg.dataSources.push(ds);
    }
  }

  if (uiCfg.cpuSyscall) {
    ftraceEvents.add('raw_syscalls/sys_enter');
    ftraceEvents.add('raw_syscalls/sys_exit');
  }

  if (uiCfg.batteryDrain) {
    const ds = new TraceConfig.DataSource();
    ds.config = new DataSourceConfig();
    if (isCrOSTarget(target) || isLinuxTarget(target)) {
      ds.config.name = 'linux.sysfs_power';
    } else {
      ds.config.name = 'android.power';
      ds.config.androidPowerConfig = new AndroidPowerConfig();
      ds.config.androidPowerConfig.batteryPollMs = uiCfg.batteryDrainPollMs;
      ds.config.androidPowerConfig.batteryCounters = [
        AndroidPowerConfig.BatteryCounters.BATTERY_COUNTER_CAPACITY_PERCENT,
        AndroidPowerConfig.BatteryCounters.BATTERY_COUNTER_CHARGE,
        AndroidPowerConfig.BatteryCounters.BATTERY_COUNTER_CURRENT,
      ];
      ds.config.androidPowerConfig.collectPowerRails = true;
    }
    if (!isChromeTarget(target) || isCrOSTarget(target)) {
      protoCfg.dataSources.push(ds);
    }
  }

  if (uiCfg.boardSensors) {
    ftraceEvents.add('regulator/regulator_set_voltage');
    ftraceEvents.add('regulator/regulator_set_voltage_complete');
    ftraceEvents.add('power/clock_enable');
    ftraceEvents.add('power/clock_disable');
    ftraceEvents.add('power/clock_set_rate');
    ftraceEvents.add('power/suspend_resume');
  }

  let sysStatsCfg: SysStatsConfig|undefined = undefined;

  if (uiCfg.cpuCoarse) {
    sysStatsCfg = new SysStatsConfig();
    sysStatsCfg.statPeriodMs = uiCfg.cpuCoarsePollMs;
    sysStatsCfg.statCounters = [
      SysStatsConfig.StatCounters.STAT_CPU_TIMES,
      SysStatsConfig.StatCounters.STAT_FORK_COUNT,
    ];
  }

  if (uiCfg.memHiFreq) {
    procThreadAssociationPolling = true;
    procThreadAssociationFtrace = true;
    ftraceEvents.add('mm_event/mm_event_record');
    ftraceEvents.add('kmem/rss_stat');
    ftraceEvents.add('ion/ion_stat');
    ftraceEvents.add('dmabuf_heap/dma_heap_stat');
    ftraceEvents.add('kmem/ion_heap_grow');
    ftraceEvents.add('kmem/ion_heap_shrink');
  }

  if (procThreadAssociationFtrace) {
    ftraceEvents.add('sched/sched_process_exit');
    ftraceEvents.add('sched/sched_process_free');
    ftraceEvents.add('task/task_newtask');
    ftraceEvents.add('task/task_rename');
  }

  if (uiCfg.meminfo) {
    if (sysStatsCfg === undefined) sysStatsCfg = new SysStatsConfig();
    sysStatsCfg.meminfoPeriodMs = uiCfg.meminfoPeriodMs;
    sysStatsCfg.meminfoCounters = uiCfg.meminfoCounters.map(name => {
      // tslint:disable-next-line no-any
      return MeminfoCounters[name as any as number] as any as number;
    });
  }

  if (uiCfg.vmstat) {
    if (sysStatsCfg === undefined) sysStatsCfg = new SysStatsConfig();
    sysStatsCfg.vmstatPeriodMs = uiCfg.vmstatPeriodMs;
    sysStatsCfg.vmstatCounters = uiCfg.vmstatCounters.map(name => {
      // tslint:disable-next-line no-any
      return VmstatCounters[name as any as number] as any as number;
    });
  }

  if (uiCfg.memLmk) {
    // For in-kernel LMK (roughly older devices until Go and Pixel 3).
    ftraceEvents.add('lowmemorykiller/lowmemory_kill');

    // For userspace LMKd (newer devices).
    // 'lmkd' is not really required because the code in lmkd.c emits events
    // with ATRACE_TAG_ALWAYS. We need something just to ensure that the final
    // config will enable atrace userspace events.
    atraceApps.add('lmkd');

    ftraceEvents.add('oom/oom_score_adj_update');
    procThreadAssociationPolling = true;
    trackInitialOomScore = true;
  }

  let heapprofd: HeapprofdConfig|undefined = undefined;
  if (uiCfg.heapProfiling) {
    // TODO(hjd): Check or inform user if buffer size are too small.
    const cfg = new HeapprofdConfig();
    cfg.samplingIntervalBytes = uiCfg.hpSamplingIntervalBytes;
    if (uiCfg.hpSharedMemoryBuffer >= 8192 &&
        uiCfg.hpSharedMemoryBuffer % 4096 === 0) {
      cfg.shmemSizeBytes = uiCfg.hpSharedMemoryBuffer;
    }
    for (const value of uiCfg.hpProcesses.split('\n')) {
      if (value === '') {
        // Ignore empty lines
      } else if (isNaN(+value)) {
        cfg.processCmdline.push(value);
      } else {
        cfg.pid.push(+value);
      }
    }
    if (uiCfg.hpContinuousDumpsInterval > 0) {
      const cdc = cfg.continuousDumpConfig = new NativeContinuousDumpConfig();
      cdc.dumpIntervalMs = uiCfg.hpContinuousDumpsInterval;
      if (uiCfg.hpContinuousDumpsPhase > 0) {
        cdc.dumpPhaseMs = uiCfg.hpContinuousDumpsPhase;
      }
    }
    cfg.blockClient = uiCfg.hpBlockClient;
    if (uiCfg.hpAllHeaps) {
      cfg.allHeaps = true;
    }
    heapprofd = cfg;
  }

  let javaHprof: JavaHprofConfig|undefined = undefined;
  if (uiCfg.javaHeapDump) {
    const cfg = new JavaHprofConfig();
    for (const value of uiCfg.jpProcesses.split('\n')) {
      if (value === '') {
        // Ignore empty lines
      } else if (isNaN(+value)) {
        cfg.processCmdline.push(value);
      } else {
        cfg.pid.push(+value);
      }
    }
    if (uiCfg.jpContinuousDumpsInterval > 0) {
      const cdc = cfg.continuousDumpConfig = new JavaContinuousDumpConfig();
      cdc.dumpIntervalMs = uiCfg.jpContinuousDumpsInterval;
      if (uiCfg.hpContinuousDumpsPhase > 0) {
        cdc.dumpPhaseMs = uiCfg.jpContinuousDumpsPhase;
      }
    }
    javaHprof = cfg;
  }

  if (uiCfg.procStats || procThreadAssociationPolling || trackInitialOomScore) {
    const ds = new TraceConfig.DataSource();
    ds.config = new DataSourceConfig();
    ds.config.targetBuffer = 1;  // Aux
    ds.config.name = 'linux.process_stats';
    ds.config.processStatsConfig = new ProcessStatsConfig();
    if (uiCfg.procStats) {
      ds.config.processStatsConfig.procStatsPollMs = uiCfg.procStatsPeriodMs;
    }
    if (procThreadAssociationPolling || trackInitialOomScore) {
      ds.config.processStatsConfig.scanAllProcessesOnStart = true;
    }
    if (!isChromeTarget(target) || isCrOSTarget(target)) {
      protoCfg.dataSources.push(ds);
    }
  }

  if (uiCfg.androidLogs) {
    const ds = new TraceConfig.DataSource();
    ds.config = new DataSourceConfig();
    ds.config.name = 'android.log';
    ds.config.androidLogConfig = new AndroidLogConfig();
    ds.config.androidLogConfig.logIds = uiCfg.androidLogBuffers.map(name => {
      // tslint:disable-next-line no-any
      return AndroidLogId[name as any as number] as any as number;
    });

    if (!isChromeTarget(target) || isCrOSTarget(target)) {
      protoCfg.dataSources.push(ds);
    }
  }

  if (uiCfg.androidFrameTimeline) {
    const ds = new TraceConfig.DataSource();
    ds.config = new DataSourceConfig();
    ds.config.name = 'android.surfaceflinger.frametimeline';
    if (!isChromeTarget(target) || isCrOSTarget(target)) {
      protoCfg.dataSources.push(ds);
    }
  }

  if (uiCfg.chromeLogs) {
    chromeCategories.add('log');
  }

  if (uiCfg.taskScheduling) {
    chromeCategories.add('toplevel');
    chromeCategories.add('sequence_manager');
    chromeCategories.add('disabled-by-default-toplevel.flow');
  }

  if (uiCfg.ipcFlows) {
    chromeCategories.add('toplevel');
    chromeCategories.add('disabled-by-default-ipc.flow');
    chromeCategories.add('mojom');
  }

  if (uiCfg.jsExecution) {
    chromeCategories.add('toplevel');
    chromeCategories.add('v8');
  }

  if (uiCfg.webContentRendering) {
    chromeCategories.add('toplevel');
    chromeCategories.add('blink');
    chromeCategories.add('cc');
    chromeCategories.add('gpu');
  }

  if (uiCfg.uiRendering) {
    chromeCategories.add('toplevel');
    chromeCategories.add('cc');
    chromeCategories.add('gpu');
    chromeCategories.add('viz');
    chromeCategories.add('ui');
    chromeCategories.add('views');
  }

  if (uiCfg.inputEvents) {
    chromeCategories.add('toplevel');
    chromeCategories.add('benchmark');
    chromeCategories.add('evdev');
    chromeCategories.add('input');
    chromeCategories.add('disabled-by-default-toplevel.flow');
  }

  if (uiCfg.navigationAndLoading) {
    chromeCategories.add('loading');
    chromeCategories.add('net');
    chromeCategories.add('netlog');
    chromeCategories.add('navigation');
    chromeCategories.add('browser');
  }

  if (chromeCategories.size !== 0) {
    let chromeRecordMode;
    if (uiCfg.mode === 'STOP_WHEN_FULL') {
      chromeRecordMode = 'record-until-full';
    } else {
      chromeRecordMode = 'record-continuously';
    }
    const configStruct = {
      record_mode: chromeRecordMode,
      included_categories: [...chromeCategories.values()],
      memory_dump_config: {},
    };
    if (chromeCategories.has('disabled-by-default-memory-infra')) {
      configStruct.memory_dump_config = {
        allowed_dump_modes: ['background', 'light', 'detailed'],
        triggers: [{
          min_time_between_dumps_ms: 10000,
          mode: 'detailed',
          type: 'periodic_interval',
        }],
      };
    }
    const traceConfigJson = JSON.stringify(configStruct);

    const traceDs = new TraceConfig.DataSource();
    traceDs.config = new DataSourceConfig();
    traceDs.config.name = 'org.chromium.trace_event';
    traceDs.config.chromeConfig = new ChromeConfig();
    traceDs.config.chromeConfig.traceConfig = traceConfigJson;
    protoCfg.dataSources.push(traceDs);


    const metadataDs = new TraceConfig.DataSource();
    metadataDs.config = new DataSourceConfig();
    metadataDs.config.name = 'org.chromium.trace_metadata';
    metadataDs.config.chromeConfig = new ChromeConfig();
    metadataDs.config.chromeConfig.traceConfig = traceConfigJson;
    protoCfg.dataSources.push(metadataDs);

    if (chromeCategories.has('disabled-by-default-memory-infra')) {
      const memoryDs = new TraceConfig.DataSource();
      memoryDs.config = new DataSourceConfig();
      memoryDs.config.name = 'org.chromium.memory_instrumentation';
      memoryDs.config.chromeConfig = new ChromeConfig();
      memoryDs.config.chromeConfig.traceConfig = traceConfigJson;
      protoCfg.dataSources.push(memoryDs);

      const HeapProfDs = new TraceConfig.DataSource();
      HeapProfDs.config = new DataSourceConfig();
      HeapProfDs.config.name = 'org.chromium.native_heap_profiler';
      HeapProfDs.config.chromeConfig = new ChromeConfig();
      HeapProfDs.config.chromeConfig.traceConfig = traceConfigJson;
      protoCfg.dataSources.push(HeapProfDs);
    }

    if (chromeCategories.has('disabled-by-default-cpu_profiler') ||
        chromeCategories.has('disabled-by-default-cpu_profiler.debug')) {
      const dataSource = new TraceConfig.DataSource();
      dataSource.config = new DataSourceConfig();
      dataSource.config.name = 'org.chromium.sampler_profiler';
      dataSource.config.chromeConfig = new ChromeConfig();
      dataSource.config.chromeConfig.traceConfig = traceConfigJson;
      protoCfg.dataSources.push(dataSource);
    }
  }

  // Keep these last. The stages above can enrich them.

  if (sysStatsCfg !== undefined &&
      (!isChromeTarget(target) || isCrOSTarget(target))) {
    const ds = new TraceConfig.DataSource();
    ds.config = new DataSourceConfig();
    ds.config.name = 'linux.sys_stats';
    ds.config.sysStatsConfig = sysStatsCfg;
    protoCfg.dataSources.push(ds);
  }

  if (heapprofd !== undefined &&
      (!isChromeTarget(target) || isCrOSTarget(target))) {
    const ds = new TraceConfig.DataSource();
    ds.config = new DataSourceConfig();
    ds.config.targetBuffer = 0;
    ds.config.name = 'android.heapprofd';
    ds.config.heapprofdConfig = heapprofd;
    protoCfg.dataSources.push(ds);
  }

  if (javaHprof !== undefined &&
      (!isChromeTarget(target) || isCrOSTarget(target))) {
    const ds = new TraceConfig.DataSource();
    ds.config = new DataSourceConfig();
    ds.config.targetBuffer = 0;
    ds.config.name = 'android.java_hprof';
    ds.config.javaHprofConfig = javaHprof;
    protoCfg.dataSources.push(ds);
  }

  // TODO(octaviant): move all this logic in a follow up CL.
  if (uiCfg.ftrace || uiCfg.atrace || ftraceEvents.size > 0 ||
      atraceCats.size > 0 || atraceApps.size > 0) {
    const ds = new TraceConfig.DataSource();
    ds.config = new DataSourceConfig();
    ds.config.name = 'linux.ftrace';
    ds.config.ftraceConfig = new FtraceConfig();
    // Override the advanced ftrace parameters only if the user has ticked the
    // "Advanced ftrace config" tab.
    if (uiCfg.ftrace) {
      if (uiCfg.ftraceBufferSizeKb) {
        ds.config.ftraceConfig.bufferSizeKb = uiCfg.ftraceBufferSizeKb;
      }
      if (uiCfg.ftraceDrainPeriodMs) {
        ds.config.ftraceConfig.drainPeriodMs = uiCfg.ftraceDrainPeriodMs;
      }
      if (uiCfg.symbolizeKsyms) {
        ds.config.ftraceConfig.symbolizeKsyms = true;
        ftraceEvents.add('sched/sched_blocked_reason');
      }
      for (const line of uiCfg.ftraceExtraEvents.split('\n')) {
        if (line.trim().length > 0) ftraceEvents.add(line.trim());
      }
    }

    if (uiCfg.atrace) {
      if (uiCfg.allAtraceApps) {
        atraceApps.clear();
        atraceApps.add('*');
      } else {
        for (const line of uiCfg.atraceApps.split('\n')) {
          if (line.trim().length > 0) atraceApps.add(line.trim());
        }
      }
    }

    if (atraceCats.size > 0 || atraceApps.size > 0) {
      ftraceEvents.add('ftrace/print');
    }

    let ftraceEventsArray: string[] = [];
    if (isAndroidP(target)) {
      for (const ftraceEvent of ftraceEvents) {
        // On P, we don't support groups so strip all group names from ftrace
        // events.
        const groupAndName = ftraceEvent.split('/');
        if (groupAndName.length !== 2) {
          ftraceEventsArray.push(ftraceEvent);
          continue;
        }
        // Filter out any wildcard event groups which was not supported
        // before Q.
        if (groupAndName[1] === '*') {
          continue;
        }
        ftraceEventsArray.push(groupAndName[1]);
      }
    } else {
      ftraceEventsArray = Array.from(ftraceEvents);
    }

    ds.config.ftraceConfig.ftraceEvents = ftraceEventsArray;
    ds.config.ftraceConfig.atraceCategories = Array.from(atraceCats);
    ds.config.ftraceConfig.atraceApps = Array.from(atraceApps);

    if (isTargetOsAtLeast(target, 'S')) {
      const compact = new FtraceConfig.CompactSchedConfig();
      compact.enabled = true;
      ds.config.ftraceConfig.compactSched = compact;
    }

    if (!isChromeTarget(target) || isCrOSTarget(target)) {
      protoCfg.dataSources.push(ds);
    }
  }

  return protoCfg;
}

export function toPbtxt(configBuffer: Uint8Array): string {
  const msg = TraceConfig.decode(configBuffer);
  const json = msg.toJSON();
  function snakeCase(s: string): string {
    return s.replace(/[A-Z]/g, c => '_' + c.toLowerCase());
  }
  // With the ahead of time compiled protos we can't seem to tell which
  // fields are enums.
  function isEnum(value: string): boolean {
    return value.startsWith('MEMINFO_') || value.startsWith('VMSTAT_') ||
        value.startsWith('STAT_') || value.startsWith('LID_') ||
        value.startsWith('BATTERY_COUNTER_') || value === 'DISCARD' ||
        value === 'RING_BUFFER';
  }
  // Since javascript doesn't have 64 bit numbers when converting protos to
  // json the proto library encodes them as strings. This is lossy since
  // we can't tell which strings that look like numbers are actually strings
  // and which are actually numbers. Ideally we would reflect on the proto
  // definition somehow but for now we just hard code keys which have this
  // problem in the config.
  function is64BitNumber(key: string): boolean {
    return [
      'maxFileSizeBytes',
      'samplingIntervalBytes',
      'shmemSizeBytes',
      'pid'
    ].includes(key);
  }
  function* message(msg: {}, indent: number): IterableIterator<string> {
    for (const [key, value] of Object.entries(msg)) {
      const isRepeated = Array.isArray(value);
      const isNested = typeof value === 'object' && !isRepeated;
      for (const entry of (isRepeated ? value as Array<{}> : [value])) {
        yield ' '.repeat(indent) + `${snakeCase(key)}${isNested ? '' : ':'} `;
        if (typeof entry === 'string') {
          if (isEnum(entry) || is64BitNumber(key)) {
            yield entry;
          } else {
            yield `"${entry.replace(new RegExp('"', 'g'), '\\"')}"`;
          }
        } else if (typeof entry === 'number') {
          yield entry.toString();
        } else if (typeof entry === 'boolean') {
          yield entry.toString();
        } else if (typeof entry === 'object' && entry !== null) {
          yield '{\n';
          yield* message(entry, indent + 4);
          yield ' '.repeat(indent) + '}';
        } else {
          throw new Error(`Record proto entry "${entry}" with unexpected type ${
              typeof entry}`);
        }
        yield '\n';
      }
    }
  }
  return [...message(json, 0)].join('');
}

export class RecordController extends Controller<'main'> implements Consumer {
  private app: App;
  private config: RecordConfig|null = null;
  private readonly extensionPort: MessagePort;
  private recordingInProgress = false;
  private consumerPort: ConsumerPort;
  private traceBuffer: Uint8Array[] = [];
  private bufferUpdateInterval: ReturnType<typeof setTimeout>|undefined;
  private adb = new AdbOverWebUsb();
  private recordedTraceSuffix = TRACE_SUFFIX;
  private fetchedCategories = false;

  // We have a different controller for each targetOS. The correct one will be
  // created when needed, and stored here. When the key is a string, it is the
  // serial of the target (used for android devices). When the key is a single
  // char, it is the 'targetOS'
  private controllerPromises = new Map<string, Promise<RpcConsumerPort>>();

  constructor(args: {app: App, extensionPort: MessagePort}) {
    super('main');
    this.app = args.app;
    this.consumerPort = ConsumerPort.create(this.rpcImpl.bind(this));
    this.extensionPort = args.extensionPort;
  }

  run() {
    // TODO(eseckler): Use ConsumerPort's QueryServiceState instead
    // of posting a custom extension message to retrieve the category list.
    if (this.app.state.fetchChromeCategories && !this.fetchedCategories) {
      this.fetchedCategories = true;
      if (this.app.state.extensionInstalled) {
        this.extensionPort.postMessage({method: 'GetCategories'});
      }
      globals.dispatch(Actions.setFetchChromeCategories({fetch: false}));
    }
    if (this.app.state.recordConfig === this.config &&
        this.app.state.recordingInProgress === this.recordingInProgress) {
      return;
    }
    this.config = this.app.state.recordConfig;

    const configProto =
        genConfigProto(this.config, this.app.state.recordingTarget);
    const configProtoText = toPbtxt(configProto);
    const configProtoBase64 = base64Encode(configProto);
    const commandline = `
      echo '${configProtoBase64}' |
      base64 --decode |
      adb shell "perfetto -c - -o /data/misc/perfetto-traces/trace" &&
      adb pull /data/misc/perfetto-traces/trace /tmp/trace
    `;
    const traceConfig = genConfig(this.config, this.app.state.recordingTarget);
    // TODO(hjd): This should not be TrackData after we unify the stores.
    publishTrackData({
      id: 'config',
      data: {
        commandline,
        pbBase64: configProtoBase64,
        pbtxt: configProtoText,
        traceConfig
      }
    });

    // If the recordingInProgress boolean state is different, it means that we
    // have to start or stop recording a trace.
    if (this.app.state.recordingInProgress === this.recordingInProgress) return;
    this.recordingInProgress = this.app.state.recordingInProgress;

    if (this.recordingInProgress) {
      this.startRecordTrace(traceConfig);
    } else {
      this.stopRecordTrace();
    }
  }

  startRecordTrace(traceConfig: TraceConfig) {
    this.scheduleBufferUpdateRequests();
    this.traceBuffer = [];
    this.consumerPort.enableTracing({traceConfig});
  }

  stopRecordTrace() {
    if (this.bufferUpdateInterval) clearInterval(this.bufferUpdateInterval);
    this.consumerPort.disableTracing({});
  }

  scheduleBufferUpdateRequests() {
    if (this.bufferUpdateInterval) clearInterval(this.bufferUpdateInterval);
    this.bufferUpdateInterval = setInterval(() => {
      this.consumerPort.getTraceStats({});
    }, 200);
  }

  readBuffers() {
    this.consumerPort.readBuffers({});
  }

  onConsumerPortResponse(data: ConsumerPortResponse) {
    if (data === undefined) return;
    if (isReadBuffersResponse(data)) {
      if (!data.slices || data.slices.length === 0) return;
      // TODO(nicomazz): handle this as intended by consumer_port.proto.
      console.assert(data.slices.length === 1);
      if (data.slices[0].data) this.traceBuffer.push(data.slices[0].data);
      // The line underneath is 'misusing' the format ReadBuffersResponse.
      // The boolean field 'lastSliceForPacket' is used as 'lastPacketInTrace'.
      // See http://shortn/_53WB8A1aIr.
      if (data.slices[0].lastSliceForPacket) this.onTraceComplete();
    } else if (isEnableTracingResponse(data)) {
      this.readBuffers();
    } else if (isGetTraceStatsResponse(data)) {
      const percentage = this.getBufferUsagePercentage(data);
      if (percentage) {
        publishBufferUsage({percentage});
      }
    } else if (isFreeBuffersResponse(data)) {
      // No action required.
    } else if (isDisableTracingResponse(data)) {
      // No action required.
    } else {
      console.error('Unrecognized consumer port response:', data);
    }
  }

  onTraceComplete() {
    this.consumerPort.freeBuffers({});
    globals.dispatch(Actions.setRecordingStatus({status: undefined}));
    if (globals.state.recordingCancelled) {
      globals.dispatch(
          Actions.setLastRecordingError({error: 'Recording cancelled.'}));
      this.traceBuffer = [];
      return;
    }
    const trace = this.generateTrace();
    globals.dispatch(Actions.openTraceFromBuffer({
      title: 'Recorded trace',
      buffer: trace.buffer,
      fileName: `recorded_trace${this.recordedTraceSuffix}`,
    }));
    this.traceBuffer = [];
  }

  // TODO(nicomazz): stream each chunk into the trace processor, instead of
  // creating a big long trace.
  generateTrace() {
    let traceLen = 0;
    for (const chunk of this.traceBuffer) traceLen += chunk.length;
    const completeTrace = new Uint8Array(traceLen);
    let written = 0;
    for (const chunk of this.traceBuffer) {
      completeTrace.set(chunk, written);
      written += chunk.length;
    }
    return completeTrace;
  }

  getBufferUsagePercentage(data: GetTraceStatsResponse): number {
    if (!data.traceStats || !data.traceStats.bufferStats) return 0.0;
    let maximumUsage = 0;
    for (const buffer of data.traceStats.bufferStats) {
      const used = buffer.bytesWritten as number;
      const total = buffer.bufferSize as number;
      maximumUsage = Math.max(maximumUsage, used / total);
    }
    return maximumUsage;
  }

  onError(message: string) {
    // TODO(octaviant): b/204998302
    console.error('Error in record controller: ', message);
    globals.dispatch(
        Actions.setLastRecordingError({error: message.substr(0, 150)}));
    globals.dispatch(Actions.stopRecording({}));
  }

  onStatus(message: string) {
    globals.dispatch(Actions.setRecordingStatus({status: message}));
  }

  // Depending on the recording target, different implementation of the
  // consumer_port will be used.
  // - Chrome target: This forwards the messages that have to be sent
  // to the extension to the frontend. This is necessary because this
  // controller is running in a separate worker, that can't directly send
  // messages to the extension.
  // - Android device target: WebUSB is used to communicate using the adb
  // protocol. Actually, there is no full consumer_port implementation, but
  // only the support to start tracing and fetch the file.
  async getTargetController(target: RecordingTarget): Promise<RpcConsumerPort> {
    const identifier = RecordController.getTargetIdentifier(target);

    // The reason why caching the target 'record controller' Promise is that
    // multiple rcp calls can happen while we are trying to understand if an
    // android device has a socket connection available or not.
    const precedentPromise = this.controllerPromises.get(identifier);
    if (precedentPromise) return precedentPromise;

    const controllerPromise =
        new Promise<RpcConsumerPort>(async (resolve, _) => {
          let controller: RpcConsumerPort|undefined = undefined;
          if (isChromeTarget(target)) {
            controller =
                new ChromeExtensionConsumerPort(this.extensionPort, this);
          } else if (isAdbTarget(target)) {
            this.onStatus(`Please allow USB debugging on device.
                 If you press cancel, reload the page.`);
            const socketAccess = await this.hasSocketAccess(target);

            controller = socketAccess ?
                new AdbSocketConsumerPort(this.adb, this) :
                new AdbConsumerPort(this.adb, this);
          } else {
            throw Error(`No device connected`);
          }

          if (!controller) throw Error(`Unknown target: ${target}`);
          resolve(controller);
        });

    this.controllerPromises.set(identifier, controllerPromise);
    return controllerPromise;
  }

  private static getTargetIdentifier(target: RecordingTarget): string {
    return isAdbTarget(target) ? target.serial : target.os;
  }

  private async hasSocketAccess(target: AdbRecordingTarget) {
    const devices = await navigator.usb.getDevices();
    const device = devices.find(d => d.serialNumber === target.serial);
    console.assert(device);
    if (!device) return Promise.resolve(false);
    return AdbSocketConsumerPort.hasSocketAccess(device, this.adb);
  }

  private async rpcImpl(
      method: RPCImplMethod, requestData: Uint8Array,
      _callback: RPCImplCallback) {
    try {
      const state = this.app.state;
      // TODO(hjd): This is a bit weird. We implicity send each RPC message to
      // whichever target is currently selected (creating that target if needed)
      // it would be nicer if the setup/teardown was more explicit.
      const target = await this.getTargetController(state.recordingTarget);
      this.recordedTraceSuffix = target.getRecordedTraceSuffix();
      target.handleCommand(method.name, requestData);
    } catch (e) {
      console.error(`error invoking ${method}: ${e.message}`);
    }
  }
}
