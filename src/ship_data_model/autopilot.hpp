#pragma once

#include "core.hpp"

namespace ship_data_model {

template<typename Real = float>
struct AutopilotTimings {
    Real server_s = Real(0);
    Real sensors_s = Real(0);
    Real imu_s = Real(0);
    Real autopilot_s = Real(0);
    Real servo_s = Real(0);
    Real total_s = Real(0);
};

template<typename Real = float>
struct AutopilotData {
    bool has_version = false;
    Stamped<Real> timestamp_s;

    Setting<AutopilotMode> preferred_mode;
    Setting<AutopilotMode> mode;
    uint32_t available_modes_mask = mode_mask_compass;
    Setting<bool> gps_and_nav_modes;

    Stamped<Real> heading_command_deg;
    Setting<bool> enabled;
    Stamped<Real> heading_deg;
    Stamped<Real> heading_error_deg;
    Stamped<Real> heading_error_int_deg;
    Stamped<Real> heading_command_rate_deg_s;

    Setting<PilotName> pilot;

    Stamped<Real> gps_compass_offset_deg;
    Stamped<Real> wind_compass_offset_deg;
    Stamped<Real> true_wind_compass_offset_deg;
    RangeSetting<Real> wind_offset_filter_0_1;

    Stamped<Real> runtime_s;
    Stamped<AutopilotTimings<Real>> timings;
};

template<typename Real = float>
struct PilotTerm {
    RangeSetting<Real> gain;
    Stamped<Real> contribution;
};

template<typename Real = float>
struct BasicPilotData {
    PilotTerm<Real> P;
    PilotTerm<Real> I;
    PilotTerm<Real> D;
    PilotTerm<Real> DD;
    PilotTerm<Real> PR;
};

template<typename Real = float>
struct PilotsData {
    BasicPilotData<Real> basic;
    BasicPilotData<Real> absolute;
    BasicPilotData<Real> wind;
    BasicPilotData<Real> gps;
};

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
