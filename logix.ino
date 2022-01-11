#include "4000.h"
#include "check_inputs.h"

void setup() {
  Serial.begin(9600);
  check_inputs(IC_4000, sizeof(IC_4000));
}

void loop() {
  
}
