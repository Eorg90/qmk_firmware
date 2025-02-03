/* My layout for the Dactyl Manuform 5x6 Keyboard */

#include QMK_KEYBOARD_H

// Layers aliases
enum layers {
    _BASEMOD = 0,
    _GAME,
    _SYMBOL,
    _NAVI,
    _MOUSE,
    _NUMBER,
    _RESET
};

// Layers modifiers
#define SYMBOL MO(_SYMBOL)
#define TGSYMB TG(_SYMBOL)
#define NAVI MO(_NAVI)
#define TGNAV TG(_NAVI)
#define MOUSE MO(_MOUSE)
#define TGMSE TG(_MOUSE)
#define TGGAME TG(_GAME)
#define TGBASE DF(_BASEMOD)

// Symbols
#define CM_LBRC RALT(KC_8)
#define CM_RBRC RALT(KC_9)
#define CM_LSBR RALT(KC_7)
#define CM_RSBR RALT(KC_0)
#define CM_SLSH RALT(KC_MINS)
#define CM_LBRC RALT(KC_8)
#define CM_GT LSFT(KC_NUBS)
#define CM_AT RALT(KC_Q)
#define CM_EUR RALT(KC_E)
#define CM_PIPE RALT(KC_NUBS)
#define CM_TILD RALT(KC_RBRC)
#define CM_UNDO LCTL(KC_Y)
#define CM_CUT LCTL(KC_X)
#define CM_COPY LCTL(KC_C)
#define CM_PSTE LCTL(KC_V)

// mod-tabs layers
#define RESCAPE LT(_RESET,KC_ESC)
#define NAVBSPC LT(_NAVI, KC_BSPC)
#define NAVSPC LT(_NAVI, KC_SPC)
#define NUMTAB LT(_NUMBER, KC_TAB)
#define NUMENT LT(_NUMBER, KC_ENT)

enum custom_keycodes {
    SMTD_KEYCODES_BEGIN = SAFE_RANGE,
    CKC_K,
    CKC_Z,
    CKC_OE,
    CKC_AE,
    CKC_Y,
    CKC_V,
    CKC_W,
    CKC_G,
    CKC_BSPC,
    CKC_SPC,
    CKC_TAB,
    CKC_ENT,
    CKC_ESC,
    CKC_DEL,
    CKC_SZ,
    CKC_X,
    CKC_P1,
    CKC_P2,
    CKC_P3,
    CKC_DOT,
    SMTD_KEYCODES_END
};

#include "sm_td.h"

#ifdef SWAP_HANDS_ENABLE
const keypos_t PROGMEM hand_swap_config[MATRIX_ROWS][MATRIX_COLS] = {
    /* Left hand, matrix positions */
    {{5, 6}, {4, 6}, {3, 6}, {2, 6}, {1, 6}, {0, 6}},
    {{5, 7}, {4, 7}, {3, 7}, {2, 7}, {1, 7}, {0, 7}},
    {{5, 8}, {4, 8}, {3, 8}, {2, 8}, {1, 8}, {0, 8}},
    {{5, 9}, {4, 9}, {3, 9}, {2, 9}, {1, 9}, {0, 9}},
    {{5, 10}, {4, 10}, {3, 10}, {2, 10}, {1, 10}, {0, 10}},
    {{5, 11}, {4, 11}, {3, 11}, {2, 11}, {1, 11}, {0, 11}},
    /* Right hand, matrix positions */
    {{5, 0}, {4, 0}, {3, 0}, {2, 0}, {1, 0}, {0, 0}},
    {{5, 1}, {4, 1}, {3, 1}, {2, 1}, {1, 1}, {0, 1}},
    {{5, 2}, {4, 2}, {3, 2}, {2, 2}, {1, 2}, {0, 2}},
    {{5, 3}, {4, 3}, {3, 3}, {2, 3}, {1, 3}, {0, 3}},
    {{5, 4}, {4, 4}, {3, 4}, {2, 4}, {1, 4}, {0, 4}},
    {{5, 5}, {4, 5}, {3, 5}, {2, 5}, {1, 5}, {0, 5}}
};
#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

 [_BASEMOD] = LAYOUT_5x6(
     RESCAPE,KC_NO  ,KC_NO  ,KC_NO  ,KC_NO  ,KC_NO  ,                        KC_NO  ,KC_NO  ,KC_NO  ,KC_NO  ,KC_NO  ,KC_NO  ,
     KC_MINS,KC_B   ,KC_U   ,KC_DOT ,KC_COMM,KC_LBRC,                        KC_P   ,KC_C   ,KC_L   ,KC_M   ,KC_F   ,KC_X   ,
     SYMBOL ,KC_H   ,KC_I   ,KC_E   ,KC_A   ,KC_O   ,                        KC_D   ,KC_T   ,KC_R   ,KC_N   ,KC_S   ,SYMBOL ,
     TGMSE  ,CKC_K  ,CKC_Z  ,CKC_OE ,CKC_AE ,KC_Q   ,                        KC_J   ,CKC_G  ,CKC_W  ,CKC_V  ,CKC_Y  ,TGMSE  ,
     SH_OS  ,KC_NO  ,KC_NO  ,KC_NO  ,                                                        KC_NO  ,KC_NO  ,KC_NO  ,SH_OS  ,
                                     CKC_TAB,CKC_BSPC,                        CKC_SPC,CKC_ENT,
                                             SH_MON ,CKC_ESC,        CKC_DEL,SH_MON ,
                                             KC_NO  ,KC_NO  ,        KC_NO  ,KC_NO
  ),

  [_GAME] = LAYOUT_5x6(
     RESCAPE,KC_1   ,KC_2   ,KC_3   ,KC_4   ,KC_5   ,                        _______,_______,_______,_______,_______,_______,
     KC_TAB ,KC_Q   ,KC_W   ,KC_E   ,KC_R   ,KC_T   ,                        _______,_______,_______,_______,_______,_______,
     KC_F5  ,KC_A   ,KC_S   ,KC_D   ,KC_F   ,KC_G   ,                        _______,_______,_______,_______,_______,_______,
     KC_F6  ,KC_Y   ,KC_X   ,KC_C   ,KC_V   ,KC_B   ,                        _______,_______,_______,_______,_______,_______,
     KC_LCTL,KC_F7  ,KC_LALT,KC_F8  ,                                                        _______,_______,_______,_______,
                                     KC_BSPC,KC_LSFT,                        _______,_______,
                                             KC_F3  ,KC_F1  ,        _______,_______,
                                             KC_F4  ,KC_F2  ,        _______,_______
  ),

  [_SYMBOL] = LAYOUT_5x6(
     KC_F1  ,KC_F2  ,KC_F3  ,KC_F4  ,KC_F5  ,KC_F6  ,                        KC_F7  ,KC_F8  ,KC_F9  ,KC_F10 ,KC_F11 ,KC_F12 ,
     CM_EUR ,KC_TILD,KC_QUES,CM_LBRC,CM_RBRC,KC_GRV ,                        KC_EXLM,KC_NUBS,CM_GT  ,KC_RPRN,KC_CIRC,KC_DLR ,
     TGSYMB ,CM_SLSH,KC_AMPR,CM_LSBR,CM_RSBR,KC_RCBR,                        KC_UNDS,KC_ASTR,KC_LPRN,KC_SLSH,KC_RABK,TGSYMB ,
     _______,KC_EQL ,KC_PLUS,CM_PIPE,CM_TILD,KC_BSLS,                        CM_AT  ,KC_PERC,KC_AT  ,KC_PIPE,KC_LABK,_______,
     _______,_______,_______,_______,                                                        _______,_______,_______,_______,
                                     KC_CAPS,_______,                        _______,KC_CAPS,
                                             _______,_______,        _______,_______,
                                             _______,_______,        _______,_______

  ),

  [_NAVI] = LAYOUT_5x6(
     KC_MUTE,KC_MPLY,KC_VOLD,KC_VOLU,KC_MPRV,KC_MNXT,                        KC_CALC,KC_NO  ,KC_NO  ,KC_NO  ,KC_NO  ,_______,
     KC_INS ,KC_PGUP,KC_BSPC,KC_UP  ,KC_DEL ,KC_PGDN,                        KC_PMNS,KC_P7  ,KC_P8  ,KC_P9  ,KC_PPLS,KC_NUM ,
     KC_ENT ,KC_HOME,KC_LEFT,KC_DOWN,KC_RGHT,KC_END ,                        KC_PAST,KC_P4  ,KC_P5  ,KC_P6  ,KC_PDOT,_______,
     _______,CM_UNDO,CM_CUT ,CM_COPY,CM_PSTE,KC_APP ,                        KC_PSLS,CKC_P1 ,CKC_P2 ,CKC_P3 ,CKC_DOT,KC_PSCR,
     _______,_______,TGNAV  ,_______,                                                        _______,TGNAV  ,_______,_______,
                                     _______,_______,                        KC_P0  ,_______,
                                             _______,_______,        _______,_______,
                                             _______,_______,        _______,_______
  ),

  [_MOUSE] = LAYOUT_5x6(
     _______,_______,_______,_______,_______,_______,                        _______,_______,_______,_______,_______, TGMSE ,
     _______,_______,_______,MS_BTN4,MS_BTN5,_______,                        _______,MS_BTN4,MS_BTN5,_______,_______,_______,
     _______,MS_WHLL,MS_BTN2,MS_BTN3,MS_BTN1,MS_WHLR,                        MS_WHLL,MS_BTN1,MS_BTN3,MS_BTN2,MS_WHLR,_______,
     _______,_______,_______,MS_WHLU,MS_WHLD,TGMSE  ,                        TGMSE  ,MS_WHLD,MS_WHLU,_______,_______,_______,
     _______,_______,_______,_______,                                                        _______,_______,_______,_______,
                                     _______,_______,                        _______,_______,
                                             _______,TGMSE  ,        TGMSE  ,_______,
                                             _______,_______,        _______,_______
  ),

  [_NUMBER] = LAYOUT_5x6(
     _______,_______,_______,_______,_______,_______,                        _______,_______,_______,_______,_______,_______,
     KC_F1  ,KC_F2  ,KC_F3  ,KC_F4  ,KC_F5  ,KC_F6  ,                        KC_F7  ,KC_F8  ,KC_F9  ,KC_F10 ,KC_F11 ,KC_F12 ,
     _______,KC_1   ,KC_2   ,KC_3   ,KC_4   ,KC_5   ,                        KC_6   ,KC_7   ,KC_8   ,KC_9   ,KC_0   ,_______,
     KC_MUTE,KC_MPLY,KC_VOLD,KC_VOLU,KC_MPRV,KC_MNXT,                        KC_CALC,KC_RCTL,KC_RSFT,KC_LALT,KC_RGUI,_______,
     _______,_______,_______,_______,                                                        _______,_______,_______,_______,
                                     _______,_______,                        _______,_______,
                                             _______,_______,        _______,_______,
                                             _______,_______,        _______,_______
  ),

  [_RESET] = LAYOUT_5x6(
     _______,_______,_______,_______,_______,_______,                        _______,_______,_______,_______,_______,KC_PWR ,
     _______,_______,_______,_______,_______,_______,                        _______,_______,_______,_______,_______,_______,
     _______,_______,_______,_______,_______,_______,                        _______,_______,_______,_______,_______,_______,
     _______,_______,_______,_______,_______,_______,                        _______,_______,_______,_______,_______,_______,
     _______,_______,_______,_______,                                                        _______,_______,_______,_______,
                                     _______,_______,                        _______,_______,
                                             _______,_______,        _______,_______,
                                             _______,_______,        _______,_______
  ),
};

void on_smtd_action(uint16_t keycode, smtd_action action, uint8_t tap_count) {
    switch (keycode) {
        SMTD_MT(CKC_K, KC_K, KC_LEFT_GUI, 1)
        SMTD_MT(CKC_Z, KC_Z, KC_LEFT_ALT, 1)
        SMTD_MT(CKC_OE, KC_SCLN, KC_LSFT, 1)
        SMTD_MT(CKC_AE, KC_QUOT, KC_LEFT_CTRL, 1)
        SMTD_MT(CKC_Y, KC_Y, KC_RIGHT_GUI, 1)
        SMTD_MT(CKC_V, KC_V, KC_LEFT_ALT, 1)
        SMTD_MT(CKC_W, KC_W, KC_RSFT, 1)
        SMTD_MT(CKC_G, KC_G, KC_RIGHT_CTRL, 1)
        SMTD_MT(CKC_DOT, KC_DOT, KC_RIGHT_GUI, 1)
        SMTD_MT(CKC_P3, KC_P3, KC_LEFT_ALT, 1)
        SMTD_MT(CKC_P2, KC_P2, KC_RSFT, 1)
        SMTD_MT(CKC_P1, KC_P1, KC_RIGHT_CTRL, 1)
        SMTD_MT(CKC_TAB, KC_TAB, KC_LSFT, 1)
        SMTD_MT(CKC_ENT, KC_ENT, KC_RSFT, 1)

        SMTD_LT(CKC_BSPC, KC_BSPC, _NAVI, 1)
        SMTD_LT(CKC_SPC, KC_SPC, _NAVI, 1)
        SMTD_LT(CKC_ESC, KC_ESC, _NUMBER, 1)
        SMTD_LT(CKC_DEL, KC_DEL, _NUMBER, 1)
        SMTD_LT(CKC_SZ, KC_MINS, _SYMBOL, 1)
        SMTD_LT(CKC_X, KC_X, _SYMBOL, 1)
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_smtd(keycode, record)) {
        return false;
    }

    return true;
}
