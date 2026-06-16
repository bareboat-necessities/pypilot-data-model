#pragma once

#include "data_model.hpp"
#include "field_id.hpp"

namespace pypilot_data_model {

template<typename Real>
inline bool apply_number(DataModel<Real>& model, FieldId id, Real value, uint64_t now_us) {
    switch (id) {
    case FieldId::ap_heading_deg: model.ap.heading_deg.set(value, now_us); return true;
    case FieldId::ap_heading_command_deg: model.ap.heading_command_deg.set(value, now_us); return true;
    case FieldId::ap_heading_error_deg: model.ap.heading_error_deg.set(value, now_us); return true;
    case FieldId::ap_heading_error_int_deg: model.ap.heading_error_int_deg.set(value, now_us); return true;
    case FieldId::ap_heading_command_rate_deg_s: model.ap.heading_command_rate_deg_s.set(value, now_us); return true;
    case FieldId::ap_runtime_s: model.ap.runtime_s.set(value, now_us); return true;

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

    case FieldId::pilot_basic_P: model.pilots.basic.P.gain.value = value; return true;
    case FieldId::pilot_basic_Pgain: model.pilots.basic.P.contribution.set(value, now_us); return true;
    case FieldId::pilot_basic_D: model.pilots.basic.D.gain.value = value; return true;
    case FieldId::pilot_basic_Dgain: model.pilots.basic.D.contribution.set(value, now_us); return true;
    case FieldId::pilot_basic_DD: model.pilots.basic.DD.gain.value = value; return true;
    case FieldId::pilot_basic_DDgain: model.pilots.basic.DD.contribution.set(value, now_us); return true;
    case FieldId::pilot_basic_PR: model.pilots.basic.PR.gain.value = value; return true;
    case FieldId::pilot_basic_PRgain: model.pilots.basic.PR.contribution.set(value, now_us); return true;
    case FieldId::pilot_basic_FF: model.pilots.basic.FF.gain.value = value; return true;
    case FieldId::pilot_basic_FFgain: model.pilots.basic.FF.contribution.set(value, now_us); return true;

    case FieldId::pilot_wind_gps_wind_offset_deg: model.pilots.wind.gps_wind_offset_deg.set(value, now_us); return true;
    case FieldId::pilot_wind_P: model.pilots.wind.P.gain.value = value; return true;
    case FieldId::pilot_wind_Pgain: model.pilots.wind.P.contribution.set(value, now_us); return true;
    case FieldId::pilot_wind_D: model.pilots.wind.D.gain.value = value; return true;
    case FieldId::pilot_wind_Dgain: model.pilots.wind.D.contribution.set(value, now_us); return true;
    case FieldId::pilot_wind_DD: model.pilots.wind.DD.gain.value = value; return true;
    case FieldId::pilot_wind_DDgain: model.pilots.wind.DD.contribution.set(value, now_us); return true;
    case FieldId::pilot_wind_WG: model.pilots.wind.WG.gain.value = value; return true;
    case FieldId::pilot_wind_WGgain: model.pilots.wind.WG.contribution.set(value, now_us); return true;

    case FieldId::pilot_absolute_P: model.pilots.absolute.P.gain.value = value; return true;
    case FieldId::pilot_absolute_Pgain: model.pilots.absolute.P.contribution.set(value, now_us); return true;
    case FieldId::pilot_absolute_I: model.pilots.absolute.I.gain.value = value; return true;
    case FieldId::pilot_absolute_Igain: model.pilots.absolute.I.contribution.set(value, now_us); return true;
    case FieldId::pilot_absolute_D: model.pilots.absolute.D.gain.value = value; return true;
    case FieldId::pilot_absolute_Dgain: model.pilots.absolute.D.contribution.set(value, now_us); return true;
    case FieldId::pilot_absolute_FF: model.pilots.absolute.FF.gain.value = value; return true;
    case FieldId::pilot_absolute_FFgain: model.pilots.absolute.FF.contribution.set(value, now_us); return true;

    case FieldId::pilot_rate_D: model.pilots.rate.D.gain.value = value; return true;
    case FieldId::pilot_rate_Dgain: model.pilots.rate.D.contribution.set(value, now_us); return true;
    case FieldId::pilot_rate_DD: model.pilots.rate.DD.gain.value = value; return true;
    case FieldId::pilot_rate_DDgain: model.pilots.rate.DD.contribution.set(value, now_us); return true;
    case FieldId::pilot_rate_FF: model.pilots.rate.FF.gain.value = value; return true;
    case FieldId::pilot_rate_FFgain: model.pilots.rate.FF.contribution.set(value, now_us); return true;
    case FieldId::pilot_rate_maxturnrate_deg_s: model.pilots.rate.max_turn_rate_deg_s.value = value; return true;
    case FieldId::pilot_rate_turnraterate_deg_s2: model.pilots.rate.turn_rate_rate_deg_s2.value = value; return true;

    case FieldId::pilot_simple_P: model.pilots.simple.P.gain.value = value; return true;
    case FieldId::pilot_simple_Pgain: model.pilots.simple.P.contribution.set(value, now_us); return true;
    case FieldId::pilot_simple_I: model.pilots.simple.I.gain.value = value; return true;
    case FieldId::pilot_simple_Igain: model.pilots.simple.I.contribution.set(value, now_us); return true;
    case FieldId::pilot_simple_D: model.pilots.simple.D.gain.value = value; return true;
    case FieldId::pilot_simple_Dgain: model.pilots.simple.D.contribution.set(value, now_us); return true;

    case FieldId::pilot_vmg_P: model.pilots.vmg.P.gain.value = value; return true;
    case FieldId::pilot_vmg_Pgain: model.pilots.vmg.P.contribution.set(value, now_us); return true;
    case FieldId::pilot_vmg_D: model.pilots.vmg.D.gain.value = value; return true;
    case FieldId::pilot_vmg_Dgain: model.pilots.vmg.D.contribution.set(value, now_us); return true;
    case FieldId::pilot_vmg_DD: model.pilots.vmg.DD.gain.value = value; return true;
    case FieldId::pilot_vmg_DDgain: model.pilots.vmg.DD.contribution.set(value, now_us); return true;

    default: return false;
    }
}

template<typename Real>
inline bool read_number(const DataModel<Real>& model, FieldId id, Real& out) {
    switch (id) {
    case FieldId::ap_heading_deg: out = model.ap.heading_deg.value; return model.ap.heading_deg.valid;
    case FieldId::ap_heading_command_deg: out = model.ap.heading_command_deg.value; return model.ap.heading_command_deg.valid;
    case FieldId::ap_heading_error_deg: out = model.ap.heading_error_deg.value; return model.ap.heading_error_deg.valid;
    case FieldId::imu_heading_lowpass_deg: out = model.imu.heading_lowpass_deg.value; return model.imu.heading_lowpass_deg.valid;
    case FieldId::wind_filtered_direction_deg: out = model.wind.apparent.filtered_direction_deg.value; return model.wind.apparent.filtered_direction_deg.valid;
    case FieldId::wind_speed_kn: out = model.wind.apparent.speed_kn.value; return model.wind.apparent.speed_kn.valid;
    case FieldId::gps_speed_kn: out = model.navigation.gps.speed_kn.value; return model.navigation.gps.speed_kn.valid;
    case FieldId::servo_current_a: out = model.servo.current_a.value; return model.servo.current_a.valid;
    case FieldId::servo_command_norm: out = model.servo.command_norm.value; return model.servo.command_norm.valid;
    case FieldId::pilot_basic_P: out = model.pilots.basic.P.gain.value; return true;
    case FieldId::pilot_basic_Pgain: out = model.pilots.basic.P.contribution.value; return model.pilots.basic.P.contribution.valid;
    default: return false;
    }
}

template<typename Real>
inline bool apply_bool(DataModel<Real>& model, FieldId id, bool value, uint64_t) {
    switch (id) {
    case FieldId::ap_enabled: model.ap.enabled.value = value; return true;
    case FieldId::servo_engaged: model.servo.engaged.value = value; return true;
    default: return false;
    }
}

template<typename Real>
inline bool read_bool(const DataModel<Real>& model, FieldId id, bool& out) {
    switch (id) {
    case FieldId::ap_enabled: out = model.ap.enabled.value; return true;
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
    default: return false;
    }
}

template<typename Real>
inline bool apply_mode(DataModel<Real>& model, FieldId id, AutopilotMode value, uint64_t) {
    if (id == FieldId::ap_mode) {
        model.ap.mode.value = value;
        return true;
    }
    return false;
}

template<typename Real>
inline bool apply_pilot(DataModel<Real>& model, FieldId id, PilotName value, uint64_t) {
    if (id == FieldId::ap_pilot) {
        model.ap.pilot.value = value;
        return true;
    }
    return false;
}

template<typename Real>
inline bool apply_rudder_calibration_state(DataModel<Real>& model, FieldId id, RudderCalibrationState value, uint64_t) {
    if (id == FieldId::rudder_calibration_state) {
        model.rudder.calibration_state.value = value;
        return true;
    }
    return false;
}

} // namespace pypilot_data_model
