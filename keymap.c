
#include QMK_KEYBOARD_H
#include "keymap_spanish.h"

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
    SIMBO,
    MOUSE,
    NUMERIC,
    ADJUST,
    TDPC,
    TDALT,
    TDMAY,
};

enum {
    TD_PC = 0,
    TD_ALT,
    TD_MAY,
};

#define QWERTY TT(_QWERTY)
#define COLEMA TT(_COLEMAK)
#define FN TT(_FN)
#define SIMBO TT(_SIMBOLOS)
#define MOUSE TT(_MOUSE)
#define NUMERIC TT(_NUMERICO)

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
#define HOME_NT LGUI_T(ES_NTIL)
#define HOME_K LALT_T(KC_K)
#define HOME_L LCTL_T(KC_L)
#define HOME_J RSFT_T(KC_J)

#define REDO LCTL(KC_Y)
#define UNDO LCTL(KC_Z)
#define CUT LCTL(KC_X)
#define COPY LCTL(KC_C)
#define PASTE LCTL(KC_V)
#define M_CF4 LCTL(KC_F4)
#define M_WE G(KC_E)

#define ES_LESS_MAC KC_GRAVE
#define ES_GRTR_MAC LSFT(KC_GRAVE)
#define ES_BSLS_MAC ALGR(KC_6)
#define NO_PIPE_ALT KC_GRAVE
#define NO_BSLS_ALT KC_EQUAL
#define LSA_T(kc) MT(MOD_LSFT | MOD_LALT, kc)
#define BP_NDSH_MAC ALGR(KC_8)

//layer led colors

void rgb_matrix_indicators_user(void) {
    if(IS_LAYER_ON(_QWERTY)) {
        rgb_matrix_set_color(11, 0, 40, 50);
    }

    if(IS_LAYER_ON(_COLEMAK)) {
        rgb_matrix_set_color(11, 50, 10, 20);
    }

    //layer indicators

    if(IS_LAYER_ON(_NUMERICO)) {
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
    }

    if(IS_LAYER_ON(_ADJUST)) {
        rgb_matrix_set_color(39, 50, 10, 20);
        rgb_matrix_set_color(19, 50, 10, 20);
        rgb_matrix_set_color(22, 50, 10, 20);
        rgb_matrix_set_color(42, 50, 10, 20);
    }

    if(IS_LAYER_ON(_FN)) {
        rgb_matrix_set_color(39, 50, 0, 0);

        rgb_matrix_set_color(20, 50, 0, 0);
        rgb_matrix_set_color(31, 50, 0, 0);
        rgb_matrix_set_color(32, 50, 0, 0);
        rgb_matrix_set_color(33, 50, 0, 0);

        rgb_matrix_set_color(42, 50, 0, 0);
        rgb_matrix_set_color(43, 50, 0, 0);
        rgb_matrix_set_color(44, 50, 0, 0);
    }

    if(IS_LAYER_ON(_SIMBOLOS)) {
        rgb_matrix_set_color_all(10, 0, 50);

        // rgb_matrix_set_color(42, 10, 0, 50);

        // rgb_matrix_set_color(2, 10, 0, 50);
        // rgb_matrix_set_color(3, 10, 0, 50);
        // rgb_matrix_set_color(4, 10, 0, 50);

        // rgb_matrix_set_color(14, 10, 0, 50);
        // rgb_matrix_set_color(15, 10, 0, 50);
        // rgb_matrix_set_color(16, 10, 0, 50);

        // rgb_matrix_set_color(26, 10, 0, 50);
        // rgb_matrix_set_color(27, 10, 0, 50);
        // rgb_matrix_set_color(28, 10, 0, 50);

        // rgb_matrix_set_color(38, 10, 0, 50);
        // rgb_matrix_set_color(39, 10, 0, 50);
        // rgb_matrix_set_color(40, 10, 0, 50);
    }

    //capslock leds

    if (host_keyboard_leds() & (1<<USB_LED_CAPS_LOCK)) {
        rgb_matrix_set_color_all(50, 15.6, 0);
    }

}

qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_PC] = ACTION_TAP_DANCE_DOUBLE(KC_COMM, S(KC_COMM)),
  [TD_ALT] = ACTION_TAP_DANCE_DOUBLE(KC_RALT, KC_LALT),
  [TD_MAY] = ACTION_TAP_DANCE_DOUBLE(KC_LSFT, KC_CAPS),
};

#define TDPC TD(TD_PC)
#define TDALT TD(TD_ALT)
#define TDMAY TD(TD_MAY)

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
    KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    TDMAY, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    TD(TD_PC), KC_DOT,  KC_SLSH, RSFT_T(KC_ENT),
    KC_LCTL, KC_LALT, NUMERIC, FN, SIMBO,   KC_SPC,  SIMBO,   FN, NUMERIC, KC_RALT,   KC_LGUI
),

/* Colemaks
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   F  |   P  |   G  |   J  |   L  |   U  |   Y  |   Ñ  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  |   A  |   R  |   S  |   T  |   D  |   H  |   N  |   E  |   I  |   O  |  "   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   K  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | BLTog| Ctrl | NUME  | FN  | SIMB |    Space    | SIMB |  FN  | NUMER | ALT |  GUI |
 * `-----------------------------------------------------------------------------------'
 */
[_COLEMAK] = LAYOUT_planck_mit(
    KC_ESC,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN,    KC_BSPC,
    KC_TAB,  KC_A,    KC_R,    KC_S,    KC_T,    KC_D,    KC_H,    KC_N,    KC_E,    KC_I,    KC_O, KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, RSFT_T(KC_ENT),
    KC_LCTL, KC_LALT, NUMERIC, FN, SIMBO,   KC_SPC,  SIMBO,   FN, NUMERIC, KC_RALT,   KC_LGUI
),

/* SIMBOLOS
 * ,-----------------------------------------------------------------------------------.
 * |      |   =  │   *  │   +  │   @  │   \  |   €  │   $  │   [  │  ]   │  º   |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   "  │   '  │   /  │   &  │   |  |   ¡  │   !  │   (  │  )   │      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  <   │  >   │   %  │   -  │   #  |   ¿  │   ?  │   {  │  }   │      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_SIMBOLOS] = LAYOUT_planck_mit(
    _______, ES_EQL, ES_ASTR, ES_PLUS, ES_AT, ES_BSLS, ES_EURO, S(KC_4), ES_LBRC, ES_RBRC, ES_MORD, KC_DEL,
    _______, S(KC_2), ES_QUOT, ES_SLSH, ES_AMPR, ES_PIPE, ES_IEXL, ES_EXLM, ES_LPRN, ES_RPRN, _______, _______,
    _______, ES_LABK, ES_RABK, S(KC_5), KC_SLSH, ES_HASH, ES_IQUE, ES_QUES, ES_LCBR, ES_RCBR, _______,  _______,
    _______, _______, _______, _______, _______, _______, _______,    _______,    _______, _______, _______
),

/* Función
 * ,-----------------------------------------------------------------------------------.
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |  GE  │  CF4 |      |      |      |   ↑  |      |      | F12  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | REDO │ UNDO │ C C  │ C V  │  C C | HOME │   ←  │   ↓  │   →  │  END |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_FN] = LAYOUT_planck_mit(
    _______,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5, KC_F6,  KC_F7,   KC_F8,   KC_F9,   KC_F10, KC_F11,
    _______,  XXXXXXX, XXXXXXX, M_WE , M_CF4, XXXXXXX,   XXXXXXX, XXXXXXX, KC_UP, XXXXXXX, XXXXXXX,  KC_F12,
    _______,  REDO, UNDO, CUT, PASTE, COPY,  KC_HOME, KC_LEFT, KC_DOWN, KC_RIGHT, KC_END, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),
/* Numerica
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |   7  |   8  |   9  |   -  | HOME |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |   4  |   5  |   6  |   +  |  END |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |   1  |   2  |   3  |   -  | PGUP |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |   0  |   .  |  ENT |   =  | PGDOW|
 * `-----------------------------------------------------------------------------------'
 */
[_NUMERICO] = LAYOUT_planck_mit(
    _______, _______, _______, _______, _______, _______, _______, KC_7, KC_8, KC_9, KC_KP_PLUS,  KC_HOME,
    _______, _______, _______, _______, _______, _______, _______, KC_4, KC_5, KC_6, KC_KP_MINUS, KC_END,
    _______, _______, _______, _______, _______, _______, _______, KC_1, KC_2, KC_3, KC_KP_EQUAL, KC_PGUP,
    _______, _______, _______, _______, _______, _______, _______, KC_0, KC_DOT, KC_ENT, KC_PGDN
),

/* Adjust (Simbolos + FN)
 *                      v------------------------RGB CONTROL--------------------v
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset|Debug | RGB  |RGBMOD| HUE+ | HUE- | SAT+ | SAT- |BRGTH+|BRGTH-|  Del |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |QWERTY|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |COLEMA|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_planck_mit(
    _______, RESET,   DEBUG,   RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD,  RGB_VAI, RGB_VAD, KC_DEL ,
    _______, _______, _______, _______, _______, _______, _______, _______,  _______,  _______, _______, QWERTY,
    _______, _______, _______, _______, _______, _______, _______, _______,  _______,  _______, _______, COLEMA,
    RGB_TOG, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______
)

};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _SIMBOLOS, _FN, _ADJUST);
}

// bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//     switch (keycode) {
//         case QWERTY:
//             if (record->event.pressed) {
//                 rgblight_mode(5);
//                 set_single_persistent_default_layer(_QWERTY);
//             }
//             return false;
//             break;
//         case COLEMA:
//             if (record->event.pressed) {
//                 rgblight_mode(5);
//                 set_single_persistent_default_layer(_COLEMAK);
//             }
//             return false;
//             break;
//     }

//     return true;
// }

