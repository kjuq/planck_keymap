#pragma once

#ifdef AUDIO_ENABLE
// #    define STARTUP_SONG SONG(PLANCK_SOUND)
#    define STARTUP_SONG SONG(NO_SOUND)

#    define DEFAULT_LAYER_SONGS \
        { SONG(QWERTY_SOUND), SONG(COLEMAK_SOUND), SONG(DVORAK_SOUND) }
#endif

#define ENCODER_RESOLUTION 4

//#define ACTION_DEBUG

// Tap-Hold Configuration Options
#define HOLD_ON_OTHER_KEY_PRESS_PER_KEY
#define TAPPING_TERM 200
#define TAPPING_TERM_PER_KEY

// In order to make sounds when connected to a computer
#define AUDIO_INIT_DELAY

// Mouse Settings

// Delay between pressing a movement key and cursor movement (10)
// ... I can't see the difference though
#undef  MOUSEKEY_DELAY
#define MOUSEKEY_DELAY 10

// Time between cursor movements in milliseconds (20)
#undef  MOUSEKEY_INTERVAL
#define MOUSEKEY_INTERVAL 1

// Step size (8)
#undef  MOUSEKEY_MOVE_DELTA
#define MOUSEKEY_MOVE_DELTA 10

// Maximum cursor speed at which acceleration stops (10)
#undef  MOUSEKEY_MAX_SPEED
#define MOUSEKEY_MAX_SPEED 1

// Time until maximum cursor speed is reached (30)
// Set 0 to disable accleration
#undef  MOUSEKEY_TIME_TO_MAX
#define MOUSEKEY_TIME_TO_MAX 0

// Mouse Wheel Settings

// Delay between pressing a wheel key and wheel movement (10)
#undef  MOUSEKEY_WHEEL_DELAY
#define MOUSEKEY_WHEEL_DELAY 10

// Time between wheel movements (80)
#undef  MOUSEKEY_WHEEL_INTERVAL
#define MOUSEKEY_WHEEL_INTERVAL 80

// Maximum number of scroll steps per scroll action (8)
#undef  MOUSEKEY_WHEEL_MAX_SPEED
#define MOUSEKEY_WHEEL_MAX_SPEED 8

// Time until maximum scroll speed is reached (40)
// set 0 to disable accleration
#undef  MOUSEKEY_WHEEL_TIME_TO_MAX
#define MOUSEKEY_WHEEL_TIME_TO_MAX 40

// RGB Settings

// Enable RGB Animations
#define RGBLIGHT_EFFECT_ALTERNATING
#define RGBLIGHT_EFFECT_BREATHING
#define RGBLIGHT_EFFECT_CHRISTMAS
#define RGBLIGHT_EFFECT_KNIGHT
#define RGBLIGHT_EFFECT_RAINBOW_MOOD
#define RGBLIGHT_EFFECT_RAINBOW_SWIRL
#define RGBLIGHT_EFFECT_RGB_TEST
#define RGBLIGHT_EFFECT_SNAKE
#define RGBLIGHT_EFFECT_STATIC_GRADIENT
#define RGBLIGHT_EFFECT_TWINKLE

// Default RGB color
#define RGBLIGHT_DEFAULT_HUE 170

// Turn off RGB when computer went to sleep
#define RGBLIGHT_SLEEP

// Prevent freezing
#define DYNAMIC_MACRO_NO_NESTING
