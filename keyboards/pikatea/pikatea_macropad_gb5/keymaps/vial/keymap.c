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
    RGB_USER_GREEN = QK_KB_0,
    RGB_USER_RED,
    RGB_USER_BLUE,
    RGB_USER_WHITE,
    RGB_USER_YELLOW,
    RGB_USER_ORANGE,
    RGB_USER_CYAN,
    RGB_USER_PURPLE,
    RGB_USER_DEFAULT
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        KC_F15,  KC_F16,   KC_MEDIA_PREV_TRACK,    KC_MEDIA_PLAY_PAUSE,    KC_MEDIA_NEXT_TRACK,    KC_MUTE
    ),
    [1] = LAYOUT(
        _______,    _______,    _______,    _______,    _______,    _______
    ),
    [2] = LAYOUT(
        _______,    _______,    _______,    _______,    _______,    _______
    ),
    [3] = LAYOUT(
        _______,    _______,    _______,    _______,    _______,    _______
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

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case RGB_USER_GREEN:
            rgb_matrix_mode(RGB_MATRIX_CUSTOM_my_green_effect);
            return false;
        case RGB_USER_RED:
            rgb_matrix_mode(RGB_MATRIX_CUSTOM_my_red_effect);
            return false;
        case RGB_USER_BLUE:
            rgb_matrix_mode(RGB_MATRIX_CUSTOM_my_blue_effect);
            return false;
        case RGB_USER_WHITE:
            rgb_matrix_mode(RGB_MATRIX_CUSTOM_my_white_effect);
            return false;
        case RGB_USER_YELLOW:
            rgb_matrix_mode(RGB_MATRIX_CUSTOM_my_yellow_effect);
            return false;
        case RGB_USER_ORANGE:
            rgb_matrix_mode(RGB_MATRIX_CUSTOM_my_orange_effect);
            return false;
        case RGB_USER_CYAN:
            rgb_matrix_mode(RGB_MATRIX_CUSTOM_my_cyan_effect);
            return false;
        case RGB_USER_PURPLE:
            rgb_matrix_mode(RGB_MATRIX_CUSTOM_my_purple_effect);
            return false;
        case RGB_USER_DEFAULT:
            rgb_matrix_mode(RGB_MATRIX_SOLID_COLOR);
            return false;
        default:
            return true;
    }
}

void keyboard_post_init_user(void) {
  // Call the post init code.
  rgb_matrix_mode(RGB_MATRIX_SOLID_COLOR);
}
