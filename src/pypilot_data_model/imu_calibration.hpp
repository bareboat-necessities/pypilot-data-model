#pragma once

#include "core.hpp"

namespace pypilot_data_model {

enum class ImuCalibrationState : uint8_t {
    unknown,
    uncalibrated,
    collecting,
    fitting,
    valid,
    locked,
    failed
};

template<typename Real = float>
struct ImuAxisCalibrationData {
    Setting<bool> valid;
    Setting<bool> locked;
    Setting<Vec3<Real>> bias;
    Setting<Vec3<Real>> scale;
    Setting<Vec3<Real>> offset;
    Stamped<Real> age_s;
    Stamped<Real> fit_error;
    Stamped<uint32_t> point_count;
};

template<typename Real = float>
struct ImuCalibrationData {
    Setting<ImuCalibrationState> state;
    ImuAxisCalibrationData<Real> accel;
    ImuAxisCalibrationData<Real> compass;
    ImuAxisCalibrationData<Real> gyro;

    Setting<Quat<Real>> alignment_q;
    Setting<Real> heading_offset_deg;
    Stamped<Real> compass_field_strength;
    Stamped<Real> compass_inclination_deg;
    Stamped<Real> calibration_progress_0_1;
    char source[64] = {0};
};

template<typename Real = float>
struct ImuStateData {
    Setting<bool> enabled;
    Setting<bool> present;
    Setting<bool> healthy;
    char device[64] = {0};
    char driver[64] = {0};
    Stamped<Real> rate_hz;
    Stamped<Real> dt_s;
    Stamped<uint32_t> sample_count;
    Stamped<uint32_t> drop_count;
    Stamped<uint32_t> error_count;
};

} // namespace pypilot_data_model
