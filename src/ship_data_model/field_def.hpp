#pragma once

#include <stddef.h>

namespace ship_data_model {

enum class FieldId {
    unknown,
    compat_value,
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
    servo_flags,
    servo_telemetry_state,
    rudder_calibration_state,
    imu_calibration_heading_offset_deg,
    pilot_basic_P,
    pilot_basic_Pgain
};

enum class FieldType {
    number,
    integer,
    boolean,
    string_value,
    mode_enum,
    pilot_enum,
    source_enum,
    rudder_calibration_enum,
    servo_state_enum
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

#define SHIP_DATA_MODEL_COMPAT_FIELD(name) {FieldId::compat_value, name, "", FieldType::number, false, false, false},
#define SHIP_DATA_MODEL_COMPAT_FIELD_ROWS \
    SHIP_DATA_MODEL_COMPAT_FIELD("ap.version") \
    SHIP_DATA_MODEL_COMPAT_FIELD("ap.preferred_mode") \
    SHIP_DATA_MODEL_COMPAT_FIELD("ap.mode") \
    SHIP_DATA_MODEL_COMPAT_FIELD("ap.modes") \
    SHIP_DATA_MODEL_COMPAT_FIELD("ap.gps_and_nav_modes") \
    SHIP_DATA_MODEL_COMPAT_FIELD("ap.heading_command") \
    SHIP_DATA_MODEL_COMPAT_FIELD("ap.enabled") \
    SHIP_DATA_MODEL_COMPAT_FIELD("ap.heading") \
    SHIP_DATA_MODEL_COMPAT_FIELD("ap.heading_error") \
    SHIP_DATA_MODEL_COMPAT_FIELD("ap.heading_error_int") \
    SHIP_DATA_MODEL_COMPAT_FIELD("ap.heading_command_rate") \
    SHIP_DATA_MODEL_COMPAT_FIELD("ap.pilot") \
    SHIP_DATA_MODEL_COMPAT_FIELD("ap.gps_compass_offset") \
    SHIP_DATA_MODEL_COMPAT_FIELD("ap.wind_compass_offset") \
    SHIP_DATA_MODEL_COMPAT_FIELD("ap.true_wind_compass_offset") \
    SHIP_DATA_MODEL_COMPAT_FIELD("ap.wind_offset_filter") \
    SHIP_DATA_MODEL_COMPAT_FIELD("ap.runtime") \
    SHIP_DATA_MODEL_COMPAT_FIELD("ap.timings") \
    SHIP_DATA_MODEL_COMPAT_FIELD("imu.rate") \
    SHIP_DATA_MODEL_COMPAT_FIELD("imu.frequency") \
    SHIP_DATA_MODEL_COMPAT_FIELD("imu.alignmentQ") \
    SHIP_DATA_MODEL_COMPAT_FIELD("imu.heading_offset") \
    SHIP_DATA_MODEL_COMPAT_FIELD("imu.alignmentCounter") \
    SHIP_DATA_MODEL_COMPAT_FIELD("imu.uptime") \
    SHIP_DATA_MODEL_COMPAT_FIELD("imu.warning") \
    SHIP_DATA_MODEL_COMPAT_FIELD("imu.heading_lowpass_constant") \
    SHIP_DATA_MODEL_COMPAT_FIELD("imu.headingrate_lowpass_constant") \
    SHIP_DATA_MODEL_COMPAT_FIELD("imu.headingraterate_lowpass_constant") \
    SHIP_DATA_MODEL_COMPAT_FIELD("imu.accel") \
    SHIP_DATA_MODEL_COMPAT_FIELD("imu.gyro") \
    SHIP_DATA_MODEL_COMPAT_FIELD("imu.compass") \
    SHIP_DATA_MODEL_COMPAT_FIELD("imu.accel.residuals") \
    SHIP_DATA_MODEL_COMPAT_FIELD("imu.pitch") \
    SHIP_DATA_MODEL_COMPAT_FIELD("imu.roll") \
    SHIP_DATA_MODEL_COMPAT_FIELD("imu.fusionQPose") \
    SHIP_DATA_MODEL_COMPAT_FIELD("imu.heading") \
    SHIP_DATA_MODEL_COMPAT_FIELD("imu.heading_lowpass") \
    SHIP_DATA_MODEL_COMPAT_FIELD("imu.headingrate") \
    SHIP_DATA_MODEL_COMPAT_FIELD("imu.headingrate_lowpass") \
    SHIP_DATA_MODEL_COMPAT_FIELD("imu.headingraterate") \
    SHIP_DATA_MODEL_COMPAT_FIELD("imu.headingraterate_lowpass") \
    SHIP_DATA_MODEL_COMPAT_FIELD("imu.pitchrate") \
    SHIP_DATA_MODEL_COMPAT_FIELD("imu.rollrate") \
    SHIP_DATA_MODEL_COMPAT_FIELD("imu.gyrobias") \
    SHIP_DATA_MODEL_COMPAT_FIELD("gps.source") \
    SHIP_DATA_MODEL_COMPAT_FIELD("gps.rate") \
    SHIP_DATA_MODEL_COMPAT_FIELD("gps.track") \
    SHIP_DATA_MODEL_COMPAT_FIELD("gps.speed") \
    SHIP_DATA_MODEL_COMPAT_FIELD("gps.fix") \
    SHIP_DATA_MODEL_COMPAT_FIELD("gps.leeway_ground") \
    SHIP_DATA_MODEL_COMPAT_FIELD("gps.compass_error") \
    SHIP_DATA_MODEL_COMPAT_FIELD("gps.declination") \
    SHIP_DATA_MODEL_COMPAT_FIELD("gps.alignmentCounter") \
    SHIP_DATA_MODEL_COMPAT_FIELD("wind.source") \
    SHIP_DATA_MODEL_COMPAT_FIELD("wind.rate") \
    SHIP_DATA_MODEL_COMPAT_FIELD("wind.direction") \
    SHIP_DATA_MODEL_COMPAT_FIELD("wind.speed") \
    SHIP_DATA_MODEL_COMPAT_FIELD("wind.offset") \
    SHIP_DATA_MODEL_COMPAT_FIELD("wind.sensors_height") \
    SHIP_DATA_MODEL_COMPAT_FIELD("wind.filtered_speed") \
    SHIP_DATA_MODEL_COMPAT_FIELD("wind.filtered_direction") \
    SHIP_DATA_MODEL_COMPAT_FIELD("wind.filter_constant") \
    SHIP_DATA_MODEL_COMPAT_FIELD("wind.filter_factor") \
    SHIP_DATA_MODEL_COMPAT_FIELD("truewind.source") \
    SHIP_DATA_MODEL_COMPAT_FIELD("truewind.rate") \
    SHIP_DATA_MODEL_COMPAT_FIELD("truewind.direction") \
    SHIP_DATA_MODEL_COMPAT_FIELD("truewind.speed") \
    SHIP_DATA_MODEL_COMPAT_FIELD("truewind.offset") \
    SHIP_DATA_MODEL_COMPAT_FIELD("truewind.sensors_height") \
    SHIP_DATA_MODEL_COMPAT_FIELD("truewind.filtered_speed") \
    SHIP_DATA_MODEL_COMPAT_FIELD("truewind.filtered_direction") \
    SHIP_DATA_MODEL_COMPAT_FIELD("truewind.filter_constant") \
    SHIP_DATA_MODEL_COMPAT_FIELD("truewind.filter_factor") \
    SHIP_DATA_MODEL_COMPAT_FIELD("apb.source") \
    SHIP_DATA_MODEL_COMPAT_FIELD("apb.track") \
    SHIP_DATA_MODEL_COMPAT_FIELD("apb.xte") \
    SHIP_DATA_MODEL_COMPAT_FIELD("apb.xte.gain") \
    SHIP_DATA_MODEL_COMPAT_FIELD("water.source") \
    SHIP_DATA_MODEL_COMPAT_FIELD("water.rate") \
    SHIP_DATA_MODEL_COMPAT_FIELD("water.speed") \
    SHIP_DATA_MODEL_COMPAT_FIELD("water.leeway") \
    SHIP_DATA_MODEL_COMPAT_FIELD("water.leeway.source") \
    SHIP_DATA_MODEL_COMPAT_FIELD("water.current.speed") \
    SHIP_DATA_MODEL_COMPAT_FIELD("water.current.direction") \
    SHIP_DATA_MODEL_COMPAT_FIELD("water.wind.speed") \
    SHIP_DATA_MODEL_COMPAT_FIELD("water.wind.direction") \
    SHIP_DATA_MODEL_COMPAT_FIELD("rudder.source") \
    SHIP_DATA_MODEL_COMPAT_FIELD("rudder.rate") \
    SHIP_DATA_MODEL_COMPAT_FIELD("rudder.angle") \
    SHIP_DATA_MODEL_COMPAT_FIELD("rudder.speed") \
    SHIP_DATA_MODEL_COMPAT_FIELD("rudder.offset") \
    SHIP_DATA_MODEL_COMPAT_FIELD("rudder.scale") \
    SHIP_DATA_MODEL_COMPAT_FIELD("rudder.nonlinearity") \
    SHIP_DATA_MODEL_COMPAT_FIELD("rudder.calibration_state") \
    SHIP_DATA_MODEL_COMPAT_FIELD("rudder.range") \
    SHIP_DATA_MODEL_COMPAT_FIELD("servo.calibration") \
    SHIP_DATA_MODEL_COMPAT_FIELD("servo.position_command") \
    SHIP_DATA_MODEL_COMPAT_FIELD("servo.command") \
    SHIP_DATA_MODEL_COMPAT_FIELD("servo.speed_gain") \
    SHIP_DATA_MODEL_COMPAT_FIELD("servo.duty") \
    SHIP_DATA_MODEL_COMPAT_FIELD("servo.faults") \
    SHIP_DATA_MODEL_COMPAT_FIELD("servo.voltage") \
    SHIP_DATA_MODEL_COMPAT_FIELD("servo.current") \
    SHIP_DATA_MODEL_COMPAT_FIELD("servo.current.noise") \
    SHIP_DATA_MODEL_COMPAT_FIELD("servo.controller_temp") \
    SHIP_DATA_MODEL_COMPAT_FIELD("servo.motor_temp") \
    SHIP_DATA_MODEL_COMPAT_FIELD("servo.engaged") \
    SHIP_DATA_MODEL_COMPAT_FIELD("servo.max_current") \
    SHIP_DATA_MODEL_COMPAT_FIELD("servo.current.factor") \
    SHIP_DATA_MODEL_COMPAT_FIELD("servo.current.offset") \
    SHIP_DATA_MODEL_COMPAT_FIELD("servo.voltage.factor") \
    SHIP_DATA_MODEL_COMPAT_FIELD("servo.voltage.offset") \
    SHIP_DATA_MODEL_COMPAT_FIELD("servo.max_controller_temp") \
    SHIP_DATA_MODEL_COMPAT_FIELD("servo.max_motor_temp") \
    SHIP_DATA_MODEL_COMPAT_FIELD("servo.max_slew_speed") \
    SHIP_DATA_MODEL_COMPAT_FIELD("servo.max_slew_slow") \
    SHIP_DATA_MODEL_COMPAT_FIELD("servo.gain") \
    SHIP_DATA_MODEL_COMPAT_FIELD("servo.clutch_pwm") \
    SHIP_DATA_MODEL_COMPAT_FIELD("servo.use_brake") \
    SHIP_DATA_MODEL_COMPAT_FIELD("servo.period") \
    SHIP_DATA_MODEL_COMPAT_FIELD("servo.compensate_current") \
    SHIP_DATA_MODEL_COMPAT_FIELD("servo.compensate_voltage") \
    SHIP_DATA_MODEL_COMPAT_FIELD("servo.amp_hours") \
    SHIP_DATA_MODEL_COMPAT_FIELD("servo.watts") \
    SHIP_DATA_MODEL_COMPAT_FIELD("servo.speed") \
    SHIP_DATA_MODEL_COMPAT_FIELD("servo.speed.min") \
    SHIP_DATA_MODEL_COMPAT_FIELD("servo.speed.max") \
    SHIP_DATA_MODEL_COMPAT_FIELD("servo.position") \
    SHIP_DATA_MODEL_COMPAT_FIELD("servo.position.p") \
    SHIP_DATA_MODEL_COMPAT_FIELD("servo.position.i") \
    SHIP_DATA_MODEL_COMPAT_FIELD("servo.position.d") \
    SHIP_DATA_MODEL_COMPAT_FIELD("servo.raw_command") \
    SHIP_DATA_MODEL_COMPAT_FIELD("servo.use_eeprom") \
    SHIP_DATA_MODEL_COMPAT_FIELD("servo.state") \
    SHIP_DATA_MODEL_COMPAT_FIELD("servo.controller") \
    SHIP_DATA_MODEL_COMPAT_FIELD("servo.flags") \
    SHIP_DATA_MODEL_COMPAT_FIELD("ap.tack.state") \
    SHIP_DATA_MODEL_COMPAT_FIELD("ap.tack.timeout") \
    SHIP_DATA_MODEL_COMPAT_FIELD("ap.tack.delay") \
    SHIP_DATA_MODEL_COMPAT_FIELD("ap.tack.angle") \
    SHIP_DATA_MODEL_COMPAT_FIELD("ap.tack.rate") \
    SHIP_DATA_MODEL_COMPAT_FIELD("ap.tack.threshold") \
    SHIP_DATA_MODEL_COMPAT_FIELD("ap.tack.count") \
    SHIP_DATA_MODEL_COMPAT_FIELD("ap.tack.direction") \
    SHIP_DATA_MODEL_COMPAT_FIELD("ap.tack.use_heel") \
    SHIP_DATA_MODEL_COMPAT_FIELD("ap.tack.use_wind_direction") \
    SHIP_DATA_MODEL_COMPAT_FIELD("ap.pilot.basic.P") \
    SHIP_DATA_MODEL_COMPAT_FIELD("ap.pilot.basic.Pgain") \
    SHIP_DATA_MODEL_COMPAT_FIELD("ap.pilot.basic.D") \
    SHIP_DATA_MODEL_COMPAT_FIELD("ap.pilot.basic.Dgain") \
    SHIP_DATA_MODEL_COMPAT_FIELD("ap.pilot.basic.DD") \
    SHIP_DATA_MODEL_COMPAT_FIELD("ap.pilot.basic.DDgain") \
    SHIP_DATA_MODEL_COMPAT_FIELD("ap.pilot.basic.PR") \
    SHIP_DATA_MODEL_COMPAT_FIELD("ap.pilot.basic.PRgain") \
    SHIP_DATA_MODEL_COMPAT_FIELD("ap.pilot.basic.FF") \
    SHIP_DATA_MODEL_COMPAT_FIELD("ap.pilot.basic.FFgain") \
    SHIP_DATA_MODEL_COMPAT_FIELD("ap.pilot.wind.gps_wind_offset") \
    SHIP_DATA_MODEL_COMPAT_FIELD("ap.pilot.wind.P") \
    SHIP_DATA_MODEL_COMPAT_FIELD("ap.pilot.wind.Pgain") \
    SHIP_DATA_MODEL_COMPAT_FIELD("ap.pilot.wind.D") \
    SHIP_DATA_MODEL_COMPAT_FIELD("ap.pilot.wind.Dgain") \
    SHIP_DATA_MODEL_COMPAT_FIELD("ap.pilot.wind.DD") \
    SHIP_DATA_MODEL_COMPAT_FIELD("ap.pilot.wind.DDgain") \
    SHIP_DATA_MODEL_COMPAT_FIELD("ap.pilot.wind.WG") \
    SHIP_DATA_MODEL_COMPAT_FIELD("ap.pilot.wind.WGgain") \
    SHIP_DATA_MODEL_COMPAT_FIELD("ap.pilot.absolute.P") \
    SHIP_DATA_MODEL_COMPAT_FIELD("ap.pilot.absolute.Pgain") \
    SHIP_DATA_MODEL_COMPAT_FIELD("ap.pilot.absolute.I") \
    SHIP_DATA_MODEL_COMPAT_FIELD("ap.pilot.absolute.Igain") \
    SHIP_DATA_MODEL_COMPAT_FIELD("ap.pilot.absolute.D") \
    SHIP_DATA_MODEL_COMPAT_FIELD("ap.pilot.absolute.Dgain") \
    SHIP_DATA_MODEL_COMPAT_FIELD("ap.pilot.absolute.FF") \
    SHIP_DATA_MODEL_COMPAT_FIELD("ap.pilot.absolute.FFgain") \
    SHIP_DATA_MODEL_COMPAT_FIELD("ap.pilot.rate.D") \
    SHIP_DATA_MODEL_COMPAT_FIELD("ap.pilot.rate.Dgain") \
    SHIP_DATA_MODEL_COMPAT_FIELD("ap.pilot.rate.DD") \
    SHIP_DATA_MODEL_COMPAT_FIELD("ap.pilot.rate.DDgain") \
    SHIP_DATA_MODEL_COMPAT_FIELD("ap.pilot.rate.FF") \
    SHIP_DATA_MODEL_COMPAT_FIELD("ap.pilot.rate.FFgain") \
    SHIP_DATA_MODEL_COMPAT_FIELD("ap.pilot.rate.maxturnrate") \
    SHIP_DATA_MODEL_COMPAT_FIELD("ap.pilot.rate.turnraterate") \
    SHIP_DATA_MODEL_COMPAT_FIELD("ap.pilot.simple.P") \
    SHIP_DATA_MODEL_COMPAT_FIELD("ap.pilot.simple.Pgain") \
    SHIP_DATA_MODEL_COMPAT_FIELD("ap.pilot.simple.I") \
    SHIP_DATA_MODEL_COMPAT_FIELD("ap.pilot.simple.Igain") \
    SHIP_DATA_MODEL_COMPAT_FIELD("ap.pilot.simple.D") \
    SHIP_DATA_MODEL_COMPAT_FIELD("ap.pilot.simple.Dgain") \
    SHIP_DATA_MODEL_COMPAT_FIELD("ap.pilot.vmg.P") \
    SHIP_DATA_MODEL_COMPAT_FIELD("ap.pilot.vmg.Pgain") \
    SHIP_DATA_MODEL_COMPAT_FIELD("ap.pilot.vmg.D") \
    SHIP_DATA_MODEL_COMPAT_FIELD("ap.pilot.vmg.Dgain") \
    SHIP_DATA_MODEL_COMPAT_FIELD("ap.pilot.vmg.DD") \
    SHIP_DATA_MODEL_COMPAT_FIELD("ap.pilot.vmg.DDgain") \
    SHIP_DATA_MODEL_COMPAT_FIELD("ap.pilot.deadzone.deadzone") \
    SHIP_DATA_MODEL_COMPAT_FIELD("ap.pilot.fuzzy.learningP") \
    SHIP_DATA_MODEL_COMPAT_FIELD("ap.pilot.fuzzy.learningD") \
    SHIP_DATA_MODEL_COMPAT_FIELD("ap.pilot.fuzzy.seastate") \
    SHIP_DATA_MODEL_COMPAT_FIELD("ap.pilot.learning.P") \
    SHIP_DATA_MODEL_COMPAT_FIELD("ap.pilot.learning.Pgain") \
    SHIP_DATA_MODEL_COMPAT_FIELD("ap.pilot.learning.D") \
    SHIP_DATA_MODEL_COMPAT_FIELD("ap.pilot.learning.Dgain") \
    SHIP_DATA_MODEL_COMPAT_FIELD("ap.pilot.learning.W") \
    SHIP_DATA_MODEL_COMPAT_FIELD("ap.pilot.learning.Wgain")

static constexpr FieldMeta field_definitions[] = {
    {FieldId::compat_value, "compat.value", "", FieldType::number, false, false, false},
    {FieldId::server_version, "server.version", "", FieldType::string_value, false, false, false},
    {FieldId::server_version, "ap.version", "", FieldType::string_value, false, false, false},
    {FieldId::server_uptime_s, "server.uptime", "s", FieldType::number, false, false, false},
    {FieldId::status_last_error, "status.last_error", "", FieldType::string_value, false, false, false},
    {FieldId::ap_enabled, "ap.enabled", "", FieldType::boolean, true, false, false},
    {FieldId::ap_mode, "ap.mode", "", FieldType::mode_enum, true, true, false},
    {FieldId::ap_pilot, "ap.pilot", "", FieldType::pilot_enum, true, true, true},
    {FieldId::ap_heading_deg, "ap.heading", "deg", FieldType::number, false, false, false},
    {FieldId::ap_tack_progress_0_1, "ap.tack.progress", "", FieldType::number, false, false, false},
    {FieldId::wind_source, "wind.source", "", FieldType::source_enum, true, true, false},
    {FieldId::wind_filtered_direction_deg, "wind.filtered_direction", "deg", FieldType::number, false, false, false},
    {FieldId::servo_current_a, "servo.current", "A", FieldType::number, false, false, false},
    {FieldId::servo_telemetry_current_a, "servo.telemetry.current", "A", FieldType::number, false, false, false},
    {FieldId::servo_flags, "servo.flags", "", FieldType::integer, false, false, false},
    {FieldId::servo_telemetry_state, "servo.state", "", FieldType::servo_state_enum, false, false, false},
    {FieldId::rudder_calibration_state, "rudder.calibration_state", "", FieldType::rudder_calibration_enum, true, true, false},
    {FieldId::imu_calibration_heading_offset_deg, "imu.heading_offset", "deg", FieldType::number, true, true, false},
    {FieldId::pilot_basic_P, "ap.pilot.basic.P", "", FieldType::number, true, true, true},
    {FieldId::pilot_basic_P, "ap.pilot.learning.P", "", FieldType::number, true, true, true},
    {FieldId::pilot_basic_Pgain, "ap.pilot.basic.Pgain", "", FieldType::number, false, false, true},
    {FieldId::pilot_basic_Pgain, "ap.pilot.learning.Pgain", "", FieldType::number, false, false, true},
    SHIP_DATA_MODEL_COMPAT_FIELD_ROWS
};

#undef SHIP_DATA_MODEL_COMPAT_FIELD_ROWS
#undef SHIP_DATA_MODEL_COMPAT_FIELD

static constexpr size_t field_definition_count = sizeof(field_definitions) / sizeof(field_definitions[0]);

} // namespace ship_data_model
