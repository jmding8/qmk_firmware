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

#define APL 0
#define WIN 1
#define NAVNUM 2
#define FKEYS 3
#define ADJUST 4

enum custom_keycodes {
  KC_R000 = SAFE_RANGE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [APL] = LAYOUT(
       KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_BSPC,
       KC_ESC,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,       KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
      KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,       KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_RSFT,
                                 KC_LCTL, KC_LALT, KC_LGUI,    KC_R000, LT(FKEYS, KC_ENT), MO(ADJUST)
    ),
    [WIN] = LAYOUT(
       KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_BSPC,
       KC_ESC,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,       KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
      KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,       KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_RSFT,
                                 KC_LWIN, KC_LALT, KC_LCTL,    KC_R000, LT(FKEYS, KC_ENT), MO(ADJUST)
    ),
    [NAVNUM] = LAYOUT(
      _______,    KC_1,    KC_2,    KC_3,    KC_4, KC_LCBR,    KC_RCBR, _______,   KC_UP, KC_PGUP, _______,  KC_DEL,
      _______,    KC_5,    KC_6,    KC_7,    KC_8, KC_LBRC,    KC_RBRC, KC_LEFT, KC_DOWN, KC_RGHT, _______, KC_BSLS,
      KC_LSFT,    KC_9,    KC_0, KC_MINS,  KC_EQL,  KC_GRV,    _______, KC_PGDN, KC_HOME,  KC_END, _______, KC_RSFT,
                                 _______, _______, _______,    _______, _______, _______
    ),
    [FKEYS] = LAYOUT(
      KC_PSCR,   KC_F1,   KC_F2,   KC_F3,   KC_F4, _______,    _______, _______, _______, _______, KC_CLCK, _______,
      _______,   KC_F5,   KC_F6,   KC_F7,   KC_F8, _______,    _______, _______, _______, _______, KC_CLCK, _______,
      _______,   KC_F1,  KC_F10,  KC_F11,  KC_F12, _______,    _______, _______, _______, _______, KC_CLCK, _______,
                                 _______, _______, _______,    _______, _______, _______
    ),
    [ADJUST] = LAYOUT(
      _______, _______, _______, _______, _______, _______,    _______, _______, KC_VOLU, _______, _______, _______,
      _______, _______, _______, _______, _______, _______,    _______, KC_BRID, KC_VOLD, KC_BRIU, _______, _______,
      _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______,
                                 _______, _______, _______,    _______, _______, _______
    )
};

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

static uint8_t mode_switcher_state = 0;
static uint8_t pressed_keys_counter = 0;
static int8_t kc_r000_counter = -1;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  // Mode switcher, RESET, WINDOWS and APPLE
  if (keycode == KC_TAB || keycode == KC_BSPC) {
    if (record->event.pressed) {
      mode_switcher_state |= 0B10000000;
    } else {
      mode_switcher_state &= ~(0B10000000);
    }
  }

  if (keycode == KC_T || keycode == KC_Y) {
    if (record->event.pressed) {
      mode_switcher_state |= 0B01000000;
    } else {
      mode_switcher_state &= ~(0B01000000);
    }
  }

  if (mode_switcher_state == 0B11000000 && record->event.pressed) {
    switch (keycode) {
      case KC_R:
        reset_keyboard();
        break;
      case KC_U:
        reset_keyboard();
        break;
      case KC_A:
        persistent_default_layer_set(APL);
        layer_on(APL);
        layer_off(WIN);
        break;
      case KC_W:
        layer_off(APL);
        layer_on(WIN);
        break;
    }
  }

  // Count pressed keys for key tap/hold overloading.
  if (record->event.pressed) {
    pressed_keys_counter++;
  } else {
    pressed_keys_counter--;
  }

  // Handle right, row 0, col 00 (right thumb 0) overloading.
  if (keycode == KC_R000) {
    if (record->event.pressed) {
      if (pressed_keys_counter == 1) {
        kc_r000_counter = 0;
      }
      layer_on(NAVNUM);
    } else {
      if (kc_r000_counter < 1) {
        SEND_STRING(" ");
      } else { 
      }
      layer_off(NAVNUM);
      kc_r000_counter = -1;
    }
  } else {
    if (record->event.pressed) {
      // do nothing
    } else if (kc_r000_counter >= 0) {
      kc_r000_counter++;
    }
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