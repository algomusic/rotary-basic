// rotary-basic example

#include "rotary_basic.h"

int counter = 0;

void setup() {
  Serial.begin(115200);
  // pins A, B, and Push
  setupRotaryBasic(15, 16, 17);
}

void loop() {
  int state = updateRotaryBasic(); // needs rapid updating
  if (state == 1) {
    counter--;
    Serial.println(String(counter) + " CCW");
  }
  if (state == 2) {
    counter++;
    Serial.println(String(counter) + " CW");
  }
  if (state == 3) {
    counter = 0;
    Serial.println(String(counter) + " PUSH DOWN");
  }
  if (state == 4) Serial.println("PUSH UP");
}
