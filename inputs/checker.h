bool analogCheck(int n) {
    if(n == 0) {
        return !(digitalRead(INPUT_PIN_LAST));
    } else if (n == 1) {
        return !(digitalRead(INPUT_PIN_NEXT));
    } else if (n == 2) {
        return !(digitalRead(INPUT_PIN_TYPE));
    } else if (n == 3) {
        return !(digitalRead(INPUT_PIN_SCAN));
    }
}

void inputsCheck() {
    if(analogCheck(0)) {
        lastIC();
    }
    if(analogCheck(1)) {
        nextIC();
    }
    if(analogCheck(2)) { nextDB(); }
    if(analogCheck(3)) {
        if(DATABASE[db_index].name == "AUTO") {
            logicalTestAll();
        } else {
            logicalTest(true);
        }
    }
}