#pragma once

namespace ship_data_model {

enum class FieldId {
    unknown,
    server_version,
    server_uptime_s,
    status_last_error,
    ap_enabled,
    ap_mode,
    ap_pilot,
    ap_heading_deg,
    ap_tack_progress_0_1,
    wind_source,
    wind_filtered_direction_deg,
    servo_current_a,
    servo_telemetry_current_a,
    rudder_calibration_state,
    pilot_basic_P,
    pilot_basic_Pgain
};

} // namespace ship_data_model
