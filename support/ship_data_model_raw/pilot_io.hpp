#pragma once

#include "core.hpp"

namespace pypilot_data_model {

enum class PilotCommandSource : uint8_t {
    none,
    internal,
    runtime,
    signalk,
    nmea,
    remote,
    tack
};

template<typename Real = float>
struct PilotCommandData {
    Setting<PilotCommandSource> source;
    TimedCommand<Real> heading_command_deg;
    TimedCommand<Real> heading_command_rate_deg_s;
    TimedCommand<Real> servo_command_norm;
    TimedCommand<Real> servo_position_command_deg;
    TimedCommand<AutopilotMode> mode_command;
    TimedCommand<bool> enabled_command;
    TimedCommand<PilotName> pilot_command;
};

template<typename Real = float>
struct PilotOutputData {
    Stamped<Real> command_norm;
    Stamped<Real> command_rate_norm_s;
    Stamped<Real> heading_error_deg;
    Stamped<Real> heading_error_int_deg;
    Stamped<Real> desired_heading_deg;
    Stamped<Real> desired_heading_rate_deg_s;
    Stamped<Real> desired_turn_rate_deg_s;
    Stamped<Real> saturated_command_norm;
    Stamped<Real> feed_forward_norm;
    Stamped<Real> proportional_norm;
    Stamped<Real> derivative_norm;
    Stamped<Real> integral_norm;
    Setting<bool> saturated;
    Setting<bool> pilot_fault;
    char active_pilot_name[32] = {0};
};

} // namespace pypilot_data_model
