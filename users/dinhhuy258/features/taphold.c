#include "definitions/constants.h"
#include "definitions/keycodes.h"
#include "definitions/layers.h"

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case TD_SWITCH_APP:
            return TAPPING_TERM + TD_SWITCH_APP_TAPPING_TERM_OFFSET;
        default:
            return TAPPING_TERM;
    }
}

bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LT(NAV, KC_ESC):
        case LT(MOU, KC_SPC):
        case LT(SYM, KC_NO):
            // Immediately select the hold action when another key is tapped.
            return true;
        default:
            // Do not select the hold action when another key is tapped.
            return false;
    }
}
