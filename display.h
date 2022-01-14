#include <LiquidCrystal.h>
LiquidCrystal lcd(LCD_PIN_0, 44, 46, 48, 50, 52);

void display_lines(String chars) {
    for(int i = 0; i < 16; i++) {
        lcd.setCursor(i, 0);
        lcd.print(chars[i]);
    }
    for(int i = 16; i < 32; i++) {
        lcd.setCursor(i - 16, 1);
        lcd.print(chars[i]);
    }
}

void display_begin() {
    //lcd.createChar(0, smiley);

    lcd.begin(16, 2);
    display_lines("   ALL IN ONE      IC CHECKER   ");

    //lcd.setCursor(0, 0);

    //lcd.write(byte(0));


}

// name   > IC Number
// status > 1 =  
void display_state(String name, int status, int ongoing, int total) {
    if(status == 1) {
        display_lines("   ALL IN ONE      IC CHECKER   ");
    }
}

void display_gates(String *gates, String output) {
    // format for add gate errors
    String text_1 = "                                ";
    // second line forward
    for(int i = 0; i < 16; i++) { text_1[i] = gates[1][i]; }
    // first line backword
    for(int i = 15; i > -1; i--) { text_1[31 - i] = gates[0][i]; }
    // check with output
    int n = -1;
    for(int i = 1; i < 32; i++) {
        // increase gate id when name starts
        if(text_1[i - 1] == ' ' && text_1[i] != ' ') { n++; }
        // add dashes for broken gates
        if(text_1[i] != ' ' && output[n] == '0') { text_1[i] = '-'; }
    }
    // format for display
    String text_2 = "                                ";
    // front to middle
    for(int i = 0; i < 16; i++) { text_2[16 + i] = text_1[i]; }
    // back to middle
    for(int i = 31; i > 16; i--) { text_2[31 - i] = text_1[i]; }
    
    display_lines(text_2);
}