// This is the personal keymap of jmding.

// Configuration options
#include QMK_KEYBOARD_H

enum layers {APL, WIN, NAVNUM, FNS, ADJ};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [APL] = LAYOUT(
       KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_BSLS,
       KC_ESC,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,       KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
      KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,       KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_RSFT,
                                 KC_LCTL, KC_LOPT, KC_LGUI,       KC_SPC, KC_NO, MO(ADJ)
                                                                          // Using KC_NO to trigger NAVNUM and
                                                                          // FNS layer because using a custom keycode
                                                                          // didn't work.
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
                                 _______, _______, _______,    _______, _______, _______
    ),
    [FNS] = LAYOUT(
      _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,    _______, _______, KC_MS_U, _______, KC_BTN3, KC_PSCR,
      _______,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,    _______, KC_MS_L, KC_MS_D, KC_MS_R, KC_BTN1, _______,
      KC_TRNS, _______, _______,  KC_F11,  KC_F12, _______,    _______, _______, _______, _______, KC_BTN2, KC_CAPS,
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
  ENTER_COMBO,
  FNS_COMBO
};

const uint16_t PROGMEM tilde_combo[] = {KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM enter_combo[] = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM fns_combo[] = {KC_SPC, KC_NO, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [TILDE_COMBO] = COMBO_ACTION(tilde_combo),
  [ENTER_COMBO] = COMBO_ACTION(enter_combo),
  [FNS_COMBO] = COMBO_ACTION(fns_combo)
};
 
void process_combo_event(uint8_t combo_index, bool pressed) {
  switch(combo_index) {
    case TILDE_COMBO:
      if (pressed) {
        register_code(KC_GRV);
      } else {
        unregister_code(KC_GRV);
      }
      break;
    case ENTER_COMBO:
      if (pressed) {
        register_code(KC_ENT);
      } else {
        unregister_code(KC_ENT);
      }
      break;
    case FNS_COMBO:
      if (pressed) {
        layer_on(FNS);
      } else {
        layer_off(FNS);
      }
      break;
  }
}

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

static uint8_t reset_hook = 0;
void maybe_reset(void) {
  if (reset_hook == 0B11110000) {
    reset_keyboard();
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // Handle hooks for RESET combo.
    case KC_W:
    case KC_Y:
      if (record->event.pressed) {
        reset_hook |= 0B10000000;
        maybe_reset();
      } else {
        reset_hook &= ~(0B10000000);
      }
      break;
    case KC_E:
    case KC_U:
      if (record->event.pressed) {
        reset_hook |= 0B01000000;
        maybe_reset();
      } else {
        reset_hook &= ~(0B01000000);
      }
      break;
    case KC_R:
    case KC_I:
      if (record->event.pressed) {
        reset_hook |= 0B00100000;
        maybe_reset();
      } else {
        reset_hook &= ~(0B00100000);
      }
      break;
    case KC_T:
    case KC_O:
      if (record->event.pressed) {
        reset_hook |= 0B00010000;
        maybe_reset();
      } else {
        reset_hook &= ~(0B00010000);
      }
      break;
    
    // Handle hook for NAVNUM / FNS layer.
    case KC_NO:
      if (record->event.pressed) {
        if (IS_LAYER_OFF(FNS)) {
          layer_on(NAVNUM);
        }
      } else {
        layer_off(NAVNUM);
      }
    case KC_SPC:
      if (!record->event.pressed) {
        layer_off(FNS);
      }
      break;
  }
  
  return true;
}