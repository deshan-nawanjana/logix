int _PINS_[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14 };

void check_inputs(char **arr, int size) {

    // get array length
    size = size / 2;

    // pin strcture
    String pins = arr[0];

    int n = 0;
    // set pin modes
    for(int c = 0; c < 19; c++) {
        if(pins[c] == 'I') {
            // set input
            Serial.print("MODE I : "); Serial.println(_PINS_[n]);
            pinMode(_PINS_[n], INPUT);
        } else if(pins[c] == 'O') {
            // set output
            Serial.print("MODE O : "); Serial.println(_PINS_[n]);
            pinMode(_PINS_[n], OUTPUT);
        } else {
            // set output to ignore
            pinMode(_PINS_[n], OUTPUT);
        }
        // next pin index
        if(pins[c] != ' ') { n++; }
    }

}