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

enum layers {APL, WIN, NAVNUM, FKEY, ADJUST};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [APL] = LAYOUT(
              KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
              KC_A,    KC_S,    KC_D,    KC_F,    KC_G,        KC_H,    KC_J,    KC_K,    KC_L, KC_QUOT,
      LSFT_T(KC_Z),    KC_X,    KC_C,    KC_V,    KC_B,        KC_N,    KC_M, KC_COMM,  KC_DOT, RSFT_T(KC_SLSH),
                             KC_LCTL, KC_LALT, KC_LCMD,        KC_SPC, MO(NAVNUM), MO(ADJUST)
    ),
    [WIN] = LAYOUT(
      _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______,
                        KC_LWIN, _______, KC_LCTL,    _______, _______, _______
    ),
    [NAVNUM] = LAYOUT(
         KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    _______, _______,   KC_UP, KC_PGUP, _______,
         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, 
      KC_TRNS, _______, KC_MINS,  KC_EQL,  KC_GRV,    _______, KC_PGDN, KC_HOME,  KC_END, KC_TRNS,
                        _______, _______, _______,    MO(FKEY), _______, MO(FKEY)
    ),
    [FKEY] = LAYOUT(
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,    _______, _______, KC_MS_U, _______, _______,
        KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,    _______, KC_MS_L, KC_MS_D, KC_MS_R, _______,
      KC_TRNS, _______,  KC_F11,  KC_F12, _______,    _______, KC_BTN1, KC_BTN3, KC_BTN2, KC_TRNS,
                        _______, _______, _______,    _______, _______, _______
    ),
    [ADJUST] = LAYOUT(
      _______, TG(WIN), _______, _______, _______,    _______, _______, KC_VOLU, _______, _______,
      _______, _______, _______, _______, _______,    _______, KC_BRID, KC_VOLD, KC_BRIU, _______,
      _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______,
                        KC_LWIN, _______, KC_LCTL,    _______, MO(FKEY), _______
    )
};

enum combos {
  GRV,
  ESC,
  TAB,
  LBRC,
  RBRC,
  BSLS,
  BSPC,
  DEL,
  SCLN,
  ENT,
  CAPS
};

const uint16_t PROGMEM grv_combo[] = {KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM esc_combo[] = {KC_S, KC_D, COMBO_END};
const uint16_t PROGMEM tab_combo[] = {KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM lbrc_combo[] = {KC_U, KC_J, COMBO_END};
const uint16_t PROGMEM rbrc_combo[] = {KC_I, KC_K, COMBO_END};
const uint16_t PROGMEM bsls_combo[] = {KC_O, KC_L, COMBO_END};
const uint16_t PROGMEM bspc_combo[] = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM del_combo[] = {KC_H, KC_J, COMBO_END};
const uint16_t PROGMEM scln_combo[] = {KC_L, KC_QUOT, COMBO_END};
const uint16_t PROGMEM ent_combo[] = {KC_K, KC_L, COMBO_END};
const uint16_t PROGMEM caps_combo[] = {KC_A, KC_QUOT, COMBO_END};


combo_t key_combos[COMBO_COUNT] = {
  [GRV] = COMBO(grv_combo, KC_GRV),
  [ESC] = COMBO(esc_combo, KC_ESC),
  [TAB] = COMBO(tab_combo, KC_TAB),
  [LBRC] = COMBO(lbrc_combo, KC_LBRC),
  [RBRC] = COMBO(rbrc_combo, KC_RBRC),
  [BSLS] = COMBO(bsls_combo, KC_BSLS),
  [BSPC] = COMBO(bspc_combo, KC_BSPC),
  [DEL] = COMBO(del_combo, KC_DEL),
  [SCLN] = COMBO(scln_combo, KC_SCLN),
  [ENT] = COMBO(ent_combo, KC_ENT),
  [CAPS] = COMBO(caps_combo, KC_CAPS)
};
 
static uint8_t mode_switcher_state = 0;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  // Mode switcher, RESET, WINDOWS and APPLE
  if (keycode == KC_E || keycode == KC_I) {
    if (record->event.pressed) {
      mode_switcher_state |= 0B10000000;
    } else {
      mode_switcher_state &= ~(0B10000000);
    }
  }

  if (keycode == KC_R || keycode == KC_U) {
    if (record->event.pressed) {
      mode_switcher_state |= 0B01000000;
    } else {
      mode_switcher_state &= ~(0B01000000);
    }
  }

  if (keycode == KC_T || keycode == KC_Y) {
    if (record->event.pressed) {
      mode_switcher_state |= 0B00100000;
    } else {
      mode_switcher_state &= ~(0B00100000);
    }
  }

  if (mode_switcher_state == 0B11100000 && record->event.pressed) {
    reset_keyboard();
  }

  return true;
}