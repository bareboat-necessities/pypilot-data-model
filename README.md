# pypilot-data-model

Header-only C++ data structures matching the current pypilot runtime model from the provided pypilot source zip.

This project is deliberately **not** a future marine-INS model and deliberately **not** a hashmap of pypilot values. It is a typed C++ model for the current pypilot data groups:

- `ap.*`
- `imu.*`
- `gps.*`
- `apb.*`
- `wind.*`
- `truewind.*`
- `water.*`
- `rudder.*`
- `servo.*`
- `ap.pilot.*`
- profile placeholders

Design constraints:

- header-only
- C++11
- Arduino and Linux compatible
- `template<typename Real = float>` for decimal values
- unit abbreviations in field names
- monotonic microsecond timestamps for live values
- type-safe structs and enums, not hash maps
- no sockets, no serial, no JSON parser, no pilot math

## Build on Linux

```bash
cmake -S . -B build
cmake --build build --parallel
ctest --test-dir build --output-on-failure
```

## Arduino

Include:

```cpp
#include <pypilot_data_model/data_model.hpp>
```

## Field mapping

The library also includes a typed pypilot name map in the same package. It maps protocol names such as `ap.heading`, `wind.filtered_direction`, and `servo.current` to `FieldId` values and provides switch-based typed accessors into `DataModel<Real>`. This keeps pypilot strings at the boundary while preserving type-safe structs internally.

```cpp
#include <pypilot_data_model/data_model.hpp>

auto id = pypilot_data_model::field_id_from_name("ap.heading");
pypilot_data_model::apply_number(model, id, 123.4f, now_us);
```

## License

GPL-3.0-or-later.
