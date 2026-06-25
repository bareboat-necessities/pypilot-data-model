#pragma once

#include "core.hpp"

namespace pypilot_data_model {

enum class TackState : uint8_t {
    none,
    waiting,
    begin,
    tacking,
    recovering,
    complete,
    cancelled,
    timeout
};

enum class TackDirection : uint8_t {
    none,
    port,
    starboard
};

template<typename Real = float>
struct TackData {
    Setting<bool> enabled;
    Setting<TackState> state;
    Setting<TackDirection> direction;
    RangeSetting<Real> timeout_s;
    RangeSetting<Real> delay_s;
    RangeSetting<Real> angle_deg;
    RangeSetting<Real> rate_deg_s;
    Stamped<Real> progress_0_1;
    Stamped<Real> command_heading_deg;
    Stamped<Real> start_heading_deg;
    Stamped<Real> target_heading_deg;
    uint64_t start_us = 0;
    uint64_t last_state_change_us = 0;
};

} // namespace pypilot_data_model
