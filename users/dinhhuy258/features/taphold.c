#include "taphold.h"
#include "../definitions/keycodes.h"

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case TD_SWITCH_APP:
            return TAPPING_TERM + 50;
        default:
            return TAPPING_TERM;
    }
}
