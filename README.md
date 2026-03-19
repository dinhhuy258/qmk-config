# Keyboard Keymaps

This repository contains firmware for my keyboards running QMK.

## Keymap

![my_keymap](https://github.com/user-attachments/assets/067554bd-2ec2-4ec4-bfe4-7f3c0c08b968)

This userspace defines a **Leader** workflow triggered by tapping the **SYM** layer key (configured as `LT(SYM, KC_NO)`) and then entering short sequences.

## Leader Key Sequences

### Command Sequences (Leader → J → key)

Sends **Cmd+Alt+Ctrl+\<Key>** to launch my custom commands:

| Sequence     | Sends          | Action                           |
| ------------ | -------------- | -------------------------------- |
| `Leader J J` | Cmd+Alt+Ctrl+J | Bitwarden: Get password          |
| `Leader J K` | Cmd+Alt+Ctrl+K | Bitwarden: Get TOTP              |
| `Leader J F` | Cmd+Alt+Ctrl+F | Open command palette (`~/.cmds`) |
| `Leader J D` | Cmd+Alt+Ctrl+D | File manager                     |
| `Leader J S` | Cmd+Alt+Ctrl+S | Google search                    |
| `Leader J W` | Cmd+Alt+Ctrl+W | AWS Console in Firefox           |
| `Leader J A` | Cmd+Alt+Ctrl+A | Open notes (`index.norg`)        |
| `Leader J Q` | Cmd+Alt+Ctrl+Q | Launch `k9s` (Kubernetes CLI)    |
| `Leader J G` | Cmd+Alt+Ctrl+G | Approve GitHub PR from clipboard |

### Tmux Sequences (Leader → F → key)

Sends tmux commands prefixed with **Ctrl+F**:

| Sequence     | Sends          | Action             |
| ------------ | -------------- | ------------------ |
| `Leader F F` | Ctrl+F         | Tmux prefix only   |
| `Leader F R` | Ctrl+F, R      | Reload tmux config |
| `Leader F W` | Ctrl+F, W      | Delete panel       |
| `Leader F T` | Ctrl+F, T      | New panel          |
| `Leader F G` | Ctrl+F, G      | Vertical split     |
| `Leader F V` | Ctrl+F, V      | Horizontal split   |
| `Leader F J` | Ctrl+F, J      | Enter copy mode    |
| `Leader F K` | Ctrl+F, K      | `tmux-jump`        |
| `Leader F L` | Ctrl+F, L      | `tmux-urlview`     |
| `Leader F D` | Ctrl+F, D      | Swap panel down    |
| `Leader F S` | Ctrl+F, S      | Swap panel up      |
| `Leader F Y` | Ctrl+F, Y      | Save session       |
| `Leader F P` | Ctrl+F, P      | Load session       |
| `Leader F A` | Ctrl+F, Ctrl+G | Navi cheatsheet    |

### Text Expansion Sequences (Leader → A → key)

Types common text strings:

| Sequence     | Output       |
| ------------ | ------------ |
| `Leader A D` | `dinhhuy258` |
| `Leader A L` | `LGTM`       |

## Installation

This repository is designed as an [External QMK Userspace](https://docs.qmk.fm/newbs_external_userspace). To use it with QMK, follow these steps:

1. [Set up QMK](https://docs.qmk.fm/newbs) if you have not already.
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
make crkbd:dinhhuy258:flash SERIAL_PIN=D3
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
