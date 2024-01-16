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

#pragma once

#include "quantum.h"

/* This is a shortcut to help you visually see your layout.
 *
 * The first section contains all of the arguments representing the physical
 * layout of the board and position of the keys.
 *
 * The second converts the arguments into a two-dimensional array which
 * represents the switch matrix.
 */
#define LAYOUT( \
K00, K01, K02, K03, K04, K05, K06, K07, K08, K09, K010, K011, K012, K013, K014, K015, K016, K017, K018, K019, K020, K021, K022, K023,  \
K10, K11, K12, K13, K14, K15, K16, K17, K18, K19, K110, K111, K112, K113, K114, K115, K116, K117, K118, K119, K120, K121, K122, K123,  \
K20, K21, K22, K23, K24, K25, K26, K27, K28, K29, K210, K211, K212, K213, K214, K215, K216, K217, K218, K219, K220, K221, K222, K223,  \
K30, K31, K32, K33, K34, K35, K36, K37, K38, K39, K310, K311, K312, K313, K314, K315, K316, K317, K318, K319, K320, K321, K322, K323  \
) { \
{ K00, K01, K02, K03, K04, K05, K06, K07, K08, K09, K010, K011, K012, K013, K014, K015, K016, K017, K018, K019, K020, K021, K022, K023 },  \
{ K10, K11, K12, K13, K14, K15, K16, K17, K18, K19, K110, K111, K112, K113, K114, K115, K116, K117, K118, K119, K120, K121, K122, K123 },  \
{ K20, K21, K22, K23, K24, K25, K26, K27, K28, K29, K210, K211, K212, K213, K214, K215, K216, K217, K218, K219, K220, K221, K222, K223 },  \
{ K30, K31, K32, K33, K34, K35, K36, K37, K38, K39, K310, K311, K312, K313, K314, K315, K316, K317, K318, K319, K320, K321, K322, K323 }  \
}
