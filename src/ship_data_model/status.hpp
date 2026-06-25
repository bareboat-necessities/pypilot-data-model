#pragma once

#include "core.hpp"

namespace ship_data_model {

template<typename Real = float>
struct StatusData {
    Stamped<uint32_t> health;
    Stamped<uint32_t> faults;
    Stamped<uint32_t> warnings;
    Stamped<Real> uptime_s;
    Stamped<Real> loop_period_s;
    Stamped<Real> cpu_load_0_1;
    Stamped<uint32_t> free_memory_bytes;
    char last_error[96] = {0};
    char last_warning[96] = {0};
};

} // namespace ship_data_model
