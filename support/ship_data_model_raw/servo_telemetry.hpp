#pragma once

#include "core.hpp"

namespace pypilot_data_model {

enum class ServoControllerState : uint8_t {
    unknown,
    disconnected,
    idle,
    engaged,
    moving,
    fault,
    calibration
};

template<typename Real = float>
struct ServoTelemetryData {
    Setting<ServoControllerState> controller_state;
    Setting<uint32_t> flags;
    Setting<uint32_t> faults;

    Stamped<Real> command_norm;
    Stamped<Real> raw_command_norm;
    Stamped<Real> command_rate_norm_s;
    Stamped<Real> position_deg;
    Stamped<Real> position_command_deg;
    Stamped<Real> speed_norm;
    Stamped<Real> duty_pct;

    Stamped<Real> voltage_v;
    Stamped<Real> current_a;
    Stamped<Real> current_noise_a;
    Stamped<Real> watts_w;
    Stamped<Real> controller_temp_c;
    Stamped<Real> motor_temp_c;

    Stamped<Real> rudder_feedback_deg;
    Stamped<Real> rudder_min_deg;
    Stamped<Real> rudder_max_deg;
    Stamped<Real> rudder_center_deg;

    Stamped<uint32_t> packet_count;
    Stamped<uint32_t> bad_packet_count;
    Stamped<uint32_t> timeout_count;
    Stamped<uint32_t> controller_reboot_count;

    uint64_t last_command_us = 0;
    uint64_t last_telemetry_us = 0;
};

template<typename Real = float>
struct ServoCalibrationData {
    Setting<bool> valid;
    Setting<bool> use_eeprom;
    RangeSetting<Real> current_factor;
    RangeSetting<Real> current_offset_a;
    RangeSetting<Real> voltage_factor;
    RangeSetting<Real> voltage_offset_v;
    RangeSetting<Real> position_p;
    RangeSetting<Real> position_i;
    RangeSetting<Real> position_d;
    RangeSetting<Real> speed_min_pct;
    RangeSetting<Real> speed_max_pct;
    RangeSetting<Real> rudder_min_deg;
    RangeSetting<Real> rudder_max_deg;
    RangeSetting<Real> rudder_center_deg;
    char source[64] = {0};
};

} // namespace pypilot_data_model
