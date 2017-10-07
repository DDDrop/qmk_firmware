#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"

#define BASE  0
#define SYMB  1
#define MCCR  2

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = KEYMAP(KC_GRAVE,KC_1,KC_2,KC_3,KC_4,KC_5,TG(1),KC_TAB,KC_Q,KC_W,KC_E,KC_R,KC_T,KC_EQUAL,LCTL(LALT(KC_SPACE)),KC_A,KC_S,KC_D,KC_F,KC_G,KC_LSHIFT,LT(1,KC_Z),KC_X,KC_C,KC_V,KC_B,ALL_T(KC_NO),_______,LT(2,KC_QUOTE),KC_LCTL,KC_LALT,KC_LGUI,KC_LEFT,KC_RIGHT,KC_HOME,KC_SPACE,KC_BSPACE,KC_END,TG(2),KC_6,KC_7,KC_8,KC_9,KC_0,KC_ESCAPE,KC_MINUS,KC_Y,KC_U,KC_I,KC_O,KC_P,_______,KC_H,KC_J,KC_K,KC_L,_______,_______,MEH_T(KC_NO),KC_N,KC_M,KC_COMMA,KC_DOT,LT(1,KC_SLASH),KC_RSHIFT,KC_LGUI,KC_LBRACKET,KC_RBRACKET,LT(2,KC_BSLASH),TG(3),KC_UP,KC_DOWN,KC_PGUP,KC_PGDOWN,KC_TAB,KC_ENTER),

    [1] = KEYMAP(KC_ESCAPE,KC_F1,KC_F2,KC_F3,KC_F4,KC_F5,KC_F6,_______,_______,_______,KC_UP,_______,_______,_______,_______,_______,KC_LEFT,KC_DOWN,KC_RIGHT,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,KC_F7,KC_F8,KC_F9,KC_F10,KC_F11,KC_F12,_______,_______,KC_1,KC_2,KC_3,KC_4,KC_5,_______,KC_6,KC_7,KC_8,KC_9,KC_0,_______,_______,_______,KC_RSHIFT,KC_LALT,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______),

    [2] = KEYMAP(RESET,_______,_______,_______,_______,_______,_______,_______,_______,_______,KC_MS_UP,_______,_______,_______,_______,_______,KC_MS_LEFT,KC_MS_DOWN,KC_MS_RIGHT,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,KC_MS_BTN1,KC_MS_BTN2,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,KC_MEDIA_PLAY_PAUSE,_______,_______,_______,KC_MEDIA_PREV_TRACK,KC_MEDIA_NEXT_TRACK,_______,_______,KC_AUDIO_VOL_UP,KC_AUDIO_VOL_DOWN,KC_AUDIO_MUTE,_______,_______,_______,_______,_______,_______,_______,KC_WWW_BACK),

    [3] = KEYMAP(KC_ESCAPE,KC_5,KC_6,KC_7,KC_8,_______,_______,KC_TAB,KC_1,KC_2,KC_3,KC_4,KC_P,_______,_______,KC_Q,KC_W,KC_E,KC_R,_______,KC_LSHIFT,_______,_______,KC_D,KC_F,KC_B,_______,_______,_______,KC_LCTL,KC_LALT,KC_A,_______,_______,_______,KC_SPACE,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______),
};

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(SYMB)                // FN1 - Momentary Layer 1 (Symbols)
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
        if (record->event.pressed) {
          register_code(KC_RSFT);
        } else {
          unregister_code(KC_RSFT);
        }
        break;
      }
    return MACRO_NONE;
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {

};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
      // TODO: Make this relevant to the ErgoDox EZ.
        case 1:
            ergodox_right_led_1_on();
            break;
        case 2:
            ergodox_right_led_2_on();
            break;
        case 3:
            ergodox_right_led_3_on();
            break;
        default:
            // none
            break;
    }

};
