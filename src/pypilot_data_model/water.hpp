#pragma once

#include "core.hpp"

namespace pypilot_data_model {

template<typename Real = float>
struct WaterData {
    Setting<SensorSource> source;
    RangeSetting<Real> rate_hz;

    Stamped<Real> speed_kn;
    Stamped<Real> leeway_deg;
    Setting<SensorSource> leeway_source;

    Stamped<Real> current_speed_kn;
    Stamped<Real> current_direction_deg;

    Stamped<Real> wind_speed_kn;
    Stamped<Real> wind_direction_deg;

    uint64_t last_update_us = 0;
};

} // namespace pypilot_data_model
