SRC += muse.c

ifneq ($(strip $(NO_SECRETS)), yes)
    # NOTE needs to be in users for below line to work
    # ifneq ("$(wildcard $(USER_PATH)/secrets.c)","")
    ifneq ("$(wildcard keyboards/planck/keymaps/atanasj/secrets.c)","")
        SRC += secrets.c
    endif
endif

COMMAND_ENABLE = no
CONSOLE_ENABLE = no
LTO_ENABLE = no					# yes for bm40rgbhs

VPATH  += keyboards/planck/keymaps/atanasj/combos/

COMBO_ENABLE = yes
TAP_DANCE_ENABLE = yes
LEADER_ENABLE = yes
UNICODE_ENABLE = yes
NKRO_ENABLE = yes
AUDIO_ENABLE = yes				# no for bm40rgbhs
MIDI_ENABLE = yes
DYNAMIC_MACRO_ENABLE = yes
CAPS_WORD_ENABLE = yes
