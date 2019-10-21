/**
 * Marlin 3D Printer Firmware
 * Copyright (C) 2016 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
 *
 * Based on Sprinter and grbl.
 * Copyright (C) 2011 Camiel Gubbels / Erik van der Zalm
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

/**
 * Ultimaker pin assignments
 */

#if !defined(__AVR_ATmega1280__) && !defined(__AVR_ATmega2560__)
  #error "Oops!  Make sure you have 'Arduino Mega' selected from the 'Tools -> Boards' menu."
#endif

#define DEFAULT_MACHINE_NAME    "FABLICATOR"
#define DEFAULT_SOURCE_CODE_URL ""
#define BOARD_NAME              "FABLICATOR"

#define LARGE_FLASH true

//
// Servos
//
#define LED_PIN         13

//
// Limit Switches
//
#define X_MIN_PIN          32
#define X_MAX_PIN          -1
#define Y_MIN_PIN          33
#define Y_MAX_PIN          -1
#define Z_MIN_PIN          -1
#define Z_MAX_PIN          34

//
//
// Steppers
//
#define X_STEP_PIN         22
#define X_DIR_PIN          23
#define X_ENABLE_PIN       16

#define X2_STEP_PIN        37
#define X2_DIR_PIN         36
#define X2_ENABLE_PIN      16


#define Y_STEP_PIN         24
#define Y_DIR_PIN          25
#define Y_ENABLE_PIN       16

#define Z_STEP_PIN         26
#define Z_DIR_PIN          27
#define Z_ENABLE_PIN       16

#define E0_STEP_PIN        28
#define E0_DIR_PIN         29
#define E0_ENABLE_PIN      16

#define E1_STEP_PIN        30
#define E1_DIR_PIN         31
#define E1_ENABLE_PIN      16

//
// Temperature Sensors
//
#define TEMP_0_PIN          6   // Analog Input
#define TEMP_1_PIN          7   // Analog Input
#define TEMP_BED_PIN       2   // Analog Input

//
// Heaters / Fans
//
#define HEATER_0_PIN        2
#define HEATER_1_PIN        3
#define HEATER_BED_PIN      4

#define FAN_PIN             -1