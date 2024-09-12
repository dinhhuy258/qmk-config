include $(USER_PATH)/oled/rules.mk

SRC += $(USER_PATH)/swapper.c

MOUSEKEY_ENABLE = yes

# Enables Link Time Optimization (LTO) when compiling the keyboard.
# This makes the process take longer, but it can significantly reduce the compiled size.
LTO_ENABLE = yes

EXTRAFLAGS += -flto
