#include QMK_KEYBOARD_H

#include "keymap.h"

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
// END TAPDANCE.C
// =============================================================================
