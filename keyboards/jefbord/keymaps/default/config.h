/* Copyright 2019 Jamie
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

// Mod/layer tap configuation
#define RETRO_TAPPING // long presses of MT/LT keys not paired with a second keypress will now result in a tap output
#define TAPPING_FORCE_HOLD // a tap followed by a hold of a MT/LT key used to be two taps, now it is a tap and a hold
#define PERMISSIVE_HOLD // SFT_T(a) down, j down, j up, SFT_T(a) up in < tapping_term will now be J instead of aj
// #define IGNORE_MOD_TAP_INTERRUPT // rolled mod-taps will now be sequential taps
#define QMK_KEYS_PER_SCAN 4
#define TAPPING_TERM 125

#define COMBO_COUNT 6
#define COMBO_TERM 75