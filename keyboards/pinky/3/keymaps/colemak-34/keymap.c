/* Copyright 2018 'Masayuki Sunahara'
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

enum layer_names {
    _ALPH,
    _SYM,
    _NUM,
    _NAV
};

enum custom_keycodes {
    ALPH = SAFE_RANGE,
    SYM,
    NUM,
    NAV
};

// Left-hand home row mods
#define SFT_A LSFT_T(KC_A)
#define CTL_R LCTL_T(KC_R)
#define ALT_S LALT_T(KC_S)
#define GUI_TT LGUI_T(KC_T)

// Right-hand home row mods
#define GUI_N RGUI_T(KC_N)
#define ALT_E LALT_T(KC_E)
#define CTL_I RCTL_T(KC_I)
#define SFT_O RSFT_T(KC_O)

#define MONAV TT(3)  // momentarily access navigation layer or toggle
#define ESC_SYM LT(1, KC_ESC)
#define SPC_SYM LT(1, KC_SPC)
#define ENT_NAV LT(2, KC_ENT)

// TODO spc + sym, esc + sym, ent + nav

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_ALPH] = LAYOUT_split_3x7_4(
        _______, KC_Q   , KC_W   , KC_F   , KC_P   , KC_B   , KC_LPRN,    KC_RPRN, KC_J   , KC_L   , KC_U   , KC_Y   , KC_SCLN, _______,
        _______, SFT_A  , CTL_R  , ALT_S  , GUI_TT  , KC_G   , KC_LBRC,    KC_RBRC, KC_M   , GUI_N  , ALT_E  , CTL_I  , SFT_O,   _______,
        _______, KC_Z   , KC_X   , KC_C   , KC_D   , KC_V   , _______,    _______, KC_K   , KC_H   , KC_COMM, KC_DOT , KC_SLSH, _______,
                                   _______, MONAV  , ESC_SYM, _______,    _______ , SPC_SYM, ENT_NAV, _______
    ),
    [_SYM] = LAYOUT_split_3x7_4( // spc activate
        _______, KC_EXLM, KC_AT  , KC_HASH, KC_DLR , KC_PERC, _______,   _______, KC_CIRC , KC_AMPR, KC_ASTR, _______, _______, _______,
        _______, KC_LT  , KC_LCBR, KC_EQL , KC_LPRN, KC_PLUS, _______,   _______, KC_MINUS, KC_RPRN, KC_UNDS, KC_RCBR, KC_PIPE, _______,
        _______, _______, KC_GRV , KC_TILD, KC_LBRC, KC_LT  , _______,   _______, KC_GT   , KC_RBRC, KC_QUOT, KC_DQT , KC_BSLS, _______,
                                   _______, _______, KC_TAB , _______,   _______, KC_BSPC , KC_DEL,  _______
    ),
    [_NUM] = LAYOUT_split_3x7_4(
        _______, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , _______,    _______, KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , _______,
        _______, KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , _______,    _______, KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , _______,
        _______, _______, _______, _______, KC_F10 , KC_F11 , _______,    _______, KC_F12 , _______, _______, _______, _______, _______,
                                   _______, _______, _______, _______,    _______, _______, _______, _______
    ),
    [_NAV] = LAYOUT_split_3x7_4(
        _______, _______, _______, KC_PGDN, KC_ACL0, KC_PGUP, _______,    _______, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, _______, _______,
        _______, KC_MPRV, KC_MNXT, KC_MPLY, KC_ACL1, KC_END , _______,    _______, KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, _______, _______,
        _______, KC_VOLD, KC_VOLU, KC_MUTE, KC_ACL2, _______, _______,    _______, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, _______, _______,
                                   _______, _______, _______, _______,    _______, _______, _______, _______
    )
};

