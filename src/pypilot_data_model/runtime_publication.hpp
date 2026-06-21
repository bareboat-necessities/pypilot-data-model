#pragma once

#include "core.hpp"
#include "field_id.hpp"

namespace pypilot_data_model {

enum class RuntimeValueType : uint8_t {
    boolean,
    number,
    integer,
    string_value,
    mode,
    pilot_name
};

enum class RuntimeValueScope : uint8_t {
    telemetry,
    command,
    setting,
    calibration,
    status,
    fault
};

struct RuntimeValueMetadata {
    FieldId field_id;
    const char* name;
    RuntimeValueType type;
    RuntimeValueScope scope;
    bool writable;
    bool persistent;
};

inline const RuntimeValueMetadata* core_runtime_values(size_t& count) {
    static const RuntimeValueMetadata values[] = {
        {FieldId::ap_enabled, "ap.enabled", RuntimeValueType::boolean, RuntimeValueScope::command, true, true},
        {FieldId::ap_mode, "ap.mode", RuntimeValueType::mode, RuntimeValueScope::command, true, true},
        {FieldId::ap_preferred_mode, "ap.preferred_mode", RuntimeValueType::mode, RuntimeValueScope::setting, true, true},
        {FieldId::ap_pilot, "ap.pilot", RuntimeValueType::pilot_name, RuntimeValueScope::setting, true, true},
        {FieldId::ap_heading_command_deg, "ap.heading_command", RuntimeValueType::number, RuntimeValueScope::command, true, false},
        {FieldId::ap_heading_deg, "ap.heading", RuntimeValueType::number, RuntimeValueScope::telemetry, false, false},
        {FieldId::ap_heading_error_deg, "ap.heading_error", RuntimeValueType::number, RuntimeValueScope::telemetry, false, false},
        {FieldId::imu_heading_deg, "imu.heading", RuntimeValueType::number, RuntimeValueScope::telemetry, false, false},
        {FieldId::imu_heading_lowpass_deg, "imu.heading_lowpass", RuntimeValueType::number, RuntimeValueScope::telemetry, false, false},
        {FieldId::imu_pitch_deg, "imu.pitch", RuntimeValueType::number, RuntimeValueScope::telemetry, false, false},
        {FieldId::imu_roll_deg, "imu.roll", RuntimeValueType::number, RuntimeValueScope::telemetry, false, false},
        {FieldId::imu_heel_deg, "imu.heel", RuntimeValueType::number, RuntimeValueScope::telemetry, false, false},
        {FieldId::imu_headingrate_deg_s, "imu.headingrate", RuntimeValueType::number, RuntimeValueScope::telemetry, false, false},
        {FieldId::imu_headingrate_lowpass_deg_s, "imu.headingrate_lowpass", RuntimeValueType::number, RuntimeValueScope::telemetry, false, false},
        {FieldId::gps_source, "gps.source", RuntimeValueType::integer, RuntimeValueScope::telemetry, false, false},
        {FieldId::gps_speed_kn, "gps.speed", RuntimeValueType::number, RuntimeValueScope::telemetry, false, false},
        {FieldId::gps_track_deg, "gps.track", RuntimeValueType::number, RuntimeValueScope::telemetry, false, false},
        {FieldId::gps_timestamp_s, "gps.timestamp", RuntimeValueType::number, RuntimeValueScope::telemetry, false, false},
        {FieldId::wind_source, "wind.source", RuntimeValueType::integer, RuntimeValueScope::telemetry, false, false},
        {FieldId::wind_speed_kn, "wind.speed", RuntimeValueType::number, RuntimeValueScope::telemetry, false, false},
        {FieldId::wind_direction_deg, "wind.direction", RuntimeValueType::number, RuntimeValueScope::telemetry, false, false},
        {FieldId::truewind_source, "truewind.source", RuntimeValueType::integer, RuntimeValueScope::telemetry, false, false},
        {FieldId::truewind_speed_kn, "truewind.speed", RuntimeValueType::number, RuntimeValueScope::telemetry, false, false},
        {FieldId::truewind_direction_deg, "truewind.direction", RuntimeValueType::number, RuntimeValueScope::telemetry, false, false},
        {FieldId::water_speed_kn, "water.speed", RuntimeValueType::number, RuntimeValueScope::telemetry, false, false},
        {FieldId::rudder_angle_deg, "rudder.angle", RuntimeValueType::number, RuntimeValueScope::telemetry, false, false},
        {FieldId::servo_engaged, "servo.engaged", RuntimeValueType::boolean, RuntimeValueScope::command, true, true},
        {FieldId::servo_command_norm, "servo.command", RuntimeValueType::number, RuntimeValueScope::command, true, false},
        {FieldId::servo_position_deg, "servo.position", RuntimeValueType::number, RuntimeValueScope::telemetry, false, false},
        {FieldId::servo_current_a, "servo.current", RuntimeValueType::number, RuntimeValueScope::telemetry, false, false},
        {FieldId::servo_voltage_v, "servo.voltage", RuntimeValueType::number, RuntimeValueScope::telemetry, false, false},
        {FieldId::servo_controller_temp_c, "servo.controller_temp", RuntimeValueType::number, RuntimeValueScope::telemetry, false, false},
        {FieldId::servo_motor_temp_c, "servo.motor_temp", RuntimeValueType::number, RuntimeValueScope::telemetry, false, false},
        {FieldId::servo_flags, "servo.flags", RuntimeValueType::integer, RuntimeValueScope::fault, false, false},
        {FieldId::ap_tack_state, "ap.tack.state", RuntimeValueType::integer, RuntimeValueScope::command, true, false},
        {FieldId::ap_tack_direction, "ap.tack.direction", RuntimeValueType::integer, RuntimeValueScope::command, true, false},
        {FieldId::server_profile_name, "profile.name", RuntimeValueType::string_value, RuntimeValueScope::setting, true, true},
        {FieldId::server_version, "server.version", RuntimeValueType::string_value, RuntimeValueScope::status, false, false},
        {FieldId::server_uptime_s, "server.uptime", RuntimeValueType::number, RuntimeValueScope::status, false, false},
        {FieldId::status_faults, "status.faults", RuntimeValueType::integer, RuntimeValueScope::fault, false, false},
        {FieldId::status_warnings, "status.warnings", RuntimeValueType::integer, RuntimeValueScope::status, false, false},
        {FieldId::runtime_published_value_count, "runtime.published_value_count", RuntimeValueType::integer, RuntimeValueScope::status, false, false}
    };
    count = sizeof(values) / sizeof(values[0]);
    return values;
}

template<typename Real = float>
struct RuntimePublicationState {
    Stamped<Real> last_publish_period_s;
    Stamped<uint32_t> published_value_count;
    Stamped<uint32_t> dropped_value_count;
    uint64_t last_publish_us = 0;
};

} // namespace pypilot_data_model
