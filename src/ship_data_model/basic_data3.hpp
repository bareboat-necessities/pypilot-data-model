#pragma once

namespace ship_data_model {

template<typename Real = float>
struct BasicPilotData {
    PilotTerm<Real> P;
    PilotTerm<Real> I;
    PilotTerm<Real> D;
    PilotTerm<Real> DD;
    PilotTerm<Real> PR;
};

} // namespace ship_data_model
