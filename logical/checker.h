

void logicalTest(bool fast) {
    // turn on ic supply
    digitalWrite(IC_PIN_3V, HIGH);
    // define pins array for ic
    int IC_PINS[12] = {
        IC_PIN_01, IC_PIN_02, IC_PIN_03, IC_PIN_04, IC_PIN_05, IC_PIN_06,
        IC_PIN_08, IC_PIN_09, IC_PIN_10, IC_PIN_11, IC_PIN_12, IC_PIN_13
    };
    // get ic data
    DB db = DATABASE[db_index];
    IC ic = DATABASE[db_index].list[ic_index];

    if(!fast) {
        // send scanning ic info
        Serial.print("INPUT.SCAN_RUNS ");
        Serial.print(db.name);
        Serial.print(" ");
        Serial.println(ic.code);
    }

    // pin modes row
    String pins = toLogicRow(ic.table[0]);

    if(!fast) {
        // send pin modes row
        Serial.print("STATE.SCAN_PINS ");
        Serial.println(pins);
    }

    // set pin modes
    for(int i = 0; i < 12; i++) {
        if(pins[i] == '1') {
            pinMode(IC_PINS[i], OUTPUT);
        } else {
            pinMode(IC_PINS[i], INPUT);
        }
    }

    delay(50);

    String out_marks = "AAAAAAAAAA";
    int out_count = 0;

    int tot_count = 0;
    // count total rows
    for(int i = 1; ic.table[i] != -1; i++) { tot_count++; }
    
    // each row loop
    for(int i = 1; ic.table[i] != -1; i++) {
        // reset output count per line
        out_count = 0;
        // current logic row
        String line = toLogicRow(ic.table[i]);
        // set voltage only for input pins
        for(int i = 0; i < 12; i++) {
            if(pins[i] == '1') {
                if(line[i] == '1') { digitalWrite(IC_PINS[i], HIGH); }
                if(line[i] == '0') { digitalWrite(IC_PINS[i], LOW); }
            }
        }
        
        if(!fast) {
            // display scanning animation
            updateRuns(line, i, tot_count);
        } else { delay(5); }

        // read voltage only for output pins
        for(int i = 0; i < 12; i++) {
            if(pins[i] == '0') {
                int a = line[i] == '1' && digitalRead(IC_PINS[i]) == HIGH;
                int b = line[i] == '0' && digitalRead(IC_PINS[i]) == LOW;
                if(a || b) { out_marks[out_count] += 1; }
                out_count++;
            }
        }

        if(!fast) {
            // send each score and state
            Serial.print("STATE.SCAN_LINE ");
            Serial.print(line);
            Serial.print(" ");
            Serial.print(out_marks);
            Serial.print(" ");
            Serial.print(i);
            Serial.print("/");
            Serial.println(tot_count);
        }
    }

    if(!fast) {
        // send score string
        Serial.print("STATE.SCAN_MARK ");
        Serial.print(out_marks);
        Serial.print(" ");
        // check each output marks
        char tot_mrk = 'A' + tot_count;
        for(int i = 0; i < 10; i++) {
            if(i < out_count) {
                if(out_marks[i] == tot_mrk) {
                    out_marks[i] = '1';
                } else { out_marks[i] = '0'; }
            } else { out_marks[i] = '\0'; }
        }
        // send final score
        Serial.println(tot_mrk);
        Serial.print("STATE.SCAN_OUTS ");
        Serial.println(out_marks);
        // turn off ic supply
        digitalWrite(IC_PIN_3V, LOW);
        // display result
        displayPins(out_marks);
    } else { logicalTest(false); }
}