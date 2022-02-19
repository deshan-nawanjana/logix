void logicalTest(bool fast) {
    if(!fast) {
        // scan start screen
        displayText(
            " ~!@   MANUAL   ",
            " #$^  SCANNING  "
        );
        delay(300);
    }
    // turn on ic supply
    pinMode(IC_PIN_3V, OUTPUT);
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
        Serial.print("INPUT.SCAN_MANU ");
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
            delay(CHECK_DELAY);
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
        Serial.print("STATE.OUTS_MANU ");
        Serial.println(out_marks);
        // turn off ic supply
        digitalWrite(IC_PIN_3V, LOW);
        pinMode(IC_PIN_3V, INPUT);
        // display result
        displayPins(out_marks);
    } else { logicalTest(false); }
}

void logicalTestAll() {
    // scan start screen
    displayText(
        " ~!@    AUTO    ",
        " #$^  SCANNING  "
    );

    delay(300);

    int ic_match = -1;
    int db_match = -1;
    int mx_marks = 0;

    // turn on ic supply
    pinMode(IC_PIN_3V, OUTPUT);
    digitalWrite(IC_PIN_3V, HIGH);

    // define pins array for ic
    int IC_PINS[12] = {
        IC_PIN_01, IC_PIN_02, IC_PIN_03, IC_PIN_04, IC_PIN_05, IC_PIN_06,
        IC_PIN_08, IC_PIN_09, IC_PIN_10, IC_PIN_11, IC_PIN_12, IC_PIN_13
    };

    Serial.println("INPUT.SCAN_AUTO");

    // get type of auto mode
    int s; int e;
    if(ic_index == 0) {
        s = 0; e = 2; // full
    } else if(ic_index == 1) {
        s = 0; e = 1; // ttl
    } else {
        s = 1; e = 2; // cmos
    }

    // each database
    for(int d = s; d < e; d++) {
        // current database
        DB db = DATABASE[d];
        // each ic
        for(int c = 0; c < db.count; c++) {
            // current ic
            IC ic = db.list[c];
            // pin modes row
            String pins = toLogicRow(ic.table[0]);
            // set pin modes
            for(int i = 0; i < 12; i++) {
                if(pins[i] == '1') {
                    pinMode(IC_PINS[i], OUTPUT);
                } else {
                    pinMode(IC_PINS[i], INPUT);
                }
            }
            // display scanning animation
            updateRuns(toLogicRow(ic.table[2]), c, db.count);
            // create score string
            String out_marks = "AAAAAAAAAA";
            int out_count = 0;
            // count total rows
            int tot_count = 0;
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
                delay(5);
                // read voltage only for output pins
                for(int i = 0; i < 12; i++) {
                    if(pins[i] == '0') {
                        int a = line[i] == '1' && digitalRead(IC_PINS[i]) == HIGH;
                        int b = line[i] == '0' && digitalRead(IC_PINS[i]) == LOW;
                        if(a || b) { out_marks[out_count] += 1; }
                        out_count++;
                    }
                }
            }
            // check each output marks
            int marks = 0;
            char tot_mrk = 'A' + tot_count;
            for(int i = 0; i < 10; i++) {
                if(i < out_count) {
                    if(out_marks[i] == tot_mrk)  { marks++; }
                }
            }
            // calculate precentage
            marks = marks * 100 / out_count;
            // remember if larger
            if(marks > mx_marks) {
                db_match = d;
                ic_match = c;
                mx_marks = marks;
            }
        }
    }

    if(mx_marks > 0) {

        String p = String(mx_marks);
        String t = String(DATABASE[db_match].name);
        String c = String(DATABASE[db_match].list[ic_match].code);

        Serial.print("STATE.OUTS_AUTO ");
        Serial.print(t);
        Serial.print(" ");
        Serial.print(c);
        Serial.print(" ");
        Serial.print(p);
        Serial.println("%");

        String logo_1 = " ~!@ ";
        String line_1 = strlen(p) == 2
            ? strcat(logo_1, strcat(String(p), "% MATCH  "))
            : strcat(logo_1, strcat(String(p), "% MATCH "));

        String logo_2 = " #$^ ";
        String labels = strcat(strcat(t, " "), c);

        String line_2 = strlen(labels) == 8
            ? strcat(strcat(strcat(logo_2, " "), labels), "  ")
            : strcat(strcat(logo_2, labels), "   ");

        displayText(line_1, line_2);
    } else {
        displayText(
            " ~!@  NO MATCH  ",
            " #$^  FOUND     "
        );
        Serial.println("STATE.OUTS_AUTO NO_MATCH");
    }

    // turn off ic supply
    digitalWrite(IC_PIN_3V, LOW);
    pinMode(IC_PIN_3V, INPUT);

    // check user inputs
    int back = 0;
    while(back == 0) {
        for(int i = 0; i < 2; i++) {
            delay(50);
            // inspect user inputs
            for(int i = 0; i < 200; i += 20) {
                if(db_match != -1 && analogCheck(0)) {
                    // manual check
                    db_index = db_match;
                    ic_index = ic_match;
                    delay(50);
                    logicalTest(true);
                    back = 1; i = 200; return;
                }
                if(analogCheck(2)) {
                    // rescan all
                    delay(50);
                    logicalTestAll();
                    back = 1; i = 200; return;
                }
                if(analogCheck(3)) {
                    // back to menu
                    delay(50);
                    displayMenu();
                    back = 1; i = 200; return;
                }
            }
        }
    }
}