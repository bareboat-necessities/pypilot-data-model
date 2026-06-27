#pragma once

namespace ship_data_model {

template<typename Real = float>
struct BasicPilotData {
    PilotTerm<Real> P;
    PilotTerm<Real> I;
    PilotTerm<Real> D;
};

} // namespace ship_data_model
