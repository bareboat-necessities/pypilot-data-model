#pragma once

#include <stddef.h>

namespace ship_data_model {

enum class FieldId {
    unknown,
    compat_value,
    server_version,
    server_uptime_s,
    status_last_error,
    ap_enabled,
    ap_mode,
    ap_pilot,
    ap_heading_deg,
    ap_tack_progress_0_1,
    wind_source,
    wind_filtered_direction_deg,
    servo_current_a,
    servo_telemetry_current_a,
    servo_flags,
    servo_telemetry_state,
    rudder_calibration_state,
    imu_calibration_heading_offset_deg,
    pilot_basic_P,
    pilot_basic_Pgain
};

enum class FieldType {
    number,
    integer,
    boolean,
    string_value,
    mode_enum,
    pilot_enum,
    source_enum,
    rudder_calibration_enum,
    servo_state_enum
};

struct FieldMeta {
    FieldId id;
    const char* pypilot_name;
    const char* unit;
    FieldType type;
    bool writable;
    bool persistent;
    bool pilot_specific;
};

static constexpr FieldMeta field_definitions[] = {
    {FieldId::compat_value, "compat.value", "", FieldType::number, false, false, false},
    {FieldId::server_version, "server.version", "", FieldType::string_value, false, false, false},
    {FieldId::server_version, "ap.version", "", FieldType::string_value, false, false, false},
    {FieldId::server_uptime_s, "server.uptime", "s", FieldType::number, false, false, false},
    {FieldId::status_last_error, "status.last_error", "", FieldType::string_value, false, false, false},
    {FieldId::ap_enabled, "ap.enabled", "", FieldType::boolean, true, false, false},
    {FieldId::ap_mode, "ap.mode", "", FieldType::mode_enum, true, true, false},
    {FieldId::ap_pilot, "ap.pilot", "", FieldType::pilot_enum, true, true, true},
    {FieldId::ap_heading_deg, "ap.heading", "deg", FieldType::number, false, false, false},
    {FieldId::ap_tack_progress_0_1, "ap.tack.progress", "", FieldType::number, false, false, false},
    {FieldId::wind_source, "wind.source", "", FieldType::source_enum, true, true, false},
    {FieldId::wind_filtered_direction_deg, "wind.filtered_direction", "deg", FieldType::number, false, false, false},
    {FieldId::servo_current_a, "servo.current", "A", FieldType::number, false, false, false},
    {FieldId::servo_telemetry_current_a, "servo.telemetry.current", "A", FieldType::number, false, false, false},
    {FieldId::servo_flags, "servo.flags", "", FieldType::integer, false, false, false},
    {FieldId::servo_telemetry_state, "servo.state", "", FieldType::servo_state_enum, false, false, false},
    {FieldId::rudder_calibration_state, "rudder.calibration_state", "", FieldType::rudder_calibration_enum, true, true, false},
    {FieldId::imu_calibration_heading_offset_deg, "imu.heading_offset", "deg", FieldType::number, true, true, false},
    {FieldId::pilot_basic_P, "ap.pilot.basic.P", "", FieldType::number, true, true, true},
    {FieldId::pilot_basic_P, "ap.pilot.learning.P", "", FieldType::number, true, true, true},
    {FieldId::pilot_basic_Pgain, "ap.pilot.basic.Pgain", "", FieldType::number, false, false, true}
};

static constexpr size_t field_definition_count = sizeof(field_definitions) / sizeof(field_definitions[0]);

} // namespace ship_data_model
