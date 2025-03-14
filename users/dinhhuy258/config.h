#pragma once

// The combos' keys are always checked from layer BASE, even if other layers are active.
// https://docs.qmk.fm/features/combo#layer-independent-combos
#define COMBO_ONLY_FROM_LAYER 0
#define COMBO_TERM 50
// https://docs.qmk.fm/features/combo#generic-hook-to-dis-allow-a-combo-activation
#define COMBO_SHOULD_TRIGGER

#define MK_3_SPEED
#define MK_MOMENTARY_ACCEL
#define MK_C_OFFSET_0 6
#define MK_C_INTERVAL_0 16
#define MK_C_OFFSET_1 24
#define MK_C_INTERVAL_1 16
#define MK_C_OFFSET_2 42
#define MK_C_INTERVAL_2 16

#define TAPPING_TERM 200
