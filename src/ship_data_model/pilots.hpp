#pragma once

#include "core.hpp"

namespace ship_data_model {

template<typename Real = float>
struct PilotTerm {
    RangeSetting<Real> gain;
    Stamped<Real> contribution;
};

template<typename Real = float>
struct BasicPilotData {
    PilotTerm<Real> P;
    PilotTerm<Real> I;
    PilotTerm<Real> D;
    PilotTerm<Real> DD;
    PilotTerm<Real> PR;
};

template<typename Real = float>
struct PilotsData {
    BasicPilotData<Real> basic;
    BasicPilotData<Real> absolute;
    BasicPilotData<Real> wind;
    BasicPilotData<Real> gps;
};

} // namespace ship_data_model
