#pragma once

#include "core.hpp"

namespace pypilot_data_model {

template<typename Real = float>
struct WindSensorData {
    Setting<SensorSource> source;
    RangeSetting<Real> rate_hz;

    Stamped<Real> direction_deg;
    Stamped<Real> speed_kn;

    RangeSetting<Real> offset_deg;
    RangeSetting<Real> sensors_height_m;

    Stamped<Real> filtered_speed_kn;
    Stamped<Real> filtered_direction_deg;

    RangeSetting<Real> filter_constant_0_1;
    Stamped<Real> filter_factor_0_1;

    uint64_t last_update_us = 0;
};

template<typename Real = float>
struct WindData {
    WindSensorData<Real> apparent;
    WindSensorData<Real> truewind;
};

} // namespace pypilot_data_model
