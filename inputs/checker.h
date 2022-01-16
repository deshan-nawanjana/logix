int INPUT_CMDS[4] = { 0, 0, 0, 0 };
int INPUT_PINS[4] = {
    INPUT_PIN_0,
    INPUT_PIN_1,
    INPUT_PIN_2,
    INPUT_PIN_3
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
    if(analogCheck(0)) { nextDB(); }
    if(analogCheck(2)) { lastIC(); }
    if(analogCheck(3)) { nextIC(); }
    if(analogCheck(1)) { logicalTest(); }
}