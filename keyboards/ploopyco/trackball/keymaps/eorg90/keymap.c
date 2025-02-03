/* Copyright 2020 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
 * Copyright 2019 Sunjun Kim
 * Copyright 2020 Ploopy Corporation
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

enum custom_keycodes {
    _BTN3 = KC_F13,
    _SWAPP,
    _SWAPPR,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT( /* Base */
        KC_BTN1, _BTN3, LT(1, KC_BTN4),
          LT(2, KC_BTN2), LT(3, KC_BTN5)
    ),
    [1] = LAYOUT(
        KC_NO, KC_NO, KC_NO,
        C(KC_C), C(KC_V)
    ),
    [2] = LAYOUT(
        KC_F5, C(S(KC_T)), KC_ENT,
        KC_TRNS, KC_TRNS
    ),
    [3] = LAYOUT(
        KC_TRNS, C(KC_W), KC_TRNS,
        KC_TRNS, KC_TRNS
    ),
};

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] = {},
    [1] = {},
    [2] = {ENCODER_CCW_CW(_SWAPP, _SWAPPR)},
    [3] = {ENCODER_CCW_CW(C(KC_TAB), S(C(KC_TAB)))},
};
#endif

bool set_scrolling = false;
int8_t scroll_divisor = 2;

report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
    if (set_scrolling) {
        mouse_report.h = mouse_report.x;
        mouse_report.v = -mouse_report.y;
        mouse_report.x = 0;
        mouse_report.y = 0;
    }

    // // Check if the custom keycode is pressed and modify the mouse report
    // if (host_keyboard_leds() & (1 << _BTN3)) {
    //     register_code16(KC_LSFT);
    //     mouse_report.buttons |= (1 << 2); // Set the middle mouse button
    //     // Add any additional logic for the shifted state if needed
    //     unregister_code16(KC_LSFT);
    // }

    return mouse_report;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
        case 1:
            set_scrolling = true;
            pointing_device_set_cpi(50);
            break;
        default:
            if (set_scrolling) {
            set_scrolling = false;
            pointing_device_set_cpi(1200);
            }
            unregister_code16(KC_LALT);
            break;
    }
    return state;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case _BTN3: {
            if (record->event.pressed) {
                register_code16(KC_LSFT);
                wait_ms(50);
                register_code16(KC_BTN3);
            } else {
                unregister_code16(KC_BTN3);
                wait_ms(50);
                unregister_code16(KC_LSFT);
            }
            return false;
        }
        case _SWAPP: {
            if (record->event.pressed) {
                register_code16(KC_LALT);
                tap_code16(KC_TAB);
            }
            return false;
        }
        case _SWAPPR: {
            if (record->event.pressed) {
                register_code16(KC_LALT);
                register_code16(KC_LSFT);
                tap_code16(KC_TAB);
                unregister_code16(KC_LSFT);
            }
            return false;
        }
        default: {
            return true;
        }
    }
}
