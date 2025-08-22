#pragma once

#include QMK_KEYBOARD_H

#include "keycodes.h"
#include "layers.h"

// clang-format off
#define __________________BASE_L1__________________       KC_Q,            KC_W,            KC_E,            KC_R,            KC_T
#define __________________BASE_L2__________________       LGUI_T(KC_A),    LOPT_T(KC_S),    LCTL_T(KC_D),    LSFT_T(KC_F),    KC_G
#define __________________BASE_L3__________________       KC_Z,            KC_X,            KC_C,            KC_V,            KC_B
#define ______________BASE_THUMB_LEFT______________       LT(NAV, KC_ESC), LT(MOU, KC_SPC)

#define __________________BASE_R1__________________       KC_Y,            KC_U,            KC_I,            KC_O,            KC_P
#define __________________BASE_R2__________________       KC_H,            LSFT_T(KC_J),    LCTL_T(KC_K),    LALT_T(KC_L),    LGUI_T(KC_SCLN)
#define __________________BASE_R3__________________       KC_N,            KC_M,            KC_COMM,         KC_DOT,          KC_SLSH
#define ______________BASE_THUMB_RIGHT_____________       LT(SHORTCUT, KC_ENT), LT(SYM, KC_NO)

#define ___________________NAV_L1__________________       KC_BRID,         KC_BRIU,         SCREENSHOT,      ZOOM_OUT,        ZOOM_IN
#define ___________________NAV_L2__________________       KC_LGUI,         KC_LOPT,         KC_LCTL,         KC_LSFT,         KC_F12
#define ___________________NAV_L3__________________       KC_VOLD,         KC_VOLU,         KC_MUTE,         ZOOM_RESET,      XXXXXXX
#define ______________NAV_THUMB_LEFT_______________       _______,         _______

#define ___________________NAV_R1__________________       XXXXXXX,         XXXXXXX,         XXXXXXX,         XXXXXXX,         TD(TD_SWITCH_APP)
#define ___________________NAV_R2__________________       KC_LEFT,         KC_DOWN,         KC_UP,           KC_RGHT,         SWITCH_APP
#define ___________________NAV_R3__________________       NAV_LEFT,        VIM_LEFT,        VIM_RIGHT,       NAV_RIGHT,       LGUI(KC_GRAVE)
#define ______________NAV_THUMB_RIGHT______________       _______,         _______

#define ___________________MOU_L1__________________       XXXXXXX,         XXXXXXX,         MOU_MIN_SPEED,   MOU_MAX_SPEED,   XXXXXXX
#define ___________________MOU_L2__________________       KC_LGUI,         KC_LOPT,         KC_LCTL,         KC_LSFT,         XXXXXXX
#define ___________________MOU_L3__________________       XXXXXXX,         XXXXXXX,         XXXXXXX,         XXXXXXX,         JIGGLE
#define ______________MOU_THUMB_LEFT_______________       _______,         _______

#define ___________________MOU_R1__________________       XXXXXXX,         MOUSE_HINT_CLK, MOUSE_HINT_MOVE,  MOUSE_HINT_SCRN, TD(TD_SWITCH_APP)
#define ___________________MOU_R2__________________       MOUSE_LEFT,      MOUSE_DOWN,      MOUSE_UP,        MOUSE_RIGHT,     SWITCH_APP
#define ___________________MOU_R3__________________       WHEEL_LEFT,      WHEEL_DOWN,      WHEEL_UP,        WHEEL_RIGHT,     LGUI(KC_GRAVE)
#define ______________MOU_THUMB_RIGHT______________       LEFT_CLICK,      RIGHT_CLICK

#define ___________________SYM_L1__________________       KC_AMPR,         KC_7,            KC_8,            KC_9,            KC_GRV
#define ___________________SYM_L2__________________       KC_DLR,          KC_4,            KC_5,            LSFT_T(KC_6),    KC_TILD
#define ___________________SYM_L3__________________       KC_0,            KC_1,            KC_2,            KC_3,            XXXXXXX
#define ______________SYM_THUMB_LEFT_______________       _______,         _______

#define ___________________SYM_R1__________________       KC_AT,           KC_ASTR,         KC_HASH,         KC_PERC,         KC_COLON
#define ___________________SYM_R2__________________       KC_EXLM,         LSFT_T(KC_EQL),  KC_MINS,         KC_BSLS,         KC_SCLN
#define ___________________SYM_R3__________________       KC_QUOT,         KC_DQUO,         KC_COMM,         KC_DOT,          KC_SLSH
#define ______________SYM_THUMB_RIGHT______________       _______,         _______

#define ___________________WM_L1___________________       WM_WS_1,         WM_WS_2,         WM_WS_3,         WM_WS_4,         WM_WS_5
#define ___________________WM_L2___________________       WM_FULLSCREEN,   WM_MODE_RESIZE,  WM_MODE_MOVE,    WM_L_TILES,      WM_L_ACCORDION
#define ___________________WM_L3___________________       WM_MODE_JOIN,    XXXXXXX,         WM_CLOSE,        RECT_SMALLER,    RECT_LARGER
#define ______________WM_THUMB_LEFT________________       _______,         TD(TD_RESET)

#define ___________________WM_R1___________________       WM_MOVE_WS_1,    WM_MOVE_WS_2,    WM_MOVE_WS_3,    WM_MOVE_WS_4,    WM_MOVE_WS_5
#define ___________________WM_R2___________________       WM_FOCUS_LEFT,   WM_FOCUS_DOWN,   WM_FOCUS_UP,     WM_FOCUS_RIGHT,  WM_TOGGLE_FT
#define ___________________WM_R3___________________       RECT_CENTER,     WM_MOVE_MONITOR, XXXXXXX,         XXXXXXX,         XXXXXXX
#ifdef GAME_LAYER_ENABLE
#define ______________WM_THUMB_RIGHT_______________       TO(GAME),        _______
#else
#define ______________WM_THUMB_RIGHT_______________       _______,         _______
#endif

#define ________________SHORTCUT_L1________________       HYPR(KC_Q),      HYPR(KC_W),      HYPR(KC_E),      HYPR(KC_R),      XXXXXXX
#define ________________SHORTCUT_L2________________       HYPR(KC_A),      HYPR(KC_S),      HYPR(KC_D),      HYPR(KC_F),      HYPR(KC_G)
#define ________________SHORTCUT_L3________________       HYPR(KC_Z),      XXXXXXX,         XXXXXXX,         XXXXXXX,         XXXXXXX
#define ____________SHORTCUT_THUMB_LEFT____________       _______,         _______

#define ________________SHORTCUT_R1________________       XXXXXXX,         XXXXXXX,         XXXXXXX,         XXXXXXX,         XXXXXXX
#define ________________SHORTCUT_R2________________       XXXXXXX,         XXXXXXX,         XXXXXXX,         XXXXXXX,         XXXXXXX
#define ________________SHORTCUT_R3________________       XXXXXXX,         XXXXXXX,         XXXXXXX,         XXXXXXX,         XXXXXXX
#define ____________SHORTCUT_THUMB_RIGHT___________       _______,         _______

#ifdef GAME_LAYER_ENABLE
#define ___________________GAME_L1_________________       KC_Q,            KC_W,            KC_E,            KC_R,            KC_T
#define ___________________GAME_L2_________________       KC_A,            KC_S,            KC_D,            KC_F,            KC_G
#define ___________________GAME_L3_________________       KC_Z,            KC_X,            KC_C,            KC_V,            KC_B
#define ______________GAME_THUMB_LEFT______________       KC_ESC,          KC_SPC

#define ___________________GAME_R1_________________       KC_Y,            KC_U,            KC_I,            KC_O,            KC_P
#define ___________________GAME_R2_________________       KC_H,            KC_J,            KC_K,            KC_L,            KC_SCLN
#define ___________________GAME_R3_________________       KC_N,            KC_M,            KC_COMM,         KC_DOT,          KC_SLSH
#define ______________GAME_THUMB_RIGHT_____________       KC_ENT,          TO(BASE)
#endif
