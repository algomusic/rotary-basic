// rotary-basic example
// pins A, B, and Push
#include "rotary_basic.h"

void setup() {
  Serial.begin(115200);
  setupRotaryBasic(16, 0, 13);

}

void loop() {
    int state = updateRotaryBasic();
    if (state == 1) Serial.println("CCW");
    if (state == 2) Serial.println("CW");
    if (state == 3) Serial.println("PUSH");
}
