/**
 * Marlin 3D Printer Firmware
 * Copyright (c) 2020 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
 *
 * Based on Sprinter and grbl.
 * Copyright (c) 2011 Camiel Gubbels / Erik van der Zalm
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

#pragma once

#ifndef STM32F4
  #error "Oops! Select an STM32F4 board in 'Tools > Board.'"
#endif

//
// Limit Switches
//
#define X_MIN_PIN                             PA15
#define Y_MIN_PIN                             PC13
#define X_MAX_PIN                             PB1
#define Z_MAX_PIN                             PC12

//
// Filament runout
//
#define FIL_RUNOUT_PIN    PC5
#define FIL_RUNOUT2_PIN   PC4
#define BTN_ENC           PB0

//
// Steppers
//
#define X_STEP_PIN    PB5
#define X_DIR_PIN     PB4

#define X2_STEP_PIN   PC3
#define X2_DIR_PIN    PC2

#define Y_STEP_PIN    PB7
#define Y_DIR_PIN     PB6

#define Z_STEP_PIN    PB9
#define Z_DIR_PIN     PB8

#define E0_STEP_PIN   PC15
#define E0_DIR_PIN    PC14

#define E1_STEP_PIN   PC1
#define E1_DIR_PIN    PC0

//
// Temperature Sensors
//
#define TEMP_0_PIN        PA0
#define TEMP_1_PIN        PA1
#define TEMP_BED_PIN      PA2
#define TEMP_CHAMBER_PIN  PA3
// SPARE PT100 SENSOR @ PA4

//
// Heaters / Fans
//
#define HEATER_0_PIN      PA5
#define HEATER_1_PIN      PA6
#define HEATER_BED_PIN    PA7

//
// Onboard SD support
//
#define SDIO_D0_PIN     PC8
#define SDIO_D1_PIN     PC9
#define SDIO_D2_PIN     PC10
#define SDIO_D3_PIN     PC11
#define SDIO_CK_PIN     PB15
#define SDIO_CMD_PIN    PD2

#define SDCARD_CONNECTION   ONBOARD

//
// Required for sanity check
#define X_ENABLE_PIN 999
#define X2_ENABLE_PIN 999
#define Y_ENABLE_PIN 999
#define Z_ENABLE_PIN 999
#define E0_ENABLE_PIN 999
#define E1_ENABLE_PIN 999
