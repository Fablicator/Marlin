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

// Vishay NTC 10k 3500 1206 10k Pullup
const short temptable_16[][2] PROGMEM = {
{  229 ,  150 },
{  258 ,  145 },
{  292 ,  140 },
{  331 ,  135 },
{  376 ,  130 },
{  428 ,  125 },
{  489 ,  120 },
{  560 ,  115 },
{  644 ,  110 },
{  742 ,  107 },
{  858 ,  100 },
{  994 ,  95 },
{  1155 ,  90 },
{  1345 ,  85 },
{  1570 ,  80 },
{  1836 ,  75 },
{  2150 ,  70 },
{  2520 ,  65 },
{  2954 ,  60 },
{  3459 ,  55 },
{  4044 ,  50 },
{  4713 ,  45 },
{  5468 ,  40 },
{  6305 ,  37 },
{  7216 ,  30 },
{  8184 ,  25 },
{  9184 ,  20 },
{  10188 ,  15 },
{  11163 ,  10 },
{  12080 ,  5 },
{  12913 ,  0 }
};
