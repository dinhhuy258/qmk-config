#pragma once

// https://docs.qmk.fm/#/config_options?id=setting-handedness
#define MASTER_RIGHT

// The default serial pin is D2, but my microcontroller has a problem with this pin, causing communication issues between the split keyboards.
// So, I soldered a wire between the D2 and D3 pins and used D3 as the serial pin.
#undef SOFT_SERIAL_PIN
#define SOFT_SERIAL_PIN D3
