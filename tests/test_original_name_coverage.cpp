#include <cassert>
#include <cstdio>
#include <pypilot_data_model.hpp>
#include <pypilot_data_model/pypilot_original_names.hpp>

using namespace pypilot_data_model;

int main() {
    size_t missing = 0;
    for (size_t i = 0; i < pypilot_original_names_size; ++i) {
        const char* name = pypilot_original_names[i];
        const FieldId id = field_id_from_name(name);
        if (id == FieldId::unknown) {
            std::fprintf(stderr, "missing original pypilot name: %s\n", name);
            ++missing;
        }
    }
    assert(missing == 0);

    assert(field_id_from_name("ap.version") == FieldId::server_version);
    assert(field_id_from_name("imu.heading_offset") == FieldId::imu_calibration_heading_offset_deg);
    assert(field_id_from_name("servo.state") == FieldId::servo_telemetry_state);
    assert(field_id_from_name("ap.pilot.learning.P") == FieldId::pilot_basic_P);
    assert(field_id_from_name("does.not.exist") == FieldId::unknown);
    return 0;
}
