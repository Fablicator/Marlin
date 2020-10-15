/**
 * Marlin 3D Printer Firmware
 * Copyright (c) 2019 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
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

#include "../../gcode.h"

#include "../../../inc/MarlinConfig.h"

#if ENABLED(USING_MX) || ENABLED(USING_SX) || ENABLED(USING_FM1)

  /**
   * M9411: Report parameters from Calibration.h
   */
  void GcodeSuite::M9411() {
    SERIAL_ECHO_START();
    SERIAL_ECHOLNPGM("\n\n\n\n");
    SERIAL_ECHOLNPGM("----------------------------");
    SERIAL_ECHOLNPGM("Calibration.h");
    SERIAL_ECHOLNPGM("----------------------------");
    SERIAL_ECHOLNPGM("\n\n\n\n");
    #if ENABLED(USING_MX)
      SERIAL_ECHOLNPGM("#define USING_MX");
    #elif ENABLED(USING_FM1)
      SERIAL_ECHOLNPGM("#define USING_FM1");
    #elif ENABLED(USING_SX)
      SERIAL_ECHOLNPGM("#define USING_SX");
    #endif

    SERIAL_ECHOLNPGM(" ");

    SERIAL_ECHOLNPAIR("#define Z_MAX_POS ", Z_MAX_POS);
    SERIAL_ECHOLNPAIR("#define X1_BED_OFFSET ", X1_BED_OFFSET);
    #if ENABLED(USING_MX)
      SERIAL_ECHOLNPAIR("#define X2_BED_OFFSET ", X2_BED_OFFSET);
      float tmp[] = HOTEND_OFFSET_Y;
      SERIAL_ECHOLNPAIR("#define HOTEND_OFFSET_Y { ", tmp[0],", ", tmp[1], " }");
    #endif
    SERIAL_ECHOLNPGM(" ");
    SERIAL_ECHOLNPAIR("#define DEFAULT_Kp ", DEFAULT_Kp);
    SERIAL_ECHOLNPAIR("#define DEFAULT_Ki ", DEFAULT_Ki);
    SERIAL_ECHOLNPAIR("#define DEFAULT_Kd ", DEFAULT_Kd);
    SERIAL_ECHOLNPGM(" ");
    SERIAL_ECHOLNPAIR("#define TEMP_SENSOR_BED ", TEMP_SENSOR_BED);
    

    SERIAL_ECHOLNPGM(" ");
    #if ENABLED(FILAMENT_RUNOUT_SENSOR)
      SERIAL_ECHOLNPGM("#define FILAMENT_RUNOUT_SENSOR");
    #endif
    
    #if ENABLED(USING_INDUSTRIAL_SUPPLY)
      SERIAL_ECHOLNPGM("#define USING_INDUSTRIAL_SUPPLY");
    #endif
  }
#endif