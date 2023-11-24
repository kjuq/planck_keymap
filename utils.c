void react_on_toggle(bool enabled) {
    if (enabled) {
        react_key_press_by_RGB(HSV_ORANGE); // disable
    } else {
        react_key_press_by_RGB(HSV_WHITE); // enable
    }
}

// Have to use a macro because bit field cannot be gotten a pointer
#define switch_override_with_react(override, user_config_key) { \
    bool enabled = (user_config_key) ? false : true; \
    switch_override((override), enabled); \
    (user_config_key) = enabled; \
    eeconfig_update_user(user_config.raw); \
    react_on_toggle(enabled); \
}
