# pypilot-data-model

Header-only C++ data structures matching the current pypilot runtime model from the provided pypilot source zip.

This project is deliberately **not** a future marine-INS model and deliberately **not** a hashmap of pypilot values. It is a typed C++ model for the current pypilot data groups:

- `server.*`
- `status.*` and fault/warning state
- `ap.*`
- `ap.tack.*`
- `imu.*`
- IMU state and calibration
- `gps.*`
- `apb.*`
- `wind.*`
- `truewind.*`
- `water.*`
- `rudder.*`
- `servo.*`
- extended servo telemetry and calibration
- pilot command/output state
- `ap.pilot.*`
- profile placeholders
- runtime-publication metadata and counters

Design constraints:

- header-only
- C++11
- Arduino and Linux compatible
- `template<typename Real = float>` for decimal values
- unit abbreviations in field names
- monotonic microsecond timestamps for live values
- type-safe structs and enums, not hash maps
- no sockets, no serial, no JSON parser, no pilot math

## Expanded value coverage

The model now includes explicit typed groups for:

```text
ServerData
StatusData
TackData
ServoTelemetryData
ServoCalibrationData
ImuStateData
ImuCalibrationData
PilotCommandData
PilotOutputData
RuntimePublicationState
RuntimeValueMetadata table
```

The runtime metadata table is a static typed table, not a dynamic binding registry. It gives runtime-facing code enough information to publish known pypilot names such as `ap.enabled`, `imu.heading_lowpass`, `gps.speed`, `wind.speed`, `servo.flags`, and `server.uptime` while keeping actual storage in typed C++ fields.

## Build on Linux

```bash
cmake -S . -B build
cmake --build build --parallel
ctest --test-dir build --output-on-failure
```

## Public include

Use the same public include on Linux and Arduino:

```cpp
#include <pypilot_data_model.hpp>
```

The nested headers under `pypilot_data_model/` remain implementation headers, but examples and tests use the unified public header.

## Field mapping

The library also includes a typed pypilot name map in the same package. It maps protocol names such as `ap.heading`, `wind.filtered_direction`, and `servo.current` to `FieldId` values and provides switch-based typed accessors into `DataModel<Real>`. This keeps pypilot strings at the boundary while preserving type-safe structs internally.

```cpp
#include <pypilot_data_model.hpp>

auto id = pypilot_data_model::field_id_from_name("ap.heading");
pypilot_data_model::apply_number(model, id, 123.4f, now_us);
```

## License

GPL-3.0-or-later.
