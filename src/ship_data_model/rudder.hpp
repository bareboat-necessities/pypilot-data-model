#pragma once

#include "core.hpp"

namespace ship_data_model {

template<typename Real = float>
struct RudderData {
    Setting<SensorSource> source;
    Stamped<Real> angle_deg;
    Setting<RudderCalibrationState> calibration_state;
    RangeSetting<Real> range_deg;
    RangeSetting<Real> offset_deg;
    uint64_t last_update_us = 0;
};

} // namespace ship_data_model
