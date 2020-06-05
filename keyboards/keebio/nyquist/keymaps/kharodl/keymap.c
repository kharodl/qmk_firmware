#include QMK_KEYBOARD_H

enum layer_names {
    _QWERTY,
    _COLEMAK,
    _DVORAK,
    _PLOVER,
    _LOWER,
    _RAISE,
    _ADJUST,
    _MEDIA
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK,
  DVORAK,
  PLOVER,
  BACKLIT,
  PLV_EXT,
  PLV_CTL,
  PLV_STP
};


#define LOWER   MO(_LOWER)
#define RAISE   MO(_RAISE)
#define GUI     MO(_GUI)
#define SPR_ENT MEH_T(KC_ENT) // Super enter, ctrl+alt+shift on hold
#define CTL_ESC LCTL_T(KC_ESC) // control on hold, esc on tap

// Defines for task manager and such
#define CALTDEL LCTL(LALT(KC_DEL))
#define TSKMGR LCTL(LSFT(KC_ESC))

// Window manager keys
#define WM_DTPB LALT(LGUI(KC_F))
#define WM_DTPF LCTL(LALT(LGUI(KC_RGHT)))
#define WM_PREV LCTL(LALT(LGUI(KC_LEFT)))
#define WM_NW   LCTL(LGUI(KC_LEFT))
#define WM_N    LALT(LGUI(KC_UP))
#define WM_NE   LCTL(LGUI(KC_RGHT))
#define WM_E    LALT(LGUI(KC_RGHT))
#define WM_SE   S(LCTL(LGUI(KC_RGHT)))
#define WM_S    LALT(LGUI(KC_DOWN))
#define WM_SW   S(LCTL(LGUI(KC_LEFT)))
#define WM_W    LALT(LGUI(KC_LEFT))
#define WM_CNTR LALT(LGUI(KC_C))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |CtlEsc|   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |SftEnt|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Super|  GUI | Alt  | Del  | Lower| Space| Enter| Raise| Left |Right | Home | End  |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_ortho_4x12(
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
  CTL_ESC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_SFTENT,
  KC_MEH,  KC_LGUI, KC_LALT, KC_DEL,  LOWER,   KC_SPC,  KC_ENT,  RAISE,   KC_LEFT, KC_RGHT, KC_HOME, KC_END
),

/* Colemak
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   F  |   P  |   G  |   J  |   L  |   U  |   Y  |   ;  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |CtlEsc|   A  |   R  |   S  |   T  |   D  |   H  |   N  |   E  |   I  |   O  |  '   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   K  |   M  |   ,  |   .  |   /  |SftEnt|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Super|  GUI | Alt  | Del  | Lower| Space| Enter| Raise| Left |Right | Home | End  |
 * `-----------------------------------------------------------------------------------'
 */
[_COLEMAK] = LAYOUT_ortho_4x12(
    KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSPC,
    CTL_ESC, KC_A,    KC_R,    KC_S,    KC_T,    KC_D,    KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_SFTENT,
    KC_MEH,  KC_LGUI, KC_LALT, KC_DEL,  LOWER,   KC_SPC,  KC_ENT,  RAISE,   KC_LEFT, KC_RGHT, KC_HOME, KC_END
),

/* Dvorak
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   '  |   ,  |   .  |   P  |   Y  |   F  |   G  |   C  |   R  |   L  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |CtlEsc|   A  |   O  |   E  |   U  |   I  |   D  |   H  |   T  |   N  |   S  |  /   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   ;  |   Q  |   J  |   K  |   X  |   B  |   M  |   W  |   V  |   Z  |SftEnt|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Super|  GUI | Alt  | Del  | Lower| Space| Enter| Raise| Left |Right | Home | End  |
 * `-----------------------------------------------------------------------------------'
 */
[_DVORAK] = LAYOUT_ortho_4x12(
    KC_TAB,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,    KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_BSPC,
    CTL_ESC, KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_SLSH,
    KC_LSFT, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,    KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_SFTENT,
    KC_MEH,  KC_LGUI, KC_LALT, KC_DEL,  LOWER,   KC_SPC,  KC_ENT,  RAISE,   KC_LEFT, KC_RGHT, KC_HOME, KC_END
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
    PLV_EXT, KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1
    PLV_CTL, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,
    PLV_STP, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    PLV_EXT, _______, _______, KC_C,    KC_V,    _______, _______, KC_N,    KC_M,    _______, _______, PLV_EXT
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
  KC_ENT,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_PGUP, KC_SLSH, KC_4,    KC_5,    KC_6,    KC_MINS, KC_EQL,
  _______, C(KC_Z), C(KC_X), C(KC_C), C(KC_V), KC_PGDN, KC_ASTR, KC_1,    KC_2,    KC_3,    KC_PLUS, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, KC_0,    KC_DOT,  KC_INS,  KC_MENU
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |  Up  |   _  |   +  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F6  |  F7  |  F8  |  F9  |  F10 | Down |   -  |   =  |   {  |   }  |  |   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F11 |      |  F12 |      |      |      |      |   |  |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_ortho_4x12(
  KC_GRV,  KC_EXLM,  KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR,  KC_LPRN, KC_RPRN, KC_DEL,
  _______, KC_F1,   KC_F2,    KC_F3,   KC_F4,   KC_F5,   KC_UP,   KC_UNDS, KC_PLUS,  KC_LBRC, KC_RBRC, KC_BSLS,
  _______, KC_F6,   KC_F7,    KC_F8,   KC_F9,   KC_F10,  KC_DOWN, KC_MINS, KC_EQL,   KC_LCBR, KC_RCBR, KC_PIPE,
  _______, KC_F11,  _______,  KC_F12,  _______, _______, _______, _______, _______,  _______, _______, _______
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |RGBTOG|RGBRMO|RGBMOD|Qwerty|Colmk |Dvorak|Plover|caltde|
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |CapLck| Prev | Play | Next |Brgt D|RGBHUD|RGBHUI|Brgt U| VolD | Mute | VolU |AGnorm|
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |RGBSAD|RGBSAI|      |      |      |      |AGswap|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |RGBVAD|RGBVAI|      |      |      |NKTOGG| RESET|
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_ortho_4x12(
  _______, _______, _______, _______, RGB_TOG, RGB_RMOD, RGB_MOD, QWERTY,  COLEMAK, DVORAK,  PLOVER,  CALTDEL,
  KC_CAPS, KC_MPRV, KC_MPLY, KC_MNXT, KC_BRID, RGB_HUD,  RGB_HUI, KC_BRIU, KC_VOLD, KC_MUTE, KC_VOLU, AG_NORM,
  _______, _______, _______, _______, _______, RGB_SAD,  RGB_SAI, _______, _______, _______, _______, AG_SWAP,
  _______, _______, _______, _______, _______, RGB_VAD,  RGB_VAI, _______, _______, _______, NK_TOGG, RESET
)

};

void toggle_plover(void) {
  // Toggles plover application with PHROLG chord
  SEND_STRING(SS_DOWN(X_P) SS_DOWN(X_H) SS_DOWN(X_R) SS_DOWN(X_O) SS_DOWN(X_L) SS_DOWN(X_G));
  SEND_STRING(SS_UP(X_P) SS_UP(X_H) SS_UP(X_R) SS_UP(X_O) SS_UP(X_L) SS_UP(X_G));
}

void disable_plover(void) {
  toggle_plover();
  layer_off(_PLOVER);
}

void enable_plover(void) {
  toggle_plover();
  layer_off(_RAISE);
  layer_off(_LOWER);
  layer_off(_ADJUST);
  layer_on(_PLOVER);
}

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
        enable_plover();
        if (!eeconfig_is_enabled()) {
            eeconfig_init();
        }
        keymap_config.raw = eeconfig_read_keymap();
        keymap_config.nkro = 1;
        eeconfig_update_keymap(keymap_config.raw);
      }
      return false;
      break;
    case PLV_EXT:
      if (record->event.pressed) {
        disable_plover();
      }
      return false;
      break;
    // case PLV_CTL:
    //   if (record->event.down) {
    //     disable_plover();
    //     SEND_STRING(SS_DOWN(X_LCTL));
    //   } else if (record->event.up) {
    //     SEND_STRING(SS_UP(X_LCTL));
    //     enable_plover();
    //   }
    //   return false;
    //   break;
  }
  return true;
}
