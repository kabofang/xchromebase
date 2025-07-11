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

import {Draft} from 'immer';

import {assertExists, assertTrue} from '../base/logging';
import {RecordConfig} from '../controller/record_config_types';
import {globals} from '../frontend/globals';
import {columnKey} from '../frontend/pivot_table_redux';
import {TableColumn} from '../frontend/pivot_table_redux_query_generator';
import {ACTUAL_FRAMES_SLICE_TRACK_KIND} from '../tracks/actual_frames/common';
import {ASYNC_SLICE_TRACK_KIND} from '../tracks/async_slices/common';
import {COUNTER_TRACK_KIND} from '../tracks/counter/common';
import {DEBUG_SLICE_TRACK_KIND} from '../tracks/debug_slices/common';
import {
  EXPECTED_FRAMES_SLICE_TRACK_KIND
} from '../tracks/expected_frames/common';
import {HEAP_PROFILE_TRACK_KIND} from '../tracks/heap_profile/common';
import {
  PERF_SAMPLES_PROFILE_TRACK_KIND
} from '../tracks/perf_samples_profile/common';
import {
  PROCESS_SCHEDULING_TRACK_KIND
} from '../tracks/process_scheduling/common';
import {PROCESS_SUMMARY_TRACK} from '../tracks/process_summary/common';

import {randomColor} from './colorizer';
import {createEmptyState} from './empty_state';
import {DEFAULT_VIEWING_OPTION, PERF_SAMPLES_KEY} from './flamegraph_util';
import {
  AggregationAttrs,
  PivotAttrs,
  SubQueryAttrs,
  TableAttrs
} from './pivot_table_common';
import {
  AdbRecordingTarget,
  Area,
  CallsiteInfo,
  EngineMode,
  FlamegraphStateViewingOption,
  LoadedConfig,
  LogsPagination,
  NewEngineMode,
  OmniboxState,
  PivotTableReduxResult,
  RecordingTarget,
  SCROLLING_TRACK_GROUP,
  SortDirection,
  State,
  Status,
  TraceTime,
  TrackKindPriority,
  TrackState,
  VisibleState,
} from './state';
import {toNs} from './time';

type StateDraft = Draft<State>;

const highPriorityTrackOrder = [
  PROCESS_SCHEDULING_TRACK_KIND,
  PROCESS_SUMMARY_TRACK,
  EXPECTED_FRAMES_SLICE_TRACK_KIND,
  ACTUAL_FRAMES_SLICE_TRACK_KIND
];

const lowPriorityTrackOrder = [
  PERF_SAMPLES_PROFILE_TRACK_KIND,
  HEAP_PROFILE_TRACK_KIND,
  COUNTER_TRACK_KIND,
  ASYNC_SLICE_TRACK_KIND
];

export interface AddTrackArgs {
  id?: string;
  engineId: string;
  kind: string;
  name: string;
  labels?: string[];
  trackKindPriority: TrackKindPriority;
  trackGroup?: string;
  config: {};
}

export interface PostedTrace {
  buffer: ArrayBuffer;
  title: string;
  fileName?: string;
  url?: string;
  uuid?: string;
  localOnly?: boolean;
}

function clearTraceState(state: StateDraft) {
  const nextId = state.nextId;
  const recordConfig = state.recordConfig;
  const recordingTarget = state.recordingTarget;
  const fetchChromeCategories = state.fetchChromeCategories;
  const extensionInstalled = state.extensionInstalled;
  const availableAdbDevices = state.availableAdbDevices;
  const chromeCategories = state.chromeCategories;
  const newEngineMode = state.newEngineMode;

  Object.assign(state, createEmptyState());
  state.nextId = nextId;
  state.recordConfig = recordConfig;
  state.recordingTarget = recordingTarget;
  state.fetchChromeCategories = fetchChromeCategories;
  state.extensionInstalled = extensionInstalled;
  state.availableAdbDevices = availableAdbDevices;
  state.chromeCategories = chromeCategories;
  state.newEngineMode = newEngineMode;
}

function rank(ts: TrackState): number[] {
  const hpRank = rankIndex(ts.kind, highPriorityTrackOrder);
  const lpRank = rankIndex(ts.kind, lowPriorityTrackOrder);
  // TODO(hjd): Create sortBy object on TrackState to avoid this cast.
  const tid = (ts.config as {tid?: number}).tid || 0;
  return [hpRank, ts.trackKindPriority.valueOf(), lpRank, tid];
}

function rankIndex<T>(element: T, array: T[]): number {
  const index = array.indexOf(element);
  if (index === -1) return array.length;
  return index;
}

function generateNextId(draft: StateDraft): string {
  const nextId = String(Number(draft.nextId) + 1);
  draft.nextId = nextId;
  return nextId;
}

export const StateActions = {

  openTraceFromFile(state: StateDraft, args: {file: File}): void {
    clearTraceState(state);
    const id = generateNextId(state);
    state.currentEngineId = id;
    state.engines[id] = {
      id,
      ready: false,
      source: {type: 'FILE', file: args.file},
    };
  },

  openTraceFromBuffer(state: StateDraft, args: PostedTrace): void {
    clearTraceState(state);
    const id = generateNextId(state);
    state.currentEngineId = id;
    state.engines[id] = {
      id,
      ready: false,
      source: {type: 'ARRAY_BUFFER', ...args},
    };
  },

  openTraceFromUrl(state: StateDraft, args: {url: string}): void {
    clearTraceState(state);
    const id = generateNextId(state);
    state.currentEngineId = id;
    state.engines[id] = {
      id,
      ready: false,
      source: {type: 'URL', url: args.url},
    };
  },

  openTraceFromHttpRpc(state: StateDraft, _args: {}): void {
    clearTraceState(state);
    const id = generateNextId(state);
    state.currentEngineId = id;
    state.engines[id] = {
      id,
      ready: false,
      source: {type: 'HTTP_RPC'},
    };
  },

  setTraceUuid(state: StateDraft, args: {traceUuid: string}) {
    state.traceUuid = args.traceUuid;
  },

  fillUiTrackIdByTraceTrackId(
      state: StateDraft, trackState: TrackState, uiTrackId: string) {
    const config = trackState.config as {trackId: number};
    if (config.trackId !== undefined) {
      state.uiTrackIdByTraceTrackId[config.trackId] = uiTrackId;
      return;
    }

    const multiple = trackState.config as {trackIds: number[]};
    if (multiple.trackIds !== undefined) {
      for (const trackId of multiple.trackIds) {
        state.uiTrackIdByTraceTrackId[trackId] = uiTrackId;
      }
    }
  },

  addTracks(state: StateDraft, args: {tracks: AddTrackArgs[]}) {
    args.tracks.forEach(track => {
      const id = track.id === undefined ? generateNextId(state) : track.id;
      track.id = id;
      state.tracks[id] = track as TrackState;
      this.fillUiTrackIdByTraceTrackId(state, track as TrackState, id);
      if (track.trackGroup === SCROLLING_TRACK_GROUP) {
        state.scrollingTracks.push(id);
      } else if (track.trackGroup !== undefined) {
        assertExists(state.trackGroups[track.trackGroup]).tracks.push(id);
      }
    });
  },

  addTrack(state: StateDraft, args: {
    id?: string; engineId: string; kind: string; name: string;
    trackGroup?: string; config: {}; trackKindPriority: TrackKindPriority;
  }): void {
    const id = args.id !== undefined ? args.id : generateNextId(state);
    state.tracks[id] = {
      id,
      engineId: args.engineId,
      kind: args.kind,
      name: args.name,
      trackKindPriority: args.trackKindPriority,
      trackGroup: args.trackGroup,
      config: args.config,
    };
    this.fillUiTrackIdByTraceTrackId(state, state.tracks[id], id);
    if (args.trackGroup === SCROLLING_TRACK_GROUP) {
      state.scrollingTracks.push(id);
    } else if (args.trackGroup !== undefined) {
      assertExists(state.trackGroups[args.trackGroup]).tracks.push(id);
    }
  },

  addTrackGroup(
      state: StateDraft,
      // Define ID in action so a track group can be referred to without running
      // the reducer.
      args: {
        engineId: string; name: string; id: string; summaryTrackId: string;
        collapsed: boolean;
      }): void {
    state.trackGroups[args.id] = {
      engineId: args.engineId,
      name: args.name,
      id: args.id,
      collapsed: args.collapsed,
      tracks: [args.summaryTrackId],
    };
  },

  addDebugTrack(state: StateDraft, args: {engineId: string, name: string}):
      void {
        if (state.debugTrackId !== undefined) return;
        const trackId = generateNextId(state);
        state.debugTrackId = trackId;
        this.addTrack(state, {
          id: trackId,
          engineId: args.engineId,
          kind: DEBUG_SLICE_TRACK_KIND,
          name: args.name,
          trackKindPriority: TrackKindPriority.ORDINARY,
          trackGroup: SCROLLING_TRACK_GROUP,
          config: {
            maxDepth: 1,
          }
        });
        this.toggleTrackPinned(state, {trackId});
      },

  removeDebugTrack(state: StateDraft, _: {}): void {
    const {debugTrackId} = state;
    if (debugTrackId === undefined) return;
    delete state.tracks[debugTrackId];
    state.scrollingTracks =
        state.scrollingTracks.filter(id => id !== debugTrackId);
    state.pinnedTracks = state.pinnedTracks.filter(id => id !== debugTrackId);
    state.debugTrackId = undefined;
  },

  sortThreadTracks(state: StateDraft, _: {}): void {
    // Use a numeric collator so threads are sorted as T1, T2, ..., T10, T11,
    // rather than T1, T10, T11, ..., T2, T20, T21 .
    const coll = new Intl.Collator([], {sensitivity: 'base', numeric: true});
    for (const group of Object.values(state.trackGroups)) {
      group.tracks.sort((a: string, b: string) => {
        const aRank = rank(state.tracks[a]);
        const bRank = rank(state.tracks[b]);
        for (let i = 0; i < aRank.length; i++) {
          if (aRank[i] !== bRank[i]) return aRank[i] - bRank[i];
        }

        const aName = state.tracks[a].name.toLocaleLowerCase();
        const bName = state.tracks[b].name.toLocaleLowerCase();
        return coll.compare(aName, bName);
      });
    }
  },

  updateAggregateSorting(
      state: StateDraft, args: {id: string, column: string}) {
    let prefs = state.aggregatePreferences[args.id];
    if (!prefs) {
      prefs = {id: args.id};
      state.aggregatePreferences[args.id] = prefs;
    }

    if (!prefs.sorting || prefs.sorting.column !== args.column) {
      // No sorting set for current column.
      state.aggregatePreferences[args.id].sorting = {
        column: args.column,
        direction: 'DESC'
      };
    } else if (prefs.sorting.direction === 'DESC') {
      // Toggle the direction if the column is currently sorted.
      state.aggregatePreferences[args.id].sorting = {
        column: args.column,
        direction: 'ASC'
      };
    } else {
      // If direction is currently 'ASC' toggle to no sorting.
      state.aggregatePreferences[args.id].sorting = undefined;
    }
  },

  setVisibleTracks(state: StateDraft, args: {tracks: string[]}) {
    state.visibleTracks = args.tracks;
  },

  updateTrackConfig(state: StateDraft, args: {id: string, config: {}}) {
    if (state.tracks[args.id] === undefined) return;
    state.tracks[args.id].config = args.config;
  },

  executeQuery(
      state: StateDraft,
      args: {queryId: string; query: string, engineId?: string}): void {
    state.queries[args.queryId] = {
      id: args.queryId,
      query: args.query,
      engineId: args.engineId
    };
  },

  deleteQuery(state: StateDraft, args: {queryId: string}): void {
    delete state.queries[args.queryId];
  },

  moveTrack(
      state: StateDraft,
      args: {srcId: string; op: 'before' | 'after', dstId: string}): void {
    const moveWithinTrackList = (trackList: string[]) => {
      const newList: string[] = [];
      for (let i = 0; i < trackList.length; i++) {
        const curTrackId = trackList[i];
        if (curTrackId === args.dstId && args.op === 'before') {
          newList.push(args.srcId);
        }
        if (curTrackId !== args.srcId) {
          newList.push(curTrackId);
        }
        if (curTrackId === args.dstId && args.op === 'after') {
          newList.push(args.srcId);
        }
      }
      trackList.splice(0);
      newList.forEach(x => {
        trackList.push(x);
      });
    };

    moveWithinTrackList(state.pinnedTracks);
    moveWithinTrackList(state.scrollingTracks);
  },

  toggleTrackPinned(state: StateDraft, args: {trackId: string}): void {
    const id = args.trackId;
    const isPinned = state.pinnedTracks.includes(id);
    const trackGroup = assertExists(state.tracks[id]).trackGroup;

    if (isPinned) {
      state.pinnedTracks.splice(state.pinnedTracks.indexOf(id), 1);
      if (trackGroup === SCROLLING_TRACK_GROUP) {
        state.scrollingTracks.unshift(id);
      }
    } else {
      if (trackGroup === SCROLLING_TRACK_GROUP) {
        state.scrollingTracks.splice(state.scrollingTracks.indexOf(id), 1);
      }
      state.pinnedTracks.push(id);
    }
  },

  toggleTrackGroupCollapsed(state: StateDraft, args: {trackGroupId: string}):
      void {
        const id = args.trackGroupId;
        const trackGroup = assertExists(state.trackGroups[id]);
        trackGroup.collapsed = !trackGroup.collapsed;
      },

  requestTrackReload(state: StateDraft, _: {}) {
    if (state.lastTrackReloadRequest) {
      state.lastTrackReloadRequest++;
    } else {
      state.lastTrackReloadRequest = 1;
    }
  },

  // TODO(hjd): engine.ready should be a published thing. If it's part
  // of the state it interacts badly with permalinks.
  setEngineReady(
      state: StateDraft,
      args: {engineId: string; ready: boolean, mode: EngineMode}): void {
    const engine = state.engines[args.engineId];
    if (engine === undefined) {
      return;
    }
    engine.ready = args.ready;
    engine.mode = args.mode;
  },

  setNewEngineMode(state: StateDraft, args: {mode: NewEngineMode}): void {
    state.newEngineMode = args.mode;
  },

  // Marks all engines matching the given |mode| as failed.
  setEngineFailed(state: StateDraft, args: {mode: EngineMode; failure: string}):
      void {
        for (const engine of Object.values(state.engines)) {
          if (engine.mode === args.mode) engine.failed = args.failure;
        }
      },

  createPermalink(state: StateDraft, args: {isRecordingConfig: boolean}): void {
    state.permalink = {
      requestId: generateNextId(state),
      hash: undefined,
      isRecordingConfig: args.isRecordingConfig
    };
  },

  setPermalink(state: StateDraft, args: {requestId: string; hash: string}):
      void {
        // Drop any links for old requests.
        if (state.permalink.requestId !== args.requestId) return;
        state.permalink = args;
      },

  loadPermalink(state: StateDraft, args: {hash: string}): void {
    state.permalink = {requestId: generateNextId(state), hash: args.hash};
  },

  clearPermalink(state: StateDraft, _: {}): void {
    state.permalink = {};
  },

  setTraceTime(state: StateDraft, args: TraceTime): void {
    state.traceTime = args;
  },

  updateStatus(state: StateDraft, args: Status): void {
    state.status = args;
  },

  // TODO(hjd): Remove setState - it causes problems due to reuse of ids.
  setState(state: StateDraft, args: {newState: State}): void {
    for (const key of Object.keys(state)) {
      // tslint:disable-next-line no-any
      delete (state as any)[key];
    }
    for (const key of Object.keys(args.newState)) {
      // tslint:disable-next-line no-any
      (state as any)[key] = (args.newState as any)[key];
    }

    // If we're loading from a permalink then none of the engines can
    // possibly be ready:
    for (const engine of Object.values(state.engines)) {
      engine.ready = false;
    }
  },

  setRecordConfig(
      state: StateDraft,
      args: {config: RecordConfig, configType?: LoadedConfig}): void {
    state.recordConfig = args.config;
    state.lastLoadedConfig = args.configType || {type: 'NONE'};
  },

  selectNote(state: StateDraft, args: {id: string}): void {
    if (args.id) {
      state.currentSelection = {
        kind: 'NOTE',
        id: args.id
      };
    }
  },

  addNote(state: StateDraft, args: {timestamp: number, color: string}): void {
    const id = generateNextId(state);
    state.notes[id] = {
      noteType: 'DEFAULT',
      id,
      timestamp: args.timestamp,
      color: args.color,
      text: '',
    };
    this.selectNote(state, {id});
  },

  markCurrentArea(
      state: StateDraft, args: {color: string, persistent: boolean}):
      void {
        if (state.currentSelection === null ||
            state.currentSelection.kind !== 'AREA') {
          return;
        }
        const id = args.persistent ? generateNextId(state) : '0';
        const color = args.persistent ? args.color : '#344596';
        state.notes[id] = {
          noteType: 'AREA',
          id,
          areaId: state.currentSelection.areaId,
          color,
          text: '',
        };
        state.currentSelection.noteId = id;
      },

  toggleMarkCurrentArea(state: StateDraft, args: {persistent: boolean}) {
    const selection = state.currentSelection;
    if (selection != null && selection.kind === 'AREA' &&
        selection.noteId !== undefined) {
      this.removeNote(state, {id: selection.noteId});
    } else {
      const color = randomColor();
      this.markCurrentArea(state, {color, persistent: args.persistent});
    }
  },

  markArea(state: StateDraft, args: {area: Area, persistent: boolean}): void {
    const areaId = generateNextId(state);
    assertTrue(args.area.endSec >= args.area.startSec);
    state.areas[areaId] = {
      id: areaId,
      startSec: args.area.startSec,
      endSec: args.area.endSec,
      tracks: args.area.tracks
    };
    const noteId = args.persistent ? generateNextId(state) : '0';
    const color = args.persistent ? randomColor() : '#344596';
    state.notes[noteId] = {
      noteType: 'AREA',
      id: noteId,
      areaId,
      color,
      text: '',
    };
  },

  changeNoteColor(state: StateDraft, args: {id: string, newColor: string}):
      void {
        const note = state.notes[args.id];
        if (note === undefined) return;
        note.color = args.newColor;
      },

  changeNoteText(state: StateDraft, args: {id: string, newText: string}): void {
    const note = state.notes[args.id];
    if (note === undefined) return;
    note.text = args.newText;
  },

  removeNote(state: StateDraft, args: {id: string}): void {
    if (state.notes[args.id] === undefined) return;
    delete state.notes[args.id];
    // For regular notes, we clear the current selection but for an area note
    // we only want to clear the note/marking and leave the area selected.
    if (state.currentSelection === null) return;
    if (state.currentSelection.kind === 'NOTE' &&
        state.currentSelection.id === args.id) {
      state.currentSelection = null;
    } else if (
        state.currentSelection.kind === 'AREA' &&
        state.currentSelection.noteId === args.id) {
      state.currentSelection.noteId = undefined;
    }
  },

  selectSlice(state: StateDraft, args: {id: number, trackId: string}): void {
    state.currentSelection = {
      kind: 'SLICE',
      id: args.id,
      trackId: args.trackId,
    };
  },

  selectCounter(
      state: StateDraft,
      args: {leftTs: number, rightTs: number, id: number, trackId: string}):
      void {
        state.currentSelection = {
          kind: 'COUNTER',
          leftTs: args.leftTs,
          rightTs: args.rightTs,
          id: args.id,
          trackId: args.trackId,
        };
      },

  selectHeapProfile(
      state: StateDraft,
      args: {id: number, upid: number, ts: number, type: string}): void {
    state.currentSelection = {
      kind: 'HEAP_PROFILE',
      id: args.id,
      upid: args.upid,
      ts: args.ts,
      type: args.type,
    };
    this.openFlamegraph(state, {
      type: args.type,
      startNs: toNs(state.traceTime.startSec),
      endNs: args.ts,
      upids: [args.upid],
      viewingOption: DEFAULT_VIEWING_OPTION
    });
  },

  selectPerfSamples(
      state: StateDraft,
      args: {id: number, upid: number, ts: number, type: string}): void {
    state.currentSelection = {
      kind: 'PERF_SAMPLES',
      id: args.id,
      upid: args.upid,
      ts: args.ts,
      type: args.type,
    };
    this.openFlamegraph(state, {
      type: args.type,
      startNs: toNs(state.traceTime.startSec),
      endNs: args.ts,
      upids: [args.upid],
      viewingOption: PERF_SAMPLES_KEY
    });
  },

  openFlamegraph(state: StateDraft, args: {
    upids: number[],
    startNs: number,
    endNs: number,
    type: string,
    viewingOption: FlamegraphStateViewingOption
  }): void {
    state.currentFlamegraphState = {
      kind: 'FLAMEGRAPH_STATE',
      upids: args.upids,
      startNs: args.startNs,
      endNs: args.endNs,
      type: args.type,
      viewingOption: args.viewingOption,
      focusRegex: ''
    };
  },

  selectCpuProfileSample(
      state: StateDraft, args: {id: number, utid: number, ts: number}): void {
    state.currentSelection = {
      kind: 'CPU_PROFILE_SAMPLE',
      id: args.id,
      utid: args.utid,
      ts: args.ts,
    };
  },

  expandFlamegraphState(
      state: StateDraft, args: {expandedCallsite?: CallsiteInfo}): void {
    if (state.currentFlamegraphState === null) return;
    state.currentFlamegraphState.expandedCallsite = args.expandedCallsite;
  },

  changeViewFlamegraphState(
      state: StateDraft, args: {viewingOption: FlamegraphStateViewingOption}):
      void {
        if (state.currentFlamegraphState === null) return;
        state.currentFlamegraphState.viewingOption = args.viewingOption;
      },

  changeFocusFlamegraphState(state: StateDraft, args: {focusRegex: string}):
      void {
        if (state.currentFlamegraphState === null) return;
        state.currentFlamegraphState.focusRegex = args.focusRegex;
      },

  selectChromeSlice(
      state: StateDraft,
      args: {id: number, trackId: string, table: string, scroll?: boolean}):
      void {
        state.currentSelection = {
          kind: 'CHROME_SLICE',
          id: args.id,
          trackId: args.trackId,
          table: args.table
        };
        state.pendingScrollId = args.scroll ? args.id : undefined;
      },

  clearPendingScrollId(state: StateDraft, _: {}): void {
    state.pendingScrollId = undefined;
  },

  selectThreadState(state: StateDraft, args: {id: number, trackId: string}):
      void {
        state.currentSelection = {
          kind: 'THREAD_STATE',
          id: args.id,
          trackId: args.trackId,
        };
      },

  deselect(state: StateDraft, _: {}): void {
    state.currentSelection = null;
  },

  updateLogsPagination(state: StateDraft, args: LogsPagination): void {
    state.logsPagination = args;
  },

  startRecording(state: StateDraft, _: {}): void {
    state.recordingInProgress = true;
    state.lastRecordingError = undefined;
    state.recordingCancelled = false;
  },

  stopRecording(state: StateDraft, _: {}): void {
    state.recordingInProgress = false;
  },

  cancelRecording(state: StateDraft, _: {}): void {
    state.recordingInProgress = false;
    state.recordingCancelled = true;
  },

  setExtensionAvailable(state: StateDraft, args: {available: boolean}): void {
    state.extensionInstalled = args.available;
  },

  setRecordingTarget(state: StateDraft, args: {target: RecordingTarget}): void {
    state.recordingTarget = args.target;
  },

  setFetchChromeCategories(state: StateDraft, args: {fetch: boolean}): void {
    state.fetchChromeCategories = args.fetch;
  },

  setAvailableAdbDevices(
      state: StateDraft, args: {devices: AdbRecordingTarget[]}): void {
    state.availableAdbDevices = args.devices;
  },

  setOmnibox(state: StateDraft, args: OmniboxState): void {
    state.frontendLocalState.omniboxState = args;
  },

  selectArea(state: StateDraft, args: {area: Area}): void {
    const areaId = generateNextId(state);
    assertTrue(args.area.endSec >= args.area.startSec);
    state.areas[areaId] = {
      id: areaId,
      startSec: args.area.startSec,
      endSec: args.area.endSec,
      tracks: args.area.tracks
    };
    state.currentSelection = {kind: 'AREA', areaId};
  },

  editArea(state: StateDraft, args: {area: Area, areaId: string}): void {
    assertTrue(args.area.endSec >= args.area.startSec);
    state.areas[args.areaId] = {
      id: args.areaId,
      startSec: args.area.startSec,
      endSec: args.area.endSec,
      tracks: args.area.tracks
    };
  },

  reSelectArea(state: StateDraft, args: {areaId: string, noteId: string}):
      void {
        state.currentSelection = {
          kind: 'AREA',
          areaId: args.areaId,
          noteId: args.noteId
        };
      },

  toggleTrackSelection(
      state: StateDraft, args: {id: string, isTrackGroup: boolean}) {
    const selection = state.currentSelection;
    if (selection === null || selection.kind !== 'AREA') return;
    const areaId = selection.areaId;
    const index = state.areas[areaId].tracks.indexOf(args.id);
    if (index > -1) {
      state.areas[areaId].tracks.splice(index, 1);
      if (args.isTrackGroup) {  // Also remove all child tracks.
        for (const childTrack of state.trackGroups[args.id].tracks) {
          const childIndex = state.areas[areaId].tracks.indexOf(childTrack);
          if (childIndex > -1) {
            state.areas[areaId].tracks.splice(childIndex, 1);
          }
        }
      }
    } else {
      state.areas[areaId].tracks.push(args.id);
      if (args.isTrackGroup) {  // Also add all child tracks.
        for (const childTrack of state.trackGroups[args.id].tracks) {
          if (!state.areas[areaId].tracks.includes(childTrack)) {
            state.areas[areaId].tracks.push(childTrack);
          }
        }
      }
    }
  },

  setVisibleTraceTime(state: StateDraft, args: VisibleState): void {
    state.frontendLocalState.visibleState = {...args};
  },

  setChromeCategories(state: StateDraft, args: {categories: string[]}): void {
    state.chromeCategories = args.categories;
  },

  setLastRecordingError(state: StateDraft, args: {error?: string}): void {
    state.lastRecordingError = args.error;
    state.recordingStatus = undefined;
  },

  setRecordingStatus(state: StateDraft, args: {status?: string}): void {
    state.recordingStatus = args.status;
    state.lastRecordingError = undefined;
  },

  setAnalyzePageQuery(state: StateDraft, args: {query: string}): void {
    state.analyzePageQuery = args.query;
  },

  requestSelectedMetric(state: StateDraft, _: {}): void {
    if (!state.metrics.availableMetrics) throw Error('No metrics available');
    if (state.metrics.selectedIndex === undefined) {
      throw Error('No metric selected');
    }
    state.metrics.requestedMetric =
        state.metrics.availableMetrics[state.metrics.selectedIndex];
  },

  resetMetricRequest(state: StateDraft, args: {name: string}): void {
    if (state.metrics.requestedMetric !== args.name) return;
    state.metrics.requestedMetric = undefined;
  },

  setAvailableMetrics(state: StateDraft, args: {availableMetrics: string[]}):
      void {
        state.metrics.availableMetrics = args.availableMetrics;
        if (args.availableMetrics.length > 0) state.metrics.selectedIndex = 0;
      },

  setMetricSelectedIndex(state: StateDraft, args: {index: number}): void {
    if (!state.metrics.availableMetrics ||
        args.index >= state.metrics.availableMetrics.length) {
      throw Error('metric selection out of bounds');
    }
    state.metrics.selectedIndex = args.index;
  },

  togglePerfDebug(state: StateDraft, _: {}): void {
    state.perfDebug = !state.perfDebug;
  },

  toggleSidebar(state: StateDraft, _: {}): void {
    state.sidebarVisible = !state.sidebarVisible;
  },

  setHoveredUtidAndPid(state: StateDraft, args: {utid: number, pid: number}) {
    state.hoveredPid = args.pid;
    state.hoveredUtid = args.utid;
  },

  setHighlightedSliceId(state: StateDraft, args: {sliceId: number}) {
    state.highlightedSliceId = args.sliceId;
  },

  setHighlightedFlowLeftId(state: StateDraft, args: {flowId: number}) {
    state.focusedFlowIdLeft = args.flowId;
  },

  setHighlightedFlowRightId(state: StateDraft, args: {flowId: number}) {
    state.focusedFlowIdRight = args.flowId;
  },

  setSearchIndex(state: StateDraft, args: {index: number}) {
    state.searchIndex = args.index;
  },

  setHoveredLogsTimestamp(state: StateDraft, args: {ts: number}) {
    state.hoveredLogsTimestamp = args.ts;
  },

  setHoveredNoteTimestamp(state: StateDraft, args: {ts: number}) {
    state.hoveredNoteTimestamp = args.ts;
  },

  setCurrentTab(state: StateDraft, args: {tab: string|undefined}) {
    state.currentTab = args.tab;
  },

  toggleAllTrackGroups(state: StateDraft, args: {collapsed: boolean}) {
    for (const [_, group] of Object.entries(state.trackGroups)) {
      group.collapsed = args.collapsed;
    }
  },

  togglePivotTableRedux(state: StateDraft, args: {areaId: string|null}) {
    state.nonSerializableState.pivotTableRedux.selectionArea =
        args.areaId === null ?
        null :
        {areaId: args.areaId, tracks: globals.state.areas[args.areaId].tracks};
    if (args.areaId !==
        state.nonSerializableState.pivotTableRedux.selectionArea?.areaId) {
      state.nonSerializableState.pivotTableRedux.queryResult = null;
    }
  },

  addNewPivotTable(state: StateDraft, args: {
    name: string,
    pivotTableId: string,
    selectedPivots: PivotAttrs[],
    selectedAggregations: AggregationAttrs[],
    traceTime?: TraceTime,
    selectedTrackIds?: number[]
  }): void {
    state.pivotTable[args.pivotTableId] = {
      id: args.pivotTableId,
      name: args.name,
      selectedPivots: args.selectedPivots,
      selectedAggregations: args.selectedAggregations,
      isLoadingQuery: false,
      traceTime: args.traceTime,
      selectedTrackIds: args.selectedTrackIds
    };
  },

  deletePivotTable(state: StateDraft, args: {pivotTableId: string}): void {
    delete state.pivotTable[args.pivotTableId];
  },

  resetPivotTableRequest(state: StateDraft, args: {pivotTableId: string}):
      void {
        if (state.pivotTable[args.pivotTableId] !== undefined) {
          state.pivotTable[args.pivotTableId].requestedAction = undefined;
        }
      },

  setPivotTableRequest(
      state: StateDraft,
      args: {pivotTableId: string, action: string, attrs?: SubQueryAttrs}):
      void {
        state.pivotTable[args.pivotTableId].requestedAction = {
          action: args.action,
          attrs: args.attrs
        };
      },

  setAvailablePivotTableColumns(
      state: StateDraft,
      args: {availableColumns: TableAttrs[], availableAggregations: string[]}):
      void {
        state.pivotTableConfig.availableColumns = args.availableColumns;
        state.pivotTableConfig.availableAggregations =
            args.availableAggregations;
      },

  toggleQueryLoading(state: StateDraft, args: {pivotTableId: string}): void {
    state.pivotTable[args.pivotTableId].isLoadingQuery =
        !state.pivotTable[args.pivotTableId].isLoadingQuery;
  },

  setSelectedPivotsAndAggregations(state: StateDraft, args: {
    pivotTableId: string,
    selectedPivots: PivotAttrs[],
    selectedAggregations: AggregationAttrs[]
  }) {
    state.pivotTable[args.pivotTableId].selectedPivots =
        args.selectedPivots.map(pivot => Object.assign({}, pivot));
    state.pivotTable[args.pivotTableId].selectedAggregations =
        args.selectedAggregations.map(
            aggregation => Object.assign({}, aggregation));
  },

  setPivotTableRange(state: StateDraft, args: {
    pivotTableId: string,
    traceTime?: TraceTime,
    selectedTrackIds?: number[]
  }) {
    const pivotTable = state.pivotTable[args.pivotTableId];
    pivotTable.traceTime = args.traceTime;
    pivotTable.selectedTrackIds = args.selectedTrackIds;
  },

  setPivotStateQueryResult(
      state: StateDraft, args: {queryResult: PivotTableReduxResult|null}) {
    state.nonSerializableState.pivotTableRedux.queryResult = args.queryResult;
  },

  setPivotTableReduxConstrainToArea(
      state: StateDraft, args: {constrain: boolean}) {
    state.nonSerializableState.pivotTableRedux.constrainToArea = args.constrain;
  },

  dismissFlamegraphModal(state: StateDraft, _: {}) {
    state.flamegraphModalDismissed = true;
  },

  setPivotTableEditMode(state: StateDraft, args: {editMode: boolean}) {
    state.nonSerializableState.pivotTableRedux.editMode = args.editMode;
    if (!args.editMode) {
      // Switching from edit mode to view mode, need to request query
      state.nonSerializableState.pivotTableRedux.queryRequested = true;
    }
  },

  setPivotTableQueryRequested(
      state: StateDraft, args: {queryRequested: boolean}) {
    state.nonSerializableState.pivotTableRedux.queryRequested =
        args.queryRequested;
  },

  setPivotTablePivotSelected(
      state: StateDraft, args: {column: TableColumn, selected: boolean}) {
    if (args.selected) {
      state.nonSerializableState.pivotTableRedux.selectedPivotsMap.set(
          columnKey(args.column), args.column);
    } else {
      state.nonSerializableState.pivotTableRedux.selectedPivotsMap.delete(
          columnKey(args.column));
    }
  },

  setPivotTableAggregationSelected(
      state: StateDraft, args: {column: TableColumn, selected: boolean}) {
    if (args.selected) {
      state.nonSerializableState.pivotTableRedux.selectedAggregations.set(
          columnKey(args.column), args.column);
    } else {
      state.nonSerializableState.pivotTableRedux.selectedAggregations.delete(
          columnKey(args.column));
    }
  },

  setPivotTableSortColumn(
      state: StateDraft, args: {column: TableColumn, order: SortDirection}) {
    state.nonSerializableState.pivotTableRedux.sortCriteria = {
      column: args.column,
      order: args.order
    };
  }
};

// When we are on the frontend side, we don't really want to execute the
// actions above, we just want to serialize them and marshal their
// arguments, send them over to the controller side and have them being
// executed there. The magic below takes care of turning each action into a
// function that returns the marshaled args.

// A DeferredAction is a bundle of Args and a method name. This is the marshaled
// version of a StateActions method call.
export interface DeferredAction<Args = {}> {
  type: string;
  args: Args;
}

// This type magic creates a type function DeferredActions<T> which takes a type
// T and 'maps' its attributes. For each attribute on T matching the signature:
// (state: StateDraft, args: Args) => void
// DeferredActions<T> has an attribute:
// (args: Args) => DeferredAction<Args>
type ActionFunction<Args> = (state: StateDraft, args: Args) => void;
type DeferredActionFunc<T> = T extends ActionFunction<infer Args>?
    (args: Args) => DeferredAction<Args>:
    never;
type DeferredActions<C> = {
  [P in keyof C]: DeferredActionFunc<C[P]>;
};

// Actions is an implementation of DeferredActions<typeof StateActions>.
// (since StateActions is a variable not a type we have to do
// 'typeof StateActions' to access the (unnamed) type of StateActions).
// It's a Proxy such that any attribute access returns a function:
// (args) => {return {type: ATTRIBUTE_NAME, args};}
export const Actions =
    // tslint:disable-next-line no-any
    new Proxy<DeferredActions<typeof StateActions>>({} as any, {
      // tslint:disable-next-line no-any
      get(_: any, prop: string, _2: any) {
        return (args: {}): DeferredAction<{}> => {
          return {
            type: prop,
            args,
          };
        };
      },
    });
