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

#define ENCODERS_CW_KEY  { { 1, 1 } }
#define ENCODERS_CCW_KEY { { 0, 1 } }

/* RBG settings */
#ifdef RGB_DI_PIN
/*== all animations enable ==*/
#    define RGBLIGHT_ANIMATIONS
/*== customize breathing effect ==*/
/*==== (DEFAULT) use fixed table instead of exp() and sin() ====*/
#    define RGBLIGHT_BREATHE_TABLE_SIZE 256      // 256(default) or 128 or 64
/*==== use exp() and sin() ====*/
#    define RGBLIGHT_EFFECT_BREATHE_CENTER 1.85  // 1 to 2.7
#    define RGBLIGHT_EFFECT_BREATHE_MAX    255   // 0 to 255
/* default rgb */
#    define RGBLIGHT_DEFAULT_MODE RGBLIGHT_MODE_BREATHING
#endif

/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */

/* define if matrix has ghost (lacks anti-ghosting diodes) */
//#define MATRIX_HAS_GHOST

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

/* vial stuff */

#define VIAL_KEYBOARD_UID {0x2B, 0x72, 0x3E, 0x47, 0x50, 0x3C, 0x86, 0x7D}


