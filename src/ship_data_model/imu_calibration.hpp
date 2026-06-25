#pragma once

#include "core.hpp"

namespace ship_data_model {

template<typename Real = float>
struct ImuStateData {
    Setting<bool> enabled;
    Stamped<bool> present;
    Stamped<bool> healthy;
    char device[64] = {0};
    char driver[64] = {0};
    Stamped<Real> rate_hz;
};

template<typename Real = float>
struct ImuCalibrationData {
    Setting<bool> locked;
    Stamped<Vec3<Real>> accel_bias_g;
    Stamped<Vec3<Real>> gyro_bias_deg_s;
    Stamped<Vec3<Real>> compass_offset;
};

} // namespace ship_data_model
