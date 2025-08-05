#include "dinhhuy258.h"
#include "definitions/layers.h"
#include "definitions/keycodes.h"
#include "definitions/constants.h"
#include "definitions/keyboard_config.h"
#include "features/swapper.h"
#include "features/led_indicators.h"
#include "features/secrets.h"

bool switch_app_active = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_secret_triggers(keycode, record)) {
        return false;
    }

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
                static const int8_t deltas[JIGGLER_CIRCLE_RADIUS_FRAMES] = {0, -1, -2, -2, -3, -3, -4, -4, -4, -4, -3, -3, -2, -2, -1, 0, 0, 1, 2, 2, 3, 3, 4, 4, 4, 4, 3, 3, 2, 2, 1, 0};
                static uint8_t      phase                                = 0;
                // Get x delta from table and y delta by rotating a quarter cycle.
                report.x = deltas[phase];
                report.y = deltas[(phase + 8) & (JIGGLER_CIRCLE_RADIUS_FRAMES - 1)];
                phase    = (phase + 1) & (JIGGLER_CIRCLE_RADIUS_FRAMES - 1);
                host_mouse_send(&report);
                return JIGGLER_CALLBACK_INTERVAL_MS;
            }

            token = defer_exec(1, jiggler_callback, NULL); // Schedule callback.
        }
    }

    const user_keyboard_config_t *config = get_keyboard_config();
    process_swapper(&switch_app_active, KC_LGUI, KC_TAB, SWITCH_APP, (keypos_t *)config->switch_app_ignore_positions, config->switch_app_ignore_positions_size, keycode, record);

    return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    state = update_tri_layer_state(state, NAV, SYM, WM);

#if defined(KEYBOARD_ergodox_ez)
    update_led_indicators(state);
#endif

    return state;
}
