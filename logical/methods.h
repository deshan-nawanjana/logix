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