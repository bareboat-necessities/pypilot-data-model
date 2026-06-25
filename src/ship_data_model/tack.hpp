#pragma once

#include "core.hpp"

namespace ship_data_model {

template<typename Real = float>
struct TackData {
    Setting<bool> enabled;
    Setting<int32_t> state;
    Setting<int32_t> direction;
    RangeSetting<Real> timeout_s;
    RangeSetting<Real> delay_s;
    RangeSetting<Real> angle_deg;
    RangeSetting<Real> rate_deg_s;
    Stamped<Real> progress_0_1;
    Stamped<Real> command_heading_deg;
    Stamped<Real> start_heading_deg;
    Stamped<Real> target_heading_deg;
};

} // namespace ship_data_model
