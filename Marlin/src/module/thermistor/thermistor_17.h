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

// 10k 3% Honeywell 175-103LAE thermistor
const short temptable_17[][2] PROGMEM = {
  {OV(22),  150 },
  {OV(31),  135 },
  {OV(35),  115},
  {OV(39),  112 },
  {OV(44),  110 },
  {OV(50),  105 },
  {OV(57),  100 },
  {OV(65),  95 },
  {OV(74),  90 },
  {OV(97),   82 },
  {OV(127),   73 },
  {OV(168),   66 },
  {OV(221),   54 },
  {OV(287),   45 },
  {OV(368),   38 },
  {OV(462),   31 },
  {OV(564),   20 },
  {OV(668),   10 },
  {OV(764),   0 },
  {OV(985),  -40 }
};