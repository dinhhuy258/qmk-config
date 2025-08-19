#include "definitions/constants.h"
#include "definitions/keycodes.h"
#include "definitions/layers.h"

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t* record) {
    switch (keycode) {
        case TD_SWITCH_APP:
            return TAPPING_TERM + TD_SWITCH_APP_TAPPING_TERM_OFFSET;
        default:
            return TAPPING_TERM;
    }
}

bool get_chordal_hold(uint16_t tap_hold_keycode, keyrecord_t* tap_hold_record, uint16_t other_keycode, keyrecord_t* other_record) {
    // Exceptionally allow some one-handed chords for thumb keys.
    switch (tap_hold_keycode) {
        case LT(NAV, KC_ESC):
        case LT(MOU, KC_SPC):
        case LT(SYM, KC_NO):
        case LT(SHORTCUT, KC_ENT):
            return true;
    }

    // Otherwise defer to the opposite hands rule.
    return get_chordal_hold_default(tap_hold_record, other_record);
}

bool get_permissive_hold(uint16_t keycode, keyrecord_t* record) {
    switch (keycode) {
        case LGUI_T(KC_SCLN):
            // Do not select the hold action when another key is tapped.
            return false;
        default:
            // Immediately select the hold action when another key is tapped.
            return true;
    }
}
