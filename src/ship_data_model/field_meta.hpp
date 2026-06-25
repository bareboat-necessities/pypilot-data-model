#pragma once

#include "field_id.hpp"

namespace ship_data_model {

enum class FieldType {
    number,
    boolean,
    string_value,
    mode_enum,
    pilot_enum,
    source_enum,
    rudder_calibration_enum
};

struct FieldMeta {
    FieldId id;
    const char* pypilot_name;
    const char* unit;
    FieldType type;
    bool writable;
    bool persistent;
    bool pilot_specific;
};

} // namespace ship_data_model
