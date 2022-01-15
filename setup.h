// serial port baud rate
#define BAUD_RATE 9600

// pins for display
#define LCD_PIN_0 42 // RS
#define LCD_PIN_1 44 // E
#define LCD_PIN_2 46 // D4
#define LCD_PIN_3 48 // D5
#define LCD_PIN_4 50 // D6
#define LCD_PIN_5 52 // D7

// pins for ic base [ 0 to 6 ]

#define IC_PIN_01 2
#define IC_PIN_02 3
#define IC_PIN_03 4
#define IC_PIN_04 5
#define IC_PIN_05 6
#define IC_PIN_06 7

// pins for ic base [ 8 to 13 ]
#define IC_PIN_08 8
#define IC_PIN_09 9
#define IC_PIN_10 10
#define IC_PIN_11 11
#define IC_PIN_12 12
#define IC_PIN_13 13

// analog  pins for user input button
#define INPUT_PIN_0 A2 // toggle ic series
#define INPUT_PIN_1 A3 // start / end scaning
#define INPUT_PIN_2 A1 // last ic code
#define INPUT_PIN_3 A0 // next ic code

// single ic struct definition
struct IC {
  String code;
  int *image;
  int *table;
};

// ic list struct definition
struct DB {
  String name;
  String code;
  IC *list;
  int count;
};