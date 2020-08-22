// generated from users/manna-harbour_miryoku/miryoku.org  -*- buffer-read-only: t -*-

#pragma once


// Mouse key speed and acceleration.
#undef MOUSEKEY_DELAY
#define MOUSEKEY_DELAY          0
#undef MOUSEKEY_INTERVAL
#define MOUSEKEY_INTERVAL       16
#undef MOUSEKEY_WHEEL_DELAY
#define MOUSEKEY_WHEEL_DELAY    0
#undef MOUSEKEY_MAX_SPEED
#define MOUSEKEY_MAX_SPEED      6
#undef MOUSEKEY_TIME_TO_MAX
#define MOUSEKEY_TIME_TO_MAX    64

// Mod/layer tap configuation
// v0
// #define IGNORE_MOD_TAP_INTERRUPT
// #define TAPPING_FORCE_HOLD
// #define AUTO_SHIFT_TIMEOUT TAPPING_TERM
// #define RETRO_SHIFT 500
// #define QMK_KEYS_PER_SCAN 4
// #define TAPPING_TERM 150 // too slow, sometimes shifted characters wouldn't turn out because they were input too quickly

// v1
// #define IGNORE_MOD_TAP_INTERRUPT
// #define TAPPING_FORCE_HOLD
// #define AUTO_SHIFT_TIMEOUT TAPPING_TERM
// #define RETRO_SHIFT 500
// #define QMK_KEYS_PER_SCAN 4
// #define TAPPING_TERM 100 // too fast, sometimes hard to get taps to register

// v2
// #define IGNORE_MOD_TAP_INTERRUPT
// #define TAPPING_FORCE_HOLD
// #define AUTO_SHIFT_TIMEOUT TAPPING_TERM
// #define RETRO_SHIFT 500
// #define QMK_KEYS_PER_SCAN 4
// #define TAPPING_TERM 125

// // v3
// #define PERMISSIVE_HOLD
// #define RETRO_TAPPING
// #define IGNORE_MOD_TAP_INTERRUPT // turns rolled mod-taps in to sequential taps
// #define TAPPING_FORCE_HOLD
// // #define AUTO_SHIFT_TIMEOUT TAPPING_TERM // Irrelevant, I do not enable auto shift
// // #define RETRO_SHIFT 500 // cannot find another instance of this anywhere
// #define QMK_KEYS_PER_SCAN 4
// #define TAPPING_TERM 200

// v4
#define PERMISSIVE_HOLD
#define RETRO_TAPPING
#define IGNORE_MOD_TAP_INTERRUPT // turns rolled mod-taps in to sequential taps
#define TAPPING_FORCE_HOLD
#define QMK_KEYS_PER_SCAN 4
// #define TAPPING_TERM 200 // this was too long, I am missing shifted characters in particular, "I" intended comes out as "ai"
// #define TAPPING_TERM 150
#define TAPPING_TERM 125
