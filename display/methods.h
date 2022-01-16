// initialize display
void displayInit() {
    // start serial port
    Serial.begin(BAUD_RATE);
    // init display
    display.begin(16, 2);
}

// write text on display
void displayText(String line_1, String line_2 = "") {
    String text = strcat(line_1, line_2);
    // pre register all symbols
    regAllSymbols(TEXT_SYMBOLS, TEXT_SYMBOLS_LENGTH, text);
    // print display
    for(int i = 0; i < 32; i++) {
        // get current x and y
        int x = i < 16 ? i : i - 16;
        int y = i < 16 ? 0 : 1;
        // print each char
        setSymbol(TEXT_SYMBOLS, TEXT_SYMBOLS_LENGTH, text[i], x, y);
    }
}

// write symbols on display
void displaySymb(String text) {
    // pre register all symbols
    regAllSymbols(GATE_SYMBOLS, GATE_SYMBOLS_LENGTH, text);
    // print display
    for(int i = 0; i < 32; i++) {
        // get current x and y
        int x = i < 16 ? i : i - 16;
        int y = i < 16 ? 0 : 1;
        // print each char
        display.setCursor(x, y);
        if(text[i] == '0') { display.print(' '); }
        else if(text[i] == '1') { display.print('-'); }
        else if(text[i] == '2') { display.print('='); }
        else {
            setSymbol(GATE_SYMBOLS, GATE_SYMBOLS_LENGTH, text[i], x, y);
        }
    }
}

void displayOuts(String marks) {

    // extract image
    String image_1 = "00000000000000000000000000000000";
    int k = 0;
    for(int i = 0; i < 8; i++) {
        String val = String(DATABASE[db_index].list[ic_index].image[i]);
        int len = strlen(val);
        for(k = 0; k < len; k++) {
            image_1[(i * 4) + k + (4 - len)] = val[k];
        }
    }
    // duplicate image
    String image_2 = "00000000000000000000000000000000";
    for(int i = 0; i < 32; i++) { image_2[i] = image_1[i]; }
    // find broken ics
    int n = -1;
    // second line left to right
    for(int i = 17; i < 31; i++) {
        if(image_2[i] == '0' && image_2[i + 1] != '0') { n++; }
        if(image_2[i] != '0' && marks[n] == '0') { image_2[i] = '#'; }
    }
    // first line right to left
    for(int i = 15; i > 1; i--) {
        if(image_2[i] == '0' && image_2[i - 1] != '0') { n++; }
        if(image_2[i] != '0' && marks[n] == '0') { image_2[i] = '#'; }
    }
    // make space
    for(int i = 0; i < 32; i++) { if(image_2[i] == '#') { image_2[i] = '0'; } }

    Serial.print("PRINT.GATE_MAPS ");
    Serial.print(image_1);
    Serial.print(" ");
    Serial.println(image_2);

    image_1[16] = '*';
    image_2[16] = '*';

    // image blink animation
    int back = 0;
    while(back == 0) {
        displaySymb(image_1);
        for(int i = 0; i < 400; i += 20) {
            if(analogCheck(1)) {
                Serial.println("INPUT.SCAN_ENDS");
                displayMenu(); back = 1; i = 400; return;
            }
            if(analogCheck(0)) {
                Serial.println("INPUT.SCAN_BACK");
                logicalTest(); back = 1; i = 400; return;
            }
        }
        displaySymb(image_2);
        for(int i = 0; i < 200; i += 20) {
            if(analogCheck(1)) {
                Serial.println("INPUT.SCAN_ENDS");
                displayMenu(); back = 1; i = 200; return;
            }
            if(analogCheck(0)) {
                Serial.println("INPUT.SCAN_BACK");
                logicalTest(); back = 1; i = 200; return;
            }
        }
    }
}