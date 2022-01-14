struct IC {
  String code;
  String description;
  String *gates;
  String *check;
};

#include "setup.h"

#include "logical/4000.h"
#include "logical/4000_list.h"
#include "logical/7400.h"
#include "logical/7400_list.h"
#include "logical/checker.h"
#include "logical/methods.h"

#include "display/symbols.h"
#include "display/methods.h"
#include "display/visuals.h"

void setup() {
  Serial.begin(BAUD_RATE);
  displayInit();
  displayText("   TTL & CMOS   ", "LOGIC ICs TESTER");
  delay(1000);
  displayMenu();
}

void loop() {
  toggleType();
  delay(500);
}