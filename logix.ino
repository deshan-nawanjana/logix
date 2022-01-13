#include "4000.h"
#include "display.h"
#include "check_inputs.h"

void setup() {
  Serial.begin(9600);
  display_begin();
  delay(3000);
  display_gates(IC_4000_GATES, "111ZZZZZZZ");
  delay(1000);
  display_gates(IC_4000_GATES, "011ZZZZZZZ");
  delay(1000);
  display_gates(IC_4000_GATES, "101ZZZZZZZ");
  delay(1000);
  display_gates(IC_4000_GATES, "110ZZZZZZZ");
  delay(1000);
  display_gates(IC_4000_GATES, "000ZZZZZZZ");
  delay(1000);
  display_gates(IC_4000_GATES, "111ZZZZZZZ");
  delay(1000);
  check_inputs(IC_4002);
}

void loop() {
  
}
