#include "dinhhuy258.h"
#include "bongocat.h"

void oled_render_master(void) {
    render_bongocat();
}

void oled_render_slave(void) {
    render_bongocat();
}

bool oled_task_user(void) {
#if OLED_TIMEOUT > 0
    // The animation prevents the normal timeout from occuring
    if (last_input_activity_elapsed() > OLED_TIMEOUT && last_led_activity_elapsed() > OLED_TIMEOUT) {
        oled_off();

        return false;
    } else {
        oled_on();
    }
#endif
    if (is_keyboard_master()) {
        oled_render_master();
    } else {
        oled_render_slave();
    }

    return false;
}
