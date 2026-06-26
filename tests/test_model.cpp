#include <cassert>
#include <type_traits>
#include <ship_data_model.hpp>

using namespace ship_data_model;

int main() {
    DataModel<> mf;
    DataModel<double> md;

    static_assert(std::is_same<decltype(mf.ap.heading_deg.value), float>::value, "default Real must be float");
    static_assert(std::is_same<decltype(md.ap.heading_deg.value), double>::value, "Real=double must work");

    assert(source_priority(SensorSource::gpsd) == 1);
    assert(source_priority(SensorSource::servo) == 1);
    assert(source_priority(SensorSource::serial) == 2);
    assert(source_priority(SensorSource::tcp) == 3);
    assert(source_priority(SensorSource::signalk) == 4);
    assert(source_priority(SensorSource::water_wind) == 5);
    assert(source_priority(SensorSource::gps_wind) == 6);
    assert(source_priority(SensorSource::none) == 7);

    assert(servo_sync_flag == 1u);
    assert(servo_rebooted_flag == 32768u);
    assert(servo_port_overcurrent_fault == 65536u);
    assert(servo_saturated == 524288u);

    mf.ap.enabled.value = true;
    mf.ap.mode.value = AutopilotMode::wind;
    mf.navigation.gps.timestamp_s.set(1710000000.0f, 1000000);
    mf.navigation.gps.speed_kn.set(5.5f, 1000000);
    mf.navigation.apb.mode_hint.value = AutopilotMode::gps;
    mf.navigation.apb.sender_id[0] = 'G';
    mf.navigation.apb.sender_id[1] = 'P';
    mf.navigation.apb.sender_id[2] = '\0';
    assert(mf.navigation.gps.timestamp_s.valid);
    assert(mf.navigation.gps.speed_kn.valid);
    assert(mf.navigation.apb.mode_hint.value == AutopilotMode::gps);
    assert(mf.navigation.apb.sender_id[0] == 'G');
    assert(!mf.navigation.gps.speed_kn.stale(1100000, 200000));
    assert(mf.navigation.gps.speed_kn.stale(1300000, 200000));

    mf.servo.flags.value = servo_overcurrent_fault;
    assert(servo_faulted(mf.servo.flags.value));

    mf.servo.command_norm.set_external(0.25f, 1000);
    assert(mf.servo.command_norm.value == 0.25f);
    assert(!mf.servo.command_norm.use_period);
    mf.servo.command_norm.set_internal_command(0.0f, 2000);
    assert(mf.servo.command_norm.use_period);

    mf.wind.apparent.direction_deg.set(-35.0f, 42);
    mf.imu.heading_lowpass_deg.set(123.0f, 42);
    mf.rudder.angle_deg.set(2.5f, 42);
    mf.pilots.basic.P.gain.value = 0.003f;
    mf.pilots.basic.P.contribution.set(0.01f, 42);

    (void)md;
    return 0;
}
