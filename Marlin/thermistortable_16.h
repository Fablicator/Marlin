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
{0 * OVERSAMPLENR, 140 },
{20 * OVERSAMPLENR, 130 },
{31 * OVERSAMPLENR, 120 },
{40 * OVERSAMPLENR, 110 },
{53 * OVERSAMPLENR, 100 },
{69 * OVERSAMPLENR, 90 },
{98 * OVERSAMPLENR, 80 },
{142 * OVERSAMPLENR, 70 },
{192 * OVERSAMPLENR, 60 },
{282 * OVERSAMPLENR, 50 },
{338 * OVERSAMPLENR, 40 },
{450 * OVERSAMPLENR, 30},
{512 * OVERSAMPLENR, 25},
{574 * OVERSAMPLENR, 20},
{637 * OVERSAMPLENR, 15},
{698 * OVERSAMPLENR, 10},
{755 * OVERSAMPLENR, 5},
{807 * OVERSAMPLENR, 0}
};
