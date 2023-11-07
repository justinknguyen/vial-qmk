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

#include "pikatea_macropad_gb5.h"

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

/*
led_config_t g_led_config = { {
  // Key Matrix to LED Index
  {   0,1,2,3,4, NO_LED },
  { NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED}
}, {
  // LED Index to Physical Position
  { 188,  64 }, { 187,  64 }, { 149,  64 }, { 112,  64 }, {  37,  64 }
}, {
  // LED Index to Flag
  4, 4, 4, 4, 4
} };
*/
