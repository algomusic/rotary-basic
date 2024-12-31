// rotary-basic example

#include "rotary_basic.h"

void setup() {
  Serial.begin(115200);
  // pins A, B, and Push
  setupRotaryBasic(33, 37, 38);
}

void loop() {
  int state = updateRotaryBasic(); // needs rapid updating
  if (state == 1) Serial.println("CCW");
  if (state == 2) Serial.println("CW");
  if (state == 3) Serial.println("PUSH DOWN");
  if (state == 4) Serial.println("PUSH UP");
}
