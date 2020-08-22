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
#define RETRO_TAPPING // long presses of MT/LT keys not paired with a second keypress will now result in a tap output
#define TAPPING_FORCE_HOLD // a tap followed by a hold of a MT/LT key used to be two taps, now it is a tap and a hold
#define PERMISSIVE_HOLD // SFT_T(a) down, j down, j up, SFT_T(a) up in < tapping_term will now be J instead of aj
// #define IGNORE_MOD_TAP_INTERRUPT // rolled mod-taps will now be sequential taps
#define QMK_KEYS_PER_SCAN 4
#define TAPPING_TERM 125

#define COMBO_COUNT 11
#define COMBO_TERM 75