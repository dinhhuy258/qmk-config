#include "custom_shift_keys.h"

typedef struct {
    uint16_t keycode;
    uint16_t shifted_keycode;
} custom_shift_key_t;

custom_shift_key_t custom_shift_keys[] = {
    {KC_8, KC_LCBR},         // shift 8 = {
    {KC_5, KC_LPRN},         // shift 5 = (
    {KC_2, KC_LBRC},         // shift 2 = [
    {KC_9, KC_RCBR},         // shift 9 = }
    {LSFT_T(KC_6), KC_RPRN}, // shift 6 = )
    {KC_3, KC_RBRC},         // shift 3 = ]
    {KC_DLR, KC_CIRC},       // shift $ = ^
};

bool process_custom_shift_keys(uint16_t keycode, keyrecord_t *record) {
    static uint16_t registered_keycode = KC_NO;

    // If a custom shift key is registered, then this event is either releasing
    // it or manipulating another key at the same time. Either way, we release
    // the currently registered key.
    if (registered_keycode != KC_NO) {
        unregister_code16(registered_keycode);
        registered_keycode = KC_NO;
    }

    if (record->event.pressed) { // Press event.
        const uint8_t saved_mods = get_mods();
        const uint8_t mods       = saved_mods | get_weak_mods() | get_oneshot_mods();
        if ((mods & MOD_MASK_SHIFT) != 0) { // // Shift is held.
            // Continue default handling if this is a tap-hold key being held.
            if ((IS_QK_MOD_TAP(keycode) || IS_QK_LAYER_TAP(keycode)) && record->tap.count == 0) {
                return true;
            }

            for (int i = 0; i < sizeof(custom_shift_keys) / sizeof(custom_shift_key_t); i++) {
                if (keycode == custom_shift_keys[i].keycode) {
                    registered_keycode = custom_shift_keys[i].shifted_keycode;
                    if (IS_QK_MODS(registered_keycode) && // Should keycode be shifted?
                        (QK_MODS_GET_MODS(registered_keycode) & MOD_LSFT) != 0) {
                        register_code16(registered_keycode); // If so, press it directly.
                    } else {
                        // Otherwise cancel shift mods, press the key, and restore mods.
                        del_weak_mods(MOD_MASK_SHIFT);
                        del_oneshot_mods(MOD_MASK_SHIFT);
                        unregister_mods(MOD_MASK_SHIFT);
                        register_code16(registered_keycode);
                        set_mods(saved_mods);
                    }

                    return false;
                }
            }
        }
    }

    return true; // Continue with default handling.
}
