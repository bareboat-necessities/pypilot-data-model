#pragma once

#include <string.h>
#include "core.hpp"

namespace ship_data_model {

inline bool sensor_source_from_name(const char* name, SensorSource& out) {
    if (!name) return false;
    if (strcmp(name, "gpsd") == 0) out = SensorSource::gpsd;
    else if (strcmp(name, "servo") == 0) out = SensorSource::servo;
    else if (strcmp(name, "serial") == 0) out = SensorSource::serial;
    else if (strcmp(name, "tcp") == 0) out = SensorSource::tcp;
    else if (strcmp(name, "signalk") == 0) out = SensorSource::signalk;
    else if (strcmp(name, "water_wind") == 0) out = SensorSource::water_wind;
    else if (strcmp(name, "gps_wind") == 0) out = SensorSource::gps_wind;
    else if (strcmp(name, "none") == 0) out = SensorSource::none;
    else return false;
    return true;
}

inline bool pilot_from_name(const char* name, PilotName& out) {
    if (!name) return false;
    if (strcmp(name, "basic") == 0) out = PilotName::basic;
    else if (strcmp(name, "absolute") == 0) out = PilotName::absolute;
    else if (strcmp(name, "wind") == 0) out = PilotName::wind;
    else if (strcmp(name, "gps") == 0) out = PilotName::gps;
    else if (strcmp(name, "rate") == 0) out = PilotName::rate;
    else if (strcmp(name, "simple") == 0) out = PilotName::simple;
    else if (strcmp(name, "vmg") == 0) out = PilotName::vmg;
    else if (strcmp(name, "deadzone") == 0) out = PilotName::deadzone;
    else if (strcmp(name, "fuzzy") == 0) out = PilotName::fuzzy;
    else if (strcmp(name, "learning") == 0) out = PilotName::learning;
    else return false;
    return true;
}

template<typename Real = float>
struct AutopilotServerData {
    char version[32] = {0};
    char hostname[64] = {0};
    char config_dir[128] = {0};
    char profile_name[64] = {0};
    Setting<bool> enabled;
    Setting<bool> persistent;
    Setting<bool> watchdog_enabled;
    Stamped<Real> timestamp_s;
    Stamped<Real> uptime_s;
    Stamped<Real> monotonic_s;
    Stamped<Real> poll_period_s;
    Stamped<uint32_t> client_count;
    Stamped<uint32_t> value_count;
    Stamped<uint32_t> watch_count;
};

template<typename Real = float>
struct AutopilotStatusData {
    Stamped<SystemHealth> health;
    Stamped<uint32_t> faults;
    Stamped<uint32_t> warnings;
    Stamped<Real> uptime_s;
    Stamped<Real> loop_period_s;
    Stamped<Real> cpu_load_0_1;
    Stamped<uint32_t> free_memory_bytes;
    char last_error[96] = {0};
    char last_warning[96] = {0};
};

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
    Stamped<PilotCommandSource> source;
    TimedCommand<Real> heading_deg;
    TimedCommand<Real> heading_command_deg;
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
    char active_pilot_name[32] = {0};
};

template<typename Real = float>
struct AutopilotProfileData {
    char name[64] = {0};
};

} // namespace ship_data_model
