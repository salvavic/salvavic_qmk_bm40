
#include QMK_KEYBOARD_H
// #include "keymap_spanish.h"

enum layers {
  _QWERTY,
  _COLEMAK,
  _FN,
  _SIMBOLOS,
  _MOUSE,
  _NUMERICO,
  _ADJUST,
};

enum keycodes {
    QWERTY = SAFE_RANGE,
    COLEMA,
    FN,
    FNDEL,
    SIMBO,
    SIMBOENT,
    MOUSE,
    NUMERIC,
    ADJUST,
    TDPC,
    TDALT
};

enum {
    TD_PC = 0,
    TD_MAY,
};

#define QWERTY DF(_QWERTY)
#define COLEMA DF(_COLEMAK)
#define FN MO(_FN)
#define FNDEL LT(_FN, KC_DEL)
#define SIMBO MO(_SIMBOLOS)
#define SIMBOENT LT(_SIMBOLOS, KC_ENTER)
#define MOUSE MO(_MOUSE)
#define NUMERIC MO(_NUMERICO)

// COLEMAK - home row mods
#define HOMEQ_A LGUI_T(KC_A)
#define HOMEQ_R LALT_T(KC_R)
#define HOMEQ_S LSFT_T(KC_S)
#define HOMEQ_T LCTL_T(KC_T)
#define HOMEQ_O LGUI_T(KC_O)
#define HOMEQ_I LALT_T(KC_I)
#define HOMEQ_E RSFT_T(KC_E)
#define HOMEQ_N LCTL_T(KC_N)
// QWERTY - home row mods
#define HOME_A LGUI_T(KC_A)
#define HOME_S LALT_T(KC_S)
#define HOME_D LCTL_T(KC_D)
#define HOME_F LSFT_T(KC_F)
#define HOME_NT LGUI_T(KC_SCLN)
#define HOME_K RCTL_T(KC_K)
#define HOME_L RALT_T(KC_L)
#define HOME_J RSFT_T(KC_J)

#define LSA_T(kc) MT(MOD_LSFT | MOD_LALT, kc)

bool rgb_matrix_indicators_user(void) {

	switch (get_highest_layer(layer_state)) {
		case _QWERTY:
			rgb_matrix_set_color(11, 0, 40, 50);
			break;
		case _COLEMAK:
            rgb_matrix_set_color_all(50, 10, 20);
			break;
		case _NUMERICO:
            // rgb_matrix_set_color_all(0, 40, 50);

            rgb_matrix_set_color(38, 0, 40, 50);
            rgb_matrix_set_color(7, 0, 40, 50);
            rgb_matrix_set_color(8, 0, 40, 50);
            rgb_matrix_set_color(9, 0, 40, 50);
            rgb_matrix_set_color(10, 0, 40, 50);

            rgb_matrix_set_color(19, 0, 40, 50);
            rgb_matrix_set_color(20, 0, 40, 50);
            rgb_matrix_set_color(21, 0, 40, 50);
            rgb_matrix_set_color(22, 0, 40, 50);

            rgb_matrix_set_color(31, 0, 40, 50);
            rgb_matrix_set_color(32, 0, 40, 50);
            rgb_matrix_set_color(33, 0, 40, 50);
            rgb_matrix_set_color(34, 0, 40, 50);

            rgb_matrix_set_color(43, 0, 40, 50);
            rgb_matrix_set_color(42, 0, 40, 50);
            rgb_matrix_set_color(44, 0, 40, 50);
            rgb_matrix_set_color(45, 0, 40, 50);

            rgb_matrix_set_color(52, 0, 40, 50);
            rgb_matrix_set_color(53, 0, 40, 50);
            rgb_matrix_set_color(54, 0, 40, 50);
            rgb_matrix_set_color(55, 0, 40, 50);
			break;
		case _ADJUST:
            rgb_matrix_set_color_all(50, 10, 20);
			break;
		case _FN:
            rgb_matrix_set_color(39, 50, 0, 0);

            rgb_matrix_set_color(20, 50, 0, 0);
            rgb_matrix_set_color(31, 50, 0, 0);
            rgb_matrix_set_color(32, 50, 0, 0);
            rgb_matrix_set_color(33, 50, 0, 0);

            rgb_matrix_set_color(42, 50, 0, 0);
            rgb_matrix_set_color(43, 50, 0, 0);
            rgb_matrix_set_color(44, 50, 0, 0);
			break;
		case _SIMBOLOS:
            rgb_matrix_set_color_all(10, 0, 50);
			break;
	}

  led_t led_state = host_keyboard_led_state();
  if (led_state.caps_lock) {
    rgb_matrix_set_color_all(50, 15.6, 0);

  }

  return false;
}

tap_dance_action_t  tap_dance_actions[] = {
  [TD_PC] = ACTION_TAP_DANCE_DOUBLE(KC_COMM, S(KC_COMM)),
  [TD_MAY] = ACTION_TAP_DANCE_DOUBLE(KC_LSFT, KC_CAPS),
};


/*
const key_override_t delete_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_BSPC, KC_DELETE);
const key_override_t bspace_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_DELETE, KC_BSPC);

// // This globally defines all key overrides to be used
const key_override_t **key_overrides = (const key_override_t *[]){
    &delete_key_override,
    &bspace_key_override,
    NULL // Null terminate the array of overrides!
};
*/

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | BLTog| Ctrl | NUME  | FN  | SIMB |    Space    | SIMB |  FN  | NUMER | ALT |  GUI |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_planck_mit(
    KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    KC_TAB,  HOME_A,    HOME_S,    HOME_D,    HOME_F,    KC_G,    KC_H,    HOME_J,    HOME_K,    HOME_L,    HOME_NT, KC_QUOT,
    TD(TD_MAY), KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    TD(TD_PC), KC_DOT,  KC_SLSH, RSFT_T(KC_ENT),
    KC_LCTL, LALT_T(KC_LGUI), NUMERIC, FNDEL, SIMBOENT,   KC_SPC,  SIMBOENT,   FNDEL, NUMERIC, KC_RALT,   KC_LGUI
),

/* Colemaks
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   F  |   P  |   G  |   J  |   L  |   U  |   Y  |   Ñ  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  |   A  |   R  |   S  |   T  |   D  |   H  |   N  |   E  |   I  |   O  |  "   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   K  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | AltI | NUME  | FN  | SIMB |    Space    | SIMB |  FN  | NUMER | ALT |  GUI |
 * `-----------------------------------------------------------------------------------'
 */
[_COLEMAK] = LAYOUT_planck_mit(
    KC_ESC,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN,    KC_BSPC,
    KC_TAB,  HOMEQ_A,    HOMEQ_R,    HOMEQ_S,    HOMEQ_T,    KC_D,    KC_H,    HOMEQ_N,    HOMEQ_E,    HOMEQ_I,    HOMEQ_O, KC_QUOT,
    TD(TD_MAY), KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_K,    KC_M,    TD(TD_PC), KC_DOT,  KC_SLSH, RSFT_T(KC_ENT),
    KC_LCTL, LALT_T(KC_LGUI), NUMERIC, FN, SIMBO,   KC_SPC,  SIMBOENT,   FNDEL, NUMERIC, KC_RALT,   KC_LGUI
),
/* SIMBOLOS
 * ,-----------------------------------------------------------------------------------.
 * |      |   =  │   *  │   +  │   @  │   \  |   €  │   $  │   [  │  ]   │  º   |  DEL |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   "  │   '  │   /  │   &  │   |  |   ¡  │   !  │   (  │  )   │  '   |  ^   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  <   │  >   │   %  │   -  │   #  |   ¿  │   ?  │   {  │  }   │  `   |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_SIMBOLOS] = LAYOUT_planck_mit(
    _______, S(KC_0), S(KC_RBRC), KC_RBRC, ALGR(KC_2), ALGR(KC_GRV), ALGR(KC_5), S(KC_4), ALGR(KC_LBRC), ALGR(KC_RBRC), KC_GRV, KC_DEL,
    _______, S(KC_2), KC_MINS, S(KC_7), S(KC_6), ALGR(KC_1), KC_EQL, S(KC_1), S(KC_8), S(KC_9), KC_MINS,  S(KC_LBRC),
    _______, KC_NUBS, S(KC_NUBS), S(KC_5), KC_SLSH, ALGR(KC_3), S(KC_EQL), S(KC_MINS), ALGR(KC_QUOT), ALGR(KC_NUHS), KC_LBRC,  _______,
    _______, _______, _______, _______, _______, _______, _______,    _______,    _______, _______, _______
),

/* Función


 * ,-----------------------------------------------------------------------------------.
 * | CatP |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | APP  |      |      |      │      | CF4  |INSERT|      |   ↑  |PGDOWN| PGUP | F12  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      │GC(L) │GC(R) │      │      | HOME │   ←  │   ↓  │   →  │  END |PrintS|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      | Bksp |      |      |             |      |      |      |      |CaturP|
 * `-----------------------------------------------------------------------------------'
 */
[_FN] = LAYOUT_planck_mit(
    SGUI(KC_S),  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5, KC_F6,  KC_F7,   KC_F8,   KC_F9,   KC_F10, KC_F11,
    KC_APP,  _______, _______, _______ , _______, LCTL(KC_F4),   KC_INS, XXXXXXX, KC_UP, KC_PGUP, KC_PGDN,  KC_F12,
    G(KC_TAB), _______, G(C(KC_LEFT)), G(C(KC_RIGHT)), _______, _______,  KC_HOME, KC_LEFT, KC_DOWN, KC_RIGHT, KC_END, KC_PSCR,
    _______, _______, KC_BSPC, _______, _______, _______, _______, _______, KC_VOLD, KC_VOLU, SGUI(KC_S)
),
/* Numerica
 * ,-----------------------------------------------------------------------------------.
 * |      | MCO  | MCOD |      |      |      |      |   7  |   8  |   9  |   -  | HOME |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |   4  |   5  |   6  |   +  |  END |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |   1  |   2  |   3  |   -  | PGUP |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |   0  |   .  |  ENT |      | PGDOW|
 * `-----------------------------------------------------------------------------------'
 */
[_NUMERICO] = LAYOUT_planck_mit(
    _______, _______, _______, _______, _______, _______, _______, KC_7, KC_8, KC_9, KC_KP_PLUS,  KC_HOME,
    _______, _______, KC_PGUP, KC_UP, KC_PGDN, _______, _______, KC_4, KC_5, KC_6, KC_KP_MINUS, KC_END,
    _______, KC_HOME, KC_LEFT, KC_DOWN, KC_RIGHT, KC_END, _______, KC_1, KC_2, KC_3, KC_KP_EQUAL, KC_PGUP,
    _______, _______, _______, _______, _______, _______, KC_0, KC_DOT, KC_ENT, _______, KC_PGDN
),

/* Adjust (Simbolos + FN)
 *                      v------------------------RGB CONTROL--------------------v
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset|Debug | RGB  |RGBMOD| HUE+ | HUE- | SAT+ | SAT- |BRGTH+|BRGTH-|  Del |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |QWERTY|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      | Vol- | Vol+ |      |COLEMA|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Prev | Next | Play | Mute |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_planck_mit(
    _______, QK_BOOT, DB_TOGG,   RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD,  RGB_VAI, RGB_VAD, KC_DEL ,
    _______, TT(_NUMERICO), _______, _______, _______, _______, _______, _______,  _______,  _______, _______, QWERTY,
    _______, _______, _______, _______, _______, _______, _______, _______,  KC_VOLD,  KC_VOLU, _______, COLEMA,
    RGB_TOG, _______, _______, _______, _______, _______, _______, KC_MPRV,  KC_MNXT, KC_MPLY, KC_MUTE
)

};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _SIMBOLOS, _FN, _ADJUST);
}

// bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//     switch (keycode) {
//         case MCO:
//             if (record->event.pressed) {
//                 // when keycode MCOMENT is pressed
//                 SEND_STRING(SS_DOWN(X_LCTL)"kc");
//             } else {
//                 // when keycode MCOMENT is released
//             }
//             break;
//         case MCOD:
//             if (record->event.pressed) {
//                 // when keycode MCOMENT is pressed
//                 SEND_STRING(SS_DOWN(X_LCTL)"ku");
//             } else {
//                 // when keycode MCOMENT is released
//             }
//             break;
//     }

//     return true;
// }

bool get_tapping_force_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case HOME_A:
            return true;
        case HOME_S:
            return true;
        case HOME_D:
            return true;
        case HOME_F:
            return true;
        case HOME_J:
            return true;
        case HOME_K:
            return true;
        case HOME_L:
            return true;
        case HOME_NT:
            return true;

        case LALT_T(KC_R):
            return true;
        case LSFT_T(KC_S):
            return true;
        case LCTL_T(KC_T):
            return true;
        case RGUI_T(KC_O):
            return true;
        case RALT_T(KC_I):
            return true;
        case RSFT_T(KC_N):
            return true;
        case RCTL_T(KC_E):
            return true;

        default:
            return false;
    }
}

// bool get_retro_tapping(uint16_t keycode, keyrecord_t *record) {
//     switch (keycode) {
//         case HOME_A:
//             return true;
//         case HOME_S:
//             return true;
//         case HOME_D:
//             return true;
//         case HOME_F:
//             return true;
//         case HOME_J:
//             return true;
//         case HOME_K:
//             return true;
//         case HOME_L:
//             return true;
//         case HOME_NT:
//             return true;

//         case LALT_T(KC_R):
//             return true;
//         case LSFT_T(KC_S):
//             return true;
//         case LCTL_T(KC_T):
//             return true;
//         case RGUI_T(KC_O):
//             return true;
//         case RALT_T(KC_I):
//             return true;
//         case RSFT_T(KC_N):
//             return true;
//         case RCTL_T(KC_E):
//             return true;

//         default:
//             return false;
//     }
// }

bool get_ignore_mod_tap_interrupt(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case HOME_A:
            return true;
        case HOME_S:
            return true;
        case HOME_D:
            return true;
        case HOME_F:
            return true;
        case HOME_J:
            return true;
        case HOME_K:
            return true;
        case HOME_L:
            return true;
        case HOME_NT:
            return true;

        case LALT_T(KC_R):
            return true;
        case LSFT_T(KC_S):
            return true;
        case LCTL_T(KC_T):
            return true;
        case RGUI_T(KC_O):
            return true;
        case RALT_T(KC_I):
            return true;
        case RSFT_T(KC_N):
            return true;
        case RCTL_T(KC_E):
            return true;

        default:
            return false;
    }
}


uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case HOME_A:
            return TAPPING_TERM + LONG_TAPPING_TERM;
        case HOME_S:
            return TAPPING_TERM + LONG_TAPPING_TERM;
        case HOME_D:
            return TAPPING_TERM + LONG_TAPPING_TERM;
        case HOME_F:
            return TAPPING_TERM + LONG_TAPPING_TERM;
        case HOME_J:
            return TAPPING_TERM + LONG_TAPPING_TERM;
        case HOME_K:
            return TAPPING_TERM + LONG_TAPPING_TERM;
        case HOME_L:
            return TAPPING_TERM + LONG_TAPPING_TERM;
        case HOME_NT:
            return TAPPING_TERM + LONG_TAPPING_TERM;

        case LALT_T(KC_R):
            return TAPPING_TERM + LONG_TAPPING_TERM;
        case LSFT_T(KC_S):
            return TAPPING_TERM + LONG_TAPPING_TERM;
        case LCTL_T(KC_T):
            return TAPPING_TERM + LONG_TAPPING_TERM;
        case RGUI_T(KC_O):
            return TAPPING_TERM + LONG_TAPPING_TERM;
        case RALT_T(KC_I):
            return TAPPING_TERM + LONG_TAPPING_TERM;
        case RSFT_T(KC_N):
            return TAPPING_TERM + LONG_TAPPING_TERM;
        case RCTL_T(KC_E):
            return TAPPING_TERM + LONG_TAPPING_TERM;

        default:
            return TAPPING_TERM;
    }
}

