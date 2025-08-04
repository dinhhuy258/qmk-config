#pragma once

#include QMK_KEYBOARD_H

// Secret system state tracking
typedef struct {
    bool is_secret_mode_active;
} secret_state_t;

// Function declarations
void secret_system_init(void);
bool process_secret_triggers(uint16_t keycode, keyrecord_t *record);
void secret_system_task(void);
void secret_mode_activate(void);
void secret_mode_deactivate(void);
bool is_secret_mode_active(void);