#include "leader.h"
#include "definitions/keycodes.h"
#include "definitions/layers.h"
#include "features/secrets.h"

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
    process_secrets();

    // Leader + C + [key] combinations for cmd-alt-ctrl shortcuts
    if (leader_sequence_three_keys(KC_C, KC_R, KC_NO)) {
        register_code(KC_LGUI);
        register_code(KC_LALT);
        register_code(KC_LCTL);
        register_code(KC_R);
        unregister_code(KC_R);
        unregister_code(KC_LCTL);
        unregister_code(KC_LALT);
        unregister_code(KC_LGUI);
    }
    if (leader_sequence_three_keys(KC_C, KC_F, KC_NO)) {
        register_code(KC_LGUI);
        register_code(KC_LALT);
        register_code(KC_LCTL);
        register_code(KC_F);
        unregister_code(KC_F);
        unregister_code(KC_LCTL);
        unregister_code(KC_LALT);
        unregister_code(KC_LGUI);
    }
    if (leader_sequence_three_keys(KC_C, KC_P, KC_NO)) {
        register_code(KC_LGUI);
        register_code(KC_LALT);
        register_code(KC_LCTL);
        register_code(KC_P);
        unregister_code(KC_P);
        unregister_code(KC_LCTL);
        unregister_code(KC_LALT);
        unregister_code(KC_LGUI);
    }
    if (leader_sequence_three_keys(KC_C, KC_O, KC_NO)) {
        register_code(KC_LGUI);
        register_code(KC_LALT);
        register_code(KC_LCTL);
        register_code(KC_O);
        unregister_code(KC_O);
        unregister_code(KC_LCTL);
        unregister_code(KC_LALT);
        unregister_code(KC_LGUI);
    }
    if (leader_sequence_three_keys(KC_C, KC_J, KC_NO)) {
        register_code(KC_LGUI);
        register_code(KC_LALT);
        register_code(KC_LCTL);
        register_code(KC_J);
        unregister_code(KC_J);
        unregister_code(KC_LCTL);
        unregister_code(KC_LALT);
        unregister_code(KC_LGUI);
    }
    if (leader_sequence_three_keys(KC_C, KC_S, KC_NO)) {
        register_code(KC_LGUI);
        register_code(KC_LALT);
        register_code(KC_LCTL);
        register_code(KC_S);
        unregister_code(KC_S);
        unregister_code(KC_LCTL);
        unregister_code(KC_LALT);
        unregister_code(KC_LGUI);
    }
    if (leader_sequence_three_keys(KC_C, KC_W, KC_NO)) {
        register_code(KC_LGUI);
        register_code(KC_LALT);
        register_code(KC_LCTL);
        register_code(KC_W);
        unregister_code(KC_W);
        unregister_code(KC_LCTL);
        unregister_code(KC_LALT);
        unregister_code(KC_LGUI);
    }
    if (leader_sequence_three_keys(KC_C, KC_N, KC_NO)) {
        register_code(KC_LGUI);
        register_code(KC_LALT);
        register_code(KC_LCTL);
        register_code(KC_N);
        unregister_code(KC_N);
        unregister_code(KC_LCTL);
        unregister_code(KC_LALT);
        unregister_code(KC_LGUI);
    }
}
