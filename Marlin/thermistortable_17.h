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
  {    22 * OVERSAMPLENR,  150 },
  {   31 * OVERSAMPLENR,  135 },
  {  35 * OVERSAMPLENR,  115},
  {  39 * OVERSAMPLENR,  112 },
  {  44 * OVERSAMPLENR,  110 },
  {  50 * OVERSAMPLENR,  105 },
  {  57 * OVERSAMPLENR,  100 },
  {  65 * OVERSAMPLENR,  95 },
  {  74 * OVERSAMPLENR,  90 },
  {  97 * OVERSAMPLENR,   82 },
  {  127 * OVERSAMPLENR,   73 },
  {  168 * OVERSAMPLENR,   66 },
  {  221 * OVERSAMPLENR,   54 },
  {  287 * OVERSAMPLENR,   45 },
  {  368 * OVERSAMPLENR,   38 },
  {  462 * OVERSAMPLENR,   31 },
  {  564 * OVERSAMPLENR,   20 },
  {  668 * OVERSAMPLENR,   10 },
  {  764 * OVERSAMPLENR,   0 },
  { 985 * OVERSAMPLENR,  -40 }
};
