#pragma once

#include "field_id.hpp"

namespace pypilot_data_model {

enum class FieldType : uint8_t {
    boolean,
    number,
    source_enum,
    mode_enum,
    pilot_enum,
    rudder_calibration_enum,
    quat,
    json,
    string_value
};

struct FieldMeta {
    FieldId id;
    const char* pypilot_name;
    const char* unit;
    FieldType type;
    bool writable;
    bool persistent;
    bool profiled;
};

} // namespace pypilot_data_model
