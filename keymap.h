#pragma once

#include QMK_KEYBOARD_H
#include "muse.h"

// =============================================================================
// LAYERS
// =============================================================================

uint8_t mod_state;
uint8_t oneshot_mod_state;
uint16_t last_keycode;

bool caps_word_on;
void caps_word_enable(void);
void caps_word_disable(void);

enum planck_layers {
  _BL,
  _SL,
  _NL,
  _VI,
  _WL,
  _WQ,
  _MS,
  _LOWER,
  _FN,
  _MD
};

// =============================================================================
// MACRO KEYS
// =============================================================================

bool is_alt_tab_active = false; // ADD this near the begining of keymap.c

enum macros {
    SUSPEND = SAFE_RANGE,
    GUI_TAB,
    SGUI_TAB,
    CAPS_WORD
};

// =============================================================================
// KEY DEF SECTION
// =============================================================================

#define LOWER  LT(_LOWER, KC_LSFT)
#define NUMPAD LT(_NL, KC_SPC)
// #define FN_LAY LT(_FN, KC_SPC)
#define FN_LAY MO(_FN)
#define L_VI_D LT(_VI, KC_D)
#define L_MS_E LT(_MS, KC_E)
#define WIND_W LT(_WL, KC_W)
#define M_NUMP MO(_NL)
#define T_SNAK TG(_SL)
#define T_NUMB TG(_NL)
#define T_VIL TG(_VI)
#define T_MSL TG(_MS)

// layer taps keys
#define L_VI_D LT(_VI, KC_D)
#define L_MS_E LT(_MS, KC_E)

// single mod keys
#define OS_LS  OSM(MOD_LSFT)
#define OS_LC  OSM(MOD_LCTL)
#define OS_LA  OSM(MOD_LALT)
#define OS_LG  OSM(MOD_LGUI)

// double mod combos
#define OS_LSA  OSM(MOD_BIT(KC_LSFT) | MOD_BIT(KC_LALT))
#define OS_LSC  OSM(MOD_BIT(KC_LSFT) | MOD_BIT(KC_LCTL))
#define OS_LSG  OSM(MOD_BIT(KC_LSFT) | MOD_BIT(KC_LGUI))
#define OS_LAC  OSM(MOD_BIT(KC_LALT) | MOD_BIT(KC_LCTL))
#define OS_LAG  OSM(MOD_BIT(KC_LALT) | MOD_BIT(KC_LGUI))

// triple mod combos
#define OS_LCAG OSM(MOD_BIT(KC_LCTL) | MOD_BIT(KC_LALT) | MOD_BIT(KC_LGUI))
#define OS_LCAS OSM(MOD_BIT(KC_LCTL) | MOD_BIT(KC_LALT) | MOD_BIT(KC_LSFT))
#define OS_LCGS OSM(MOD_BIT(KC_LCTL) | MOD_BIT(KC_LGUI) | MOD_BIT(KC_LSFT))

// hyper combo
#define OS_HYPR OSM(MOD_BIT(KC_LCTL) | MOD_BIT(KC_LGUI) | MOD_BIT(KC_LALT) | MOD_BIT(KC_LSFT))

#define M_GC_ESC MT(MOD_LGUI|MOD_LCTL,KC_ESC)

#define M_GA_SPC MT(MOD_LGUI|MOD_LALT,KC_SPC)
#define T_G_TAB LCMD_T(KC_TAB)
#define T_C_ESC LCTL_T(KC_ESC)
#define T_A_SPC ALT_T(KC_SPC)
// #define T_A_UND MT(MOD_LALT,KC_MIN)

#define T_G_BSP RCMD_T(KC_BSPC)
#define T_C_QUO RCTL_T(KC_QUOT)
#define T_SG_EN SGUI_T(KC_ENT)

#define TD_SEMI TD(SEMI_)
#define TD_HELP TD(SL_HLP)
#define T_SHDOT LSFT_T(KC_PDOT)

#define DW_BKWD A(KC_BSPC)
#define DW_FRWD A(KC_DEL)
#define TD_DEL TD(B_F_DEL)

// =============================================================================
// END KEYMAP.H
// =============================================================================
