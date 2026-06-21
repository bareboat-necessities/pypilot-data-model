# Original pypilot value audit

This is the first static audit of value names observed in the uploaded `pypilot-master.zip` source tree. It is used to drive `FieldId`, `field_table`, `field_access`, and runtime publication coverage.

## Core server/autopilot values from `autopilot.py`

```text
version
timestamp
ap.preferred_mode
ap.mode
ap.modes
ap.gps_and_nav_modes
ap.heading_command
ap.enabled
ap.heading
ap.heading_error
ap.heading_error_int
ap.heading_command_rate
ap.pilot
ap.gps_compass_offset
ap.wind_compass_offset
ap.true_wind_compass_offset
ap.wind_offset_filter
ap.runtime
ap.timings
```

## Boat IMU values from `boatimu.py` and `calibration_fit.py`

```text
imu.gyrobias
imu.error
imu.rate
imu.frequency
imu.alignmentQ
imu.heading_offset
imu.alignmentCounter
imu.uptime
imu.warning
imu.heading_lowpass_constant
imu.headingrate_lowpass_constant
imu.headingraterate_lowpass_constant
imu.accel
imu.gyro
imu.compass
imu.fusionQPose
imu.accel.calibration
imu.accel.calibration.locked
imu.compass.calibration
imu.compass.calibration.locked
imu.compass.calibration.field_strength
imu.compass.calibration.inclination
```

## Sensor values from `sensors.py` and `nmea.py`

```text
wind.source
wind.rate
wind.direction
wind.speed
wind.offset
wind.sensors_height
wind.filtered_speed
wind.filtered_direction
wind.filter_constant
wind.filter_factor
truewind.source
truewind.rate
truewind.direction
truewind.speed
truewind.offset
truewind.sensors_height
truewind.filtered_speed
truewind.filtered_direction
truewind.filter_constant
truewind.filter_factor
gps.source
gps.rate
gps.track
gps.speed
gps.fix
gps.filtered.output
gps.filtered.fix
gps.leeway_ground
gps.compass_error
gps.declination
gps.alignmentCounter
apb.source
apb.track
apb.xte
apb.xte.gain
water.source
water.rate
water.speed
water.leeway
water.leeway.source
water.current.speed
water.current.direction
water.wind.speed
water.wind.direction
rudder.source
```

## Servo values from `servo.py` and `servo_calibration.py`

```text
servo.calibration
servo.position_command
servo.command
servo.speed_gain
servo.duty
servo.faults
servo.voltage
servo.current
servo.current.noise
servo.controller_temp
servo.motor_temp
servo.engaged
servo.max_current
servo.current.factor
servo.current.offset
servo.voltage.factor
servo.voltage.offset
servo.max_controller_temp
servo.max_motor_temp
servo.max_slew_speed
servo.max_slew_slow
servo.gain
servo.clutch_pwm
servo.use_brake
servo.period
servo.compensate_current
servo.compensate_voltage
servo.amp_hours
servo.watts
servo.speed
servo.speed.min
servo.speed.max
servo.position
servo.position.p
servo.position.i
servo.position.d
servo.raw_command
servo.use_eeprom
servo.state
servo.controller
servo.flags
servo.brake_hack
```

## Pilot/autogain values observed

```text
ap.P
ap.I
ap.D
ap.DD
ap.P2
ap.pilot.basic.P
ap.pilot.basic.Pgain
ap.pilot.basic.D
ap.pilot.basic.Dgain
ap.pilot.basic.DD
ap.pilot.basic.DDgain
ap.pilot.basic.PR
ap.pilot.basic.PRgain
ap.pilot.basic.FF
ap.pilot.basic.FFgain
ap.pilot.wind.P
ap.pilot.wind.Pgain
ap.pilot.wind.D
ap.pilot.wind.Dgain
ap.pilot.wind.DD
ap.pilot.wind.DDgain
ap.pilot.wind.WG
ap.pilot.wind.WGgain
ap.pilot.absolute.P
ap.pilot.absolute.Pgain
ap.pilot.absolute.I
ap.pilot.absolute.Igain
ap.pilot.absolute.D
ap.pilot.absolute.Dgain
ap.pilot.absolute.FF
ap.pilot.absolute.FFgain
ap.pilot.rate.D
ap.pilot.rate.Dgain
ap.pilot.rate.DD
ap.pilot.rate.DDgain
ap.pilot.rate.FF
ap.pilot.rate.FFgain
ap.pilot.rate.maxturnrate
ap.pilot.rate.turnraterate
ap.pilot.simple.P
ap.pilot.simple.Pgain
ap.pilot.simple.I
ap.pilot.simple.Igain
ap.pilot.simple.D
ap.pilot.simple.Dgain
ap.pilot.vmg.P
ap.pilot.vmg.Pgain
ap.pilot.vmg.D
ap.pilot.vmg.Dgain
ap.pilot.vmg.DD
ap.pilot.vmg.DDgain
```

## Current C++ coverage status

The C++ model now has typed storage for the major groups above and has expanded `FieldId`, `field_table`, and switch accessors for the core publishable/runtime-facing subset. Some lower-priority Python names still need explicit `FieldId` accessors, especially exact calibration internals and every historical pilot/autogain alias.

Remaining audit work:

```text
complete generated comparison between values.py/server.py registrations and field_table
add exact aliases for ap.P/ap.I/ap.D/ap.DD/ap.P2 if retained
add every calibration vector component as separate runtime fields if runtime publication needs them
add fixture that checks every name in this audit resolves or is explicitly marked omitted
```
