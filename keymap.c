#include QMK_KEYBOARD_H
#include "muse.h"

bool is_alt_tab_active = false;  // ADD this near the begining of keymap.c
__attribute__ ((weak))
bool process_record_secrets(uint16_t keycode, keyrecord_t *record) {
  return true;
}

#include "keymap.h"

#ifdef COMBO_ENABLE
#    include "keymap_combo.h"
#endif

#ifdef TAP_DANCE_ENABLE
#    include "tapdance.h"
#endif

#if defined(RGBLIGHT_ENABLE) || defined(RGB_MATRIX_ENABLE)
#    include "rgbstuff.h"
#endif

// =============================================================================
// KEYMAP SECTION
// =============================================================================

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_BL] = LAYOUT_planck_mit(
    T_G_TAB, KC_Q,     WIND_W,  L_MS_E,   KC_R,   KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    T_G_BSP,
    T_C_ESC, KC_A,     KC_S,    L_VI_D,   KC_F,   KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, T_C_QUO,
    KC_LSPO, KC_Z,     KC_X,    KC_C,     KC_V,   KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  TD_HELP, KC_RSFT,
    OS_HYPR, M_GC_ESC, LOWER,   OS_LAG,   NUMPAD, T_A_SPC,          FN_LAY,  OS_LCAG, XXXXXXX, KC_SECRET_1, T_SG_EN
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
    _______, _______, _______, _______, _______, _______, KC_HOME, KC_PGDN,  KC_PGUP, KC_END,   KC_CAPS, T_SNAK,
    _______, KC_LCMD, KC_LALT, _______, KC_LSFT, KC_LEAD, KC_LEFT, KC_DOWN,  KC_UP,   KC_RIGHT, KC_F19,  _______,
    _______, _______, _______, _______, T_VIL,   _______, DW_BKWD, KC_BSPC,  KC_DEL,  DW_FRWD,  TD_DEL,  _______,
    _______, _______, _______, _______, _______, _______,          _______,  _______, _______,  _______, _______
),
[_WL] = LAYOUT_planck_mit(
    _______, MO(_WQ), _______, XXXXXXX, MO(_DM), XXXXXXX, XXXXXXX,    XXXXXXX,    XXXXXXX,    KC_BTN5,    XXXXXXX, XXXXXXX,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, HYPR(KC_H), HYPR(KC_J), HYPR(KC_K), HYPR(KC_L), XXXXXXX, _______,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, HYPR(KC_I), XXXXXXX,    _______,    _______,    XXXXXXX, XXXXXXX,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, HYPR(KC_ENT),        XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX, _______
 ),
[_WQ] = LAYOUT_planck_mit(
    _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,      XXXXXXX, XXXXXXX,  KC_BTN7,   XXXXXXX, XXXXXXX,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, G(S(KC_GRV)), GUI_TAB, SGUI_TAB, G(KC_GRV), XXXXXXX, _______,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,      XXXXXXX, _______,  _______,   XXXXXXX, XXXXXXX,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,               XXXXXXX, XXXXXXX,  XXXXXXX,   XXXXXXX, _______
 ),
[_DM] = LAYOUT_planck_mit(
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, DM_REC1, DM_PLY1, DM_REC2, DM_PLY2, XXXXXXX, _______,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, DM_RSTP,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______
 ),
[_MS] = LAYOUT_planck_mit(
    KC_ACL0, KC_ACL2, KC_ACL1, _______, KC_R,    XXXXXXX, KC_WH_L, KC_WH_U,    KC_WH_D, KC_WH_R, XXXXXXX, XXXXXXX,
    _______, KC_A,    KC_S,    XXXXXXX, KC_F,    XXXXXXX, KC_MS_L, KC_MS_D,    KC_MS_U, KC_MS_R, XXXXXXX, _______,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, T_MSL,   XXXXXXX, XXXXXXX, C(G(KC_D)), XXXXXXX, KC_BTN2, XXXXXXX, XXXXXXX,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_BTN1,          XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, _______
 ),
[_FN] = LAYOUT_planck_mit(
    SUSPEND, KC_TILD, KC_LCBR, KC_RCBR, KC_PIPE, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, DEBUG,   RGB_TOG,
    KC_BRIU, KC_GRV,  KC_LBRC, KC_RBRC, KC_BSLS, XXXXXXX, XXXXXXX, KC_LGUI, XXXXXXX, KC_BSPC, _______, _______,
    KC_BRID, XXXXXXX, KC_LPRN, KC_RPRN, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_LSFT,
    _______, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD,          _______, XXXXXXX, RGB_VAI, RGB_VAD, RESET
),
[_LOWER] = LAYOUT_planck_mit(
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   _______, _______, _______, _______, KC_MPLY, _______,
    KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, _______, _______,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MUTE, XXXXXXX, MU_ON,   MU_OFF,  MU_MOD,
    _______, XXXXXXX, _______, XXXXXXX, XXXXXXX, KC_LALT,          XXXXXXX, TG(_MD), AU_ON,   AU_OFF,  _______
),
// NOTE quantum/process_keycode/process_midi.c
#ifdef MIDI_ENABLE
[_MD] = LAYOUT_planck_mit(
    MI_CHU,  MI_Cs,    MI_Ds,   XXXXXXX,  MI_Fs,    MI_Gs,     MI_As,    XXXXXXX,  MI_Cs_1,   MI_Ds_1,  XXXXXXX,   MI_Fs_1,
    MI_MOD,  MI_C,     MI_D,    MI_E,     MI_F,     MI_G,      MI_A,     MI_B,     MI_C_1,    MI_D_1,   MI_E_1,    MI_F_1,
    MI_VELD, MI_VELU,  MI_PORT, MI_SOST,  MI_SOFT,  MI_LEG,    MI_BENDD, MI_BENDU, MI_VEL_8,  MI_OCT_0, MI_VEL_0,  TG(_MD),
    MI_SUS,  MI_OCTD,  MI_OCTU, MI_MODSD, MI_MODSU, MI_ALLOFF,           XXXXXXX,  MI_TRNS_0, MI_TRNSD, MI_TRNSU,  MI_SUS
),
#endif
};

// layer_state_t layer_state_set_user(layer_state_t state) {
//   return update_tri_layer_state(state, _LOWER, _FN, _MD);
// }


// =============================================================================
// MACRO DEFS
// =============================================================================

// CAPS_WORD: A "smart" Caps Lock key that only capitalizes the next identifier you type
// and then toggles off Caps Lock automatically when you're done.
void caps_word_enable(void) {
    caps_word_on = true;
    if (!(host_keyboard_led_state().caps_lock)) {
        tap_code(KC_CAPS);
    }
}

void caps_word_disable(void) {
    caps_word_on = false;
    if (host_keyboard_led_state().caps_lock) {
        tap_code(KC_CAPS);
    }
}

// Used to extract the basic tapping keycode from a dual-role key.
// Example: GET_TAP_KC(MT(MOD_RSFT, KC_E)) == KC_E
#define GET_TAP_KC(dual_role_key) dual_role_key & 0xFF

void process_caps_word(uint16_t keycode, const keyrecord_t *record) {
    // Update caps word state
    if (caps_word_on) {
        switch (keycode) {
            case QK_MOD_TAP ... QK_MOD_TAP_MAX:
            case QK_LAYER_TAP ... QK_LAYER_TAP_MAX:
                // Earlier return if this has not been considered tapped yet
                if (record->tap.count == 0) {
                    return;
                }
                // Get the base tapping keycode of a mod- or layer-tap key
                keycode = GET_TAP_KC(keycode);
                break;
            default:
                break;
        }
        switch (keycode) {
            // Keycodes to shift
            case KC_A ... KC_Z:
                if (record->event.pressed) {
                    caps_word_enable();
                }
            // Keycodes that enable caps word but shouldn't get shifted
            case KC_MINS:
            case KC_BSPC:
            case REPEAT:
            // disable below so that disables after one word in _SL
            // case KC_UNDS:
            // case KC_F24: /* The dummy keycode used in NAV_UND */
            case KC_PIPE:
            case CAPS_WORD:
                // If chording mods, disable caps word
                if (record->event.pressed && (get_mods() != MOD_LSFT) && (get_mods() != 0)) {
                    caps_word_disable();
                }
                break;
            default:
                // Any other keycode should automatically disable caps
                if (record->event.pressed) {
                    caps_word_disable();
                }
                break;
        }
    }
}

uint16_t last_keycode  = KC_NO;
uint8_t  last_modifier = 0;

void process_repeat_key(uint16_t keycode, const keyrecord_t *record) {
    last_modifier = oneshot_mod_state > mod_state ? oneshot_mod_state : mod_state;
    if (keycode != REPEAT) {
        // Early return when holding down a pure layer key
        // to retain modifiers
        switch (keycode) {
            case QK_DEF_LAYER ... QK_DEF_LAYER_MAX:
            case QK_MOMENTARY ... QK_MOMENTARY_MAX:
            case QK_LAYER_MOD ... QK_LAYER_MOD_MAX:
            case QK_ONE_SHOT_LAYER ... QK_ONE_SHOT_LAYER_MAX:
            case QK_TOGGLE_LAYER ... QK_TOGGLE_LAYER_MAX:
            case QK_TO ... QK_TO_MAX:
            case QK_LAYER_TAP_TOGGLE ... QK_LAYER_TAP_TOGGLE_MAX:
                return;
        }
        last_modifier = oneshot_mod_state > mod_state ? oneshot_mod_state : mod_state;
        switch (keycode) {
            case QK_LAYER_TAP ... QK_LAYER_TAP_MAX:
            case QK_MOD_TAP ... QK_MOD_TAP_MAX:
                if (record->event.pressed) {
                    last_keycode = GET_TAP_KC(keycode);
                }
                break;
            default:
                if (record->event.pressed) {
                    last_keycode = keycode;
                }
                break;
        }
    } else { // keycode == REPEAT
        if (record->event.pressed) {
            register_mods(last_modifier);
            register_code16(last_keycode);
        } else {
            unregister_code16(last_keycode);
            unregister_mods(last_modifier);
        }
    }
}
// float my_song[][2] = SONG(QWERTY_SOUND);

float tone_rick[][2]    = SONG(RICK_ROLL);
float tone_qwerty[][2]  = SONG(QWERTY_SOUND);
float tone_dvorak[][2]  = SONG(DVORAK_SOUND);
float tone_colemak[][2] = SONG(COLEMAK_SOUND);

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    process_caps_word(keycode, record);
    process_repeat_key(keycode, record);
    mod_state = get_mods();
    oneshot_mod_state = get_oneshot_mods();
    switch (keycode) {
        // case DM_REC1:
        //     if (record->event.pressed) {
        //         PLAY_SONG(tone_qwerty);
        //     }
        //     return true; // Let QMK send the enter press/release events
        // break;
        // case DM_REC2:
        //     if (record->event.pressed) {
        //         PLAY_SONG(tone_dvorak);
        //     }
        //     return true; // Let QMK send the enter press/release events
        // break;
        // case DM_RSTP:
        //     if (record->event.pressed) {
        //         PLAY_SONG(tone_colemak);
        //     }
        //     return true; // Let QMK send the enter press/release events
        // break;
        case CAPS_WORD:
        // Toggle `caps_word_on`
        if (record->event.pressed) {
            if (caps_word_on) {
                caps_word_disable();
                return false;
            } else {
                caps_word_enable();
                return false;
            }
        }
        break;
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
    // return true;
    return process_record_secrets(keycode, record);
}


// Redefine with lower delay
void led_blink(void) {
    rgblight_toggle();
    wait_ms(25);
    rgblight_toggle();
}

void dynamic_macro_record_start_user(void) {
    led_blink();
    PLAY_SONG(tone_qwerty);

}

void dynamic_macro_play_user(int8_t direction) {
    led_blink();
}

void dynamic_macro_record_key_user(int8_t direction, keyrecord_t *record) {
    led_blink();
    PLAY_SONG(tone_dvorak);

}

void dynamic_macro_record_end_user(int8_t direction) {
    led_blink();
    PLAY_SONG(tone_colemak);
}

// =============================================================================
// TAPPING TERM PER KEY SECTION
// =============================================================================

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case L_MS_E:
    case L_VI_D:
    case WIND_W:
    case NUMPAD:
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
        case L_MS_E:
        case L_VI_D:
        case WIND_W:
        case NUMPAD:
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
        case L_MS_E:
        case L_VI_D:
        case WIND_W:
        case NUMPAD:
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
        case T_A_SPC:
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
