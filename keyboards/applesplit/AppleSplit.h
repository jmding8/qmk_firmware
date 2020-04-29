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

#include "quantum.h"

/* This a shortcut to help you visually see your layout.
 *
 * The first section contains all of the arguments representing the physical
 * layout of the board and position of the keys.
 *
 * The second converts the arguments into a two-dimensional array which
 * represents the switch matrix.
 */
#define LAYOUT( \
    L00, L01, L02, L03, L04,  L05, L06, R06, R05,  R04, R03, R02, R01, R00, \
    L10, L11, L12, L13, L14, L15, L16, R16, R15, R14, R13, R12, R11,   R10, \
    L20,   L21, L22, L23, L24, L25, R27, R26, R25, R24, R23, R22, R21, R20, \
    L30,    L31, L32, L33, L34, L35, R36, R35, R34, R33, R32, R31,     R30, \
    L40,  L41, L42, L43, L44, L45, L46, R46, R45, R44, R43,  R42, R41, R40, \
    L50, L51, L52, L53,  L54, L55, L56, R56, R55, R54,  R53, R52, R51, R50  \
) \
{ \
    { L00,  L01,  L02,  L03,  L04,  L05,  L06,KC_NO }, \
    { L10,  L11,  L12,  L13,  L14,  L15,  L16,KC_NO }, \
    { L20,KC_NO,  L21,  L22,  L23,  L24,  L25,KC_NO }, \
    { L30,KC_NO,  L31,  L32,  L33,  L34,  L35,KC_NO }, \
    { L40,  L41,  L42,  L43,  L44,  L45,  L46,KC_NO }, \
    { L50,  L51,  L52,  L53,  L54,  L55,  L56,KC_NO }, \
    { R00,  KC_NO,R01,  R02,  R03,  R04,  R05,  R06 }, \
    { R10,  KC_NO,R11,  R12,  R13,  R14,  R15,  R16 }, \
    { R20,  R21,  R22,  R23,  R24,  R25,  R26,  R27 }, \
    { R30,  KC_NO,R31,  R32,  R33,  R34,  R35,  R36 }, \
    { R40,  KC_NO,R41,  R42,  R43,  R44,  R45,  R46 }, \
    { R50,  KC_NO,R51,  R52,  R53,  R54,  R55,  R56 }  \
}

/*
{ R06,KC_NO,  R05,  R04,  R03,  R02,  R01,  R00 }, \
{ R16,KC_NO,  R15,  R14,  R13,  R12,  R11,  R10 }, \
{ R27,  R26,  R25,  R24,  R23,  R22,  R21,  R20 }, \
{ R36,KC_NO,  R35,  R34,  R33,  R32,  R31,  R30 }, \
{ R46,KC_NO,  R45,  R44,  R43,  R42,  R41,  R40 }, \
{ R56,KC_NO,  R55,  R54,  R53,  R52,  R51,  R50 }  \
*/
