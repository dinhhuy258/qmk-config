MCU = RP2040
BOOTLOADER = rp2040
CONVERT_TO = rp2040_ce

USER_NAME := dinhhuy258

OLED_ENABLE = yes
OLED_DRIVER = ssd1306

ifneq ($(strip $(USE_SERIAL_PIN_D3)),)
    OPT_DEFS += -DUSE_SERIAL_PIN_D3
endif

ifneq ($(strip $(GAME_LAYER_ENABLE)),)
    OPT_DEFS += -DGAME_LAYER_ENABLE
endif

ifneq ($(strip $(USE_RGB_LIGHTING)),)
    RGBLIGHT_ENABLE = yes
    RGB_MATRIX_ENABLE = no # Can't have RGBLIGHT and RGB_MATRIX at the same time.
    WS2812_DRIVER = vendor
else
    RGBLIGHT_ENABLE = no
    RGB_MATRIX_ENABLE = no
endif

ifneq ($(strip $(TAPPING_TERM)),)
    OPT_DEFS += -DCUSTOM_TAPPING_TERM=$(TAPPING_TERM)
endif
