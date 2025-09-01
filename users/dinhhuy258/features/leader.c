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

static void send_tmux_key(uint16_t key) {
    register_code(KC_LCTL);
    register_code(KC_F);
    unregister_code(KC_F);
    unregister_code(KC_LCTL);
    if (key == KC_NO) {
        return;
    }
    wait_ms(10);
    register_code(key);
    unregister_code(key);
}

bool process_leader_command_keys(void) {
    static const uint16_t cmd_alt_ctrl_keys[] = {
        KC_J, // bw_get_password
        KC_K, // bw_get_totp
        KC_F, // fcmd ~/.cmds
        KC_D, // fm
        KC_S, // sgg (Search Google)
        KC_W, // aow (Open AWS Console in Firefox browser)
        KC_A, // index.norg (Notes)
        KC_Q, // k9s
    };
    for (int i = 0; i < sizeof(cmd_alt_ctrl_keys) / sizeof(cmd_alt_ctrl_keys[0]); i++) {
        if (leader_sequence_two_keys(KC_J, cmd_alt_ctrl_keys[i])) {
            send_cmd_alt_ctrl_key(cmd_alt_ctrl_keys[i]);

            return true;
        }
    }

    return false;
}

void process_leader_tmux_keys(void) {
    // Navi cheatsheet
    if (leader_sequence_three_keys(KC_F, KC_A, KC_NO)) {
        register_code(KC_LCTL);
        register_code(KC_F);
        unregister_code(KC_F);
        unregister_code(KC_LCTL);
        wait_ms(10);
        register_code(KC_LCTL);
        register_code(KC_G);
        unregister_code(KC_G);
        unregister_code(KC_LCTL);

        return;
    }

    static const struct {
        uint16_t second_key;
        uint16_t target_key;
    } tmux_keys[] = {
        {KC_F, KC_NO}, // Tmux prefix
        {KC_R, KC_R},  // Reload config
        {KC_W, KC_W},  // Delete panel
        {KC_T, KC_T},  // New panel
        {KC_G, KC_G},  // Vertical split
        {KC_V, KC_V},  // Horizontal split
        {KC_J, KC_J},  // Enter copy mode
        {KC_K, KC_K},  // tmux-jump
        {KC_L, KC_L},  // tmux-urlview
        {KC_D, KC_D},  // Swap panel -D
        {KC_S, KC_S},  // Swap panel -U
        {KC_Z, KC_Z},  // Swap to previous window
        {KC_B, KC_B},  // Swap to next window
        {KC_U, KC_U},  // Save session
        {KC_P, KC_P},  // Load session
    }; // Swap panel -U

    for (int i = 0; i < sizeof(tmux_keys) / sizeof(tmux_keys[0]); i++) {
        if (leader_sequence_three_keys(KC_F, tmux_keys[i].second_key, KC_NO)) {
            send_tmux_key(tmux_keys[i].target_key);

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

    if (process_leader_command_keys()) {
        return; // If a command key was processed, do not process further tmux keys
    }

    process_leader_tmux_keys();
}
