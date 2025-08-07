#include "definitions/keycodes.h"
#include "definitions/constants.h"

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case TD_SWITCH_APP:
            return TAPPING_TERM + TD_SWITCH_APP_TAPPING_TERM_OFFSET;
        default:
            return TAPPING_TERM;
    }
}
