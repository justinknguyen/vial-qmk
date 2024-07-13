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

// use the names from vial.json
enum blender_keycode {
    RGB_MY_EFFECT = QK_KB_0,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        KC_F15,  KC_F16,   KC_MEDIA_PREV_TRACK,    KC_MEDIA_PLAY_PAUSE,    KC_MEDIA_NEXT_TRACK,    KC_MUTE,
        KC_VOLU, KC_VOLD
    ),
    [1] = LAYOUT(
        _______,    _______,    _______,    _______,    _______,    _______,
        _______,    _______
    ),
    [2] = LAYOUT(
        _______,    _______,    _______,    _______,    _______,    _______,
        _______,    _______
    ),
    [3] = LAYOUT(
        _______,    _______,    _______,    _______,    _______,    _______,
        _______,    _______
    )
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [0] =   { ENCODER_CCW_CW(KC_VOLD, KC_VOLU),   },
    [1] =   { ENCODER_CCW_CW(_______, _______),   },
    [2] =   { ENCODER_CCW_CW(_______, _______),   },
    [3] =   { ENCODER_CCW_CW(_______, _______),   },
};
#endif