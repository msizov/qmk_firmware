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


#include <stdio.h>
char wpm_str[10];

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
  }
  return true;
}



//#ifdef OLED_DRIVER_ENABLE
// WPM-responsive animation stuff here
#    define IDLE_FRAMES 2
#    define IDLE_SPEED 20  // below this wpm value your animation will idle

// #define PREP_FRAMES 1 // uncomment if >1

#    define TAP_FRAMES 2//2
#    define TAP_SPEED 40  // above this wpm value typing animation to trigger

#    define ANIM_FRAME_DURATION 200  // how long each frame lasts in ms
// #define SLEEP_TIMER 60000 // should sleep after this period of 0 wpm, needs fixing
#    define ANIM_SIZE 144 //636  // number of bytes in array, minimize for adequate firmware size, max is 1024

uint32_t anim_timer         = 0;
uint32_t anim_sleep         = 0;
uint8_t  current_frame = 0;
// uint8_t current_prep_frame = 0; // uncomment if PREP_FRAMES >1

// Code containing pixel art, contains:
// 5 idle frames, 1 prep frame, and 2 tap frames

// To make your own pixel art:
// save a png/jpeg of an 128x32 image (resource: https://www.pixilart.com/draw )
// follow this guide up to and including "CONVERT YOUR IMAGE" https://docs.splitkb.com/hc/en-us/articles/360013811280-How-do-I-convert-an-image-for-use-on-an-OLED-display-
// replace numbers in brackets with your own
// if you start getting errors when compiling make sure you didn't accedentally delete a bracket
static void render_anim(void) {
    static const char PROGMEM idle[IDLE_FRAMES][ANIM_SIZE] = {
	{
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x30, 0x08, 0x04, 0xfc, 0x00, 0x00, 0x00, 
	0x00, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0x42, 0x62, 0x52, 0x4a, 0x46, 0x42, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0xfc, 0x62, 0x01, 0x08, 0x48, 0x00, 0x00, 0x01, 0x22, 0xa2, 0x81, 
	0x01, 0x1c, 0xe2, 0x01, 0x00, 0x12, 0x1a, 0x16, 0x12, 0x00, 0x00, 0x80, 0x80, 0x80, 0x80, 0x00, 
	0x02, 0x06, 0x04, 0x08, 0x18, 0x10, 0x3d, 0x26, 0x40, 0xc1, 0x83, 0x02, 0x00, 0x00, 0x81, 0x01, 
	0x1c, 0x8a, 0x09, 0x70, 0xa0, 0x80, 0x18, 0xa4, 0x42, 0x02, 0x03, 0xa7, 0x6f, 0x1f, 0x1f, 0x0f, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x03, 0x02, 0x04, 0x0d, 
	0x09, 0x18, 0x10, 0x20, 0x60, 0x41, 0xc1, 0xbc, 0x84, 0x02, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00
	}, {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0x30, 0x08, 0xf8, 0x00, 0x00, 0x00, 
	0x00, 0x80, 0x80, 0x80, 0x80, 0x84, 0x06, 0x17, 0x15, 0x95, 0x54, 0x34, 0x14, 0x04, 0x04, 0x04, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0xf8, 0x64, 0x02, 0x11, 0x90, 0x00, 0x00, 0x01, 0x22, 0xa2, 0x81, 
	0x01, 0x10, 0xec, 0x03, 0x01, 0x90, 0xd0, 0xb2, 0x93, 0x02, 0x82, 0xc2, 0xc2, 0x80, 0x00, 0x00, 
	0x02, 0x06, 0x04, 0x08, 0x18, 0x11, 0x3d, 0x26, 0x40, 0xc4, 0x84, 0x04, 0x00, 0x00, 0x41, 0x81, 
	0x9c, 0x4a, 0x09, 0x70, 0xa0, 0x80, 0xbc, 0x62, 0x02, 0x01, 0x61, 0xb3, 0x0f, 0x0f, 0x07, 0x06, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x03, 0x02, 0x04, 0x0c, 
	0x08, 0x18, 0x10, 0x20, 0x60, 0x41, 0xc0, 0xbc, 0x86, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00
	}

    };
    static const char PROGMEM tap[TAP_FRAMES][ANIM_SIZE] = {
	{
	0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x80, 0x60, 0x18, 0x04, 0x02, 0xfe, 0x00, 0x00, 0x80, 0x80, 
	0x40, 0x40, 0xc0, 0x41, 0x03, 0x02, 0xce, 0x3a, 0x13, 0x10, 0x10, 0x0e, 0x02, 0x03, 0x01, 0x00, 
	0x20, 0x33, 0x16, 0x00, 0x7e, 0xb1, 0x26, 0x82, 0x20, 0x00, 0x00, 0x00, 0x91, 0xd9, 0x80, 0x00, 
	0x0e, 0xf1, 0x00, 0x00, 0x80, 0x40, 0x20, 0x30, 0x70, 0xf8, 0xfc, 0xfe, 0xfe, 0xf8, 0xf0, 0x40, 
	0x02, 0xe6, 0x3c, 0x0e, 0x06, 0x03, 0x82, 0x60, 0x41, 0xc1, 0x80, 0x00, 0x00, 0x01, 0x00, 0x1e, 
	0x09, 0x24, 0x14, 0x47, 0x85, 0xf8, 0x10, 0xa0, 0x40, 0x08, 0x15, 0xa7, 0x43, 0x01, 0x00, 0x00, 
	0xe0, 0x38, 0x0d, 0x02, 0x12, 0x32, 0xe1, 0x80, 0x04, 0x1c, 0x71, 0xe1, 0xe3, 0xc2, 0x84, 0x0c, 
	0x0a, 0x1a, 0x13, 0x21, 0x60, 0x41, 0xc1, 0xbc, 0x84, 0x02, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00},

	{
	0x04, 0x18, 0x34, 0x23, 0xe0, 0x00, 0x00, 0x00, 0xc0, 0x30, 0x08, 0x04, 0xfc, 0x00, 0x00, 0x00, 
	0x00, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0x80, 0x80, 0x80, 0xf8, 0x44, 0x62, 0x23, 0x30, 0x18, 
	0x04, 0x0c, 0x08, 0x00, 0x00, 0xfc, 0x62, 0x0d, 0x04, 0x40, 0x00, 0x00, 0x01, 0x22, 0xb2, 0x81, 
	0x01, 0x1c, 0xe2, 0x01, 0x00, 0x80, 0x40, 0x41, 0x60, 0xe0, 0xf0, 0xf8, 0xf0, 0xe0, 0x80, 0x00, 
	0x82, 0x1e, 0x31, 0x25, 0x29, 0x22, 0x30, 0x20, 0x41, 0xc1, 0x81, 0x00, 0xc0, 0x00, 0x01, 0x01, 
	0x1c, 0x0a, 0x09, 0x70, 0xa7, 0x88, 0x10, 0xa0, 0x40, 0x00, 0x19, 0xa7, 0x47, 0x03, 0x01, 0x00, 
	0x01, 0x03, 0x03, 0x81, 0xc3, 0x44, 0xe2, 0x24, 0x00, 0x18, 0x25, 0x43, 0x40, 0x20, 0x10, 0x48, 
	0xc8, 0x58, 0x90, 0x20, 0x60, 0x41, 0xc1, 0xbc, 0x84, 0x02, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00
	}
    };
    

    // assumes 1 frame prep stage
    void animation_phase(void) {
        current_frame = current_frame ^ 1;
        if (get_current_wpm() <= IDLE_SPEED) {    
            oled_write_raw_P(idle[current_frame], ANIM_SIZE);
        } else
        //if (get_current_wpm() > IDLE_SPEED && get_current_wpm() < TAP_SPEED) {
        //    // oled_write_raw_P(prep[abs((PREP_FRAMES-1)-current_prep_frame)], ANIM_SIZE); // uncomment if IDLE_FRAMES >1
        //    oled_write_raw_P(prep[0], ANIM_SIZE);  // remove if IDLE_FRAMES >1
        //}
        //if (get_current_wpm() >= TAP_SPEED) {
	{
            oled_write_raw_P(tap[current_frame], ANIM_SIZE);
        }
    }
    if (get_current_wpm() != 000) {
        oled_on();  // not essential but turns on animation OLED with any alpha keypress
        if (timer_elapsed32(anim_timer) > ANIM_FRAME_DURATION) {
            anim_timer = timer_read32();
            animation_phase();
        }
        anim_sleep = timer_read32();
    } else {
      //        if (timer_elapsed32(anim_sleep) > OLED_TIMEOUT) {
      //      oled_off();
	    //  } else {
            if (timer_elapsed32(anim_timer) > ANIM_FRAME_DURATION) {
                anim_timer = timer_read32();
                animation_phase();
           }
	    //  }
    }
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) { return OLED_ROTATION_270; }

// Used to draw on to the oled screen
bool oled_task_user(void) {
  //render_anim();  // renders pixelart
    oled_set_cursor(0, 0);                            // sets cursor to (row, column) using charactar spacing (5 rows on 128x32 screen, anything more will overflow back to the top)
    sprintf(wpm_str, "WPM\n%03d\n", get_current_wpm());  // edit the string to change wwhat shows up, edit %03d to change how many digits show up
    oled_write(wpm_str, false);                       // writes wpm on top left corner of string

    switch (get_highest_layer(layer_state)) {
        case _WORKMAN:
            oled_write_P(PSTR("WRKMN\n"), false);
            break;
        case _LOWER:
            oled_write_P(PSTR("LOWER\n"), false);
            break;
        case _RAISE:
            oled_write_P(PSTR("RAISE\n"), false);
            break;
        case _ADJUST:
            oled_write_P(PSTR("ADJST\n"), false);
            break;
        default:
            oled_write_P(PSTR("ERMAC\n"), false);
    }

    // Host Keyboard LED Status
    led_t led_state = host_keyboard_led_state();
    char state[5] = {0,0,0,0,0};
    state[0] =led_state.caps_lock ?  'C' : ' ';
    state[2] =led_state.num_lock ?  'N' : ' ';
    state[4] =led_state.scroll_lock ?  'S' : ' ';
    oled_write(state, false);
    oled_set_cursor(0, 5);
    //oled_write_P(led_state.scroll_lock ? PSTR("SCRLK \n") : PSTR("lel  "), false);
    //render_anim();
    render_anim();
    return true;
}
//#endif
