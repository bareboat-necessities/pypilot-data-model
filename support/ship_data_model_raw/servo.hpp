#pragma once

#include "core.hpp"

namespace pypilot_data_model {

template<typename Real = float>
struct ServoData {
    bool has_calibration_json = false;

    TimedCommand<Real> position_command_deg;
    TimedCommand<Real> command_norm;

    RangeSetting<Real> speed_gain_0_1;
    Stamped<Real> duty_pct;

    Setting<uint32_t> faults;

    Stamped<Real> voltage_v;
    Stamped<Real> current_a;
    Stamped<Real> current_noise_a;

    Stamped<Real> controller_temp_c;
    Stamped<Real> motor_temp_c;

    Setting<bool> engaged;
    RangeSetting<Real> max_current_a;

    RangeSetting<Real> current_factor;
    RangeSetting<Real> current_offset_a;
    RangeSetting<Real> voltage_factor;
    RangeSetting<Real> voltage_offset_v;

    RangeSetting<Real> max_controller_temp_c;
    RangeSetting<Real> max_motor_temp_c;

    RangeSetting<Real> max_slew_speed_pct;
    RangeSetting<Real> max_slew_slow_pct;

    RangeSetting<Real> gain;
    RangeSetting<Real> clutch_pwm_pct;
    Setting<bool> use_brake;

    RangeSetting<Real> period_s;
    Setting<bool> compensate_current;
    Setting<bool> compensate_voltage;

    Setting<Real> amp_hours_ah;
    Stamped<Real> watts_w;

    Stamped<Real> speed_norm;
    RangeSetting<Real> speed_min_pct;
    RangeSetting<Real> speed_max_pct;

    Stamped<Real> position_deg;
    RangeSetting<Real> position_p;
    RangeSetting<Real> position_i;
    RangeSetting<Real> position_d;

    Stamped<Real> raw_command_norm;

    Setting<bool> use_eeprom;
    bool has_state = false;
    bool has_controller = false;
    Setting<uint32_t> flags;
};

inline bool servo_faulted(uint32_t flags) {
    return (flags & (servo_overtemp_fault |
                     servo_overcurrent_fault |
                     servo_invalid_packet_flag |
                     servo_port_pin_fault |
                     servo_starboard_pin_fault |
                     servo_bad_voltage_fault |
                     servo_min_rudder_fault |
                     servo_max_rudder_fault |
                     servo_bad_fuses_flag |
                     servo_port_overcurrent_fault |
                     servo_starboard_overcurrent_fault |
                     servo_driver_timeout)) != 0;
}

} // namespace pypilot_data_model
