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
#pragma once

// Vishay NTC 10k 3500 1206 10k Pullup
const temp_entry_t temptable_16[] PROGMEM = {
{OV(0), 140 },
{OV(20), 130 },
{OV(31), 120 },
{OV(40), 110 },
{OV(53), 100 },
{OV(69), 90 },
{OV(98), 80 },
{OV(142), 70 },
{OV(192), 60 },
{OV(282), 50 },
{OV(338), 40 },
{OV(450), 30},
{OV(512), 25},
{OV(574), 20},
{OV(637), 15},
{OV(698), 10},
{OV(755), 5},
{OV(807), 0}
};
