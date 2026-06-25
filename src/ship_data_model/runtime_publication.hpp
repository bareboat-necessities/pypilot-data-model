#pragma once

#include "core.hpp"

namespace ship_data_model {

template<typename Real = float>
struct RuntimePublicationState {
    Stamped<uint32_t> published_value_count;
    Stamped<uint32_t> published_byte_count;
};

} // namespace ship_data_model
