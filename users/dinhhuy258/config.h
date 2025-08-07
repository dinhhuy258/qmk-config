#pragma once

#include "definitions/constants.h"

// The combos' keys are always checked from layer BASE, even if other layers are active.
// https://docs.qmk.fm/features/combo#layer-independent-combos
#define COMBO_ONLY_FROM_LAYER 0
#define COMBO_TERM COMBO_TERM_MS
// https://docs.qmk.fm/features/combo#generic-hook-to-dis-allow-a-combo-activation
#define COMBO_SHOULD_TRIGGER

#define MK_3_SPEED
#define MK_MOMENTARY_ACCEL
#define MK_C_OFFSET_0 MOUSE_CURSOR_OFFSET_SLOW
#define MK_C_INTERVAL_0 MOUSE_CURSOR_INTERVAL_SLOW
#define MK_C_OFFSET_1 MOUSE_CURSOR_OFFSET_MEDIUM
#define MK_C_INTERVAL_1 MOUSE_CURSOR_INTERVAL_MEDIUM
#define MK_C_OFFSET_2 MOUSE_CURSOR_OFFSET_FAST
#define MK_C_INTERVAL_2 MOUSE_CURSOR_INTERVAL_FAST

#define TAPPING_TERM DEFAULT_TAPPING_TERM
#define TAPPING_TERM_PER_KEY

#define LEADER_PER_KEY_TIMING
#define LEADER_TIMEOUT 250
