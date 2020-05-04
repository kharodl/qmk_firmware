#include QMK_KEYBOARD_H

enum layer_names {
    _QWERTY,
    _LOWER,
    _RAISE,
    _FUNCTION,
    _ADJUST,
};

enum planck_keycodes {
  LOWER = SAFE_RANGE,
  RAISE
};

// Defines for task manager and such
#define CALTDEL LCTL(LALT(KC_DEL))
#define TSKMGR LCTL(LSFT(KC_ESC))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |SftEnt|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |  GUI | Alt  | Del  | Lower| Space| Enter| Raise| Left |Right | Home | End  |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_ortho_4x12(
  KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,   KC_T,   KC_Y,  KC_U,   KC_I,    KC_O,    KC_P,    KC_BSPC,
  KC_ESC,   KC_A,    KC_S,    KC_D,    KC_F,   KC_G,   KC_H,  KC_J,   KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  KC_LSFT,  KC_Z,    KC_X,    KC_C,    KC_V,   KC_B,   KC_N,  KC_M,   KC_COMM, KC_DOT,  KC_SLSH, KC_SFTENT,
  KC_LCTL,  KC_LGUI, KC_LALT, KC_DEL,  LOWER,  KC_SPC, KC_ENT, RAISE, KC_LEFT, KC_RGHT, KC_HOME, KC_END
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |Enter | Left | Down |  Up  |Right | PgUp |   /  |   4  |   5  |   6  |   -  |  =   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |CTRL-Z|CTRL-X|CTRL-C|CTRL-V|PgDown|   *  |   1  |   2  |   3  |   +  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |   0  |   .  |Insert| Menu |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_ortho_4x12(
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
  KC_ENT,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, KC_SLSH, KC_4,    KC_5,    KC_6,    KC_MINS, KC_EQL,
  _______, C(KC_Z), C(KC_X), C(KC_C), C(KC_V), _______, KC_ASTR, KC_1,    KC_2,    KC_3,    KC_PLUS, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, KC_0,    KC_DOT,  KC_INS,  KC_MENU
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  Up  |   _  |   +  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 | Down |   -  |   =  |   {  |   }  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      | Play | Vol- | Mute | Vol+ |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_ortho_4x12(
  KC_GRV,  KC_EXLM,  KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR,  KC_LPRN, KC_RPRN, KC_DEL,
  KC_F1,   KC_F2,    KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_UP,   KC_UNDS, KC_PLUS,  KC_LBRC, KC_RBRC, KC_BSLS,
  KC_F7,   KC_F8,    KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DOWN, KC_MINS, KC_EQL,   KC_LCBR, KC_RCBR, _______,
  _______, _______,  _______, _______, _______, _______, _______, _______, KC_MPLY,  KC_VOLD, KC_MUTE, KC_VOLU
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |RGBTOG|RGBRMO|RGBMOD|      |      |      |      |caltde|
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |RGBHUD|RGBHUI|      |      |      |      |AGnorm|
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |RGBSAD|RGBSAI|      |      |      |      |AGswap|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |RGBVAD|RGBVAI|      |      |      |      | RESET|
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_ortho_4x12(
  _______, _______, _______, _______, RGB_TOG, RGB_RMOD, RGB_MOD, _______, _______, _______, _______, CALTDEL,
  _______, _______, _______, _______, _______, RGB_HUD,  RGB_HUI, _______, _______, _______, _______, AG_NORM,
  _______, _______, _______, _______, _______, RGB_SAD,  RGB_SAI, _______, _______, _______, _______, AG_SWAP,
  _______, _______, _______, _______, _______, RGB_VAD,  RGB_VAI, _______, _______, _______, _______, RESET
)

};

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
  }
  return true;
}
