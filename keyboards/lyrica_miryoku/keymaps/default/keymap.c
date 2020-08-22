/* Copyright 2019 Thomas Baart <thomas@splitkb.com>
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

// #define APL 0
// #define NAV 1
// #define MOUSE 2
// #define SYM 3
// #define NUMS 4
// #define FKEYS 5

enum layers {APL, WIN, NAV, MOUSE, NUM, FKEY};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [APL] = LAYOUT(
                          KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
      LSFT_T(KC_A), LCTL_T(KC_S), LOPT_T(KC_D), LCMD_T(KC_F), KC_G,        KC_H, RCMD_T(KC_J), ROPT_T(KC_K), RCTL_T(KC_L), RSFT_T(KC_QUOT),
                          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,        KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,
                        KC_ESC, LT(MOUSE, KC_TAB), LT(NAV, KC_BSPC),        LT(NUM, KC_SPC), LT(FKEY, KC_ENT), KC_DEL
    ),
    [WIN] = LAYOUT(
                       _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______,
      LSFT_T(KC_A), LWIN_T(KC_S), LALT_T(KC_D), LCTL_T(KC_F), KC_G,    KC_H, RCTL_T(KC_J), RALT_T(KC_K), RWIN_T(KC_L), RSFT_T(KC_QUOT),
                       _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______,
                                         _______, _______, _______,    _______, _______, _______
    ),
    [NAV] = LAYOUT(
        RESET, _______, _______, _______, _______,    _______, _______,   KC_UP, KC_PGUP, _______,
      _______, _______, _______, _______, _______,    KC_CAPS, KC_LEFT, KC_DOWN, KC_RGHT, KC_BSPC,
      _______, _______, _______, _______, _______,     KC_INS, KC_PGDN, KC_HOME,  KC_END, _______,
                        _______, _______, _______,    _______, _______, _______
    ),
    [MOUSE] = LAYOUT(
        RESET, _______, _______, _______, _______,    _______, _______, KC_MS_U, _______, _______,
      _______, _______, _______, _______, _______,    _______, KC_MS_L, KC_MS_D, KC_MS_R, _______,
      _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______,
                        _______, _______, _______,    KC_BTN1, KC_BTN3, KC_BTN2
    ),
    [NUM] = LAYOUT(
      KC_LBRC,    KC_7,    KC_8,    KC_9, KC_RBRC,    _______, _______, _______, _______,   RESET,
      KC_SCLN,    KC_4,    KC_5,    KC_6,  KC_EQL,    _______, _______, _______, _______, _______,
       KC_GRV,    KC_1,    KC_2,    KC_3, KC_BSLS,    _______, _______, _______, _______, _______,
                         KC_DOT,    KC_0, KC_MINS,    _______, LT(NAV, KC_ENT), _______
    ),
    [FKEY] = LAYOUT(
       KC_F12,   KC_F7,   KC_F8,   KC_F9, KC_RBRC,    _______, _______, _______, _______,   RESET,
       KC_F11,   KC_F4,   KC_F5,   KC_F6,  KC_EQL,    _______, _______, _______, _______, _______,
       KC_F10,   KC_F1,   KC_F2,   KC_F3, KC_BSLS,    _______, _______, _______, _______, _______,
                         KC_DOT,    KC_0, KC_MINS,    LT(NAV, KC_SPC), _______, _______
    )
};

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

static uint8_t mode_switcher_state = 0;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  // Mode switcher, RESET, WINDOWS and APPLE
  if (keycode == KC_Q) {
    if (record->event.pressed) {
      mode_switcher_state |= 0B10000000;
    } else {
      mode_switcher_state &= ~(0B10000000);
    }
  }

  if (keycode == KC_T) {
    if (record->event.pressed) {
      mode_switcher_state |= 0B01000000;
    } else {
      mode_switcher_state &= ~(0B01000000);
    }
  }

  if (mode_switcher_state == 0B11000000 && record->event.pressed) {
    switch (keycode) {
      case KC_A:
        persistent_default_layer_set(APL);
        layer_off(WIN);
        break;
      case KC_W:
        layer_on(WIN);
        break;
    }
  }

  return true;
}