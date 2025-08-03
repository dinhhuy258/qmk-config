#include "secret_triggers.h"
#include "definitions/layers.h"
#include "definitions/keycodes.h"

#ifndef NO_SECRETS

// Global secret system state
static secret_state_t secret_state = {0};
static deferred_token secret_timeout_token = INVALID_DEFERRED_TOKEN;

// Define the activation sequence: NAV+SYM (WM layer active) -> G+H -> S+E+C
const secret_sequence_t SECRET_ACTIVATION_SEQUENCE = {
    .keys = {KC_S, KC_E, KC_C},
    .length = 3,
    .timeout_ms = SECRET_SEQUENCE_TIMEOUT_MS
};

// Emergency disable sequence: E+S+C+A+P+E
const secret_sequence_t SECRET_EMERGENCY_SEQUENCE = {
    .keys = {KC_E, KC_S, KC_C, KC_A, KC_P, KC_E},
    .length = 6,
    .timeout_ms = SECRET_SEQUENCE_TIMEOUT_MS
};

// Forward declarations
static uint32_t secret_timeout_callback(uint32_t trigger_time, void *cb_arg);
static bool check_layer_activation_prerequisites(void);
static bool process_combo_trigger(uint16_t keycode, keyrecord_t *record);
static bool process_steganographic_combos(uint16_t keycode, keyrecord_t *record);

void secret_system_init(void) {
    secret_state.is_secret_mode_active = false;
    secret_state.awaiting_sequence = false;
    secret_state.sequence_position = 0;
    secret_state.last_trigger_time = 0;
    secret_state.failed_attempts = 0;
    secret_state.emergency_disabled = false;
}

bool process_secret_triggers(uint16_t keycode, keyrecord_t *record) {
    // Check if secrets are emergency disabled
    if (secret_state.emergency_disabled) {
        return true; // Pass through all keys normally
    }
    
    // Check for emergency disable sequence first
    if (check_secret_sequence(keycode) && secret_state.sequence_position >= SECRET_EMERGENCY_SEQUENCE.length) {
        secret_emergency_disable();
        return false; // Consume the key
    }
    
    // Handle secret mode keys if active
    if (secret_state.is_secret_mode_active) {
        switch (keycode) {
            case SECRET_1:
            case SECRET_2:
            case SECRET_3:
            case SECRET_4:
            case SECRET_5:
                if (record->event.pressed) {
                    // Call the actual secret function (defined in secrets.c)
                    extern bool process_secret_macro(uint16_t keycode, keyrecord_t *record);
                    process_secret_macro(keycode, record);
                    secret_mode_deactivate(); // Auto-deactivate after use
                }
                return false; // Consume the key
                
            case SECRET_EMERGENCY_DISABLE:
                if (record->event.pressed) {
                    secret_emergency_disable();
                }
                return false; // Consume the key
                
            case KC_ESC:
                if (record->event.pressed) {
                    secret_mode_deactivate();
                }
                return false; // Consume the key
        }
    }
    
    // Check for sequence-based triggers
    if (secret_state.awaiting_sequence) {
        if (record->event.pressed) {
            if (check_secret_sequence(keycode)) {
                if (secret_state.sequence_position >= SECRET_ACTIVATION_SEQUENCE.length) {
                    secret_mode_activate();
                    secret_sequence_reset();
                    return false; // Consume the key
                }
            } else {
                // Wrong key in sequence
                secret_state.failed_attempts++;
                secret_sequence_reset();
                
                if (secret_state.failed_attempts >= SECRET_MAX_FAILED_ATTEMPTS) {
                    // Temporary lockout
                    secret_state.emergency_disabled = true;
                    secret_timeout_token = defer_exec(SECRET_LOCKOUT_TIME_MS, secret_timeout_callback, NULL);
                }
                return true; // Let the wrong key through normally
            }
        }
        return false; // Consume all keys during sequence mode
    }
    
    // Check for combo-based triggers
    if (process_combo_trigger(keycode, record)) {
        return false; // Combo trigger consumed the key
    }
    
    // Check for steganographic combo triggers
    if (process_steganographic_combos(keycode, record)) {
        return false; // Steganographic trigger consumed the key
    }
    
    return true; // Pass through normally
}

static bool check_layer_activation_prerequisites(void) {
    // Check if we're in WM layer (NAV + SYM held)
    return layer_state_is(WM);
}

static bool process_combo_trigger(uint16_t keycode, keyrecord_t *record) {
    static bool g_pressed = false;
    static bool h_pressed = false;
    static uint16_t combo_start_time = 0;
    
    if (!check_layer_activation_prerequisites()) {
        g_pressed = false;
        h_pressed = false;
        return false;
    }
    
    if (record->event.pressed) {
        if (keycode == KC_G) {
            g_pressed = true;
            combo_start_time = timer_read();
        } else if (keycode == KC_H) {
            h_pressed = true;
            if (!combo_start_time) combo_start_time = timer_read();
        }
        
        // Check if both G and H are pressed within reasonable time
        if (g_pressed && h_pressed && (timer_elapsed(combo_start_time) < 500)) {
            secret_state.awaiting_sequence = true;
            secret_state.sequence_position = 0;
            secret_state.last_trigger_time = timer_read();
            g_pressed = false;
            h_pressed = false;
            return true; // Consumed
        }
    } else {
        // Key released
        if (keycode == KC_G) g_pressed = false;
        if (keycode == KC_H) h_pressed = false;
    }
    
    return false;
}

static bool process_steganographic_combos(uint16_t keycode, keyrecord_t *record) {
    static uint16_t z_press_time = 0;
    static bool z_held = false;
    
    if (keycode == KC_Z) {
        if (record->event.pressed) {
            z_press_time = timer_read();
            z_held = true;
        } else {
            uint16_t hold_duration = timer_elapsed(z_press_time);
            z_held = false;
            
            // Normal tap (< 500ms) = normal undo combo behavior
            // Long hold (> 2000ms) = secret trigger
            if (hold_duration > 2000) {
                secret_state.awaiting_sequence = true;
                secret_state.sequence_position = 0;
                secret_state.last_trigger_time = timer_read();
                return true; // Consumed
            }
        }
    } else if (keycode == KC_X && record->event.pressed && z_held) {
        uint16_t hold_duration = timer_elapsed(z_press_time);
        if (hold_duration > 2000) {
            // Z held for >2s when X pressed = secret mode
            secret_state.awaiting_sequence = true;
            secret_state.sequence_position = 0;
            secret_state.last_trigger_time = timer_read();
            z_held = false;
            return true; // Consumed
        }
    }
    
    return false;
}

bool check_secret_sequence(uint16_t keycode) {
    const secret_sequence_t *sequence = secret_state.emergency_disabled ? 
        &SECRET_EMERGENCY_SEQUENCE : &SECRET_ACTIVATION_SEQUENCE;
    
    if (secret_state.sequence_position < sequence->length) {
        if (keycode == sequence->keys[secret_state.sequence_position]) {
            secret_state.sequence_position++;
            secret_state.last_trigger_time = timer_read();
            return true;
        }
    }
    return false;
}

void secret_sequence_reset(void) {
    secret_state.awaiting_sequence = false;
    secret_state.sequence_position = 0;
    secret_state.last_trigger_time = 0;
}

void secret_mode_activate(void) {
    if (secret_state.emergency_disabled) return;
    
    secret_state.is_secret_mode_active = true;
    layer_on(SECRET);
    
    // Set timeout for auto-deactivation
    if (secret_timeout_token != INVALID_DEFERRED_TOKEN) {
        cancel_deferred_exec(secret_timeout_token);
    }
    secret_timeout_token = defer_exec(SECRET_MODE_TIMEOUT_MS, secret_timeout_callback, NULL);
    
    // Clear any modifier states for clean secret transmission
    clear_mods();
    clear_weak_mods();
}

void secret_mode_deactivate(void) {
    secret_state.is_secret_mode_active = false;
    layer_off(SECRET);
    secret_sequence_reset();
    
    if (secret_timeout_token != INVALID_DEFERRED_TOKEN) {
        cancel_deferred_exec(secret_timeout_token);
        secret_timeout_token = INVALID_DEFERRED_TOKEN;
    }
}

void secret_emergency_disable(void) {
    secret_mode_deactivate();
    secret_state.emergency_disabled = true;
    secret_state.failed_attempts = 0;
    
    // Set long timeout for re-enabling
    if (secret_timeout_token != INVALID_DEFERRED_TOKEN) {
        cancel_deferred_exec(secret_timeout_token);
    }
    secret_timeout_token = defer_exec(SECRET_LOCKOUT_TIME_MS * 5, secret_timeout_callback, NULL);
}

bool is_secret_mode_active(void) {
    return secret_state.is_secret_mode_active;
}

void secret_system_task(void) {
    // Check for sequence timeout
    if (secret_state.awaiting_sequence) {
        if (timer_elapsed(secret_state.last_trigger_time) > SECRET_SEQUENCE_TIMEOUT_MS) {
            secret_sequence_reset();
        }
    }
}

void secret_combo_triggered(void) {
    // Called when the G+H combo is triggered in WM layer
    secret_state.awaiting_sequence = true;
    secret_state.sequence_position = 0;
    secret_state.last_trigger_time = timer_read();
}

static uint32_t secret_timeout_callback(uint32_t trigger_time, void *cb_arg) {
    if (secret_state.emergency_disabled) {
        // Re-enable system after lockout
        secret_state.emergency_disabled = false;
        secret_state.failed_attempts = 0;
    } else {
        // Normal timeout - deactivate secret mode
        secret_mode_deactivate();
    }
    
    secret_timeout_token = INVALID_DEFERRED_TOKEN;
    return 0; // Don't repeat
}

#endif // NO_SECRETS