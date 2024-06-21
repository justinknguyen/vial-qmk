/* Copyrigh 2022 Jack Kester
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
#include "action_layer.h"
#include "keycodes.h"
#include "keymap_common.h"
#include "midi.h"

#include QMK_KEYBOARD_H

/*
The full midi emulates a Midi slider with the enocder. Changing layers
changes the Midi channel used. Compatible with VIA.
*/

extern MidiDevice midi_device;
// Store value
int val[8] = {0,0,0,0,0,0,0,0};
// Step amount
int stepAmount = 2;
// store current layer
int currentLayer = 0;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        TO(4),  TO(3),  TO(2),  TO(1),  TO(0),  KC_MUTE
    ),
    [1] = LAYOUT(
        _______,    _______,    _______,    _______,    _______,    _______
    ),
    [2] = LAYOUT(
        _______,    _______,    _______,    _______,    _______,    _______
    ),
    [3] = LAYOUT(
        _______,    _______,    _______,    _______,    _______,    _______
    ),
    [4] = LAYOUT(
        _______,    _______,    _______,    _______,    _______,    _______
    ),
    [5] = LAYOUT(
        _______,    _______,    _______,    _______,    _______,    _______
    ),
    [6] = LAYOUT(
        _______,    _______,    _______,    _______,    _______,    _______
    ),
    [7] = LAYOUT(
        _______,    _______,    _______,    _______,    _______,    _______
    )
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [0] =   { ENCODER_CCW_CW(KC_VOLD, KC_VOLU),   },
    [1] =   { ENCODER_CCW_CW(_______, _______),   },
    [2] =   { ENCODER_CCW_CW(_______, _______),   },
    [3] =   { ENCODER_CCW_CW(_______, _______),   },
    [4] =   { ENCODER_CCW_CW(_______, _______),   },
    [5] =   { ENCODER_CCW_CW(_______, _______),   },
    [6] =   { ENCODER_CCW_CW(_______, _______),   },
    [7] =   { ENCODER_CCW_CW(_______, _______),   },
};
#endif

//save the layer state to a variable
layer_state_t layer_state_set_user(layer_state_t state) {
    currentLayer = get_highest_layer(state);
    return state;
}
