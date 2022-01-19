// common modules
int strlen(String str) {
    int len = 0;
    while(str[len] != '\0') { len++; }
    return len;
}

String strcat(String str_1, String str_2) {
    int len_1 = strlen(str_1);
    int len_2 = strlen(str_2);
    char out[len_1 + len_2] = "";
    for(int i = 0; i < len_1; i++) { out[i] = str_1[i]; }
    for(int i = 0; i < len_2; i++) { out[i + len_1] = str_2[i]; }
    out[len_1 + len_2] = '\0';
    return out;
}

// display modules
extern void updateMenu();
extern void updateRuns(String line, int crr, int tot);

// display methods
extern void displayInit();
extern void displayText(String line_1, String line_2);
extern void displaySymb(String arr);
extern void displayOuts(String marks);
extern void displayPins(String marks);
extern void displayBackMenu(String image_1, String image_2, String marks, int page);

// logical modules
extern String toLogicRow(int x);
extern String getPinsRow();

// logical methods
extern void logicalTest(bool fast);
extern void logicalTestAll();

// inputs modules
extern bool analogCheck(int n);
extern void inputsCheck();

// inputs methods
extern void displayHome();
extern void displayMenu();
extern void lastDB();
extern void nextDB();
extern void lastIC();
extern void nextIC();
extern void sendCP(String type, String code);