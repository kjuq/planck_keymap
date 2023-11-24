void init_macos(void) {
    switch_all_overrides_eeprom(false);
    user_config.is_macos = true;
    user_config.is_windows = false;
    user_config.is_linux = false;

    toggle_word_override(true);
    user_config.override_word_move = true;

    toggle_word_del_override(true);
    user_config.override_word_del = true;

    switch_override(&cmd_v_override, true);
    user_config.override_cmd_v = true;

    switch_override(&enter_key_override, true);
    user_config.override_enter = true;

    switch_override(&tab_key_override, true);
    user_config.override_tab = true;

    switch_override(&bs_key_override, true);
    user_config.override_backspace = true;

    switch_override(&del_key_override, true);
    user_config.override_delete = true;

    switch_override(&up_key_override, true);
    switch_override(&down_key_override, true);
    switch_override(&right_key_override, true);
    switch_override(&left_key_override, true);
    user_config.override_arrows = true;

    switch_override(&ctrl_tab_override, true);
    switch_override(&alt_tab_override, true);
    switch_override(&cmd_tab_override, true);
    switch_override(&shift_tab_override, true);
    user_config.override_modded_esc = true;

    default_layer_or((layer_state_t)1 << _SPC_TAP);
    default_layer_xor((layer_state_t)1 << _SPC_TAP);
    user_config.spc_tap = false;

    eeconfig_update_user(user_config.raw);
}

void init_windows(void) {
    switch_all_overrides_eeprom(true);
    user_config.is_macos = false;
    user_config.is_windows = true;
    user_config.is_linux = false;

    toggle_word_override(true);
    toggle_word_del_override(true);

    default_layer_or((layer_state_t)1 << _SPC_TAP);
    default_layer_xor((layer_state_t)1 << _SPC_TAP);
    user_config.spc_tap = false;

    switch_jis(false);
    user_config.is_jis_mode = false;

    eeconfig_update_user(user_config.raw);
}

void init_linux(void) {
    switch_all_overrides_eeprom(true);
    user_config.is_macos = false;
    user_config.is_windows = false;
    user_config.is_linux = true;

    toggle_word_override(false);
    toggle_word_del_override(false);

    default_layer_or((layer_state_t)1 << _SPC_TAP);
    default_layer_xor((layer_state_t)1 << _SPC_TAP);
    user_config.spc_tap = false;

    switch_jis(false);
    user_config.is_jis_mode = false;

    eeconfig_update_user(user_config.raw);
}

void reload_user_eeprom(void) {
    enable_all_overrides();

    user_config.raw = eeconfig_read_user();

    if (!user_config.override_tab) {
        switch_override(&tab_key_override, false);
    }
    if (!user_config.override_enter) {
        switch_override(&enter_key_override, false);
    }
    if (!user_config.override_backspace) {
        switch_override(&bs_key_override, false);
    }
    if (!user_config.override_delete) {
        switch_override(&del_key_override, false);
    }
    if (!user_config.override_arrows) {
        switch_override(&up_key_override, false);
        switch_override(&down_key_override, false);
        switch_override(&right_key_override, false);
        switch_override(&left_key_override, false);
    }
    if (!user_config.override_home) {
        switch_override(&home_key_override, false);
    }
    if (!user_config.override_end) {
        switch_override(&end_key_override, false);
    }
    if (!user_config.override_ctrl_k) {
        switch_override(&ctrl_k_key_override, false);
    }
    if (!user_config.override_ctrl_o) {
        switch_override(&ctrl_o_key_override, false);
    }
    if (!user_config.override_ctrl_u) {
        switch_override(&ctrl_u_key_override, false);
    }
    if (!user_config.override_cmd_space) {
        switch_override(&cmd_space_override, false);
    }
    if (!user_config.override_cmd_v) {
        switch_override(&cmd_v_override, false);
    }
    if (!user_config.override_cmd_d) {
        switch_override(&cmd_d_override, false);
    }
    if (!user_config.override_word_move) {
        switch_override(&w_fwd_mac_override, false);
        switch_override(&w_bck_mac_override, false);
        switch_override(&w_fwd_win_override, false);
        switch_override(&w_bck_win_override, false);
    }
    if (!user_config.override_word_del) {
        switch_override(&w_del_mac_override, false);
        switch_override(&w_del_win_override, false);
    }

    if (!user_config.override_modded_esc) {
        switch_override(&ctrl_tab_override, false);
        switch_override(&alt_tab_override, false);
        switch_override(&cmd_tab_override, false);
        switch_override(&shift_tab_override, false);
    }

    if (!user_config.is_jis_mode) {
        switch_jis(false);
    }

    if (user_config.fnc_tap) {
        default_layer_or((layer_state_t)1 << _FNC_TAP);
    }
    if (user_config.spc_tap) {
        default_layer_or((layer_state_t)1 << _SPC_TAP);
    }
};
