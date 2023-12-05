#pragma once

#include QMK_KEYBOARD_H

#include "user_layers.h"
#include "user_songs.h"
#include "user_eeprom.h"
#include "user_init.c"

inline static void user_enter_layer(uint8_t layer, uint8_t hue, uint8_t sat, uint8_t val) {
    #ifdef AUDIO_ENABLE
    stop_all_notes();
    PLAY_SONG(num_lock_on_song);
    #endif
    layer_move(layer);
    rgblight_mode_noeeprom(RGBLIGHT_MODE_SNAKE + 2);
    rgblight_sethsv_noeeprom(hue, sat, val);
    return;
}

inline static void user_exit_layer(void) {
    #ifdef AUDIO_ENABLE
    PLAY_SONG(num_lock_off_song);
    #endif
    layer_clear();
    rgblight_reload_from_eeprom();
    return;
};

inline static void user_react_key_press_by_RGB(uint8_t hue, uint8_t sat, uint8_t val) {
    #ifdef RGBLIGHT_ENABLE
    rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
    rgblight_sethsv_noeeprom(hue, sat, val);
    wait_ms(100); // 100 ms
    user_enter_layer(_ADJUST, HSV_ADJUST);
    #endif
    return;
};

void react_on_toggle(bool enable) {
    if (enable) {
        user_react_key_press_by_RGB(HSV_RED); // enable
    } else {
        user_react_key_press_by_RGB(HSV_BLUE); // disable
    }
}

void override_toggle_post(bool enable) {
    eeconfig_update_user(user_config.raw);
    reload_user_eeprom();
    react_on_toggle(enable);
}
