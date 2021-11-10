int rotaryPins [] = {16, 0, 13};
unsigned long ms, potTime;
int prevA, prevB, prevP;
bool rotaryCW, rotaryCCW, rotaryPush;

void setupRotaryBasic(int a, int b, int p) {
  rotaryPins[0] = a;
  rotaryPins[1] = b;
  rotaryPins[2] = p;
  pinMode(rotaryPins[2], INPUT_PULLUP);
}

int updateRotaryBasic() {
  int state = 0; // 0= off, 1 = CW, 2 = CCW, 3 = Push
  if (millis() - potTime > 2) {
    potTime = millis();
    int pinA = digitalRead(rotaryPins[0]);
    int pinB = digitalRead(rotaryPins[1]);
    int pinPush = digitalRead(rotaryPins[2]);
    
    // Serial.print(pinA);Serial.print(" "); Serial.print(pinB);Serial.print(" "); Serial.println(pinPush);
    
    if (pinA == 1 && pinB == 1 && prevA == 0 && state == 0 && prevB == 0) {
//      Serial.print("CCW "); Serial.print(pinA); Serial.print(" "); Serial.print(pinB);Serial.print(" "); Serial.print(prevA); Serial.print(" "); Serial.println(prevB);
      state = 1;
    } else if (pinA == 0 && pinB == 0 && prevA == 1) {
//      Serial.print("CW "); Serial.print(pinA); Serial.print(" "); Serial.print(pinB);Serial.print(" ");Serial.print(prevA); Serial.print(" "); Serial.println(prevB);
      state = 2;  
    } else if (pinPush == 0 && state != 3 && prevP == 1 ) {
//      Serial.print("Push "); Serial.println(pinPush);
      state = 3;
    }
    
    prevA = pinA;
    prevB = pinB;
    prevP = pinPush;
  }
  return state;
}
