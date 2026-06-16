#pragma once

#include "core.hpp"

namespace pypilot_data_model {

template<typename Real = float>
struct PilotGain {
    RangeSetting<Real> gain;
    Stamped<Real> contribution;
};

template<typename Real = float>
struct BasicPilotData {
    PilotGain<Real> P;
    PilotGain<Real> D;
    PilotGain<Real> DD;
    PilotGain<Real> PR;
    PilotGain<Real> FF;
};

template<typename Real = float>
struct WindPilotData {
    Stamped<Real> gps_wind_offset_deg;
    PilotGain<Real> P;
    PilotGain<Real> D;
    PilotGain<Real> DD;
    PilotGain<Real> WG;
};

template<typename Real = float>
struct AbsolutePilotData {
    PilotGain<Real> P;
    PilotGain<Real> I;
    PilotGain<Real> D;
    PilotGain<Real> FF;
};

template<typename Real = float>
struct GpsPilotData {
    Stamped<Real> wind_gps_offset_deg;
    Stamped<Real> true_wind_gps_offset_deg;
    PilotGain<Real> P;
    PilotGain<Real> D;
    PilotGain<Real> DD;
    PilotGain<Real> FF;
};

template<typename Real = float>
struct RatePilotData {
    PilotGain<Real> D;
    PilotGain<Real> DD;
    PilotGain<Real> FF;
    RangeSetting<Real> max_turn_rate_deg_s;
    RangeSetting<Real> turn_rate_rate_deg_s2;
};

template<typename Real = float>
struct SimplePilotData {
    PilotGain<Real> P;
    PilotGain<Real> I;
    PilotGain<Real> D;
};

template<typename Real = float>
struct VmgPilotData {
    PilotGain<Real> P;
    PilotGain<Real> D;
    PilotGain<Real> DD;
};

template<typename Real = float>
struct PilotsData {
    BasicPilotData<Real> basic;
    WindPilotData<Real> wind;
    AbsolutePilotData<Real> absolute;
    GpsPilotData<Real> gps;
    RatePilotData<Real> rate;
    SimplePilotData<Real> simple;
    VmgPilotData<Real> vmg;
};

} // namespace pypilot_data_model
