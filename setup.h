// serial port baud rate
#define BAUD_RATE 9600

// pins for display
#define LCD_PIN_RS 52 // RS
#define LCD_PIN_E0 50 // E
#define LCD_PIN_D4 48 // D4
#define LCD_PIN_D5 46 // D5
#define LCD_PIN_D6 44 // D6
#define LCD_PIN_D7 42 // D7

#define IC_PIN_3V 22

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
#define INPUT_PIN_LAST A3 // last ic code
#define INPUT_PIN_NEXT A2 // next ic code
#define INPUT_PIN_TYPE A1 // toggle ic series / rescan
#define INPUT_PIN_SCAN A0 // scan / back

// delay time for each ic check step
#define CHECK_DELAY 100

// ic struct definition
struct IC {
  String code;
  int *image;
  int *table;
  int *gates;
};

// ic list struct definition
struct DB {
  String name;
  String code;
  IC *list;
  int count;
};