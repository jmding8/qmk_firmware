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

// --------------------------------------------------------------
// Mouse
// --------------------------------------------------------------
// Constant speed mode
// #define MK_3_SPEED
// #define MOUSEKEY_DELAY 300
// #define MOUSEKEY_INTERVAL 16
// #define MOUSEKEY_MAX_SPEED 3
// #define MOUSEKEY_TIME_TO_MAX 60
// #define MK_C_OFFSET_0    4
// #define MK_C_INTERVAL_0  28
// #define MK_C_OFFSET_1    8
// #define MK_C_INTERVAL_1  16
// #define MK_C_OFFSET_2    5
// #define MK_C_INTERVAL_2  8

// #define MOUSEKEY_WHEEL_MAX_SPEED 4
// #define MOUSEKEY_WHEEL_TIME_TO_MAX 40

// #define MK_W_OFFSET_0       1
// #define MK_W_INTERVAL_0     120
// #define MK_W_OFFSET_1       1
// #define MK_W_INTERVAL_1     100
// #define MK_W_OFFSET_2       1
// #define MK_W_INTERVAL_2     60

// Acceleration mode
#undef MOUSEKEY_DELAY
#define MOUSEKEY_DELAY          0
#undef MOUSEKEY_INTERVAL
#define MOUSEKEY_INTERVAL       24 //40 //48 //64 //32
#undef MOUSEKEY_WHEEL_DELAY
#define MOUSEKEY_WHEEL_DELAY    0
#undef MOUSEKEY_MAX_SPEED
#define MOUSEKEY_MAX_SPEED      30
#undef MOUSEKEY_TIME_TO_MAX
#define MOUSEKEY_TIME_TO_MAX    64

// --------------------------------------------------------------
// Mod/layer tap configuation
// --------------------------------------------------------------
#define RETRO_TAPPING // long presses of MT/LT keys not paired with a second keypress will now result in a tap output
#define TAPPING_FORCE_HOLD // a tap followed by a hold of a MT/LT key used to be two taps, now it is a tap and a hold
#define PERMISSIVE_HOLD // SFT_T(a) down, j down, j up, SFT_T(a) up in < tapping_term will now be J instead of aj
// #define IGNORE_MOD_TAP_INTERRUPT // rolled mod-taps will now be sequential taps
#define QMK_KEYS_PER_SCAN 4
#define TAPPING_TERM 200

// --------------------------------------------------------------
// Combo configuration
// --------------------------------------------------------------
#define COMBO_COUNT 3
// #define COMBO_TERM 75
#define COMBO_TERM 100