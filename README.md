# Keyboard Keymaps

This repository contains firmware for my keyboards running QMK.

## Installation

This repository is designed as an [External QMK Userspace](https://docs.qmk.fm/newbs_external_userspace). To use it with QMK, follow these steps:

1. [Set up QMK](https://docs.qmk.fm/newbs) if you haven't already.
2. Clone this repository to your local machine.
3. Run the following command to configure QMK to use this repository as an overlay:

```sh
qmk config user.overlay_dir="$(realpath .)"
```

Once configured, you can compile and flash the keymaps for your keyboards using the following commands:

### Ergodox EZ

To compile and flash the keymap for the Ergodox EZ, use:

```sh
make ergodox_ez:dinhhuy258:teensy
```

### Corne

To compile and flash the keymap for the Corne, use:

```sh
make crkbd:dinhhuy258:flash
```

For one of my Corne keyboards equipped with the RP2040 chip, the default serial D2 pin is non-functional. As a result, the following modification has been made:

- The D2 and D3 pins have been connected and soldered together.
- D3 can be configured to function as the serial data pin in the firmware by using the build flag:

```sh
make crkbd:dinhhuy258:flash USE_SERIAL_PIN_D3=yes
```

```
              .__|~~|__.
    D3 [TX0] -|        |- [RAW]
    D2 [RX1] -|        |- [GND]
       [GND] -|        |- [RST]
       [GND] -|  Pro   |- [VCC]
SDA/D1 [  2] -|  Micro |- [A3 ] F4
SCL/D0 [  3] -|        |- [A2 ] F5
    D4 [  4] -|        |- [A1 ] F6
    C6 [  5] -|        |- [A0 ] F7
    D7 [  6] -|        |- [15 ] B1
    E6 [  7] -|        |- [14 ] B3
    B4 [  8] -|        |- [16 ] B2
    B5 [  9] -|________|- [10 ] B6
```

Additionally, RGB lighting can be controlled with build flags:

```sh
make crkbd:dinhhuy258:flash USE_RGB_LIGHTING=yes
```

You can also customize the tapping term (default is 200ms) by using the `TAPPING_TERM` build flag:

```sh
make crkbd:dinhhuy258:flash TAPPING_TERM=150
```

To initially boot the RP2040 into bootloader mode

1. Hold down the BOOT button on the RP2040 board.
2. While holding the BOOT button, plug the USB cable into your computer.
3. Release the BOOT button after the board is connected. The RP2040 should now appear as a USB mass storage device, allowing you to flash the firmware.
