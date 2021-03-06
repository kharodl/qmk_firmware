/*
Copyright 2017 Danny Nguyen <danny@hexwire.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#define USE_I2C

// #define SPLIT_USB_DETECT
// Detect (with timeout) USB connection when delegating master/slave
// Default behavior for ARM
// Required for AVR Teensy
// #define SPLIT_USB_TIMEOUT 2000
// Maximum timeout when detecting master/slave when using SPLIT_USB_DETECT
// #define SPLIT_USB_TIMEOUT_POLL 10
// Poll frequency when

/* Select hand configuration */
// #define MASTER_RIGHT
// #define EE_HANDS

#define FORCE_NKRO

#define TAPPING_TERM 200

#undef RGBLED_NUM
#define RGBLIGHT_ANIMATIONS
#define RGBLED_NUM 12
#define RGBLIGHT_HUE_STEP 8
#define RGBLIGHT_SAT_STEP 16
#define RGBLIGHT_VAL_STEP 8

#define NO_ACTION_MACRO
#define NO_ACTION_FUNCTION
#define NO_ACTION_ONESHOT

#define NO_USB_STARTUP_CHECK
