#pragma once

#include "core.hpp"

namespace pypilot_data_model {

template<typename Real = float>
struct BoatImuData {
    Setting<uint8_t> rate_hz;
    Stamped<Real> frequency_hz;

    Setting<Quat<Real>> alignment_q;
    RangeSetting<Real> heading_offset_deg;
    Setting<int32_t> alignment_counter;

    Stamped<Real> uptime_s;
    bool has_warning = false;
    bool has_error = false;

    Stamped<Vec3<Real>> gyro_bias_deg_s;
    Stamped<Vec3<Real>> accel_g;
    Stamped<Vec3<Real>> gyro_deg_s;
    Stamped<Vec3<Real>> compass_raw;
    Stamped<Vec3<Real>> accel_residuals_g;

    Stamped<Real> pitch_deg;
    Stamped<Real> roll_deg;
    Stamped<Real> heel_deg;

    Stamped<Real> pitch_rate_deg_s;
    Stamped<Real> roll_rate_deg_s;
    Stamped<Real> heading_rate_deg_s;
    Stamped<Real> heading_rate_rate_deg_s2;

    Stamped<Real> heading_rate_lowpass_deg_s;
    Stamped<Real> heading_rate_rate_lowpass_deg_s2;

    Stamped<Real> heading_deg;
    Stamped<Real> heading_lowpass_deg;
    Stamped<Quat<Real>> fusion_q_pose;

    RangeSetting<Real> heading_lowpass_constant_0_1;
    RangeSetting<Real> headingrate_lowpass_constant_0_1;
    RangeSetting<Real> headingraterate_lowpass_constant_0_1;
};

} // namespace pypilot_data_model
