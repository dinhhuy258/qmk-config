#pragma once

#include QMK_KEYBOARD_H

#ifndef NO_SECRETS

// Secret system state tracking
typedef struct {
    bool is_secret_mode_active;
    bool awaiting_sequence;
    uint8_t sequence_position;
    uint16_t last_trigger_time;
    uint8_t failed_attempts;
    bool emergency_disabled;
} secret_state_t;

// Secret trigger sequences
typedef struct {
    uint16_t keys[8];  // Maximum 8 keys in sequence
    uint8_t length;
    uint32_t timeout_ms;
} secret_sequence_t;

// Function declarations
void secret_system_init(void);
bool process_secret_triggers(uint16_t keycode, keyrecord_t *record);
void secret_system_task(void);
void secret_mode_activate(void);
void secret_mode_deactivate(void);
void secret_emergency_disable(void);
bool is_secret_mode_active(void);
void secret_sequence_reset(void);
bool check_secret_sequence(uint16_t keycode);
void secret_combo_triggered(void);

// Timeout constants
#define SECRET_MODE_TIMEOUT_MS 30000    // 30 seconds
#define SECRET_SEQUENCE_TIMEOUT_MS 5000 // 5 seconds for sequence completion
#define SECRET_MAX_FAILED_ATTEMPTS 3    // Lock out after 3 failed attempts
#define SECRET_LOCKOUT_TIME_MS 60000    // 1 minute lockout

// Secret trigger definitions
extern const secret_sequence_t SECRET_ACTIVATION_SEQUENCE;
extern const secret_sequence_t SECRET_EMERGENCY_SEQUENCE;

#else
// No-op definitions when secrets are disabled
#define secret_system_init()
#define process_secret_triggers(keycode, record) true
#define secret_system_task()
#define secret_mode_activate()
#define secret_mode_deactivate()
#define secret_emergency_disable()
#define is_secret_mode_active() false
#define secret_sequence_reset()
#define check_secret_sequence(keycode) false
#endif // NO_SECRETS