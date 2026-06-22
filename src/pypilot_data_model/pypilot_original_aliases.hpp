#pragma once

// Compatibility shim retained only for source compatibility.
// Runtime implementation lives in detail/pypilot_original_aliases.hpp.
#include "detail/pypilot_original_aliases.hpp"

namespace pypilot_data_model {

inline FieldId field_id_from_original_alias(const char* name) {
    return detail::field_id_from_original_alias(name);
}

} // namespace pypilot_data_model
