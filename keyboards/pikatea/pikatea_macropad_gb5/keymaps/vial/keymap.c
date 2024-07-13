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

enum blender_keycode {
    M1 = QK_KB_0,
    M2,
    M3,
    M4,
    M5,
    M6,
    M7
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        M1, M2, M3, M4, M5, KC_SLEP, 
        M6, M7
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
    [0] =   { ENCODER_CCW_CW(M6, M7),   },
    [1] =   { ENCODER_CCW_CW(_______, _______),   },
    [2] =   { ENCODER_CCW_CW(_______, _______),   },
    [3] =   { ENCODER_CCW_CW(_______, _______),   },
};
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case M1:
            if (record->event.pressed) {
                // Macro 1: Ctrl + Alt + Shift + Left, Delay, Release
                register_code(KC_LCTL);
                register_code(KC_LALT);
                register_code(KC_LSFT);
                register_code(KC_LEFT);
                wait_ms(100);
            } else {
                unregister_code(KC_LCTL);
                unregister_code(KC_LALT);
                unregister_code(KC_LSFT);
                unregister_code(KC_LEFT);
            }
            break;
        case M2:
            if (record->event.pressed) {
                // Macro 2: Ctrl + Alt + Shift + P, Delay, Release
                register_code(KC_LCTL);
                register_code(KC_LALT);
                register_code(KC_LSFT);
                register_code(KC_P);
                wait_ms(100);
            } else {
                unregister_code(KC_LCTL);
                unregister_code(KC_LALT);
                unregister_code(KC_LSFT);
                unregister_code(KC_P);
            }
            break;
        case M3:
            if (record->event.pressed) {
                // Macro 3: Ctrl + Alt + Shift + Right, Delay, Release
                register_code(KC_LCTL);
                register_code(KC_LALT);
                register_code(KC_LSFT);
                register_code(KC_RGHT);
                wait_ms(100);
            } else {
                unregister_code(KC_LCTL);
                unregister_code(KC_LALT);
                unregister_code(KC_LSFT);
                unregister_code(KC_RGHT);
            }
            break;
        case M4:
            if (record->event.pressed) {
                // Macro 4: Ctrl + GUI + KP_1, Delay, Release
                register_code(KC_LCTL);
                register_code(KC_LGUI);
                register_code(KC_KP_1);
                wait_ms(100);
            } else {
                unregister_code(KC_LCTL);
                unregister_code(KC_LGUI);
                unregister_code(KC_KP_1);
            }
            break;
        case M5:
            if (record->event.pressed) {
                // Macro 5: Ctrl + Alt + Shift + A, Delay, Release
                register_code(KC_LCTL);
                register_code(KC_LALT);
                register_code(KC_LSFT);
                register_code(KC_A);
                wait_ms(100);
            } else {
                unregister_code(KC_LCTL);
                unregister_code(KC_LALT);
                unregister_code(KC_LSFT);
                unregister_code(KC_A);
            }
            break;
        case M6:
            if (record->event.pressed) {
                // Macro 6: Ctrl + Alt + Shift + Down, Delay, Release
                register_code(KC_LCTL);
                register_code(KC_LALT);
                register_code(KC_LSFT);
                register_code(KC_DOWN);
                wait_ms(100);
            } else {
                unregister_code(KC_LCTL);
                unregister_code(KC_LALT);
                unregister_code(KC_LSFT);
                unregister_code(KC_DOWN);
            }
            break;
            
        case M7:
            if (record->event.pressed) {
                // Macro 7: Ctrl + Alt + Shift + Up, Delay, Release
                register_code(KC_LCTL);
                register_code(KC_LALT);
                register_code(KC_LSFT);
                register_code(KC_UP);
                wait_ms(100);
            } else {
                unregister_code(KC_LCTL);
                unregister_code(KC_LALT);
                unregister_code(KC_LSFT);
                unregister_code(KC_UP);
            }
            break;
    }
    return true;
}