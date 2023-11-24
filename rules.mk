ifeq ($(strip $(AUDIO_ENABLE)), yes)
    SRC += muse.c
endif

MIDI_ENABLE = no
KEY_OVERRIDE_ENABLE = yes
DYNAMIC_MACRO_ENABLE = yes
COMMAND_ENABLE = no

