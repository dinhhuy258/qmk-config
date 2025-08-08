#include "leader.h"
#include "definitions/keycodes.h"
#include "definitions/layers.h"
#include "features/secrets.h"

static void send_cmd_alt_ctrl_key(uint16_t key) {
    register_code(KC_LGUI);
    register_code(KC_LALT);
    register_code(KC_LCTL);
    register_code(key);
    unregister_code(key);
    unregister_code(KC_LCTL);
    unregister_code(KC_LALT);
    unregister_code(KC_LGUI);
}

void process_leader_command_keys(void) {
    static const uint16_t cmd_alt_ctrl_keys[] = {KC_R, KC_F, KC_P, KC_O, KC_J, KC_S, KC_W, KC_N};
    for (int i = 0; i < sizeof(cmd_alt_ctrl_keys) / sizeof(cmd_alt_ctrl_keys[0]); i++) {
        if (leader_sequence_two_keys(KC_C, cmd_alt_ctrl_keys[i])) {
            send_cmd_alt_ctrl_key(cmd_alt_ctrl_keys[i]);

            return;
        }
    }
}

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
    if (process_secrets()) {
        return; // If a secret was processed, do not process further leader commands
    }

    process_leader_command_keys();
}
