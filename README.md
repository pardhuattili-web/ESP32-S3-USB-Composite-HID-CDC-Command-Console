# ESP32-S3 USB Composite HID + CDC Command Console

Portfolio-ready ESP-IDF/Embedded C reference for an ESP32-S3 USB peripheral combining a keyboard-style HID interface with a CDC command console.

## Features
- USB HID keyboard report abstraction
- USB CDC text-command abstraction
- Button debounce and press/long-press events
- Rotary encoder quadrature decoder
- FreeRTOS event-driven architecture
- Macro slots with validation
- NVS storage integration seam
- Runtime diagnostics and testable host logic

## Architecture
```
GPIO/Encoder -> Input Driver -> FreeRTOS Queue -> App/Macro Engine
                                             |-> USB HID
                                             |-> USB CDC CLI
                                             |-> NVS
```

## Repository
- `main/`: application entry point
- `components/input/`: input event processing
- `components/hid/`: HID reports and macros
- `components/cli/`: command parser
- `components/storage/`: persistence abstraction
- `components/runtime/`: application integration
- `tests/`: host unit tests
- `docs/`: architecture and validation notes
- `tools/`: CDC host helper

## Example CLI
```text
help
status
macro set 0 CTRL C
macro set 1 CTRL V
macro run 0
macro list
config save
```

## Build
```bash
idf.py set-target esp32s3
idf.py build
idf.py flash monitor
```

## Hardware
ESP32-S3 board with native USB, two push buttons, one rotary encoder and optional status LED. Select GPIOs appropriate to the exact development board.

## Important integration note
The application deliberately uses small adapter seams for TinyUSB and NVS. Bind those seams to the exact ESP-IDF/TinyUSB APIs of the installed ESP-IDF release. This keeps the host-testable logic independent from USB descriptor/version details.

## Portfolio talking points
USB composite architecture, FreeRTOS event queues, interrupt-safe input handling, HID report encoding, CDC command parsing, flash persistence, driver abstraction, diagnostics and unit testing.
