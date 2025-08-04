#include "secret_triggers.h"
#include "definitions/layers.h"
#include "definitions/keycodes.h"

// Global secret system state
static secret_state_t secret_state = {0};

void secret_system_init(void) {
    secret_state.is_secret_mode_active = false;
}

bool process_secret_triggers(uint16_t keycode, keyrecord_t *record) {
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
                }
                // Always deactivate after any keypress in secret mode (one-shot behavior)
                secret_mode_deactivate();
                return false; // Consume the key

            default:
                // Any other key pressed while in secret mode - deactivate and pass through
                if (record->event.pressed) {
                    secret_mode_deactivate();
                }
                return true; // Pass the key through normally
        }
    }

    return true; // Pass through normally
}

void secret_mode_activate(void) {
    secret_state.is_secret_mode_active = true;
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
