// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include "keymap_us_extended.h"
#include QMK_KEYBOARD_H

void keyboard_pre_init_user(void) {
    setPinOutput(GP18); // Shift
    writePinHigh(GP18);
    setPinOutput(GP19); // Square
    writePinHigh(GP19);
    setPinOutput(GP20); // Circle
    writePinHigh(GP20);
    setPinOutput(GP21); // People Button
    writePinHigh(GP21);
}

void oneshot_mods_changed_user(uint8_t mods) {
  if (mods & MOD_MASK_SHIFT) {
    writePinLow(GP18);
  }
  if (!mods) {
    writePinHigh(GP18);
  }
}

void oneshot_layer_changed_user(uint8_t layer) {
  if (layer == 1) {
    writePinLow(GP19);
  }
  if (layer == 2) {
    writePinLow(GP20);
  }
  if (!layer) {
    writePinHigh(GP19);
    writePinHigh(GP20);
  }
}

bool dip_switch_update_user(uint8_t index, bool active) { 
    switch (index) {
        case 0:
            if(active) { tap_code(KC_MS_BTN1); } else {  }
            break;
        case 1:
            if(active) { tap_code(KC_VOLD); } else {  }
            break;
        case 2:
            if(active) { tap_code(KC_VOLU); } else {  }
            break;
        case 3:
            if (active) { tap_code(KC_MS_BTN3); } else {  }
            break;
    }
    return true;
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [0] = LAYOUT_7x7(
        KC_1,		    KC_2,		KC_3,		KC_4,	KC_5,	KC_6,		KC_7,
        KC_Q,		    KC_W,		KC_E,		KC_R,	KC_T,	KC_Y,		KC_U,
        KC_A,		    KC_S,		KC_D,		KC_F,	KC_G,	KC_H,		KC_J,
        OSM(MOD_LSFT),	KC_Z,		KC_X,		KC_C,	KC_V,	KC_B,		KC_N,
        OSL(1),	        KC_LWIN,	KC_LEFT,	KC_SPC,	KC_DOT,	KC_M,		KC_RGHT, 
        KC_K,		    KC_I,		KC_O,		KC_NO,	KC_NO,	KC_L,		KC_BSPC,
        KC_8,		    KC_9,		KC_0,		KC_P,	KC_ENT,	KC_COMM,	OSL(2)
    ),
    [1] = LAYOUT_7x7(
        KC_1,		    KC_2,		KC_3,		KC_4,       KC_5,	    KC_6,		    KC_7,
        US_EXLM,		US_AT,		US_EURO,	US_HASH,	US_PERC,	US_CIRC,	US_AMPR,
        US_TILD,		KC_NO,		US_LCBR,	US_RCBR,	US_DIAE,	US_SLSH,	US_QUOT,
        KC_CAPS,	    US_GRV,		US_LDAQ,	US_RDAQ,	US_MINS,	US_PIPE,	US_LABK,
        KC_NO,	        BL_STEP,	KC_LEFT,	KC_SPC,	    US_QUES,	US_RABK,	KC_RGHT, 
        US_LBRC,		US_ASTR,	US_LPRN,	KC_NO,	    KC_NO,	    US_RBRC,	KC_BSPC,
        KC_8,		    KC_9,		KC_0,		US_RPRN,	KC_ENT,	    US_COLN,	KC_NO
    ),
    [2] = LAYOUT_7x7(
        KC_1,		    KC_2,		KC_3,		KC_4,	    KC_5,	    KC_6,		KC_7,
        US_IEXL,		US_ARNG,	US_EACU,	US_DLR,	    US_THRN,	KC_NO,		US_UACU,
        US_AACU,		US_SS,		KC_NO,		US_PND,	    US_YEN,	    US_BSLS,	US_DQUO,
        KC_RSFT,	    US_AE,		US_OE,		US_CCED,	US_UNDS,	US_PLUS,	US_NTIL,
        KC_NO,      	KC_LWIN,	KC_LEFT,	KC_SPC,	    US_IQUE,	US_MICR,	KC_RGHT, 
        KC_NO,	    	US_IACU,	US_OACU,	KC_NO,	    KC_NO,	    US_OSTR,	KC_BSPC,
        KC_8,		    KC_9,		KC_0,		US_EQL,	    KC_ENT,	    US_SCLN,	KC_NO

    )
};
