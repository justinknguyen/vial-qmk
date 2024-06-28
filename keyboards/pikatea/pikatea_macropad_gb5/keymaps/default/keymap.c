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
        KC_F15,  KC_F16,   KC_MEDIA_PREV_TRACK,    KC_MEDIA_PLAY_PAUSE,    KC_MEDIA_NEXT_TRACK,    KC_MUTE,
        KC_VOLD,   KC_VOLU
    ),
    [1] = LAYOUT(
        _______,   _______,   _______,    _______,    _______,    _______,
        _______,   _______
    ),
    [2] = LAYOUT(
        _______,   _______,   _______,    _______,    _______,    _______,
        _______,   _______
    ),
    [3] = LAYOUT(
        _______,   _______,   _______,    _______,    _______,    _______,
        _______,   _______
    )
};

#if defined(ENCODER_ENABLE)
bool encoder_update_kb(uint8_t index, bool clockwise) {
    if (!encoder_update_user(index, clockwise)) {
        return false;
    }

    //TODO: cvespa: figure out how to make this dynamic
    keypos_t a = { .col = 0, .row = 1 };
    keypos_t b = { .col = 1, .row = 1 };

    uint8_t currentLayer = get_highest_layer(layer_state);

    if (clockwise) {
        tap_code(keymap_key_to_keycode(currentLayer, a));
    } else {
        tap_code(keymap_key_to_keycode(currentLayer, b));
    }
    return true;
}
#endif

