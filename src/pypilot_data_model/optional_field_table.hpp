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
    {FieldId::water_depth_offset_m, "water.depth.offset", "m", FieldType::number, false, false, false},

    {FieldId::pilot_wind_gps_wind_offset_deg, "ap.pilot.wind.gps_wind_offset", "deg", FieldType::number, false, false, false},
    {FieldId::pilot_wind_P, "ap.pilot.wind.P", "", FieldType::number, true, true, true},
    {FieldId::pilot_wind_Pgain, "ap.pilot.wind.Pgain", "", FieldType::number, false, false, false},
    {FieldId::pilot_wind_D, "ap.pilot.wind.D", "", FieldType::number, true, true, true},
    {FieldId::pilot_wind_Dgain, "ap.pilot.wind.Dgain", "", FieldType::number, false, false, false},
    {FieldId::pilot_wind_DD, "ap.pilot.wind.DD", "", FieldType::number, true, true, true},
    {FieldId::pilot_wind_DDgain, "ap.pilot.wind.DDgain", "", FieldType::number, false, false, false},
    {FieldId::pilot_wind_WG, "ap.pilot.wind.WG", "", FieldType::number, true, true, true},
    {FieldId::pilot_wind_WGgain, "ap.pilot.wind.WGgain", "", FieldType::number, false, false, false},

    {FieldId::pilot_absolute_P, "ap.pilot.absolute.P", "", FieldType::number, true, true, true},
    {FieldId::pilot_absolute_Pgain, "ap.pilot.absolute.Pgain", "", FieldType::number, false, false, false},
    {FieldId::pilot_absolute_I, "ap.pilot.absolute.I", "", FieldType::number, true, true, true},
    {FieldId::pilot_absolute_Igain, "ap.pilot.absolute.Igain", "", FieldType::number, false, false, false},
    {FieldId::pilot_absolute_D, "ap.pilot.absolute.D", "", FieldType::number, true, true, true},
    {FieldId::pilot_absolute_Dgain, "ap.pilot.absolute.Dgain", "", FieldType::number, false, false, false},
    {FieldId::pilot_absolute_FF, "ap.pilot.absolute.FF", "", FieldType::number, true, true, true},
    {FieldId::pilot_absolute_FFgain, "ap.pilot.absolute.FFgain", "", FieldType::number, false, false, false},

    {FieldId::pilot_rate_D, "ap.pilot.rate.D", "", FieldType::number, true, true, true},
    {FieldId::pilot_rate_Dgain, "ap.pilot.rate.Dgain", "", FieldType::number, false, false, false},
    {FieldId::pilot_rate_DD, "ap.pilot.rate.DD", "", FieldType::number, true, true, true},
    {FieldId::pilot_rate_DDgain, "ap.pilot.rate.DDgain", "", FieldType::number, false, false, false},
    {FieldId::pilot_rate_FF, "ap.pilot.rate.FF", "", FieldType::number, true, true, true},
    {FieldId::pilot_rate_FFgain, "ap.pilot.rate.FFgain", "", FieldType::number, false, false, false},
    {FieldId::pilot_rate_maxturnrate_deg_s, "ap.pilot.rate.maxturnrate", "deg/s", FieldType::number, true, true, false},
    {FieldId::pilot_rate_turnraterate_deg_s2, "ap.pilot.rate.turnraterate", "deg/s^2", FieldType::number, true, true, true},

    {FieldId::pilot_simple_P, "ap.pilot.simple.P", "", FieldType::number, true, true, true},
    {FieldId::pilot_simple_Pgain, "ap.pilot.simple.Pgain", "", FieldType::number, false, false, false},
    {FieldId::pilot_simple_I, "ap.pilot.simple.I", "", FieldType::number, true, true, true},
    {FieldId::pilot_simple_Igain, "ap.pilot.simple.Igain", "", FieldType::number, false, false, false},
    {FieldId::pilot_simple_D, "ap.pilot.simple.D", "", FieldType::number, true, true, true},
    {FieldId::pilot_simple_Dgain, "ap.pilot.simple.Dgain", "", FieldType::number, false, false, false},

    {FieldId::pilot_vmg_P, "ap.pilot.vmg.P", "", FieldType::number, true, true, true},
    {FieldId::pilot_vmg_Pgain, "ap.pilot.vmg.Pgain", "", FieldType::number, false, false, false},
    {FieldId::pilot_vmg_D, "ap.pilot.vmg.D", "", FieldType::number, true, true, true},
    {FieldId::pilot_vmg_Dgain, "ap.pilot.vmg.Dgain", "", FieldType::number, false, false, false},
    {FieldId::pilot_vmg_DD, "ap.pilot.vmg.DD", "", FieldType::number, true, true, true},
    {FieldId::pilot_vmg_DDgain, "ap.pilot.vmg.DDgain", "", FieldType::number, false, false, false}
};

static constexpr size_t optional_field_table_size = sizeof(optional_field_table) / sizeof(optional_field_table[0]);

} // namespace pypilot_data_model
