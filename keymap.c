#include QMK_KEYBOARD_H
#include "muse.h"

#include "keymap.h"

#ifdef COMBO_ENABLE
#include "keymap_combo.h"
#endif

#ifdef TAP_DANCE_ENABLE
#include "tapdance.h"
#endif

#if defined (RGBLIGHT_ENABLE) || defined (RGB_MATRIX_ENABLE)
#include "rgb.h"
#endif

// =============================================================================
// KEYMAP SECTION
// =============================================================================

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_BL] = LAYOUT_planck_mit(
    T_G_TAB, KC_Q,     WIND_W,  L_MS_E,   KC_R,   KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    T_G_BSP,
    T_C_ESC, KC_A,     KC_S,    L_VI_D,   KC_F,   KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, T_C_QUO,
    KC_LSPO, KC_Z,     KC_X,    KC_C,     KC_V,   KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  TD_HELP, KC_RSFT,
    OS_HYPR, M_GC_ESC, LOWER,   OS_LAG,   NUMPAD, T_A_SPC,          FN_LAY,  OS_LCAG, XXXXXXX, XXXXXXX, T_SG_EN
),
[_SL] = LAYOUT_planck_mit(
    T_G_TAB, KC_Q,     WIND_W,  L_MS_E,   KC_R,   KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    T_G_BSP,
    T_C_ESC, KC_A,     KC_S,    L_VI_D,   KC_F,   KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, T_C_QUO,
    KC_LSPO, KC_Z,     KC_X,    KC_C,     KC_V,   KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  TD_HELP, KC_RSFT,
    OS_HYPR, M_GC_ESC, LOWER,   OS_LAG,   NUMPAD, KC_UNDS,          FN_LAY,  OS_LCAG, XXXXXXX, XXXXXXX, T_SG_EN
),
[_NL] = LAYOUT_planck_mit(
    _______, XXXXXXX, XXXXXXX, _______,  XXXXXXX, XXXXXXX, XXXXXXX, KC_7,    KC_8,    KC_9,    KC_EQL,  _______,
    _______, KC_LGUI, KC_LALT, _______,  T_SHDOT, XXXXXXX, XXXXXXX, KC_4,    KC_5,    KC_6,    KC_MINS, _______,
    _______, XXXXXXX, XXXXXXX, XXXXXXX,  T_NUMB,  XXXXXXX, XXXXXXX, KC_1,    KC_2,    KC_3,    KC_PSLS, XXXXXXX,
    _______, XXXXXXX, _______, _______,  _______, KC_0,             KC_SPC,  _______, XXXXXXX, XXXXXXX, _______
 ),
[_VI] = LAYOUT_planck_mit(
    _______, _______, _______, _______, _______, _______, KC_HOME, KC_PGDN,  KC_PGUP, KC_END,   XXXXXXX, T_SNAK,
    _______, KC_LCMD, KC_LALT, _______, KC_LSFT, KC_LEAD, KC_LEFT, KC_DOWN,  KC_UP,   KC_RIGHT, KC_F19,  KC_CAPS,
    _______, _______, _______, _______, T_VIL,   _______, DW_BKWD, KC_BSPC,  KC_DEL,  DW_FRWD,  TD_DEL,  _______,
    _______, _______, _______, _______, _______, _______,          _______,  _______, _______,  _______, _______
),
[_WL] = LAYOUT_planck_mit(
    _______, MO(_WQ), _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX,    XXXXXXX,    KC_BTN5,    XXXXXXX, XXXXXXX,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, HYPR(KC_H), HYPR(KC_J), HYPR(KC_K), HYPR(KC_L), XXXXXXX, XXXXXXX,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, HYPR(KC_I), XXXXXXX,    _______,    _______,    XXXXXXX, XXXXXXX,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, HYPR(KC_ENT),        XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX, _______
 ),
[_WQ] = LAYOUT_planck_mit(
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,      XXXXXXX, XXXXXXX,  KC_BTN7,   XXXXXXX, XXXXXXX,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, G(S(KC_GRV)), GUI_TAB, SGUI_TAB, G(KC_GRV), XXXXXXX, XXXXXXX,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,      XXXXXXX, _______,  _______,   XXXXXXX, XXXXXXX,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,               XXXXXXX, XXXXXXX,  XXXXXXX,   XXXXXXX, _______
 ),
[_MS] = LAYOUT_planck_mit(
    KC_ACL0, KC_ACL2, KC_ACL1, _______, KC_R,    XXXXXXX, KC_WH_L, KC_WH_U,    KC_WH_D, KC_WH_R, XXXXXXX, XXXXXXX,
    _______, KC_A,    KC_S,    XXXXXXX, KC_F,    XXXXXXX, KC_MS_L, KC_MS_D,    KC_MS_U, KC_MS_R, XXXXXXX, XXXXXXX,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, T_MSL,   XXXXXXX, XXXXXXX, C(G(KC_D)), XXXXXXX, KC_BTN2, XXXXXXX, XXXXXXX,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_BTN1,          XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, _______
 ),
[_LOWER] = LAYOUT_planck_mit(
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   _______, _______, _______, _______, KC_MPLY, _______,
    KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, _______, _______,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MUTE, XXXXXXX, MU_ON,   MU_OFF,  MU_MOD,
    _______, XXXXXXX, _______, XXXXXXX, XXXXXXX, KC_LALT,          XXXXXXX, TG(_MD), AU_ON,   AU_OFF,  _______
),
[_FN] = LAYOUT_planck_mit(
    SUSPEND, KC_TILD, KC_LCBR, KC_RCBR, KC_PIPE, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, DEBUG,   RGB_TOG,
    KC_BRIU, KC_GRV,  KC_LBRC, KC_RBRC, KC_BSLS, XXXXXXX, XXXXXXX, KC_LGUI, XXXXXXX, KC_BSPC, _______, XXXXXXX,
    KC_BRID, XXXXXXX, KC_LPRN, KC_RPRN, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_LSFT,
    _______, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD,          _______, XXXXXXX, RGB_VAI, RGB_VAD, RESET
),
// NOTE quantum/process_keycode/process_midi.c
[_MD] = LAYOUT_planck_mit(
    MI_CHU,  MI_Cs,    MI_Ds,   XXXXXXX,  MI_Fs,    MI_Gs,     MI_As,    XXXXXXX,  MI_Cs_1,   MI_Ds_1,  XXXXXXX,   MI_Fs_1,
    MI_MOD,  MI_C,     MI_D,    MI_E,     MI_F,     MI_G,      MI_A,     MI_B,     MI_C_1,    MI_D_1,   MI_E_1,    MI_F_1,
    MI_VELD, MI_VELU,  MI_PORT, MI_SOST,  MI_SOFT,  MI_LEG,    MI_BENDD, MI_BENDU, MI_VEL_8,  MI_OCT_0, MI_VEL_0,  TG(_MD),
    MI_SUS,  MI_OCTD,  MI_OCTU, MI_MODSD, MI_MODSU, MI_ALLOFF,           XXXXXXX,  MI_TRNS_0, MI_TRNSD, MI_TRNSU,  MI_SUS
),
};

// layer_state_t layer_state_set_user(layer_state_t state) {
//   return update_tri_layer_state(state, _LOWER, _FN, _MD);
// }


// =============================================================================
// MACRO DEFS
// =============================================================================

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case GUI_TAB:
            if (record->event.pressed) {
                if (!is_alt_tab_active) {
                    is_alt_tab_active = true;
                    register_code(KC_LGUI);
                }
                register_code(KC_TAB);
            } else {
                unregister_code(KC_TAB);
            }
            break;
        case SGUI_TAB:
            if (record->event.pressed) {
                if (!is_alt_tab_active) {
                    is_alt_tab_active = true;
                    register_code(KC_LGUI);
                }
                register_code(KC_LSFT);
                register_code(KC_TAB);
            } else {
                unregister_code(KC_LSFT);
                unregister_code(KC_TAB);
            }
            break;
        case KC_RSFT:
            perform_space_cadet(record, KC_RSPC, KC_RSFT, KC_RSFT, KC_0);
            return false;
        case SUSPEND:
            if (record->event.pressed) {
                if (is_led_on) {
                    is_led_on = false;
                    rgblight_disable();
                    SEND_STRING(SS_LCTL(SS_LGUI("q")) SS_DELAY(999) SS_TAP(X_ESC));
                }
            }
            return true;
        default:
            if (record->event.pressed) {
                if (!is_led_on) {
                    is_led_on = true;
                    rgblight_enable();
                }
            }
    }
    return true;
}

// =============================================================================
// TAPPING TERM PER KEY SECTION
// =============================================================================

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case LT(_MS,KC_E):
    case LT(_VI,KC_D):
    case NUMPAD:
    case WIND_W:
        return 225;
    case SL_HLP:
        return 150;
    case KC_LSPO:
    case KC_RSPC:
        return 115;
    case SEMI_:
        return 155;
    case FN_LAY:
        return 35;
    default:
        return TAPPING_TERM;
    }
}

// =============================================================================
// RETRO TAPPING PER KEY SECTION
// =============================================================================

bool get_retro_tapping(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LT(_MS, KC_E):
        case LT(_VI, KC_D):
        case WIND_W:
            return true;
        default:
            return false;
    }
}

// =============================================================================
// PERMISSIVE HOLD PER KEY SECTION
// =============================================================================

bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LT(_MS, KC_E):
        case LT(_VI, KC_D):
        case WIND_W:
            return true;
        default:
            return false;
    }
}

// =============================================================================
// MOD TAP INTERRUP PER KEY SECTION
// =============================================================================

bool get_ignore_mod_tap_interrupt(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case ALT_T(KC_SPC):
        case KC_LSPO:
        case KC_RSFT:
            return true;
        default:
            return false;
    }
}

// =============================================================================
// LEADER KEY SECTION
// =============================================================================

LEADER_EXTERNS();

void matrix_scan_user(void) {
    if (is_alt_tab_active) {
        if (!layer_state_is(_WQ)) {
            unregister_code(KC_LGUI);
            is_alt_tab_active = false;
        }
    }
    LEADER_DICTIONARY() {
        leading = false;
        leader_end();
        // R section
        SEQ_THREE_KEYS(KC_R, KC_F, KC_N) {
            // negate function
            SEND_STRING("`%!in%` <- Negate(`%in%`)");
        }
        SEQ_TWO_KEYS(KC_R, KC_SCLN) {
            // needs to a as semi colon is a tap dance key
            // need to use bscp as first enters semi colon
            SEND_STRING(" <-");
        }
        SEQ_TWO_KEYS(KC_R, KC_P) {
            SEND_STRING(" %>%");
        }
        SEQ_TWO_KEYS(KC_R, KC_I) {
            SEND_STRING(" %in% ");
        }
        SEQ_TWO_KEYS(KC_R, KC_N) {
            SEND_STRING(" %!in% ");
        }
        // Signature section
        SEQ_TWO_KEYS(KC_S, KC_S) {
            SEND_STRING("Cheers,  :-)" SS_TAP(X_ENT) SS_TAP(X_ENT) "Atanas");
        }
        /* // Kamoji section */
        /* SEQ_TWO_KEYS(KC_K, KC_F) { */
        /*     send_unicode_string("(ノಠ痊ಠ)ノ彡┻━┻"); */
        /* } */
        /* // Emoticons section */
        /* SEQ_TWO_KEYS(KC_E, KC_T) { */
        /*     SEND_STRING(SS_LALT("D83D+DC83")); // 💃 */
        /* } */
        /* SEQ_TWO_KEYS(KC_E, KC_P) { */
        /*     SEND_STRING(SS_LALT("D83D+DCA9")); // 💩 */
        /* } */
    }
}

// =============================================================================
// END KEYMAP.C
// =============================================================================
