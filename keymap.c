#include QMK_KEYBOARD_H

#include "action_layer.h"
#include "keycodes.h"
#include "keymap.h"

#include "overrides.c"
#include "init.c"
#include "utils.c"

#include "os_detection.h"

bool is_apple;
bool is_lnxwin;

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

    wait_ms(500);

    if (detected_host_os() == OS_MACOS) {
        init_macos();
    } else if (detected_host_os() == OS_IOS) {
        init_ios();
    } else if (detected_host_os() == OS_LINUX) {
        init_linux();
    } else if (detected_host_os() == OS_WINDOWS) {
        init_windows();
    } else {
        init_unsure();
    }

    is_apple = user_config.is_macos || user_config.is_ios;
    is_lnxwin = user_config.is_linux || user_config.is_windows;

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
                user_config.override_tab = user_config.override_tab ? false : true;
                override_toggle_post(user_config.override_tab);
            }
            return false;
        case KO_EN:
            if (record->event.pressed) {
                user_config.override_enter = user_config.override_enter ? false : true;
                override_toggle_post(user_config.override_enter);
            }
            return false;
        case KO_BS:
            if (record->event.pressed) {
                user_config.override_backspace = user_config.override_backspace ? false : true;
                override_toggle_post(user_config.override_backspace);
            }
            return false;
        case KO_DL:
            if (record->event.pressed) {
                user_config.override_delete = user_config.override_delete ? false : true;
                override_toggle_post(user_config.override_delete);
            }
            return false;
        case KO_AR:
            if (record->event.pressed) {
                user_config.override_arrows = user_config.override_arrows ? false : true;
                override_toggle_post(user_config.override_arrows);
            }
            return false;
        case KO_HM:
            if (record->event.pressed) {
                user_config.override_home = user_config.override_home ? false : true;
                override_toggle_post(user_config.override_home);
            }
            return false;
        case KO_ED:
            if (record->event.pressed) {
                user_config.override_end = user_config.override_end ? false : true;
                override_toggle_post(user_config.override_end);
            }
            return false;
        case KO_CTLU:
            if (record->event.pressed) {
                user_config.override_ctrl_u = user_config.override_ctrl_u ? false : true;
                override_toggle_post(user_config.override_ctrl_u);
            }
            return false;

        case KO_CMSP:
            if (record->event.pressed) {
                user_config.override_cmd_space = user_config.override_cmd_space ? false : true;
                override_toggle_post(user_config.override_cmd_space);
            }
            return false;
        case KO_CMDV:
            if (record->event.pressed) {
                user_config.override_cmd_v = user_config.override_cmd_v ? false : true;
                override_toggle_post(user_config.override_cmd_v);
            }
            return false;
        case KO_CMDD:
            if (record->event.pressed) {
                user_config.override_cmd_d = user_config.override_cmd_d ? false : true;
                override_toggle_post(user_config.override_cmd_d);
            }
            return false;
        case KO_CMDQ:
            if (record->event.pressed) {
                user_config.override_cmd_q = user_config.override_cmd_q ? false : true;
                override_toggle_post(user_config.override_cmd_q);
            }
            return false;
        case KO_MTAB:
            if (record->event.pressed) {
                user_config.override_modded_esc = user_config.override_modded_esc ? false : true;
                override_toggle_post(user_config.override_modded_esc);
            }
            return false;
        case KO_WD:
            if (record->event.pressed) {
                bool cur_status;
                if (is_apple) {
                    cur_status = user_config.override_word_mv_apl;
                    user_config.override_word_mv_apl = cur_status ? false : true;
                } else {
                    cur_status = user_config.override_word_mv_lnx;
                    user_config.override_word_mv_lnx = cur_status ? false : true;
                }
                override_toggle_post(cur_status);
            }
            return false;
        case KO_WDDL:
            if (record->event.pressed) {
                bool cur_status;
                if (is_apple) {
                    cur_status = user_config.override_word_dl_apl;
                    user_config.override_word_dl_apl = cur_status ? false : true;
                } else {
                    cur_status = user_config.override_word_dl_lnx;
                    user_config.override_word_dl_lnx = cur_status ? false : true;
                }
                override_toggle_post(cur_status);
            }
            return false;
        case KO_LXCM:
            if (record->event.pressed) {
                user_config.override_linux_cmd = user_config.override_linux_cmd ? false : true;
                override_toggle_post(user_config.override_linux_cmd);
            }
            return false;

        case KO_JIS:
            if (record->event.pressed) {
                user_config.is_jis_mode = user_config.is_jis_mode ? false : true;
                override_toggle_post(user_config.is_jis_mode);
            }
            return false;

        case KO_PRNT:
            if (record->event.pressed) {
                tap_code(KC_LNG2);
                register_code(KC_LSFT);
                tap_code16(KC_LBRC);

                if (user_config.is_macos) {
                    SEND_STRING(" macos");
                } else if (user_config.is_windows) {
                    SEND_STRING(" win");
                } else if (user_config.is_linux) {
                    SEND_STRING(" linux");
                } else if (user_config.is_ios) {
                    SEND_STRING(" ios");
                } else {
                    SEND_STRING(" unknown");
                }
                SEND_STRING(" \\");

                if (key_override_is_enabled()) {
                    if (user_config.override_modded_esc) SEND_STRING(" modesc");
                    if (user_config.override_enter) SEND_STRING(" ent");
                    if (user_config.override_backspace) SEND_STRING(" bksp");
                    if (user_config.override_tab) SEND_STRING(" tab");
                    if (user_config.override_arrows) SEND_STRING(" arr");
                    if (user_config.override_delete) SEND_STRING(" del");
                    if (user_config.override_word_dl_apl) SEND_STRING(" wddlapl");
                    if (user_config.override_word_dl_lnx) SEND_STRING(" wddllnx");
                    if (user_config.override_word_mv_apl) SEND_STRING(" wdmvapl");
                    if (user_config.override_word_mv_lnx) SEND_STRING(" wdmvlnx");
                    if (user_config.override_ctrl_u) SEND_STRING(" ctlu");
                    if (user_config.override_cmd_v) SEND_STRING(" cmdv");
                    if (user_config.override_cmd_q) SEND_STRING(" cmdq");
                    if (user_config.spc_tap) SEND_STRING(" spctap");

                    SEND_STRING(" \\");

                    if (user_config.override_home) SEND_STRING(" home");
                    if (user_config.override_end) SEND_STRING(" end");

                    SEND_STRING(" \\");

                    if (user_config.override_linux_cmd) SEND_STRING(" lnxcmd");

                    if (user_config.override_cmd_d) SEND_STRING(" cmdd");

                    if (user_config.is_jis_mode) SEND_STRING(" jis");

                    if (user_config.fnc_tap) SEND_STRING(" fnctap");
                    if (user_config.override_cmd_space) SEND_STRING(" cmdspc");
                } else {
                    SEND_STRING(" override disabled");
                }

                tap_code(KC_SPC);
                tap_code16(KC_RBRC);
                unregister_code(KC_LSFT);
            }
            return false;

        // Hold tap
        case LT_FNC:
            if (record->event.pressed) {
                user_config.fnc_tap = user_config.fnc_tap ? false : true;
                override_toggle_post(user_config.fnc_tap);
            }
            return false;

        case MT_SPC:
            if (record->event.pressed) {
                user_config.spc_tap = user_config.spc_tap ? false : true;
                override_toggle_post(user_config.spc_tap);
            }
            return false;
        }
    return true;
}
