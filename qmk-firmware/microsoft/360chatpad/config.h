/* Copyright 2019 DmNosachev
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

// Have't added any diodes in this particular convertion project
#define MATRIX_HAS_GHOST

// #define PS2_PIO_USE_PIO1 // Force the usage of PIO1 peripheral, by default the PS2 implementation uses the PIO0 peripheral

#define BACKLIGHT_PINS { GP16, GP17 }
#define BACKLIGHT_ON_STATE 0
#define BACKLIGHT_LEVELS 1
#define DIP_SWITCH_PINS { GP22, GP26, GP27, GP28 }