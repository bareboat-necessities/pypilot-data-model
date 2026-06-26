#pragma once

#include "core_data_types.hpp"

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

template<typename Real = float>
struct WaterData {
    Setting<SensorSource> source;
    Setting<SensorSource> leeway_source;
    Setting<SensorSource> depth_source;
    Stamped<Real> speed_kn;
    Stamped<Real> leeway_deg;
    Stamped<Real> depth_m;
    Stamped<Real> depth_offset_m;
    uint64_t last_update_us = 0;
};

} // namespace ship_data_model
