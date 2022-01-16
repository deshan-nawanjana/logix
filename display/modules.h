#include <LiquidCrystal.h>

LiquidCrystal display(
    LCD_PIN_0,
    LCD_PIN_1,
    LCD_PIN_2,
    LCD_PIN_3,
    LCD_PIN_4,
    LCD_PIN_5
);

void updateMenu() {
    String line_1 = " TYPE  <  XXX > ";
    String line_2 = " CODE  < XXXX > ";

    String name = DATABASE[db_index].name;
    String code = DATABASE[db_index].list[ic_index].code;

    int n_len = strlen(name);
    int c_len = strlen(code);

    // add ic type to line 1
    int n_idx = n_len == 4 ? 9 : 10;
    for(int i = 0; i < n_len; i++) {
       line_1[i + n_idx] = name[i];
    }

    // add ic code to line 1
    int c_idx = c_len == 4 ? 9 : 8;
    for(int i = 0; i < c_len; i++) {
       line_2[i + c_idx] = code[i];
    }

    displayText(line_1, line_2);
}

void updateRuns(String line, int crr, int tot) {
    // generate animation wave
    int n = 0;
    String wave = "  ____________  ";
    for(int i = 0; i < 16; i++) {
        if(wave[i] == '_') {
            if(line[n] == '1') { wave[i] = '='; }
            if(line[n] == '0') { wave[i] = '_'; }
            n++;
        }
    }
    // generate scanning text
    String text = "SCANNING...    %";
    String preg = String(crr * 100 / tot);
    int len = strlen(preg);
    for(int i = 14; i > 14 - len; i--) {
        text[i] = preg[len - (14 - i) - 1];
    }
    // display and delay
    displayText(text, wave);
    delay(CHECK_DELAY);
}