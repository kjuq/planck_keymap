#pragma once

#include QMK_KEYBOARD_H

#include "user_layers.h"
#include "user_songs.h"
#include "user_eeprom.h"
#include "user_init.c"

void user_enter_layer(uint8_t layer, uint8_t hue, uint8_t sat, uint8_t val) {
    stop_all_notes();
    PLAY_SONG(num_lock_on_song);
    layer_move(layer);
    rgblight_mode_noeeprom(RGBLIGHT_MODE_SNAKE + 2);
    rgblight_sethsv_noeeprom(hue, sat, val);
    return;
}

void user_exit_layer(void) {
    PLAY_SONG(num_lock_off_song);
    layer_clear();
    rgblight_reload_from_eeprom();
    return;
};

void user_react_key_press(uint8_t hue, uint8_t sat, uint8_t val) {
    rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
    rgblight_sethsv_noeeprom(hue, sat, val);
    wait_ms(100); // 100 ms
    user_enter_layer(_ADJUST, HSV_ADJUST);
    return;
};

void user_override_toggle_post(bool enable) {
    eeconfig_update_user(user_config.raw);
    user_reload_user_eeprom();
    if (enable) {
        user_react_key_press(HSV_RED); // enable
    } else {
        user_react_key_press(HSV_BLUE); // disable
    }
}
