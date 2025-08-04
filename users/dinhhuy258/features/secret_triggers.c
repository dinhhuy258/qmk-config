#include "secret_triggers.h"
#include "definitions/layers.h"
#include "definitions/keycodes.h"

// Global secret system state
static secret_state_t secret_state = {0};

void secret_system_init(void) {
    secret_state.is_secret_mode_active = false;
    secret_state.activation_time       = 0;
}

bool process_secret_triggers(uint16_t keycode, keyrecord_t *record) {
    // Handle secret mode keys if active
    if (secret_state.is_secret_mode_active) {
#if defined(KEYBOARD_ergodox_ez)
        // Debug: Flash LED 1 when any key is pressed in secret mode
        if (record->event.pressed) {
            ergodox_right_led_1_off();
            wait_ms(20);
            ergodox_right_led_1_on();
        }
#endif
        switch (keycode) {
            case KC_Q: // This should never happen if layer is working correctly
#if defined(KEYBOARD_ergodox_ez)
                       // Flash LED 2 if we receive KC_Q instead of SECRET_1 (indicates layer problem)
                if (record->event.pressed) {
                    ergodox_right_led_2_off();
                    wait_ms(100);
                    ergodox_right_led_2_on();
                    wait_ms(100);
                    ergodox_right_led_2_off();
                    wait_ms(100);
                    ergodox_right_led_2_on();
                }
#endif
                // Manually call SECRET_1 processing
                if (record->event.pressed) {
                    extern bool process_secret_macro(uint16_t keycode, keyrecord_t *record);
                    // Create a fake record with SECRET_1 keycode
                    keyrecord_t fake_record = *record;
                    process_secret_macro(SECRET_1, &fake_record);
                }
                secret_mode_deactivate();
                // Force clear all layers to return to BASE
                layer_clear();
                return false; // Consume the key

            case SECRET_1:
            case SECRET_2:
            case SECRET_3:
            case SECRET_4:
            case SECRET_5:
                if (record->event.pressed) {
#if defined(KEYBOARD_ergodox_ez)
                    // Flash LEDs to show secret key was pressed
                    ergodox_right_led_1_off();
                    ergodox_right_led_2_off();
                    ergodox_right_led_3_off();
                    wait_ms(50);
                    ergodox_right_led_1_on();
                    ergodox_right_led_2_on();
                    ergodox_right_led_3_on();
                    wait_ms(50);
#endif
                    // Call the actual secret function (defined in secrets.c)
                    extern bool process_secret_macro(uint16_t keycode, keyrecord_t *record);
                    process_secret_macro(keycode, record);
                }
                // Always deactivate after any keypress in secret mode (one-shot behavior)
                secret_mode_deactivate();
                // Force clear all layers to return to BASE
                layer_clear();
                return false; // Consume the key

            default:
                // Any other key pressed while in secret mode - deactivate and pass through
                if (record->event.pressed) {
#if defined(KEYBOARD_ergodox_ez)
                    // Flash LED 3 for any unhandled key in secret mode
                    ergodox_right_led_3_off();
                    wait_ms(50);
                    ergodox_right_led_3_on();
                    wait_ms(50);
                    ergodox_right_led_3_off();
                    wait_ms(50);
                    ergodox_right_led_3_on();
#endif
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

    if defined (KEYBOARD_ergodox_ez)
        // Turn on all 3 LEDs for debugging
        ergodox_right_led_1_on();
    ergodox_right_led_2_on();
    ergodox_right_led_3_on();
#endif

    // Clear any modifier states for clean secret transmission
    clear_mods();
    clear_weak_mods();
}

void secret_mode_deactivate(void) {
    secret_state.is_secret_mode_active = false;
    layer_off(SECRET);

#if defined(KEYBOARD_ergodox_ez)
    // Turn off all 3 LEDs
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
#endif
}

bool is_secret_mode_active(void) {
    return secret_state.is_secret_mode_active;
}

void secret_system_task(void) {
    // No background tasks needed for simplified system
}
