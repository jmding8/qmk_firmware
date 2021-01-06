// This is the personal keymap of jmding

// Configuration options
#include QMK_KEYBOARD_H

// Declarations
enum layers {APL, WIN, NAVNUM, FNS, ADJ};
enum my_keycodes {TD_LAYERS = SAFE_RANGE};

// -------------------------------------------------------------------------------------------------------
// Keymaps
// -------------------------------------------------------------------------------------------------------
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [APL] = LAYOUT(
       KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_BSLS,
       KC_ESC,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,       KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
      KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,       KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_RSFT,
                                 KC_LCTL, KC_LOPT, KC_LGUI,       KC_SPC, TD_LAYERS, MO(ADJ)

                                                                // Using a KC_SPC + ___ combos to trigger layers doesnt work
                                                                // All of the options for the second key result in unwanted
                                                                // behaviors:
                                                                // KC_ NO: spaces only trigger ~50% time
                                                                // KC_ G: works perfectly, but solo presses -> g
                                                                // KC_ STOP, INT7, EXSEL, EXEC: NAVNUM doesnt toggle
                                                                //   It appears that keycodes lacking Windows support
                                                                //   (https://beta.docs.qmk.fm/using-qmk/simple-keycodes/keycodes)
                                                                //   all have behave the same way
                                                                // KC_ F24: works perfectly, but solo presses -> ~ on WIN
                                                                // CUSTOM_KEYCODE: solo presses -> e
    ),
    [WIN] = LAYOUT(
      _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______,
                                 KC_LWIN, KC_LCTL, KC_LALT,    _______, _______, _______
    ),
    [NAVNUM] = LAYOUT(
      _______,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    _______, _______,   KC_UP, KC_PGUP, KC_LBRC, KC_RBRC,
      _______,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______, KC_LEFT, KC_DOWN, KC_RGHT, KC_BSPC,  KC_ENT,
      KC_TRNS, _______, _______, KC_MINS,  KC_EQL, _______,    _______, KC_PGDN, KC_HOME,  KC_END,  KC_DEL, KC_TRNS,
                                 _______, _______, _______,    _______, _______, _______
    ),
    [FNS] = LAYOUT(
      _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,    KC_CAPS, _______, KC_MS_U, _______, KC_BTN3, _______,
      _______,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,    KC_PSCR, KC_MS_L, KC_MS_D, KC_MS_R, KC_BTN1, _______,
      KC_TRNS, _______, _______,  KC_F11,  KC_F12, _______,    _______, _______, _______, _______, KC_BTN2, KC_TRNS,
                                 _______, _______, _______,    _______, _______, _______
    ),
    [ADJ] = LAYOUT(
      _______, _______, TG(WIN), _______, _______, _______,    _______, _______, KC_VOLU, _______, _______, _______,
      _______, _______, _______, _______, _______, _______,    _______, KC_BRID, KC_VOLD, KC_BRIU, _______, _______,
      KC_TRNS, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, KC_TRNS,
                                 _______, _______, _______,    _______, _______, _______
    )
};

// -------------------------------------------------------------------------------------------------------
// Combos
// -------------------------------------------------------------------------------------------------------
enum combos {
  TILDE_COMBO,
  RESET1_COMBO,
  RESET2_COMBO
};

const uint16_t PROGMEM tilde_combo[] = {KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM reset1_combo[] = {KC_E, KC_R, KC_T, COMBO_END};
const uint16_t PROGMEM reset2_combo[] = {KC_Y, KC_U, KC_I, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [TILDE_COMBO] = COMBO_ACTION(tilde_combo),
  [RESET1_COMBO] = COMBO_ACTION(reset1_combo),
  [RESET2_COMBO] = COMBO_ACTION(reset2_combo)
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
    case RESET1_COMBO:
    case RESET2_COMBO:
      reset_keyboard();
      break;
  }
}

// -------------------------------------------------------------------------------------------------------
// Legacy persistent layer set
// -------------------------------------------------------------------------------------------------------
void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

// -------------------------------------------------------------------------------------------------------
// Process Record
// -------------------------------------------------------------------------------------------------------
static uint16_t timer = 0;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
  // Custom tap dance implementation. Tap-hold for layer 1, Tap-tap-hold for layer 2.
  // QMK's out of the box implementation requires you to wait for the full tapping 
  // term before pushing the desired tap-dance output. This implementation immediately
  // sets layer 1 on the first tap without waiting for the full tapping term to expire.
    case TD_LAYERS:
      if (record->event.pressed) {
        if (timer_elapsed(timer) < 200) {
          layer_on(FNS);
        } else {
          layer_on(NAVNUM);
        }
        timer = timer_read();
      } else {
        layer_off(NAVNUM);
        layer_off(FNS);
        // timer = timer_read();
      }
      break;
  }
  
  return true;
}