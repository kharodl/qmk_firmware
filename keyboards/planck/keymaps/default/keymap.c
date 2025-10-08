/* Copyright 2015-2021 Jack Humbert
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

#ifdef AUDIO_ENABLE
#    include "muse.h"
#endif

enum planck_layers {
  _QWERTY,
  _COLEMAK,
  _LOWER,
  _RAISE,
  _ADJUST
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK
};

#define LOWER   MO(_LOWER)
#define RAISE   MO(_RAISE)

#define SFTENT  RSFT_T(KC_ENT) // shift on hold, enter on tap

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |SftEnt|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |  GUI | Alt  | Del  |LOWER |    Space    |RAISE | Left |Right | Down |  Up  |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_planck_grid(
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, SFTENT,
    KC_LCTL, KC_LGUI, KC_LALT, KC_DEL,  LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_RGHT, KC_DOWN, KC_UP
),

/* Colemak
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   F  |   P  |   G  |   J  |   L  |   U  |   Y  |   ;  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  |   A  |   R  |   S  |   T  |   D  |   H  |   N  |   E  |   I  |   O  |  '   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   K  |   M  |   ,  |   .  |   /  |SftEnt|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |  GUI | Alt  | Del  |LOWER |    Space    |RAISE | Left |Right | Down |  Up  |
 * `-----------------------------------------------------------------------------------'
 */
[_COLEMAK] = LAYOUT_planck_grid(
    KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,   KC_G,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSPC,
    KC_ESC,  KC_A,    KC_R,    KC_S,    KC_T,   KC_D,    KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,   KC_B,    KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, SFTENT,
    KC_LCTL, KC_LGUI, KC_LALT, KC_DEL,  LOWER,  KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_RGHT, KC_DOWN, KC_UP
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Enter |      | Home |  Up  | End  | PgUp |   *  |   4  |   5  |   6  |   +  |  =   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      | Left | Down |Right |PgDown|   /  |   1  |   2  |   3  |   -  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |------|             |      |   0  |   .  |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_planck_grid(
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,   KC_0,    _______,
    KC_ENT,  _______, KC_HOME, KC_UP,   KC_END,  KC_PGUP, KC_ASTR, KC_4,    KC_5,    KC_6,   KC_PLUS, KC_EQL,
    _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, KC_SLSH, KC_1,    KC_2,    KC_3,   KC_MINS, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, KC_0,    KC_DOT, _______, _______
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Del  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  Up  |   _  |   +  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 | Down |   -  |   =  |   {  |   }  |  |   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |Shift |      |             |------|      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_planck_grid(
    KC_GRV,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR,  KC_LPRN, KC_RPRN, KC_DEL,
    KC_F1,   KC_F2,    KC_F3,  KC_F4,   KC_F5,   KC_F6,   KC_UP,   KC_UNDS, KC_PLUS,  KC_LBRC, KC_RBRC, KC_BSLS,
    KC_F7,    KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,  KC_DOWN, KC_MINS, KC_EQL,   KC_LCBR, KC_RCBR, KC_PIPE,
    _______, _______, _______, KC_LSFT, _______, _______, _______, _______, _______,  _______, _______, _______
),

/* Adjust (Lower + Raise), Media and RGB control
 * ,-----------------------------------------------------------------------------------.
 * |NK_TOG|      |      |      |      |RGBTOG|RGBMOD|      |      |      |Colmak|Qwerty|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |CapLck| Prev | Play | Next |Brgt- |R_HUE-|R_HUE+|Brgt+ | Vol- | Mute | Vol+ |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |R_BRT-|R_SAT-|R_SAT+|R_BRT+|      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |AGnorm|AGswap|      |      |------|             |------|      |      |      | DFU  |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_planck_grid(
    NK_TOGG, _______, _______, _______, _______, UG_TOGG, UG_NEXT, _______, _______, _______, COLEMAK, QWERTY,
    KC_CAPS, KC_MPRV, KC_MPLY, KC_MNXT, KC_BRID, UG_HUED, UG_HUEU, KC_BRIU, KC_VOLD, KC_MUTE, KC_VOLU, _______,
    _______, _______, _______, _______, UG_VALD, UG_SATD, UG_SATU, UG_VALU, _______, _______, _______, _______,
    AG_NORM, AG_SWAP, _______, _______, _______, _______, _______, _______, _______, _______, _______, QK_BOOT
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
  }
  return true;
}
