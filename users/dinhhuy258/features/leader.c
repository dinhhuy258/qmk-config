#include "leader.h"
#include "definitions/keycodes.h"
#include "definitions/layers.h"

bool process_leader_key(uint16_t keycode, keyrecord_t *record) {
    if (keycode != LT(SYM, KC_NO)) {
        return true; // Not a leader key, pass through normally
    }

    if (record->tap.count && record->event.pressed) {
        leader_start();

        return false; // Consume the key
    }

    return true;
}

void leader_end_user(void) {
    if (leader_sequence_one_key(KC_Q)) {
        SEND_STRING("Hello world");
    }
}
