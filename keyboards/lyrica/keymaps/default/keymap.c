// This is the personal keymap of jmding

// Configuration options
#include QMK_KEYBOARD_H

// Layer declarations
enum layers {APL, WIN, NAVNUM, FNS, ADJ};


// -------------------------------------------------------------------------------------------------------
// Tap dance
// -------------------------------------------------------------------------------------------------------
// Tap Dance declarations
enum {TD_LAYERS};

enum {
  SINGLE_TAP = 1,
  SINGLE_HOLD = 2,
  DOUBLE_TAP = 3,
  DOUBLE_HOLD = 4,
  TRIPLE_TAP = 5,
  TRIPLE_HOLD = 6
};

int cur_dance (qk_tap_dance_state_t *state) {
  if (state->count == 1) {
    if (state->pressed) return SINGLE_HOLD;
    else return SINGLE_TAP;
  }
  else if (state->count == 2) {
    if (state->pressed) return DOUBLE_HOLD;
    else return DOUBLE_TAP;
  }
  else if (state->count == 3) {
    if (state->interrupted || !state->pressed)  return TRIPLE_TAP;
    else return TRIPLE_HOLD;
  }
  else return 8;
}

typedef struct {
  bool is_press_action;
  int state;
} tap;

static tap alttap_state = {
  .is_press_action = true,
  .state = 0
};

void alt_finished (qk_tap_dance_state_t *state, void *user_data) {
  alttap_state.state = cur_dance(state);
  switch (alttap_state.state) {
    case SINGLE_TAP: layer_on(NAVNUM); break;
    case SINGLE_HOLD: layer_on(NAVNUM); break;
    case DOUBLE_TAP: layer_on(FNS); break;
    case DOUBLE_HOLD: layer_on(FNS); break;
  }
}

void alt_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (alttap_state.state) {
    case SINGLE_TAP: layer_off(NAVNUM); break;
    case SINGLE_HOLD: layer_off(NAVNUM); break;
    case DOUBLE_TAP: layer_off(FNS); break;
    case DOUBLE_HOLD: layer_off(FNS); break;
  }
  alttap_state.state = 0;
}

qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_LAYERS] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, alt_finished, alt_reset)
};


// -------------------------------------------------------------------------------------------------------
// Keymaps dance
// -------------------------------------------------------------------------------------------------------
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [APL] = LAYOUT(
       KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_BSLS,
       KC_ESC,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,       KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
      KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,       KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_RSFT,
                                 KC_LCTL, KC_LOPT, KC_LGUI,       KC_SPC, TD(TD_LAYERS), MO(ADJ)

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

// -------------------------------------------------------------------------------------------------------
// Combos
// -------------------------------------------------------------------------------------------------------
enum combos {
  TILDE_COMBO,
  ENTER_COMBO,
  RESET1_COMBO,
  RESET2_COMBO
};

const uint16_t PROGMEM tilde_combo[] = {KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM enter_combo[] = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM reset1_combo[] = {KC_E, KC_R, KC_T, COMBO_END};
const uint16_t PROGMEM reset2_combo[] = {KC_Y, KC_U, KC_I, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [TILDE_COMBO] = COMBO_ACTION(tilde_combo),
  [ENTER_COMBO] = COMBO_ACTION(enter_combo),
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
    case ENTER_COMBO:
      if (pressed) {
        register_code(KC_ENT);
      } else {
        unregister_code(KC_ENT);
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

