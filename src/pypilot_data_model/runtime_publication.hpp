#pragma once

#include "core.hpp"

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
    const char* name;
    RuntimeValueType type;
    RuntimeValueScope scope;
    bool writable;
    bool persistent;
};

inline const RuntimeValueMetadata* core_runtime_values(size_t& count) {
    static const RuntimeValueMetadata values[] = {
        {"ap.enabled", RuntimeValueType::boolean, RuntimeValueScope::command, true, true},
        {"ap.mode", RuntimeValueType::mode, RuntimeValueScope::command, true, true},
        {"ap.preferred_mode", RuntimeValueType::mode, RuntimeValueScope::setting, true, true},
        {"ap.pilot", RuntimeValueType::pilot_name, RuntimeValueScope::setting, true, true},
        {"ap.heading_command", RuntimeValueType::number, RuntimeValueScope::command, true, false},
        {"ap.heading", RuntimeValueType::number, RuntimeValueScope::telemetry, false, false},
        {"ap.heading_error", RuntimeValueType::number, RuntimeValueScope::telemetry, false, false},
        {"imu.heading", RuntimeValueType::number, RuntimeValueScope::telemetry, false, false},
        {"imu.heading_lowpass", RuntimeValueType::number, RuntimeValueScope::telemetry, false, false},
        {"imu.pitch", RuntimeValueType::number, RuntimeValueScope::telemetry, false, false},
        {"imu.roll", RuntimeValueType::number, RuntimeValueScope::telemetry, false, false},
        {"imu.heel", RuntimeValueType::number, RuntimeValueScope::telemetry, false, false},
        {"imu.headingrate", RuntimeValueType::number, RuntimeValueScope::telemetry, false, false},
        {"imu.headingrate_lowpass", RuntimeValueType::number, RuntimeValueScope::telemetry, false, false},
        {"gps.source", RuntimeValueType::integer, RuntimeValueScope::telemetry, false, false},
        {"gps.speed", RuntimeValueType::number, RuntimeValueScope::telemetry, false, false},
        {"gps.track", RuntimeValueType::number, RuntimeValueScope::telemetry, false, false},
        {"gps.fix.latitude", RuntimeValueType::number, RuntimeValueScope::telemetry, false, false},
        {"gps.fix.longitude", RuntimeValueType::number, RuntimeValueScope::telemetry, false, false},
        {"wind.source", RuntimeValueType::integer, RuntimeValueScope::telemetry, false, false},
        {"wind.speed", RuntimeValueType::number, RuntimeValueScope::telemetry, false, false},
        {"wind.direction", RuntimeValueType::number, RuntimeValueScope::telemetry, false, false},
        {"truewind.source", RuntimeValueType::integer, RuntimeValueScope::telemetry, false, false},
        {"truewind.speed", RuntimeValueType::number, RuntimeValueScope::telemetry, false, false},
        {"truewind.direction", RuntimeValueType::number, RuntimeValueScope::telemetry, false, false},
        {"water.source", RuntimeValueType::integer, RuntimeValueScope::telemetry, false, false},
        {"water.speed", RuntimeValueType::number, RuntimeValueScope::telemetry, false, false},
        {"rudder.source", RuntimeValueType::integer, RuntimeValueScope::telemetry, false, false},
        {"rudder.angle", RuntimeValueType::number, RuntimeValueScope::telemetry, false, false},
        {"servo.engaged", RuntimeValueType::boolean, RuntimeValueScope::command, true, true},
        {"servo.command", RuntimeValueType::number, RuntimeValueScope::command, true, false},
        {"servo.position", RuntimeValueType::number, RuntimeValueScope::telemetry, false, false},
        {"servo.current", RuntimeValueType::number, RuntimeValueScope::telemetry, false, false},
        {"servo.voltage", RuntimeValueType::number, RuntimeValueScope::telemetry, false, false},
        {"servo.controller_temp", RuntimeValueType::number, RuntimeValueScope::telemetry, false, false},
        {"servo.motor_temp", RuntimeValueType::number, RuntimeValueScope::telemetry, false, false},
        {"servo.flags", RuntimeValueType::integer, RuntimeValueScope::fault, false, false},
        {"ap.tack.state", RuntimeValueType::integer, RuntimeValueScope::command, true, false},
        {"ap.tack.direction", RuntimeValueType::integer, RuntimeValueScope::command, true, false},
        {"profile.name", RuntimeValueType::string_value, RuntimeValueScope::setting, true, true},
        {"server.version", RuntimeValueType::string_value, RuntimeValueScope::status, false, false},
        {"server.uptime", RuntimeValueType::number, RuntimeValueScope::status, false, false}
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
