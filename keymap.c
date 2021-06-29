/* Copyright 2015-2017 Jack Humbert
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H
#include "muse.h"

enum planck_layers {
  _BL,
  _SL,
  _NL,
  _VI,
  _MS,
  _LOWER,
  _FN,
  _MD
};

#include "keymap_combo.h"

// =============================================================================
// KEY DEF SECTION
// =============================================================================

#define LOWER  LT(_LOWER, KC_LSFT)
#define NUMPAD LT(_NL, KC_SPC)
// #define FN_LAY LT(_FN, KC_SPC)
#define FN_LAY MO(_FN)
#define L_VI_D LT(_VI, KC_D)
#define L_MS_E LT(_MS, KC_E)
#define M_NUMP MO(_NL)
#define T_SNAK TG(_SL)
#define T_NUMB TG(_NL)
#define T_VIL TG(_VI)
#define T_MSL TG(_MS)

#define OS_LCAG OSM(MOD_BIT(KC_LCTL) | MOD_BIT(KC_LGUI) | MOD_BIT(KC_LALT))
#define OS_HYPR OSM(MOD_BIT(KC_LCTL) | MOD_BIT(KC_LGUI) | MOD_BIT(KC_LALT) | MOD_BIT(KC_LSFT))

#define M_GC_ESC MT(MOD_LGUI|MOD_LCTL,KC_ESC)

#define OS_LAG  OSM(MOD_BIT(KC_LGUI) | MOD_BIT(KC_LALT))
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
// LED SECTION
// =============================================================================

#ifdef RGBLIGHT_ENABLE
// track led status
bool is_led_on = true;
// Light LEDs 6 to 9 and 12 to 15 red when caps lock is active. Hard to ignore!
const rgblight_segment_t PROGMEM my_capslock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {1, 0, HSV_RED},
    {1, 1, HSV_RED},
    {1, 2, HSV_RED},
    {1, 3, HSV_RED},
    {1, 4, HSV_RED},
    {1, 5, HSV_RED},
    {1, 6, HSV_RED},
    {1, 7, HSV_RED},
    {1, 8, HSV_RED}
);
const rgblight_segment_t PROGMEM my_layer1_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 0, HSV_CYAN}
);
// Light LEDs 11 & 12 in purple when keyboard layer 2 is active
const rgblight_segment_t PROGMEM my_layer2_layer[] = RGBLIGHT_LAYER_SEGMENTS(
            // capslock leds
    // if (host_keyboard_leds() & (1 << USB_LED_CAPS_LOCK)) {
    // {1, 1, HSV_RED},
    // {1, 4, HSV_RED},
    // {1, 6, HSV_RED},
    // {1, 7, HSV_RED},

    // {1, 0, HSV_CHARTREUSE},
    // {1, 2, HSV_CHARTREUSE},
    // {1, 3, HSV_CHARTREUSE},
    // {1, 5, HSV_CHARTREUSE},
    // {1, 8, HSV_CHARTREUSE}
    // }
    // else
    {1, 0, HSV_CHARTREUSE},
    {1, 1, HSV_CHARTREUSE},
    {1, 2, HSV_CHARTREUSE},
    {1, 3, HSV_CHARTREUSE},
    {1, 4, HSV_CHARTREUSE},
    {1, 5, HSV_CHARTREUSE},
    {1, 6, HSV_CHARTREUSE},
    {1, 7, HSV_CHARTREUSE},
    {1, 8, HSV_CHARTREUSE}
);
// Light LEDs 13 & 14 in green when keyboard layer 3 is active
const rgblight_segment_t PROGMEM my_layer3_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {1, 0, HSV_SPRINGGREEN},
    {1, 1, HSV_SPRINGGREEN},
    {1, 2, HSV_SPRINGGREEN},
    {1, 3, HSV_SPRINGGREEN},
    {1, 4, HSV_SPRINGGREEN},
    {1, 5, HSV_SPRINGGREEN},
    {1, 6, HSV_SPRINGGREEN},
    {1, 7, HSV_SPRINGGREEN},
    {1, 8, HSV_SPRINGGREEN}
);
// Light LEDs 13 & 14 in green when keyboard layer 3 is active
const rgblight_segment_t PROGMEM my_layer4_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {1, 0, HSV_GOLDENROD},
    {1, 1, HSV_GOLDENROD},
    {1, 2, HSV_GOLDENROD},
    {1, 3, HSV_GOLDENROD},
    {1, 4, HSV_GOLDENROD},
    {1, 5, HSV_GOLDENROD},
    {1, 6, HSV_GOLDENROD},
    {1, 7, HSV_GOLDENROD},
    {1, 8, HSV_GOLDENROD}
);
// Light LEDs 13 & 14 in green when keyboard layer 3 is active
const rgblight_segment_t PROGMEM my_layer5_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {1, 0, HSV_PINK},
    {1, 1, HSV_PINK},
    {1, 2, HSV_PINK},
    {1, 3, HSV_PINK},
    {1, 4, HSV_PINK},
    {1, 5, HSV_PINK},
    {1, 6, HSV_PINK},
    {1, 7, HSV_PINK},
    {1, 8, HSV_PINK}
);
const rgblight_segment_t PROGMEM my_layer6_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {1, 0, HSV_MAGENTA},
    {1, 1, HSV_MAGENTA},
    {1, 2, HSV_MAGENTA},
    {1, 3, HSV_MAGENTA},
    {1, 4, HSV_MAGENTA},
    {1, 5, HSV_MAGENTA},
    {1, 6, HSV_MAGENTA},
    {1, 7, HSV_MAGENTA},
    {1, 8, HSV_MAGENTA}
);
const rgblight_segment_t PROGMEM my_layer7_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {1, 0, HSV_BLUE},
    {1, 1, HSV_BLUE},
    {1, 2, HSV_BLUE},
    {1, 3, HSV_BLUE},
    {1, 4, HSV_BLUE},
    {1, 5, HSV_BLUE},
    {1, 6, HSV_BLUE},
    {1, 7, HSV_BLUE},
    {1, 8, HSV_BLUE}
);

// Now define the array of layers. Later layers take precedence
const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    my_capslock_layer,
    my_layer1_layer,    // Overrides caps lock layer
    my_layer2_layer,    // Overrides other layers
    my_layer3_layer,    // Overrides other layers
    my_layer4_layer,    // Overrides other layers
    my_layer5_layer,    // Overrides other layers
    my_layer6_layer,    // Overrides other layers
    my_layer7_layer     // Overrides other layers
);

void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = my_rgb_layers;
}

bool led_update_user(led_t led_state) {
    rgblight_set_layer_state(0, led_state.caps_lock);
    return true;
}

layer_state_t default_layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(1, layer_state_cmp(state, _BL));
    return state;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(2, layer_state_cmp(state, _SL));
    rgblight_set_layer_state(3, layer_state_cmp(state, _VI));
    rgblight_set_layer_state(4, layer_state_cmp(state, _NL));
    rgblight_set_layer_state(5, layer_state_cmp(state, _MS));
    rgblight_set_layer_state(6, layer_state_cmp(state, _FN));
    rgblight_set_layer_state(7, layer_state_cmp(state, _MD));
    return state;
}

/* void suspend_power_down_user(void) { */
/*     rgb_matrix_set_suspend_state(true); */
/* } */

/* void suspend_wakeup_init_user(void) { */
/*     rgb_matrix_set_suspend_state(false); */
/* } */
#endif

// =============================================================================
// MACRO SECTION
// =============================================================================

enum macros {
    SUSPEND = SAFE_RANGE
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
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

typedef struct {
    bool is_press_action;
    uint8_t state;
} tap;

enum {
    SINGLE_TAP = 1,
    SINGLE_HOLD,
    DOUBLE_TAP,
    DOUBLE_HOLD,
    DOUBLE_SINGLE_TAP, // Send two single taps
};

// Tap dance enums
enum {
    SL_HLP,
    SEMI_,
    B_F_DEL
};

uint8_t cur_dance(qk_tap_dance_state_t *state);

// =============================================================================
// TAPPING TERM PER KEY SECTION
// =============================================================================

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case LT(_MS,KC_E):
    case LT(_VI,KC_D):
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
        case LT(_MS, KC_E):
        case LT(_VI, KC_D):
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
// KEYMAP SECTION
// =============================================================================

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_BL] = LAYOUT_planck_mit(
    T_G_TAB, KC_Q,     KC_W,  L_MS_E,   KC_R,   KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    T_G_BSP,
    T_C_ESC, KC_A,     KC_S,  L_VI_D,   KC_F,   KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, T_C_QUO,
    KC_LSPO, KC_Z,     KC_X,  KC_C,     KC_V,   KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  TD_HELP, KC_RSFT,
    OS_HYPR, M_GC_ESC, LOWER, OS_LAG,   NUMPAD, T_A_SPC,          FN_LAY,  OS_LCAG, XXXXXXX, XXXXXXX, T_SG_EN
),
[_SL] = LAYOUT_planck_mit(
    T_G_TAB, KC_Q,     KC_W,  L_MS_E,   KC_R,   KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    T_G_BSP,
    T_C_ESC, KC_A,     KC_S,  L_VI_D,   KC_F,   KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, T_C_QUO,
    KC_LSPO, KC_Z,     KC_X,  KC_C,     KC_V,   KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  TD_HELP, KC_RSFT,
    OS_HYPR, M_GC_ESC, LOWER, OS_LAG,   NUMPAD, KC_UNDS,          FN_LAY,  OS_LCAG, XXXXXXX, XXXXXXX, T_SG_EN
),
[_NL] = LAYOUT_planck_mit(
    _______, XXXXXXX, XXXXXXX, _______,  XXXXXXX, XXXXXXX, XXXXXXX, KC_7,    KC_8,    KC_9,    KC_EQL,  _______,
    _______, KC_LGUI, KC_LALT, _______,  T_SHDOT, XXXXXXX,  XXXXXXX, KC_4,    KC_5,    KC_6,    KC_MINS, _______,
    _______, XXXXXXX, XXXXXXX, XXXXXXX,  T_NUMB,  XXXXXXX, XXXXXXX, KC_1,    KC_2,    KC_3,    KC_PSLS, XXXXXXX,
    _______, XXXXXXX, _______, _______,  _______, KC_0,             KC_SPC,  _______, XXXXXXX, XXXXXXX, _______
 ),
[_VI] = LAYOUT_planck_mit(
    _______, _______, _______, _______, _______, _______, KC_HOME, KC_PGDN,  KC_PGUP, KC_END,   XXXXXXX, T_SNAK,
    _______, KC_LCMD, KC_LALT, _______, KC_LSFT, KC_LEAD, KC_LEFT, KC_DOWN,  KC_UP,   KC_RIGHT, KC_F19,  KC_CAPS,
    _______, _______, _______, _______, T_VIL,   _______, DW_BKWD, KC_BSPC,  KC_DEL,  DW_FRWD,  TD_DEL,  _______,
    _______, _______, _______, _______, _______, _______,          _______,  _______, _______,  _______, _______
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
    SUSPEND, KC_TILD, KC_GRV,  KC_BSLS, KC_PIPE, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, DEBUG,   RGB_TOG,
    KC_BRIU, KC_LCBR, KC_LBRC, KC_RBRC, KC_RCBR, XXXXXXX, XXXXXXX, KC_LGUI, XXXXXXX, KC_BSPC, _______, XXXXXXX,
    KC_BRID, KC_UNDS, KC_LPRN, KC_RPRN, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_LSFT,
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
// TAP DANCE SECTION
// =============================================================================

uint8_t cur_dance(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    } else return 8;
}

// Create an instance of 'tap' for the 'x' tap dance.
static tap help_tap_state = {
    .is_press_action = true,
    .state = 0
};

void help_finished(qk_tap_dance_state_t *state, void *user_data) {
    help_tap_state.state = cur_dance(state);
    switch (help_tap_state.state) {
    case SINGLE_TAP:
        register_code(KC_SLSH);
        break;
    case DOUBLE_TAP:
        register_code(KC_LCMD);
        register_code(KC_LSFT);
        register_code(KC_SLSH);
    }
}

void help_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (help_tap_state.state) {
    case SINGLE_TAP:
        unregister_code(KC_SLSH);
        break;
    case DOUBLE_TAP:
        unregister_code(KC_LCMD);
        unregister_code(KC_LSFT);
        unregister_code(KC_SLSH);
    }
    help_tap_state.state = 0;
}

// Create an instance of 'tap' for the 'x' tap dance.
static tap semi_tap_state = {
    .is_press_action = true,
    .state = 0
};

void semi_finished(qk_tap_dance_state_t *state, void *user_data) {
    semi_tap_state.state = cur_dance(state);
    switch (semi_tap_state.state) {
    case SINGLE_TAP:
        register_code(KC_QUOT);
        // register_code(KC_SCLN);
        break;
    case DOUBLE_TAP:
        register_code(KC_SCLN);
        // register_code(KC_LSFT);
        // register_code(KC_MINS);
    }
}

void semi_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (semi_tap_state.state) {
    case SINGLE_TAP:
        // unregister_code(KC_SCLN);
        unregister_code(KC_QUOT);
        break;
    case DOUBLE_TAP:
        unregister_code(KC_SCLN);
        // unregister_code(KC_LSFT);
        // unregister_code(KC_MINS);
    }
    semi_tap_state.state = 0;
}

// Create an instance of 'tap' for the 'x' tap dance.
static tap bfdel_tap_state = {
    .is_press_action = true,
    .state = 0
};

void bfdel_finished(qk_tap_dance_state_t *state, void *user_data) {
    bfdel_tap_state.state = cur_dance(state);
    switch (bfdel_tap_state.state) {
        case SINGLE_TAP:
            register_code(KC_LCMD);
            register_code(KC_LSFT);
            tap_code(KC_LEFT);
            unregister_code(KC_LCMD);
            unregister_code(KC_LSFT);
            tap_code(KC_BSPC);
            break;
        case DOUBLE_TAP:
            register_code(KC_LCMD);
            register_code(KC_LSFT);
            tap_code(KC_RIGHT);
            unregister_code(KC_LCMD);
            unregister_code(KC_LSFT);
            tap_code(KC_BSPC);
    }
}

void bfdel_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (bfdel_tap_state.state) {
    case SINGLE_TAP:
        unregister_code(KC_BSPC);
        break;
    case DOUBLE_TAP:
        unregister_code(KC_BSPC);
    }
    bfdel_tap_state.state = 0;
}

qk_tap_dance_action_t tap_dance_actions[] = {
    [SL_HLP] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, help_finished, help_reset),
    [SEMI_]  = ACTION_TAP_DANCE_FN_ADVANCED(NULL, semi_finished, semi_reset),
    [B_F_DEL]  = ACTION_TAP_DANCE_FN_ADVANCED(NULL, bfdel_finished, bfdel_reset)
};


// =============================================================================
// LEADER KEY SECTION
// =============================================================================

LEADER_EXTERNS();

void matrix_scan_user(void) {
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
