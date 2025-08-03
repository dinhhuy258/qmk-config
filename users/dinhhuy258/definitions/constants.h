#pragma once

// Animation timing constants
#define BONGOCAT_ANIM_FRAMES 2
#define BONGOCAT_ANIM_FRAME_DURATION 200 // ms
#define BONGOCAT_ANIM_SIZE 636           // bytes

#define LUNA_ANIM_FRAMES 2
#define LUNA_ANIM_FRAME_DURATION 200 // ms
#define LUNA_ANIM_SIZE 96            // bytes
#define LUNA_RUN_TO_SIT_IDLE_TIME_MS 1000

// Tap dance timing
#define TD_SWITCH_APP_TAPPING_TERM_OFFSET 50

// Mouse jiggler constants
#define JIGGLER_CALLBACK_INTERVAL_MS 16
#define JIGGLER_CIRCLE_RADIUS_FRAMES 32

// Combo timing
#define COMBO_TERM_MS 50

// Mouse speed settings
#define MOUSE_CURSOR_OFFSET_SLOW 6
#define MOUSE_CURSOR_INTERVAL_SLOW 16
#define MOUSE_CURSOR_OFFSET_MEDIUM 24
#define MOUSE_CURSOR_INTERVAL_MEDIUM 16
#define MOUSE_CURSOR_OFFSET_FAST 42
#define MOUSE_CURSOR_INTERVAL_FAST 16

// Default tapping term
#ifndef CUSTOM_TAPPING_TERM
#    define DEFAULT_TAPPING_TERM 200
#else
#    define DEFAULT_TAPPING_TERM CUSTOM_TAPPING_TERM
#endif
