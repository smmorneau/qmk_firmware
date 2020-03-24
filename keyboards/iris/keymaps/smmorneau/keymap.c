#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

#define MODS (MOD_BIT(KC_LSHIFT)|MOD_BIT(KC_RSHIFT))

#define _BL 0  // base layer - QWERTY
#define _SL 1  // symbol layer - LOWER
#define _NL 2  // navigation layer - RAISE
#define _FL 3  // function layer - ADJUST

/* KC_BSPACE alone, KC_DELETE with shift */
#define BSP_DEL F(0)

#define LOWER  MO(_SL)
#define RAISE  MO(_NL)
#define ADJUST MO(_FL)

#define TAPPING_TOGGLE 2

// enum custom_keycodes {
//   QWERTY = SAFE_RANGE,
//   LOWER,
//   RAISE,
//   ADJUST,
// };


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /*
   * ,-----+-----+-----+-----+-----+-----+                ,-----+-----+-----+-----+-----+-----+
   * | ESC |  1  |  2  |  3  |  4  |  5  |                |  6  |  7  |  8  |  9  |  0  | ADJ |
   * |-----+-----+-----+-----+-----+-----+                +-----+-----+-----+-----+-----+-----+
   * |  `  |  Q  |  W  |  E  |  R  |  T  |                |  Y  |  U  |  I  |  O  |  P  |  '  |
   * +-----+-----+-----+-----+-----+-----+                +-----+-----+-----+-----+-----+-----+
   * | TAB |  A  |  S  |  D  |  F  |  G  |                |  H  |  J  |  K  |  L  |  [  |  ]  |
   * +-----+-----+-----+-----+-----+-----+-----.    ,-----+-----+-----+-----+-----+-----+-----+
   * | LSFT|  Z  |  X  |  C  |  V  |  B  | OPT /    \     |  N  |  M  |  ,  |  .  |  /  | RCTL|
   * +-----+-----+-----+--+--+-----+-----+----/      \ SPC+-----+-----+--+--+-----+-----+-----+
   *                      \LOWER| BSPC | CMC /        \      | ENT |RAISE/
   *                      `-----+-----+-----'          `-----+-----+----'
   */
  [_BL] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    ADJUST,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_GRV,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_QUOT,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                               KC_H,    KC_J,    KC_K,    KC_L,    KC_LBRC, KC_RBRC,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_LALT,          _______, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RCTL,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    LOWER,   BSP_DEL, KC_LCMD,                   KC_SPC,  KC_ENT,  RAISE
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  /*
   * ,-----+-----+-----+-----+-----+-----+                ,-----+-----+-----+-----+-----+-----+
   * |     |  !  |  @  |  #  |  $  |  %  |                |  ^  |  &  |  *  |  (  |  )  |  `  |
   * |-----+-----+-----+-----+-----+-----+                +-----+-----+-----+-----+-----+-----+
   * |  `  |     |     |  /  |  \  |     |                |  *  |  (  |  )  |  |  |  +  |  ?  |
   * +-----+-----+-----+-----+-----+-----+                +-----+-----+-----+-----+-----+-----+
   * |     |  -  |  +  |  @  |  ;  |  ?  |                |  &  |  :  |  =  |  !  |  {  |  }  |
   * +-----+-----+-----+-----+-----+-----+-----.    ,-----+-----+-----+-----+-----+-----+-----+
   * |     |     |     |     |  $  |     |     /    \     |  _  |  -  |  <  |  >  |  /  |  \  |
   * +-----+-----+-----+--+--+-----+-----+    /      \    +-----+-----+--+--+-----+-----+-----+
   *                      \     |     |      /        \      |     |     /
   *                      `-----+-----+-----'          `-----+-----+----'
   */
  [_SL] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                            KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_GRV,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_GRV,  _______, _______, KC_SLSH, KC_BSLS, _______,                            KC_ASTR, KC_LPRN, KC_RPRN, KC_PIPE, KC_PLUS, KC_QUES,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_MINS, KC_PLUS, KC_AT,   KC_SCLN, KC_QUES,                            KC_AMPR, KC_COLN, KC_EQL,  KC_EXLM, KC_LCBR, KC_RCBR,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, KC_DLR,  _______, _______,          _______, KC_UNDS, KC_MINS, KC_LT,   KC_GT,   KC_HASH, KC_BSLS,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  /*
   * ,-----+-----+-----+-----+-----+-----+                ,-----+-----+-----+-----+-----+-----+
   * |     |     |     |     |     |     |                |     |     |     |     |     |     |
   * |-----+-----+-----+-----+-----+-----+                +-----+-----+-----+-----+-----+-----+
   * |     |  -  |  +  |BRT- |BRT+ |     |                |MUTE |VOL- |VOL+ |PREV |PLAY |NEXT |
   * +-----+-----+-----+-----+-----+-----+                +-----+-----+-----+-----+-----+-----+
   * |     |PGUP |PGDWN|HOME | END |     |                |LEFT |DOWN | UP  |RIGHT|     |     |
   * +-----+-----+-----+-----+-----+-----+-----.    ,-----+-----+-----+-----+-----+-----+-----+
   * |     |     |     |     |     |     |     /    \     |     |     |     |     |     |     |
   * +-----+-----+-----+--+--+-----+-----+    /      \    +-----+-----+--+--+-----+-----+-----+
   *                      \     |     |      /        \      |     |     /
   *                      `-----+-----+-----'          `-----+-----+----'
   */
  [_NL] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_PMNS, KC_PPLS, KC_F14,  KC_F15,  _______,                            KC__MUTE, KC__VOLDOWN, KC__VOLUP, KC_MRWD, KC_MPLY, KC_MFFD,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_PGUP, KC_PGDN, KC_HOME, KC_END,  _______,                            KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  /*
   * ,-----+-----+-----+-----+-----+-----+                ,-----+-----+-----+-----+-----+-----+
   * |     | F1  | F2  | F3  | F4  | F5  |                | F6  | F7  | F8  | F9  | F10 |     |
   * |-----+-----+-----+-----+-----+-----+                +-----+-----+-----+-----+-----+-----+
   * |     | F11 | F12 | F13 | F14 | F15 |                | F16 | F17 | F18 | F19 | F20 |     |
   * +-----+-----+-----+-----+-----+-----+                +-----+-----+-----+-----+-----+-----+
   * |     |     |     |     |     |     |                |     |     |     |     |     |     |
   * +-----+-----+-----+-----+-----+-----+-----.    ,-----+-----+-----+-----+-----+-----+-----+
   * |     |     |     |     |     |     |     /    \     |     |     |     |     |  -  |     |
   * +-----+-----+-----+--+--+-----+-----+    /      \    +-----+-----+--+--+-----+-----+-----+
   *                      \     |     |      /        \      |     |     /
   *                      `-----+-----+-----'          `-----+-----+----'
   */
  [_FL] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                              KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_F11,  KC_F12,  KC_F13,  KC_F14,  KC_F15,                             KC_F16,  KC_F17,  KC_F18,  KC_F19,  KC_F20,  _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_F21,  KC_F22,  KC_F23,  KC_F24,  _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  )
};

/* List of user defined functions. F(N) corresponds to item N of this list. */
const uint16_t PROGMEM fn_actions[] = {
  [0] = ACTION_FUNCTION(0),  // Calls action_function()
};

void action_function(keyrecord_t *record, uint8_t id, uint8_t opt) {
  static uint8_t mods_pressed;
  static bool mod_flag;

  switch (id) {
    case 0:
      // KC_BSPACE alone, KC_DELETE with modifiers
      mods_pressed = get_mods()&MODS; // which mods are pressed
      if (record->event.pressed) {
        // keydown
        if (mods_pressed) {
          mod_flag = true;
          add_key(KC_DELETE);
          send_keyboard_report();
        } else {
          add_key(KC_BSPACE);
          send_keyboard_report();
        }
      } else {
        // keyup
        if (mod_flag) {
          mod_flag = false;
          del_key(KC_DELETE);
          send_keyboard_report();
        } else {
          del_key(KC_BSPACE);
          send_keyboard_report();
        }
      }
      break;
  }
}

// bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//   switch (keycode) {
//     case QWERTY:
//       if (record->event.pressed) {
//         set_single_persistent_default_layer(_BL);
//       }
//       return false;
//       break;
//     case LOWER:
//       if (record->event.pressed) {
//         layer_on(_SL);
//         update_tri_layer(_SL, _NL, _FL);
//       } else {
//         layer_off(_SL);
//         update_tri_layer(_SL, _NL, _FL);
//       }
//       return false;
//       break;
//     case RAISE:
//       if (record->event.pressed) {
//         layer_on(_NL);
//         update_tri_layer(_SL, _NL, _FL);
//       } else {
//         layer_off(_NL);
//         update_tri_layer(_SL, _NL, _FL);
//       }
//       return false;
//       break;
//     case ADJUST:
//       if (record->event.pressed) {
//         layer_on(_FL);
//       } else {
//         layer_off(_FL);
//       }
//       return false;
//       break;
//   }
//   return true;
// }
