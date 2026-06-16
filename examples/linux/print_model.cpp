#include <iostream>
#include <pypilot_data_model.hpp>

int main() {
    pypilot_data_model::DataModel<> model;
    model.ap.enabled.value = true;
    model.ap.mode.value = pypilot_data_model::AutopilotMode::wind;
    model.ap.heading_command_deg.set(42.0f, 1000000);
    model.wind.apparent.filtered_direction_deg.set(-38.5f, 1000000);
    model.servo.current_a.set(1.25f, 1000000);

    std::cout << "ap.enabled=" << model.ap.enabled.value << "\n";
    std::cout << "ap.heading_command_deg=" << model.ap.heading_command_deg.value << "\n";
    std::cout << "wind.filtered_direction_deg=" << model.wind.apparent.filtered_direction_deg.value << "\n";
    std::cout << "servo.current_a=" << model.servo.current_a.value << "\n";
    return 0;
}
