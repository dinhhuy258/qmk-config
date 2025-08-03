enum combos {
    VIM_QUIT,
    INPUT_SOURCE,
    CAPS_WORD,
    TAB,
    BACKSPACE,
    CUT,
    COPY,
    PASTE,
    UNDO,
    PLUS,
    MINUS,
    ASTERISK,
    SLASH,
    LEFT_PAREN,
    RIGHT_PAREN,
#ifndef NO_SECRETS
    SECRET_TRIGGER_COMBO,
#endif
};

/*
  ╭──────────────────────────┬──────────────────────────────────╮
  │ KC_Q KC_W KC_E KC_R KC_T │ KC_Y KC_U KC_I    KC_O   KC_P    │
  │ KC_A KC_S KC_D KC_F KC_G │ KC_H KC_J KC_K    KC_L   KC_SCLN │
  │ KC_Z KC_X KC_C KC_V KC_B │ KC_N KC_M KC_COMM KC_DOT KC_SLSH │
  ╰──────────────╮ ____ ____ │ ____ ____ ╭──────────────────────╯
                 ╰───────────┴───────────╯
*/
const uint16_t PROGMEM vim_quit_combo[]     = {KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM input_source_combo[] = {KC_Z, KC_SLSH, COMBO_END};
const uint16_t PROGMEM caps_word_combo[]    = {LGUI_T(KC_A), LGUI_T(KC_SCLN), COMBO_END};
const uint16_t PROGMEM tab_combo[]          = {LOPT_T(KC_S), LCTL_T(KC_D), COMBO_END};
const uint16_t PROGMEM backspace_combo[]    = {LCTL_T(KC_K), LALT_T(KC_L), COMBO_END};
const uint16_t PROGMEM cut_combo[]          = {KC_X, KC_V, COMBO_END};
const uint16_t PROGMEM copy_combo[]         = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM paste_combo[]        = {KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM undo_combo[]         = {KC_Z, KC_X, COMBO_END};
const uint16_t PROGMEM plus_combo[]         = {KC_R, KC_T, COMBO_END};
const uint16_t PROGMEM minus_combo[]        = {KC_Y, KC_U, COMBO_END};
const uint16_t PROGMEM asterisk_combo[]     = {KC_V, KC_B, COMBO_END};
const uint16_t PROGMEM slash_combo[]        = {KC_N, KC_M, COMBO_END};
const uint16_t PROGMEM left_paren_combo[]   = {LSFT_T(KC_F), HYPR_T(KC_G), COMBO_END};
const uint16_t PROGMEM right_paren_combo[]  = {HYPR_T(KC_H), LSFT_T(KC_J), COMBO_END};
#ifndef NO_SECRETS
const uint16_t PROGMEM secret_trigger_combo[] = {HYPR_T(KC_G), HYPR_T(KC_H), COMBO_END};
#endif

// clang-format off
combo_t key_combos[] = {
    [VIM_QUIT] = COMBO_ACTION(vim_quit_combo),
    [INPUT_SOURCE] = COMBO_ACTION(input_source_combo),
    [CAPS_WORD] = COMBO_ACTION(caps_word_combo),
    [TAB] = COMBO(tab_combo, KC_TAB),
    [BACKSPACE] = COMBO(backspace_combo, KC_BSPC),
    [CUT] = COMBO_ACTION(cut_combo),
    [COPY] = COMBO_ACTION(copy_combo),
    [PASTE] = COMBO_ACTION(paste_combo),
    [UNDO] = COMBO_ACTION(undo_combo),
    [PLUS] = COMBO_ACTION(plus_combo),
    [MINUS] = COMBO_ACTION(minus_combo),
    [ASTERISK] = COMBO_ACTION(asterisk_combo),
    [SLASH] = COMBO_ACTION(slash_combo),
    [LEFT_PAREN] = COMBO_ACTION(left_paren_combo),
    [RIGHT_PAREN] = COMBO_ACTION(right_paren_combo),
#ifndef NO_SECRETS
    [SECRET_TRIGGER_COMBO] = COMBO_ACTION(secret_trigger_combo),
#endif
};
// clang-format on

bool combo_should_trigger(uint16_t combo_index, combo_t *combo, uint16_t keycode, keyrecord_t *record) {
    switch (combo_index) {
        case VIM_QUIT:
        case INPUT_SOURCE:
        case CAPS_WORD:
        case TAB:
            return layer_state_is(BASE);
        case PLUS:
        case MINUS:
        case ASTERISK:
        case SLASH:
        case LEFT_PAREN:
        case RIGHT_PAREN:
            return layer_state_is(NUM);
        case BACKSPACE:
            return layer_state_is(BASE) || layer_state_is(NUM) || layer_state_is(SYM);
#ifndef NO_SECRETS
        case SECRET_TRIGGER_COMBO:
            return layer_state_is(WM); // Only trigger in WM layer
#endif
    }

    return true;
}

void process_combo_event(uint16_t combo_index, bool pressed) {
    switch (combo_index) {
        case VIM_QUIT:
            if (pressed) {
                SEND_STRING(":q!");
            }
            break;
        case INPUT_SOURCE:
            if (pressed) {
                tap_code16(HYPR(KC_TAB));
            }
            break;
        case CAPS_WORD:
            if (pressed) {
                caps_word_on();
            }
            break;
        case TAB:
            if (pressed) {
                tap_code(KC_TAB);
            }
            break;
        case BACKSPACE:
            if (pressed) {
                tap_code(KC_BSPC);
            }
            break;
        case CUT:
            if (pressed) {
                tap_code16(LGUI(KC_X));
            }
            break;
        case COPY:
            if (pressed) {
                tap_code16(LGUI(KC_C));
            }
            break;
        case PASTE:
            if (pressed) {
                tap_code16(LGUI(KC_V));
            }
            break;
        case UNDO:
            if (pressed) {
                tap_code16(LGUI(KC_Z));
            }
            break;
        case PLUS:
            if (pressed) {
                tap_code16(LSFT(KC_EQUAL));
            }
            break;
        case MINUS:
            if (pressed) {
                tap_code(KC_MINUS);
            }
            break;
        case ASTERISK:
            if (pressed) {
                tap_code16(LSFT(KC_8));
            }
            break;
        case SLASH:
            if (pressed) {
                tap_code(KC_SLSH);
            }
            break;
        case LEFT_PAREN:
            if (pressed) {
                tap_code16(LSFT(KC_9));
            }
            break;
        case RIGHT_PAREN:
            if (pressed) {
                tap_code16(LSFT(KC_0));
            }
            break;
#ifndef NO_SECRETS
        case SECRET_TRIGGER_COMBO:
            if (pressed) {
                // This will trigger the sequence mode in secret_triggers.c
                extern void secret_combo_triggered(void);
                secret_combo_triggered();
            }
            break;
#endif
    }
}
