#include "dinhhuy258.h"
#include "definitions/layers.h"
#include "definitions/keycodes.h"
#include "definitions/constants.h"
#include "definitions/keyboard_config.h"
#include "features/swapper.h"
#include "features/led_indicators.h"
#include "features/leader.h"
#include "features/custom_shift_keys.h"
#include "features/mouse_jiggler.h"

bool switch_app_active = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_leader_key(keycode, record)) {
        return false;
    }

    if (!process_custom_shift_keys(keycode, record)) {
        return false;
    }

    process_mouse_jiggler(keycode, record);

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
