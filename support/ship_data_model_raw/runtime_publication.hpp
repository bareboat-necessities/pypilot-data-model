#pragma once

#include "core.hpp"

namespace pypilot_data_model {

template<typename Real = float>
struct RuntimePublicationState {
    Stamped<Real> last_publish_period_s;
    Stamped<uint32_t> published_value_count;
    Stamped<uint32_t> dropped_value_count;
};

} // namespace pypilot_data_model
