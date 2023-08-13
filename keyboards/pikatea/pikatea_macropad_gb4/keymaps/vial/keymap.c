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
#include "rgb_matrix.h"
#include "color.h"

// use the names from vial.json
enum blender_keycode {
    RGB_USER_GREEN = QK_KB_0,
    RGB_USER_RED,
    RGB_USER_BLUE,
    RGB_USER_WHITE,
    RGB_USER_YELLOW,
    RGB_USER_ORANGE,
    RGB_USER_CYAN,
    RGB_USER_PURPLE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        KC_F13,   KC_F14,  KC_F15,  KC_F16,   KC_MEDIA_PREV_TRACK,    KC_MEDIA_PLAY_PAUSE,    KC_MEDIA_NEXT_TRACK,    KC_MUTE,
        KC_VOLU, KC_VOLD
    ),
    [1] = LAYOUT(
        _______,   _______,   _______,   _______,   _______,    _______,    _______,    _______,
        _______,   _______
    ),
    [2] = LAYOUT(
        _______,   _______,   _______,   _______,   _______,    _______,    _______,    _______,
        _______,   _______
    )
};

int KEY_CODE = RGB_USER_GREEN;
bool rgb_matrix_indicators_user() {
    switch (KEY_CODE) {
        case RGB_USER_GREEN:
            rgb_matrix_set_color_all(RGB_GREEN);
            break;
        case RGB_USER_RED:
            rgb_matrix_set_color_all(RGB_RED);
            break;
        case RGB_USER_BLUE:
           rgb_matrix_set_color_all(RGB_BLUE);
            break;
        case RGB_USER_WHITE:
            rgb_matrix_set_color_all(RGB_WHITE);
            break;
        case RGB_USER_YELLOW:
            rgb_matrix_set_color_all(RGB_YELLOW);
            break;
        case RGB_USER_ORANGE:
            rgb_matrix_set_color_all(RGB_ORANGE);
            break;
        case RGB_USER_CYAN:
            rgb_matrix_set_color_all(RGB_CYAN);
            break;
        case RGB_USER_PURPLE:
            rgb_matrix_set_color_all(RGB_PURPLE);
            break;
        default:
            return true;
    }

    return false;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case RGB_USER_GREEN:
        case RGB_USER_RED:
        case RGB_USER_BLUE:
        case RGB_USER_WHITE:
        case RGB_USER_YELLOW:
        case RGB_USER_ORANGE:
        case RGB_USER_CYAN:
        case RGB_USER_PURPLE:
            KEY_CODE = keycode;
            return false;
        default:
            return true;
    }
}
