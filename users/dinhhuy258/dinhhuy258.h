#pragma once

#include QMK_KEYBOARD_H

#define TMUX_PREFIX LCTL(KC_F)
#define VIM_PREFIX KC_SCLN
#define SCREENSHOT HYPR(KC_4)
#define NAV_LEFT KC_F23
#define NAV_RIGHT KC_F24
#define VIM_LEFT KC_F21
#define VIM_RIGHT KC_F22
#define MOU_MAX_SPEED MS_ACL2
#define MOU_MIN_SPEED MS_ACL0
#define MOUSE_LEFT MS_LEFT
#define MOUSE_DOWN MS_DOWN
#define MOUSE_UP MS_UP
#define MOUSE_RIGHT MS_RGHT
#define MOUSE_HINT_MOVE LGUI(LOPT(KC_L))
#define MOUSE_HINT_SCRN LGUI(LOPT(KC_S))
#define MOUSE_HINT_CLK HYPR(KC_ENT)
#define WHEEL_LEFT MS_WHLL
#define WHEEL_DOWN MS_WHLD
#define WHEEL_UP MS_WHLU
#define WHEEL_RIGHT MS_WHLR
#define RIGHT_CLICK MS_BTN2
#define LEFT_CLICK MS_BTN1
#define WM_FOCUS_LEFT LOPT(LCTL(LSFT(KC_H)))
#define WM_FOCUS_DOWN LOPT(LCTL(LSFT(KC_J)))
#define WM_FOCUS_UP LOPT(LCTL(LSFT(KC_K)))
#define WM_FOCUS_RIGHT LOPT(LCTL(LSFT(KC_L)))
#define WM_FULLSCREEN LOPT(LCTL(LSFT(KC_A)))
#define WM_TOGGLE_FT LOPT(LCTL(LSFT(KC_SCLN)))
#define WM_CLOSE LOPT(LCTL(LSFT(KC_C)))
#define WM_WS_1 LOPT(LCTL(LSFT(KC_Q)))
#define WM_WS_2 LOPT(LCTL(LSFT(KC_W)))
#define WM_WS_3 LOPT(LCTL(LSFT(KC_E)))
#define WM_WS_4 LOPT(LCTL(LSFT(KC_R)))
#define WM_WS_5 LOPT(LCTL(LSFT(KC_T)))
#define WM_MOVE_WS_1 LOPT(LCTL(LSFT(KC_Y)))
#define WM_MOVE_WS_2 LOPT(LCTL(LSFT(KC_U)))
#define WM_MOVE_WS_3 LOPT(LCTL(LSFT(KC_I)))
#define WM_MOVE_WS_4 LOPT(LCTL(LSFT(KC_O)))
#define WM_MOVE_WS_5 LOPT(LCTL(LSFT(KC_P)))
#define WM_MOVE_MONITOR LOPT(LCTL(LSFT(KC_M)))
#define WM_MODE_RESIZE LOPT(LCTL(LSFT(KC_S)))
#define WM_MODE_MOVE LOPT(LCTL(LSFT(KC_D)))
#define WM_L_ACCORDION LOPT(LCTL(LSFT(KC_F)))
#define WM_L_TILES LOPT(LCTL(LSFT(KC_G)))
#define WM_MODE_JOIN LOPT(LCTL(LSFT(KC_Z)))

enum layers {
    BASE = 0,
    NAV,
    MOU,
    SYM,
    NUM,
    WM,
#ifdef GAME_LAYER_ENABLE
    GAME,
#endif
};

enum keycodes {
    SWITCH_APP = SAFE_RANGE, // Switch to next window (cmd-tab)
};

enum tapdance {
    TD_SWITCH_APP = 0,
    TD_RESET,
};

// clang-format off
#define __________________BASE_L1__________________       KC_Q,            KC_W,            KC_E,            KC_R,            KC_T
#define __________________BASE_L2__________________       LGUI_T(KC_A),    LOPT_T(KC_S),    LCTL_T(KC_D),    LSFT_T(KC_F),    HYPR_T(KC_G)
#define __________________BASE_L3__________________       KC_Z,            KC_X,            KC_C,            KC_V,            KC_B
#define ______________BASE_THUMB_LEFT______________       LT(NAV, KC_ESC), LT(MOU, KC_SPC)

#define __________________BASE_R1__________________       KC_Y,            KC_U,            KC_I,            KC_O,            KC_P
#define __________________BASE_R2__________________       HYPR_T(KC_H),    LSFT_T(KC_J),    LCTL_T(KC_K),    LALT_T(KC_L),    LGUI_T(KC_SCLN)
#define __________________BASE_R3__________________       KC_N,            KC_M,            KC_COMM,         KC_DOT,          KC_SLSH
#define ______________BASE_THUMB_RIGHT_____________       LT(NUM, KC_ENT), LT(SYM, KC_BSPC)

#define ___________________NAV_L1__________________       KC_BRID,         KC_BRIU,         SCREENSHOT,      XXXXXXX,         XXXXXXX
#define ___________________NAV_L2__________________       KC_LGUI,         KC_LOPT,         KC_LCTL,         KC_LSFT,         XXXXXXX
#define ___________________NAV_L3__________________       KC_VOLD,         KC_VOLU,         KC_MUTE,         TMUX_PREFIX,     XXXXXXX
#define ______________NAV_THUMB_LEFT_______________       _______,         _______

#define ___________________NAV_R1__________________       XXXXXXX,         XXXXXXX,         XXXXXXX,         XXXXXXX,         TD(TD_SWITCH_APP)
#define ___________________NAV_R2__________________       KC_LEFT,         KC_DOWN,         KC_UP,           KC_RGHT,         SWITCH_APP
#define ___________________NAV_R3__________________       NAV_LEFT,        VIM_LEFT,        VIM_RIGHT,       NAV_RIGHT,       LGUI(KC_GRAVE)
#define ______________NAV_THUMB_RIGHT______________       _______,         _______

#define ___________________MOU_L1__________________       XXXXXXX,         XXXXXXX,         MOU_MIN_SPEED,   MOU_MAX_SPEED,   XXXXXXX
#define ___________________MOU_L2__________________       KC_LGUI,         KC_LOPT,         KC_LCTL,         KC_LSFT,         XXXXXXX
#define ___________________MOU_L3__________________       XXXXXXX,         XXXXXXX,         XXXXXXX,         XXXXXXX,         XXXXXXX
#define ______________MOU_THUMB_LEFT_______________       _______,         _______

#define ___________________MOU_R1__________________       XXXXXXX,         MOUSE_HINT_CLK, MOUSE_HINT_MOVE,  MOUSE_HINT_SCRN, TD(TD_SWITCH_APP)
#define ___________________MOU_R2__________________       MOUSE_LEFT,      MOUSE_DOWN,      MOUSE_UP,        MOUSE_RIGHT,     SWITCH_APP
#define ___________________MOU_R3__________________       WHEEL_LEFT,      WHEEL_DOWN,      WHEEL_UP,        WHEEL_RIGHT,     LGUI(KC_GRAVE)
#define ______________MOU_THUMB_RIGHT______________       LEFT_CLICK,      RIGHT_CLICK

#define ___________________SYM_L1__________________       KC_AMPR,         KC_ASTR,         KC_LCBR,         KC_RCBR,         KC_GRV
#define ___________________SYM_L2__________________       KC_CIRC,         KC_DLR,          KC_LPRN,         KC_RPRN,         KC_TILD
#define ___________________SYM_L3__________________       KC_PERC,         KC_HASH,         KC_LBRC,         KC_RBRC,         KC_QUES
#define ______________SYM_THUMB_LEFT_______________       _______,         _______

#define ___________________SYM_R1__________________       KC_AT,           KC_PLUS,         KC_UNDS,         KC_PIPE,         KC_COLON
#define ___________________SYM_R2__________________       KC_EXLM,         KC_EQL,          KC_MINS,         KC_BSLS,         KC_SCLN
#define ___________________SYM_R3__________________       KC_QUOT,         KC_DQUO,         KC_COMM,         KC_DOT,          KC_SLSH
#define ______________SYM_THUMB_RIGHT______________       _______,         _______

#define ___________________NUM_L1__________________       XXXXXXX,         KC_7,            KC_8,            KC_9,            XXXXXXX
#define ___________________NUM_L2__________________       XXXXXXX,         KC_4,            KC_5,            KC_6,            XXXXXXX
#define ___________________NUM_L3__________________       KC_0,            KC_1,            KC_2,            KC_3,            XXXXXXX
#define ______________NUM_THUMB_LEFT_______________       _______,         _______

#define ___________________NUM_R1__________________       XXXXXXX,         VIM_PREFIX,      XXXXXXX,         XXXXXXX,         XXXXXXX
#define ___________________NUM_R2__________________       XXXXXXX,         KC_LSFT,         KC_LCTL,         KC_LOPT,         KC_LGUI
#define ___________________NUM_R3__________________       XXXXXXX,         TMUX_PREFIX,     KC_COMM,         KC_DOT,          XXXXXXX
#define ______________NUM_THUMB_RIGHT______________       _______,         _______

#define ___________________WM_L1___________________       WM_WS_1,         WM_WS_2,         WM_WS_3,         WM_WS_4,         WM_WS_5
#define ___________________WM_L2___________________       WM_FULLSCREEN,   WM_MODE_RESIZE,  WM_MODE_MOVE,    WM_L_TILES,      WM_L_ACCORDION
#define ___________________WM_L3___________________       WM_MODE_JOIN,    XXXXXXX,         WM_CLOSE,        XXXXXXX,         XXXXXXX
#define ______________WM_THUMB_LEFT________________       _______,         TD(TD_RESET)

#define ___________________WM_R1___________________       WM_MOVE_WS_1,    WM_MOVE_WS_2,    WM_MOVE_WS_3,    WM_MOVE_WS_4,    WM_MOVE_WS_5
#define ___________________WM_R2___________________       WM_FOCUS_LEFT,   WM_FOCUS_DOWN,   WM_FOCUS_UP,     WM_FOCUS_RIGHT,  WM_TOGGLE_FT
#define ___________________WM_R3___________________       XXXXXXX,         WM_MOVE_MONITOR, XXXXXXX,         XXXXXXX,         XXXXXXX
#ifdef GAME_LAYER_ENABLE
#define ______________WM_THUMB_RIGHT_______________       TO(GAME),        _______
#else
#define ______________WM_THUMB_RIGHT_______________       _______,         _______
#endif

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
