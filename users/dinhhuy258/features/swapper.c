#include "swapper.h"

void update_swapper(bool *active, uint16_t cmdish, uint16_t tabish, uint16_t trigger, keypos_t ignored_key_positions[], uint8_t ignored_key_positions_size, uint16_t keycode, keyrecord_t *record) {
    if (keycode == trigger) {
        if (record->event.pressed) {
            if (!*active) {
                *active = true;
                register_code(cmdish);
            }
            register_code(tabish);
        } else {
            unregister_code(tabish);
            // Don't unregister cmdish until some other key is hit or released.
        }

        return;
    }

    if (*active) {
        // Check if the key is in the ignored key positions.
        for (uint8_t i = 0; i < ignored_key_positions_size; ++i) {
            if (record->event.key.row == ignored_key_positions[i].row && record->event.key.col == ignored_key_positions[i].col) {
                return;
            }
        }

        unregister_code(cmdish);
        *active = false;
    }
}
