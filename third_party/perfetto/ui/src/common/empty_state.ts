// Copyright (C) 2021 The Android Open Source Project
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

import {createEmptyRecordConfig} from '../controller/record_config_types';
import {columnKey} from '../frontend/pivot_table_redux';
import {TableColumn} from '../frontend/pivot_table_redux_query_generator';
import {
  autosaveConfigStore,
  recordTargetStore
} from '../frontend/record_config';

import {featureFlags} from './feature_flags';
import {
  defaultTraceTime,
  NonSerializableState,
  State,
  STATE_VERSION
} from './state';

const AUTOLOAD_STARTED_CONFIG_FLAG = featureFlags.register({
  id: 'autoloadStartedConfig',
  name: 'Auto-load last used recording config',
  description: 'Starting a recording automatically saves its configuration. ' +
      'This flag controls whether this config is automatically loaded.',
  defaultValue: true,
});

function columnSet(...columns: TableColumn[]): Map<string, TableColumn> {
  const result = new Map<string, TableColumn>();

  for (const column of columns) {
    result.set(columnKey(column), column);
  }

  return result;
}

export function createEmptyNonSerializableState(): NonSerializableState {
  return {
    pivotTableRedux: {
      selectionArea: null,
      queryResult: null,
      editMode: true,
      selectedPivotsMap: columnSet(
          {table: 'slice', column: 'category'},
          {table: 'slice', column: 'name'}),
      selectedAggregations:
          columnSet({table: 'thread_slice', column: 'thread_dur'}, 'count'),
      constrainToArea: true,
      queryRequested: false,
    },
  };
}

export function createEmptyState(): State {
  return {
    version: STATE_VERSION,
    currentEngineId: undefined,
    nextId: '-1',
    newEngineMode: 'USE_HTTP_RPC_IF_AVAILABLE',
    engines: {},
    traceTime: {...defaultTraceTime},
    tracks: {},
    uiTrackIdByTraceTrackId: {},
    aggregatePreferences: {},
    trackGroups: {},
    visibleTracks: [],
    pinnedTracks: [],
    scrollingTracks: [],
    areas: {},
    queries: {},
    metrics: {},
    permalink: {},
    notes: {},
    pivotTableConfig: {},
    pivotTable: {},

    recordConfig: AUTOLOAD_STARTED_CONFIG_FLAG.get() ?
        autosaveConfigStore.get() :
        createEmptyRecordConfig(),
    displayConfigAsPbtxt: false,
    lastLoadedConfig: {type: 'NONE'},

    frontendLocalState: {
      omniboxState: {
        lastUpdate: 0,
        omnibox: '',
        mode: 'SEARCH',
      },

      visibleState: {
        ...defaultTraceTime,
        lastUpdate: 0,
        resolution: 0,
      },
    },

    logsPagination: {
      offset: 0,
      count: 0,
    },

    status: {msg: '', timestamp: 0},
    currentSelection: null,
    currentFlamegraphState: null,
    traceConversionInProgress: false,

    perfDebug: false,
    sidebarVisible: true,
    hoveredUtid: -1,
    hoveredPid: -1,
    hoveredLogsTimestamp: -1,
    hoveredNoteTimestamp: -1,
    highlightedSliceId: -1,
    focusedFlowIdLeft: -1,
    focusedFlowIdRight: -1,
    searchIndex: -1,

    recordingInProgress: false,
    recordingCancelled: false,
    extensionInstalled: false,
    flamegraphModalDismissed: false,
    recordingTarget: recordTargetStore.getValidTarget(),
    availableAdbDevices: [],

    fetchChromeCategories: false,
    chromeCategories: undefined,
    nonSerializableState: createEmptyNonSerializableState()
  };
}