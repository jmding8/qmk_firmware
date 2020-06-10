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

// place overrides here

// 2
// #define TAPPING_TERM 250
// getting navigation instead of space sometimes

// 3
// #define JMD_HOLD_ON_OTHER_KEY_PRESS
// #define TAPPING_TERM 400
// when typing natural text, often I input space + right-hand-character in a rolling
// combo fashion, which gets interpreted as mod here

// 4
#define PERMISSIVE_HOLD

// 5 
// when typing " ←" rapidly (tap(space), hold(space) + j), the second press
// of the space/navnum triggers a space rather than pending a hold. Setting
// tapping_term to a small number to hopefully fix this.
// #define TAPPING_TERM 150 original problem persists
// #define TAPPING_TERM 120 original problem persists
// #define TAPPING_TERM 100 space becomes inconsistent as it requires really short presses
#define TAPPING_TERM 150




// #define IGNORE_MOD_TAP_INTERRUPT
