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
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 *
 */

#include "../../inc/MarlinConfig.h"
#include "../gcode.h"

/**
 * M9411: Report configuration parameters
 */

void GcodeSuite::M9411() {
    SERIAL_ECHOLN("v ----- Insert below into Calibration.h ----- v");
    SERIAL_ECHOLN("");

    #if ENABLED(USING_MX)
        SERIAL_ECHOLN("#define USING_MX");
    #elif ENABLED(USING_SX)
        SERIAL_ECHOLN("#define USING_SX");
    #elif ENABLED(USING_FM1)
        SERIAL_ECHOLN("#define USING_FM1");
    #else
        SERIAL_ECHOLN("No printer definition")
    #endif

    SERIAL_ECHOLN("");

    #if EXTRUDERS == 2
        const float tmp[] = HOTEND_OFFSET_Y;
        SERIAL_ECHOLNPAIR("#define HOTEND_OFFSET_Y {", tmp[0], ", ", tmp[1], "}");
        SERIAL_ECHOLNPAIR("#define X2_MAX_POS ", X2_MAX_POS);
    #endif

    SERIAL_ECHOLN("");

    SERIAL_ECHOLNPAIR("#define Z_MAX_POS ", Z_MAX_POS);
    
    SERIAL_ECHOLN("");

    SERIAL_ECHOLNPAIR("#define DEFAULT_Kp ", DEFAULT_Kp);
    SERIAL_ECHOLNPAIR("#define DEFAULT_Ki ", DEFAULT_Ki);
    SERIAL_ECHOLNPAIR("#define DEFAULT_Kd ", DEFAULT_Kd);
    
    SERIAL_ECHOLN("");

    SERIAL_ECHOLNPAIR("#define TEMP_SENSOR_BED ", TEMP_SENSOR_BED);

    SERIAL_ECHOLN("");

    #ifdef FILAMENT_RUNOUT_SENSOR
        SERIAL_ECHOLN("#define FILAMENT_RUNOUT_SENSOR");
    #endif

    SERIAL_ECHOLN("");

    #ifdef X_MICROSTEPS
        SERIAL_ECHOLNPAIR("#define X_MICROSTEPS ", X_MICROSTEPS);
    #endif
    #ifdef Y_MICROSTEPS
        SERIAL_ECHOLNPAIR("#define Y_MICROSTEPS ", Y_MICROSTEPS);
    #endif
    #ifdef Z_MICROSTEPS
        SERIAL_ECHOLNPAIR("#define Z_MICROSTEPS ", Z_MICROSTEPS);
    #endif
    #ifdef E_MICROSTEPS
        SERIAL_ECHOLNPAIR("#define E_MICROSTEPS ", E_MICROSTEPS);
    #endif
}