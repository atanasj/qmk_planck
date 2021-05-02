/* Copyright 2020 tominabox1
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

enum layers {
  _BL,
  _VI,
  _NL,
  _MS,
  _FN
  /* _LOWER, */
  /* _RAISE, */
  /* _ADJUST */
};

#include "keymap_combo.h"

bool is_led_on = true;

/* #define LOWER MO(_LOWER) */
/* #define RAISE MO(_RAISE) */
#define LOWER MO(_NL)
#define RAISE MO(_FN)

// =============================================================================
// MACRO SECTION
// =============================================================================

enum macros {
    M_DBW = SAFE_RANGE,
    SUSPEND,
    M_DFW
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case KC_RSFT:
        /* fix space cadet shift */
        /* only right because LT() on left alphas */
        perform_space_cadet(record, KC_RSPC, KC_RSFT, KC_RSFT, KC_0);
        return false;
    case SUSPEND:
        if (record->event.pressed) {
            SEND_STRING(SS_LCTL(SS_LGUI("q")) SS_DELAY(500) SS_TAP(X_ESC));
            /* if(is_led_on) { */
            /*     is_led_on = false; */
            /*     /\* annepro2LedDisable(); *\/ */
            /* } */
        }
        return true;
    case M_DBW:
        if (record->event.pressed) {
            register_code(KC_LCMD);
            register_code(KC_LSFT);
            tap_code(KC_LEFT);
            unregister_code(KC_LCMD);
            unregister_code(KC_LSFT);
            tap_code(KC_BSPC);
        }
        return true;
    case M_DFW:
        if (record->event.pressed) {
            register_code(KC_LCMD);
            register_code(KC_LSFT);
            tap_code(KC_RIGHT);
            unregister_code(KC_LCMD);
            unregister_code(KC_LSFT);
            tap_code(KC_BSPC);
        }
        return true;
    default:
        if (record->event.pressed) {
            if(!is_led_on) {
                is_led_on = true;
                /* annepro2LedEnable(); */
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
    TRIPLE_TAP,
    TRIPLE_HOLD
};

// Tap dance enums
enum {
    /* META_DOWN, */
    /* SUPER_UP, */
    SL_HLP,
    SEMI_
};

uint8_t cur_dance(qk_tap_dance_state_t *state);

// =============================================================================
// TAPPING TERM PER KEY SECTION
// =============================================================================

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    /* case LT(_MS,KC_E): */
    /*     return 225; */
    case LT(_VI,KC_D):
        return 225;
    case RCTL_T(KC_ENT):
        return 350;
    /* case META_DOWN: */
    /*     return 165; */
    /* case SUPER_UP: */
    /*     return 165; */
    case SL_HLP:
        return 150;
    case KC_LSPO:
        return 127;
    case KC_RSPC:
        return 127;
    case SEMI_:
        return 155;
    default:
        return TAPPING_TERM;
    }
}

// =============================================================================
// MOD TAP INTERRUP PER KEY SECTION
// =============================================================================

bool get_ignore_mod_tap_interrupt(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case ALT_T(KC_SPC):
            return true;
        case KC_LSPO:
            return true;
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

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | BLTog| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_BL] = LAYOUT_planck_mit(
    LCMD_T(KC_TAB),  KC_Q,                         KC_W,                         LT(_MS,KC_E), KC_R,  KC_T,          KC_Y,  KC_U,            KC_I,    KC_O,   KC_P,      RCMD_T(KC_BSPC),
    LCTL_T(KC_ESC),  KC_A,                         KC_S,                         LT(_VI,KC_D), KC_F,  KC_G,          KC_H,  KC_J,            KC_K,    KC_L,   TD(SEMI_), RCTL_T(KC_QUOT),
    KC_LSPO,         KC_Z,                         KC_X,                         KC_C,         KC_V,  KC_B,          KC_N,  KC_M,            KC_COMM, KC_DOT, TD(SL_HLP),KC_RSFT,
    HYPR_T(RGB_TOG), MT(MOD_LGUI|MOD_LCTL,KC_ESC), MT(MOD_LGUI|MOD_LALT,KC_SPC), KC_LALT,      LOWER, ALT_T(KC_SPC), RAISE, LCAG_T(KC_LEFT), KC_DOWN, KC_UP,  SGUI_T(KC_RGHT)
),

  /* VI layer */
 [_VI] = LAYOUT_planck_mit(
    _______, _______, _______, _______, _______, _______, KC_HOME,    KC_PGDN,  KC_PGUP, KC_END,    XXXXXXX, XXXXXXX,
    _______, KC_LCMD, KC_LALT, _______, KC_LSFT, _______, KC_LEFT,    KC_DOWN,  KC_UP,   KC_RIGHT,  KC_F19,  KC_CAPS,
    XXXXXXX, MO(_NL), _______, _______, _______, M_DBW,   A(KC_BSPC), KC_BSPC,  KC_DEL,  A(KC_DEL), XXXXXXX, _______,
    _______, _______, _______, _______, _______,      _______,        _______,  _______, _______,   _______, _______
),
 /* NL layer */
 [_NL] = LAYOUT_planck_mit(
    XXXXXXX, XXXXXXX, XXXXXXX, _______,  XXXXXXX,         XXXXXXX, XXXXXXX, KC_7,    KC_8,    KC_9,    KC_EQL,  XXXXXXX,
    _______, KC_LGUI, KC_LALT, _______,  LSFT_T(KC_PDOT), XXXXXXX, XXXXXXX, KC_4,    KC_5,    KC_6,    KC_MINS, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  KC_LGUI,         XXXXXXX, XXXXXXX, KC_1,    KC_2,    KC_3,    KC_PSLS, XXXXXXX,
    XXXXXXX, XXXXXXX, _______, KC_0,     _______,         KC_0,             XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
 ),
 /* MS layer */
 [_MS] = LAYOUT_planck_mit(
    KC_ACL0, KC_ACL2, KC_ACL1, _______, KC_R,    XXXXXXX, KC_WH_L, KC_WH_U,    KC_WH_D, KC_WH_R, XXXXXXX, XXXXXXX,
    _______, KC_A,    KC_S,    XXXXXXX, XXXXXXX, XXXXXXX, KC_MS_L, KC_MS_D,    KC_MS_U, KC_MS_R, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, C(G(KC_D)), XXXXXXX, KC_BTN2, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,      KC_BTN1,     XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX
 ),
 /* FN layer */
 [_FN] = LAYOUT_planck_mit(
    XXXXXXX, S(KC_GRV),  KC_GRV,  KC_BSLS, S(KC_BSLS), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, S(KC_LBRC), KC_LBRC, KC_RBRC, S(KC_RBRC), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, XXXXXXX,
    XXXXXXX, S(KC_MINS), XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    RESET,   DEBUG,      RGB_TOG, RGB_MOD, RGB_HUI,    RGB_HUD,          RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, XXXXXXX
),
/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   +  |   {  |   }  |  |   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO ~ |ISO | | Home | End  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
/* [_LOWER] = LAYOUT_planck_mit( */
/*     KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR,    KC_ASTR,    KC_LPRN, KC_RPRN, KC_BSPC, */
/*     KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_UNDS,    KC_PLUS,    KC_LCBR, KC_RCBR, KC_PIPE, */
/*     _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  S(KC_NUHS), S(KC_NUBS), KC_HOME, KC_END,  _______, */
/*     _______, _______, _______, _______, _______, _______, _______,    KC_MNXT,    KC_VOLD, KC_VOLU, KC_MPLY */
/* ), */

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO # |ISO / |Pg Up |Pg Dn |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
/* [_RAISE] = LAYOUT_planck_mit( */
/*     KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, */
/*     KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS, */
/*     _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_NUHS, KC_NUBS, KC_PGUP, KC_PGDN, _______, */
/*     _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY */
/* ), */

/* Adjust (Lower + Raise)
 *                      v------------------------RGB CONTROL--------------------v
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset|Debug | RGB  |RGBMOD| HUE+ | HUE- | SAT+ | SAT- |BRGTH+|BRGTH-|  Del |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
/* [_ADJUST] = LAYOUT_planck_mit( */
/*     _______, RESET,   DEBUG,   RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD,  RGB_VAI, RGB_VAD, KC_DEL , */
/*     _______, _______, _______, _______, _______, _______, _______, _______,  _______,  _______, _______, _______, */
/*     _______, _______, _______, _______, _______, _______, _______, _______,  _______,  _______, _______, _______, */
/*     _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______ */
/* ) */

};

layer_state_t layer_state_set_user(layer_state_t state) {
  /* return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST); */
  return update_tri_layer_state(state, _VI, _NL, _FN);
}


// =============================================================================
/* // TAP DANCE SECTION */
/* // ============================================================================= */

uint8_t cur_dance(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    } if (state->count == 3) {
        if (state->interrupted || !state->pressed) return TRIPLE_TAP;
        else return TRIPLE_HOLD;
    } else return 8;
}

/* /\* // Create an instance of 'tap' for the 'meta' tap dance. *\/ */
/* /\* static tap meta_tap_state = { *\/ */
/* /\*     .is_press_action = true, *\/ */
/* /\*     .state = 0 *\/ */
/* /\* }; *\/ */

/* /\* void meta_finished(qk_tap_dance_state_t *state, void *user_data) { *\/ */
/* /\*     meta_tap_state.state = cur_dance(state); *\/ */
/* /\*     switch (meta_tap_state.state) { *\/ */
/* /\*     case SINGLE_TAP: *\/ */
/* /\*         register_code(KC_DOWN); *\/ */
/* /\*         break; *\/ */
/* /\*     case SINGLE_HOLD: *\/ */
/* /\*         register_code(KC_LSFT); *\/ */
/* /\*         register_code(KC_LALT); *\/ */
/* /\*         break; *\/ */
/* /\*     /\\* case DOUBLE_TAP: *\\/ *\/ */
/* /\*     /\\*     tap_code(KC_DOWN); *\\/ *\/ */
/* /\*     /\\*     register_code(KC_DOWN); *\\/ *\/ */
/* /\*     /\\*     break; *\\/ *\/ */
/* /\*     case DOUBLE_HOLD: *\/ */
/* /\*         register_code(KC_LSFT); *\/ */
/* /\*         register_code(KC_LALT); *\/ */
/* /\*         register_code(KC_LGUI); *\/ */
/* /\*         break; *\/ */
/* /\*     case DOUBLE_SINGLE_TAP: *\/ */
/* /\*         tap_code(KC_DOWN); *\/ */
/* /\*         register_code(KC_DOWN); *\/ */
/* /\*     } *\/ */
/* /\* } *\/ */

/* /\* void meta_reset(qk_tap_dance_state_t *state, void *user_data) { *\/ */
/* /\*     switch (meta_tap_state.state) { *\/ */
/* /\*     case SINGLE_TAP: *\/ */
/* /\*         unregister_code(KC_DOWN); *\/ */
/* /\*         break; *\/ */
/* /\*     case SINGLE_HOLD: *\/ */
/* /\*         unregister_code(KC_LSFT); *\/ */
/* /\*         unregister_code(KC_LALT); *\/ */
/* /\*         break; *\/ */
/* /\*     /\\* case DOUBLE_TAP: *\\/ *\/ */
/* /\*     /\\*     unregister_code(KC_DOWN); *\\/ *\/ */
/* /\*     /\\*     break; *\\/ *\/ */
/* /\*     case DOUBLE_HOLD: *\/ */
/* /\*         unregister_code(KC_LSFT); *\/ */
/* /\*         unregister_code(KC_LALT); *\/ */
/* /\*         unregister_code(KC_LGUI); *\/ */
/* /\*         break; *\/ */
/* /\*     case DOUBLE_SINGLE_TAP: *\/ */
/* /\*         unregister_code(KC_DOWN); *\/ */
/* /\*     } *\/ */
/* /\*     meta_tap_state.state = 0; *\/ */
/* /\* } *\/ */

/* /\* // Create an instance of 'tap' for the 'meta' tap dance. *\/ */
/* /\* static tap super_tap_state = { *\/ */
/* /\*     .is_press_action = true, *\/ */
/* /\*     .state = 0 *\/ */
/* /\* }; *\/ */

/* /\* void super_finished(qk_tap_dance_state_t *state, void *user_data) { *\/ */
/* /\*     super_tap_state.state = cur_dance(state); *\/ */
/* /\*     switch (super_tap_state.state) { *\/ */
/* /\*     case SINGLE_TAP: *\/ */
/* /\*         register_code(KC_UP); *\/ */
/* /\*         break; *\/ */
/* /\*     case SINGLE_HOLD: *\/ */
/* /\*         register_code(KC_LSFT); *\/ */
/* /\*         register_code(KC_LCTL); *\/ */
/* /\*         break; *\/ */
/* /\*     /\\* case DOUBLE_TAP: *\\/ *\/ */
/* /\*     /\\*     tap_code(KC_UP); *\\/ *\/ */
/* /\*     /\\*     register_code(KC_UP); *\\/ *\/ */
/* /\*     /\\*     break; *\\/ *\/ */
/* /\*     case DOUBLE_HOLD: *\/ */
/* /\*         register_code(KC_LSFT); *\/ */
/* /\*         register_code(KC_LCTL); *\/ */
/* /\*         register_code(KC_LGUI); *\/ */
/* /\*         break; *\/ */
/* /\*     case DOUBLE_SINGLE_TAP: *\/ */
/* /\*         tap_code(KC_UP); *\/ */
/* /\*         register_code(KC_UP); *\/ */
/* /\*     } *\/ */
/* /\* } *\/ */

/* /\* void super_reset(qk_tap_dance_state_t *state, void *user_data) { *\/ */
/* /\*     switch (super_tap_state.state) { *\/ */
/* /\*     case SINGLE_TAP: unregister_code(KC_UP); break; *\/ */
/* /\*     case SINGLE_HOLD: *\/ */
/* /\*         unregister_code(KC_LSFT); *\/ */
/* /\*         unregister_code(KC_LCTL); *\/ */
/* /\*         break; *\/ */
/* /\*     /\\* case DOUBLE_TAP: *\\/ *\/ */
/* /\*     /\\*     unregister_code(KC_DOWN); *\\/ *\/ */
/* /\*     /\\*     break; *\\/ *\/ */
/* /\*     case DOUBLE_HOLD: *\/ */
/* /\*         unregister_code(KC_LSFT); *\/ */
/* /\*         unregister_code(KC_LCTL); *\/ */
/* /\*         unregister_code(KC_LGUI); *\/ */
/* /\*         break; *\/ */
/* /\*     case DOUBLE_SINGLE_TAP: *\/ */
/* /\*         unregister_code(KC_UP); *\/ */
/* /\*     } *\/ */
/* /\*     super_tap_state.state = 0; *\/ */
/* /\* } *\/ */

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
        /* case SINGLE_HOLD: register_code(KC_LCTRL); break; */
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
        /* case SINGLE_HOLD: unregister_code(KC_LCTRL); break; */
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
        register_code(KC_SCLN);
        break;
    case SINGLE_HOLD:
        layer_on(_FN);
        break;
    case DOUBLE_TAP:
        register_code(KC_LSFT);
        register_code(KC_MINS);
    }
}

void semi_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (semi_tap_state.state) {
    case SINGLE_TAP:
        unregister_code(KC_SCLN);
        break;
    case SINGLE_HOLD:
        layer_off(_FN);
        break;
    case DOUBLE_TAP:
        unregister_code(KC_LSFT);
        unregister_code(KC_MINS);
    }
    semi_tap_state.state = 0;
}

qk_tap_dance_action_t tap_dance_actions[] = {
    /* [META_DOWN] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, meta_finished, meta_reset), */
    /* [SUPER_UP] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, super_finished, super_reset), */
    [SL_HLP] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, help_finished, help_reset),
    [SEMI_]  = ACTION_TAP_DANCE_FN_ADVANCED(NULL, semi_finished, semi_reset)
};

// =============================================================================
// LEADER KEY SECTION
// =============================================================================

LEADER_EXTERNS();

void matrix_scan_user(void) {
    LEADER_DICTIONARY() {
        leading = false;
        leader_end();
        // NOTE in built R operators
        SEQ_ONE_KEY(KC_A) {
            /* needs to a as semi colon is a tap dance key */
            SEND_STRING(" <-");
        }
        SEQ_ONE_KEY(KC_P) {
            SEND_STRING(" %>%");
        }
        SEQ_ONE_KEY(KC_I) {
            SEND_STRING(" %in% ");
        }
        SEQ_ONE_KEY(KC_N) {
            SEND_STRING(" %!in% ");
        }
    }
}

// =============================================================================
// END KEYMAP.C
// =============================================================================
