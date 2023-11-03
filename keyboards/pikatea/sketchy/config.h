/* Copyright 2021 Kyle McCreery 
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


#pragma once

/* USB Device descriptor parameter */
// #define VENDOR_ID       0xDC9E
// #define PRODUCT_ID      0x512E
// #define DEVICE_VER      0x0001
// #define MANUFACTURER    DCPEdit
// #define PRODUCT         SketchySketchy

/* key matrix size */
// #define MATRIX_ROWS 5
// #define MATRIX_COLS 12

/* key matrix pins */
#define MATRIX_ROW_PINS { GP20, GP21, GP15, GP13, GP9 }
#define MATRIX_COL_PINS { GP4, GP5, GP6, GP7, GP8, GP12, GP14, GP16, GP23, GP22, GP26, GP27 }

/* encoder resolution */
#define ENCODER_RESOLUTION 4
#define TAP_CODE_DELAY 10

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW

/* Set 0 if debouncing isn't needed */
#define DEBOUNCE 5

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE

/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE


#define I2C_DRIVER I2CD1
#define I2C1_SDA_PIN GP2
#define I2C1_SCL_PIN GP3