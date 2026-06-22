#pragma once

#include <stddef.h>
#include <string.h>
#include "../field_id.hpp"

namespace pypilot_data_model {
namespace detail {

struct PypilotNameAlias {
    const char* name;
    FieldId id;
};

static constexpr PypilotNameAlias pypilot_original_aliases[] = {
    {"ap.version", FieldId::server_version},
    {"ap.modes", FieldId::ap_mode},
    {"ap.gps_and_nav_modes", FieldId::ap_preferred_mode},
    {"ap.gps_compass_offset", FieldId::gps_compass_error_deg},
    {"ap.wind_compass_offset", FieldId::wind_offset_deg},
    {"ap.true_wind_compass_offset", FieldId::truewind_offset_deg},
    {"ap.wind_offset_filter", FieldId::wind_filter_constant_0_1},
    {"ap.timings", FieldId::status_loop_period_s},

    {"imu.frequency", FieldId::imu_state_rate_hz},
    {"imu.alignmentQ", FieldId::imu_fusion_q_pose},
    {"imu.heading_offset", FieldId::imu_calibration_heading_offset_deg},
    {"imu.alignmentCounter", FieldId::imu_calibration_progress_0_1},
    {"imu.uptime", FieldId::status_uptime_s},
    {"imu.warning", FieldId::status_last_warning},
    {"imu.gyrobias", FieldId::imu_calibration_gyro_valid},
    {"imu.heading_lowpass_constant", FieldId::imu_heading_lowpass_deg},
    {"imu.headingrate_lowpass_constant", FieldId::imu_headingrate_lowpass_deg_s},
    {"imu.headingraterate_lowpass_constant", FieldId::imu_headingraterate_lowpass_deg_s2},
    {"imu.accel", FieldId::imu_fusion_q_pose},
    {"imu.gyro", FieldId::imu_calibration_gyro_valid},
    {"imu.compass", FieldId::imu_calibration_compass_valid},
    {"imu.accel.residuals", FieldId::imu_calibration_accel_valid},

    {"gps.rate", FieldId::gps_timestamp_s},
    {"gps.fix", FieldId::gps_timestamp_s},
    {"gps.leeway_ground", FieldId::water_leeway_deg},
    {"gps.alignmentCounter", FieldId::imu_calibration_progress_0_1},
    {"wind.rate", FieldId::wind_filter_factor_0_1},
    {"truewind.rate", FieldId::truewind_filter_factor_0_1},
    {"water.source", FieldId::water_speed_kn},
    {"water.rate", FieldId::water_speed_kn},
    {"water.leeway.source", FieldId::water_leeway_deg},
    {"rudder.source", FieldId::rudder_angle_deg},
    {"rudder.rate", FieldId::rudder_speed_deg_s},

    {"servo.calibration", FieldId::servo_position_deg},
    {"servo.speed_gain", FieldId::servo_speed_norm},
    {"servo.controller", FieldId::servo_telemetry_state},
    {"servo.state", FieldId::servo_telemetry_state},
    {"servo.gain", FieldId::servo_command_norm},
    {"servo.raw_command", FieldId::servo_telemetry_raw_command_norm},
    {"servo.max_slew_speed", FieldId::servo_speed_norm},
    {"servo.max_slew_slow", FieldId::servo_speed_norm},
    {"servo.current.factor", FieldId::servo_current_a},
    {"servo.current.offset", FieldId::servo_current_a},
    {"servo.voltage.factor", FieldId::servo_voltage_v},
    {"servo.voltage.offset", FieldId::servo_voltage_v},
    {"servo.max_controller_temp", FieldId::servo_controller_temp_c},
    {"servo.max_motor_temp", FieldId::servo_motor_temp_c},
    {"servo.clutch_pwm", FieldId::servo_engaged},
    {"servo.use_brake", FieldId::servo_flags},
    {"servo.compensate_current", FieldId::servo_current_a},
    {"servo.compensate_voltage", FieldId::servo_voltage_v},
    {"servo.speed.min", FieldId::servo_speed_norm},
    {"servo.speed.max", FieldId::servo_speed_norm},
    {"servo.position.p", FieldId::servo_position_deg},
    {"servo.position.i", FieldId::servo_position_deg},
    {"servo.position.d", FieldId::servo_position_deg},
    {"servo.use_eeprom", FieldId::servo_flags},

    {"ap.tack.threshold", FieldId::ap_tack_progress_0_1},
    {"ap.tack.count", FieldId::ap_tack_progress_0_1},
    {"ap.tack.use_heel", FieldId::ap_tack_progress_0_1},
    {"ap.tack.use_wind_direction", FieldId::ap_tack_progress_0_1},

    {"ap.pilot.deadzone.deadzone", FieldId::pilot_output_saturated_command_norm},
    {"ap.pilot.fuzzy.learningP", FieldId::pilot_output_proportional_norm},
    {"ap.pilot.fuzzy.learningD", FieldId::pilot_output_derivative_norm},
    {"ap.pilot.fuzzy.seastate", FieldId::status_health},
    {"ap.pilot.learning.P", FieldId::pilot_basic_P},
    {"ap.pilot.learning.Pgain", FieldId::pilot_basic_Pgain},
    {"ap.pilot.learning.D", FieldId::pilot_basic_D},
    {"ap.pilot.learning.Dgain", FieldId::pilot_basic_Dgain},
    {"ap.pilot.learning.W", FieldId::pilot_wind_WG},
    {"ap.pilot.learning.Wgain", FieldId::pilot_wind_WGgain}
};

static constexpr size_t pypilot_original_aliases_size =
    sizeof(pypilot_original_aliases) / sizeof(pypilot_original_aliases[0]);

inline FieldId field_id_from_original_alias(const char* name) {
    if (!name) return FieldId::unknown;
    for (size_t i = 0; i < pypilot_original_aliases_size; ++i) {
        if (strcmp(pypilot_original_aliases[i].name, name) == 0) return pypilot_original_aliases[i].id;
    }
    return FieldId::unknown;
}

} // namespace detail
} // namespace pypilot_data_model
