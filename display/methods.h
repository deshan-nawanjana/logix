// initialize display
void displayInit() {
    // start serial port
    Serial.begin(BAUD_RATE);
    // init display
    display.begin(16, 2);
    // ic supply pin mode
    pinMode(IC_PIN_3V, OUTPUT);
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

    image_1[16] = '*';
    image_2[16] = '*';

    displayText(
        "                ",
        "                "
    );

    displayBackMenu(image_1, image_2, marks, 1);
}

void displayPins(String marks) {
    String image_1 = "0000000GTTTTTTTH0000000IBBBBBBBJ";
    String image_2 = "0FULLY0GTTTTTTTH0WORKS0IBBBBBBBJ";

    String pins = getPinsRow();

    int ok = 1;
    for(int i = 0; i < strlen(marks); i++) {
        if(marks[i] == '0') { ok = 0; }
    }

    if(ok == 0) {
        image_2[1] = 'F';
        image_2[2] = 'O';
        image_2[3] = 'U';
        image_2[4] = 'N';
        image_2[5] = 'D';

        image_2[17] = 'E';
        image_2[18] = 'R';
        image_2[19] = 'R';
        image_2[20] = 'O';
        image_2[21] = 'R';
        image_2[22] = 'S';
    }

    for(int i = 0; i < 12; i++) {
        int m = pins[i] - 50;
        if(i < 6) {
            // bottom line
            char c = m == -1 ? 'B' : marks[m] == '1' ? 'B' : 'Z';
            image_2[i + 24] = c;
        } else {
            // top line
            char c = m == -1 ? 'T' : marks[m] == '1' ? 'T' : 'X';
            image_2[14 - (i - 6)] = c;
        }
    }

    displayBackMenu(image_2, image_1, marks, 2);
}

void displayBackMenu(String image_1, String image_2, String marks, int page) {
    // display final result
    int back = 0;
    while(back == 0) {
        for(int i = 0; i < 2; i++) {
            // animate images
            if(i == 0) {
                displaySymb(image_1);
            } else { displaySymb(image_2); }
            delay(50);
            // inspect user inputs
            for(int i = 0; i < 200; i += 20) {
                if(page == 2 && analogCheck(0)) {
                    // display pins
                    delay(50);
                    displayOuts(marks); back = 1; i = 200; return;
                }
                if(page == 1 && analogCheck(1)) {
                    // display outs
                    delay(50);
                    displayPins(marks); back = 1; i = 200; return;
                }
                if(analogCheck(3)) {
                    // back to menu
                    delay(50);
                    displayMenu(); back = 1; i = 200; return;
                }
                if(analogCheck(2)) {
                    // rescan
                    delay(50);
                    logicalTest(true); back = 1; i = 200; return;
                }
            }
        }
    }
}