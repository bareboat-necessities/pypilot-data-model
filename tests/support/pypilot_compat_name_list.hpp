#pragma once

#include <stddef.h>

namespace pypilot_data_model_test {

static constexpr const char* pypilot_compat_names[] = {
    "ap.version", "ap.preferred_mode", "ap.mode", "ap.modes", "ap.gps_and_nav_modes",
    "ap.heading_command", "ap.enabled", "ap.heading", "ap.heading_error", "ap.heading_error_int",
    "ap.heading_command_rate", "ap.pilot", "ap.gps_compass_offset", "ap.wind_compass_offset",
    "ap.true_wind_compass_offset", "ap.wind_offset_filter", "ap.runtime", "ap.timings",

    "imu.rate", "imu.frequency", "imu.alignmentQ", "imu.heading_offset", "imu.alignmentCounter",
    "imu.uptime", "imu.warning", "imu.heading_lowpass_constant", "imu.headingrate_lowpass_constant",
    "imu.headingraterate_lowpass_constant", "imu.accel", "imu.gyro", "imu.compass",
    "imu.accel.residuals", "imu.pitch", "imu.roll", "imu.fusionQPose", "imu.heading",
    "imu.heading_lowpass", "imu.headingrate", "imu.headingrate_lowpass", "imu.headingraterate",
    "imu.headingraterate_lowpass", "imu.pitchrate", "imu.rollrate", "imu.gyrobias",

    "gps.source", "gps.rate", "gps.track", "gps.speed", "gps.fix", "gps.leeway_ground",
    "gps.compass_error", "gps.declination", "gps.alignmentCounter",
    "wind.source", "wind.rate", "wind.direction", "wind.speed", "wind.offset",
    "wind.sensors_height", "wind.filtered_speed", "wind.filtered_direction", "wind.filter_constant",
    "wind.filter_factor", "truewind.source", "truewind.rate", "truewind.direction", "truewind.speed",
    "truewind.offset", "truewind.sensors_height", "truewind.filtered_speed", "truewind.filtered_direction",
    "truewind.filter_constant", "truewind.filter_factor", "apb.source", "apb.track", "apb.xte",
    "apb.xte.gain", "water.source", "water.rate", "water.speed", "water.leeway",
    "water.leeway.source", "water.current.speed", "water.current.direction", "water.wind.speed",
    "water.wind.direction", "rudder.source", "rudder.rate", "rudder.angle", "rudder.speed",
    "rudder.offset", "rudder.scale", "rudder.nonlinearity", "rudder.calibration_state", "rudder.range",

    "servo.calibration", "servo.position_command", "servo.command", "servo.speed_gain", "servo.duty",
    "servo.faults", "servo.voltage", "servo.current", "servo.current.noise", "servo.controller_temp",
    "servo.motor_temp", "servo.engaged", "servo.max_current", "servo.current.factor",
    "servo.current.offset", "servo.voltage.factor", "servo.voltage.offset", "servo.max_controller_temp",
    "servo.max_motor_temp", "servo.max_slew_speed", "servo.max_slew_slow", "servo.gain",
    "servo.clutch_pwm", "servo.use_brake", "servo.period", "servo.compensate_current",
    "servo.compensate_voltage", "servo.amp_hours", "servo.watts", "servo.speed", "servo.speed.min",
    "servo.speed.max", "servo.position", "servo.position.p", "servo.position.i", "servo.position.d",
    "servo.raw_command", "servo.use_eeprom", "servo.state", "servo.controller", "servo.flags",

    "ap.tack.state", "ap.tack.timeout", "ap.tack.delay", "ap.tack.angle", "ap.tack.rate",
    "ap.tack.threshold", "ap.tack.count", "ap.tack.direction", "ap.tack.use_heel",
    "ap.tack.use_wind_direction",

    "ap.pilot.basic.P", "ap.pilot.basic.Pgain", "ap.pilot.basic.D", "ap.pilot.basic.Dgain",
    "ap.pilot.basic.DD", "ap.pilot.basic.DDgain", "ap.pilot.basic.PR", "ap.pilot.basic.PRgain",
    "ap.pilot.basic.FF", "ap.pilot.basic.FFgain", "ap.pilot.wind.gps_wind_offset",
    "ap.pilot.wind.P", "ap.pilot.wind.Pgain", "ap.pilot.wind.D", "ap.pilot.wind.Dgain",
    "ap.pilot.wind.DD", "ap.pilot.wind.DDgain", "ap.pilot.wind.WG", "ap.pilot.wind.WGgain",
    "ap.pilot.absolute.P", "ap.pilot.absolute.Pgain", "ap.pilot.absolute.I", "ap.pilot.absolute.Igain",
    "ap.pilot.absolute.D", "ap.pilot.absolute.Dgain", "ap.pilot.absolute.FF", "ap.pilot.absolute.FFgain",
    "ap.pilot.rate.D", "ap.pilot.rate.Dgain", "ap.pilot.rate.DD", "ap.pilot.rate.DDgain",
    "ap.pilot.rate.FF", "ap.pilot.rate.FFgain", "ap.pilot.rate.maxturnrate",
    "ap.pilot.rate.turnraterate", "ap.pilot.simple.P", "ap.pilot.simple.Pgain",
    "ap.pilot.simple.I", "ap.pilot.simple.Igain", "ap.pilot.simple.D", "ap.pilot.simple.Dgain",
    "ap.pilot.vmg.P", "ap.pilot.vmg.Pgain", "ap.pilot.vmg.D", "ap.pilot.vmg.Dgain",
    "ap.pilot.vmg.DD", "ap.pilot.vmg.DDgain", "ap.pilot.deadzone.deadzone",
    "ap.pilot.fuzzy.learningP", "ap.pilot.fuzzy.learningD", "ap.pilot.fuzzy.seastate",
    "ap.pilot.learning.P", "ap.pilot.learning.Pgain", "ap.pilot.learning.D", "ap.pilot.learning.Dgain",
    "ap.pilot.learning.W", "ap.pilot.learning.Wgain"
};

static constexpr size_t pypilot_compat_names_size =
    sizeof(pypilot_compat_names) / sizeof(pypilot_compat_names[0]);

} // namespace pypilot_data_model_test
