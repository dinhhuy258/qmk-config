#include "led_indicators.h"

#if defined(KEYBOARD_ergodox_ez)
#    include "ergodox_ez.h"
#    include "../definitions/layers.h"

void update_led_indicators(layer_state_t state) {
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
}
#endif
