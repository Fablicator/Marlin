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

// 2-wire PT100 Sensor with LM124 with ~55" 24 AWG leads 
const temp_entry_t temptable_24[] PROGMEM = {
    {OV(343),	-40},
    {OV(358),	-30},
    {OV(374),	-20},
    {OV(389),	-10},
    {OV(405),	0},
    {OV(420),	10},
    {OV(435),	20},
    {OV(450),	30},
    {OV(465),	40},
    {OV(480),	50},
    {OV(495),	60},
    {OV(510),	70},
    {OV(524),	80},
    {OV(539),	90},
    {OV(554),	100},
    {OV(568),	110},
    {OV(583),	120},
    {OV(597),	130},
    {OV(611),	140},
    {OV(625),	150},
    {OV(639),	160},
    {OV(653),	170},
    {OV(667),	180},
    {OV(681),	190},
    {OV(695),	200},
    {OV(709),	210},
    {OV(723),	220},
    {OV(736),	230},
    {OV(750),	240},
    {OV(763),	250},
    {OV(777),	260},
    {OV(790),	270},
    {OV(803),	280},
    {OV(816),	290},
    {OV(829),	300},
    {OV(842),	310},
    {OV(855),	320},
    {OV(868),	330},
    {OV(881),	340},
    {OV(894),	350},
    {OV(907),	360},
    {OV(919),	370},
    {OV(932),	380},
    {OV(944),	390},
    {OV(957),	400},
    {OV(1078),	500}
};