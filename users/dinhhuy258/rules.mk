include $(USER_PATH)/oled/rules.mk

SRC += $(USER_PATH)/dinhhuy258.c
SRC += $(USER_PATH)/definitions/keyboard_config.c
SRC += $(USER_PATH)/features/swapper.c
SRC += $(USER_PATH)/features/taphold.c
SRC += $(USER_PATH)/features/caps_word.c
SRC += $(USER_PATH)/features/led_indicators.c
SRC += $(USER_PATH)/features/secrets.c
SRC += $(USER_PATH)/features/leader.c
SRC += $(USER_PATH)/features/custom_shift_keys.c

# https://github.com/qmk/qmk_firmware/issues/21137#issuecomment-1577898767
INTROSPECTION_KEYMAP_C = $(USER_PATH)/keymap_introspection.c

MOUSEKEY_ENABLE = yes
# For mouse jiggler
DEFERRED_EXEC_ENABLE = yes
CAPS_WORD_ENABLE = yes
COMBO_ENABLE = yes
TAP_DANCE_ENABLE = yes
LEADER_ENABLE = yes

CONSOLE_ENABLE = no
COMMAND_ENABLE = no

# Enables Link Time Optimization (LTO) when compiling the keyboard.
# This makes the process take longer, but it can significantly reduce the compiled size.
LTO_ENABLE = yes

EXTRAFLAGS += -flto
