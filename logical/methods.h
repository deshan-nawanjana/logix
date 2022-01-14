IC logicalFind(int type, int indx) {
    if(type == 0) {
        return SERIES_4000[indx];
    } else {
        return SERIES_7400[indx];
    }
}