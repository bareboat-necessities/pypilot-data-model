#pragma once

#include "autopilot.hpp"
#include "boatimu.hpp"
#include "navigation.hpp"
#include "wind.hpp"
#include "water.hpp"
#include "rudder.hpp"
#include "servo.hpp"
#include "pilots.hpp"
#include "profile.hpp"

namespace pypilot_data_model {

template<typename Real = float>
struct DataModel {
    AutopilotData<Real> ap;
    NavigationData<Real> navigation;
    WindData<Real> wind;
    WaterData<Real> water;
    BoatImuData<Real> imu;
    RudderData<Real> rudder;
    ServoData<Real> servo;
    PilotsData<Real> pilots;
    ProfileData<Real> profile;
};

} // namespace pypilot_data_model

#include "mapping.hpp"
