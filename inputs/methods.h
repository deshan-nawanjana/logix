// display home screen and jump to menu
void displayHome() {
    Serial.println("STATE.HOME_TEXT");
    displayText(
        " ~!@    LOGIX   ",
        " #$^  IC TESTER "
    );
    delay(3000);
    displayMenu();
}

void displayMenu() {
    updateMenu();
    sendCP("STATE", "MAIN_MENU");
}

void lastDB() {
    ic_index = 0;
    if(db_index == 0) {
        db_index = DATABASE_COUNT - 1;
    } else { db_index--; }
    updateMenu();
    sendCP("INPUT", "LAST_TYPE");
}

void nextDB() {
    ic_index = 0;
    if(db_index == DATABASE_COUNT - 1) {
        db_index = 0;
    } else { db_index++; }
    updateMenu();
    sendCP("INPUT", "NEXT_TYPE");
}

void lastIC() {
    if(ic_index == 0) {
        ic_index = DATABASE[db_index].count - 1;
    } else { ic_index--; }
    updateMenu();
    sendCP("INPUT", "LAST_CODE");
}

void nextIC() {
    if(ic_index == DATABASE[db_index].count - 1) {
        ic_index = 0;
    } else { ic_index++; }
    updateMenu();
    sendCP("INPUT", "NEXT_CODE");
}

void sendCP(String type, String code) {
    Serial.print(type);
    Serial.print(".");
    Serial.print(code);
    Serial.print(" ");
    Serial.print(DATABASE[db_index].name);
    Serial.print(" ");
    Serial.println(DATABASE[db_index].list[ic_index].code);
}