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
#pragma once

#define REVERSE_TEMP_SENSOR_RANGE_24 1

// PT100 Sensor with TSZ124
const temp_entry_t temptable_24[] PROGMEM = {
    {OV(342),	-40},
    {OV(357),	-30},
    {OV(373),	-20},
    {OV(388),	-10},
    {OV(404),	0},
    {OV(419),	10},
    {OV(434),	20},
    {OV(449),	30},
    {OV(464),	40},
    {OV(479),	50},
    {OV(494),	60},
    {OV(509),	70},
    {OV(524),	80},
    {OV(538),	90},
    {OV(553),	100},
    {OV(567),	110},
    {OV(582),	120},
    {OV(596),	130},
    {OV(610),	140},
    {OV(624),	150},
    {OV(639),	160},
    {OV(653),	170},
    {OV(667),	180},
    {OV(680),	190},
    {OV(694),	200},
    {OV(708),	210},
    {OV(722),	220},
    {OV(735),	230},
    {OV(749),	240},
    {OV(762),	250},
    {OV(776),	260},
    {OV(789),	270},
    {OV(802),	280},
    {OV(815),	290},
    {OV(828),	300},
    {OV(842),	310},
    {OV(855),	320},
    {OV(867),	330},
    {OV(880),	340},
    {OV(893),	350},
    {OV(906),	360},
    {OV(918),	370},
    {OV(931),	380},
    {OV(943),	390},
    {OV(956),	400},
    {OV(1077),	500}
};