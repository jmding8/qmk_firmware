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

#define _APL 0
#define _WIN 1
#define _WINLALT 2
#define _WINRALT 3
#define _WINLCTRL 4
#define _WINLCTRLRCTRL 5


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_APL] = LAYOUT( /* Base */
    KC_ESC, KC_F1,  KC_F2,  KC_F3,  KC_F4,    KC_F5,  KC_F6,      KC_F7,  KC_F8,    KC_F9,  KC_F10, KC_F11, KC_F12,  KC_DEL, \
    KC_GRV, KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,       KC_7,   KC_8,   KC_9,   KC_0,   KC_MINS, KC_EQL,    KC_BSPC, \
    KC_TAB,     KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,       KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   KC_LBRC,KC_RBRC,KC_BSLS, \
    KC_CAPS,      KC_A,   KC_S,   KC_D,   KC_F,   KC_G,       KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,KC_QUOT,       KC_ENT, \
    KC_F13, KC_LSFT,  KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,       KC_N,   KC_M,   KC_COMM,KC_DOT,   KC_SLSH,KC_UP,  KC_RSFT, \
    KC_F14, KC_LCTL,KC_LALT,KC_LCMD,  KC_F15, KC_F16, KC_F17,     KC_SPC, KC_F18, KC_RCMD,  KC_RALT,KC_LEFT,KC_DOWN,KC_RGHT  \
  ),
  [_WIN] = LAYOUT( /* Base Windows */
    KC_ESC, KC_F1,  KC_F2,  KC_F3,  KC_F4,    KC_F5,  KC_F6,      KC_F7,  KC_F8,    KC_F9,  KC_F10, KC_F11, KC_F12,  KC_DEL, \
    KC_GRV, KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,       KC_7,   KC_8,   KC_9,   KC_0,   KC_MINS, KC_EQL,    KC_BSPC, \
    KC_TAB,     KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,       KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   KC_LBRC,KC_RBRC,KC_BSLS, \
    KC_CAPS,      KC_A,   KC_S,   KC_D,   KC_F,   KC_G,       KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,KC_QUOT,       KC_ENT, \
    KC_LSFT,KC_LSFT,  KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,       KC_N,   KC_M,   KC_COMM,KC_DOT,   KC_SLSH,KC_UP,  KC_RSFT, \
    KC_LCTL,KC_LCTL,KC_LWIN,KC_LALT, KC_LALT,KC_LCTL,KC_BSPC,     KC_SPC,KC_RALT, KC_RALT,  KC_RCTL,KC_LEFT,KC_DOWN,KC_RGHT  \
  ),
  /*
  [_WINLALT] = LAYOUT(
    _______, _______,  _______,  _______,  _______,    _______,  _______,      _______,  _______,    _______,  _______, _______, _______,  _______, \
    _______, _______,   _______,   _______,   _______,   _______,   _______,       _______,   _______,_______, _______,   _______, _______,    _______, \
    _______,     _______,   _______,   _______,   _______,   _______,       _______,   _______,KC_MINS, KC_EQL,   _______,   _______,_______,_______, \
    _______,      _______,   _______,   _______,   _______,   _______,       KC_6,  KC_7,    KC_8,   KC_9,      KC_0,_______,       _______, \
    _______,_______,  _______,   _______,   _______,   _______,   _______,       _______,KC_PGDN,   _______,_______,   _______,_______,  _______, \
    _______, _______,_______,_______,  _______, _______, _______,     _______, _______, _______,  _______,_______,_______,_______  \
  ),
  [_WINRALT] = LAYOUT(
    _______, _______,  _______,  _______,  _______,    _______,  _______,      _______,  _______,    _______,  _______, _______, _______,  _______, \
    _______, _______,   _______,   _______,   _______,   _______,   _______,       _______,   _______,   _______,   _______,   _______, _______,    _______, \
    KC_GRV,     KC_1,   KC_2,   KC_3,   KC_4,   KC_5,       _______,   _______,  KC_UP,KC_PGUP,   _______,   _______,_______,_______, \
    _______,      _______,   _______,   _______,   _______,   _______,       _______,KC_LEFT,KC_DOWN,KC_RGHT,   KC_BSPC,_______,       _______, \
    _______,_______,  _______,   _______,   _______,   _______,   _______,       _______,KC_PGDN,   _______,_______,   _______,_______,  _______, \
    _______, _______,_______,_______,  _______, _______, _______,     _______, _______, _______,  _______,_______,_______,_______  \
  ),
  [_WINLCTRL] = LAYOUT(
    _______, _______,  _______,  _______,  _______,    _______,  _______,      _______,  _______,    _______,  _______, _______, _______,  _______, \
    _______, _______,   _______,   _______,   _______,   _______,   _______,       _______,   _______,_______, _______,   _______, _______,    _______, \
    KC_ESC,     _______,   _______,   _______,   _______,   _______,       _______,   _______,   _______,   _______,   _______,   _______,_______,_______, \
    _______,      _______,   _______,   _______,   _______,   _______,       _______,_______,_______,_______,   KC_BSPC,_______,       _______, \
    _______,_______,  _______,   _______,   _______,   _______,   _______,       _______,_______,   _______,_______,   _______,_______,  _______, \
    _______, _______,_______,_______,  _______, _______, _______,     _______, _______, _______,  _______,_______,_______,_______  \
  ),
  [_WINLCTRLRCTRL] = LAYOUT(
    _______, _______,  _______,  _______,  _______,    _______,  _______,      _______,  _______,    _______,  _______, _______, _______,  _______, \
    _______, _______,   _______,   _______,   _______,   _______,   _______,       _______,   _______,_______, _______,   _______, _______,    _______, \
    _______,     _______,   _______,   _______,   _______,   _______,       _______,   _______,KC_PGUP,   _______,   _______,   _______,_______,_______, \
    _______,      _______,   _______,   _______,   _______,   _______,       _______,KC_HOME,KC_PGDN, KC_END,   KC_BSPC,_______,       _______, \
    _______,_______,  _______,   _______,   _______,   _______,   _______,       _______,_______,   _______,_______,   _______,_______,  _______, \
    _______, _______,_______,_______,  _______, _______, _______,     _______, _______, _______,  _______,_______,_______,_______  \
  ),
  */
};

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

static uint8_t magic_combo_state = 0;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (keycode == KC_ESCAPE) {
    record->event.pressed ? magic_combo_state |= 0B10000000 : magic_combo_state &= ~(0B10000000);
  }
  if (keycode == KC_F6) {
    record->event.pressed ? magic_combo_state |= 0B01000000 : magic_combo_state &= ~(0B01000000);
  }

  if (keycode == KC_R) {
    record->event.pressed ? magic_combo_state |= 0B00100000 : magic_combo_state &= ~(0B00100000);
  }
  if (keycode == KC_A) {
    record->event.pressed ? magic_combo_state |= 0B00010000 : magic_combo_state &= ~(0B00010000);
  }
  if (keycode == KC_W) {
    record->event.pressed ? magic_combo_state |= 0B00001000 : magic_combo_state &= ~(0B00001000);
  }

  // Reset
  if (magic_combo_state == 0B11100000) {
    reset_keyboard();
  }

  // Modes
  if (magic_combo_state == 0B11010000) {
    persistent_default_layer_set(_APL);
    layer_on(_APL);
    layer_off(_WIN);
  }
  if (magic_combo_state == 0B11001000) {
    layer_off(_APL);
    layer_on(_WIN);
  }

  return true;
}

void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

void led_set_user(uint8_t usb_led) {

}
