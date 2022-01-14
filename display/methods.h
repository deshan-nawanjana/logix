#include <LiquidCrystal.h>

LiquidCrystal display(
    LCD_PIN_0,
    LCD_PIN_1,
    LCD_PIN_2,
    LCD_PIN_3,
    LCD_PIN_4,
    LCD_PIN_5
);

// initialize display
void displayInit() {
    // init display
    display.begin(16, 2);
    // init symbols
    for(int i = 0; i < SYMBOLS_COUNT; i++) {
        display.createChar(i, SYMBOLS[i].data);
    }
}

// write text on display
void displayText(String line_1, String line_2) {
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

int searchSymb(char code) {
    int n = -1;
    for(int i = 0; i < SYMBOLS_COUNT; i++) {
        if(SYMBOLS[i].code == code) {
            n = i;
            Serial.print("FOUND SYMB : ");
            Serial.println(SYMBOLS[i].code);
        }
    }
    return n;
}

// write symbols on display
void displaySymb(String line_1, String line_2) {
    for(int i = 0; i < 32; i++) {
        if(i < 16) {
            // print line 1
            display.setCursor(i, 0);
            int k = searchSymb(line_1[i]);
            if(k != -1) { display.write(byte(k)); }
            else { display.print(line_1[i]); }
        } else {
            // print line 2
            display.setCursor(i - 16, 1);
            int k = searchSymb(line_2[i - 16]);
            if(k != -1) { display.write(byte(k)); }
            else { display.print(line_2[i - 16]); }
        }
    }
}

// clear display
void displayWipe() {
    displayText(
        "                ",
        "                "
    );
}