#include QMK_KEYBOARD_H

typedef enum {
    SINGLE_TAP        = 1,
    SINGLE_HOLD       = 2,
    DOUBLE_TAP        = 3,
    DOUBLE_HOLD       = 4,
    DOUBLE_SINGLE_TAP = 5, // send two single taps
    TRIPLE_TAP        = 6,
    TRIPLE_HOLD       = 7,
    TRIPLE_SINGLE_TAP = 8 // send three single taps
} td_state_t;

// static td_state_t td_state;

// int cur_dance(qk_tap_dance_state_t *state);

enum {
    SLN = 0,
    CBR,
    PRN,
    BRC,
    TD_I,
    TD_Q,
    CTLBW,
    M_L2,
    M_L3,
    M_L4,
    M_R1,
    M_R2
};

// void mainl2_finished (qk_tap_dance_state_t *state, void *user_data);
// void mainl2_reset (qk_tap_dance_state_t *state, void *user_data);

// void q_finished(qk_tap_dance_state_t *state, void *user_data);
// void q_reset(qk_tap_dance_state_t *state, void *user_data);

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = LAYOUT(
		KC_ESC, 	KC_EXLM,	GUI_C,		GUI_V,		KC_0,		KC_CIRC,							KC_DLR,		KC_AMPR,	KC_ASTR,	KC_EQL,		KC_HASH,	KC_BSPC,
		KC_TAB,		KC_Q,		KC_H,		KC_O,		KC_U,		KC_MINS,							KC_G,		KC_C,		KC_M,		KC_R,		KC_V,		KC_SLSH,
		KC_GRV,		MAIN_L1,	MAIN_L2,	MAIN_L3,	MAIN_L4,	KC_DOT,								KC_D,		MAIN_R1,	MAIN_R2,	MAIN_R3,	MAIN_R4,	KC_QUOT,
		KC_BSLS,	BOTT_L1,	BOTT_L2,	BOTT_L3,	BOTT_L4,	TD(SLN),	THMB_L3,	THMB_R1,	KC_W,		BOTT_R1,	BOTT_R2,	BOTT_R3,	BOTT_R4,	KC_PERC,
                                                                KC_AT, THMB_L2, THMB_L3,	THMB_R1, CTL_B, CTL_W
		),
	[1] = LAYOUT(
		___T___,	___X___,	___X___,	KC_MUTE,	___X___,	___X___,							___X___,	___X___,	GUI_UP,		___X___,	___X___,	___T___,
		___T___,	___X___,	KC_VOLD,	KC_UP,		KC_VOLU,	TD(CBR),							___X___,	ALT_LFT,	KC_UP,		ALT_RGT,	___X___,	___T___,
		___T___,	___X___,	KC_LEFT,	KC_DOWN,	KC_RIGHT,	TD(PRN),							GUI_LFT,	KC_LEFT,	KC_DOWN,	KC_RGHT,	GUI_RGT,	___T___,
		___T___,	NAV_L1,		NAV_L2,		NAV_L3,		NAV_L4,		TD(BRC),	___T___,	___X___,	___X___,	CTL_LFT,	GUI_DWN,	CTL_RGT,	___X___,	___T___,
		                                                      ___X___, ___X___, ___T___,	___X___, ___T___, ___T___
		),
	[2] = LAYOUT(
		___T___,	___X___,	___X___,	LSFT_F8,	___X___,	___X___,							___X___,	___X___,	___X___,	___X___,	___X___,	___T___,
		___T___,	KC_F10,		KC_F7,		KC_F8,		KC_F9,		___X___,							KC_PLUS,	KC_7,		KC_8,		KC_9,		___X___,	___T___,
		___T___,	KC_F11,		KC_F4,		KC_F5,		KC_F6,		___X___,							KC_MINS,	KC_4,		KC_5,		KC_6,		___X___,	___T___,
		___T___,	FNNUM_L1,	FNNUM_L2,	FNNUM_L3,	FNNUM_L4,	___X___,	___X___,	___T___,	KC_EQL,		FNNUM_R1,	FNNUM_R2,	FNNUM_R3,	FNNUM_R4,	___T___,
		                                                      ___X___, ___X___, ___X___,	___T___, KC_0, KC_DOT
		),
	[3] = LAYOUT(
		___T___,	___T___,	___T___,	___T___,	___T___,	___T___,							___X___,	___X___,	___X___,	___X___,	___X___,	___T___,
		___T___,	___X___,	KC_7,		KC_8,		KC_9,		___X___,							___X___,	___X___,	___X___,	___X___,	___X___,	___T___,
		___T___,	___X___,	KC_4,		KC_5,		KC_6,		___X___,							___X___,	___X___,	___X___,	___X___,	___X___,	___T___,
		___T___,	___X___,	KC_1,		KC_2,		KC_3,		___X___,	___X___,	___X___,	___X___,	KC_RGUI,	KC_RSFT,	KC_LALT,	KC_LCTL,	___T___,
		                                                      ___X___, ___T___, ___X___,	___X___, ___X___, ___X___
		)
};

// int cur_dance(qk_tap_dance_state_t *state) {
//     if (state->count == 1) {
//         if (state->interrupted || !state->pressed)
//             return SINGLE_TAP;
//         else
//             return SINGLE_HOLD;
//     } else if (state->count == 2) {
//         if (state->interrupted)
//             return DOUBLE_SINGLE_TAP;
//         else if (state->pressed)
//             return DOUBLE_HOLD;
//         else
//             return DOUBLE_TAP;
//     } else if (state->count == 3) {
//         if (state->interrupted)
//             return TRIPLE_SINGLE_TAP;
//         else if (state->pressed)
//             return TRIPLE_HOLD;
//         else
//             return TRIPLE_TAP;
//     } else
//         return 9;
// }

// void q_finished(qk_tap_dance_state_t *state, void *user_data) {
//     td_state = cur_dance(state);
//     if (td_state == SINGLE_TAP) {
//         register_code(KC_Q);
//         register_code(KC_U);
//     } else {
//         register_code(KC_Q);
//     }
// }

// void q_reset(qk_tap_dance_state_t *state, void *user_data) {
//     if (td_state == SINGLE_TAP) {
//         unregister_code(KC_Q);
//         unregister_code(KC_U);
//     } else {
//         unregister_code(KC_Q);
//     }
//     td_state = 0;
// }

// void mainl2_finished(qk_tap_dance_state_t *state, void *user_data) {
//     td_state = cur_dance(state);
//     switch (td_state) {
//         case SINGLE_TAP:
//             register_code(KC_I);
//             break;
//         case SINGLE_HOLD:
//             register_mods(MOD_BIT(KC_LALT));
//             break;
//         case DOUBLE_TAP:
//         case DOUBLE_SINGLE_TAP:
//             register_code16(LSFT(KC_I));
//             break;
//         case DOUBLE_HOLD:
//             register_code(KC_I);
//             unregister_code(KC_I);
//             register_code(KC_I);
//             break;
//         case TRIPLE_TAP:
//         case TRIPLE_HOLD:
//             register_code16(LSFT(KC_I));
//             break;
//         case TRIPLE_SINGLE_TAP:
//             register_code(KC_I);
//             unregister_code(KC_I);
//             register_code(KC_I);
//             unregister_code(KC_I);
//             register_code(KC_I);
//             break;
//     }
// }

// void mainl2_reset(qk_tap_dance_state_t *state, void *user_data) {
//     switch (td_state) {
//         case SINGLE_TAP:
//             unregister_code(KC_I);
//             break;
//         case SINGLE_HOLD:
//             unregister_mods(MOD_BIT(KC_LALT));
//             break;
//         case DOUBLE_TAP:
//         case DOUBLE_SINGLE_TAP:
//             unregister_code16(LSFT(KC_I));
//             break;
//         case DOUBLE_HOLD:
//             unregister_code(KC_I);
//             break;
//         case TRIPLE_TAP:
//         case TRIPLE_HOLD:
//             unregister_code16(LSFT(KC_I));
//             break;
//         case TRIPLE_SINGLE_TAP:
//             unregister_code(KC_I);
//             break;
//     }
//     td_state = 0;
// }

// void mainl3_finished(qk_tap_dance_state_t *state, void *user_data) {
//     td_state = cur_dance(state);
//     switch (td_state) {
//         case SINGLE_TAP:
//             register_code(KC_E);
//             break;
//         case SINGLE_HOLD:
//             register_mods(MOD_BIT(KC_LSFT));
//             break;
//         case DOUBLE_TAP:
//         case DOUBLE_HOLD:
//         case DOUBLE_SINGLE_TAP:
//             register_code(KC_E);
//             unregister_code(KC_E);
//             register_code(KC_E);
//             break;
//         case TRIPLE_TAP:
//         case TRIPLE_HOLD:
//             register_code16(LSFT(KC_E));
//             break;
//         case TRIPLE_SINGLE_TAP:
//             register_code(KC_E);
//             unregister_code(KC_E);
//             register_code(KC_E);
//             unregister_code(KC_E);
//             register_code(KC_E);
//             break;
//     }
// }

// void mainl3_reset(qk_tap_dance_state_t *state, void *user_data) {
//     switch (td_state) {
//         case SINGLE_TAP:
//             unregister_code(KC_E);
//             break;
//         case SINGLE_HOLD:
//             unregister_mods(MOD_BIT(KC_LSFT));
//             break;
//         case DOUBLE_TAP:
//         case DOUBLE_HOLD:
//         case DOUBLE_SINGLE_TAP:
//             unregister_code(KC_E);
//             break;
//         case TRIPLE_TAP:
//         case TRIPLE_HOLD:
//             unregister_code16(LSFT(KC_E));
//             break;
//         case TRIPLE_SINGLE_TAP:
//             unregister_code(KC_E);
//             break;
//     }
//     td_state = 0;
// }

qk_tap_dance_action_t tap_dance_actions[] = {
    [SLN] = ACTION_TAP_DANCE_DOUBLE(KC_COLN, KC_SCLN),
    [CBR] = ACTION_TAP_DANCE_DOUBLE(KC_LCBR, KC_RCBR),
    [PRN] = ACTION_TAP_DANCE_DOUBLE(KC_LPRN, KC_RPRN),
    [BRC] = ACTION_TAP_DANCE_DOUBLE(KC_LBRC, KC_RBRC),
    // [TD_I]  = ACTION_TAP_DANCE_DOUBLE(KC_I, LSFT(KC_I)),
    // [TD_Q]  = ACTION_TAP_DANCE_FN_ADVANCED(NULL, q_finished, q_reset),
    // [CTLBW] = ACTION_TAP_DANCE_DOUBLE(CTL_B, CTL_W),
    // [M_L2]  = ACTION_TAP_DANCE_FN_ADVANCED(NULL, mainl2_finished, mainl2_reset),
    // [M_L3]  = ACTION_TAP_DANCE_FN_ADVANCED(NULL, mainl3_finished, mainl3_reset),
    // [M_L4]  = ACTION_TAP_DANCE_FN_ADVANCED(NULL, mainl4_finished, mainl4_reset),
    // [M_R1]  = ACTION_TAP_DANCE_FN_ADVANCED(NULL, mainr1_finished, mainr1_reset),
    // [M_R2]  = ACTION_TAP_DANCE_FN_ADVANCED(NULL, mainr2_finished, mainr2_reset),
};
