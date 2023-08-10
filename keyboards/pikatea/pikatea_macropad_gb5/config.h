/*
Copyright 2020 Jack Kester

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

/* key matrix size */
#define MATRIX_ROWS 2
#define MATRIX_COLS 8

/*
 * Keyboard Matrix Assignments
 *
 * Change this to how you wired your keyboard
 * COLS: AVR pins used for columns, left to right
 * ROWS: AVR pins used for rows, top to bottom
 * DIODE_DIRECTION: COL2ROW = COL = Anode (+), ROW = Cathode (-, marked on diode)
 *                  ROW2COL = ROW = Anode (+), COL = Cathode (-, marked on diode)
 *
 */
#define MATRIX_COL_PINS { GP17, GP18, GP19, GP20, GP23, GP24, GP25, GP11  }
#define MATRIX_ROW_PINS { GP28, NO_PIN }

/* COL2ROW, ROW2COL */
#define DIODE_DIRECTION COL2ROW

/* Encoder setup */
#define ENCODERS_CW_KEY  { { 1, 1 } }
#define ENCODERS_CCW_KEY { { 0, 1 } }

// /* RBG settings */
// #define WS2812_DI_PIN GP7
// #define WS2812_BYTE_ORDER WS2812_BYTE_ORDER_RGB
#define NOP_FUDGE 0.4
// #define NOP_FUDGE 1
// #define RGBLIGHT_DEFAULT_MODE RGBLIGHT_MODE_BREATHING

// #ifdef RGB_DI_PIN
// #    define RGBLED_NUM 7
// #    define RGBLIGHT_HUE_STEP 8
// #    define RGBLIGHT_SAT_STEP 8
// #    define RGBLIGHT_VAL_STEP 8
// #    define RGBLIGHT_LIMIT_VAL 150 /* The maximum brightness level */
// #    define RGBLIGHT_SLEEP  /* If defined, the RGB lighting will be switched off when the host goes to sleep */
// #    define RGBLIGHT_LAYERS
// /*== all animations enable ==*/
// #    define RGBLIGHT_ANIMATIONS
// /*== or choose animations ==*/
// // #    define RGBLIGHT_EFFECT_BREATHING
// // #    define RGBLIGHT_EFFECT_RAINBOW_MOOD
// // #    define RGBLIGHT_EFFECT_RAINBOW_SWIRL
// // #    define RGBLIGHT_EFFECT_SNAKE
// // #    define RGBLIGHT_EFFECT_KNIGHT
// // #    define RGBLIGHT_EFFECT_CHRISTMAS
// // #    define RGBLIGHT_EFFECT_STATIC_GRADIENT
// // #    define RGBLIGHT_EFFECT_RGB_TEST
// // #    define RGBLIGHT_EFFECT_ALTERNATING
// /*== customize breathing effect ==*/
// /*==== (DEFAULT) use fixed table instead of exp() and sin() ====*/
// #    define RGBLIGHT_BREATHE_TABLE_SIZE 256      // 256(default) or 128 or 64
// /*==== use exp() and sin() ====*/
// #    define RGBLIGHT_EFFECT_BREATHE_CENTER 1.85  // 1 to 2.7
// #    define RGBLIGHT_EFFECT_BREATHE_MAX    255   // 0 to 255
// /* default rgb */
// #    define RGBLIGHT_DEFAULT_MODE RGBLIGHT_MODE_BREATHING
// #endif

/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
#define DEBOUNCE 5

/* define if matrix has ghost (lacks anti-ghosting diodes) */
//#define MATRIX_HAS_GHOST

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE


/* vial stuff */

#define VIAL_KEYBOARD_UID {0x74, 0xB0, 0xE5, 0x36, 0x63, 0x73, 0x9D, 0x94}


