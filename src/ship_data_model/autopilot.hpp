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

} // namespace ship_data_model
