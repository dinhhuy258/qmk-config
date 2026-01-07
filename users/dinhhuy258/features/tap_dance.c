void td_safe_reset(tap_dance_state_t *state, void *user_data) {
    if (state->count >= 3) {
        // Reset the keyboard if you tap the key more than three times
        reset_keyboard();
        reset_tap_dance(state);
    }
}

void td_switch_app_finished(tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        tap_code16(LGUI(KC_TAB));
    } else {
        tap_code16(LSG(KC_TAB));
    }
}

void td_snip_finished(tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        tap_code16(SNIP);       // Single tap: SNIP
    } else {
        tap_code16(SNIP_COPY);  // Double tap: SNIP_COPY
    }
}

tap_dance_action_t tap_dance_actions[] = {
    [TD_SWITCH_APP] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_switch_app_finished, NULL),
    [TD_RESET]      = ACTION_TAP_DANCE_FN(td_safe_reset),
    [TD_SNIP]       = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_snip_finished, NULL),
};
