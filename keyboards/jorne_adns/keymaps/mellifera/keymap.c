// Copyright 2021 Joric (@joric)
// SPDX-License-Identifier: GPL-2.0-or-later
#include QMK_KEYBOARD_H
#include "timer.h"
#include "mousekey.h"
enum layers {
    _WORKMAN = 0,
    _QWERTY,
    _LOWER,
    _RAISE,
    _ADJUST,
    _MOUSE
};


enum custom_keycodes {
    RGBRST = SAFE_RANGE
};

#define RBR_RGU MT(MOD_RGUI, KC_RBRC)
#define F12_RGU MT(MOD_RGUI, KC_F12)
#define PLS_LCT MT(MOD_LCTL, KC_PPLS)
#define EQL_LCT MT(MOD_LCTL, KC_PEQL)
#define APP_LCT MT(MOD_LCTL, KC_APP)
#define EQL_RCT MT(MOD_RCTL, KC_PEQL)
#define QUO_RCT MT(MOD_RCTL, KC_QUOT)
#define APP_RCT MT(MOD_RCTL, KC_APP)
#define MIN_RCT MT(MOD_RCTL, KC_MINS)
#define EQL_LAL MT(MOD_LALT, KC_EQL)
#define BSL_RAL MT(MOD_RALT, KC_BSLS)
#define BSP_LSH MT(MOD_LSFT, KC_BSPC)
#define SPC_RSH MT(MOD_RSFT, KC_SPC)
#define DEL_RSE LT(_RAISE, KC_DEL)
#define TAB_RSE LT(_RAISE, KC_TAB)
#define ENT_LWR LT(_LOWER, KC_ENT)
#define ESC_LWR LT(_LOWER, KC_ESC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_WORKMAN] = LAYOUT(
  DF(_QWERTY), KC_LBRC, KC_Q,    KC_D,    KC_R,    KC_W,    KC_B,         KC_J,    KC_F,    KC_U,    KC_P,    KC_SCLN, KC_RBRC, RGUI_T(KC_GRV),
               KC_LCTL, KC_A,    KC_S,    KC_H,    KC_T,    KC_G,         KC_Y,    KC_N,    KC_E,    KC_O,    KC_I,    RCTL_T(KC_QUOT),
               KC_LALT, KC_Z,    KC_X,    KC_M,    KC_C,    KC_V,         KC_K,    KC_L,    KC_COMM,    KC_DOT,     KC_SLSH, BSL_RAL,
                                      TAB_RSE, SPC_RSH, ENT_LWR,      ESC_LWR, BSP_LSH, DEL_RSE
),
							      
[_QWERTY] = LAYOUT(
  DF(_WORKMAN), KC_GRV,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, RGUI_T(KC_RBRC),
           KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,         KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, RCTL_T(KC_QUOT),
           KC_LALT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,         KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, BSL_RAL,
                                      TAB_RSE, SPC_RSH, ENT_LWR,      ESC_LWR, BSP_LSH, DEL_RSE
),

[_LOWER] = LAYOUT(
  _______, KC_UNDS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,        KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  F12_RGU,
           PLS_LCT, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, MIN_RCT,
           EQL_LAL, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
                                      _______, _______, _______,      _______, _______, _______
),

[_RAISE] = LAYOUT(
  _______, KC_NLCK, KC_PSLS, KC_P7,   KC_P8,   KC_P9,   KC_PMNS,      KC_VOLU, KC_HOME, KC_PSCR, KC_PGUP, KC_SLCK, KC_CAPS, _______,
           EQL_LCT, KC_PAST, KC_P4,   KC_P5,   KC_P6,   KC_PPLS,      KC_MUTE, KC_LEFT, KC_UP,   KC_RGHT, KC_INS,  APP_RCT,
           _______, KC_P0,   KC_P1,   KC_P2,   KC_P3,   KC_PCMM,      KC_VOLD, KC_END,  KC_DOWN, KC_PGDN, KC_PAUS, _______,
                                      _______, _______, _______,      _______, _______, _______
),

[_ADJUST] = LAYOUT(
  RESET,   RGBRST,  KC_ASUP, KC_ASTG, KC_ASDN, _______, _______,      _______, _______, KC_ASDN, KC_ASTG, KC_ASUP, RGBRST,  RESET,
           RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, _______, _______,      _______, _______, RGB_VAI, RGB_SAI, RGB_HUI, RGB_TOG,
           RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, _______, _______,      _______, _______, RGB_VAD, RGB_SAD, RGB_HUD, RGB_MOD,
                                      _______, SH_TG,   _______,      _______, SH_TG,   _______
),

[_MOUSE] = LAYOUT(
  _______, _______, _______, _______, _______, _______, _______,      _______, _______, KC_WH_U, _______, _______, _______, _______,
           _______, _______, _______, _______, _______, _______,      _______, KC_BTN1, KC_BTN3, KC_BTN2, _______, _______,
           _______, _______, _______, _______, _______, _______,      _______, _______, KC_WH_D, _______, _______, _______,
                                      _______, _______, _______,      _______, _______, _______
),

};

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

extern uint32_t track_timer;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  //if ((timer_elapsed(track_timer) < 3000) && !timer_expired(track_timer, timer_read()) && track_timer != 0) {
  //  layer_on(_MOUSE);
  //} else {
  //  layer_off(_MOUSE);
  //  track_timer = 0xFFFF;
  //}
  switch (keycode) {
    case RGBRST:
      #ifdef RGBLIGHT_ENABLE
        if (record->event.pressed) {
          eeconfig_update_rgblight_default();
          rgblight_enable();
        }
      #endif
      break;
    case KC_BTN1:
    case KC_BTN2:
    case KC_BTN3:
    track_timer = timer_read32();
    if (record->event.pressed) {
      mousekey_on(keycode);
      mousekey_send();
    } else {
      mousekey_off(keycode);
      mousekey_send();
    }
    
    break;
    case KC_WH_U:
    case KC_WH_D:
    track_timer = timer_read32();
    break;
  }
  return true;
}

