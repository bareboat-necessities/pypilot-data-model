#pragma once

#include "core_data_types.hpp"

namespace ship_data_model {

template<typename Real = float>
struct ValuePublicationState {
    Stamped<uint32_t> published_value_count;
    Stamped<uint32_t> published_byte_count;
};

} // namespace ship_data_model
