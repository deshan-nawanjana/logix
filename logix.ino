#include "setup.h"
#include "extern.h"

#include "database/imports.h"

#include "display/modules.h"
#include "display/symbols.h"
#include "display/methods.h"

#include "logical/checker.h"
#include "logical/methods.h"

#include "inputs/checker.h"
#include "inputs/methods.h"

void setup() {
  displayInit();
  displayHome();
  // button pin modes
  pinMode(INPUT_PIN_LAST, INPUT_PULLUP);
  pinMode(INPUT_PIN_NEXT, INPUT_PULLUP);
  pinMode(INPUT_PIN_TYPE, INPUT_PULLUP);
  pinMode(INPUT_PIN_SCAN, INPUT_PULLUP);
}

void loop() {
  inputsCheck();
}