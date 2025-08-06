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
#ifndef SECRET_2_VALUE
#    define SECRET_2_VALUE ""
#endif
#ifndef SECRET_3_VALUE
#    define SECRET_3_VALUE ""
#endif
#ifndef SECRET_4_VALUE
#    define SECRET_4_VALUE ""
#endif
#ifndef SECRET_5_VALUE
#    define SECRET_5_VALUE ""
#endif

const char secret_1[] PROGMEM = SECRET_1_VALUE;
const char secret_2[] PROGMEM = SECRET_2_VALUE;
const char secret_3[] PROGMEM = SECRET_3_VALUE;
const char secret_4[] PROGMEM = SECRET_4_VALUE;
const char secret_5[] PROGMEM = SECRET_5_VALUE;

static const char *const secrets[] PROGMEM = {secret_1, secret_2, secret_3, secret_4, secret_5};

void process_secret_macro(uint16_t keycode, keyrecord_t *record) {
    clear_mods();
    clear_oneshot_mods();
    send_string_with_delay_P((const char *)pgm_read_ptr(&secrets[keycode - SECRET_1]), MACRO_TIMER);
}

void secret_mode_deactivate(void) {
    layer_move(BASE);
}

bool process_secret(uint16_t keycode, keyrecord_t *record) {
    if (keycode < SECRET_1 || keycode > SECRET_5) {
        return true; // Not a secret keycode, pass through normally
    }

    if (record->event.pressed) {
        process_secret_macro(keycode, record);
    }
    secret_mode_deactivate();
    return false; // Consume the key
}

void secret_mode_activate(void) {
    layer_move(SECRET);
}
