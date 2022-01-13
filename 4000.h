// 4000 Dual 3-Input NOR + 1 NOT
String IC_4000_GATES[] = {
    "    NAND   NOT  ",
    "*      NAND     "
};

String IC_4000[] = {
    "NN IIIO G IO OIII V X",
    "NN 0001 G 01 1000 V X",
    "NN 0010 G 10 0001 V X",
    "NN 0100 G 01 0010 V X",
    "NN 0110 G 10 0011 V X",
    "NN 1000 G 01 0100 V X",
    "NN 1010 G 10 0101 V X",
    "NN 1100 G 01 0110 V X",
    "NN 1110 G 10 0111 V Z"
};

// 4001 Quad 2-Input NOR
String IC_4001_GATES[] = {
    "     NAND NAND  ",
    "*  NAND NAND    "
};

String IC_4001[] = {
    "IIO OII G IIO OII V X",
    "001 100 G 001 100 V X",
    "010 001 G 010 001 V X",
    "100 010 G 100 010 V X",
    "110 011 G 110 011 V Z"
};

// 4002 Dual 4-Input NOR
String IC_4002_GATES[] = {
    "       NAND     ",
    "*      NAND     "
};

String IC_4002[] = {
    "OIIII N G N IIIIO V X",
    "10000 N G N 00001 V X",
    "00001 N G N 00010 V X",
    "00010 N G N 00100 V X",
    "00011 N G N 00110 V X",
    "00100 N G N 01000 V X",
    "00101 N G N 01010 V X",
    "00110 N G N 01100 V X",
    "00111 N G N 01110 V X",
    "01000 N G N 10000 V X",
    "01001 N G N 10010 V X",
    "01010 N G N 10100 V X",
    "01011 N G N 10110 V X",
    "01100 N G N 11000 V X",
    "01101 N G N 11010 V X",
    "01110 N G N 11100 V X",
    "01111 N G N 11110 V Z"
};