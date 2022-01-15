#define SERIES_7400_COUNT 12

int T_7400[] = { 3483, 612, 1773, 2934, 3483, -1 };
int T_7402[] = { 1782, 2313, 594, 1188, 1782, -1 };
int T_7408[] = { 3483, 0, 1161, 2322, 4095, -1 };
int T_7410[] = { 3997, 98, 231, 1386, 1519, 2674, 2807, 3962, 3997, -1 };
int T_7411[] = { 3997, 0, 133, 1288, 1421, 2576, 2709, 3864, 4095, -1 };
int T_7420[] = { 3999, 612, 741, 870, 999, 1644, 1773, 1902, 2031, 2676, 2805, 2934, 3063, 3708, 3837, 3966, 3999, -1 };
int T_7421[] = { 3999, 516, 645, 774, 903, 1548, 1677, 1806, 1935, 2580, 2709, 2838, 2967, 3612, 3741, 3870, 4095, -1 };
int T_7427[] = { 3997, 98, 133, 1288, 1421, 2576, 2709, 3864, 3997, -1 };
int T_7432[] = { 3483, 0, 1773, 2934, 4095, -1 };
int T_7486[] = { 3483, 0, 1773, 2934, 3483, -1 };
int T_744075[] = { 4007, 0, 249, 1370, 1531, 2652, 2813, 3934, 4095, -1 };
int T_747266[] = { 3315, 780, 1105, 2210, 4095, -1 };

int I_7400[] = { 0, 265, 0, 2650, 2, 6500, 26, 5000 };
int I_7402[] = { 0, 275, 0, 2750, 2, 7500, 27, 5000 };
int I_7408[] = { 0, 261, 0, 2610, 2, 6100, 26, 1000 };
int I_7410[] = { 0, 3650, 0, 3650, 0, 0, 3650, 0 };
int I_7411[] = { 0, 3610, 0, 3610, 0, 0, 3610, 0 };
int I_7420[] = { 0, 0, 4, 6500, 0, 0, 4, 6500 };
int I_7421[] = { 0, 0, 4, 6100, 0, 0, 4, 6100 };
int I_7427[] = { 0, 3750, 0, 3750, 0, 0, 3750, 0 };
int I_7432[] = { 0, 271, 0, 2710, 2, 7100, 27, 1000 };
int I_7486[] = { 0, 291, 0, 2910, 2, 9100, 29, 1000 };
int I_744075[] = { 0, 3, 7100, 3710, 0, 0, 3710, 0 };
int I_747266[] = { 0, 295, 0, 2950, 2, 9500, 29, 5000 };

IC SERIES_7400[] = {
	{ "7400", I_7400, T_7400 },
	{ "7402", I_7402, T_7402 },
	{ "7408", I_7408, T_7408 },
	{ "7410", I_7410, T_7410 },
	{ "7411", I_7411, T_7411 },
	{ "7420", I_7420, T_7420 },
	{ "7421", I_7421, T_7421 },
	{ "7427", I_7427, T_7427 },
	{ "7432", I_7432, T_7432 },
	{ "7486", I_7486, T_7486 },
	{ "744075", I_744075, T_744075 },
	{ "747266", I_747266, T_747266 }
};