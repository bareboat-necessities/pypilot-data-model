#pragma once

#include <string.h>
#include "core.hpp"

namespace ship_data_model {

inline bool sensor_source_from_name(const char* name, SensorSource& out) {
    if (!name) return false;
    if (strcmp(name, "gpsd") == 0) out = SensorSource::gpsd;
    else if (strcmp(name, "servo") == 0) out = SensorSource::servo;
    else if (strcmp(name, "serial") == 0) out = SensorSource::serial;
    else if (strcmp(name, "tcp") == 0) out = SensorSource::tcp;
    else if (strcmp(name, "signalk") == 0) out = SensorSource::signalk;
    else if (strcmp(name, "water_wind") == 0) out = SensorSource::water_wind;
    else if (strcmp(name, "gps_wind") == 0) out = SensorSource::gps_wind;
    else if (strcmp(name, "none") == 0) out = SensorSource::none;
    else return false;
    return true;
}

inline bool pilot_from_name(const char* name, PilotName& out) {
    if (!name) return false;
    if (strcmp(name, "basic") == 0) out = PilotName::basic;
    else if (strcmp(name, "absolute") == 0) out = PilotName::absolute;
    else if (strcmp(name, "wind") == 0) out = PilotName::wind;
    else if (strcmp(name, "gps") == 0) out = PilotName::gps;
    else return false;
    return true;
}

inline bool rudder_calibration_state_from_name(const char* name, RudderCalibrationState& out) {
    if (!name) return false;
    if (strcmp(name, "idle") == 0) out = RudderCalibrationState::idle;
    else if (strcmp(name, "reset") == 0) out = RudderCalibrationState::reset;
    else if (strcmp(name, "centered") == 0) out = RudderCalibrationState::centered;
    else if (strcmp(name, "starboard range") == 0) out = RudderCalibrationState::starboard_range;
    else if (strcmp(name, "port range") == 0) out = RudderCalibrationState::port_range;
    else if (strcmp(name, "auto gain") == 0) out = RudderCalibrationState::auto_gain;
    else return false;
    return true;
}

} // namespace ship_data_model
