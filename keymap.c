#include QMK_KEYBOARD_H

#include "action_layer.h"
#include "keycodes.h"
#include "keymap.h"

#include "overrides.c"
#include "init.c"
#include "utils.c"

void oneshot_layer_changed_user(uint8_t layer) {
    if (layer == _MODS || layer == _ORS) {
        disable_all_overrides();
    } else { // Exit _MODS and _ORS
        reload_user_eeprom();
    }
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case CMD_SPC:
        case ALT_SPC:
            return 125;
        default:
            return TAPPING_TERM;
    }
}

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case CMD_SPC:
        case ALT_SPC:
            // Do not select the hold action when another key is pressed.
            return false;
        default:
            // Immediately select the hold action when another key is pressed.
            return true;
    }
}

void keyboard_post_init_user(void) {
    // debug_enable=true;
    // debug_matrix=true;
    // debug_keyboard=true;
    // debug_mouse=true;

    reload_user_eeprom();
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {

        // Layers
        case QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
            }
            return false;
        case COLEMAK:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_COLEMAK);
            }
            return false;
        case ADJUST:
            if (record->event.pressed) {
                if (IS_LAYER_OFF(_ADJUST)) {
                    enter_layer(_ADJUST, HSV_ADJUST);
                } else {
                    exit_layer();
                }
            }
            return false;
        case ADJUST2:
            if (record->event.pressed) {
                if (IS_LAYER_OFF(_ADJUST2)) {
                    enter_layer(_ADJUST2, HSV_BACKLIT);
                } else {
                    exit_layer();
                }
            }
            return false;
        case MOUSE:
            if (record->tap.count && record->event.pressed) {
                enter_layer(_MOUSE, 40, 255, 255);
                return false;
            }
            return true;
        case FPS:
            if (record->event.pressed) {
                if (IS_LAYER_OFF(_FPS)) {
                    enter_layer(_FPS, HSV_CORAL);
                } else {
                    exit_layer();
                }
            }
            return false;

        // Extra keys
        case MS_SHFT:
            if (record->event.pressed) {
                delta_offset = MOUSEKEY_DELTA_OFFSET;
                mk_wheel_interval -= MOUSEKEY_WHEEL_INTERVAL_OFFSET;
            } else {
                delta_offset = 0;
                mk_wheel_interval += MOUSEKEY_WHEEL_INTERVAL_OFFSET;
            }
            return false;
        case EXT_LYR:
            if (record->event.pressed) { exit_layer(); }
            return false;

        // Hooks
        case DM_REC1:
            if (record->event.pressed) {
                #ifdef AUDIO_ENABLE
                PLAY_SONG(caps_lock_on_song);
                #endif
            }
            return true;
        case DM_REC2:
            if (record->event.pressed) {
                #ifdef AUDIO_ENABLE
                PLAY_SONG(caps_lock_off_song);
                #endif
            }
            return true;
        case DM_RSTP:
            if (record->event.pressed) {
                #ifdef AUDIO_ENABLE
                PLAY_SONG(unicode_windows_song);
                #endif
            }
            return true;

        // Key override
        case KO_TOGG:
            if (record->event.pressed) {
                react_key_press_by_RGB(HSV_ORANGE);
            }
            return true;

        case KO_TB:
            if (record->event.pressed) {
                switch_override_with_react(&tab_key_override, user_config.override_tab);
            }
            return false;
        case KO_EN:
            if (record->event.pressed) {
                switch_override_with_react(&enter_key_override, user_config.override_enter);
            }
            return false;
        case KO_BS:
            if (record->event.pressed) {
                switch_override_with_react(&bs_key_override, user_config.override_backspace);
            }
            return false;
        case KO_DL:
            if (record->event.pressed) {
                switch_override_with_react(&del_key_override, user_config.override_delete);
            }
            return false;
        case KO_AR:
            if (record->event.pressed) {
                // Modify the rest of the variables
                // Because the macro only takes one argument to change enabled state.
                switch_override(&down_key_override, user_config.override_arrows ? false : true);
                switch_override(&right_key_override, user_config.override_arrows ? false :  true);
                switch_override(&left_key_override, user_config.override_arrows ? false :  true);

                switch_override_with_react(&up_key_override, user_config.override_arrows);

            }
            return false;
        case KO_HM:
            if (record->event.pressed) {
                switch_override_with_react(&home_key_override, user_config.override_home);
            }
            return false;
        case KO_ED:
            if (record->event.pressed) {
                switch_override_with_react(&end_key_override, user_config.override_end);
            }
            return false;
        case KO_CTLK:
            if (record->event.pressed) {
                switch_override_with_react(&ctrl_k_key_override, user_config.override_ctrl_k);
            }
            return false;
        case KO_CTLO:
            if (record->event.pressed) {
                switch_override_with_react(&ctrl_o_key_override, user_config.override_ctrl_o);
            }
            return false;
        case KO_CTLU:
            if (record->event.pressed) {
                switch_override_with_react(&ctrl_u_key_override, user_config.override_ctrl_u);
            }
            return false;

        case KO_CMSP:
            if (record->event.pressed) {
                switch_override_with_react(&cmd_space_override, user_config.override_cmd_space);
            }
            return false;
        case KO_CMDV:
            if (record->event.pressed) {
                switch_override_with_react(&cmd_v_override, user_config.override_cmd_v);
            }
            return false;
        case KO_CMDD:
            if (record->event.pressed) {
                switch_override_with_react(&cmd_d_override, user_config.override_cmd_d);
            }
            return false;
        case KO_MTAB:
            if (record->event.pressed) {
                switch_override(&ctrl_tab_override, user_config.override_modded_esc ? false : true);
                switch_override(&alt_tab_override, user_config.override_modded_esc ? false :  true);
                switch_override(&cmd_tab_override, user_config.override_modded_esc ? false :  true);

                switch_override_with_react(&shift_tab_override, user_config.override_modded_esc);
            }
            return false;
        case KO_WD:
            if (record->event.pressed) {
                const bool cur_status = user_config.override_word_move;
                user_config.override_word_move = cur_status ? false : true;
                eeconfig_update_user(user_config.raw);

                toggle_word_override(!cur_status);

                react_on_toggle(cur_status);
            }
            return false;
        case KO_WDDL:
            if (record->event.pressed) {
                const bool cur_status = user_config.override_word_del;
                user_config.override_word_del = cur_status ? false : true;
                eeconfig_update_user(user_config.raw);

                toggle_word_del_override(!cur_status);

                react_on_toggle(cur_status);
            }
            return false;
        case KO_LXCM:
            if (record->event.pressed) {
                user_config.override_linux_cmd = user_config.override_linux_cmd ? false : true;
                switch_linux_cmd(user_config.override_linux_cmd);
                eeconfig_update_user(user_config.raw);
                react_key_press_by_RGB(HSV_ORANGE);
            }
            return false;

        case KO_JIS:
            if (record->event.pressed) {
                user_config.is_jis_mode = user_config.is_jis_mode ? false : true;
                switch_jis(user_config.is_jis_mode);
                eeconfig_update_user(user_config.raw);
                react_key_press_by_RGB(HSV_ORANGE);
            }
            return false;

        case SW_OS:
            if (record->event.pressed) {
                if (user_config.is_macos) {
                    init_windows();
                } else if (user_config.is_windows) { // Enable Linux
                    init_linux();
                } else { // Enable MacOS
                    init_macos();
                }
                eeconfig_update_user(user_config.raw);
                react_key_press_by_RGB(HSV_ORANGE);
            }
            return false;

        case KO_RSET:
            if (record->event.pressed) {
                reset_overrides_to_default();
                react_key_press_by_RGB(HSV_ORANGE);
            }
            return false;

        case KO_PRNT:
            if (record->event.pressed) {
                tap_code(KC_LNG2);
                register_code(KC_LSFT);
                tap_code16(KC_LABK);

                if (user_config.is_macos) {
                    SEND_STRING(" macos");
                } else if (user_config.is_windows) {
                    SEND_STRING(" win");
                } else if (user_config.is_linux) {
                    SEND_STRING(" linux");
                }

                if (key_override_is_enabled()) {
                    if (user_config.override_modded_esc) SEND_STRING(" modesc");
                    if (user_config.override_enter) SEND_STRING(" ent");
                    if (user_config.override_backspace) SEND_STRING(" bksp");
                    if (user_config.override_tab) SEND_STRING(" tab");
                    if (user_config.override_arrows) SEND_STRING(" arrow");
                    if (user_config.override_delete) SEND_STRING(" del");
                    if (user_config.override_word_del) SEND_STRING(" worddel");
                    if (user_config.override_word_move) SEND_STRING(" wordmv");
                    if (user_config.override_home) SEND_STRING(" home");
                    if (user_config.override_end) SEND_STRING(" end");
                    if (user_config.override_cmd_v) SEND_STRING(" cmdv");
                    if (user_config.spc_tap) SEND_STRING(" spctap");

                    SEND_STRING(" \\");

                    if (user_config.override_linux_cmd) SEND_STRING(" linuxcmd");

                    if (user_config.override_ctrl_k) SEND_STRING(" ctrlk");
                    if (user_config.override_ctrl_o) SEND_STRING(" ctrlo");
                    if (user_config.override_ctrl_u) SEND_STRING(" ctrlu");

                    if (user_config.fnc_tap) SEND_STRING(" fnctap");
                    if (user_config.override_cmd_d) SEND_STRING(" cmdd");

                    if (user_config.is_jis_mode) SEND_STRING(" jis");

                    if (user_config.override_cmd_space) SEND_STRING(" cmdspace");
                } else {
                    SEND_STRING(" override disabled");
                }

                tap_code(KC_SPC);
                tap_code16(KC_RABK);
                unregister_code(KC_LSFT);
            }
            return false;

        // Hold tap
        case LT_FNC:
            if (record->event.pressed) {
                bool cur_enabled = user_config.fnc_tap;
                react_on_toggle(!cur_enabled);
                if (cur_enabled) {
                    default_layer_or((layer_state_t)1 << _FNC_TAP);
                    default_layer_xor((layer_state_t)1 << _FNC_TAP);
                    user_config.fnc_tap = false;
                } else {
                    default_layer_or((layer_state_t)1 << _FNC_TAP);
                    user_config.fnc_tap = true;
                }
                eeconfig_update_user(user_config.raw);
            }
            return false;

        case MT_SPC:
            if (record->event.pressed) {
                bool cur_enabled = user_config.spc_tap;
                react_on_toggle(!cur_enabled);
                if (cur_enabled) {
                    default_layer_or((layer_state_t)1 << _SPC_TAP);
                    default_layer_xor((layer_state_t)1 << _SPC_TAP);
                    user_config.spc_tap = false;
                } else {
                    default_layer_or((layer_state_t)1 << _SPC_TAP);
                    user_config.spc_tap = true;
                }
                eeconfig_update_user(user_config.raw);
            }
            return false;
        }
    return true;
}
