#include QMK_KEYBOARD_H

enum layer_names {
    _QWERTY,
    _COLEMAK,
    _DVORAK,
    _PLOVER,
    _LOWER,
    _RAISE,
    _ADJUST,
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK,
  DVORAK,
  PLOVER,
  BACKLIT,
  EXT_PLV
};

// Defines for task manager and such
#define CALTDEL LCTL(LALT(KC_DEL))
#define TSKMGR LCTL(LSFT(KC_ESC))

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define SPR_ENT MEH(KC_ENT) // Super enter, ctrl+alt+shift on hold

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |SftEnt|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |  GUI | Alt  | Del  | Lower| Space|SEnter| Raise| Left |Right | Home | End  |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_ortho_4x12(
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
  KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_SFTENT,
  KC_LCTL, KC_LGUI, KC_LALT, KC_DEL,  LOWER,   KC_SPC,  SPR_ENT, RAISE,   KC_LEFT, KC_RGHT, KC_HOME, KC_END
),

/* Colemak
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   F  |   P  |   G  |   J  |   L  |   U  |   Y  |   ;  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  |   A  |   R  |   S  |   T  |   D  |   H  |   N  |   E  |   I  |   O  |  '   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   K  |   M  |   ,  |   .  |   /  |SftEnt|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |  GUI | Alt  | Del  | Lower| Space|SEnter| Raise| Left |Right | Home | End  |
 * `-----------------------------------------------------------------------------------'
 */
[_COLEMAK] = LAYOUT_ortho_4x12(
    KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSPC,
    KC_ESC,  KC_A,    KC_R,    KC_S,    KC_T,    KC_D,    KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_SFTENT,
    KC_LCTL, KC_LGUI, KC_LALT, KC_DEL,  LOWER,   KC_SPC,  SPR_ENT, RAISE,   KC_LEFT, KC_RGHT, KC_HOME, KC_END
),

/* Dvorak
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   '  |   ,  |   .  |   P  |   Y  |   F  |   G  |   C  |   R  |   L  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  |   A  |   O  |   E  |   U  |   I  |   D  |   H  |   T  |   N  |   S  |  /   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   ;  |   Q  |   J  |   K  |   X  |   B  |   M  |   W  |   V  |   Z  |SftEnt|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |  GUI | Alt  | Del  | Lower| Space|SEnter| Raise| Left |Right | Home | End  |
 * `-----------------------------------------------------------------------------------'
 */
[_DVORAK] = LAYOUT_ortho_4x12(
    KC_TAB,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,    KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_BSPC,
    KC_ESC,  KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_SLSH,
    KC_LSFT, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,    KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_SFTENT,
    KC_LCTL, KC_LGUI, KC_LALT, KC_DEL,  LOWER,   KC_SPC,  SPR_ENT, RAISE,   KC_LEFT, KC_RGHT, KC_HOME, KC_END
),

/* Plover layer (http://opensteno.org)
 * ,-----------------------------------------------------------------------------------.
 * |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   S  |   T  |   P  |   H  |   *  |   *  |   F  |   P  |   L  |   T  |   D  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   S  |   K  |   W  |   R  |   *  |   *  |   R  |   B  |   G  |   S  |   Z  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Exit |      |      |   A  |   O  |             |   E  |   U  |      |      | Exit |
 * `-----------------------------------------------------------------------------------'
 */
[_PLOVER] = LAYOUT_ortho_4x12(
    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1   ,
    _______, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,
    _______, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    EXT_PLV, _______, _______, KC_C,    KC_V,    _______, _______, KC_N,    KC_M,    _______, _______, EXT_PLV
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
 * |      |      |      |      |RGBTOG|RGBRMO|RGBMOD|Qwerty|Colmk |Dvorak|Plover|caltde|
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |RGBHUD|RGBHUI|      |      |      |      |AGnorm|
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |RGBSAD|RGBSAI|      |      |      |      |AGswap|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |RGBVAD|RGBVAI|      |      |      |      | RESET|
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_ortho_4x12(
  _______, _______, _______, _______, RGB_TOG, RGB_RMOD, RGB_MOD, QWERTY,  COLEMAK, DVORAK,  PLOVER,  CALTDEL,
  _______, _______, _______, _______, _______, RGB_HUD,  RGB_HUI, _______, _______, _______, _______, AG_NORM,
  _______, _______, _______, _______, _______, RGB_SAD,  RGB_SAI, _______, _______, _______, _______, AG_SWAP,
  _______, _______, _______, _______, _______, RGB_VAD,  RGB_VAI, _______, _______, _______, _______, RESET
)

};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case COLEMAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_COLEMAK);
      }
      return false;
      break;
    case DVORAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_DVORAK);
      }
      return false;
      break;
    case PLOVER:
      if (record->event.pressed) {
        layer_off(_RAISE);
        layer_off(_LOWER);
        layer_off(_ADJUST);
        layer_on(_PLOVER);
        if (!eeconfig_is_enabled()) {
            eeconfig_init();
        }
        keymap_config.raw = eeconfig_read_keymap();
        keymap_config.nkro = 1;
        eeconfig_update_keymap(keymap_config.raw);
      }
      return false;
      break;
    case EXT_PLV:
      if (record->event.pressed) {
        layer_off(_PLOVER);
      }
      return false;
      break;
  }
  return true;
}
