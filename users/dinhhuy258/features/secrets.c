#include "secrets.h"
#include "definitions/constants.h"
#include "definitions/keycodes.h"
#include "definitions/layers.h"

// Replace these example values with your actual secrets
const char secret_1[] PROGMEM = "secret_1";

static const char *const secrets[] PROGMEM = {secret_1};

// Helper function to handle secret key press and cleanup
static void handle_secret_key(uint16_t secret_keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        keyrecord_t fake_record = *record;
        process_secret_macro(secret_keycode, &fake_record);
    }
    secret_mode_deactivate();
}

bool process_secret_macro(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case SECRET_1 ... SECRET_1:
            if (record->event.pressed) {
                clear_mods();
                clear_oneshot_mods();
                send_string_with_delay_P(secrets[keycode - SECRET_1], MACRO_TIMER);
            }
            return false;
    }

    return true;
}

bool process_secret_triggers(uint16_t keycode, keyrecord_t *record) {
    if (layer_state_is(SECRET)) {
        switch (keycode) {
            case KC_Q:
                handle_secret_key(SECRET_1, record);
                return false; // Consume the key
        }
    }

    return true; // Pass through normally
}

void secret_mode_activate(void) {
    layer_clear();
    layer_on(SECRET);
}

void secret_mode_deactivate(void) {
    layer_clear();
}
