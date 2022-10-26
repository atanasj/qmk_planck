#pragma once

#include QMK_KEYBOARD_H
#include "muse.h"

// =============================================================================
// LAYERS
// =============================================================================

uint8_t mod_state;
uint8_t oneshot_mod_state;

enum planck_layers {
  _BL,
  _SL,
  _NL,
  _VI,
  _WL,
  _WQ,
  _DM,
  _MS,
  _FN,
  _MD,
  _SC
};

// =============================================================================
// MACRO KEYS
// =============================================================================

enum macros {
    SUSPEND = SAFE_RANGE,
    GUI_TAB,
    SG_TAB,
    SECRET1,
    SECRET2,
    SECRET3,
    SECRET4,
    SECRET5,
};

// =============================================================================
// KEY DEF SECTION
// =============================================================================

// outer row modifiers
#define LG_Q LGUI_T(KC_Q)
#define LC_A LCTL_T(KC_A)
#define LS_Z LSFT_T(KC_Z)
#define RG_P RGUI_T(KC_P)
#define RC_QUOT LCTL_T(KC_QUOT)
#define RS_SLSH RSFT_T(KC_SLSH)
#define LAG_ESC  LAG_T(KC_SPC)

// Mouse and window layers
#define MO_WQ MO(_WQ)
#define MO_DM MO(_DM)

#define GS_GRV G(S(KC_GRV))
#define GUI_GRV G(KC_GRV)
#define CG_D C(G(KC_D))

#define HYP_H HYPR(KC_H)
#define HYP_I HYPR(KC_I)
#define HYP_J HYPR(KC_J)
#define HYP_K HYPR(KC_K)
#define HYP_L HYPR(KC_L)
#define HYP_ENT HYPR(KC_ENT)

// layer taps
#define LOWER  LT(_LOWER, KC_LSFT)
#define NUMPAD LT(_NL, KC_ESC)
#define FN_LAY MO(_FN)
#define L_FN_K LT(_FN, KC_K)
#define L_VI_D LT(_VI, KC_D)
#define L_MS_E LT(_MS, KC_E)
#define WIND_W LT(_WL, KC_W)
#define T_SNAK TG(_SL)
#define T_NUMB TG(_NL)
#define T_VIL TG(_VI)
#define T_MSL TG(_MS)
#define MIDI_ON TG(_MD)

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

// mouse layer safety keys
#define MS_GUIA LGUI_T(KC_A)
#define MS_ALTS LALT_T(KC_S)
#define MS_SFTF LSFT_T(KC_F)

#define T_G_BSP RCMD_T(KC_BSPC)
#define T_C_QUO LCTL_T(KC_QUOT)
#define T_SG_EN SGUI_T(KC_ENT)

#define TD_SEMI TD(SEMI_)
#define TD_HELP TD(SL_HLP)
#define T_SHDOT LSFT_T(KC_PDOT)

#define DW_BKWD A(KC_BSPC)
#define DW_FRWD A(KC_DEL)
#define TD_DEL TD(B_F_DEL)

// help menu
#define SL_HELP LSG(KC_SLSH)

// =============================================================================
// END KEYMAP.H
// =============================================================================
