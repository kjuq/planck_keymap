const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_COLEMAK] = LAYOUT_planck_grid( // {{{
        KC_ESC,  KC_W,    KC_F,    KC_P,    KC_V,    XXXXXXX, XXXXXXX, KC_J,    KC_L,    KC_U,    KC_Y,    KC_Q,
        KC_A,    KC_R,    KC_S,    KC_T,    KC_G,    XXXXXXX, XXXXXXX, KC_H,    KC_N,    KC_E,    KC_I,    KC_O,
        KC_Z,    KC_X,    KC_C,    KC_D,    KC_B,    XXXXXXX, XXXXXXX, KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SCLN,
        XXXXXXX, KC_LCMD, LOWER,   KC_LCTL, KC_SPC,  KC_SPC,  KC_SPC,  KC_SPC,  KC_RSFT, RAISE,   KC_RALT, MOUSE
    ), // }}}

    [_QWERTY] = LAYOUT_planck_grid( // {{{
        KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    _______, _______, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
        KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    _______, _______, KC_H,    KC_J,    KC_K,    KC_L,    KC_ESC,
        KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    _______, _______, KC_N,    KC_M,    _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ), // }}}

    [_FNC_TAP] = LAYOUT_planck_grid( // {{{
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, LWRFNC,  _______, _______, _______, _______, _______, _______, RISFNC,  _______, _______
    ), // }}}

    [_SPC_TAP] = LAYOUT_planck_grid( // {{{
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, CMD_SPC, CMD_SPC, ALT_SPC, ALT_SPC, _______, _______, _______, _______
    ), // }}}

    [_LOWER] = LAYOUT_planck_grid( // {{{
        SC_TAB,  KC_MINS, KC_EQL,  KC_QUOT, XXXXXXX, XXXXXXX, XXXXXXX, FNCTN,   KC_7,    KC_8,    KC_9,    KC_BSPC,
        MOD_CAG, KC_SLSH, KC_LBRC, KC_RBRC, KC_GRV,  XXXXXXX, XXXXXXX, KC_0,    KC_4,    KC_5,    KC_6,    XXXXXXX,
        KC_RCTL, KC_SCLN, KC_COMM, KC_DOT,  KC_BSLS, XXXXXXX, XXXXXXX, XXXXXXX, KC_1,    KC_2,    KC_3,    KC_LSFT,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ), // }}}

    [_RAISE] = LAYOUT_planck_grid( // {{{
        SA_TAB,  KC_UNDS, KC_PLUS, KC_DQUO, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_AMPR, KC_ASTR, KC_LPRN, KC_BSPC,
        XXXXXXX, KC_QUES, KC_LCBR, KC_RCBR, KC_TILD, XXXXXXX, XXXXXXX, KC_RPRN, KC_DLR,  KC_PERC, KC_CIRC, XXXXXXX,
        KC_RCMD, KC_COLN, KC_LABK, KC_RABK, KC_PIPE, XXXXXXX, XXXXXXX, XXXXXXX, KC_EXLM, KC_AT,   KC_HASH, KC_LALT,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ), // }}}

    [_FNCTN] = LAYOUT_planck_grid( // {{{
        MODS,    KC_VOLU, DM_RSTP, KC_F18,  ADJUST,  XXXXXXX, XXXXXXX, KC_F12,  KC_F7,   KC_F8,   KC_F9,   KC_F15,
        ORS,     KC_MPLY, DM_REC1, KC_F17,  KC_F20,  XXXXXXX, XXXXXXX, KC_F11,  KC_F4,   KC_F5,   KC_F6,   KC_F14,
        XXXXXXX, KC_VOLD, DM_PLY1, KC_F16,  KC_F19,  XXXXXXX, XXXXXXX, KC_F10,  KC_F1,   KC_F2,   KC_F3,   KC_F13,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ), // }}}

    [_MODS] = LAYOUT_planck_grid( // {{{
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ), // }}}

    [_ORS] = LAYOUT_planck_grid( // {{{
        XXXXXXX, XXXXXXX, KC_RGHT, KC_UP,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        KC_HOME, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_BSPC, KC_DOWN, KC_END,  KC_TAB,  XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, KC_DEL,  KC_LEFT, XXXXXXX, XXXXXXX, XXXXXXX, KC_ENT,  XXXXXXX, XXXXXXX, XXXXXXX,
        _______, _______, KC_LNG2, _______, _______, _______, _______, _______, _______, KC_LNG1, _______, _______
    ), // }}}

    [_ADJUST] = LAYOUT_planck_grid( // {{{
        EXT_LYR, KO_WDDL, KO_WD,   XXXXXXX, KO_CMDV, XXXXXXX, XXXXXXX, ADJUST2, XXXXXXX, KO_CTLU, XXXXXXX, KO_CMDQ,
        KO_HM,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KO_BS,   XXXXXXX, KO_ED,   KO_TB,   XXXXXXX,
        XXXXXXX, XXXXXXX, KO_CMDD, KO_DL,   KO_AR,   XXXXXXX, XXXXXXX, XXXXXXX, KO_EN,   XXXXXXX, KO_JIS,  KO_PRNT,
        XXXXXXX, KO_LXCM, XXXXXXX, XXXXXXX, KO_CMSP, XXXXXXX, XXXXXXX, MT_SPC,  KO_MTAB, LT_FNC,  XXXXXXX, XXXXXXX
    ), // }}}

    [_ADJUST2] = LAYOUT_planck_grid( // {{{
        EXT_LYR, QK_BOOT, DB_TOGG, AU_TOGG, XXXXXXX, XXXXXXX, XXXXXXX, RGB_TOG, RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI,
        XXXXXXX, FPS,     QWERTY,  COLEMAK, XXXXXXX, XXXXXXX, XXXXXXX, RGB_M_P, RGB_M_B, RGB_M_R, RGB_M_SW,RGB_M_SN,
        XXXXXXX, EE_CLR,  KO_TOGG, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RGB_M_K, RGB_M_X, RGB_M_G, RGB_M_T, RGB_M_TW,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
    ), // }}}

    [_MOUSE] = LAYOUT_planck_grid( // {{{
        XXXXXXX, KC_WH_D, KC_MS_U, KC_WH_U, KC_BTN3, XXXXXXX, XXXXXXX, XXXXXXX, KC_BTN3, KC_BTN2, XXXXXXX, XXXXXXX,
        XXXXXXX, KC_MS_L, KC_MS_D, KC_MS_R, KC_BTN5, XXXXXXX, XXXXXXX, XXXXXXX, MS_SHFT, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, KC_WH_L, XXXXXXX, KC_WH_R, KC_BTN4, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        _______, _______, _______, _______, _______, _______, _______, KC_BTN1, _______, _______, _______, _______
    ), // }}}

    [_FPS] = LAYOUT_planck_grid( // {{{
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, EXT_LYR,
        KC_LSFT, _______, _______, _______, KC_SPC,  KC_SPC,  KC_SPC,  KC_SPC,  _______, _______, _______, _______
    ), // }}}

};
