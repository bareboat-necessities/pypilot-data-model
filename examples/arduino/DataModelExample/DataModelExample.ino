#include <Arduino.h>
#include <pypilot_data_model/data_model.hpp>

pypilot_data_model::DataModel<> model;

void setup() {
  Serial.begin(115200);
  while (!Serial) {}

  model.ap.enabled.value = true;
  model.ap.mode.value = pypilot_data_model::AutopilotMode::wind;
  model.wind.apparent.direction_deg.set(-35.0f, micros());
  model.servo.current_a.set(1.2f, micros());

  Serial.print("wind.direction_deg=");
  Serial.println(model.wind.apparent.direction_deg.value, 2);
  Serial.print("servo.current_a=");
  Serial.println(model.servo.current_a.value, 2);
}

void loop() {}
