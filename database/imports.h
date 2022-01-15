#define DATABASE_COUNT 2

#include "4000.h"
#include "7400.h"

int ic_index = 0;
int db_index = 0;

DB DATABASE[DATABASE_COUNT] = {
    { "CMOS", "4000", SERIES_4000, 12 },
    { "TTL", "7400", SERIES_7400, 12 }
};