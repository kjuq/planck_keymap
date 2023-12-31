#pragma once

typedef union {
    uint32_t raw;
    struct {
        bool override_tab : 1;
        bool override_enter : 1;
        bool override_backspace : 1;
        bool override_delete : 1;
        bool override_arrows : 1;
        bool override_home : 1;
        bool override_end : 1;
        bool override_ctrl_k : 1;
        bool override_ctrl_o : 1;
        bool override_ctrl_u : 1;
        bool override_word_mv_apl : 1;
        bool override_word_mv_lnx : 1;
        bool override_word_dl_apl : 1;
        bool override_word_dl_lnx : 1;
        bool override_cmd_space : 1;
        bool override_cmd_v : 1;
        bool override_cmd_d : 1;
        bool override_cmd_q : 1;
        bool override_modded_esc : 1;
        bool override_linux_cmd : 1;
        bool is_jis_mode : 1;
        bool is_macos : 1;
        bool is_windows : 1;
        bool is_linux : 1;
        bool is_ios : 1;
        bool fnc_tap : 1;
        bool spc_tap : 1;
    };
} user_config_t;

user_config_t user_config;
