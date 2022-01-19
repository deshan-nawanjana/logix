#define DATABASE_COUNT 3

#include "4000.h"
#include "7400.h"
#include "auto.h"

int db_index = 0;
int ic_index = 0;

DB DATABASE[DATABASE_COUNT] = {
    { "TTL", "7400", SERIES_7400, SERIES_7400_COUNT },
    { "CMOS", "4000", SERIES_4000, SERIES_4000_COUNT },
    { "AUTO", "????", SERIES_AUTO, 1 }
};