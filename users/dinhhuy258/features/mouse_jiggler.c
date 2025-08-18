// Reference: https://getreuer.info/posts/keyboards/macros3/index.html#a-mouse-jiggler
#include "mouse_jiggler.h"
#include "definitions/keycodes.h"
#include "definitions/constants.h"

static deferred_token jiggler_token = INVALID_DEFERRED_TOKEN;
static report_mouse_t jiggler_report = {0};

static uint32_t jiggler_callback(uint32_t trigger_time, void *cb_arg) {
    // Deltas to move in a circle of radius 20 pixels over 32 frames.
    static const int8_t deltas[JIGGLER_CIRCLE_RADIUS_FRAMES] = {0, -1, -2, -2, -3, -3, -4, -4, -4, -4, -3, -3, -2, -2, -1, 0, 0, 1, 2, 2, 3, 3, 4, 4, 4, 4, 3, 3, 2, 2, 1, 0};
    static uint8_t phase = 0;

    // Get x delta from table and y delta by rotating a quarter cycle.
    jiggler_report.x = deltas[phase];
    jiggler_report.y = deltas[(phase + 8) & (JIGGLER_CIRCLE_RADIUS_FRAMES - 1)];
    phase = (phase + 1) & (JIGGLER_CIRCLE_RADIUS_FRAMES - 1);
    host_mouse_send(&jiggler_report);

    return JIGGLER_CALLBACK_INTERVAL_MS;
}

void process_mouse_jiggler(uint16_t keycode, keyrecord_t *record) {
    if (!record->event.pressed) {
        return;
    }

    if (jiggler_token) {
        // If jiggler is currently running, stop when any key is pressed.
        cancel_deferred_exec(jiggler_token);
        jiggler_token = INVALID_DEFERRED_TOKEN;
        jiggler_report = (report_mouse_t){}; // Clear the mouse.
        host_mouse_send(&jiggler_report);
    } else if (keycode == JIGGLE) {
        jiggler_token = defer_exec(1, jiggler_callback, NULL); // Schedule callback.
    }
}
