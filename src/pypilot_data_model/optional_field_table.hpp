#pragma once

#include <stddef.h>
#include "field_meta.hpp"

namespace pypilot_data_model {

static constexpr FieldMeta optional_field_table[] = {
    {FieldId::rmb_source, "rmb.source", "", FieldType::source_enum, false, false, false},
    {FieldId::rmb_xte_nmi, "rmb.xte", "nmi", FieldType::number, false, false, false},
    {FieldId::rmb_destination_lat_deg, "rmb.destination.lat", "deg", FieldType::number, false, false, false},
    {FieldId::rmb_destination_lon_deg, "rmb.destination.lon", "deg", FieldType::number, false, false, false},
    {FieldId::rmb_range_nmi, "rmb.range", "nmi", FieldType::number, false, false, false},
    {FieldId::rmb_bearing_deg, "rmb.bearing", "deg", FieldType::number, false, false, false},
    {FieldId::rmb_closing_velocity_kn, "rmb.closing_velocity", "kn", FieldType::number, false, false, false},
    {FieldId::rmb_arrived, "rmb.arrived", "", FieldType::boolean, false, false, false},
    {FieldId::water_depth_m, "water.depth", "m", FieldType::number, false, false, false},
    {FieldId::water_depth_offset_m, "water.depth.offset", "m", FieldType::number, false, false, false}
};

static constexpr size_t optional_field_table_size = sizeof(optional_field_table) / sizeof(optional_field_table[0]);

} // namespace pypilot_data_model
