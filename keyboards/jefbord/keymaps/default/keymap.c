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
#include QMK_KEYBOARD_H

enum layers {BASE, NAV, NUM, ADJ};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = LAYOUT( /* Base */
    KC_ESC ,KC_1   ,KC_2   ,KC_3   ,KC_4   ,KC_5   ,KC_6   ,    KC_7   ,KC_8   ,KC_9   ,KC_0   ,KC_MINS,KC_EQL ,KC_BSPC    , \
    KC_TAB     ,KC_Q   ,KC_W   ,KC_E   ,KC_R   ,KC_T   ,    KC_Y   ,KC_U   ,KC_I   ,KC_O   ,KC_P   ,KC_LBRC,KC_RBRC,KC_BSLS, \
  LT(NUM,KC_CAPS),KC_A   ,KC_S   ,KC_D   ,KC_F   ,KC_G   ,    KC_H   ,KC_J   ,KC_K   ,KC_L   ,KC_SCLN,KC_QUOT,KC_ENT       , \
    KC_GRV ,KC_LSFT  ,KC_Z   ,KC_X   ,KC_C   ,KC_V   ,KC_B   ,    KC_N   ,KC_M   ,KC_COMM,KC_DOT ,KC_SLSH  ,KC_UP  ,KC_RSFT, \
    KC_LCTL,KC_LWIN,KC_LALT,KC_LWIN  ,KC_LALT,KC_LCTL,KC_SPC ,    KC_SPC ,MO(NAV),MO(ADJ)  ,KC_PSCR,KC_LEFT,KC_DOWN,KC_RGHT  \
  ),
  [NAV] = LAYOUT( /* Navigation */
    _______,KC_F1  ,KC_F2  ,KC_F3  ,KC_F4  ,KC_F5  ,KC_F6  ,    KC_F7  ,KC_F8  ,KC_F9  ,KC_F10 ,KC_F11 ,KC_F12 ,_______    , \
    _______    ,_______,_______,_______,_______,_______,    _______,_______,KC_UP  ,KC_PGUP,_______,_______,_______,_______, \
    _______      ,_______,_______,_______,_______,_______,    _______,KC_LEFT,KC_DOWN,KC_RGHT,KC_BSPC,_______,_______      , \
    _______,_______  ,_______,_______,_______,_______,_______,    KC_PGDN,KC_HOME,KC_END ,_______, KC_DEL  ,_______,_______, \
    _______,_______,_______,_______  ,_______,_______,_______,    _______, KC_NO , KC_NO   ,_______,_______,_______,_______  \
  ),
  [NUM] = LAYOUT( /* Numpad */
    _______,KC_F1  ,KC_F2  ,KC_F3  ,KC_F4  ,KC_F5  ,KC_F6  ,    KC_F7  ,KC_F8  ,KC_F9  ,KC_F10 ,KC_F11 ,KC_F12 ,_______    , \
    _______    ,_______,_______,_______,_______,_______,    KC_PSLS,KC_7   ,KC_8   ,KC_9   ,KC_PMNS,_______,_______,_______, \
    _______      ,_______,_______,_______,_______,_______,    KC_PAST,KC_4   ,KC_5   ,KC_6   ,KC_PPLS,_______,_______      , \
    _______,_______  ,_______,_______,_______,_______,_______,    _______,KC_1   ,KC_2   ,KC_3   ,KC_PENT  ,_______,_______, \
    _______,_______,_______,_______  ,_______,_______,_______,    _______,KC_0   ,KC_DOT   ,_______,_______,_______,_______  \
  ),
  [ADJ] = LAYOUT( /* Adjust System */
    _______,KC_F1  ,KC_F2  ,KC_F3  ,KC_F4  ,KC_F5  ,KC_F6  ,    KC_F7  ,KC_F8  ,KC_F9  ,KC_F10 ,KC_F11 ,KC_F12 ,_______    , \
    _______    ,_______,_______,_______,_______,_______,    _______,_______,KC_VOLU,_______,_______,_______,_______,_______, \
    _______      ,_______,_______,_______,_______,_______,    _______,KC_BRID,KC_VOLD,KC_BRIU,_______,_______,_______      , \
    _______,_______  ,_______,_______,_______,_______,_______,    _______,_______,_______,_______,_______  ,_______,_______, \
    _______,_______,_______,_______  ,_______,_______,_______,    _______,_______,_______  ,_______,_______,_______,_______  \
  ),
};

static uint8_t mode_switcher_state = 0;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  // RESET chord
  if (keycode == KC_ESC || keycode == KC_0) {
    if (record->event.pressed) {
      mode_switcher_state |= 0B10000000;
    } else {
      mode_switcher_state &= ~(0B10000000);
    }
  }

  if (keycode == KC_1 || keycode == KC_EQL) {
    if (record->event.pressed) {
      mode_switcher_state |= 0B01000000;
    } else {
      mode_switcher_state &= ~(0B01000000);
    }
  }

  if (keycode == KC_2 || keycode == KC_MINS) {
    if (record->event.pressed) {
      mode_switcher_state |= 0B00100000;
    } else {
      mode_switcher_state &= ~(0B00100000);
    }
  }

  if (keycode == KC_3 || keycode == KC_BSPC) {
    if (record->event.pressed) {
      mode_switcher_state |= 0B00010000;
    } else {
      mode_switcher_state &= ~(0B00010000);
    }
  }

  if (mode_switcher_state == 0B11110000 && record->event.pressed) {
    reset_keyboard();
  }

  return true;
}
