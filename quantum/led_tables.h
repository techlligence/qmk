/*
Copyright 2017 Fred Sundvik
Copyright 2019 /u/KeepItUnder

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.
This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.
You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef LED_TABLES_H
#define LED_TABLES_H

#include "progmem.h"
#include <stdint.h>

#ifdef USE_CIE1931_CURVE
extern const uint8_t CIE1931_CURVE[] PROGMEM;
#endif

#ifdef USE_LED_BREATHING_TABLE
extern const uint8_t LED_BREATHING_TABLE[] PROGMEM;
#endif

#ifdef USE_CIE1931_16_CURVE
extern const uint16_t CIE1931_16_CURVE[] PROGMEM;
#endif

#endif
