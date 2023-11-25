#include QMK_KEYBOARD_H

user_config_t user_config;

inline static void enter_layer(uint8_t layer, uint8_t hue, uint8_t sat, uint8_t val) {
    #ifdef AUDIO_ENABLE
    stop_all_notes();
    PLAY_SONG(num_lock_on_song);
    #endif
    layer_move(layer);
    rgblight_mode_noeeprom(RGBLIGHT_MODE_SNAKE + 2);
    rgblight_sethsv_noeeprom(hue, sat, val);
    return;
}

inline static void exit_layer(void) {
    #ifdef AUDIO_ENABLE
    PLAY_SONG(num_lock_off_song);
    #endif
    layer_clear();
    rgblight_reload_from_eeprom();
    return;
};

inline static void react_key_press_by_RGB(uint8_t hue, uint8_t sat, uint8_t val) {
    #ifdef RGBLIGHT_ENABLE
    rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
    rgblight_sethsv_noeeprom(hue, sat, val);
    wait_ms(100); // 100 ms
    enter_layer(_ADJUST, HSV_ADJUST);
    #endif
    return;
};

// variables for key_overrides
key_override_t jis_at_override   = ko_make_basic(0, KC_AT, KC_LBRC); // S(KC_2)
key_override_t jis_circ_override = ko_make_basic(0, KC_CIRC, KC_EQL); // S(KC_6)
key_override_t jis_ampr_override = ko_make_basic(0, KC_AMPR, KC_CIRC); // S(KC_7)
key_override_t jis_astr_override = ko_make_basic(0, KC_ASTR, KC_DQUO); // S(KC_8)
key_override_t jis_lprn_override = ko_make_basic(0, KC_LPRN, KC_ASTR); // S(KC_9)
key_override_t jis_rprn_override = ko_make_basic(0, KC_RPRN, LSFT(KC_9)); // S(KC_0)
key_override_t jis_unds_override = ko_make_basic(0, KC_UNDS, LSFT(KC_INT1)); // S(KC_MINUS)
key_override_t jis_plus_override = ko_make_basic(0, KC_PLUS, KC_COLN); // S(KC_EQUAL)
key_override_t jis_lbrc_override = ko_make_basic(0, KC_LBRC, KC_RBRC);
key_override_t jis_lcbr_override = ko_make_basic(0, KC_LCBR, KC_RCBR); // S(KC_LBRC)
key_override_t jis_rbrc_override = ko_make_basic(0, KC_RBRC, KC_NUHS);
key_override_t jis_rcbr_override = ko_make_basic(0, KC_RCBR, LSFT(KC_NUHS)); // S(KC_RBRC)
key_override_t jis_bsls_override = ko_make_basic(0, KC_BSLS, KC_INT3);
key_override_t jis_pipe_override = ko_make_basic(0, KC_PIPE, LSFT(KC_INT3)); // S(KC_BSLS)
key_override_t jis_coln_override = ko_make_basic(0, KC_COLN, KC_QUOT); // S(KC_SCLN)
key_override_t jis_quot_override = ko_make_basic(0, KC_QUOT, KC_AMPR);
key_override_t jis_dquo_override = ko_make_basic(0, KC_DQUO, KC_AT); // S(KC_QUOT)
key_override_t jis_grv_override  = ko_make_basic(0, KC_GRV,  KC_LCBR);
key_override_t jis_tild_override = ko_make_basic(0, KC_TILD, KC_PLUS); // S(KC_GRV)
key_override_t jis_eql_override  = ko_make_basic(0, KC_EQL,  KC_UNDS);

key_override_t jis_s_2_override    = ko_make_basic(MOD_MASK_SHIFT, KC_2, KC_LBRC);
key_override_t jis_s_6_override    = ko_make_basic(MOD_MASK_SHIFT, KC_6, KC_EQL);
key_override_t jis_s_7_override    = ko_make_basic(MOD_MASK_SHIFT, KC_7, KC_CIRC);
key_override_t jis_s_8_override    = ko_make_basic(MOD_MASK_SHIFT, KC_8, KC_DQUO);
key_override_t jis_s_9_override    = ko_make_basic(MOD_MASK_SHIFT, KC_9, KC_ASTR);
key_override_t jis_s_0_override    = ko_make_basic(MOD_MASK_SHIFT, KC_0, LSFT(KC_9));
key_override_t jis_s_mins_override = ko_make_basic(MOD_MASK_SHIFT, KC_MINS, LSFT(KC_INT1));
key_override_t jis_s_eql_override  = ko_make_basic(MOD_MASK_SHIFT, KC_EQL, KC_COLN);
key_override_t jis_s_lbrc_override = ko_make_basic(MOD_MASK_SHIFT, KC_LBRC, KC_RCBR);
key_override_t jis_s_rbrc_override = ko_make_basic(MOD_MASK_SHIFT, KC_RBRC, LSFT(KC_NUHS));
key_override_t jis_s_bsls_override = ko_make_basic(MOD_MASK_SHIFT, KC_BSLS, LSFT(KC_INT3));
key_override_t jis_s_scln_override = ko_make_basic(MOD_MASK_SHIFT, KC_SCLN, KC_QUOT);
key_override_t jis_s_quot_override = ko_make_basic(MOD_MASK_SHIFT, KC_QUOT, KC_AT);
key_override_t jis_s_grv_override  = ko_make_basic(MOD_MASK_SHIFT, KC_GRV, KC_PLUS);

key_override_t right_key_override = ko_make_basic(MOD_BIT(KC_LCTL), KC_F, KC_RIGHT);
key_override_t left_key_override  = ko_make_basic(MOD_BIT(KC_LCTL), KC_B, KC_LEFT);
key_override_t up_key_override    = ko_make_basic(MOD_BIT(KC_LCTL), KC_P, KC_UP);
key_override_t down_key_override  = ko_make_basic(MOD_BIT(KC_LCTL), KC_N, KC_DOWN);

key_override_t home_key_override  = ko_make_basic(MOD_BIT(KC_LCTL), KC_A, KC_HOME);
key_override_t end_key_override   = ko_make_basic(MOD_BIT(KC_LCTL), KC_E, KC_END);

key_override_t enter_key_override = ko_make_basic(MOD_BIT(KC_LCTL), KC_M, KC_ENT);
key_override_t tab_key_override   = ko_make_basic(MOD_BIT(KC_LCTL), KC_I, KC_TAB);
key_override_t bs_key_override    = ko_make_basic(MOD_BIT(KC_LCTL), KC_H, KC_BSPC);
key_override_t del_key_override   = ko_make_basic(MOD_BIT(KC_LCTL), KC_D, KC_DEL);

key_override_t w_fwd_mac_override = ko_make_basic(MOD_BIT(KC_RALT), KC_F, RALT(KC_RGHT));
key_override_t w_bck_mac_override = ko_make_basic(MOD_BIT(KC_RALT), KC_B, RALT(KC_LEFT));

key_override_t w_fwd_win_override = ko_make_basic(MOD_BIT(KC_RALT), KC_F, RCTL(KC_RGHT));
key_override_t w_bck_win_override = ko_make_basic(MOD_BIT(KC_RALT), KC_B, RCTL(KC_LEFT));

key_override_t w_del_mac_override = ko_make_basic(MOD_BIT(KC_LCTL), KC_W, RALT(KC_BSPC));
key_override_t w_del_win_override = ko_make_basic(MOD_BIT(KC_LCTL), KC_W, LCTL(KC_BSPC));

key_override_t cmd_space_override = ko_make_basic(MOD_BIT(KC_LGUI), KC_SPC, LGUI(KC_BSLS));
key_override_t cmd_v_override     = ko_make_basic(MOD_BIT(KC_LGUI), KC_D, LGUI(KC_V));
key_override_t cmd_d_override     = ko_make_basic(MOD_BIT(KC_LGUI), KC_V, LGUI(KC_D));

key_override_t ctrl_tab_override = ko_make_basic(MOD_BIT(KC_LCTL), KC_ESC, LCTL(KC_TAB));
key_override_t alt_tab_override  = ko_make_basic(MOD_BIT(KC_RALT), KC_ESC, RALT(KC_TAB));
key_override_t cmd_tab_override  = ko_make_basic(MOD_BIT(KC_LGUI), KC_ESC, LGUI(KC_TAB));
key_override_t shift_tab_override = ko_make_basic(MOD_BIT(KC_RSFT), KC_ESC, RSFT(KC_TAB));

key_override_t linux_a_override = ko_make_basic(MOD_BIT(KC_LGUI), KC_A, LCTL(KC_A));
key_override_t linux_b_override = ko_make_basic(MOD_BIT(KC_LGUI), KC_B, LCTL(KC_B));
key_override_t linux_c_override = ko_make_basic(MOD_BIT(KC_LGUI), KC_C, KC_COPY);
key_override_t linux_d_override = ko_make_basic(MOD_BIT(KC_LGUI), KC_D, KC_PASTE);
key_override_t linux_e_override = ko_make_basic(MOD_BIT(KC_LGUI), KC_E, LCTL(KC_E));
key_override_t linux_f_override = ko_make_basic(MOD_BIT(KC_LGUI), KC_F, LCTL(KC_F));
key_override_t linux_g_override = ko_make_basic(MOD_BIT(KC_LGUI), KC_G, LCTL(KC_G));
key_override_t linux_h_override = ko_make_basic(MOD_BIT(KC_LGUI), KC_H, LCTL(KC_H));
key_override_t linux_i_override = ko_make_basic(MOD_BIT(KC_LGUI), KC_I, LCTL(KC_I));
key_override_t linux_j_override = ko_make_basic(MOD_BIT(KC_LGUI), KC_J, LCTL(KC_J));
key_override_t linux_k_override = ko_make_basic(MOD_BIT(KC_LGUI), KC_K, LCTL(KC_K));
key_override_t linux_l_override = ko_make_basic(MOD_BIT(KC_LGUI), KC_L, LCTL(KC_L));
key_override_t linux_m_override = ko_make_basic(MOD_BIT(KC_LGUI), KC_M, LCTL(KC_M));
key_override_t linux_n_override = ko_make_basic(MOD_BIT(KC_LGUI), KC_N, LCTL(KC_N));
key_override_t linux_o_override = ko_make_basic(MOD_BIT(KC_LGUI), KC_O, LCTL(KC_O));
key_override_t linux_p_override = ko_make_basic(MOD_BIT(KC_LGUI), KC_P, LCTL(KC_P));
key_override_t linux_q_override = ko_make_basic(MOD_BIT(KC_LGUI), KC_Q, LCTL(KC_Q));
key_override_t linux_r_override = ko_make_basic(MOD_BIT(KC_LGUI), KC_R, LCTL(KC_R));
key_override_t linux_s_override = ko_make_basic(MOD_BIT(KC_LGUI), KC_S, LCTL(KC_S));
key_override_t linux_t_override = ko_make_basic(MOD_BIT(KC_LGUI), KC_T, LCTL(KC_T));
key_override_t linux_u_override = ko_make_basic(MOD_BIT(KC_LGUI), KC_U, LCTL(KC_U));
key_override_t linux_v_override = ko_make_basic(MOD_BIT(KC_LGUI), KC_V, LCTL(KC_V));
key_override_t linux_w_override = ko_make_basic(MOD_BIT(KC_LGUI), KC_W, LCTL(KC_W));
key_override_t linux_x_override = ko_make_basic(MOD_BIT(KC_LGUI), KC_X, KC_CUT);
key_override_t linux_y_override = ko_make_basic(MOD_BIT(KC_LGUI), KC_Y, LCTL(KC_Y));
key_override_t linux_z_override = ko_make_basic(MOD_BIT(KC_LGUI), KC_Z, LCTL(KC_Z));
key_override_t linux_com_override = ko_make_basic(MOD_BIT(KC_LGUI), KC_COMM, LCTL(KC_COMM));
key_override_t linux_dot_override = ko_make_basic(MOD_BIT(KC_LGUI), KC_DOT, LCTL(KC_DOT));

key_override_t ctrl_u_key_override = ko_make_basic(MOD_BIT(KC_LCTL), KC_U, LCMD(KC_BSPC));

void switch_override(key_override_t *override, bool enabled) {
    override->enabled = enabled ? NULL : &false_const;
}

void switch_jis(bool enabled) {
    switch_override(&jis_at_override, enabled);
    switch_override(&jis_circ_override, enabled);
    switch_override(&jis_ampr_override, enabled);
    switch_override(&jis_astr_override, enabled);
    switch_override(&jis_lprn_override, enabled);
    switch_override(&jis_rprn_override, enabled);
    switch_override(&jis_unds_override, enabled);
    switch_override(&jis_plus_override, enabled);
    switch_override(&jis_lbrc_override, enabled);
    switch_override(&jis_lcbr_override, enabled);
    switch_override(&jis_rbrc_override, enabled);
    switch_override(&jis_rcbr_override, enabled);
    switch_override(&jis_bsls_override, enabled);
    switch_override(&jis_pipe_override, enabled);
    switch_override(&jis_coln_override, enabled);
    switch_override(&jis_quot_override, enabled);
    switch_override(&jis_dquo_override, enabled);
    switch_override(&jis_grv_override, enabled);
    switch_override(&jis_tild_override, enabled);
    switch_override(&jis_eql_override, enabled);

    switch_override(&jis_s_2_override, enabled);
    switch_override(&jis_s_6_override, enabled);
    switch_override(&jis_s_7_override, enabled);
    switch_override(&jis_s_8_override, enabled);
    switch_override(&jis_s_9_override, enabled);
    switch_override(&jis_s_0_override, enabled);
    switch_override(&jis_s_mins_override, enabled);
    switch_override(&jis_s_eql_override, enabled);
    switch_override(&jis_s_lbrc_override, enabled);
    switch_override(&jis_s_rbrc_override, enabled);
    switch_override(&jis_s_bsls_override, enabled);
    switch_override(&jis_s_scln_override, enabled);
    switch_override(&jis_s_quot_override, enabled);
    switch_override(&jis_s_grv_override, enabled);
}

void switch_linux_cmd(bool enable) {
    switch_override(&linux_a_override, enable);
    switch_override(&linux_b_override, enable);
    switch_override(&linux_c_override, enable);
    switch_override(&linux_d_override, enable);
    switch_override(&linux_e_override, enable);
    switch_override(&linux_f_override, enable);
    switch_override(&linux_g_override, enable);
    switch_override(&linux_h_override, enable);
    switch_override(&linux_i_override, enable);
    switch_override(&linux_j_override, enable);
    switch_override(&linux_k_override, enable);
    switch_override(&linux_l_override, enable);
    switch_override(&linux_m_override, enable);
    switch_override(&linux_n_override, enable);
    switch_override(&linux_o_override, enable);
    switch_override(&linux_p_override, enable);
    switch_override(&linux_q_override, enable);
    switch_override(&linux_r_override, enable);
    switch_override(&linux_s_override, enable);
    switch_override(&linux_t_override, enable);
    switch_override(&linux_u_override, enable);
    switch_override(&linux_v_override, enable);
    switch_override(&linux_w_override, enable);
    switch_override(&linux_x_override, enable);
    switch_override(&linux_y_override, enable);
    switch_override(&linux_z_override, enable);
    switch_override(&linux_com_override, enable);
    switch_override(&linux_dot_override, enable);
}

void enable_all_overrides(void) {
    for (int i = 0; key_overrides[i] != NULL; i++) {
        key_override_t *ko = (key_override_t*)key_overrides[i];
        ko->enabled = NULL;
    }
};

void disable_all_overrides(void) {
    for (int i = 0; key_overrides[i] != NULL; i++) {
        key_override_t *ko = (key_override_t*)key_overrides[i];
        ko->enabled = &false_const;
    }
};

void switch_all_overrides_eeprom(bool enable) {
    bool tmp_macos = user_config.is_macos;
    bool tmp_win = user_config.is_windows;
    bool tmp_linux = user_config.is_linux;

    if (enable) {
        enable_all_overrides();
        user_config.raw = ~0;
    } else {
        disable_all_overrides();
        user_config.raw = 0;
    }

    user_config.is_macos = tmp_macos;
    user_config.is_windows = tmp_win;
    user_config.is_linux = tmp_linux;

    eeconfig_update_user(user_config.raw);
}

void disable_word_del_override(void) {
    switch_override(&w_del_mac_override, false);
    switch_override(&w_del_win_override, false);
}

void enable_word_del_override(void) {
    if (user_config.is_macos) { // If MacOS
        switch_override(&w_del_mac_override, true);
        switch_override(&w_del_win_override, false);
    } else if (user_config.is_windows) { // If Windows
        switch_override(&w_del_mac_override, false);
        switch_override(&w_del_win_override, true);
    } else if (user_config.is_linux) { // Linux is not implemented yet. Maybe depends on distributions.
        disable_word_del_override();
    }
}

void toggle_word_del_override(bool enable) {
    if (enable) {
        enable_word_del_override();
    } else {
        disable_word_del_override();
    }
}

const key_override_t **key_overrides = (const key_override_t *[]){
    &enter_key_override,
    &tab_key_override,
    &right_key_override,
    &left_key_override,
    &up_key_override,
    &down_key_override,
    &bs_key_override,
    &del_key_override,
    &home_key_override,
    &end_key_override,
    &ctrl_u_key_override,
    &cmd_space_override,

    &cmd_d_override,
    &cmd_v_override,

    &w_fwd_mac_override,
    &w_bck_mac_override,
    &w_del_mac_override,
    &w_fwd_win_override,
    &w_bck_win_override,
    &w_del_win_override,

    &ctrl_tab_override,
    &alt_tab_override,
    &cmd_tab_override,
    &shift_tab_override,

    &linux_a_override,
    &linux_b_override,
    &linux_c_override,
    &linux_d_override,
    &linux_e_override,
    &linux_f_override,
    &linux_g_override,
    &linux_h_override,
    &linux_i_override,
    &linux_j_override,
    &linux_k_override,
    &linux_l_override,
    &linux_m_override,
    &linux_n_override,
    &linux_o_override,
    &linux_p_override,
    &linux_q_override,
    &linux_r_override,
    &linux_s_override,
    &linux_t_override,
    &linux_u_override,
    &linux_v_override,
    &linux_w_override,
    &linux_x_override,
    &linux_y_override,
    &linux_z_override,
    &linux_com_override,
    &linux_dot_override,

    &jis_at_override,
    &jis_circ_override,
    &jis_ampr_override,
    &jis_astr_override,
    &jis_lprn_override,
    &jis_rprn_override,
    &jis_unds_override,
    &jis_plus_override,
    &jis_lbrc_override,
    &jis_lcbr_override,
    &jis_rbrc_override,
    &jis_rcbr_override,
    &jis_bsls_override,
    &jis_pipe_override,
    &jis_coln_override,
    &jis_quot_override,
    &jis_dquo_override,
    &jis_grv_override,
    &jis_tild_override,
    &jis_eql_override,

    &jis_s_2_override,
    &jis_s_6_override,
    &jis_s_7_override,
    &jis_s_8_override,
    &jis_s_9_override,
    &jis_s_0_override,
    &jis_s_mins_override,
    &jis_s_eql_override,
    &jis_s_lbrc_override,
    &jis_s_rbrc_override,
    &jis_s_bsls_override,
    &jis_s_scln_override,
    &jis_s_quot_override,
    &jis_s_grv_override,

    NULL,
};
