int INPUT_CMDS[4] = { 0, 0, 0, 0 };
int INPUT_PINS[4] = {
    INPUT_PIN_TYPE,
    INPUT_PIN_SCAN,
    INPUT_PIN_LAST,
    INPUT_PIN_NEXT
};

bool analogCheck(int n) {
    int pin = INPUT_PINS[n];
    int check_1 = analogRead(INPUT_PINS[n]) > 800;
    delay(5);
    int check_2 = analogRead(INPUT_PINS[n]) > 800;
    delay(5);
    int check_3 = analogRead(INPUT_PINS[n]) > 800;
    delay(5);
    int check_4 = analogRead(INPUT_PINS[n]) > 800;

    // ignore press down state
    if(check_1 && check_2 && check_3 && check_4 && INPUT_CMDS[n] == 1) {
        return 0;
    }
    // button down press
    if(check_1 && check_2 && check_3 && check_4 && INPUT_CMDS[n] == 0) {
        INPUT_CMDS[n] = 1;
        return 1;
    }
    // button up reset
    if(!check_1 || !check_2 || !check_3 || !check_4) {
        INPUT_CMDS[n] = 0;
        return 0;
    }
}

void inputsCheck() {
    if(analogCheck(0)) { lastIC(); }
    if(analogCheck(1)) { nextIC(); }
    if(analogCheck(2)) { nextDB(); }
    if(analogCheck(3)) { logicalTest(); }
}