#pragma once

enum layers {
    BASE = 0,
    NAV,
    MOU,
    SYM,
    NUM,
    WM,
    SECRET,  // SECRET layer has higher priority than WM
#ifdef GAME_LAYER_ENABLE
    GAME,
#endif
};
