#pragma once

enum layers {
    BASE = 0,
    NAV,
    MOU,
    SYM,
    NUM,
    WM,
    SECRET,
#ifdef GAME_LAYER_ENABLE
    GAME,
#endif
};
