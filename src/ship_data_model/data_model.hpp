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
#include "server.hpp"
#include "status.hpp"
#include "tack.hpp"
#include "servo_telemetry.hpp"
#include "imu_calibration.hpp"
#include "pilot_io.hpp"
#include "runtime_publication.hpp"

namespace ship_data_model {

template<typename Real = float>
struct DataModel {
    ServerData<Real> server;
    StatusData<Real> status;

    AutopilotData<Real> ap;
    NavigationData<Real> navigation;
    WindData<Real> wind;
    WaterData<Real> water;
    BoatImuData<Real> imu;
    ImuStateData<Real> imu_state;
    ImuCalibrationData<Real> imu_calibration;

    RudderData<Real> rudder;
    ServoData<Real> servo;
    ServoTelemetryData<Real> servo_telemetry;
    ServoCalibrationData<Real> servo_calibration;

    PilotsData<Real> pilots;
    PilotCommandData<Real> pilot_command;
    PilotOutputData<Real> pilot_output;
    TackData<Real> tack;

    ProfileData<Real> profile;
    RuntimePublicationState<Real> runtime_publication;
};

} // namespace ship_data_model

#include "mapping.hpp"
#include "data_dictionary.hpp"
