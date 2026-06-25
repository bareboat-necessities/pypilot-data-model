#pragma once

#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "field_id.hpp"

namespace pypilot_data_model {

enum class DataValueType : uint8_t {
    boolean,
    number,
    integer,
    string_value,
    mode,
    pilot_name
};

enum class DataValueScope : uint8_t {
    telemetry,
    command,
    setting,
    status,
    fault
};

struct DataDictionaryEntry {
    FieldId field_id;
    const char* name;
    DataValueType type;
    DataValueScope scope;
    bool writable;
    bool persistent;
};

inline const char* data_value_type_name(DataValueType type) {
    switch (type) {
    case DataValueType::boolean: return "bool";
    case DataValueType::number: return "number";
    case DataValueType::integer: return "number";
    case DataValueType::string_value: return "string";
    case DataValueType::mode: return "string";
    case DataValueType::pilot_name: return "string";
    }
    return "unknown";
}

inline bool copy_data_text(char* dst, size_t dst_size, const char* src) {
    if (!dst || dst_size == 0) return false;
    if (!src) { dst[0] = '\0'; return true; }
    size_t i = 0;
    for (; i + 1 < dst_size && src[i]; ++i) dst[i] = src[i];
    dst[i] = '\0';
    return src[i] == '\0';
}

inline bool append_data_text(char* dst, size_t dst_size, const char* src) {
    if (!dst || !src || dst_size == 0) return false;
    const size_t used = strlen(dst);
    if (used >= dst_size) return false;
    return copy_data_text(dst + used, dst_size - used, src);
}

inline bool parse_data_bool(const char* text, bool& out) {
    if (!text) return false;
    if (strcmp(text, "true") == 0 || strcmp(text, "1") == 0) { out = true; return true; }
    if (strcmp(text, "false") == 0 || strcmp(text, "0") == 0) { out = false; return true; }
    return false;
}

inline bool parse_data_number(const char* text, double& out) {
    if (!text || !*text) return false;
    char* end = nullptr;
    const double value = strtod(text, &end);
    if (!end || (*end != '\0' && *end != '}' && *end != ',')) return false;
    out = value;
    return true;
}

inline bool strip_optional_data_quotes(const char* text, char* out, size_t out_size) {
    if (!text || !out || out_size == 0) return false;
    const size_t len = strlen(text);
    if (len >= 2 && text[0] == '"' && text[len - 1] == '"') {
        const size_t copy_len = len - 2;
        if (copy_len + 1 > out_size) return false;
        memcpy(out, text + 1, copy_len);
        out[copy_len] = '\0';
        return true;
    }
    return copy_data_text(out, out_size, text);
}

#define PYPILOT_DATA_DICTIONARY_ENTRIES(X) \
    X(FieldId::ap_enabled, "ap.enabled", boolean, command, true, true) \
    X(FieldId::ap_mode, "ap.mode", mode, command, true, true) \
    X(FieldId::ap_preferred_mode, "ap.preferred_mode", mode, setting, true, true) \
    X(FieldId::ap_pilot, "ap.pilot", pilot_name, setting, true, true) \
    X(FieldId::ap_heading_command_deg, "ap.heading_command", number, command, true, false) \
    X(FieldId::ap_heading_deg, "ap.heading", number, telemetry, false, false) \
    X(FieldId::ap_heading_error_deg, "ap.heading_error", number, telemetry, false, false) \
    X(FieldId::imu_heading_deg, "imu.heading", number, telemetry, false, false) \
    X(FieldId::imu_heading_lowpass_deg, "imu.heading_lowpass", number, telemetry, false, false) \
    X(FieldId::imu_pitch_deg, "imu.pitch", number, telemetry, false, false) \
    X(FieldId::imu_roll_deg, "imu.roll", number, telemetry, false, false) \
    X(FieldId::imu_heel_deg, "imu.heel", number, telemetry, false, false) \
    X(FieldId::imu_headingrate_deg_s, "imu.headingrate", number, telemetry, false, false) \
    X(FieldId::imu_headingrate_lowpass_deg_s, "imu.headingrate_lowpass", number, telemetry, false, false) \
    X(FieldId::gps_source, "gps.source", string_value, telemetry, false, false) \
    X(FieldId::gps_speed_kn, "gps.speed", number, telemetry, false, false) \
    X(FieldId::gps_track_deg, "gps.track", number, telemetry, false, false) \
    X(FieldId::gps_timestamp_s, "gps.timestamp", number, telemetry, false, false) \
    X(FieldId::wind_source, "wind.source", string_value, telemetry, false, false) \
    X(FieldId::wind_speed_kn, "wind.speed", number, telemetry, false, false) \
    X(FieldId::wind_direction_deg, "wind.direction", number, telemetry, false, false) \
    X(FieldId::truewind_source, "truewind.source", string_value, telemetry, false, false) \
    X(FieldId::truewind_speed_kn, "truewind.speed", number, telemetry, false, false) \
    X(FieldId::truewind_direction_deg, "truewind.direction", number, telemetry, false, false) \
    X(FieldId::water_speed_kn, "water.speed", number, telemetry, false, false) \
    X(FieldId::rudder_angle_deg, "rudder.angle", number, telemetry, false, false) \
    X(FieldId::servo_engaged, "servo.engaged", boolean, command, true, true) \
    X(FieldId::servo_command_norm, "servo.command", number, command, true, false) \
    X(FieldId::servo_position_deg, "servo.position", number, telemetry, false, false) \
    X(FieldId::servo_current_a, "servo.current", number, telemetry, false, false) \
    X(FieldId::servo_voltage_v, "servo.voltage", number, telemetry, false, false) \
    X(FieldId::servo_controller_temp_c, "servo.controller_temp", number, telemetry, false, false) \
    X(FieldId::servo_motor_temp_c, "servo.motor_temp", number, telemetry, false, false) \
    X(FieldId::servo_flags, "servo.flags", integer, fault, false, false) \
    X(FieldId::ap_tack_state, "ap.tack.state", integer, command, true, false) \
    X(FieldId::ap_tack_direction, "ap.tack.direction", integer, command, true, false) \
    X(FieldId::server_profile_name, "profile.name", string_value, setting, true, true) \
    X(FieldId::server_version, "server.version", string_value, status, false, false) \
    X(FieldId::server_uptime_s, "server.uptime", number, status, false, false) \
    X(FieldId::status_faults, "status.faults", integer, fault, false, false) \
    X(FieldId::status_warnings, "status.warnings", integer, status, false, false) \
    X(FieldId::runtime_published_value_count, "runtime.published_value_count", integer, status, false, false)

#define PYPILOT_DATA_DICTIONARY_ROW(FIELD, NAME, TYPE, SCOPE, WRITABLE, PERSISTENT) \
    {FIELD, NAME, DataValueType::TYPE, DataValueScope::SCOPE, WRITABLE, PERSISTENT},

inline const DataDictionaryEntry* core_data_dictionary(size_t& count) {
    static const DataDictionaryEntry entries[] = {
        PYPILOT_DATA_DICTIONARY_ENTRIES(PYPILOT_DATA_DICTIONARY_ROW)
    };
    count = sizeof(entries) / sizeof(entries[0]);
    return entries;
}

#undef PYPILOT_DATA_DICTIONARY_ROW

inline const DataDictionaryEntry* find_core_data_dictionary_entry(const char* name) {
    if (!name) return nullptr;
    size_t count = 0;
    const DataDictionaryEntry* entries = core_data_dictionary(count);
    for (size_t i = 0; i < count; ++i) {
        if (strcmp(entries[i].name, name) == 0) return &entries[i];
    }
    return nullptr;
}

} // namespace pypilot_data_model
