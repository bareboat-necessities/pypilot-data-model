#pragma once

#include "core.hpp"

namespace pypilot_data_model {

template<typename Real = float>
struct ServerData {
    char version[32] = {0};
    char hostname[64] = {0};
    char config_dir[160] = {0};
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

} // namespace pypilot_data_model
