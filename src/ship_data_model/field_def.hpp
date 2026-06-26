#pragma once

#include <stddef.h>

namespace ship_data_model {

enum class FieldId {
    unknown,
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
    rudder_calibration_state,
    pilot_basic_P,
    pilot_basic_Pgain
};

enum class FieldType {
    number,
    boolean,
    string_value,
    mode_enum,
    pilot_enum,
    source_enum,
    rudder_calibration_enum
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
    {FieldId::server_version, "server.version", "", FieldType::string_value, false, false, false},
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
    {FieldId::rudder_calibration_state, "rudder.calibration_state", "", FieldType::rudder_calibration_enum, true, true, false},
    {FieldId::pilot_basic_P, "ap.pilot.basic.P", "", FieldType::number, true, true, true},
    {FieldId::pilot_basic_Pgain, "ap.pilot.basic.Pgain", "", FieldType::number, false, false, true}
};

static constexpr size_t field_definition_count = sizeof(field_definitions) / sizeof(field_definitions[0]);

} // namespace ship_data_model
