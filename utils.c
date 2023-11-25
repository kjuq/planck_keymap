void react_on_toggle(bool enable) {
    if (enable) {
        react_key_press_by_RGB(HSV_RED); // enable
    } else {
        react_key_press_by_RGB(HSV_BLUE); // disable
    }
}

void override_toggle_post(bool enable) {
    eeconfig_update_user(user_config.raw);
    reload_user_eeprom();
    react_on_toggle(enable);
}
