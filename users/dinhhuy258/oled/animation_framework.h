#pragma once

#include QMK_KEYBOARD_H

typedef struct {
    uint8_t  frame_count;
    uint16_t frame_duration_ms;
    uint8_t  current_frame;
    uint32_t anim_timer;
} oled_animation_state_t;

// Initialize animation state
void oled_animation_init(oled_animation_state_t *state, uint8_t frame_count, uint16_t frame_duration_ms);

// Update animation frame and return current frame index
uint8_t oled_animation_update(oled_animation_state_t *state);
