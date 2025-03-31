#pragma once

// https://docs.qmk.fm/#/config_options?id=setting-handedness
#define MASTER_RIGHT

#ifdef CUSTOM_SERIAL_PIN
    // The default serial pin is D2, but we can customize it with the SERIAL_PIN build flag
    #undef SOFT_SERIAL_PIN
    #define SOFT_SERIAL_PIN CUSTOM_SERIAL_PIN
#endif
