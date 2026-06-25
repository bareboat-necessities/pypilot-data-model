#pragma once

#include "core.hpp"

namespace pypilot_data_model {

enum class SystemHealth : uint8_t {
    unknown,
    starting,
    ok,
    degraded,
    fault,
    shutting_down
};

enum SystemFaultFlag : uint32_t {
    system_fault_none              = 0u,
    system_fault_imu               = 1u << 0,
    system_fault_servo             = 1u << 1,
    system_fault_rudder            = 1u << 2,
    system_fault_gps               = 1u << 3,
    system_fault_wind              = 1u << 4,
    system_fault_water             = 1u << 5,
    system_fault_nmea              = 1u << 6,
    system_fault_signalk           = 1u << 7,
    system_fault_settings          = 1u << 8,
    system_fault_runtime           = 1u << 9,
    system_fault_low_voltage       = 1u << 10,
    system_fault_high_current      = 1u << 11,
    system_fault_over_temperature  = 1u << 12,
    system_fault_watchdog          = 1u << 13
};

template<typename Real = float>
struct StatusData {
    Setting<SystemHealth> health;
    Setting<uint32_t> faults;
    Setting<uint32_t> warnings;
    Stamped<Real> uptime_s;
    Stamped<Real> loop_period_s;
    Stamped<Real> cpu_load_0_1;
    Stamped<Real> free_memory_bytes;
    char last_error[128] = {0};
    char last_warning[128] = {0};
};

inline bool system_faulted(uint32_t flags) {
    return flags != system_fault_none;
}

} // namespace pypilot_data_model
