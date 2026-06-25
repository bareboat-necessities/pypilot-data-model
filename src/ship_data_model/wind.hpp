#pragma once

#include "core.hpp"

namespace ship_data_model {

template<typename Real = float>
struct WindSensorData {
    Setting<SensorSource> source;
    Stamped<Real> direction_deg;
    Stamped<Real> filtered_direction_deg;
    Stamped<Real> speed_kn;
    Stamped<Real> speed_m_s;
    uint64_t last_update_us = 0;
};

template<typename Real = float>
struct WindData {
    WindSensorData<Real> apparent;
    WindSensorData<Real> truewind;
};

} // namespace ship_data_model
