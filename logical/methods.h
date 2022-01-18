String toLogicRow(int x) {
    String out = "000000000000";
    int n = 11;
    while(x > 0) {
        int d = x % 2;
        x = (x - d) / 2;
        out[n] = d + 48;
        n--;
    }
    return out;
}

String getPinsRow() {
    String out = "            ";
    int k = 0;
    for(int i = 0; i < 4; i++) {
        String part = String(DATABASE[db_index].list[ic_index].gates[i]);
        for(int n = 0; n < 3; n++) {
            out[k] = part[n];
            k++;
        }
    }
    return out;
}