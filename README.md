# pypilot-data-model

Header-only C++11 data structures and field metadata for the current pypilot runtime value model.

The repository name and CMake target remain `pypilot_data_model`, but the public C++ namespace and public include are `ship_data_model`:

```cpp
#include <ship_data_model.hpp>

ship_data_model::DataModel<> model;
```

This project is deliberately **not** a future marine-INS model and deliberately **not** a hashmap of pypilot values. It keeps pypilot string names at the boundary and stores known values in typed C++ structs.

## Covered value groups

The model contains typed groups for:

- `server.*`
- `status.*` and fault/warning state
- `ap.*`
- `ap.tack.*`
- `ap.pilot.*`
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
- profile placeholders
- value-publication counters

The top-level model type is:

```cpp
ship_data_model::DataModel<Real>
```

where `Real` defaults to `float`.

## Main public types

```text
DataModel
AutopilotServerData
AutopilotStatusData
AutopilotData
NavigationData
WindData
WaterData
ShipImuData
ImuStateData
ImuCalibrationData
RudderData
ServoData
ServoTelemetryData
ServoCalibrationData
PilotsData
PilotCommandData
PilotOutputData
TackData
AutopilotProfileData
ValuePublicationState
FieldMeta
```

## Design constraints

- header-only
- C++11
- Arduino and Linux compatible
- `template<typename Real = float>` for decimal values
- monotonic microsecond timestamps for live values
- type-safe structs and enums, not hash maps
- no sockets, no serial transport, no JSON parser, no pilot math

## Build on Linux

```bash
cmake -S . -B build
cmake --build build --parallel
ctest --test-dir build --output-on-failure
```

## Arduino example

```bash
arduino-cli compile --fqbn arduino:avr:mega --libraries . examples/arduino/DataModelExample
```

The Arduino library metadata advertises the same public include:

```cpp
#include <ship_data_model.hpp>
```

## Field metadata and mapping

`src/ship_data_model/field_def.hpp` contains an explicit static `FieldMeta` table. Names with dedicated storage use concrete `FieldId` values. Known pypilot runtime names that are not yet backed by typed storage use `FieldId::compat_value`, but still keep their own metadata row: type, unit, writable flag, persistent flag, and pilot-specific flag.

Use `field_id_from_name()` when code needs the mapped storage ID:

```cpp
auto id = ship_data_model::field_id_from_name("ap.heading");
ship_data_model::apply_number(model, id, 123.4f, now_us);
```

Use `field_meta_from_name()` when code needs metadata for a specific pypilot runtime name:

```cpp
const ship_data_model::FieldMeta* meta =
    ship_data_model::field_meta_from_name("imu.accel");
```

`field_meta(FieldId)` returns the canonical metadata row for a concrete field ID.

## Source layout

```text
src/ship_data_model/core_data_types.hpp
src/ship_data_model/autopilot_data.hpp
src/ship_data_model/ship_imu_data.hpp
src/ship_data_model/nav_data.hpp
src/ship_data_model/wind_sea_data.hpp
src/ship_data_model/steering_data.hpp
src/ship_data_model/field_def.hpp
src/ship_data_model/data_model.hpp
src/ship_data_model/data_model_mapping.hpp
src/ship_data_model.hpp
```

Implementation headers live under `src/ship_data_model/`. Applications, examples, and tests should include only:

```cpp
#include <ship_data_model.hpp>
```

## License

Apache-2.0.
