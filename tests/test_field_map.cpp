#include <cassert>
#include <cstring>
#include <pypilot_data_model.hpp>

using namespace pypilot_data_model;

int main() {
    DataModel<> model;
    const uint64_t now_us = 123456;

    FieldId heading_id = field_id_from_name("ap.heading");
    assert(heading_id == FieldId::ap_heading_deg);
    assert(std::strcmp(pypilot_name(heading_id), "ap.heading") == 0);

    const FieldMeta* meta = field_meta(FieldId::servo_current_a);
    assert(meta);
    assert(std::strcmp(meta->pypilot_name, "servo.current") == 0);
    assert(std::strcmp(meta->unit, "A") == 0);
    assert(meta->type == FieldType::number);
    assert(!meta->writable);

    assert(apply_number(model, heading_id, 87.5f, now_us));
    assert(model.ap.heading_deg.valid);
    assert(model.ap.heading_deg.value == 87.5f);
    assert(model.ap.heading_deg.last_update_us == now_us);

    assert(apply_number(model, FieldId::wind_filtered_direction_deg, -34.25f, now_us + 1));
    assert(model.wind.apparent.filtered_direction_deg.valid);
    assert(model.wind.apparent.filtered_direction_deg.value == -34.25f);

    assert(apply_number(model, FieldId::servo_current_a, 1.75f, now_us + 2));
    assert(model.servo.current_a.value == 1.75f);

    assert(apply_bool(model, FieldId::ap_enabled, true, now_us + 3));
    bool enabled = false;
    assert(read_bool(model, FieldId::ap_enabled, enabled));
    assert(enabled);

    assert(apply_mode(model, FieldId::ap_mode, AutopilotMode::wind, now_us + 4));
    assert(model.ap.mode.value == AutopilotMode::wind);

    SensorSource source = SensorSource::none;
    assert(sensor_source_from_name("signalk", source));
    assert(source == SensorSource::signalk);
    assert(apply_source(model, FieldId::wind_source, source, now_us + 5));
    assert(model.wind.apparent.source.value == SensorSource::signalk);

    PilotName pilot = PilotName::basic;
    assert(pilot_from_name("absolute", pilot));
    assert(apply_pilot(model, FieldId::ap_pilot, pilot, now_us + 6));
    assert(model.ap.pilot.value == PilotName::absolute);

    RudderCalibrationState state = RudderCalibrationState::idle;
    assert(rudder_calibration_state_from_name("port range", state));
    assert(apply_rudder_calibration_state(model, FieldId::rudder_calibration_state, state, now_us + 7));
    assert(model.rudder.calibration_state.value == RudderCalibrationState::port_range);

    assert(apply_number(model, FieldId::pilot_basic_P, 0.003f, now_us + 8));
    assert(model.pilots.basic.P.gain.value == 0.003f);
    assert(apply_number(model, FieldId::pilot_basic_Pgain, 0.01f, now_us + 9));
    assert(model.pilots.basic.P.contribution.valid);

    assert(apply_string(model, FieldId::server_version, "0.70-cpp", now_us + 10));
    const char* text = 0;
    assert(read_string(model, FieldId::server_version, text));
    assert(std::strcmp(text, "0.70-cpp") == 0);

    assert(field_id_from_name("server.uptime") == FieldId::server_uptime_s);
    assert(apply_number(model, FieldId::server_uptime_s, 12.5f, now_us + 11));
    float out = 0;
    assert(read_number(model, FieldId::server_uptime_s, out));
    assert(out == 12.5f);

    assert(field_id_from_name("ap.tack.progress") == FieldId::ap_tack_progress_0_1);
    assert(apply_number(model, FieldId::ap_tack_progress_0_1, 0.5f, now_us + 12));
    assert(model.tack.progress_0_1.valid);

    assert(field_id_from_name("servo.telemetry.current") == FieldId::servo_telemetry_current_a);
    assert(apply_number(model, FieldId::servo_telemetry_current_a, 2.0f, now_us + 13));
    assert(read_number(model, FieldId::servo_telemetry_current_a, out));
    assert(out == 2.0f);

    assert(field_id_from_name("status.last_error") == FieldId::status_last_error);
    assert(apply_string(model, FieldId::status_last_error, "bad voltage", now_us + 14));
    assert(read_string(model, FieldId::status_last_error, text));
    assert(std::strcmp(text, "bad voltage") == 0);

    size_t count = 0;
    const RuntimeValueMetadata* runtime_values = core_runtime_values(count);
    bool found_runtime_field = false;
    for (size_t i = 0; i < count; ++i) {
        if (std::strcmp(runtime_values[i].name, "servo.current") == 0 &&
            runtime_values[i].field_id == FieldId::servo_current_a) {
            found_runtime_field = true;
        }
    }
    assert(found_runtime_field);

    assert(read_number(model, FieldId::pilot_basic_P, out));
    assert(out == 0.003f);
    assert(field_id_from_name("does.not.exist") == FieldId::unknown);

    return 0;
}
