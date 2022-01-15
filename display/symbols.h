#define SYMBOLS_COUNT 8

byte SYMBOL_AND[] = {
  B11100,
  B10010,
  B10001,
  B10001,
  B10001,
  B10010,
  B11100,
  B00000
};

byte SYMBOL_OR[] = {
  B11000,
  B10100,
  B01010,
  B01001,
  B01010,
  B10100,
  B11000,
  B00000
};

byte SYMBOL_NOT[] = {
  B11000,
  B10100,
  B10010,
  B10001,
  B10010,
  B10100,
  B11000,
  B00000
};

byte SYMBOL_XOR[] = {
  B10100,
  B10110,
  B10101,
  B01011,
  B10101,
  B10110,
  B10100,
  B00000
};

byte SYMBOL_LINE_NOT[] = {
  B00000,
  B00000,
  B01000,
  B10111,
  B01000,
  B00000,
  B00000,
  B00000
};

byte SYMBOL_LINE_3[] = {
  B00000,
  B11111,
  B00000,
  B11111,
  B00000,
  B11111,
  B00000,
  B00000
};

byte SYMBOL_LINE_4[] = {
  B11111,
  B00000,
  B11111,
  B00000,
  B11111,
  B00000,
  B11111,
  B00000
};

byte SYMBOL_DOT[] = {
  B00000,
  B00000,
  B00000,
  B00000,
  B01100,
  B10010,
  B10010,
  B01100
};

struct SYMB {
    int code;
    byte *data;
};

SYMB SYMBOLS[] = {
    { 3, SYMBOL_LINE_3 },
    { 4, SYMBOL_LINE_4 },
    { 5, SYMBOL_LINE_NOT },
    { 6, SYMBOL_AND },
    { 7, SYMBOL_OR },
    { 8, SYMBOL_NOT },
    { 9, SYMBOL_XOR },
    { 10, SYMBOL_DOT }
};

int searchSymb(char code) {
    int n = -1;
    for(int i = 0; i < SYMBOLS_COUNT; i++) {
        if(SYMBOLS[i].code == code - 48) {
            n = i;
        }
    }
    return n;
}