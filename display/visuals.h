int state = 0;
// 0 = home
// 1 = menu
// 2 = scan
// 3 = ends

int ic_type = 0; // 0 = TTL, 1 = CMOS
int ic_indx = 0;

void updateMenu() {
    // generate line_2
    String code = logicalFind(ic_type, ic_indx).code;
    String line_2 = " CODE  < XXXX > ";
    for(int i = 0; i < 4; i++) {
       line_2[i + 9] = code[i];
    }
    Serial.println(line_2);
    // select line_1
    if(ic_type == 0) {
        displayText(
            " TYPE  <  TTL > ",
            line_2
        );
    } else {
        displayText(
            " TYPE  < CMOS > ",
            line_2
        );
    }
}

void displayMenu() {
    ic_type = 0;
    ic_indx = 0;
    updateMenu();
}

void toggleType() {
    ic_type = 1 - ic_type;
    ic_indx = 0;
    updateMenu();
}

void nextCode() {

}

void lastCode() {

}