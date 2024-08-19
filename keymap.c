#include "action_layer.h"
#include QMK_KEYBOARD_H

enum tapdance_actions {
    TD_ESC_GRV,
};
enum layer_names {
    L_BASE,
    L_FN,
    L_CODE,
    L_NUM_SYM,
};

tap_dance_action_t tap_dance_actions[] = {
    [TD_ESC_GRV] = ACTION_TAP_DANCE_DOUBLE(KC_ESC, KC_GRV),
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [L_BASE] = LAYOUT_planck_mit(
        TD(TD_ESC_GRV), KC_Q,  KC_W,    KC_E,    KC_R,    KC_T,   KC_Y,    KC_U,  KC_I,    KC_O,    KC_P,    KC_BSPC,
        KC_TAB,         KC_A,  KC_S,    KC_D,    KC_F,    KC_G,   KC_H,    KC_J,  KC_K,    KC_L,    KC_SCLN, KC_ENT,
        KC_LSFT,        KC_Z,  KC_X,    KC_C,    KC_V,    KC_B,   KC_N,    KC_M,  KC_COMM, KC_DOT,  KC_UP,   LSFT_T(KC_SLSH),
        KC_LCTL,        MO(2), KC_LALT, KC_LGUI, KC_PGDN, KC_SPC,          KC_PGUP, MO(1), KC_LEFT, KC_DOWN, KC_RGHT
    ),

    [L_FN] = LAYOUT_planck_mit(
        KC_TRNS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  RGB_MOD,
        KC_TRNS, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    RGB_RMOD,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MSTP, KC_MUTE, KC_MPRV, KC_MPLY, KC_MNXT, RGB_VAI, RGB_TOG,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, RGB_VAD, RGB_M_P
    ),

    [L_CODE] = LAYOUT_planck_mit(
        KC_TRNS, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
        KC_TRNS, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_TRNS,
        KC_TRNS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
        KC_TRNS, KC_NO,   KC_LALT, KC_DEL,  KC_PGDN, KC_SPC,           KC_PGUP, QK_BOOT, KC_LEFT, KC_DOWN, KC_RGHT
    )

};
// clang-format on

bool rgb_matrix_indicators_user(void) {
    switch (get_highest_layer(layer_state)) {
        case 1:
            rgb_matrix_set_color(0, RGB_BLUE);
            break;
        case 2:
            rgb_matrix_set_color(0, RGB_GREEN);
            break;
        case 3:
            rgb_matrix_set_color(0, RGB_MAGENTA);
            break;
        case 4:
            rgb_matrix_set_color(0, RGB_ORANGE);
            break;
    }

    return true;
}
