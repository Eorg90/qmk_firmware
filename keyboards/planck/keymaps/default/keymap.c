/* A standard layout for the Dactyl Manuform 5x6 Keyboard */ 

#include QMK_KEYBOARD_H

// Layers aliases
enum layers {
    _BASEMOD = 0,
    _BUTECK,
    _HOMEMOD,
    _GAME,
    _SYMBOL,
    _NAVI,
    _MOUSE,
    _NUMBER,
    _RESET
};
//#define _BUTECK 0
//#define _HOMEMOD 1
//#define _BASEMOD 2
//#define _GAME 3
//#define _SYMBOL 4
//#define _NAVI 5
//#define _MOUSE 6
//#define _NUMBER 7
//#define _RESET 8

// Layers modifiers
#define SYMBOL MO(_SYMBOL)
#define TGSYMB TG(_SYMBOL)
#define NAVI MO(_NAVI)
#define TGNAV TG(_NAVI)
#define MOUSE MO(_MOUSE)
#define TGMSE TG(_MOUSE)
#define TGGAME TG(_GAME)
#define TGHOME DF(_HOMEMOD)
#define TGBASE DF(_BASEMOD)
#define TG_BUT DF(_BUTECK)

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

// mod-tabs layers
#define RESCAPE LT(_RESET,KC_ESC)
#define NAVBSPC LT(_NAVI, KC_BSPC)
#define NAVSPC LT(_NAVI, KC_SPC)
#define NAVENT LT(_NAVI, KC_ENT)
#define NAVTAB LT(_NAVI, KC_TAB)
#define NUMTAB LT(_NUMBER, KC_TAB)
#define NUMENT LT(_NUMBER, KC_ENT)
#define MOUSESC LT(_MOUSE, KC_ESC)
#define MOUSDEL LT(_MOUSE, KC_DEL)
#define MOUSESZ LT(_MOUSE, KC_MINS)
#define MOUSE_X LT(_MOUSE, KC_X)
#define SFT_ENT RSFT_T(KC_ENT)
#define SFT_TAB LSFT_T(KC_TAB)
#define SFT_SPC RSFT_T(KC_SPC)
#define SFT_BSP LSFT_T(KC_BSPC)
#define NUM_DEL LT(_NUMBER, KC_DEL)
#define NUM_ESC LT(_NUMBER, KC_ESC)

// home row mods left-hand
#define LGUI_H LGUI_T(KC_H)
#define LALT_I LALT_T(KC_I)
#define LSFT_E LSFT_T(KC_E)
#define LCTL_A LCTL_T(KC_A)

// home row mods right-hand
#define RCTL_t RCTL_T(KC_T)
#define RSFT_R RSFT_T(KC_R)
#define LALT_N LALT_T(KC_N)
#define RGUI_S RGUI_T(KC_S)

// base row mods
#define MOD_K LGUI_T(KC_K)
#define MOD_Z LALT_T(KC_Z)
#define MOD_OE LSFT_T(KC_SCLN)
#define MOD_AE LCTL_T(KC_QUOT)

#define MOD_Y RGUI_T(KC_Y)
#define MOD_V LALT_T(KC_V)
#define MOD_W RSFT_T(KC_W)
#define MOD_G RCTL_T(KC_G)

#define MOD_DOT RGUI_T(KC_DOT)
#define MOD_P3 LALT_T(KC_P3)
#define MOD_P2 RSFT_T(KC_P2)
#define MOD_P1 RCTL_T(KC_P1)

enum custom_keycodes {
    CM_UNDO = KC_F13,
    CM_CUT,
    CM_COPY,
    CM_PSTE,
    CM_MPLY,
    CM_VOLD,
    CM_VOLU,
    CM_MPRV
};

// functions base mod
#define MOD_UDO LGUI_T(CM_UNDO)
#define MOD_CUT LALT_T(CM_CUT)
#define MOD_CPY LSFT_T(CM_COPY)
#define MOD_PST LCTL_T(CM_PSTE)

// media base mod
#define MOD_PLY LGUI_T(CM_MPLY)
#define MOD_VLD LALT_T(CM_VOLD)
#define MOD_VLU LSFT_T(CM_VOLU)
#define MOD_PRV LCTL_T(CM_MPRV)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_BASEMOD] = LAYOUT_ortho_4x12( 
     MOUSESZ,KC_B   ,KC_U   ,KC_DOT ,KC_COMM,KC_LBRC,KC_P   ,KC_C   ,KC_L   ,KC_M   ,KC_F   ,MOUSE_X,
     SYMBOL ,KC_H   ,KC_I   ,KC_E   ,KC_A   ,KC_O   ,KC_D   ,KC_T   ,KC_R   ,KC_N   ,KC_S   ,SYMBOL ,
     KC_NO  ,MOD_K  ,MOD_Z  ,MOD_OE ,MOD_AE ,KC_Q   ,KC_J   ,MOD_G  ,MOD_W  ,MOD_V  ,MOD_Y  ,KC_NO  ,
     KC_NO  ,RESCAPE,KC_NO  ,NUM_ESC,SFT_TAB,NAVBSPC,NAVSPC ,SFT_ENT,NUM_DEL,KC_NO  ,KC_NO  ,KC_NO  
  ),

  [_BUTECK] = LAYOUT_ortho_4x12( 
     RESCAPE,KC_B   ,KC_U   ,KC_DOT ,KC_COMM,KC_LBRC,KC_P   ,KC_C   ,KC_L   ,KC_M   ,KC_F   ,KC_ENT ,
     SYMBOL ,KC_H   ,KC_I   ,KC_E   ,KC_A   ,KC_O   ,KC_D   ,KC_T   ,KC_R   ,KC_N   ,KC_S   ,SYMBOL ,
     KC_MINS,KC_K   ,KC_Z   ,KC_SCLN,KC_QUOT,KC_Q   ,KC_J   ,KC_G   ,KC_W   ,KC_V   ,KC_Y   ,KC_X   ,
     KC_LCTL,KC_LGUI,NAVI   ,KC_LALT,KC_BSPC,KC_LSFT,KC_RSFT,KC_SPC ,KC_LALT,NAVI   ,KC_LGUI,KC_RCTL
  ),

  [_HOMEMOD] = LAYOUT_ortho_4x12( 
     RESCAPE,KC_B   ,KC_U   ,KC_DOT ,KC_COMM,KC_LBRC,KC_P   ,KC_C   ,KC_L   ,KC_M   ,KC_F   ,KC_ENT ,
     SYMBOL ,LGUI_H ,LALT_I ,LSFT_E ,LCTL_A ,KC_O   ,KC_D   ,RCTL_t ,RSFT_R ,LALT_N ,RGUI_S ,SYMBOL ,
     KC_MINS,KC_K   ,KC_Z   ,KC_SCLN,KC_QUOT,KC_Q   ,KC_J   ,KC_G   ,KC_W   ,KC_V   ,KC_Y   ,KC_X   ,
     KC_NO  ,KC_NO  ,KC_NO  ,MOUSESC,NAVBSPC,NUMTAB ,NUMENT ,NAVSPC ,MOUSDEL,KC_NO  ,KC_NO  ,KC_NO  
  ),

  [_GAME] = LAYOUT_ortho_4x12(  
     KC_TAB ,KC_Q   ,KC_W   ,KC_E   ,KC_R   ,KC_T   ,_______,_______,_______,_______,_______,_______,
     KC_F1  ,KC_A   ,KC_S   ,KC_D   ,KC_F   ,KC_G   ,_______,_______,_______,_______,_______,_______,
     KC_F2  ,KC_Y   ,KC_X   ,KC_C   ,KC_V   ,KC_B   ,_______,_______,_______,_______,_______,_______,
     KC_LCTL,KC_F3  ,RESCAPE,KC_F5  ,KC_BSPC,KC_LSFT,_______,_______,_______,_______,_______,_______
  ),

  [_SYMBOL] = LAYOUT_ortho_4x12(
     _______,KC_TILD,KC_QUES,CM_LBRC,CM_RBRC,KC_GRV ,KC_EXLM,KC_NUBS,CM_GT  ,KC_RPRN,KC_CIRC,_______,
     TGSYMB ,CM_SLSH,KC_AMPR,CM_LSBR,CM_RSBR,KC_RCBR,KC_UNDS,KC_ASTR,KC_LPRN,KC_SLSH,KC_RABK,TGSYMB ,
     CM_EUR ,KC_EQL ,KC_PLUS,CM_PIPE,CM_TILD,KC_BSLS,CM_AT  ,KC_PERC,KC_AT  ,KC_PIPE,KC_LABK,KC_DLR ,
     _______,_______,_______,_______,_______,KC_CAPS,KC_CAPS,_______,_______,_______,_______,_______
  ),

  [_NAVI] = LAYOUT_ortho_4x12( 
     _______,KC_PGUP,KC_BSPC,KC_UP  ,KC_DEL ,KC_PGDN,KC_PMNS,KC_P7  ,KC_P8  ,KC_P9  ,KC_PPLS,_______, 
     KC_ENT ,KC_HOME,KC_LEFT,KC_DOWN,KC_RGHT,KC_END ,KC_PAST,KC_P4  ,KC_P5  ,KC_P6  ,KC_PDOT,_______,
     KC_INS ,CM_UNDO,CM_CUT ,CM_COPY,CM_PSTE,KC_APP ,KC_PSLS,MOD_P1 ,MOD_P2 ,MOD_P3 ,MOD_DOT,KC_NLCK, 
     _______,_______,TGNAV  ,_______,_______,_______,_______, KC_P0 ,_______,TGNAV  ,_______,_______
  ),

  [_MOUSE] = LAYOUT_ortho_4x12( 
     _______,_______,KC_BTN4,KC_MS_U,KC_BTN5,_______,_______,KC_BTN4,KC_MS_U,KC_BTN5,_______,_______,
     _______,KC_WH_L,KC_MS_L,KC_MS_D,KC_MS_R,KC_WH_R,KC_WH_L,KC_MS_L,KC_MS_D,KC_MS_R,KC_WH_R,_______,
     _______,_______,KC_WH_U,KC_BTN3,KC_WH_D,_______,_______,KC_WH_D,KC_BTN3,KC_WH_U,_______,_______,
     _______,_______,_______,_______,KC_BTN1,KC_BTN2,KC_BTN2,KC_BTN1,_______,_______,_______,_______
  ),

  [_NUMBER] = LAYOUT_ortho_4x12( 
     KC_F1  ,KC_F2  ,KC_F3  ,KC_F4  ,KC_F5  ,KC_F6  ,KC_F7  ,KC_F8  ,KC_F9  ,KC_F10 ,KC_F11 ,KC_F12 ,
     _______,KC_1   ,KC_2   ,KC_3   ,KC_4   ,KC_5   ,KC_6   ,KC_7   ,KC_8   ,KC_9   ,KC_0   ,_______,
     KC_MUTE,KC_MPLY,KC_VOLD,KC_VOLU,KC_MPRV,KC_MNXT,KC_CALC,KC_NO  ,KC_NO  ,KC_NO  ,KC_NO  ,_______,
     _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______
  ),

  [_RESET] = LAYOUT_ortho_4x12( 
     _______,_______,_______,_______,_______,_______,TG_BUT ,TGHOME ,TGBASE ,_______,_______,KC_PWR ,
     _______,_______,_______,_______,_______,TGGAME ,_______,_______,_______,_______,_______,_______,
     _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,
     _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,RESET  
  ),
};

bool get_tapping_force_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
//      case NAVSPC:
//          return false;
        case NAVBSPC:
            return false;
        case MOD_VLD:
            return false;
        case MOD_VLU:
            return false;
        default:
            return true;
    }
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case NAVSPC:
            return TAPPING_TERM*2;
        case NAVBSPC:
            return TAPPING_TERM*2;
        case MOD_K:
            return TAPPING_TERM*2;
        case MOD_Y:
            return TAPPING_TERM*2;
        case SFT_ENT:
            return TAPPING_TERM*0;
        case SFT_TAB:
            return TAPPING_TERM*0;
        default:
            return TAPPING_TERM;
    }
}

bool get_ignore_mod_tap_interrupt(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case SFT_TAB:
            return false;
        case SFT_ENT:
            return false;
        default:
            return true;
    }
}

bool get_retro_tapping(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case SFT_TAB:
            return true;
        case SFT_ENT:
            return true;
        default:
            return false;
    }
}

bool LSFT_IS_INTENDED = false;
bool RSFT_IS_INTENDED = false;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case MOD_UDO: {
            if (record->tap.count > 0) {
                if (record->event.pressed) {
                    tap_code16(LCTL(KC_Y));
                }
                return false;
            }
            return true;
        }
        case MOD_CUT: {
            if (record->tap.count > 0) {
                if (record->event.pressed) {
                    tap_code16(LCTL(KC_X));
                }
                return false;
            }
            return true;
        }
        case MOD_CPY: {
            if (record->tap.count > 0) {
                if (record->event.pressed) {
                    tap_code16(LCTL(KC_C));
                }
                return false;
            }
            return true;
        }
        case MOD_PST: {
            if (record->tap.count > 0) {
                if (record->event.pressed) {
                    tap_code16(LCTL(KC_V));
                }
                return false;
            }
            return true;
        }
        case MOD_PLY: {
            if (record->tap.count > 0) {
                if (record->event.pressed) {
                    tap_code16(KC_MPLY);
                }
                return false;
            }
            return true;
        }
        case MOD_VLD: {
            if (record->tap.count > 0) {
                if (record->event.pressed) {
                    tap_code16(KC_VOLD);
                }
                return false;
            }
            return true;
        }
        case MOD_VLU: {
            if (record->tap.count > 0) {
                if (record->event.pressed) {
                    tap_code16(KC_VOLU);
                }
                return false;
            }
            return true;
        }
        case MOD_PRV: {
            if (record->tap.count > 0) {
                if (record->event.pressed) {
                    tap_code16(KC_MPRV);
                }
                return false;
            }
            return true;
        }
        case SFT_TAB: {
            if (record->event.pressed) {
                if (get_mods() & MOD_BIT(KC_LSHIFT)) {
                    LSFT_IS_INTENDED = true;
                } 
                if (get_mods() & MOD_MASK_ALT) {
                    tap_code16(KC_TAB);
                    return false;
                } else if (get_mods() & MOD_MASK_SHIFT) {
                    tap_code16(KC_TAB);
                    return false;
                } else if (get_mods() & MOD_MASK_CTRL) {
                    tap_code16(KC_TAB);
                    return false;
                } else if (get_mods() & MOD_MASK_GUI) {
                    tap_code16(KC_TAB);
                    return false;
                } else {
                    return true;
                }
            } else {
                if (get_mods() & MOD_BIT(KC_LSHIFT)) {
                    if (LSFT_IS_INTENDED) {
                        LSFT_IS_INTENDED = false;
                        return false;
                    } else {
                        return true;
                    }
                } else if (get_mods() & MOD_MASK_ALT) {
                    return false;
                } else if (get_mods() & MOD_MASK_SHIFT) {
                    return false;
                } else if (get_mods() & MOD_MASK_CTRL) {
                    return false;
                } else if (get_mods() & MOD_MASK_GUI) {
                    return false;
                } else {
                    return true;
                }
            }
        }
        case SFT_ENT: {
            if (record->event.pressed) {
                if (get_mods() & MOD_BIT(KC_RSHIFT)) {
                    RSFT_IS_INTENDED = true;
                } 
                if (get_mods() & MOD_MASK_ALT) {
                    tap_code16(KC_ENT);
                    return false;
                } else if (get_mods() & MOD_MASK_SHIFT) {
                    tap_code16(KC_ENT);
                    return false;
                } else if (get_mods() & MOD_MASK_CTRL) {
                    tap_code16(KC_ENT);
                    return false;
                } else if (get_mods() & MOD_MASK_GUI) {
                    tap_code16(KC_ENT);
                    return false;
                } else {
                    return true;
                }
            } else {
                if (get_mods() & MOD_BIT(KC_RSHIFT)) {
                    if (RSFT_IS_INTENDED) {
                        RSFT_IS_INTENDED = false;
                        return false;
                    } else {
                        return true;
                    }
                } else if (get_mods() & MOD_MASK_ALT) {
                    return false;
                } else if (get_mods() & MOD_MASK_SHIFT) {
                    return false;
                } else if (get_mods() & MOD_MASK_CTRL) {
                    return false;
                } else if (get_mods() & MOD_MASK_GUI) {
                    return false;
                } else {
                    return true;
                }
            }
        }
        default: {
            return true;
        }
    }
}
