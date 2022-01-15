// initialize display
void displayInit() {
    // start serial port
    Serial.begin(BAUD_RATE);
    // init display
    display.begin(16, 2);
    // init symbols
    for(int i = 0; i < SYMBOLS_COUNT; i++) {
        display.createChar(i, SYMBOLS[i].data);
    }
}

// write text on display
void displayText(String line_1, String line_2 = "") {
    int end_1 = 0;
    int end_2 = 0;
    for(int i = 0; i < 32; i++) {
        if(i < 16) {
            // print line 1
            char k = line_1[i];
            if(k == '\0') { end_1 = 1; }
            if(end_1) { k = ' '; }
            display.setCursor(i, 0);
            display.print(k);
        } else {
            // print line 2
            char k = line_2[i - 16];
            if(k == '\0') { end_2 = 1; }
            if(end_2) { k = ' '; }
            display.setCursor(i - 16, 1);
            display.print(k);
        }
    }
}

// write symbols on display
void displaySymb(String arr) {
    for(int i = 0; i < 32; i++) {
        // toggle cursor for each line
        if(i < 16) { display.setCursor(i, 0); }
        if(i > 15) { display.setCursor(i - 16, 1); }
        if( i != 16) {
            int k = searchSymb(arr[i]);
            if(k != -1) {
                // in symbols
                display.write(byte(k));
            } else {
                // manual chars
                if(arr[i] == '0') { display.print(" "); }
                if(arr[i] == '1') { display.print("-"); }
                if(arr[i] == '2') { display.print("="); }
            }
        } else {
            // ic dot
            display.write(byte(7));
        }
    }
}

void displayOuts(String marks) {

    Serial.print("INPUT.SCAN_OUTS ");
    Serial.println(marks);

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
    for(int i = 17; i < 32; i++) {
        if(image_2[i] == '0' && image_2[i + 1] != '0') { n++; }
        if(image_2[i] != '0' && marks[n] == '0') { image_2[i] = '#'; }
    }
    // first line right to left
    for(int i = 14; i > 0; i--) {
        if(image_2[i - 1] != '0' && image_2[i] == '0') { n++; }
        if(image_2[i] != '0' && marks[n] == '0') { image_2[i] = '#'; }
    }
    // make space
    for(int i = 0; i < 32; i++) { if(image_2[i] == '#') { image_2[i] = '0'; } }

    Serial.print("PRINT.GATE_MAPS ");
    Serial.print(image_1);
    Serial.print(" ");
    Serial.println(image_2);

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


