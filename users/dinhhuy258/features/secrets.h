#pragma once

#include QMK_KEYBOARD_H

extern const char secret_1[] PROGMEM;

bool process_secret_macro(uint16_t keycode, keyrecord_t *record);
bool process_secret_triggers(uint16_t keycode, keyrecord_t *record);
void secret_mode_activate(void);
void secret_mode_deactivate(void);
