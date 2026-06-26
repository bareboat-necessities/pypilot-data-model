#include <cassert>
#include <cstring>
#include <pypilot_data_model.hpp>

using namespace pypilot_data_model;

int main() {
    DataModel<> model;

    std::strcpy(model.server.version, "0.70-cpp");
    std::strcpy(model.server.profile_name, "default");
    model.server.client_count.set(2u, 100);
    model.status.health.value = SystemHealth::ok;
    model.status.faults.value = system_fault_servo;
    assert(system_faulted(model.status.faults.value));

    model.imu_state.enabled.value = true;
    model.imu_state.rate_hz.set(100.0f, 200);
    model.imu_calibration.state.value = ImuCalibrationState::valid;
    model.imu_calibration.accel.valid.value = true;
    model.imu_calibration.accel.bias.value.x = 0.1f;
    model.imu_calibration.compass.valid.value = true;
    model.imu_calibration.compass_field_strength.set(47.0f, 300);

    model.servo_telemetry.controller_state.value = ServoControllerState::engaged;
    model.servo_telemetry.flags.value = servo_engaged_flag;
    model.servo_telemetry.voltage_v.set(12.4f, 400);
    model.servo_telemetry.current_a.set(1.5f, 400);
    model.servo_telemetry.rudder_feedback_deg.set(-2.0f, 400);
    model.servo_calibration.valid.value = true;
    model.servo_calibration.rudder_min_deg.value = -35.0f;
    model.servo_calibration.rudder_max_deg.value = 35.0f;

    model.tack.enabled.value = true;
    model.tack.state.value = TackState::tacking;
    model.tack.direction.value = TackDirection::starboard;
    model.tack.progress_0_1.set(0.5f, 500);

    model.pilot_command.source.value = PilotCommandSource::runtime;
    model.pilot_command.heading_command_deg.set_external(123.0f, 600);
    model.pilot_output.active_pilot_name[0] = 'b';
    model.pilot_output.active_pilot_name[1] = 'a';
    model.pilot_output.active_pilot_name[2] = 's';
    model.pilot_output.active_pilot_name[3] = 'i';
    model.pilot_output.active_pilot_name[4] = 'c';
    model.pilot_output.command_norm.set(0.25f, 700);

    assert(field_id_from_name("ap.enabled") == FieldId::ap_enabled);
    assert(field_id_from_name("servo.flags") == FieldId::servo_flags);
    assert(field_id_from_name("server.version") == FieldId::server_version);
    assert(field_meta(FieldId::servo_flags) != 0);

    const FieldMeta* servo_current = field_meta(FieldId::servo_current_a);
    assert(servo_current != 0);
    assert(std::strcmp(servo_current->pypilot_name, "servo.current") == 0);
    assert(servo_current->type == FieldType::number);
    assert(!servo_current->writable);

    const uint32_t published_count = 42u;
    model.runtime_publication.published_value_count.set(published_count, 800);
    assert(model.runtime_publication.published_value_count.value == published_count);

    return 0;
}
