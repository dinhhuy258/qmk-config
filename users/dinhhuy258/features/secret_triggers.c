#include "secret_triggers.h"
#include "definitions/layers.h"
#include "definitions/keycodes.h"

static void handle_secret_key(uint16_t secret_keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        extern bool process_secret_macro(uint16_t keycode, keyrecord_t *record);
        keyrecord_t fake_record = *record;
        process_secret_macro(secret_keycode, &fake_record);
    }
    secret_mode_deactivate();
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
