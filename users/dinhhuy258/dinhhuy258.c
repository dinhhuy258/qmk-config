#include "dinhhuy258.h"
#include "swapper.h"

bool     switch_app_active                 = false;
keypos_t switch_app_ignore_key_positions[] = {
#if defined(KEYBOARD_crkbd)
    {.col = 1, .row = 4},
#elif defined(KEYBOARD_ergodox_ez)
    {.col = 1, .row = 12},
#endif
};
uint8_t switch_app_ignore_key_positions_size = ARRAY_SIZE(switch_app_ignore_key_positions);

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        static deferred_token token  = INVALID_DEFERRED_TOKEN;
        static report_mouse_t report = {0};
        if (token) {
            // If jiggler is currently running, stop when any key is pressed.
            cancel_deferred_exec(token);
            token  = INVALID_DEFERRED_TOKEN;
            report = (report_mouse_t){}; // Clear the mouse.
            host_mouse_send(&report);
        } else if (keycode == JIGGLE) {
            uint32_t jiggler_callback(uint32_t trigger_time, void *cb_arg) {
                // Deltas to move in a circle of radius 20 pixels over 32 frames.
                static const int8_t deltas[32] = {0, -1, -2, -2, -3, -3, -4, -4, -4, -4, -3, -3, -2, -2, -1, 0, 0, 1, 2, 2, 3, 3, 4, 4, 4, 4, 3, 3, 2, 2, 1, 0};
                static uint8_t      phase      = 0;
                // Get x delta from table and y delta by rotating a quarter cycle.
                report.x = deltas[phase];
                report.y = deltas[(phase + 8) & 31];
                phase    = (phase + 1) & 31;
                host_mouse_send(&report);
                return 16; // Call the callback every 16 ms.
            }

            token = defer_exec(1, jiggler_callback, NULL); // Schedule callback.
        }
    }

    update_swapper(&switch_app_active, KC_LGUI, KC_TAB, SWITCH_APP, switch_app_ignore_key_positions, switch_app_ignore_key_positions_size, keycode, record);

    return true;
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case TD(TD_SWITCH_APP):
            return TAPPING_TERM + 50;
        default:
            return TAPPING_TERM;
    }
}

layer_state_t layer_state_set_user(layer_state_t state) {
    state = update_tri_layer_state(state, NAV, SYM, WM);

#if defined(KEYBOARD_ergodox_ez)
    uint8_t layer = biton(state);
    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
        case NAV:
            ergodox_right_led_1_on();
            break;
        case SYM:
            ergodox_right_led_2_on();
            break;
        case NUM:
            ergodox_right_led_3_on();
            break;
        case MOU:
            ergodox_right_led_1_on();
            ergodox_right_led_2_on();
            break;
        case WM:
            ergodox_right_led_1_on();
            ergodox_right_led_3_on();
            break;
        default:
            break;
    }
#endif

    return state;
}

/**********************************************************************
 * Combos Configuration
 **********************************************************************/

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

// clang-format off
combo_t key_combos[] = {
    [VIM_QUIT] = COMBO_ACTION(vim_quit_combo),
    [INPUT_SOURCE] = COMBO_ACTION(input_source_combo),
    [CAPS_WORD] = COMBO_ACTION(caps_word_combo),
    [VIM_QUIT] = COMBO_ACTION(vim_quit_combo),
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
    }
}

/**********************************************************************
 * Tap Dance Configuration
 **********************************************************************/

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

tap_dance_action_t tap_dance_actions[] = {
    [TD_SWITCH_APP] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_switch_app_finished, NULL),
    [TD_RESET]      = ACTION_TAP_DANCE_FN(td_safe_reset),
};
