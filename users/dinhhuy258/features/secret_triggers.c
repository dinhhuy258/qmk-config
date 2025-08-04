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
}

bool process_secret_triggers(uint16_t keycode, keyrecord_t *record) {
    if (secret_state.is_secret_mode_active) {
        switch (keycode) {
            case KC_Q:
                handle_secret_key(SECRET_1, record);

                return false; // Consume the key
        }
    }

    return true; // Pass through normally
}

void secret_mode_activate(void) {
    secret_state.is_secret_mode_active = true;

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
