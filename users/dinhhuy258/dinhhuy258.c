#include "dinhhuy258.h"
#include "features/swapper.h"

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
