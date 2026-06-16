#pragma once

#include "core.hpp"

namespace pypilot_data_model {

template<typename Real = float>
struct RudderData {
    Setting<SensorSource> source;
    RangeSetting<Real> rate_hz;

    Stamped<Real> angle_deg;
    Stamped<Real> speed_deg_s;

    Setting<Real> offset_deg;
    Setting<Real> scale_deg_per_raw;
    Setting<Real> nonlinearity;
    Setting<RudderCalibrationState> calibration_state;
    RangeSetting<Real> range_deg;

    Stamped<Real> raw_0_1;

    uint64_t last_update_us = 0;
};

} // namespace pypilot_data_model
