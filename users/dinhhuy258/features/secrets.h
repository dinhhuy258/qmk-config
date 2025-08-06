#pragma once

#include QMK_KEYBOARD_H

bool process_secret(uint16_t keycode, keyrecord_t *record);
void secret_mode_activate(void);
