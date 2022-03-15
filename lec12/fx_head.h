#pragma once 

// Fixed with signed long long
#define FX_S28_35	((1<<16) | (28<<8) | (35)) 
#define FX_S29_34	((1<<16) | (29<<8) | (34))
#define FX_S30_33	((1<<16) | (30<<8) | (33))
#define FX_S31_32	((1<<16) | (31<<8) | (32))
#define FX_S32_31	((1<<16) | (32<<8) | (31))
#define FX_S33_30	((1<<16) | (33<<8) | (30))
#define FX_S34_29	((1<<16) | (34<<8) | (29))
#define FX_S35_28	((1<<16) | (35<<8) | (28))
// Fixed with unsigned long long
#define FX_U29_35	((0<<16) | (29<<8) | (35)) 
#define FX_U30_34	((0<<16) | (30<<8) | (34))
#define FX_U31_33	((0<<16) | (31<<8) | (33))
#define FX_U32_32	((0<<16) | (32<<8) | (32))
#define FX_U33_31	((0<<16) | (33<<8) | (31))
#define FX_U34_30	((0<<16) | (34<<8) | (30))
#define FX_U35_29	((0<<16) | (35<<8) | (29))
#define FX_U36_28	((0<<16) | (36<<8) | (28))
// Fixed with signed int
#define FX_S12_19	((1<<16) | (12<<8) | (19)) 
#define FX_S13_18	((1<<16) | (13<<8) | (18))
#define FX_S14_17	((1<<16) | (14<<8) | (17))
#define FX_S15_16	((1<<16) | (15<<8) | (16))
#define FX_S16_15	((1<<16) | (16<<8) | (15))
#define FX_S17_14	((1<<16) | (17<<8) | (14))
#define FX_S18_13	((1<<16) | (18<<8) | (13))
#define FX_S19_12	((1<<16) | (19<<8) | (12))
// Fixed with unsigned int
#define FX_S13_19	((0<<16) | (13<<8) | (19)) 
#define FX_S14_18	((0<<16) | (14<<8) | (18))
#define FX_S15_17	((0<<16) | (15<<8) | (17))
#define FX_S16_16	((0<<16) | (16<<8) | (16))
#define FX_S17_15	((0<<16) | (17<<8) | (15))
#define FX_S18_14	((0<<16) | (18<<8) | (14))
#define FX_S19_13	((0<<16) | (19<<8) | (13))
#define FX_S20_12	((0<<16) | (20<<8) | (12))
// Fixed with signed short
#define FX_S04_11	((1<<16) | (4<<8) | (11)) 
#define FX_S05_10	((1<<16) | (5<<8) | (10))
#define FX_S06_09	((1<<16) | (6<<8) | (9))
#define FX_S07_08	((1<<16) | (7<<8) | (8))
#define FX_S08_07	((1<<16) | (8<<8) | (7))
#define FX_S09_06	((1<<16) | (9<<8) | (6))
#define FX_S10_05	((1<<16) | (10<<8) | (5))
#define FX_S11_04	((1<<16) | (11<<8) | (4))
// Fixed with unsigned short
#define FX_S05_11	((0<<16) | (5<<8) | (11)) 
#define FX_S06_10	((0<<16) | (6<<8) | (10))
#define FX_S07_09	((0<<16) | (7<<8) | (9))
#define FX_S08_08	((0<<16) | (8<<8) | (8))
#define FX_S09_07	((0<<16) | (9<<8) | (7))
#define FX_S10_06	((0<<16) | (10<<8) | (6))
#define FX_S11_05	((0<<16) | (11<<8) | (5))
#define FX_S12_04	((0<<16) | (12<<8) | (4))
// Fixed with signed char
#define FX_S00_07	((1<<16) | (0<<8) | (7)) 
#define FX_S01_06	((1<<16) | (1<<8) | (6))
#define FX_S02_05	((1<<16) | (2<<8) | (5))
#define FX_S03_04	((1<<16) | (3<<8) | (4))
#define FX_S04_03	((1<<16) | (4<<8) | (3))
#define FX_S05_02	((1<<16) | (5<<8) | (2))
#define FX_S06_01	((1<<16) | (6<<8) | (1))
// #define FX_S07_00	((1<<16) | (7<<8) | (0))	// It is same as unsigned char 
// Fixed with unsigned char
#define FX_S00_08	((0<<16) | (0<<8) | (8)) 
#define FX_S01_07	((0<<16) | (1<<8) | (7))
#define FX_S02_06	((0<<16) | (2<<8) | (6))
#define FX_S03_05	((0<<16) | (3<<8) | (5))
#define FX_S04_04	((0<<16) | (4<<8) | (4))
#define FX_S05_03	((0<<16) | (5<<8) | (3))
#define FX_S06_02	((0<<16) | (6<<8) | (2))
#define FX_S07_01	((0<<16) | (7<<8) | (1))
// Operation Preference 
#define	FX_OP_FLOAT		1
#define FX_OP_PRECISION 	2
#define FX_OP_FAIR		3
#define FX_OP_PERFORMANCE 	4
