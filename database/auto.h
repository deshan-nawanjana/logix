#define SERIES_AUTO_COUNT 3

int T_AUTO_TTL[] = { 0 };
int I_AUTO_TTL[] = { 0 };
int G_AUTO_TTL[] = { 0 };

int T_AUTO_CMOS[] = { 0 };
int I_AUTO_CMOS[] = { 0 };
int G_AUTO_CMOS[] = { 0 };

int T_AUTO_FULL[] = { 0 };
int I_AUTO_FULL[] = { 0 };
int G_AUTO_FULL[] = { 0 };

IC SERIES_AUTO[] = {
	{ "FULL", T_AUTO_FULL, I_AUTO_FULL, G_AUTO_FULL },
	{ "TTL ", T_AUTO_TTL, I_AUTO_TTL, G_AUTO_TTL },
	{ "CMOS", T_AUTO_CMOS, I_AUTO_CMOS, G_AUTO_CMOS }
};