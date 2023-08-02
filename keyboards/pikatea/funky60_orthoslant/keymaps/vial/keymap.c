/* Copyright 2020 Jack Kester
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

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
KC_TAB,   KC_W, KC_R, _______,       KC_Y, KC_I, KC_P,
KC_ESC,   KC_S, KC_F, _______,       KC_H, KC_K, KC_SCLN,
KC_LSFT,  KC_X, KC_V, _______,       KC_N, KC_COMM, KC_SLSH,
_______,  KC_LALT, _______, _______, KC_SPC, KC_LEFT, KC_UP,
KC_Q,     KC_E, KC_T, _______,       KC_U, KC_O, KC_BSPC,
KC_A,     KC_D, KC_G, _______,       KC_J, KC_L, KC_QUOT,
KC_Z,     KC_C, KC_B, KC_MUTE,       KC_M, KC_DOT, KC_ENT,
KC_LCTRL, KC_LWIN, KC_SPC, _______,  MO(1), KC_DOWN, KC_RIGHT
        ),
    [1] = LAYOUT(
_______, KC_2,     KC_4,   _______, KC_6,    KC_8,    KC_0,
_______, _______, _______, _______, _______, _______, _______,
_______, _______, _______, _______, _______, _______, _______,
_______, _______, _______, _______, _______, _______, _______,
KC_1,    KC_3,    KC_5,    _______, KC_7,    KC_9,    _______,
_______, _______, _______, _______, _______, _______, _______,
_______, _______, _______, _______, _______, _______, _______,
_______, _______, _______, _______, _______, _______, _______
        ),
    [2] = LAYOUT(
_______, _______, _______, _______, _______, _______, _______,
_______, _______, _______, _______, _______, _______, _______,
_______, _______, _______, _______, _______, _______, _______,
_______, _______, _______, _______, _______, _______, _______,
_______, _______, _______, _______, _______, _______, _______,
_______, _______, _______, _______, _______, _______, _______,
_______, _______, _______, _______, _______, _______, _______,
_______, _______, _______, _______, _______, _______, _______
        ),
    [3] = LAYOUT(
_______, _______, _______, _______, _______, _______, _______,
_______, _______, _______, _______, _______, _______, _______,
_______, _______, _______, _______, _______, _______, _______,
_______, _______, _______, _______, _______, _______, _______,
_______, _______, _______, _______, _______, _______, _______,
_______, _______, _______, _______, _______, _______, _______,
_______, _______, _______, _______, _______, _______, _______,
_______, _______, _______, _______, _______, _______, _______
        )
};


#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [0] =   { ENCODER_CCW_CW(KC_VOLD, KC_VOLU)   },
    [1] =  { ENCODER_CCW_CW(KC_VOLD, KC_VOLU)   },
    [2] =  { ENCODER_CCW_CW(KC_VOLD, KC_VOLU)   },
    [3] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU)   },
};
#endif
