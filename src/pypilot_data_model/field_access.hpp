#pragma once

#include <string.h>
#include "data_model.hpp"
#include "field_id.hpp"

namespace pypilot_data_model {

inline void copy_field_string(char* dst, size_t dst_size, const char* src) {
    if (!dst || dst_size == 0) return;
    if (!src) src = "";
    size_t i = 0;
    for (; i + 1 < dst_size && src[i]; ++i) dst[i] = src[i];
    dst[i] = '\0';
}

template<typename Real>
inline void set_pilot_gain(PilotGain<Real>& gain, Real value) {
    gain.gain.value = value;
}

template<typename Real>
inline void set_pilot_contribution(PilotGain<Real>& gain, Real value, uint64_t now_us) {
    gain.contribution.set(value, now_us);
}

template<typename Real>
inline bool read_pilot_gain(const PilotGain<Real>& gain, Real& out) {
    out = gain.gain.value;
    return true;
}

template<typename Real>
inline bool read_pilot_contribution(const PilotGain<Real>& gain, Real& out) {
    out = gain.contribution.value;
    return gain.contribution.valid;
}

template<typename Real>
inline bool apply_number(DataModel<Real>& model, FieldId id, Real value, uint64_t now_us) {
    switch (id) {
    case FieldId::server_timestamp_s: model.server.timestamp_s.set(value, now_us); return true;
    case FieldId::server_uptime_s: model.server.uptime_s.set(value, now_us); return true;
    case FieldId::server_monotonic_s: model.server.monotonic_s.set(value, now_us); return true;
    case FieldId::server_poll_period_s: model.server.poll_period_s.set(value, now_us); return true;
    case FieldId::server_client_count: model.server.client_count.set(static_cast<uint32_t>(value), now_us); return true;
    case FieldId::server_value_count: model.server.value_count.set(static_cast<uint32_t>(value), now_us); return true;
    case FieldId::server_watch_count: model.server.watch_count.set(static_cast<uint32_t>(value), now_us); return true;

    case FieldId::status_health: model.status.health.value = static_cast<SystemHealth>(static_cast<uint8_t>(value)); return true;
    case FieldId::status_faults: model.status.faults.value = static_cast<uint32_t>(value); return true;
    case FieldId::status_warnings: model.status.warnings.value = static_cast<uint32_t>(value); return true;
    case FieldId::status_uptime_s: model.status.uptime_s.set(value, now_us); return true;
    case FieldId::status_loop_period_s: model.status.loop_period_s.set(value, now_us); return true;
    case FieldId::status_cpu_load_0_1: model.status.cpu_load_0_1.set(value, now_us); return true;
    case FieldId::status_free_memory_bytes: model.status.free_memory_bytes.set(value, now_us); return true;

    case FieldId::ap_heading_deg: model.ap.heading_deg.set(value, now_us); return true;
    case FieldId::ap_heading_command_deg: model.ap.heading_command_deg.set(value, now_us); return true;
    case FieldId::ap_heading_error_deg: model.ap.heading_error_deg.set(value, now_us); return true;
    case FieldId::ap_heading_error_int_deg: model.ap.heading_error_int_deg.set(value, now_us); return true;
    case FieldId::ap_heading_command_rate_deg_s: model.ap.heading_command_rate_deg_s.set(value, now_us); return true;
    case FieldId::ap_runtime_s: model.ap.runtime_s.set(value, now_us); return true;

    case FieldId::ap_tack_state: model.tack.state.value = static_cast<TackState>(static_cast<uint8_t>(value)); return true;
    case FieldId::ap_tack_direction: model.tack.direction.value = static_cast<TackDirection>(static_cast<uint8_t>(value)); return true;
    case FieldId::ap_tack_timeout_s: model.tack.timeout_s.value = value; return true;
    case FieldId::ap_tack_delay_s: model.tack.delay_s.value = value; return true;
    case FieldId::ap_tack_angle_deg: model.tack.angle_deg.value = value; return true;
    case FieldId::ap_tack_rate_deg_s: model.tack.rate_deg_s.value = value; return true;
    case FieldId::ap_tack_progress_0_1: model.tack.progress_0_1.set(value, now_us); return true;
    case FieldId::ap_tack_command_heading_deg: model.tack.command_heading_deg.set(value, now_us); return true;
    case FieldId::ap_tack_start_heading_deg: model.tack.start_heading_deg.set(value, now_us); return true;
    case FieldId::ap_tack_target_heading_deg: model.tack.target_heading_deg.set(value, now_us); return true;

    case FieldId::pilot_command_heading_deg: model.pilot_command.heading_command_deg.set_external(value, now_us); return true;
    case FieldId::pilot_command_heading_rate_deg_s: model.pilot_command.heading_command_rate_deg_s.set_external(value, now_us); return true;
    case FieldId::pilot_command_servo_norm: model.pilot_command.servo_command_norm.set_external(value, now_us); return true;
    case FieldId::pilot_command_servo_position_deg: model.pilot_command.servo_position_command_deg.set_external(value, now_us); return true;
    case FieldId::pilot_output_command_norm: model.pilot_output.command_norm.set(value, now_us); return true;
    case FieldId::pilot_output_heading_error_deg: model.pilot_output.heading_error_deg.set(value, now_us); return true;
    case FieldId::pilot_output_desired_heading_deg: model.pilot_output.desired_heading_deg.set(value, now_us); return true;
    case FieldId::pilot_output_desired_heading_rate_deg_s: model.pilot_output.desired_heading_rate_deg_s.set(value, now_us); return true;
    case FieldId::pilot_output_saturated_command_norm: model.pilot_output.saturated_command_norm.set(value, now_us); return true;
    case FieldId::pilot_output_feed_forward_norm: model.pilot_output.feed_forward_norm.set(value, now_us); return true;
    case FieldId::pilot_output_proportional_norm: model.pilot_output.proportional_norm.set(value, now_us); return true;
    case FieldId::pilot_output_derivative_norm: model.pilot_output.derivative_norm.set(value, now_us); return true;
    case FieldId::pilot_output_integral_norm: model.pilot_output.integral_norm.set(value, now_us); return true;

    case FieldId::imu_state_rate_hz: model.imu_state.rate_hz.set(value, now_us); return true;
    case FieldId::imu_state_dt_s: model.imu_state.dt_s.set(value, now_us); return true;
    case FieldId::imu_state_sample_count: model.imu_state.sample_count.set(static_cast<uint32_t>(value), now_us); return true;
    case FieldId::imu_state_drop_count: model.imu_state.drop_count.set(static_cast<uint32_t>(value), now_us); return true;
    case FieldId::imu_state_error_count: model.imu_state.error_count.set(static_cast<uint32_t>(value), now_us); return true;
    case FieldId::imu_calibration_state: model.imu_calibration.state.value = static_cast<ImuCalibrationState>(static_cast<uint8_t>(value)); return true;
    case FieldId::imu_calibration_heading_offset_deg: model.imu_calibration.heading_offset_deg.value = value; return true;
    case FieldId::imu_calibration_compass_field_strength: model.imu_calibration.compass_field_strength.set(value, now_us); return true;
    case FieldId::imu_calibration_compass_inclination_deg: model.imu_calibration.compass_inclination_deg.set(value, now_us); return true;
    case FieldId::imu_calibration_progress_0_1: model.imu_calibration.calibration_progress_0_1.set(value, now_us); return true;

    case FieldId::imu_heading_deg: model.imu.heading_deg.set(value, now_us); return true;
    case FieldId::imu_heading_lowpass_deg: model.imu.heading_lowpass_deg.set(value, now_us); return true;
    case FieldId::imu_headingrate_deg_s: model.imu.heading_rate_deg_s.set(value, now_us); return true;
    case FieldId::imu_headingrate_lowpass_deg_s: model.imu.heading_rate_lowpass_deg_s.set(value, now_us); return true;
    case FieldId::imu_headingraterate_deg_s2: model.imu.heading_rate_rate_deg_s2.set(value, now_us); return true;
    case FieldId::imu_headingraterate_lowpass_deg_s2: model.imu.heading_rate_rate_lowpass_deg_s2.set(value, now_us); return true;
    case FieldId::imu_pitch_deg: model.imu.pitch_deg.set(value, now_us); return true;
    case FieldId::imu_roll_deg: model.imu.roll_deg.set(value, now_us); return true;
    case FieldId::imu_heel_deg: model.imu.heel_deg.set(value, now_us); return true;
    case FieldId::imu_pitchrate_deg_s: model.imu.pitch_rate_deg_s.set(value, now_us); return true;
    case FieldId::imu_rollrate_deg_s: model.imu.roll_rate_deg_s.set(value, now_us); return true;

    case FieldId::wind_direction_deg: model.wind.apparent.direction_deg.set(value, now_us); return true;
    case FieldId::wind_speed_kn: model.wind.apparent.speed_kn.set(value, now_us); return true;
    case FieldId::wind_filtered_direction_deg: model.wind.apparent.filtered_direction_deg.set(value, now_us); return true;
    case FieldId::wind_filtered_speed_kn: model.wind.apparent.filtered_speed_kn.set(value, now_us); return true;
    case FieldId::wind_offset_deg: model.wind.apparent.offset_deg.value = value; return true;
    case FieldId::wind_sensors_height_m: model.wind.apparent.sensors_height_m.value = value; return true;
    case FieldId::wind_filter_constant_0_1: model.wind.apparent.filter_constant_0_1.value = value; return true;
    case FieldId::wind_filter_factor_0_1: model.wind.apparent.filter_factor_0_1.set(value, now_us); return true;

    case FieldId::truewind_direction_deg: model.wind.truewind.direction_deg.set(value, now_us); return true;
    case FieldId::truewind_speed_kn: model.wind.truewind.speed_kn.set(value, now_us); return true;
    case FieldId::truewind_filtered_direction_deg: model.wind.truewind.filtered_direction_deg.set(value, now_us); return true;
    case FieldId::truewind_filtered_speed_kn: model.wind.truewind.filtered_speed_kn.set(value, now_us); return true;
    case FieldId::truewind_offset_deg: model.wind.truewind.offset_deg.value = value; return true;
    case FieldId::truewind_sensors_height_m: model.wind.truewind.sensors_height_m.value = value; return true;
    case FieldId::truewind_filter_constant_0_1: model.wind.truewind.filter_constant_0_1.value = value; return true;
    case FieldId::truewind_filter_factor_0_1: model.wind.truewind.filter_factor_0_1.set(value, now_us); return true;

    case FieldId::gps_timestamp_s: model.navigation.gps.timestamp_s.set(value, now_us); return true;
    case FieldId::gps_track_deg: model.navigation.gps.track_deg.set(value, now_us); return true;
    case FieldId::gps_speed_kn: model.navigation.gps.speed_kn.set(value, now_us); return true;
    case FieldId::gps_declination_deg: model.navigation.gps.declination_deg.set(value, now_us); return true;
    case FieldId::gps_compass_error_deg: model.navigation.gps.compass_error_deg.set(value, now_us); return true;

    case FieldId::apb_track_deg: model.navigation.apb.track_deg.set(value, now_us); return true;
    case FieldId::apb_xte_nmi: model.navigation.apb.xte_nmi.set(value, now_us); return true;
    case FieldId::apb_xte_gain_deg_per_nmi: model.navigation.apb.xte_gain_deg_per_nmi.value = value; return true;

    case FieldId::water_speed_kn: model.water.speed_kn.set(value, now_us); return true;
    case FieldId::water_leeway_deg: model.water.leeway_deg.set(value, now_us); return true;
    case FieldId::water_current_speed_kn: model.water.current_speed_kn.set(value, now_us); return true;
    case FieldId::water_current_direction_deg: model.water.current_direction_deg.set(value, now_us); return true;
    case FieldId::water_wind_speed_kn: model.water.wind_speed_kn.set(value, now_us); return true;
    case FieldId::water_wind_direction_deg: model.water.wind_direction_deg.set(value, now_us); return true;

    case FieldId::rudder_angle_deg: model.rudder.angle_deg.set(value, now_us); return true;
    case FieldId::rudder_speed_deg_s: model.rudder.speed_deg_s.set(value, now_us); return true;
    case FieldId::rudder_offset_deg: model.rudder.offset_deg.value = value; return true;
    case FieldId::rudder_scale_deg_per_raw: model.rudder.scale_deg_per_raw.value = value; return true;
    case FieldId::rudder_nonlinearity: model.rudder.nonlinearity.value = value; return true;
    case FieldId::rudder_range_deg: model.rudder.range_deg.value = value; return true;

    case FieldId::servo_command_norm: model.servo.command_norm.set_external(value, now_us); return true;
    case FieldId::servo_position_command_deg: model.servo.position_command_deg.set_external(value, now_us); return true;
    case FieldId::servo_current_a: model.servo.current_a.set(value, now_us); return true;
    case FieldId::servo_current_noise_a: model.servo.current_noise_a.set(value, now_us); return true;
    case FieldId::servo_voltage_v: model.servo.voltage_v.set(value, now_us); return true;
    case FieldId::servo_controller_temp_c: model.servo.controller_temp_c.set(value, now_us); return true;
    case FieldId::servo_motor_temp_c: model.servo.motor_temp_c.set(value, now_us); return true;
    case FieldId::servo_flags: model.servo.flags.value = static_cast<uint32_t>(value); return true;
    case FieldId::servo_faults: model.servo.faults.value = static_cast<uint32_t>(value); return true;
    case FieldId::servo_max_current_a: model.servo.max_current_a.value = value; return true;
    case FieldId::servo_period_s: model.servo.period_s.value = value; return true;
    case FieldId::servo_speed_norm: model.servo.speed_norm.set(value, now_us); return true;
    case FieldId::servo_position_deg: model.servo.position_deg.set(value, now_us); return true;
    case FieldId::servo_duty_pct: model.servo.duty_pct.set(value, now_us); return true;
    case FieldId::servo_watts_w: model.servo.watts_w.set(value, now_us); return true;
    case FieldId::servo_amp_hours_ah: model.servo.amp_hours_ah.value = value; return true;

    case FieldId::servo_telemetry_state: model.servo_telemetry.controller_state.value = static_cast<ServoControllerState>(static_cast<uint8_t>(value)); return true;
    case FieldId::servo_telemetry_command_norm: model.servo_telemetry.command_norm.set(value, now_us); return true;
    case FieldId::servo_telemetry_raw_command_norm: model.servo_telemetry.raw_command_norm.set(value, now_us); return true;
    case FieldId::servo_telemetry_position_deg: model.servo_telemetry.position_deg.set(value, now_us); return true;
    case FieldId::servo_telemetry_position_command_deg: model.servo_telemetry.position_command_deg.set(value, now_us); return true;
    case FieldId::servo_telemetry_speed_norm: model.servo_telemetry.speed_norm.set(value, now_us); return true;
    case FieldId::servo_telemetry_duty_pct: model.servo_telemetry.duty_pct.set(value, now_us); return true;
    case FieldId::servo_telemetry_voltage_v: model.servo_telemetry.voltage_v.set(value, now_us); return true;
    case FieldId::servo_telemetry_current_a: model.servo_telemetry.current_a.set(value, now_us); return true;
    case FieldId::servo_telemetry_current_noise_a: model.servo_telemetry.current_noise_a.set(value, now_us); return true;
    case FieldId::servo_telemetry_watts_w: model.servo_telemetry.watts_w.set(value, now_us); return true;
    case FieldId::servo_telemetry_controller_temp_c: model.servo_telemetry.controller_temp_c.set(value, now_us); return true;
    case FieldId::servo_telemetry_motor_temp_c: model.servo_telemetry.motor_temp_c.set(value, now_us); return true;
    case FieldId::servo_telemetry_rudder_feedback_deg: model.servo_telemetry.rudder_feedback_deg.set(value, now_us); return true;
    case FieldId::servo_telemetry_packet_count: model.servo_telemetry.packet_count.set(static_cast<uint32_t>(value), now_us); return true;
    case FieldId::servo_telemetry_bad_packet_count: model.servo_telemetry.bad_packet_count.set(static_cast<uint32_t>(value), now_us); return true;
    case FieldId::servo_telemetry_timeout_count: model.servo_telemetry.timeout_count.set(static_cast<uint32_t>(value), now_us); return true;
    case FieldId::servo_telemetry_reboot_count: model.servo_telemetry.controller_reboot_count.set(static_cast<uint32_t>(value), now_us); return true;

    case FieldId::pilot_basic_P: set_pilot_gain(model.pilots.basic.P, value); return true;
    case FieldId::pilot_basic_Pgain: set_pilot_contribution(model.pilots.basic.P, value, now_us); return true;
    case FieldId::pilot_basic_D: set_pilot_gain(model.pilots.basic.D, value); return true;
    case FieldId::pilot_basic_Dgain: set_pilot_contribution(model.pilots.basic.D, value, now_us); return true;
    case FieldId::pilot_basic_DD: set_pilot_gain(model.pilots.basic.DD, value); return true;
    case FieldId::pilot_basic_DDgain: set_pilot_contribution(model.pilots.basic.DD, value, now_us); return true;
    case FieldId::pilot_basic_PR: set_pilot_gain(model.pilots.basic.PR, value); return true;
    case FieldId::pilot_basic_PRgain: set_pilot_contribution(model.pilots.basic.PR, value, now_us); return true;
    case FieldId::pilot_basic_FF: set_pilot_gain(model.pilots.basic.FF, value); return true;
    case FieldId::pilot_basic_FFgain: set_pilot_contribution(model.pilots.basic.FF, value, now_us); return true;

    case FieldId::pilot_wind_gps_wind_offset_deg: model.pilots.wind.gps_wind_offset_deg.set(value, now_us); return true;
    case FieldId::pilot_wind_P: set_pilot_gain(model.pilots.wind.P, value); return true;
    case FieldId::pilot_wind_Pgain: set_pilot_contribution(model.pilots.wind.P, value, now_us); return true;
    case FieldId::pilot_wind_D: set_pilot_gain(model.pilots.wind.D, value); return true;
    case FieldId::pilot_wind_Dgain: set_pilot_contribution(model.pilots.wind.D, value, now_us); return true;
    case FieldId::pilot_wind_DD: set_pilot_gain(model.pilots.wind.DD, value); return true;
    case FieldId::pilot_wind_DDgain: set_pilot_contribution(model.pilots.wind.DD, value, now_us); return true;
    case FieldId::pilot_wind_WG: set_pilot_gain(model.pilots.wind.WG, value); return true;
    case FieldId::pilot_wind_WGgain: set_pilot_contribution(model.pilots.wind.WG, value, now_us); return true;

    case FieldId::pilot_absolute_P: set_pilot_gain(model.pilots.absolute.P, value); return true;
    case FieldId::pilot_absolute_Pgain: set_pilot_contribution(model.pilots.absolute.P, value, now_us); return true;
    case FieldId::pilot_absolute_I: set_pilot_gain(model.pilots.absolute.I, value); return true;
    case FieldId::pilot_absolute_Igain: set_pilot_contribution(model.pilots.absolute.I, value, now_us); return true;
    case FieldId::pilot_absolute_D: set_pilot_gain(model.pilots.absolute.D, value); return true;
    case FieldId::pilot_absolute_Dgain: set_pilot_contribution(model.pilots.absolute.D, value, now_us); return true;
    case FieldId::pilot_absolute_FF: set_pilot_gain(model.pilots.absolute.FF, value); return true;
    case FieldId::pilot_absolute_FFgain: set_pilot_contribution(model.pilots.absolute.FF, value, now_us); return true;

    case FieldId::pilot_rate_D: set_pilot_gain(model.pilots.rate.D, value); return true;
    case FieldId::pilot_rate_Dgain: set_pilot_contribution(model.pilots.rate.D, value, now_us); return true;
    case FieldId::pilot_rate_DD: set_pilot_gain(model.pilots.rate.DD, value); return true;
    case FieldId::pilot_rate_DDgain: set_pilot_contribution(model.pilots.rate.DD, value, now_us); return true;
    case FieldId::pilot_rate_FF: set_pilot_gain(model.pilots.rate.FF, value); return true;
    case FieldId::pilot_rate_FFgain: set_pilot_contribution(model.pilots.rate.FF, value, now_us); return true;
    case FieldId::pilot_rate_maxturnrate_deg_s: model.pilots.rate.max_turn_rate_deg_s.value = value; return true;
    case FieldId::pilot_rate_turnraterate_deg_s2: model.pilots.rate.turn_rate_rate_deg_s2.value = value; return true;

    case FieldId::pilot_simple_P: set_pilot_gain(model.pilots.simple.P, value); return true;
    case FieldId::pilot_simple_Pgain: set_pilot_contribution(model.pilots.simple.P, value, now_us); return true;
    case FieldId::pilot_simple_I: set_pilot_gain(model.pilots.simple.I, value); return true;
    case FieldId::pilot_simple_Igain: set_pilot_contribution(model.pilots.simple.I, value, now_us); return true;
    case FieldId::pilot_simple_D: set_pilot_gain(model.pilots.simple.D, value); return true;
    case FieldId::pilot_simple_Dgain: set_pilot_contribution(model.pilots.simple.D, value, now_us); return true;

    case FieldId::pilot_vmg_P: set_pilot_gain(model.pilots.vmg.P, value); return true;
    case FieldId::pilot_vmg_Pgain: set_pilot_contribution(model.pilots.vmg.P, value, now_us); return true;
    case FieldId::pilot_vmg_D: set_pilot_gain(model.pilots.vmg.D, value); return true;
    case FieldId::pilot_vmg_Dgain: set_pilot_contribution(model.pilots.vmg.D, value, now_us); return true;
    case FieldId::pilot_vmg_DD: set_pilot_gain(model.pilots.vmg.DD, value); return true;
    case FieldId::pilot_vmg_DDgain: set_pilot_contribution(model.pilots.vmg.DD, value, now_us); return true;

    case FieldId::runtime_last_publish_period_s: model.runtime_publication.last_publish_period_s.set(value, now_us); return true;
    case FieldId::runtime_published_value_count: model.runtime_publication.published_value_count.set(static_cast<uint32_t>(value), now_us); return true;
    case FieldId::runtime_dropped_value_count: model.runtime_publication.dropped_value_count.set(static_cast<uint32_t>(value), now_us); return true;

    default: return false;
    }
}

template<typename Real>
inline bool read_number(const DataModel<Real>& model, FieldId id, Real& out) {
    switch (id) {
    case FieldId::server_uptime_s: out = model.server.uptime_s.value; return model.server.uptime_s.valid;
    case FieldId::server_client_count: out = static_cast<Real>(model.server.client_count.value); return model.server.client_count.valid;
    case FieldId::server_value_count: out = static_cast<Real>(model.server.value_count.value); return model.server.value_count.valid;
    case FieldId::server_watch_count: out = static_cast<Real>(model.server.watch_count.value); return model.server.watch_count.valid;
    case FieldId::status_faults: out = static_cast<Real>(model.status.faults.value); return true;
    case FieldId::status_warnings: out = static_cast<Real>(model.status.warnings.value); return true;
    case FieldId::ap_heading_deg: out = model.ap.heading_deg.value; return model.ap.heading_deg.valid;
    case FieldId::ap_heading_command_deg: out = model.ap.heading_command_deg.value; return model.ap.heading_command_deg.valid;
    case FieldId::ap_heading_error_deg: out = model.ap.heading_error_deg.value; return model.ap.heading_error_deg.valid;
    case FieldId::ap_heading_error_int_deg: out = model.ap.heading_error_int_deg.value; return model.ap.heading_error_int_deg.valid;
    case FieldId::ap_heading_command_rate_deg_s: out = model.ap.heading_command_rate_deg_s.value; return model.ap.heading_command_rate_deg_s.valid;
    case FieldId::ap_runtime_s: out = model.ap.runtime_s.value; return model.ap.runtime_s.valid;
    case FieldId::ap_tack_state: out = static_cast<Real>(model.tack.state.value); return true;
    case FieldId::ap_tack_direction: out = static_cast<Real>(model.tack.direction.value); return true;
    case FieldId::imu_heading_deg: out = model.imu.heading_deg.value; return model.imu.heading_deg.valid;
    case FieldId::imu_heading_lowpass_deg: out = model.imu.heading_lowpass_deg.value; return model.imu.heading_lowpass_deg.valid;
    case FieldId::imu_headingrate_deg_s: out = model.imu.heading_rate_deg_s.value; return model.imu.heading_rate_deg_s.valid;
    case FieldId::imu_headingrate_lowpass_deg_s: out = model.imu.heading_rate_lowpass_deg_s.value; return model.imu.heading_rate_lowpass_deg_s.valid;
    case FieldId::imu_pitch_deg: out = model.imu.pitch_deg.value; return model.imu.pitch_deg.valid;
    case FieldId::imu_roll_deg: out = model.imu.roll_deg.value; return model.imu.roll_deg.valid;
    case FieldId::imu_heel_deg: out = model.imu.heel_deg.value; return model.imu.heel_deg.valid;
    case FieldId::gps_timestamp_s: out = model.navigation.gps.timestamp_s.value; return model.navigation.gps.timestamp_s.valid;
    case FieldId::gps_track_deg: out = model.navigation.gps.track_deg.value; return model.navigation.gps.track_deg.valid;
    case FieldId::gps_speed_kn: out = model.navigation.gps.speed_kn.value; return model.navigation.gps.speed_kn.valid;
    case FieldId::wind_direction_deg: out = model.wind.apparent.direction_deg.value; return model.wind.apparent.direction_deg.valid;
    case FieldId::wind_speed_kn: out = model.wind.apparent.speed_kn.value; return model.wind.apparent.speed_kn.valid;
    case FieldId::truewind_direction_deg: out = model.wind.truewind.direction_deg.value; return model.wind.truewind.direction_deg.valid;
    case FieldId::truewind_speed_kn: out = model.wind.truewind.speed_kn.value; return model.wind.truewind.speed_kn.valid;
    case FieldId::water_speed_kn: out = model.water.speed_kn.value; return model.water.speed_kn.valid;
    case FieldId::rudder_angle_deg: out = model.rudder.angle_deg.value; return model.rudder.angle_deg.valid;
    case FieldId::servo_current_a: out = model.servo.current_a.value; return model.servo.current_a.valid;
    case FieldId::servo_command_norm: out = model.servo.command_norm.value; return model.servo.command_norm.valid;
    case FieldId::servo_voltage_v: out = model.servo.voltage_v.value; return model.servo.voltage_v.valid;
    case FieldId::servo_position_deg: out = model.servo.position_deg.value; return model.servo.position_deg.valid;
    case FieldId::servo_controller_temp_c: out = model.servo.controller_temp_c.value; return model.servo.controller_temp_c.valid;
    case FieldId::servo_motor_temp_c: out = model.servo.motor_temp_c.value; return model.servo.motor_temp_c.valid;
    case FieldId::servo_flags: out = static_cast<Real>(model.servo.flags.value); return true;
    case FieldId::servo_faults: out = static_cast<Real>(model.servo.faults.value); return true;

    case FieldId::servo_telemetry_command_norm: out = model.servo_telemetry.command_norm.value; return model.servo_telemetry.command_norm.valid;
    case FieldId::servo_telemetry_raw_command_norm: out = model.servo_telemetry.raw_command_norm.value; return model.servo_telemetry.raw_command_norm.valid;
    case FieldId::servo_telemetry_position_deg: out = model.servo_telemetry.position_deg.value; return model.servo_telemetry.position_deg.valid;
    case FieldId::servo_telemetry_position_command_deg: out = model.servo_telemetry.position_command_deg.value; return model.servo_telemetry.position_command_deg.valid;
    case FieldId::servo_telemetry_speed_norm: out = model.servo_telemetry.speed_norm.value; return model.servo_telemetry.speed_norm.valid;
    case FieldId::servo_telemetry_duty_pct: out = model.servo_telemetry.duty_pct.value; return model.servo_telemetry.duty_pct.valid;
    case FieldId::servo_telemetry_voltage_v: out = model.servo_telemetry.voltage_v.value; return model.servo_telemetry.voltage_v.valid;
    case FieldId::servo_telemetry_current_a: out = model.servo_telemetry.current_a.value; return model.servo_telemetry.current_a.valid;
    case FieldId::servo_telemetry_current_noise_a: out = model.servo_telemetry.current_noise_a.value; return model.servo_telemetry.current_noise_a.valid;
    case FieldId::servo_telemetry_watts_w: out = model.servo_telemetry.watts_w.value; return model.servo_telemetry.watts_w.valid;
    case FieldId::servo_telemetry_controller_temp_c: out = model.servo_telemetry.controller_temp_c.value; return model.servo_telemetry.controller_temp_c.valid;
    case FieldId::servo_telemetry_motor_temp_c: out = model.servo_telemetry.motor_temp_c.value; return model.servo_telemetry.motor_temp_c.valid;
    case FieldId::servo_telemetry_rudder_feedback_deg: out = model.servo_telemetry.rudder_feedback_deg.value; return model.servo_telemetry.rudder_feedback_deg.valid;
    case FieldId::servo_telemetry_packet_count: out = static_cast<Real>(model.servo_telemetry.packet_count.value); return model.servo_telemetry.packet_count.valid;
    case FieldId::servo_telemetry_bad_packet_count: out = static_cast<Real>(model.servo_telemetry.bad_packet_count.value); return model.servo_telemetry.bad_packet_count.valid;
    case FieldId::servo_telemetry_timeout_count: out = static_cast<Real>(model.servo_telemetry.timeout_count.value); return model.servo_telemetry.timeout_count.valid;
    case FieldId::servo_telemetry_reboot_count: out = static_cast<Real>(model.servo_telemetry.controller_reboot_count.value); return model.servo_telemetry.controller_reboot_count.valid;

    case FieldId::pilot_basic_P: return read_pilot_gain(model.pilots.basic.P, out);
    case FieldId::pilot_basic_Pgain: return read_pilot_contribution(model.pilots.basic.P, out);
    case FieldId::pilot_basic_D: return read_pilot_gain(model.pilots.basic.D, out);
    case FieldId::pilot_basic_Dgain: return read_pilot_contribution(model.pilots.basic.D, out);
    case FieldId::pilot_basic_DD: return read_pilot_gain(model.pilots.basic.DD, out);
    case FieldId::pilot_basic_DDgain: return read_pilot_contribution(model.pilots.basic.DD, out);
    case FieldId::pilot_basic_PR: return read_pilot_gain(model.pilots.basic.PR, out);
    case FieldId::pilot_basic_PRgain: return read_pilot_contribution(model.pilots.basic.PR, out);
    case FieldId::pilot_basic_FF: return read_pilot_gain(model.pilots.basic.FF, out);
    case FieldId::pilot_basic_FFgain: return read_pilot_contribution(model.pilots.basic.FF, out);

    case FieldId::pilot_wind_gps_wind_offset_deg: out = model.pilots.wind.gps_wind_offset_deg.value; return model.pilots.wind.gps_wind_offset_deg.valid;
    case FieldId::pilot_wind_P: return read_pilot_gain(model.pilots.wind.P, out);
    case FieldId::pilot_wind_Pgain: return read_pilot_contribution(model.pilots.wind.P, out);
    case FieldId::pilot_wind_D: return read_pilot_gain(model.pilots.wind.D, out);
    case FieldId::pilot_wind_Dgain: return read_pilot_contribution(model.pilots.wind.D, out);
    case FieldId::pilot_wind_DD: return read_pilot_gain(model.pilots.wind.DD, out);
    case FieldId::pilot_wind_DDgain: return read_pilot_contribution(model.pilots.wind.DD, out);
    case FieldId::pilot_wind_WG: return read_pilot_gain(model.pilots.wind.WG, out);
    case FieldId::pilot_wind_WGgain: return read_pilot_contribution(model.pilots.wind.WG, out);

    case FieldId::pilot_absolute_P: return read_pilot_gain(model.pilots.absolute.P, out);
    case FieldId::pilot_absolute_Pgain: return read_pilot_contribution(model.pilots.absolute.P, out);
    case FieldId::pilot_absolute_I: return read_pilot_gain(model.pilots.absolute.I, out);
    case FieldId::pilot_absolute_Igain: return read_pilot_contribution(model.pilots.absolute.I, out);
    case FieldId::pilot_absolute_D: return read_pilot_gain(model.pilots.absolute.D, out);
    case FieldId::pilot_absolute_Dgain: return read_pilot_contribution(model.pilots.absolute.D, out);
    case FieldId::pilot_absolute_FF: return read_pilot_gain(model.pilots.absolute.FF, out);
    case FieldId::pilot_absolute_FFgain: return read_pilot_contribution(model.pilots.absolute.FF, out);

    case FieldId::pilot_rate_D: return read_pilot_gain(model.pilots.rate.D, out);
    case FieldId::pilot_rate_Dgain: return read_pilot_contribution(model.pilots.rate.D, out);
    case FieldId::pilot_rate_DD: return read_pilot_gain(model.pilots.rate.DD, out);
    case FieldId::pilot_rate_DDgain: return read_pilot_contribution(model.pilots.rate.DD, out);
    case FieldId::pilot_rate_FF: return read_pilot_gain(model.pilots.rate.FF, out);
    case FieldId::pilot_rate_FFgain: return read_pilot_contribution(model.pilots.rate.FF, out);
    case FieldId::pilot_rate_maxturnrate_deg_s: out = model.pilots.rate.max_turn_rate_deg_s.value; return true;
    case FieldId::pilot_rate_turnraterate_deg_s2: out = model.pilots.rate.turn_rate_rate_deg_s2.value; return true;

    case FieldId::pilot_simple_P: return read_pilot_gain(model.pilots.simple.P, out);
    case FieldId::pilot_simple_Pgain: return read_pilot_contribution(model.pilots.simple.P, out);
    case FieldId::pilot_simple_I: return read_pilot_gain(model.pilots.simple.I, out);
    case FieldId::pilot_simple_Igain: return read_pilot_contribution(model.pilots.simple.I, out);
    case FieldId::pilot_simple_D: return read_pilot_gain(model.pilots.simple.D, out);
    case FieldId::pilot_simple_Dgain: return read_pilot_contribution(model.pilots.simple.D, out);

    case FieldId::pilot_vmg_P: return read_pilot_gain(model.pilots.vmg.P, out);
    case FieldId::pilot_vmg_Pgain: return read_pilot_contribution(model.pilots.vmg.P, out);
    case FieldId::pilot_vmg_D: return read_pilot_gain(model.pilots.vmg.D, out);
    case FieldId::pilot_vmg_Dgain: return read_pilot_contribution(model.pilots.vmg.D, out);
    case FieldId::pilot_vmg_DD: return read_pilot_gain(model.pilots.vmg.DD, out);
    case FieldId::pilot_vmg_DDgain: return read_pilot_contribution(model.pilots.vmg.DD, out);

    case FieldId::runtime_last_publish_period_s: out = model.runtime_publication.last_publish_period_s.value; return model.runtime_publication.last_publish_period_s.valid;
    case FieldId::runtime_published_value_count: out = static_cast<Real>(model.runtime_publication.published_value_count.value); return model.runtime_publication.published_value_count.valid;
    case FieldId::runtime_dropped_value_count: out = static_cast<Real>(model.runtime_publication.dropped_value_count.value); return model.runtime_publication.dropped_value_count.valid;
    default: return false;
    }
}

template<typename Real>
inline bool apply_bool(DataModel<Real>& model, FieldId id, bool value, uint64_t) {
    switch (id) {
    case FieldId::server_enabled: model.server.enabled.value = value; return true;
    case FieldId::server_persistent: model.server.persistent.value = value; return true;
    case FieldId::server_watchdog_enabled: model.server.watchdog_enabled.value = value; return true;
    case FieldId::ap_enabled: model.ap.enabled.value = value; return true;
    case FieldId::ap_tack_enabled: model.tack.enabled.value = value; return true;
    case FieldId::pilot_output_saturated: model.pilot_output.saturated.value = value; return true;
    case FieldId::pilot_output_fault: model.pilot_output.pilot_fault.value = value; return true;
    case FieldId::imu_state_enabled: model.imu_state.enabled.value = value; return true;
    case FieldId::imu_state_present: model.imu_state.present.value = value; return true;
    case FieldId::imu_state_healthy: model.imu_state.healthy.value = value; return true;
    case FieldId::imu_calibration_accel_valid: model.imu_calibration.accel.valid.value = value; return true;
    case FieldId::imu_calibration_compass_valid: model.imu_calibration.compass.valid.value = value; return true;
    case FieldId::imu_calibration_gyro_valid: model.imu_calibration.gyro.valid.value = value; return true;
    case FieldId::servo_engaged: model.servo.engaged.value = value; return true;
    default: return false;
    }
}

template<typename Real>
inline bool read_bool(const DataModel<Real>& model, FieldId id, bool& out) {
    switch (id) {
    case FieldId::server_enabled: out = model.server.enabled.value; return true;
    case FieldId::ap_enabled: out = model.ap.enabled.value; return true;
    case FieldId::ap_tack_enabled: out = model.tack.enabled.value; return true;
    case FieldId::pilot_output_saturated: out = model.pilot_output.saturated.value; return true;
    case FieldId::pilot_output_fault: out = model.pilot_output.pilot_fault.value; return true;
    case FieldId::imu_state_present: out = model.imu_state.present.value; return true;
    case FieldId::imu_state_healthy: out = model.imu_state.healthy.value; return true;
    case FieldId::servo_engaged: out = model.servo.engaged.value; return true;
    default: return false;
    }
}

template<typename Real>
inline bool apply_source(DataModel<Real>& model, FieldId id, SensorSource value, uint64_t) {
    switch (id) {
    case FieldId::wind_source: model.wind.apparent.source.value = value; return true;
    case FieldId::truewind_source: model.wind.truewind.source.value = value; return true;
    case FieldId::gps_source: model.navigation.gps.source.value = value; return true;
    case FieldId::apb_source: model.navigation.apb.source.value = value; return true;
    default: return false;
    }
}

template<typename Real>
inline bool read_source(const DataModel<Real>& model, FieldId id, SensorSource& out) {
    switch (id) {
    case FieldId::wind_source: out = model.wind.apparent.source.value; return true;
    case FieldId::truewind_source: out = model.wind.truewind.source.value; return true;
    case FieldId::gps_source: out = model.navigation.gps.source.value; return true;
    case FieldId::apb_source: out = model.navigation.apb.source.value; return true;
    default: return false;
    }
}

template<typename Real>
inline bool apply_mode(DataModel<Real>& model, FieldId id, AutopilotMode value, uint64_t now_us) {
    switch (id) {
    case FieldId::ap_mode: model.ap.mode.value = value; return true;
    case FieldId::ap_preferred_mode: model.ap.preferred_mode.value = value; return true;
    case FieldId::apb_mode_hint: model.navigation.apb.mode_hint.value = value; return true;
    case FieldId::pilot_command_source: (void)now_us; return false;
    default: return false;
    }
}

template<typename Real>
inline bool read_mode(const DataModel<Real>& model, FieldId id, AutopilotMode& out) {
    switch (id) {
    case FieldId::ap_mode: out = model.ap.mode.value; return true;
    case FieldId::ap_preferred_mode: out = model.ap.preferred_mode.value; return true;
    case FieldId::apb_mode_hint: out = model.navigation.apb.mode_hint.value; return true;
    default: return false;
    }
}

template<typename Real>
inline bool apply_pilot(DataModel<Real>& model, FieldId id, PilotName value, uint64_t now_us) {
    switch (id) {
    case FieldId::ap_pilot: model.ap.pilot.value = value; return true;
    case FieldId::pilot_command_source: (void)now_us; return false;
    default: return false;
    }
}

template<typename Real>
inline bool read_pilot(const DataModel<Real>& model, FieldId id, PilotName& out) {
    switch (id) {
    case FieldId::ap_pilot: out = model.ap.pilot.value; return true;
    default: return false;
    }
}

template<typename Real>
inline bool apply_rudder_calibration_state(DataModel<Real>& model, FieldId id, RudderCalibrationState value, uint64_t) {
    if (id == FieldId::rudder_calibration_state) {
        model.rudder.calibration_state.value = value;
        return true;
    }
    return false;
}

template<typename Real>
inline bool apply_string(DataModel<Real>& model, FieldId id, const char* value, uint64_t) {
    if (!value) return false;
    switch (id) {
    case FieldId::server_version: copy_field_string(model.server.version, sizeof(model.server.version), value); return true;
    case FieldId::server_hostname: copy_field_string(model.server.hostname, sizeof(model.server.hostname), value); return true;
    case FieldId::server_config_dir: copy_field_string(model.server.config_dir, sizeof(model.server.config_dir), value); return true;
    case FieldId::server_profile_name: copy_field_string(model.server.profile_name, sizeof(model.server.profile_name), value); return true;
    case FieldId::status_last_error: copy_field_string(model.status.last_error, sizeof(model.status.last_error), value); return true;
    case FieldId::status_last_warning: copy_field_string(model.status.last_warning, sizeof(model.status.last_warning), value); return true;
    case FieldId::pilot_output_active_name: copy_field_string(model.pilot_output.active_pilot_name, sizeof(model.pilot_output.active_pilot_name), value); return true;
    case FieldId::imu_state_device: copy_field_string(model.imu_state.device, sizeof(model.imu_state.device), value); return true;
    case FieldId::imu_state_driver: copy_field_string(model.imu_state.driver, sizeof(model.imu_state.driver), value); return true;
    case FieldId::apb_sender_id:
        model.navigation.apb.sender_id[0] = value[0] ? value[0] : '\0';
        model.navigation.apb.sender_id[1] = value[0] && value[1] ? value[1] : '\0';
        model.navigation.apb.sender_id[2] = '\0';
        return true;
    default: return false;
    }
}

template<typename Real>
inline bool read_string(const DataModel<Real>& model, FieldId id, const char*& out) {
    switch (id) {
    case FieldId::server_version: out = model.server.version; return model.server.version[0] != '\0';
    case FieldId::server_hostname: out = model.server.hostname; return model.server.hostname[0] != '\0';
    case FieldId::server_config_dir: out = model.server.config_dir; return model.server.config_dir[0] != '\0';
    case FieldId::server_profile_name: out = model.server.profile_name; return model.server.profile_name[0] != '\0';
    case FieldId::status_last_error: out = model.status.last_error; return model.status.last_error[0] != '\0';
    case FieldId::status_last_warning: out = model.status.last_warning; return model.status.last_warning[0] != '\0';
    case FieldId::pilot_output_active_name: out = model.pilot_output.active_pilot_name; return model.pilot_output.active_pilot_name[0] != '\0';
    case FieldId::imu_state_device: out = model.imu_state.device; return model.imu_state.device[0] != '\0';
    case FieldId::imu_state_driver: out = model.imu_state.driver; return model.imu_state.driver[0] != '\0';
    case FieldId::apb_sender_id: out = model.navigation.apb.sender_id; return model.navigation.apb.sender_id[0] != '\0';
    default: return false;
    }
}

} // namespace pypilot_data_model
