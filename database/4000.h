#define SERIES_4000_COUNT 12

int T_4000[] = { 3483, 612, 1773, 2934, 3483, -1 };
int T_4002[] = { 1782, 2313, 594, 1188, 1782, -1 };
int T_4008[] = { 3483, 0, 1161, 2322, 4095, -1 };
int T_4010[] = { 3997, 98, 231, 1386, 1519, 2674, 2807, 3962, 3997, -1 };
int T_4011[] = { 3997, 0, 133, 1288, 1421, 2576, 2709, 3864, 4095, -1 };
int T_4020[] = { 3999, 96, 225, 354, 483, 1128, 1257, 1386, 1515, 2160, 2289, 2418, 2547, 3192, 3321, 3450, 3483, -1 };
int T_4021[] = { 3999, 0, 129, 258, 387, 1032, 1161, 1290, 1419, 2064, 2193, 2322, 2451, 3096, 3225, 3354, 3579, -1 };
int T_4027[] = { 3997, 98, 133, 1288, 1421, 2576, 2709, 3864, 3997, -1 };
int T_4032[] = { 3483, 0, 1773, 2934, 4095, -1 };
int T_4086[] = { 3483, 0, 1773, 2934, 3483, -1 };
int T_404075[] = { 4007, 0, 249, 1370, 1531, 2652, 2813, 3934, 4095, -1 };
int T_407266[] = { 3315, 780, 1105, 2210, 4095, -1 };

int I_4000[] = { 0, 265, 0, 2650, 2, 6500, 26, 5000 };
int I_4002[] = { 0, 275, 0, 2750, 2, 7500, 27, 5000 };
int I_4008[] = { 0, 261, 0, 2610, 2, 6100, 26, 1000 };
int I_4010[] = { 0, 3650, 0, 3650, 0, 0, 3650, 0 };
int I_4011[] = { 0, 3610, 0, 3610, 0, 0, 3610, 0 };
int I_4020[] = { 0, 0, 4, 6500, 0, 0, 4, 6500 };
int I_4021[] = { 0, 0, 4, 6100, 0, 0, 4, 6100 };
int I_4027[] = { 0, 3750, 0, 3750, 0, 0, 3750, 0 };
int I_4032[] = { 0, 271, 0, 2710, 2, 7100, 27, 1000 };
int I_4086[] = { 0, 291, 0, 2910, 2, 9100, 29, 1000 };
int I_404075[] = { 0, 3, 7100, 3710, 0, 0, 3710, 0 };
int I_407266[] = { 0, 295, 0, 2950, 2, 9500, 29, 5000 };

int G_4000[] = { 222, 333, 444, 555 };
int G_4002[] = { 222, 333, 444, 555 };
int G_4008[] = { 222, 333, 444, 555 };
int G_4010[] = { 223, 333, 333, 322 };
int G_4011[] = { 223, 333, 333, 322 };
int G_4020[] = { 221, 222, 333, 133 };
int G_4021[] = { 221, 222, 333, 133 };
int G_4027[] = { 223, 333, 333, 322 };
int G_4032[] = { 222, 333, 444, 555 };
int G_4086[] = { 222, 333, 444, 555 };
int G_404075[] = { 223, 333, 224, 444 };
int G_407266[] = { 222, 333, 444, 555 };

IC SERIES_4000[] = {
	{ "4000", I_4000, T_4000, G_4000 },
	{ "4002", I_4002, T_4002, G_4002 },
	{ "4008", I_4008, T_4008, G_4008 },
	{ "4010", I_4010, T_4010, G_4010 },
	{ "4011", I_4011, T_4011, G_4011 },
	{ "4020", I_4020, T_4020, G_4020 },
	{ "4021", I_4021, T_4021, G_4021 },
	{ "4027", I_4027, T_4027, G_4027 },
	{ "4032", I_4032, T_4032, G_4032 },
	{ "4086", I_4086, T_4086, G_4086 },
	{ "404075", I_404075, T_404075, G_404075 },
	{ "407266", I_407266, T_407266, G_407266 }
};