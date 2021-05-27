#pragma once

#ifdef AUDIO_ENABLE
#    define STARTUP_SONG SONG(PLANCK_SOUND)
// #    define STARTUP_SONG SONG(NO_SOUND)
//////////////////////////////////////////////////////////
// #define DEFAULT_LAYER_SONGS { SONG(QWERTY_SOUND), \  //
//                               SONG(COLEMAK_SOUND), \ //
//                               SONG(DVORAK_SOUND) \   //
//                             }                        //
//////////////////////////////////////////////////////////
#endif

#undef TAPPING_TERM
#define TAPPING_TERM 175
#define TAPPING_TERM_PER_KEY
#define PERMISSIVE_HOLD
#define IGNORE_MOD_TAP_INTERRUPT_PER_KEY
#define RETRO_TAPPING
#define RETRO_TAPPING_PER_KEY

#define LEADER_PER_KEY_TIMING
#define LEADER_TIMEOUT 500

// Limits the max. amount of layers to 8 to save firmware memory.
/* #define LAYER_STATE_8BIT */

#define MIDI_ADVANCED
/* override number of MIDI tone keycodes (each octave adds 12 keycodes and allocates 12 bytes) */
/* #define MIDI_TONE_KEYCODE_OCTAVES 2 */

#define COMBO_VARIABLE_LEN
/* #define COMBO_COUNT 13 */
#define COMBO_TERM 30
// Set the mouse settings to a comfortable speed/accuracy trade-off
// Assume the screen refresh rate is 60 Hz or higher
// The default is 50. This makes the mouse ~3 times faster and more accurate
// #undef to override default settings
#undef MOUSEKEY_INTERVAL
#define MOUSEKEY_INTERVAL 16
// The default is 20. Since we made the mouse about 3 times faster with the previous setting,
// give it more time to accelerate to max speed to retain precise control over short distances.
#undef MOUSEKEY_TIME_TO_MAX
#define MOUSEKEY_TIME_TO_MAX 40
// The default is 300. Let's try and make this as low as possible while keeping the cursor responsive
#undef MOUSEKEY_DELAY
#define MOUSEKEY_DELAY 100

#define MK_3_SPEED
#define MK_MOMENTARY_ACCEL

#ifdef RGBLIGHT_ENABLE
#    define RGBLIGHT_LAYERS
#    define RGBLIGHT_LAYERS_OVERRIDE_RGB_OFF
#    define RGBLIGHT_SLEEP
#    if defined(__AVR__) && !defined(__AVR_AT90USB1286__)
#        undef RGBLIGHT_ANIMATIONS
#        define RGBLIGHT_EFFECT_BREATHING
#        define RGBLIGHT_EFFECT_SNAKE
#        define RGBLIGHT_EFFECT_KNIGHT
#    else
#        define RGBLIGHT_ANIMATIONS
// #define RGB_MATRIX_STARTUP_VAL RGB_MATRIX_MAXIMUM_BRIGHTNESS
// #        define RGBLIGHT_LIMIT_VAL 10
#    endif
#endif  // RGBLIGHT_ENABLE
