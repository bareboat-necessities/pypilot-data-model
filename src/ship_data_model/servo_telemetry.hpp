#pragma once

#include "core.hpp"

namespace ship_data_model {

enum class ServoControllerState : uint8_t {
    disconnected,
    idle,
    engaged,
    fault
};

template<typename Real = float>
struct ServoTelemetryData {
    Setting<ServoControllerState> controller_state;
    Stamped<uint32_t> flags;
    Stamped<Real> command_norm;
    Stamped<Real> raw_command_norm;
    Stamped<Real> position_deg;
    Stamped<Real> voltage_v;
    Stamped<Real> current_a;
    Stamped<Real> controller_temp_c;
    Stamped<Real> motor_temp_c;
    Stamped<uint32_t> packet_count;
    Stamped<uint32_t> error_count;
};

template<typename Real = float>
struct ServoCalibrationData {
    char source[64] = {0};
    Setting<RudderCalibrationState> state;
    RangeSetting<Real> min_deg;
    RangeSetting<Real> max_deg;
    RangeSetting<Real> center_deg;
};

} // namespace ship_data_model
