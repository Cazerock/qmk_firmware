#include QMK_KEYBOARD_H

enum layer_names {
    _QWERTY,
    _LOWER,
    _RAISE,
    _FUNCTION,
    _ADJUST,
    _SSUPER,
    _EXTRA
};

enum planck_keycodes {
  LOWER = SAFE_RANGE,
  RAISE
};

#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _FUNCTION 3
#define _ADJUST 4
#define _SSUPER 5
#define _EXTRA 6

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,---------------------------------------------------------------------.
 * |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |
 * |------+------+------+------+-------------+------+------+------+------|
 * |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |
 * |------+------+------+------+------|------+------+------+------+------|
 * |   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |
 * |------+------+------+------+------+------+------+------+------+------|
 * |      |      |Adjust| Lower| Super|SP(RA)| Func |Extra |      |      |
 * `---------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_split_3x5_3(
KC_Q,          KC_W,          KC_E,           KC_R,                   KC_T,                   KC_Y,                  KC_U,                    KC_I,          KC_O,          KC_P,
LGUI_T(KC_A),  LALT_T(KC_S),  LSFT_T(KC_D),   LCTL_T(KC_F),           KC_G,                   KC_H,                  RCTL_T(KC_J),            RSFT_T(KC_K),  RALT_T(KC_L),  RGUI_T(KC_SCLN),
KC_Z,          KC_X,          KC_C,           KC_V,                   KC_B,                   KC_N,                  KC_M,                    KC_COMMA,      KC_DOT,        KC_SLASH,
                              OSL(_ADJUST),   LT(_LOWER, KC_ESCAPE),  LT(_SSUPER, KC_BSPC),   LT(_RAISE, KC_SPACE),  LT(_FUNCTION, KC_ENTER), OSL(_EXTRA)
),

/* Lower
 * ,---------------------------------------------------------------------.
 * |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |      |      |
 * |------+------+------+------+-------------+------+------+------+------|
 * |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |
 * |------+------+------+------+------|------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------|
 * |      |      | BOOT |      |      |      |      |      |      |      |
 * `---------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_split_3x5_3(
KC_EXCLAIM,   KC_AT,       KC_HASH,     KC_DOLLAR,   KC_PERCENT,  KC_CIRCUMFLEX, KC_AMPERSAND,   KC_ASTERISK,  KC_TRNS,    KC_TRNS,
KC_1,         KC_2,        KC_3,        KC_4,        KC_5,        KC_6,          KC_7,           KC_8,         KC_9,       KC_0,
KC_TRNS,      KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,       KC_TRNS,        KC_TRNS,      KC_TRNS,    KC_TRNS,
                           QK_BOOT,     KC_TRNS,     KC_TRNS,     KC_TRNS,       KC_TRNS,        KC_TRNS
),


/* Raise (Symbol layer)
 * ,---------------------------------------------------------------------.
 * |  ~   |      |  {   |   }  |      |      |  _   |  -   |  |   |  \   |
 * |------+------+------+------+-------------+------+------+------+------|
 * |  `   |      |  (   |   )  |      |      |  =   |  +   |  '   |  "   |
 * |------+------+------+------+------|------+------+------+------+------|
 * |      |      |  [  |    ]  |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |
 * `---------------------------------------------------------------------'
 */

[_RAISE] = LAYOUT_split_3x5_3(
KC_TILDE,        KC_TRNS,      KC_LCBR,       KC_RCBR,       KC_TRNS,       KC_TRNS,      KC_UNDERSCORE,  KC_MINUS,      KC_PIPE,     KC_BACKSLASH,
KC_GRAVE,        KC_TRNS,      KC_LPRN,       KC_RPRN,       KC_TRNS,       KC_TRNS,      KC_EQUAL,       KC_PLUS,       KC_QUOTE,    RSFT(KC_QUOTE),
KC_TRNS,         KC_TRNS,      KC_LBRC,       KC_RBRC,       KC_TRNS,       KC_TRNS,      KC_TRNS,        KC_TRNS,       KC_TRNS,     KC_TRNS,
                               KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,      KC_TRNS,        KC_TRNS
),

/* Function
 * ,---------------------------------------------------------------------.
 * | ESC  | TAB  |S-TAB |      |      |      | HOME | END  | PSCR | DEL  |
 * |------+------+------+------+-------------+------+------+------+------|
 * |ALT(1)|ALT(2)|ALT(3)|ALT(4)|ALT(5)| LEFT | DOWN |  UP  | RIGHT|      |
 * |------+------+------+------+------|------+------+------+------+------|
 * |ALT(6)|ALT(7)|ALT(8)|ALT(9)|ALT(0)|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      | BOOT |      |      |
 * `---------------------------------------------------------------------'
 */
[_FUNCTION] = LAYOUT_split_3x5_3(
KC_ESCAPE,    KC_TAB,          RSFT(KC_TAB), KC_TRNS,     KC_TRNS,       KC_TRNS,      KC_HOME,      KC_END,       KC_PSCR,      KC_DEL,
LALT(KC_1),   LALT(KC_2),      LALT(KC_3),   LALT(KC_4),  LALT(KC_5),    KC_LEFT,      KC_DOWN,      KC_UP,        KC_RIGHT,     KC_TRNS,
LALT(KC_6),   LALT(KC_7),      LALT(KC_8),   LALT(KC_9),  LALT(KC_0),    KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,
                               KC_TRNS,      KC_TRNS,     KC_TRNS,       KC_TRNS,      KC_TRNS,      QK_BOOT
),

/* SSuper
 * ,---------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+-------------+------+------+------+------|
 * |GUI(1)|GUI(2)|GUI(3)|GUI(4)|GUI(5)|      |      |      |      |      |
 * |------+------+------+------+------|------+------+------+------+------|
 * |GUI(6)|GUI(7)|GUI(8)|GUI(9)|GUI(0)|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |
 * `---------------------------------------------------------------------'
 */
[_SSUPER] = LAYOUT_split_3x5_3(
LGUI(KC_Q),   LGUI(KC_W),  LGUI(KC_E),  LGUI(KC_R),  LGUI(KC_T),    LGUI(KC_Y),   LGUI(KC_U),   LGUI(KC_I),     LGUI(KC_O),    LGUI(KC_P),
LGUI(KC_1),   LGUI(KC_2),  LGUI(KC_3),  LGUI(KC_4),  LGUI(KC_5),    LGUI(KC_H),   LGUI(KC_J),   LGUI(KC_K),     LGUI(KC_L),    LGUI(KC_SEMICOLON),
LGUI(KC_6),   LGUI(KC_7),  LGUI(KC_8),  LGUI(KC_9),  LGUI(KC_0),    LGUI(KC_N),   LGUI(KC_M),   LGUI(KC_COMMA), LGUI(KC_DOT),  LGUI(KC_SLASH),
                           KC_TRNS,     KC_TRNS,     KC_TRNS,       KC_TRNS,      KC_TRNS,      KC_TRNS
),

/* Adjust
 * ,---------------------------------------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  | F10  |
 * |------+------+------+------+-------------+------+------+------+------|
 * | MUTE | Vol- | Vol+ | Bri- | Bri+ |      |      |      |      |      |
 * |------+------+------+------+------|------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |
 * `---------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_split_3x5_3(
KC_F1,        KC_F2,              KC_F3,           KC_F4,                 KC_F5,             KC_F6,        KC_F7,        KC_F8,        KC_F9,        KC_F10,
KC_KB_MUTE,   KC_KB_VOLUME_DOWN,  KC_KB_VOLUME_UP, KC_BRIGHTNESS_DOWN,    KC_BRIGHTNESS_UP,  KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,
KC_TRNS,      KC_TRNS,            KC_TRNS,         KC_TRNS,               KC_TRNS,           KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,
                                  KC_TRNS,         KC_TRNS,               KC_TRNS,           KC_TRNS,      KC_TRNS,      KC_TRNS
),

/* Extra
 * ,---------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+-------------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------|------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |
 * `---------------------------------------------------------------------'
 */
[_EXTRA] = LAYOUT_split_3x5_3(
KC_TRNS,      KC_TRNS,            KC_TRNS,         KC_TRNS,           KC_TRNS,        KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,
KC_TRNS,      KC_TRNS,            KC_TRNS,         KC_TRNS,           KC_TRNS,        KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,
KC_TRNS,      KC_TRNS,            KC_TRNS,         KC_TRNS,           KC_TRNS,        KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,
                                  KC_TRNS,         KC_TRNS,           KC_TRNS,        KC_TRNS,      KC_TRNS,      KC_TRNS
)

};


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

