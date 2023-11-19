// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_beta_2(
        KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_SPC, 
		
		KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC, 
		KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS, KC_HOME, 
		KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT, KC_PGUP, 
		KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_LSFT, KC_NO, 
		KC_SPC, KC_SPC, KC_SPC, KC_LALT, KC_NO, KC_NO, KC_NO, KC_NO
    )
};
