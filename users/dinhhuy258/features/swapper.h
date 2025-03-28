#pragma once

#include QMK_KEYBOARD_H

#include "../definitions/process_record.h"

// Implements cmd-tab like behaviour on a single key. On first tap of trigger
// cmdish is held and tabish is tapped -- cmdish then remains held until some
// other key is hit or released. For example:
//
//     trigger, trigger, a -> cmd down, tab, tab, cmd up, a
//     nav down, trigger, nav up -> nav down, cmd down, tab, cmd up, nav up
//
// This behaviour is useful for more than just cmd-tab, hence: cmdish, tabish.
process_record_result_t process_swapper(bool *active, uint16_t cmdish, uint16_t tabish, uint16_t trigger, keypos_t ignored_key_positions[], uint8_t ignored_key_positions_size, uint16_t keycode, keyrecord_t *record);
