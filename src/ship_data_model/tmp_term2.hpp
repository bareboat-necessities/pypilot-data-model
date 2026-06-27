#pragma once

#include "core_data_types.hpp"

namespace ship_data_model {

template<typename Real = float>
struct PilotTerm {
    RangeSetting<Real> gain;
};

} // namespace ship_data_model
