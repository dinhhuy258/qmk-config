#pragma once

#include QMK_KEYBOARD_H

// Secret strings - modify these with your actual secrets
// These will be stored in program memory for security
extern const char secret_1[] PROGMEM;
extern const char secret_2[] PROGMEM;
extern const char secret_3[] PROGMEM;

// Function to process secret macros
bool process_secret_macro(uint16_t keycode, keyrecord_t *record);
