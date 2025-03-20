#include "dinhhuy258.h"

// clang-format off
#define LAYOUT_ergodox_pretty_wrapper(...)   LAYOUT_ergodox_pretty(__VA_ARGS__)

#define LAYOUT_ergodox_pretty_base( \
    K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, \
    K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, \
    K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A, \
    K31, K32, K33, K34 \
    ) \
    LAYOUT_ergodox_pretty_wrapper( \
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
        XXXXXXX, K01,     K02,     K03,     K04,     K05,     XXXXXXX,        XXXXXXX, K06,     K07,     K08,     K09,     K0A,     XXXXXXX, \
        XXXXXXX, K11,     K12,     K13,     K14,     K15,                              K16,     K17,     K18,     K19,     K1A,     XXXXXXX, \
        XXXXXXX, K21,     K22,     K23,     K24,     K25,     XXXXXXX,        XXXXXXX, K26,     K27,     K28,     K29,     K2A,     XXXXXXX, \
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, K31,                                                K34,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
                                                     XXXXXXX, XXXXXXX,        XXXXXXX, XXXXXXX,                                              \
                                                              XXXXXXX,        XXXXXXX,                                                       \
                                            K32,     XXXXXXX, XXXXXXX,        XXXXXXX, XXXXXXX, K33                                          \
    )

#define LAYOUT_base_wrapper(...)       LAYOUT_ergodox_pretty_base(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT_base_wrapper(
        __________________BASE_L1__________________, __________________BASE_R1__________________,
        __________________BASE_L2__________________, __________________BASE_R2__________________,
        __________________BASE_L3__________________, __________________BASE_R3__________________,
        ______________BASE_THUMB_LEFT______________, ______________BASE_THUMB_RIGHT_____________
    ),
    [NAV] = LAYOUT_base_wrapper(
        ___________________NAV_L1__________________, ___________________NAV_R1__________________,
        ___________________NAV_L2__________________, ___________________NAV_R2__________________,
        ___________________NAV_L3__________________, ___________________NAV_R3__________________,
        ______________NAV_THUMB_LEFT_______________, ______________NAV_THUMB_RIGHT______________
    ),
    [MOU] = LAYOUT_base_wrapper(
        ___________________MOU_L1__________________, ___________________MOU_R1__________________,
        ___________________MOU_L2__________________, ___________________MOU_R2__________________,
        ___________________MOU_L3__________________, ___________________MOU_R3__________________,
        ______________MOU_THUMB_LEFT_______________, ______________MOU_THUMB_RIGHT______________
    ),
    [SYM] = LAYOUT_base_wrapper(
        ___________________SYM_L1__________________, ___________________SYM_R1__________________,
        ___________________SYM_L2__________________, ___________________SYM_R2__________________,
        ___________________SYM_L3__________________, ___________________SYM_R3__________________,
        ______________SYM_THUMB_LEFT_______________, ______________SYM_THUMB_RIGHT______________
    ),
    [NUM] = LAYOUT_base_wrapper(
        ___________________NUM_L1__________________, ___________________NUM_R1__________________,
        ___________________NUM_L2__________________, ___________________NUM_R2__________________,
        ___________________NUM_L3__________________, ___________________NUM_R3__________________,
        ______________NUM_THUMB_LEFT_______________, ______________NUM_THUMB_RIGHT______________
    ),
    [WM] = LAYOUT_base_wrapper(
        ___________________WM_L1___________________, ___________________WM_R1___________________,
        ___________________WM_L2___________________, ___________________WM_R2___________________,
        ___________________WM_L3___________________, ___________________WM_R3___________________,
        ______________WM_THUMB_LEFT________________, ______________WM_THUMB_RIGHT_______________
    ),
    #ifdef GAME_LAYER_ENABLE
    [GAME] = LAYOUT_base_wrapper(
        ___________________GAME_L1_________________, ___________________GAME_R1_________________,
        ___________________GAME_L2_________________, ___________________GAME_R2_________________,
        ___________________GAME_L3_________________, ___________________GAME_R3_________________,
        ______________GAME_THUMB_LEFT______________, ______________GAME_THUMB_RIGHT_____________
    ),
    #endif
};
// clang-format on
