#pragma once

#include "core.hpp"

namespace ship_data_model {

template<typename Real = float>
struct PilotCommandData {
    Stamped<uint32_t> source;
    TimedCommand<Real> heading_deg;
    TimedCommand<Real> heading_rate_deg_s;
    TimedCommand<Real> servo_norm;
    TimedCommand<Real> servo_position_deg;
};

template<typename Real = float>
struct PilotOutputData {
    Stamped<Real> command_norm;
    Stamped<Real> heading_error_deg;
    Stamped<Real> desired_heading_deg;
    Stamped<Real> desired_heading_rate_deg_s;
    Stamped<Real> saturated_command_norm;
    Stamped<Real> feed_forward_norm;
    Stamped<Real> proportional_norm;
    Stamped<Real> derivative_norm;
    Stamped<Real> integral_norm;
    Stamped<bool> saturated;
    Stamped<bool> fault;
    char active_name[32] = {0};
};

} // namespace ship_data_model
