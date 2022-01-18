#define TEXT_SYMBOLS_LENGTH 10
#define GATE_SYMBOLS_LENGTH 16

byte LOGIC_AND[] = {
  B11100,
  B10010,
  B10001,
  B10001,
  B10001,
  B10010,
  B11100,
  B00000
};

byte LOGIC_OR[] = {
  B11000,
  B10100,
  B01010,
  B01001,
  B01010,
  B10100,
  B11000,
  B00000
};

byte LOGIC_NOT[] = {
  B11000,
  B10100,
  B10010,
  B10001,
  B10010,
  B10100,
  B11000,
  B00000
};

byte LOGIC_XOR[] = {
  B10100,
  B10110,
  B10101,
  B01011,
  B10101,
  B10110,
  B10100,
  B00000
};

byte LOGIC_LINE_NOT[] = {
  B00000,
  B00000,
  B01000,
  B10111,
  B01000,
  B00000,
  B00000,
  B00000
};

byte LOGIC_LINE_3[] = {
  B00000,
  B11111,
  B00000,
  B11111,
  B00000,
  B11111,
  B00000,
  B00000
};

byte LOGIC_LINE_4[] = {
  B11111,
  B00000,
  B11111,
  B00000,
  B11111,
  B00000,
  B11111,
  B00000
};

byte LOGIC_DOT[] = {
  B00000,
  B00000,
  B00000,
  B00000,
  B01100,
  B10010,
  B10010,
  B01100
};

byte LOGIC_IC_TL[] = {
	B00000,
	B00000,
	B00000,
	B00001,
	B00001,
	B00001,
	B00001,
	B00001
};

byte LOGIC_IC_TR[] = {
	B00000,
	B00000,
	B00000,
	B10000,
	B10000,
	B10000,
	B10000,
	B10000
};

byte LOGIC_IC_BL[] = {
	B00001,
	B00001,
	B00001,
	B00001,
	B00001,
	B00000,
	B00000,
	B00000
};

byte LOGIC_IC_BR[] = {
	B10000,
	B10000,
	B10000,
	B10000,
	B10000,
	B00000,
	B00000,
	B00000
};

byte LOGIC_IC_T[] = {
	B00100,
	B00100,
	B11111,
	B00000,
	B00000,
	B00000,
	B00000,
	B00000
};

byte LOGIC_IC_TX[] = {
	B00100,
	B00100,
	B11111,
	B00000,
	B01010,
	B00100,
	B01010,
	B00000
};

byte LOGIC_IC_B[] = {
	B00000,
	B00000,
	B00000,
	B00000,
	B00000,
	B11111,
	B00100,
	B00100
};

byte LOGIC_IC_BX[] = {
	B00000,
	B01010,
	B00100,
	B01010,
	B00000,
	B11111,
	B00100,
	B00100
};

byte ARROW_LEFT[] = {
  B00010,
  B00110,
  B01110,
  B11110,
  B01110,
  B00110,
  B00010,
  B00000
};

byte ARROW_RIGHT[] = {
  B01000,
  B01100,
  B01110,
  B01111,
  B01110,
  B01100,
  B01000,
  B00000
};

byte WAVE_LOW[] = {
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B11111
};

byte WAVE_HIGH[] = {
  B00000,
  B00000,
  B00000,
  B00000,
  B11111,
  B11111,
  B11111,
  B11111
};

byte LOGO_PART_1[] = {
	B00001,
	B00001,
	B00111,
	B00100,
	B11101,
	B00101,
	B11101,
	B00101
};

byte LOGO_PART_2[] = {
	B10101,
	B10101,
	B11111,
	B00000,
	B11111,
	B00000,
	B00000,
	B00000
};

byte LOGO_PART_3[] = {
	B10000,
	B10000,
	B11100,
	B00100,
	B10111,
	B10100,
	B10111,
	B10100
};

byte LOGO_PART_4[] = {
	B00101,
	B11101,
	B00101,
	B11100,
	B00111,
	B00001,
	B00001,
	B00000
};

byte LOGO_PART_5[] = {
	B00000,
	B00000,
	B11111,
	B00000,
	B11111,
	B10101,
	B10101,
	B00000
};

byte LOGO_PART_6[] = {
	B10100,
	B10111,
	B10100,
	B00111,
	B11100,
	B10000,
	B10000,
	B00000
};

struct SYMB {
    char code;
    byte *data;
};

SYMB TEXT_SYMBOLS[] = {
    { '<', ARROW_LEFT },
    { '>', ARROW_RIGHT },
    { '_', WAVE_LOW },
    { '=', WAVE_HIGH },

    { '~', LOGO_PART_1 },
    { '!', LOGO_PART_2 },
    { '@', LOGO_PART_3 },
    { '#', LOGO_PART_4 },
    { '$', LOGO_PART_5 },
    { '^', LOGO_PART_6 }
};

SYMB GATE_SYMBOLS[] = {
    { '3', LOGIC_LINE_3 },
    { '4', LOGIC_LINE_4 },
    { '5', LOGIC_LINE_NOT },
    { '6', LOGIC_AND },
    { '7', LOGIC_OR },
    { '8', LOGIC_NOT },
    { '9', LOGIC_XOR },
    { '*', LOGIC_DOT },

    { 'G', LOGIC_IC_TL },
    { 'H', LOGIC_IC_TR },
    { 'I', LOGIC_IC_BL },
    { 'J', LOGIC_IC_BR },
    { 'T', LOGIC_IC_T },
    { 'X', LOGIC_IC_TX },
    { 'B', LOGIC_IC_B },
    { 'Z', LOGIC_IC_BX }
};

int getSymbolIndexByCode(SYMB *sydb, int len, char code) {
  int index = -1;
  for(int i = 0; i < len; i++) {
    if(sydb[i].code == code) { index = i; }
  }
  return index;
}

char arr_symb[8] = { 0, 0, 0, 0, 0, 0, 0, 0 };
int crr_symb = 0;

int regSymbol(SYMB *sydb, int len, char code) {
  // old register
  int reg_index = -1;
  for(int i = 0; i < 8; i++) {
    if(arr_symb[i] == code) { reg_index = i; }
  }
  if(reg_index > -1) { return reg_index; }
  // new register
  int symb_index = getSymbolIndexByCode(sydb, len, code);
  if(symb_index > -1) {
    reg_index = crr_symb;
    arr_symb[reg_index] = code;
    display.createChar(reg_index, sydb[symb_index].data);
    crr_symb++;
    if(crr_symb == 8) { crr_symb = 0; }
  }
  return reg_index;
}

void regAllSymbols(SYMB *sydb, int len, String text) {
  for(int i = 0; i < 8; i++) { arr_symb[i] = 0; }
  crr_symb = 0;
  for(int i = 0; i < 32; i++) {
    int index = regSymbol(sydb, len, text[i]);
  }
}

void setSymbol(SYMB *sydb, int len, char symb, int x, int y) {
  display.setCursor(x, y);
  int index = regSymbol(sydb, len, symb);
  if(index > -1) {
    // symbol
    display.write(byte(index));
  } else {
    // common char
    display.print(symb);
  }
}