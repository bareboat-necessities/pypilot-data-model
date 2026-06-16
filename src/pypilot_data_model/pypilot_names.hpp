#pragma once

#include <string.h>
#include "field_table.hpp"
#include "optional_field_table.hpp"

namespace pypilot_data_model {

inline const FieldMeta* field_meta(FieldId id) {
    for (size_t i = 0; i < field_table_size; ++i) {
        if (field_table[i].id == id) {
            return &field_table[i];
        }
    }
    for (size_t i = 0; i < optional_field_table_size; ++i) {
        if (optional_field_table[i].id == id) {
            return &optional_field_table[i];
        }
    }
    return nullptr;
}

inline const char* pypilot_name(FieldId id) {
    const FieldMeta* meta = field_meta(id);
    return meta ? meta->pypilot_name : "";
}

inline FieldId field_id_from_name(const char* name) {
    if (!name) {
        return FieldId::unknown;
    }
    for (size_t i = 0; i < field_table_size; ++i) {
        if (strcmp(field_table[i].pypilot_name, name) == 0) {
            return field_table[i].id;
        }
    }
    for (size_t i = 0; i < optional_field_table_size; ++i) {
        if (strcmp(optional_field_table[i].pypilot_name, name) == 0) {
            return optional_field_table[i].id;
        }
    }
    return FieldId::unknown;
}

inline const char* sensor_source_name(SensorSource source) {
    switch (source) {
    case SensorSource::gpsd: return "gpsd";
    case SensorSource::servo: return "servo";
    case SensorSource::serial: return "serial";
    case SensorSource::tcp: return "tcp";
    case SensorSource::signalk: return "signalk";
    case SensorSource::water_wind: return "water+wind";
    case SensorSource::gps_wind: return "gps+wind";
    case SensorSource::none: return "none";
    }
    return "none";
}

inline bool sensor_source_from_name(const char* name, SensorSource& out) {
    if (!name) return false;
    if (strcmp(name, "gpsd") == 0) { out = SensorSource::gpsd; return true; }
    if (strcmp(name, "servo") == 0) { out = SensorSource::servo; return true; }
    if (strcmp(name, "serial") == 0) { out = SensorSource::serial; return true; }
    if (strcmp(name, "tcp") == 0) { out = SensorSource::tcp; return true; }
    if (strcmp(name, "signalk") == 0) { out = SensorSource::signalk; return true; }
    if (strcmp(name, "water+wind") == 0) { out = SensorSource::water_wind; return true; }
    if (strcmp(name, "gps+wind") == 0) { out = SensorSource::gps_wind; return true; }
    if (strcmp(name, "none") == 0) { out = SensorSource::none; return true; }
    return false;
}

inline const char* autopilot_mode_name(AutopilotMode mode) {
    switch (mode) {
    case AutopilotMode::compass: return "compass";
    case AutopilotMode::gps: return "gps";
    case AutopilotMode::nav: return "nav";
    case AutopilotMode::wind: return "wind";
    case AutopilotMode::true_wind: return "true wind";
    }
    return "compass";
}

inline bool autopilot_mode_from_name(const char* name, AutopilotMode& out) {
    if (!name) return false;
    if (strcmp(name, "compass") == 0) { out = AutopilotMode::compass; return true; }
    if (strcmp(name, "gps") == 0) { out = AutopilotMode::gps; return true; }
    if (strcmp(name, "nav") == 0) { out = AutopilotMode::nav; return true; }
    if (strcmp(name, "wind") == 0) { out = AutopilotMode::wind; return true; }
    if (strcmp(name, "true wind") == 0) { out = AutopilotMode::true_wind; return true; }
    return false;
}

inline const char* pilot_name(PilotName pilot) {
    switch (pilot) {
    case PilotName::basic: return "basic";
    case PilotName::absolute: return "absolute";
    case PilotName::wind: return "wind";
    case PilotName::gps: return "gps";
    case PilotName::rate: return "rate";
    case PilotName::simple: return "simple";
    case PilotName::vmg: return "vmg";
    case PilotName::deadzone: return "deadzone";
    case PilotName::autotune: return "autotune";
    case PilotName::fuzzy: return "fuzzy";
    case PilotName::learning: return "learning";
    case PilotName::intellect: return "intellect";
    }
    return "basic";
}

inline bool pilot_from_name(const char* name, PilotName& out) {
    if (!name) return false;
    if (strcmp(name, "basic") == 0) { out = PilotName::basic; return true; }
    if (strcmp(name, "absolute") == 0) { out = PilotName::absolute; return true; }
    if (strcmp(name, "wind") == 0) { out = PilotName::wind; return true; }
    if (strcmp(name, "gps") == 0) { out = PilotName::gps; return true; }
    if (strcmp(name, "rate") == 0) { out = PilotName::rate; return true; }
    if (strcmp(name, "simple") == 0) { out = PilotName::simple; return true; }
    if (strcmp(name, "vmg") == 0) { out = PilotName::vmg; return true; }
    if (strcmp(name, "deadzone") == 0) { out = PilotName::deadzone; return true; }
    if (strcmp(name, "autotune") == 0) { out = PilotName::autotune; return true; }
    if (strcmp(name, "fuzzy") == 0) { out = PilotName::fuzzy; return true; }
    if (strcmp(name, "learning") == 0) { out = PilotName::learning; return true; }
    if (strcmp(name, "intellect") == 0) { out = PilotName::intellect; return true; }
    return false;
}

inline const char* rudder_calibration_state_name(RudderCalibrationState state) {
    switch (state) {
    case RudderCalibrationState::idle: return "idle";
    case RudderCalibrationState::reset: return "reset";
    case RudderCalibrationState::centered: return "centered";
    case RudderCalibrationState::starboard_range: return "starboard range";
    case RudderCalibrationState::port_range: return "port range";
    case RudderCalibrationState::auto_gain: return "auto gain";
    }
    return "idle";
}

inline bool rudder_calibration_state_from_name(const char* name, RudderCalibrationState& out) {
    if (!name) return false;
    if (strcmp(name, "idle") == 0) { out = RudderCalibrationState::idle; return true; }
    if (strcmp(name, "reset") == 0) { out = RudderCalibrationState::reset; return true; }
    if (strcmp(name, "centered") == 0) { out = RudderCalibrationState::centered; return true; }
    if (strcmp(name, "starboard range") == 0) { out = RudderCalibrationState::starboard_range; return true; }
    if (strcmp(name, "port range") == 0) { out = RudderCalibrationState::port_range; return true; }
    if (strcmp(name, "auto gain") == 0) { out = RudderCalibrationState::auto_gain; return true; }
    return false;
}

} // namespace pypilot_data_model
