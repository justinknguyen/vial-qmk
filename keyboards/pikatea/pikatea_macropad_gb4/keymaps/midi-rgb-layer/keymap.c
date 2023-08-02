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
#include QMK_KEYBOARD_H

/*
The full midi emulates a Midi slider with the enocder. Changing layers
changes the Midi channel used. Compatible with VIA.
*/

extern MidiDevice midi_device;
// Store value
int val[8] = {
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0
};
// Step amount
int stepAmount = 2;
// store current layer
int currentLayer = 0;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_all(
        TO(0),   TO(1),  TO(2),  TO(3),   TO(4),    TO(5),    TO(6),    KC_MUTE
    ),
    [1] = LAYOUT_all(
        _______,   _______,   _______,   _______,   _______,    _______,    _______,    _______
    ),
    [2] = LAYOUT_all(
        _______,   _______,   _______,   _______,   _______,    _______,    _______,    _______
    ),
    [3] = LAYOUT_all(
        _______,   _______,   _______,   _______,   _______,    _______,    _______,    _______
    ),
    [4] = LAYOUT_all(
        _______,   _______,   _______,   _______,   _______,    _______,    _______,    _______
    ),
    [5] = LAYOUT_all(
        _______,   _______,   _______,   _______,   _______,    _______,    _______,    _______
    ),
    [6] = LAYOUT_all(
        _______,   _______,   _______,   _______,   _______,    _______,    _______,    _______
    ),
    [7] = LAYOUT_all(
        _______,   _______,   _______,   _______,   _______,    _______,    _______,    _______
    )
};

//create a virtual Midi Slider with the encoder
bool encoder_update_user(uint8_t index, bool clockwise) {
    if (!clockwise) {
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
    return true;
};

// Light LEDs 0 when layer 0 is active.
const rgblight_segment_t PROGMEM my_layer0[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 1, HSV_WHITE}
);

// Light LEDs 1 when layer 1 is active.
const rgblight_segment_t PROGMEM my_layer1[] = RGBLIGHT_LAYER_SEGMENTS(
    {1, 1, HSV_WHITE}
);

// Light LEDs 2 when layer 2 is active.
const rgblight_segment_t PROGMEM my_layer2[] = RGBLIGHT_LAYER_SEGMENTS(
    {2, 1, HSV_WHITE}
);

// Light LEDs 3 when layer 3 is active.
const rgblight_segment_t PROGMEM my_layer3[] = RGBLIGHT_LAYER_SEGMENTS(
    {3, 1, HSV_WHITE}
);

// Light LEDs 4 when layer 4 is active.
const rgblight_segment_t PROGMEM my_layer4[] = RGBLIGHT_LAYER_SEGMENTS(
    {4, 1, HSV_WHITE}
);

// Light LEDs 5 when layer 5 is active.
const rgblight_segment_t PROGMEM my_layer5[] = RGBLIGHT_LAYER_SEGMENTS(
    {5, 1, HSV_WHITE}
);

// Light LEDs 6 when layer 6 is active.
const rgblight_segment_t PROGMEM my_layer6[] = RGBLIGHT_LAYER_SEGMENTS(
    {6, 1, HSV_WHITE}
);

// Light LEDs 7 when layer 7 is active.
const rgblight_segment_t PROGMEM my_layer7[] = RGBLIGHT_LAYER_SEGMENTS(
    {7, 1, HSV_WHITE}
);

// Now define the array of layers. Later layers take precedence
const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    my_layer0,
    my_layer1,
    my_layer2,
    my_layer3,
    my_layer4,
    my_layer5,
    my_layer6,
    my_layer7
);

void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = my_rgb_layers;
    // Disable rgblight itself by default, the layer will still show up. and this can be turned on from vial
    rgblight_disable();
}

//save the layer state to a variable
layer_state_t layer_state_set_user(layer_state_t state) {
    currentLayer = get_highest_layer(state);
    int l;
    for (l = 0; l < 8; ++l) {
        //Check state of all layers so that we reset
        rgblight_set_layer_state(l, layer_state_cmp(state, l));
    }
    return state;
};




