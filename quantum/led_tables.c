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

#include "led_tables.h"


#ifdef USE_CIE1931_CURVE
// Lightness curve using the CIE 1931 lightness formula
//Generated by the python script provided in http://jared.geek.nz/2013/feb/linear-led-pwm
const uint8_t CIE1931_CURVE[256] PROGMEM = {
  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   1,   1,   1,   1,   1,   1,
  1,   1,   1,   2,   2,   2,   2,   2,   2,   2,   2,   3,   3,   3,   3,   3,
  3,   3,   4,   4,   4,   4,   4,   5,   5,   5,   5,   5,   6,   6,   6,   6,
  6,   7,   7,   7,   7,   8,   8,   8,   8,   9,   9,   9,  10,  10,  10,  11,
 11,  11,  12,  12,  12,  13,  13,  13,  14,  14,  14,  15,  15,  16,  16,  16,
 17,  17,  18,  18,  19,  19,  20,  20,  21,  21,  22,  22,  23,  23,  24,  24,
 25,  25,  26,  26,  27,  28,  28,  29,  29,  30,  31,  31,  32,  33,  33,  34,
 35,  35,  36,  37,  37,  38,  39,  40,  40,  41,  42,  43,  44,  44,  45,  46,
 47,  48,  49,  49,  50,  51,  52,  53,  54,  55,  56,  57,  58,  59,  60,  61,
 62,  63,  64,  65,  66,  67,  68,  69,  70,  71,  72,  73,  75,  76,  77,  78,
 79,  80,  82,  83,  84,  85,  87,  88,  89,  90,  92,  93,  94,  96,  97,  99,
100, 101, 103, 104, 106, 107, 108, 110, 111, 113, 114, 116, 118, 119, 121, 122,
124, 125, 127, 129, 130, 132, 134, 135, 137, 139, 141, 142, 144, 146, 148, 149,
151, 153, 155, 157, 159, 161, 162, 164, 166, 168, 170, 172, 174, 176, 178, 180,
182, 185, 187, 189, 191, 193, 195, 197, 200, 202, 204, 206, 208, 211, 213, 215,
218, 220, 222, 225, 227, 230, 232, 234, 237, 239, 242, 244, 247, 249, 252, 255
};
#endif

#ifdef USE_LED_BREATHING_TABLE
const uint8_t LED_BREATHING_TABLE[256] PROGMEM = {
  0, 0, 0, 0, 1, 1, 1, 2, 2, 3, 4, 5, 5, 6, 7, 9,
  10, 11, 12, 14, 15, 17, 18, 20, 21, 23, 25, 27, 29, 31, 33, 35,
  37, 40, 42, 44, 47, 49, 52, 54, 57, 59, 62, 65, 67, 70, 73, 76,
  79, 82, 85, 88, 90, 93, 97, 100, 103, 106, 109, 112, 115, 118, 121, 124,
  127, 131, 134, 137, 140, 143, 146, 149, 152, 155, 158, 162, 165, 167, 170, 173,
  176, 179, 182, 185, 188, 190, 193, 196, 198, 201, 203, 206, 208, 211, 213, 215,
  218, 220, 222, 224, 226, 228, 230, 232, 234, 235, 237, 238, 240, 241, 243, 244,
  245, 246, 248, 249, 250, 250, 251, 252, 253, 253, 254, 254, 254, 255, 255, 255,
  255, 255, 255, 255, 254, 254, 254, 253, 253, 252, 251, 250, 250, 249, 248, 246,
  245, 244, 243, 241, 240, 238, 237, 235, 234, 232, 230, 228, 226, 224, 222, 220,
  218, 215, 213, 211, 208, 206, 203, 201, 198, 196, 193, 190, 188, 185, 182, 179,
  176, 173, 170, 167, 165, 162, 158, 155, 152, 149, 146, 143, 140, 137, 134, 131,
  128, 124, 121, 118, 115, 112, 109, 106, 103, 100, 97, 93, 90, 88, 85, 82,
  79, 76, 73, 70, 67, 65, 62, 59, 57, 54, 52, 49, 47, 44, 42, 40,
  37, 35, 33, 31, 29, 27, 25, 23, 21, 20, 18, 17, 15, 14, 12, 11,
  10, 9, 7, 6, 5, 5, 4, 3, 2, 2, 1, 1, 1, 0, 0, 0
};
#endif

#ifdef USE_CIE1931_16_CURVE
// Lightness curve using the CIE 1931 lightness formula
//Generated by the python script provided in http://jared.geek.nz/2013/feb/linear-led-pwm
const uint16_t CIE1931_16_CURVE[] PROGMEM = {
	0, 7, 14, 21, 28, 36, 43, 50, 57, 64, 
	71, 78, 85, 93, 100, 107, 114, 121, 128, 135, 
	142, 149, 157, 164, 172, 180, 189, 197, 206, 215, 
	225, 234, 244, 254, 265, 276, 287, 298, 310, 322, 
	334, 346, 359, 373, 386, 400, 414, 428, 443, 458, 
	474, 490, 506, 522, 539, 557, 574, 592, 610, 629, 
	648, 668, 688, 708, 729, 750, 771, 793, 815, 838, 
	861, 885, 909, 933, 958, 983, 1009, 1035, 1061, 1088, 
	1116, 1144, 1172, 1201, 1230, 1260, 1290, 1321, 1353, 1384, 
	1417, 1449, 1482, 1516, 1550, 1585, 1621, 1656, 1693, 1729, 
	1767, 1805, 1843, 1882, 1922, 1962, 2003, 2044, 2085, 2128, 
	2171, 2214, 2258, 2303, 2348, 2394, 2440, 2487, 2535, 2583, 
	2632, 2681, 2731, 2782, 2833, 2885, 2938, 2991, 3045, 3099, 
	3154, 3210, 3266, 3323, 3381, 3439, 3498, 3558, 3618, 3679, 
	3741, 3803, 3867, 3930, 3995, 4060, 4126, 4193, 4260, 4328, 
	4397, 4466, 4536, 4607, 4679, 4752, 4825, 4899, 4973, 5049, 
	5125, 5202, 5280, 5358, 5437, 5517, 5598, 5680, 5762, 5845, 
	5929, 6014, 6100, 6186, 6273, 6361, 6450, 6540, 6630, 6722, 
	6814, 6907, 7001, 7095, 7191, 7287, 7385, 7483, 7582, 7682, 
	7782, 7884, 7986, 8090, 8194, 8299, 8405, 8512, 8620, 8729, 
	8838, 8949, 9060, 9173, 9286, 9400, 9516, 9632, 9749, 9867, 
	9986, 10106, 10227, 10348, 10471, 10595, 10720, 10845, 10972, 11100, 
	11228, 11358, 11489, 11620, 11753, 11887, 12021, 12157, 12294, 12432, 
	12570, 12710, 12851, 12993, 13136, 13279, 13424, 13570, 13718, 13866, 
	14015, 14165, 14317, 14469, 14622, 14777, 14933, 15089, 15247, 15406, 
	15566, 15727, 15890, 16053, 16217, 16383, 
    };
#endif