include $(USER_PATH)/oled/rules.mk

SRC += $(USER_PATH)/caps_word.c
SRC += $(USER_PATH)/swapper.c
# https://github.com/qmk/qmk_firmware/issues/21137#issuecomment-1577898767
INTROSPECTION_KEYMAP_C = $(USER_PATH)/dinhhuy258.c

MOUSEKEY_ENABLE = yes
CAPS_WORD_ENABLE = yes
COMBO_ENABLE = yes

CONSOLE_ENABLE = no
COMMAND_ENABLE = no

# Enables Link Time Optimization (LTO) when compiling the keyboard.
# This makes the process take longer, but it can significantly reduce the compiled size.
LTO_ENABLE = yes

EXTRAFLAGS += -flto
