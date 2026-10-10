# Changelog

All notable changes to this project are documented in this file.

The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.1.0/),
and this project adheres to [Semantic Versioning](https://semver.org/spec/v2.0.0.html).

## [v1.0.1] - 2026-10-03

This patch suppresses brief filament-pull spikes in weight estimates while preserving saved calibration and spool tare.

### Fixes

- Use the median of the latest 25 samples so brief disturbances do not pull down the reported filament remaining.
- Continue tracking sustained load changes and gradual consumption while retaining all samples for zero and reference-mass captures, noise measurements, and stability checks.
- Preserve calibration, spool tare, settings, and entities through a normal OTA update; no recalibration is required.

### Documentation & Links

- [Build and calibration guide](https://github.com/fabianwimberger/esp32-filament-scale/blob/v1.0.1/docs/build.md)
- [Filtering and configuration](https://github.com/fabianwimberger/esp32-filament-scale/blob/v1.0.1/README.md)
- [ESP32-C3 OTA firmware](https://github.com/fabianwimberger/esp32-filament-scale/releases/download/v1.0.1/firmware.ota.bin), built with ESPHome 2026.9.1. Use this image for OTA updates to retain saved settings.

## [v1.0.0] - 2026-10-03

First release of the printed filament scale for the SUNLU S2 dryer: CAD, printable parts and ESPHome firmware.

### Features

- Report filament remaining in grams and percent to Home Assistant, counting down from the spool that was loaded
- Calibrate from Home Assistant with three buttons: empty platform, known mass, dryer with full spool
- Keep zero, gain and spool capture across reboots and OTA updates, with no startup tare
- Reject captures while the reading moves, and drop missing, stale or saturated samples
- Four printed parts in print orientation: base, top and two click-in board caps, held together by four M3 × 20 screws
- Parametric OpenSCAD source with assertions for every screw length and clearance
- Diagnostic sensors for raw counts, noise range, saved calibration, chip temperature and Wi-Fi signal

### Testing

- Run the readings test, the mesh checks and ESPHome config validation on pull requests and pushes to main and develop
- Compile the ESP32-C3 firmware in CI with ESPHome 2026.9.1

### Documentation & Links

- Repository: https://github.com/fabianwimberger/esp32-filament-scale
- Build guide: [docs/build.md](https://github.com/fabianwimberger/esp32-filament-scale/blob/main/docs/build.md)
- Design notes: [docs/design.md](https://github.com/fabianwimberger/esp32-filament-scale/blob/main/docs/design.md)
