ifeq ($(strip $(OLED_ENABLE)), yes)
    SRC += $(USER_PATH)/oled/oled.c
    SRC += $(USER_PATH)/oled/animation_framework.c
    SRC += $(USER_PATH)/oled/bongocat.c
endif
