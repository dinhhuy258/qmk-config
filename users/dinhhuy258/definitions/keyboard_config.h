#pragma once

#include QMK_KEYBOARD_H

// Keyboard-specific configuration structure
typedef struct {
    keypos_t switch_app_ignore_positions[3];
    uint8_t  switch_app_ignore_positions_size;
} user_keyboard_config_t;

// Get keyboard-specific configuration
const user_keyboard_config_t* get_keyboard_config(void);

// Keyboard-specific configurations
#if defined(KEYBOARD_crkbd)
#    define KEYBOARD_SWITCH_APP_IGNORE_POSITIONS {{.col = 1, .row = 4}}
#    define KEYBOARD_SWITCH_APP_IGNORE_POSITIONS_SIZE 1
#elif defined(KEYBOARD_ergodox_ez)
#    define KEYBOARD_SWITCH_APP_IGNORE_POSITIONS {{.col = 1, .row = 12}}
#    define KEYBOARD_SWITCH_APP_IGNORE_POSITIONS_SIZE 1
#else
#    define KEYBOARD_SWITCH_APP_IGNORE_POSITIONS \
        {                                        \
        }
#    define KEYBOARD_SWITCH_APP_IGNORE_POSITIONS_SIZE 0
#endif
