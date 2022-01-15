// common modules
int strlen(String str) {
    int len = 0;
    while(str[len] != '\0') { len++; }
    return len;
}

// display modules
extern void updateMenu();
extern void updateRuns(String line, int crr, int tot);

// display methods
extern void displayInit();
extern void displayText(String line_1, String line_2);
extern void displaySymb(String arr);
extern void displayOuts(String marks);

// logical modules
extern String toLogicRow(int x);

// logical methods
extern void logicalTest();

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