#pragma once

enum layers {
    BASE = 0,
    NAV,
    MOU,
    SYM,
    WM,
#ifdef GAME_LAYER_ENABLE
    GAME,
#endif
};
