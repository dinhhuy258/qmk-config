#include "animation_framework.h"

void oled_animation_init(oled_animation_state_t *state, uint8_t frame_count, uint16_t frame_duration_ms) {
    state->frame_count       = frame_count;
    state->frame_duration_ms = frame_duration_ms;
    state->current_frame     = 0;
    state->anim_timer        = timer_read32();
}

uint8_t oled_animation_update(oled_animation_state_t *state) {
    if (timer_elapsed32(state->anim_timer) > state->frame_duration_ms) {
        state->anim_timer    = timer_read32();
        state->current_frame = (state->current_frame + 1) % state->frame_count;
    }
    return state->current_frame;
}
