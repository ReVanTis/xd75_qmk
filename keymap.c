/* Copyright 2019 ReVanTis Zhao (revantis0@gmail.com)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H

// Fillers to make layering more clear
#define ___T___ KC_TRNS

// Layer Definitions
#define _QW 0
#define _LW 1
#define _RS 2
#define _FN 3

// Custom Keycode Declarations
enum {
    BACKLIT = SAFE_RANGE,
    //blink rgb underglow with typing key presses
    TYPEBLINK,
};

// Tap Dance Declarations
enum {
    TD_ESC_CAPS = 0,
    TD_PGUP_HOME,
    TD_PGDN_END,
};

// User Config Declarations
typedef union {
  uint32_t raw;
  struct {
    bool typeblink_on :1;
  };
} user_config_t;

user_config_t user_config;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY - MIT ENHANCED / GRID COMPATIBLE
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * | `      | 1      | 2      | 3      | 4      | 5      | 6      | 7      | 8      | 9      | 0      | -      | =      | \      | BACKSP |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | TAB    | Q      | W      | E      | R      | T      | Y      | U      | I      | O      | P      | [      | ]      | INS    | DEL    |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+----------2u-----+--------|
 * | ESC    | A      | S      | D      | F      | G      | H      | J      | K      | L      | ;      | '      | XXXXXX . ENTER  | RSHIFT |
 * | 2u ----+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
 * | LSHIFT | BACKSP | Z      | X      | C      | V      | B      | N      | M      | ,      | .      | /      | PG UP  | UP     | PG DN  |
 * |--------+--------+--------+--------+--------+- 2u ------------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | LCTRL  | BRITE  |  LGUI  | LALT   | RAISE  | XXXXXX . SPACE  | LOWER  |  RALT  | RGUI   |   FN   | RCTRL  | LEFT   | DOWN   | RIGHT  |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */

 [_QW] = { /* QWERTY */
  { KC_GRV,          KC_1,     KC_2,    KC_3,    KC_4,           KC_5,    KC_6,    KC_7,           KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,           KC_BSLS, KC_BSPC  },
  { KC_TAB,          KC_Q,     KC_W,    KC_E,    KC_R,           KC_T,    KC_Y,    KC_U,           KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,          KC_INS , KC_DEL   },
  {TD(TD_ESC_CAPS),  KC_A,     KC_S,    KC_D,    KC_F,           KC_G,    KC_H,    KC_J,           KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,           KC_ENT , KC_SFTENT},
  { KC_LSFT,         KC_BSPC,  KC_Z,    KC_X,    KC_C,           KC_V,    KC_B,    KC_N,           KC_M,    KC_COMM, KC_DOT,  KC_SLSH, TD(TD_PGUP_HOME), KC_UP,   TD(TD_PGDN_END)  },
  { KC_LCTL,         BACKLIT,  KC_LGUI, KC_LALT, MO(_RS),        KC_SPC,  KC_SPC,  MO(_LW),        KC_RALT, KC_RGUI, MO(_FN), KC_RCTL, KC_LEFT,          KC_DOWN, KC_RGHT  },
 },

/* LOWERED
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * |        | F1     | F2     | F3     | F4     | F5     | F6     | F7     | F8     | F9     | F10    | F11    | F12    |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        | !      | @      | #      | $      | %      | ^      | &      | *      | (      | )      |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------- 2u ----+--------|
 * |        | F1     | F2     | F3     | F4     | F5     | F6     | _      | +      | {      | }      | |      |        . XXXXXX |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
 * |        | F7     | F8     | F9     | F10    | F11    | F12    |        |        |        |        |        |  HOME  |        |  END   |
 * |--------+--------+--------+--------+--------+- 2u ------------+--------+--------+--------+--------+-----------------+--------+--------|
 * |        |        |        |        |        | XXXXXX .        |        |        |        |        |        |        |        |        |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */
 
 [_LW] = { /* LOWERED */
  { _______ , KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,            KC_F8,   KC_F9,           KC_F10,  KC_F11,  KC_F12,  _______, ___T___  },
{LCA(KC_TAB), _______, _______, _______, _______, _______, _______, TD(TD_PGUP_HOME), KC_UP  , TD(TD_PGDN_END), KC_HOME, _______, _______, _______, _______  },
  { _______ , KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6  , KC_LEFT,          KC_DOWN, KC_RGHT,         KC_END , _______, ___T___, ___T___, ___T___  },
  { _______ , KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_BSPC,          KC_DEL , _______,         _______, _______, KC_HOME, _______, KC_END   },
  { _______ , _______, _______, _______, _______, _______, KC_ENT , _______,          _______, _______,         _______, _______, _______, _______, _______  },
 },

/* RAISED
 * .---------------------------------------------------------------------------------------------------------------------- 2u ------------.
 * |        | F1     | F2     | F3     | F4     | F5     | F6     | F7     | F8     | F9     | F10    | F11    | F12    | XXXXXX .        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
 * |        | 1      | 2      | 3      | 4      | 5      | 6      | 7      | 8      | 9      | 0      |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+- 2u ------------+--------|
 * |        | F1     | F2     | F3     | F4     | F5     | F6     | -      | =      | [      | ]      | \      | XXXXXX .        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
 * |        | F7     | F8     | F9     | F10    | F11    | F12    |        |        |        |        |        |  HOME  |        |  END   |
 * |--------+--------+--------+--------+--------+- 2u ------------+--------+--------+--------+--------+-----------------+--------+--------|
 * |        |        |        |        |        | XXXXXX .        |        |        |        |        |        |        |        |        |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */
 
 [_RS] = { /* RAISED */
  { _______ , KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,            KC_F8,   KC_F9,           KC_F10,  KC_F11,  KC_F12,  _______, ___T___  },
{LCA(KC_TAB), _______, _______, _______, _______, _______, _______, TD(TD_PGUP_HOME), KC_UP  , TD(TD_PGDN_END), KC_HOME, _______, _______, _______, _______  },
  { _______ , KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6  , KC_LEFT,          KC_DOWN, KC_RGHT,         KC_END , _______, ___T___, ___T___, ___T___  },
  { _______ , KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12 , KC_BSPC,          KC_DEL , _______,         _______, _______, KC_HOME, _______, KC_END   },
  { _______ , _______, _______, _______, _______, _______, KC_ENT , _______,          _______, _______,         _______, _______, _______, _______, _______  },
 },
 
/* FUNCTION
 * .---------------------------------------------------------------------------------------------------------------------- 2u ------------.
 * | NUM LK | F1     | F2     | F3     | F4     | F5     | F6     | F7     | F8     | F9     | F10    | F11    | F12    | XXXXXX .        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
 * | SCR LK | F13    | F14    | F15    | F16    | F17    | F18    | F19    | F20    | F21    | F22    | F23    | F24    | PAUSE  | PR SCR |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+- 2u ------------+--------|
 * | CAP LK | MS BT5 | MS BT4 | MS BT3 | MS BT2 | SLOW M | FAST M | NEXT   | VOL-   | VOL+   | PLAY   | NKRO   | XXXXXX .        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------|
 * | RGB TG | RGB MD | RGB HI | RGB HD | RGB SI | RGB SD | RGB VI | RGB VD | BL TOG | BL INC | BL DEC |        | WHEEL+ | MOUS U | WHEEL- |
 * |--------+--------+--------+--------+--------+-- 2u -----------+--------+--------+--------+--------+-----------------+--------+--------|
 * |        | RESET  | QWERTY | COLEMK | DVORAK | XXXXXX . MS BT1 |        |        |        |        |        | MOUS L | MOUS D | MOUS R |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */
 
 [_FN] = { /* FUNCTION */
  { KC_NLCK, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,            KC_F12,  _______, ___T___  },
  { KC_SLCK, KC_F13,  KC_F14,  KC_F15,  KC_F16,  KC_F17,  KC_F18,  KC_F19,  KC_F20,  KC_F21,  KC_F22,  KC_F23,            KC_F24,  KC_PAUS, KC_PSCR  },
  { KC_CAPS, KC_BTN5, KC_BTN4, KC_BTN3, KC_BTN2, KC_ACL0, KC_ACL2, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY, MAGIC_TOGGLE_NKRO, ___T___, ___T___, ___T___  },
  { RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, BL_TOGG, BL_INC,  BL_DEC,  TYPEBLINK,         KC_WH_U, KC_MS_U, KC_WH_D  },
  { _______, RESET  , _______, _______, _______, KC_BTN1, KC_BTN2, _______, _______, _______, _______, _______,           KC_MS_L, KC_MS_D, KC_MS_R  },
 },
};

#define COLOR_RS         RGB_CHARTREUSE
#define COLOR_LW         RGB_MAGENTA
#define COLOR_FN         RGB_CORAL
#define COLOR_CAPS       RGB_RED
#define COLOR_MOD        RGB_CYAN
#define COLOR_TYPEBLINK  RGB_WHITE
#define COLOR_CUR        rgblight_config.hue,rgblight_config.sat,rgblight_config.val

#define CAPS_ON          host_keyboard_leds() & (1 << USB_LED_CAPS_LOCK)

int mod_pressed = 0;
int type_pressed = 0;

extern rgblight_config_t rgblight_config;
void led_set_user(uint8_t usb_led) {
    if (usb_led & (1 << USB_LED_CAPS_LOCK)) {
        capslock_led_on();
    } else {
        capslock_led_off();
    }
}

void keyboard_post_init_user() {
    gp100_led_off();
    user_config.raw = eeconfig_read_user();
}

void set_rgblight_by_layer(uint32_t layer)
{
    switch (biton32(layer)) {
    case _RS:
        rgblight_setrgb(COLOR_RS);
        break;
    case _LW:
        rgblight_setrgb(COLOR_LW);
        break;
    case _FN:
        rgblight_setrgb(COLOR_FN);
        break;
    default:
        if (CAPS_ON)
            rgblight_setrgb(COLOR_CAPS);
        else
            rgblight_sethsv(COLOR_CUR);
        break;
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t * record) {
    switch (keycode) {
    // Hold BACKLIT = Left Ctrl
    case BACKLIT:
        if (record -> event.pressed) {
            register_code(KC_LCTL);
            mod_pressed++;
            rgblight_setrgb(COLOR_MOD);
#ifdef BACKLIGHT_ENABLE
            backlight_step();
#endif
        } else {
            unregister_code(KC_LCTL);
            mod_pressed--;
            if (mod_pressed == 0)
                set_rgblight_by_layer(layer_state);
        }
        return false;
        break;
    //Ctrl/Shift/Alt/Win/Enter keys will change underglow to COLOR_MOD
    case KC_LSFT:
    case KC_LCTL:
    case KC_LGUI:
    case KC_LALT:
    case KC_RSFT:
    case KC_RCTL:
    case KC_RGUI:
    case KC_RALT:
    case KC_SFTENT:
    case KC_ENT:
    case TD(TD_ESC_CAPS):
        if (record -> event.pressed) {
            mod_pressed++;
            rgblight_setrgb(COLOR_MOD);
        } else {
            mod_pressed--;
            if (mod_pressed == 0)
                set_rgblight_by_layer(layer_state);
        }
        return true;
        break;
    //Except Modifier keys from type blink
    case MO(_RS):
    case MO(_LW):
    case MO(_FN):
        return true;
        break;
    // Toggle typeblink with TYPEBLINK
    case TYPEBLINK:
        if (record -> event.pressed) {
            user_config.typeblink_on = !user_config.typeblink_on;
            eeconfig_update_user(user_config.raw);
        } else { }
        return true;
        break;
    // Check typeblink and BLINK!
    default:
        if(user_config.typeblink_on) {
            if (record -> event.pressed) {
                type_pressed++;
                rgblight_setrgb(COLOR_TYPEBLINK);
            } else {
                type_pressed--;
                if (type_pressed == 0 && mod_pressed == 0)
                {
                    set_rgblight_by_layer(layer_state);
                }
                else if (type_pressed == 0 && mod_pressed != 0)
                {
                    rgblight_setrgb(COLOR_MOD);
                }
            }
        }
        return true;
    }
}

uint32_t layer_state_set_user(uint32_t state) {
    set_rgblight_by_layer(state);
    switch (biton32(state)) {
    // Lit up GP100 LED with non-default layer.
    case _RS:
    case _LW:
    case _FN:
        gp100_led_on();
        break;
    default:
        gp100_led_off();
        break;
    }
    return state;
}

qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_ESC_CAPS]  = ACTION_TAP_DANCE_DOUBLE(KC_ESC, KC_CAPS),
    [TD_PGUP_HOME]  = ACTION_TAP_DANCE_DOUBLE(KC_PGUP, KC_HOME),
    [TD_PGDN_END]  = ACTION_TAP_DANCE_DOUBLE(KC_PGDN, KC_END)
};
