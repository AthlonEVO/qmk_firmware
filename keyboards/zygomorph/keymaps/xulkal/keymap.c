#include QMK_KEYBOARD_H
#include "xulkal.h"

#ifdef PROTOCOL_LUFA
#include "lufa.h"
#include "split_util.h"
#endif

#define EXPAND_LAYOUT(...) LAYOUT_5x12(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /*  / QWERTY \
   * /-----------------------------------------\  /-----------------------------------------\
   * | GESC |   1  |   2  |  3   |  4   |  5   |  |  6   |  7   |  8   |  9   |  0   | BkSp |
   * |------+------+------+------+------+------|  |------+------+------+------+------+------|
   * | Tab  |   Q  |   W  |  E   |  R   |  T   |  |  Y   |  U   |  I   |  O   |  P   |   \  |
   * |------+------+------+------+------+------|  |------+------+------+------+------+------|
   * |FN(CAPS)| A  |   S  |   D  |  F   |  G   |  |  H   |  J   |  K   |  L   |  ;   | Enter|
   * |------+------+------+------+------+------|  |------+------+------+------+------+------|
   * | Sft[ |   Z  |   X  |   C  |  V   |  B   |  |  N   |  M   |  ,   |  .   |  /   | Sft] |
   * |------+------+------+------+------+------|  |------+------+------+------+------+------|
   * | Ctl- |  Win | LOWER| RAISE| Alt  | Space|  | Space| Left |  Up  | Down | Right| Ctl= |
   * \------+------+------+------+------+------/  \------+------+------+------+------+------/
   */
  [_QWERTY] = EXPAND_LAYOUT( \
    _________________QWERTY_L1_________________,  _________________QWERTY_R1_________________, \
    _________________QWERTY_L2_________________,  _________________QWERTY_R2_________________, \
    _________________QWERTY_L3_________________,  _________________QWERTY_R3_________________, \
    _________________QWERTY_L4_________________,  _________________QWERTY_R4_________________, \
    _________________QWERTY_L5_________________,  _________________QWERTY_R5_________________ \
  ),

#ifndef GAMELAYER_DISABLE
  [_GAME] = EXPAND_LAYOUT( \
    ___________________GAME_L1_________________,  ___________________GAME_R1_________________, \
    ___________________GAME_L2_________________,  ___________________GAME_R2_________________, \
    ___________________GAME_L3_________________,  ___________________GAME_R3_________________, \
    ___________________GAME_L4_________________,  ___________________GAME_R4_________________, \
    ___________________GAME_L5_________________,  ___________________GAME_R5_________________ \
  ),
#endif

  [_LOWER] =  EXPAND_LAYOUT( \
    __________________LOWER_L1_________________,  __________________LOWER_R1_________________, \
    __________________LOWER_L2_________________,  __________________LOWER_R2_________________, \
    __________________LOWER_L3_________________,  __________________LOWER_R3_________________, \
    __________________LOWER_L4_________________,  __________________LOWER_R4_________________, \
    __________________LOWER_L5_________________,  __________________LOWER_R5_________________ \
  ),

  [_RAISE] = EXPAND_LAYOUT( \
    __________________RAISE_L1_________________,  __________________RAISE_R1_________________, \
    __________________RAISE_L2_________________,  __________________RAISE_R2_________________, \
    __________________RAISE_L3_________________,  __________________RAISE_R3_________________, \
    __________________RAISE_L4_________________,  __________________RAISE_R4_________________, \
    __________________RAISE_L5_________________,  __________________RAISE_R5_________________ \
  ),

#ifdef TRILAYER_ENABLED
  [_ADJUST] = EXPAND_LAYOUT( \
    _________________ADJUST_L1_________________,  _________________ADJUST_R1_________________, \
    _________________ADJUST_L2_________________,  _________________ADJUST_R2_________________, \
    _________________ADJUST_L3_________________,  _________________ADJUST_R3_________________, \
    _________________ADJUST_L4_________________,  _________________ADJUST_R4_________________, \
    _________________ADJUST_L5_________________,  _________________ADJUST_R5_________________ \
  ),
#endif
};

#ifdef ENCODER_ENABLE
void encoder_update_user(uint8_t index, bool clockwise) {
  if (index == 0) { /* First encoder */
    if (clockwise) {
      tap_code(KC_PGDN);
    } else {
      tap_code(KC_PGUP);
    }
  } else if (index == 1) { /* Second encoder from slave */
    if (clockwise) {
      tap_code(KC_UP);
    } else {
      tap_code(KC_DOWN);
    }
  }
}
#endif
