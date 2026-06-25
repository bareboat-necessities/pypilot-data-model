#pragma once

#include "core.hpp"

namespace ship_data_model {

inline bool servo_faulted(uint32_t flags) {
    const uint32_t fault_mask = servo_overtemp_fault |
                                servo_overcurrent_fault |
                                servo_port_pin_fault |
                                servo_starboard_pin_fault |
                                servo_bad_voltage_fault |
                                servo_min_rudder_fault |
                                servo_max_rudder_fault |
                                servo_port_overcurrent_fault |
                                servo_starboard_overcurrent_fault |
                                servo_driver_timeout;
    return (flags & fault_mask) != 0;
}

template<typename Real = float>
struct ServoData {
    bool has_controller = false;
    Setting<bool> engaged;
    Setting<uint32_t> flags;
    TimedCommand<Real> command_norm;
    TimedCommand<Real> position_command_deg;
    Stamped<Real> current_a;
    Stamped<Real> voltage_v;
    Stamped<Real> controller_temp_c;
    Stamped<Real> motor_temp_c;
    Stamped<Real> rudder_position_deg;
    RangeSetting<Real> max_current_a;
    RangeSetting<Real> max_controller_temp_c;
    RangeSetting<Real> max_motor_temp_c;
};

} // namespace ship_data_model
