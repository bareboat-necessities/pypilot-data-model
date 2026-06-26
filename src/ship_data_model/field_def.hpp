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
    servo_state_enum,
    object_value,
    vector3_value,
    quaternion_value,
    tack_state_enum,
    tack_direction_enum,
    unknown_value
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

#define FIELD_CMD_NUMBER(name) {FieldId::compat_value, name, "", FieldType::number, true, false, false},
#define FIELD_CMD_NUMBER_DEG(name) {FieldId::compat_value, name, "deg", FieldType::number, true, false, false},
#define FIELD_CMD_TACK_DIRECTION_ENUM(name) {FieldId::compat_value, name, "", FieldType::tack_direction_enum, true, false, false},
#define FIELD_CMD_TACK_STATE_ENUM(name) {FieldId::compat_value, name, "", FieldType::tack_state_enum, true, false, false},
#define FIELD_PILOT_RW_NUMBER(name) {FieldId::compat_value, name, "", FieldType::number, true, true, true},
#define FIELD_PILOT_RW_NUMBER_DEG(name) {FieldId::compat_value, name, "deg", FieldType::number, true, true, true},
#define FIELD_PILOT_RW_NUMBER_DEG_S(name) {FieldId::compat_value, name, "deg/s", FieldType::number, true, true, true},
#define FIELD_RO_BOOLEAN(name) {FieldId::compat_value, name, "", FieldType::boolean, false, false, false},
#define FIELD_RO_INTEGER(name) {FieldId::compat_value, name, "", FieldType::integer, false, false, false},
#define FIELD_RO_NUMBER(name) {FieldId::compat_value, name, "", FieldType::number, false, false, false},
#define FIELD_RO_NUMBER_AH(name) {FieldId::compat_value, name, "Ah", FieldType::number, false, false, false},
#define FIELD_RO_NUMBER_C(name) {FieldId::compat_value, name, "C", FieldType::number, false, false, false},
#define FIELD_RO_NUMBER_DEG(name) {FieldId::compat_value, name, "deg", FieldType::number, false, false, false},
#define FIELD_RO_NUMBER_DEG_S(name) {FieldId::compat_value, name, "deg/s", FieldType::number, false, false, false},
#define FIELD_RO_NUMBER_HZ(name) {FieldId::compat_value, name, "Hz", FieldType::number, false, false, false},
#define FIELD_RO_NUMBER_KN(name) {FieldId::compat_value, name, "kn", FieldType::number, false, false, false},
#define FIELD_RO_NUMBER_NMI(name) {FieldId::compat_value, name, "nmi", FieldType::number, false, false, false},
#define FIELD_RO_NUMBER_S(name) {FieldId::compat_value, name, "s", FieldType::number, false, false, false},
#define FIELD_RO_NUMBER_V(name) {FieldId::compat_value, name, "V", FieldType::number, false, false, false},
#define FIELD_RO_NUMBER_W(name) {FieldId::compat_value, name, "W", FieldType::number, false, false, false},
#define FIELD_RO_OBJECT_VALUE(name) {FieldId::compat_value, name, "", FieldType::object_value, false, false, false},
#define FIELD_RO_QUATERNION_VALUE(name) {FieldId::compat_value, name, "", FieldType::quaternion_value, false, false, false},
#define FIELD_RO_VECTOR3_VALUE(name) {FieldId::compat_value, name, "", FieldType::vector3_value, false, false, false},
#define FIELD_RW_BOOLEAN(name) {FieldId::compat_value, name, "", FieldType::boolean, true, true, false},
#define FIELD_RW_MODE_ENUM(name) {FieldId::compat_value, name, "", FieldType::mode_enum, true, true, false},
#define FIELD_RW_NUMBER(name) {FieldId::compat_value, name, "", FieldType::number, true, true, false},
#define FIELD_RW_NUMBER_A(name) {FieldId::compat_value, name, "A", FieldType::number, true, true, false},
#define FIELD_RW_NUMBER_C(name) {FieldId::compat_value, name, "C", FieldType::number, true, true, false},
#define FIELD_RW_NUMBER_DEG(name) {FieldId::compat_value, name, "deg", FieldType::number, true, true, false},
#define FIELD_RW_NUMBER_DEG_NMI(name) {FieldId::compat_value, name, "deg/nmi", FieldType::number, true, true, false},
#define FIELD_RW_NUMBER_DEG_S(name) {FieldId::compat_value, name, "deg/s", FieldType::number, true, true, false},
#define FIELD_RW_NUMBER_HZ(name) {FieldId::compat_value, name, "Hz", FieldType::number, true, true, false},
#define FIELD_RW_NUMBER_M(name) {FieldId::compat_value, name, "m", FieldType::number, true, true, false},
#define FIELD_RW_NUMBER_S(name) {FieldId::compat_value, name, "s", FieldType::number, true, true, false},
#define FIELD_RW_OBJECT_VALUE(name) {FieldId::compat_value, name, "", FieldType::object_value, true, true, false},
#define FIELD_RW_QUATERNION_VALUE(name) {FieldId::compat_value, name, "", FieldType::quaternion_value, true, true, false},
#define FIELD_RW_SOURCE_ENUM(name) {FieldId::compat_value, name, "", FieldType::source_enum, true, true, false},

static constexpr FieldMeta field_definitions[] = {
    {FieldId::compat_value, "compat.value", "", FieldType::unknown_value, false, false, false},
    {FieldId::server_version, "server.version", "", FieldType::string_value, false, false, false},
    {FieldId::server_version, "ap.version", "", FieldType::string_value, false, false, false},
    {FieldId::server_uptime_s, "server.uptime", "s", FieldType::number, false, false, false},
    {FieldId::status_last_error, "status.last_error", "", FieldType::string_value, false, false, false},
    {FieldId::ap_enabled, "ap.enabled", "", FieldType::boolean, true, true, false},
    {FieldId::ap_mode, "ap.mode", "", FieldType::mode_enum, true, true, false},
    {FieldId::ap_pilot, "ap.pilot", "", FieldType::pilot_enum, true, true, false},
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
    {FieldId::pilot_basic_Pgain, "ap.pilot.basic.Pgain", "", FieldType::number, true, true, true},
    {FieldId::pilot_basic_Pgain, "ap.pilot.learning.Pgain", "", FieldType::number, true, true, true},

    FIELD_CMD_NUMBER("ap.heading_command_rate")
    FIELD_CMD_NUMBER("servo.position_command")
    FIELD_CMD_NUMBER("servo.command")

    FIELD_CMD_NUMBER_DEG("ap.heading_command")

    FIELD_CMD_TACK_DIRECTION_ENUM("ap.tack.direction")

    FIELD_CMD_TACK_STATE_ENUM("ap.tack.state")

    FIELD_PILOT_RW_NUMBER("ap.pilot.basic.D")
    FIELD_PILOT_RW_NUMBER("ap.pilot.basic.Dgain")
    FIELD_PILOT_RW_NUMBER("ap.pilot.basic.DD")
    FIELD_PILOT_RW_NUMBER("ap.pilot.basic.DDgain")
    FIELD_PILOT_RW_NUMBER("ap.pilot.basic.PR")
    FIELD_PILOT_RW_NUMBER("ap.pilot.basic.PRgain")
    FIELD_PILOT_RW_NUMBER("ap.pilot.basic.FF")
    FIELD_PILOT_RW_NUMBER("ap.pilot.basic.FFgain")
    FIELD_PILOT_RW_NUMBER("ap.pilot.wind.P")
    FIELD_PILOT_RW_NUMBER("ap.pilot.wind.Pgain")
    FIELD_PILOT_RW_NUMBER("ap.pilot.wind.D")
    FIELD_PILOT_RW_NUMBER("ap.pilot.wind.Dgain")
    FIELD_PILOT_RW_NUMBER("ap.pilot.wind.DD")
    FIELD_PILOT_RW_NUMBER("ap.pilot.wind.DDgain")
    FIELD_PILOT_RW_NUMBER("ap.pilot.wind.WG")
    FIELD_PILOT_RW_NUMBER("ap.pilot.wind.WGgain")
    FIELD_PILOT_RW_NUMBER("ap.pilot.absolute.P")
    FIELD_PILOT_RW_NUMBER("ap.pilot.absolute.Pgain")
    FIELD_PILOT_RW_NUMBER("ap.pilot.absolute.I")
    FIELD_PILOT_RW_NUMBER("ap.pilot.absolute.Igain")
    FIELD_PILOT_RW_NUMBER("ap.pilot.absolute.D")
    FIELD_PILOT_RW_NUMBER("ap.pilot.absolute.Dgain")
    FIELD_PILOT_RW_NUMBER("ap.pilot.absolute.FF")
    FIELD_PILOT_RW_NUMBER("ap.pilot.absolute.FFgain")
    FIELD_PILOT_RW_NUMBER("ap.pilot.rate.D")
    FIELD_PILOT_RW_NUMBER("ap.pilot.rate.Dgain")
    FIELD_PILOT_RW_NUMBER("ap.pilot.rate.DD")
    FIELD_PILOT_RW_NUMBER("ap.pilot.rate.DDgain")
    FIELD_PILOT_RW_NUMBER("ap.pilot.rate.FF")
    FIELD_PILOT_RW_NUMBER("ap.pilot.rate.FFgain")
    FIELD_PILOT_RW_NUMBER("ap.pilot.simple.P")
    FIELD_PILOT_RW_NUMBER("ap.pilot.simple.Pgain")
    FIELD_PILOT_RW_NUMBER("ap.pilot.simple.I")
    FIELD_PILOT_RW_NUMBER("ap.pilot.simple.Igain")
    FIELD_PILOT_RW_NUMBER("ap.pilot.simple.D")
    FIELD_PILOT_RW_NUMBER("ap.pilot.simple.Dgain")
    FIELD_PILOT_RW_NUMBER("ap.pilot.vmg.P")
    FIELD_PILOT_RW_NUMBER("ap.pilot.vmg.Pgain")
    FIELD_PILOT_RW_NUMBER("ap.pilot.vmg.D")
    FIELD_PILOT_RW_NUMBER("ap.pilot.vmg.Dgain")
    FIELD_PILOT_RW_NUMBER("ap.pilot.vmg.DD")
    FIELD_PILOT_RW_NUMBER("ap.pilot.vmg.DDgain")
    FIELD_PILOT_RW_NUMBER("ap.pilot.deadzone.deadzone")
    FIELD_PILOT_RW_NUMBER("ap.pilot.fuzzy.learningP")
    FIELD_PILOT_RW_NUMBER("ap.pilot.fuzzy.learningD")
    FIELD_PILOT_RW_NUMBER("ap.pilot.fuzzy.seastate")
    FIELD_PILOT_RW_NUMBER("ap.pilot.learning.D")
    FIELD_PILOT_RW_NUMBER("ap.pilot.learning.Dgain")
    FIELD_PILOT_RW_NUMBER("ap.pilot.learning.W")
    FIELD_PILOT_RW_NUMBER("ap.pilot.learning.Wgain")

    FIELD_PILOT_RW_NUMBER_DEG("ap.pilot.wind.gps_wind_offset")

    FIELD_PILOT_RW_NUMBER_DEG_S("ap.pilot.rate.maxturnrate")
    FIELD_PILOT_RW_NUMBER_DEG_S("ap.pilot.rate.turnraterate")

    FIELD_RO_BOOLEAN("imu.warning")

    FIELD_RO_INTEGER("ap.modes")
    FIELD_RO_INTEGER("imu.alignmentCounter")
    FIELD_RO_INTEGER("gps.alignmentCounter")
    FIELD_RO_INTEGER("servo.faults")
    FIELD_RO_INTEGER("ap.tack.count")

    FIELD_RO_NUMBER("rudder.speed")
    FIELD_RO_NUMBER("servo.duty")
    FIELD_RO_NUMBER("servo.current.noise")
    FIELD_RO_NUMBER("servo.speed")
    FIELD_RO_NUMBER("servo.position")
    FIELD_RO_NUMBER("servo.raw_command")

    FIELD_RO_NUMBER_AH("servo.amp_hours")

    FIELD_RO_NUMBER_C("servo.controller_temp")
    FIELD_RO_NUMBER_C("servo.motor_temp")

    FIELD_RO_NUMBER_DEG("ap.heading_error")
    FIELD_RO_NUMBER_DEG("ap.heading_error_int")
    FIELD_RO_NUMBER_DEG("ap.gps_compass_offset")
    FIELD_RO_NUMBER_DEG("ap.wind_compass_offset")
    FIELD_RO_NUMBER_DEG("ap.true_wind_compass_offset")
    FIELD_RO_NUMBER_DEG("imu.pitch")
    FIELD_RO_NUMBER_DEG("imu.roll")
    FIELD_RO_NUMBER_DEG("imu.heading")
    FIELD_RO_NUMBER_DEG("imu.heading_lowpass")
    FIELD_RO_NUMBER_DEG("gps.track")
    FIELD_RO_NUMBER_DEG("gps.leeway_ground")
    FIELD_RO_NUMBER_DEG("gps.compass_error")
    FIELD_RO_NUMBER_DEG("gps.declination")
    FIELD_RO_NUMBER_DEG("wind.direction")
    FIELD_RO_NUMBER_DEG("truewind.direction")
    FIELD_RO_NUMBER_DEG("truewind.filtered_direction")
    FIELD_RO_NUMBER_DEG("apb.track")
    FIELD_RO_NUMBER_DEG("water.leeway")
    FIELD_RO_NUMBER_DEG("water.current.direction")
    FIELD_RO_NUMBER_DEG("water.wind.direction")
    FIELD_RO_NUMBER_DEG("rudder.angle")

    FIELD_RO_NUMBER_DEG_S("imu.headingrate")
    FIELD_RO_NUMBER_DEG_S("imu.headingrate_lowpass")
    FIELD_RO_NUMBER_DEG_S("imu.headingraterate")
    FIELD_RO_NUMBER_DEG_S("imu.headingraterate_lowpass")
    FIELD_RO_NUMBER_DEG_S("imu.pitchrate")
    FIELD_RO_NUMBER_DEG_S("imu.rollrate")

    FIELD_RO_NUMBER_HZ("imu.frequency")

    FIELD_RO_NUMBER_KN("gps.speed")
    FIELD_RO_NUMBER_KN("wind.speed")
    FIELD_RO_NUMBER_KN("wind.filtered_speed")
    FIELD_RO_NUMBER_KN("truewind.speed")
    FIELD_RO_NUMBER_KN("truewind.filtered_speed")
    FIELD_RO_NUMBER_KN("water.speed")
    FIELD_RO_NUMBER_KN("water.current.speed")
    FIELD_RO_NUMBER_KN("water.wind.speed")

    FIELD_RO_NUMBER_NMI("apb.xte")

    FIELD_RO_NUMBER_S("ap.runtime")
    FIELD_RO_NUMBER_S("imu.uptime")

    FIELD_RO_NUMBER_V("servo.voltage")

    FIELD_RO_NUMBER_W("servo.watts")

    FIELD_RO_OBJECT_VALUE("ap.timings")
    FIELD_RO_OBJECT_VALUE("gps.fix")

    FIELD_RO_QUATERNION_VALUE("imu.fusionQPose")

    FIELD_RO_VECTOR3_VALUE("imu.accel")
    FIELD_RO_VECTOR3_VALUE("imu.gyro")
    FIELD_RO_VECTOR3_VALUE("imu.compass")
    FIELD_RO_VECTOR3_VALUE("imu.accel.residuals")
    FIELD_RO_VECTOR3_VALUE("imu.gyrobias")

    FIELD_RW_BOOLEAN("ap.gps_and_nav_modes")
    FIELD_RW_BOOLEAN("servo.engaged")
    FIELD_RW_BOOLEAN("servo.use_brake")
    FIELD_RW_BOOLEAN("servo.compensate_current")
    FIELD_RW_BOOLEAN("servo.compensate_voltage")
    FIELD_RW_BOOLEAN("servo.use_eeprom")
    FIELD_RW_BOOLEAN("ap.tack.use_heel")
    FIELD_RW_BOOLEAN("ap.tack.use_wind_direction")

    FIELD_RW_MODE_ENUM("ap.preferred_mode")

    FIELD_RW_NUMBER("ap.wind_offset_filter")
    FIELD_RW_NUMBER("imu.heading_lowpass_constant")
    FIELD_RW_NUMBER("imu.headingrate_lowpass_constant")
    FIELD_RW_NUMBER("imu.headingraterate_lowpass_constant")
    FIELD_RW_NUMBER("wind.filter_constant")
    FIELD_RW_NUMBER("wind.filter_factor")
    FIELD_RW_NUMBER("truewind.filter_constant")
    FIELD_RW_NUMBER("truewind.filter_factor")
    FIELD_RW_NUMBER("rudder.scale")
    FIELD_RW_NUMBER("rudder.nonlinearity")
    FIELD_RW_NUMBER("servo.speed_gain")
    FIELD_RW_NUMBER("servo.current.factor")
    FIELD_RW_NUMBER("servo.current.offset")
    FIELD_RW_NUMBER("servo.voltage.factor")
    FIELD_RW_NUMBER("servo.voltage.offset")
    FIELD_RW_NUMBER("servo.max_slew_speed")
    FIELD_RW_NUMBER("servo.max_slew_slow")
    FIELD_RW_NUMBER("servo.gain")
    FIELD_RW_NUMBER("servo.clutch_pwm")
    FIELD_RW_NUMBER("servo.speed.min")
    FIELD_RW_NUMBER("servo.speed.max")
    FIELD_RW_NUMBER("servo.position.p")
    FIELD_RW_NUMBER("servo.position.i")
    FIELD_RW_NUMBER("servo.position.d")
    FIELD_RW_NUMBER("servo.controller")
    FIELD_RW_NUMBER("ap.tack.threshold")

    FIELD_RW_NUMBER_A("servo.max_current")

    FIELD_RW_NUMBER_C("servo.max_controller_temp")
    FIELD_RW_NUMBER_C("servo.max_motor_temp")

    FIELD_RW_NUMBER_DEG("wind.offset")
    FIELD_RW_NUMBER_DEG("truewind.offset")
    FIELD_RW_NUMBER_DEG("rudder.offset")
    FIELD_RW_NUMBER_DEG("rudder.range")
    FIELD_RW_NUMBER_DEG("ap.tack.angle")

    FIELD_RW_NUMBER_DEG_NMI("apb.xte.gain")

    FIELD_RW_NUMBER_DEG_S("ap.tack.rate")

    FIELD_RW_NUMBER_HZ("imu.rate")
    FIELD_RW_NUMBER_HZ("gps.rate")
    FIELD_RW_NUMBER_HZ("wind.rate")
    FIELD_RW_NUMBER_HZ("truewind.rate")
    FIELD_RW_NUMBER_HZ("water.rate")
    FIELD_RW_NUMBER_HZ("rudder.rate")

    FIELD_RW_NUMBER_M("wind.sensors_height")
    FIELD_RW_NUMBER_M("truewind.sensors_height")

    FIELD_RW_NUMBER_S("servo.period")
    FIELD_RW_NUMBER_S("ap.tack.timeout")
    FIELD_RW_NUMBER_S("ap.tack.delay")

    FIELD_RW_OBJECT_VALUE("servo.calibration")

    FIELD_RW_QUATERNION_VALUE("imu.alignmentQ")

    FIELD_RW_SOURCE_ENUM("gps.source")
    FIELD_RW_SOURCE_ENUM("truewind.source")
    FIELD_RW_SOURCE_ENUM("apb.source")
    FIELD_RW_SOURCE_ENUM("water.source")
    FIELD_RW_SOURCE_ENUM("water.leeway.source")
    FIELD_RW_SOURCE_ENUM("rudder.source")
};

#undef FIELD_CMD_NUMBER
#undef FIELD_CMD_NUMBER_DEG
#undef FIELD_CMD_TACK_DIRECTION_ENUM
#undef FIELD_CMD_TACK_STATE_ENUM
#undef FIELD_PILOT_RW_NUMBER
#undef FIELD_PILOT_RW_NUMBER_DEG
#undef FIELD_PILOT_RW_NUMBER_DEG_S
#undef FIELD_RO_BOOLEAN
#undef FIELD_RO_INTEGER
#undef FIELD_RO_NUMBER
#undef FIELD_RO_NUMBER_AH
#undef FIELD_RO_NUMBER_C
#undef FIELD_RO_NUMBER_DEG
#undef FIELD_RO_NUMBER_DEG_S
#undef FIELD_RO_NUMBER_HZ
#undef FIELD_RO_NUMBER_KN
#undef FIELD_RO_NUMBER_NMI
#undef FIELD_RO_NUMBER_S
#undef FIELD_RO_NUMBER_V
#undef FIELD_RO_NUMBER_W
#undef FIELD_RO_OBJECT_VALUE
#undef FIELD_RO_QUATERNION_VALUE
#undef FIELD_RO_VECTOR3_VALUE
#undef FIELD_RW_BOOLEAN
#undef FIELD_RW_MODE_ENUM
#undef FIELD_RW_NUMBER
#undef FIELD_RW_NUMBER_A
#undef FIELD_RW_NUMBER_C
#undef FIELD_RW_NUMBER_DEG
#undef FIELD_RW_NUMBER_DEG_NMI
#undef FIELD_RW_NUMBER_DEG_S
#undef FIELD_RW_NUMBER_HZ
#undef FIELD_RW_NUMBER_M
#undef FIELD_RW_NUMBER_S
#undef FIELD_RW_OBJECT_VALUE
#undef FIELD_RW_QUATERNION_VALUE
#undef FIELD_RW_SOURCE_ENUM

static constexpr size_t field_definition_count = sizeof(field_definitions) / sizeof(field_definitions[0]);

} // namespace ship_data_model
