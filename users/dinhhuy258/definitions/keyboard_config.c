#include "keyboard_config.h"

static const user_keyboard_config_t user_keyboard_config = {
    .switch_app_ignore_positions      = KEYBOARD_SWITCH_APP_IGNORE_POSITIONS,
    .switch_app_ignore_positions_size = KEYBOARD_SWITCH_APP_IGNORE_POSITIONS_SIZE,
};

const user_keyboard_config_t* get_keyboard_config(void) {
    return &user_keyboard_config;
}
