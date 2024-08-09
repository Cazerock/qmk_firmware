#include QMK_KEYBOARD_H

enum layer_names {
    _COLEMAKDH,
    _LOWER,
    _RAISE,
    _FUNCTION,
    _ADJUST,
    _SSUPER,
};

enum planck_keycodes {
  LOWER = SAFE_RANGE,
  RAISE
};

#define _COLEMAKDH 0
#define _LOWER 1
#define _RAISE 2
#define _FUNCTION 3
#define _ADJUST 4
#define _SSUPER 5

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* ColemakDH
 * ,---------------------------------------------------------------------.
 * |   Q  |   W  |   F  |   P  |   B  |   J  |   L  |   U  |   Y  |   ;  |
 * |------+------+------+------+-------------+------+------+------+------|
 * |   A  |   R  |   S  |   T  |   G  |   M  |   N  |   E  |   I  |   O  |
 * |------+------+------+------+------|------+------+------+------+------|
 * |   X  |   C  |   D  |   V  |Alt(Z)|Alt(K)|   H  |   ,  |   .  |   /  |
 * |------+------+------+------+------+------+------+------+------+------|
 * |    Super | Ctl (Esc) | Sft (Sp) | Sft (Bsp) | Ctl (Ent) | Layer     |
 * `---------------------------------------------------------------------'
 */
[_COLEMAKDH] = LAYOUT_split_3x5_3(
KC_Q,          KC_W,          KC_F,           KC_P,                   KC_B,                   KC_J,                  KC_L,                    KC_U,          KC_Y,          KC_SCLN,
KC_A,          KC_R,          KC_S,           KC_T,                   KC_G,                   KC_M,                  KC_N,                    KC_E,          KC_I,          KC_O,
KC_X,          KC_C,          KC_D,           KC_V,                   LALT_T(KC_Z),           RALT_T(KC_K),          KC_H,                    KC_COMMA,      KC_DOT,        KC_SLASH,
                             KC_APP,          LCTL_T(KC_ESCAPE),      LSFT_T(KC_SPACE),      RSFT_T(KC_BSPC),        RCTL_T(KC_ENTER),        OSL(_LOWER)
),

/* Lower
 * ,---------------------------------------------------------------------.
 * |   F1 |   F2 |   F3 |   F4 |   F5 |   F6 |   F7 |   F8 |   F9 |  F10 |
 * |------+------+------+------+-------------+------+------+------+------|
 * |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |
 * |------+------+------+------+------|------+------+------+------+------|
 * |  `   |   -  |   =  |   '  |      |      |  TAB |   [  |   ]  |   \  |
 * |------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |
 * `---------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_split_3x5_3(
KC_F1,        KC_F2,       KC_F3,       KC_F4,       KC_F5,       KC_F6,         KC_F7,          KC_F8,        KC_F9,      KC_F10,
KC_1,         KC_2,        KC_3,        KC_4,        KC_5,        KC_6,          KC_7,           KC_8,         KC_9,       KC_0,
KC_GRV,       KC_MINS,     KC_EQL,      KC_QUOT,     KC_TRNS,     KC_TRNS,       KC_TAB,         KC_LBRC,      KC_RBRC,    KC_BSLS,
                           KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,       KC_TRNS,        KC_TRNS
),

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

const uint16_t PROGMEM vim_escape[] = {RCTL_T(KC_J), RSFT_T(KC_K), COMBO_END};
const uint16_t PROGMEM vim_enter[] = {RSFT_T(KC_K), RCTL_T(KC_J), COMBO_END};
combo_t key_combos[] = {
    COMBO(vim_escape, KC_ESC),
    COMBO(vim_enter, KC_ENTER),
};

// current TAPPING_TERM 200
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LT(_SSUPER, KC_BSPC):
            return TAPPING_TERM - 50;
        case LT(_RAISE, KC_SPACE):
            return TAPPING_TERM - 50;
        case LGUI_T(KC_A):
            return TAPPING_TERM + 30;
        case LALT_T(KC_S):
            return TAPPING_TERM;
        case LSFT_T(KC_D):
            return TAPPING_TERM - 50; // lower for colon
        case LCTL_T(KC_F):
            return TAPPING_TERM - 30; // lower for tridactyl
        case RCTL_T(KC_J):
            return TAPPING_TERM;
        case RSFT_T(KC_K):
            return TAPPING_TERM;
        case RALT_T(KC_L):
            return TAPPING_TERM;
        case RGUI_T(KC_SCLN):
            return TAPPING_TERM + 30;
        default:
            return TAPPING_TERM;
    }
}

