int _PINS_[14] = { 2, 3, 4, 5, 6, 7, -1, 8, 9, 10, 11, 12, 13, -1 };

void set_pin_mode(char c, int n) {
    if(c == 'I') {
        Serial.print("MODE : I "); Serial.println(_PINS_[n]);
        pinMode(_PINS_[n], INPUT);
    } else if(c == 'O') {
        Serial.print("MODE : O "); Serial.println(_PINS_[n]);
        pinMode(_PINS_[n], OUTPUT);
    } else {
        pinMode(_PINS_[n], OUTPUT);
    }
}

void set_vol_mode(char c, int n) {
    if(c == '1') {
        Serial.print("VOLT : H "); Serial.println(_PINS_[n]);
        digitalWrite(_PINS_[n], HIGH);
    }
    if(c == '0') {
        Serial.print("VOLT : L "); Serial.println(_PINS_[n]);
        digitalWrite(_PINS_[n], LOW);
    }
}

int chk_vol_read(char c, int n) {
    Serial.print("CHCK : PIN "); Serial.print(_PINS_[n]);
    Serial.print(" IS "); Serial.print(c);
    if(c == '1' && digitalRead(_PINS_[n]) == HIGH) {
        Serial.println(" ? : YES");
        return 1;
    } else if(c == '0' && digitalRead(_PINS_[n]) == LOW) {
        Serial.println(" ? : YES");
        return 1;
    } else {
        Serial.println(" ? : NO");
        return 0;
    }
}

int char_to_int(char k) {
    // init output index
    if(k == '*') { return 0; }
    if(k < 65) {
        // 0 to 9
        return k - 48;
    } else {
        // A to Z
        return k - 55;
    }
}

char int_to_char(int k) {
    if(k < 10) {
        // 0 to 9
        return k + 48;
    } else {
        // A to Z
        return k + 55;
    }
}

void check_inputs(String *arr) {

    Serial.println("==== IC BEG ====");

    // pin strcture
    String pins = arr[0];

    // set pin modes for each char unil find 'X'
    int i = 0; // pin index
    for(int c = 0; pins[c] != 'X'; c++) {
        set_pin_mode(pins[c], i);
        // next pin index
        if(pins[c] != ' ') { i++; }
    }

    // output string
    String output = "**********";
    int end = 0; // end checker
    int tot = 0;
    // each line until end is 0
    for(int n = 1; end == 0; n++) {
        tot++;
        Serial.println("==== IC LNE ====");
        // current line
        String line = arr[n];
        
        int c = 0; // chr index
        int i = 0; // pin index
        
        i = 0;
        // set voltage low or high if an input pin
        for(c = 0; line[c] != 'X' && line[c] != 'Z'; c++) {
            if(pins[c] == 'I') { set_vol_mode(line[c], i); }
            // next pin index
            if(pins[c] != ' ') { i++; }
        }

        delay(200);

        int t = 0; // out index

        i = 0;
        // check voltage low or high if an output pin
        for(c = 0; line[c] != 'X' && line[c] != 'Z'; c++) {
            if(pins[c] == 'O') {
                // get true = 1 or false = 0
                int out = chk_vol_read(line[c], i);
                // get old output index value
                int old = char_to_int(output[t]);
                // increase and store output index value back
                output[t] = int_to_char(old + out);
                t++;
            }
            // next pin index
            if(pins[c] != ' ') { i++; }
        }

        Serial.print("OUTS : "); Serial.println(output);

        // check next char to end
        if(line[c] == 'Z') {
            Serial.println("==== IC END ====");
            end = 1;
        }
    }

    Serial.print("OUTPUT SATES = ");
    Serial.println(output);

    // check increasement count with line count
    for(int c = 0; c < 10; c++) {
        if(output[c] == '*') {
            output[c] = 'Z';
        } else {
            if(char_to_int(output[c]) == tot) {
                output[c] = '1';
            } else {
                output[c] = '0';
            }
        }
    }

    Serial.print("TOTAL LINES  = ");
    Serial.print(tot);
    Serial.print(" (");
    Serial.print(int_to_char(tot));
    Serial.println(")");

    Serial.print("FINAL RESULT = ");
    Serial.println(output);

}