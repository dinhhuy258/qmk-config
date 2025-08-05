#include "secrets.h"
#include "definitions/constants.h"
#include "definitions/keycodes.h"
#include "definitions/layers.h"

#if __has_include("secrets_config.h")
#    include "secrets_config.h"
#endif

#ifndef SECRET_1_VALUE
#    define SECRET_1_VALUE ""
#endif

const char secret_1[] PROGMEM = SECRET_1_VALUE;

static const char *const secrets[] PROGMEM = {secret_1};

void process_secret_macro(uint16_t keycode, keyrecord_t *record) {
    clear_mods();
    clear_oneshot_mods();
    send_string_with_delay_P(secrets[keycode - SECRET_1], MACRO_TIMER);
}

void secret_mode_deactivate(void) {
    layer_move(BASE);
}

bool process_secret_triggers(uint16_t keycode, keyrecord_t *record) {
    if (layer_state_is(SECRET)) {
        switch (keycode) {
            case KC_Q:
                if (record->event.pressed) {
                    process_secret_macro(SECRET_1, record);
                }
                secret_mode_deactivate();

                return false; // Consume the key
        }
    }

    return true; // Pass through normally
}

void secret_mode_activate(void) {
    layer_move(SECRET);
}
