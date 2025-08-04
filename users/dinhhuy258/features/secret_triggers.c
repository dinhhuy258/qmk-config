#include "secret_triggers.h"
#include "definitions/layers.h"
#include "definitions/keycodes.h"

// Global secret system state
static secret_state_t secret_state = {0};

// Helper function to handle secret key press and cleanup
static void handle_secret_key(uint16_t secret_keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        extern bool process_secret_macro(uint16_t keycode, keyrecord_t *record);
        keyrecord_t fake_record = *record;
        process_secret_macro(secret_keycode, &fake_record);
    }
    secret_mode_deactivate();
    layer_clear();
}

void secret_system_init(void) {
    secret_state.is_secret_mode_active = false;
    secret_state.activation_time       = 0;
}

bool process_secret_triggers(uint16_t keycode, keyrecord_t *record) {
    // Handle secret mode keys if active
    if (secret_state.is_secret_mode_active) {
        // Map fallback keycodes to their corresponding secret keycodes
        uint16_t secret_keycode = 0;
        switch (keycode) {
            case KC_Q:
                secret_keycode = SECRET_1;
                break;
            case KC_W:
                secret_keycode = SECRET_2;
                break;
            case KC_E:
                secret_keycode = SECRET_3;
                break;
            case SECRET_1:
            case SECRET_2:
            case SECRET_3:
                secret_keycode = keycode;
                break;
        }

        // Handle secret keys (both direct and fallback)
        if (secret_keycode != 0) {
            handle_secret_key(secret_keycode, record);
            return false; // Consume the key
        }

        // Any other key pressed while in secret mode - deactivate and pass through
        if (record->event.pressed) {
            // Only deactivate on key press, not key release
            secret_mode_deactivate();

            // Force clear all layers to return to BASE
            layer_clear();

            return true; // Pass the key through normally
        } else {
            // For key releases, ignore them if they happen shortly after activation
            // This prevents immediate deactivation from B/N releases or layer key releases
            uint16_t elapsed = timer_elapsed(secret_state.activation_time);
            if (elapsed < 500) { // Ignore releases within 500ms of activation
                return false;    // Consume the key release without deactivating
            }
            // After 500ms, key releases pass through normally without deactivating
            return true;
        }
    }

    return true; // Pass through normally
}

void secret_mode_activate(void) {
    secret_state.is_secret_mode_active = true;
    secret_state.activation_time       = timer_read();

    // Clear all layers first, then activate only SECRET layer
    // This ensures SECRET layer has full precedence
    layer_clear();
    layer_on(SECRET);

    // Clear any modifier states for clean secret transmission
    clear_mods();
    clear_weak_mods();
}

void secret_mode_deactivate(void) {
    secret_state.is_secret_mode_active = false;
    layer_off(SECRET);
}

bool is_secret_mode_active(void) {
    return secret_state.is_secret_mode_active;
}

void secret_system_task(void) {
    // No background tasks needed for simplified system
}
