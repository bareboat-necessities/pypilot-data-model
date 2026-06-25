#pragma once

#include <string.h>
#include "field_table.hpp"
#include "pypilot_names.hpp"

namespace ship_data_model {

template<typename Real> struct DataModel;

inline void copy_data_text(char* out, size_t out_size, const char* text) {
    if (!out || out_size == 0) return;
    size_t i = 0;
    if (text) {
        for (; i + 1 < out_size && text[i]; ++i) out[i] = text[i];
    }
    out[i] = '\0';
}

inline FieldId field_id_from_name(const char* name) {
    if (!name) return FieldId::unknown;
    for (size_t i = 0; i < field_table_size; ++i) {
        if (strcmp(field_table[i].pypilot_name, name) == 0) return field_table[i].id;
    }
    return FieldId::unknown;
}

inline const FieldMeta* field_meta(FieldId id) {
    for (size_t i = 0; i < field_table_size; ++i) if (field_table[i].id == id) return &field_table[i];
    return nullptr;
}

inline const char* pypilot_name(FieldId id) {
    const FieldMeta* meta = field_meta(id);
    return meta ? meta->pypilot_name : "";
}

template<typename Real>
inline bool apply_number(DataModel<Real>& model, FieldId id, Real value, uint64_t now_us) {
    switch (id) {
    case FieldId::server_uptime_s: model.server.uptime_s.set(value, now_us); return true;
    case FieldId::ap_heading_deg: model.ap.heading_deg.set(value, now_us); return true;
    case FieldId::ap_tack_progress_0_1: model.tack.progress_0_1.set(value, now_us); return true;
    case FieldId::wind_filtered_direction_deg: model.wind.apparent.filtered_direction_deg.set(value, now_us); return true;
    case FieldId::servo_current_a: model.servo.current_a.set(value, now_us); return true;
    case FieldId::servo_telemetry_current_a: model.servo_telemetry.current_a.set(value, now_us); return true;
    case FieldId::pilot_basic_P: model.pilots.basic.P.gain.value = value; return true;
    case FieldId::pilot_basic_Pgain: model.pilots.basic.P.contribution.set(value, now_us); return true;
    default: return false;
    }
}

template<typename Real>
inline bool read_number(const DataModel<Real>& model, FieldId id, Real& out) {
    switch (id) {
    case FieldId::server_uptime_s: out = model.server.uptime_s.value; return model.server.uptime_s.valid;
    case FieldId::ap_heading_deg: out = model.ap.heading_deg.value; return model.ap.heading_deg.valid;
    case FieldId::servo_telemetry_current_a: out = model.servo_telemetry.current_a.value; return model.servo_telemetry.current_a.valid;
    case FieldId::pilot_basic_P: out = model.pilots.basic.P.gain.value; return true;
    default: return false;
    }
}

template<typename Real>
inline bool apply_bool(DataModel<Real>& model, FieldId id, bool value, uint64_t) {
    if (id == FieldId::ap_enabled) { model.ap.enabled.value = value; return true; }
    return false;
}

template<typename Real>
inline bool read_bool(const DataModel<Real>& model, FieldId id, bool& out) {
    if (id == FieldId::ap_enabled) { out = model.ap.enabled.value; return true; }
    return false;
}

template<typename Real>
inline bool apply_mode(DataModel<Real>& model, FieldId id, AutopilotMode value, uint64_t) {
    if (id == FieldId::ap_mode) { model.ap.mode.value = value; return true; }
    return false;
}

template<typename Real>
inline bool apply_source(DataModel<Real>& model, FieldId id, SensorSource value, uint64_t) {
    if (id == FieldId::wind_source) { model.wind.apparent.source.value = value; return true; }
    return false;
}

template<typename Real>
inline bool apply_pilot(DataModel<Real>& model, FieldId id, PilotName value, uint64_t) {
    if (id == FieldId::ap_pilot) { model.ap.pilot.value = value; return true; }
    return false;
}

template<typename Real>
inline bool apply_rudder_calibration_state(DataModel<Real>& model, FieldId id, RudderCalibrationState value, uint64_t) {
    if (id == FieldId::rudder_calibration_state) { model.rudder.calibration_state.value = value; return true; }
    return false;
}

template<typename Real>
inline bool apply_string(DataModel<Real>& model, FieldId id, const char* value, uint64_t) {
    if (id == FieldId::server_version) { copy_data_text(model.server.version, sizeof(model.server.version), value); return true; }
    if (id == FieldId::status_last_error) { copy_data_text(model.status.last_error, sizeof(model.status.last_error), value); return true; }
    return false;
}

template<typename Real>
inline bool read_string(const DataModel<Real>& model, FieldId id, const char*& out) {
    if (id == FieldId::server_version) { out = model.server.version; return true; }
    if (id == FieldId::status_last_error) { out = model.status.last_error; return true; }
    return false;
}

} // namespace ship_data_model
