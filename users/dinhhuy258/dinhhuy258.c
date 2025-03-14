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
    update_swapper(&switch_app_active, KC_LGUI, KC_TAB, SWITCH_APP, switch_app_ignore_key_positions, switch_app_ignore_key_positions_size, keycode, record);

    return true;
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
