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

enum layers {APL, WIN, NAVNUM, FNS, ADJ};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [APL] = LAYOUT(
       KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_BSLS,
       KC_ESC,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,       KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
      KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,       KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_RSFT,
                                 KC_LCTL, KC_LOPT, KC_LGUI,       KC_SPC, MO(NAVNUM), MO(ADJ)
    ),
    [WIN] = LAYOUT(
      _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______,
                                 KC_LWIN, KC_LALT, KC_LCTL,    _______, _______, _______
    ),
    [NAVNUM] = LAYOUT(
      _______,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    _______, _______,   KC_UP, KC_PGUP, KC_LBRC, KC_RBRC,
      _______,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______, KC_LEFT, KC_DOWN, KC_RGHT, KC_BSPC,  KC_DEL,
      KC_TRNS, _______, _______, KC_MINS,  KC_EQL, _______,    _______, KC_PGDN, KC_HOME,  KC_END, _______, KC_TRNS,
                                 _______, _______, _______,    MO(FNS), _______, _______
    ),
    [FNS] = LAYOUT(
      _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,    _______, _______, KC_MS_U, _______, _______, KC_PSCR,
      _______,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,    _______, KC_MS_L, KC_MS_D, KC_MS_R, _______, _______,
      KC_TRNS, _______, _______,  KC_F11,  KC_F12, _______,    _______, KC_BTN1, KC_BTN3, KC_BTN2, _______, KC_CAPS,
                                 _______, _______, _______,    _______, _______, _______
    ),
    [ADJ] = LAYOUT(
      _______, _______, TG(WIN), _______, _______, _______,    _______, _______, KC_VOLU, _______, _______, _______,
      _______, _______, _______, _______, _______, _______,    _______, KC_BRID, KC_VOLD, KC_BRIU, _______, _______,
      KC_TRNS, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, KC_TRNS,
                                 _______, _______, _______,    _______, _______, _______
    )
};

enum combos {
  TILDE_COMBO,
  ENTER_COMBO
};

const uint16_t PROGMEM tilde_combo[] = {KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM enter_combo[] = {KC_J, KC_K, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [TILDE_COMBO] = COMBO(tilde_combo, KC_GRV),
  [ENTER_COMBO] = COMBO(enter_combo, KC_ENT)
};

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

static uint8_t mode_switcher_state = 0;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  // Reset
  if (keycode == KC_W || keycode == KC_Y) {
    if (record->event.pressed) {
      mode_switcher_state |= 0B10000000;
    } else {
      mode_switcher_state &= ~(0B10000000);
    }
  }

  if (keycode == KC_E || keycode == KC_U) {
    if (record->event.pressed) {
      mode_switcher_state |= 0B01000000;
    } else {
      mode_switcher_state &= ~(0B01000000);
    }
  }

  if (keycode == KC_R || keycode == KC_I) {
    if (record->event.pressed) {
      mode_switcher_state |= 0B00100000;
    } else {
      mode_switcher_state &= ~(0B00100000);
    }
  }

  if (keycode == KC_T || keycode == KC_O) {
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

bool led_update_kb(led_t led_state) {
    bool res = led_update_user(led_state);
    if(res) {
        writePin(D5, !led_state.caps_lock);
        writePin(B0, !led_state.caps_lock);
    }
    return res;
}