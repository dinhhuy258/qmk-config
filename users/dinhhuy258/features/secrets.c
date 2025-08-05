#include "secrets.h"
#include "definitions/constants.h"
#include "definitions/keycodes.h"

// Replace these example values with your actual secrets
const char secret_1[] PROGMEM = "secret_1";

static const char *const secrets[] PROGMEM = {secret_1};

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
