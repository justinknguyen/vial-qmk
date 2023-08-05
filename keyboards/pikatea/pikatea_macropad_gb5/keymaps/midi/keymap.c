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
#include "keycodes.h"
#include "keymap_common.h"
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

#define LAYOUT_midi( \
    k00, k01, k02, k03, k04, k05, k06, k07,  \
    E00A, E00B \
) \
{ \
    { k00, k01, k02, k03, k04, k05, k06, k07 }, \
    { E00A, E00B } \
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_midi(
        TO(6),   TO(5),  TO(4),  TO(3),   TO(2),  TO(1),  TO(0),    KC_MUTE,
        KC_VOLU, KC_VOLD
    ),
    [1] = LAYOUT_midi(
        _______,   _______,   _______,   _______,   _______,    _______,    _______,    _______,
        _______,    _______
    ),
    [2] = LAYOUT_midi(
        _______,   _______,   _______,   _______,   _______,    _______,    _______,    _______,
        _______,    _______
    ),
    [3] = LAYOUT_midi(
        _______,   _______,   _______,   _______,   _______,    _______,    _______,    _______,
        _______,    _______
    ),
    [4] = LAYOUT_midi(
        _______,   _______,   _______,   _______,   _______,    _______,    _______,    _______,
        _______,    _______
    ),
    [5] = LAYOUT_midi(
        _______,   _______,   _______,   _______,   _______,    _______,    _______,    _______,
        _______,    _______
    ),
    [6] = LAYOUT_midi(
        _______,   _______,   _______,   _______,   _______,    _______,    _______,    _______,
        _______,    _______
    ),
    [7] = LAYOUT_midi(
        _______,   _______,   _______,   _______,   _______,    _______,    _______,    _______,
        _______,    _______
    )
};

//create a virtual Midi Slider with the encoder
bool encoder_update_user(uint8_t index, bool clockwise) {
    keypos_t a = { .col = 0, .row = 1 };
    keypos_t b = { .col = 1, .row = 1 };
    if (keymap_key_to_keycode(0, a) == KC_VOLD && keymap_key_to_keycode(0, b) == KC_VOLU) {
        clockwise = !clockwise;
    }

    if (clockwise) {
        val[currentLayer] = val[currentLayer] + stepAmount;
        if (val[currentLayer] > 127) {
            val[currentLayer] = 127;
        }
        midi_send_cc(&midi_device, currentLayer+1, 7, val[currentLayer]);
    } else {
        val[currentLayer] = val[currentLayer] - stepAmount;
        if (val[currentLayer] < 0) {
            val[currentLayer] = 0;
        }
        midi_send_cc(&midi_device, currentLayer+1, 7, val[currentLayer]);
    }
    //We do not want to contiune. we have handled this action
    return false;
}

//save the layer state to a variable
layer_state_t layer_state_set_user(layer_state_t state) {
    currentLayer = get_highest_layer(state);
    return state;
}
