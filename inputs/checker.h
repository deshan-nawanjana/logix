int INPUT_CMDS[4] = { 0, 0, 0, 0 };
int INPUT_PINS[4] = {
    INPUT_PIN_TYPE,
    INPUT_PIN_SCAN,
    INPUT_PIN_LAST,
    INPUT_PIN_NEXT
};

bool analogCheck(int n) {
    int pin = INPUT_PINS[n];
    // four rounds check
    int chk = 1;
    for(int i = 0; i < 4; i++) {
        chk = chk && analogRead(pin) < 400;
        delay(5);
    }
    // ignore press down state
    if(chk && INPUT_CMDS[n] == 1) { return 0; }
    if(chk && INPUT_CMDS[n] == 0) {
        // button down press
        INPUT_CMDS[n] = 1;
        return 1;
    } else {
        // button up reset
        INPUT_CMDS[n] = 0;
        return 0;
    }
}

void inputsCheck() {
    if(analogCheck(0)) { lastIC(); }
    if(analogCheck(1)) { nextIC(); }
    if(analogCheck(2)) { nextDB(); }
    if(analogCheck(3)) { logicalTest(true); }
}