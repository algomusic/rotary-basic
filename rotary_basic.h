int rotaryPins [] = {16, 0, 13};
unsigned long ms, potTime;
int prevA, prevB, prevP;
bool rotaryCW, rotaryCCW, rotaryPush;

void setupRotaryBasic(int a, int b, int p) {
  rotaryPins[0] = a;
  rotaryPins[1] = b;
  rotaryPins[2] = p;
  pinMode(rotaryPins[0], INPUT_PULLUP);
  pinMode(rotaryPins[1], INPUT_PULLUP);
  pinMode(rotaryPins[2], INPUT_PULLUP);
}

int updateRotaryBasic() {
  int state = 0; // 0= off, 1 = CW, 2 = CCW, 3 = Push down, 4 = push up
  if (millis() - potTime > 2) { 
    potTime = millis();
    int pinA = digitalRead(rotaryPins[0]);
    int pinB = digitalRead(rotaryPins[1]);
    int pinPush = digitalRead(rotaryPins[2]);

    // if (pinA != prevA || pinB != prevB || pinPush != prevP) {
    // if (pinA == 0 || pinB == 0 || pinPush == 0) {
    //   Serial.print(pinA);Serial.print(" ("); Serial.print(prevA);Serial.print(") ");
    //   Serial.print(pinB);Serial.print(" ");Serial.print(" ("); Serial.print(prevB);Serial.print(") ");
    //   Serial.print(pinPush);Serial.print(" ("); Serial.print(prevP);Serial.println(") ");
    // }
    
    if (pinA == 1 && prevA == 0 && pinB == 0  && state != 1) {
    //  Serial.print("CCW "); Serial.print(pinA); Serial.print(" "); Serial.print(pinB);Serial.print(" "); Serial.print(prevA); Serial.print(" "); Serial.println(prevB);
      state = 1;
    } else if (pinA == 0 && pinB == 1 && prevB == 0 && state != 2) {
    //  Serial.print("CW "); Serial.print(pinA); Serial.print(" "); Serial.print(pinB);Serial.print(" ");Serial.print(prevA); Serial.print(" "); Serial.println(prevB);
      state = 2;  
    } else if (pinPush == 0 && state != 3 && prevP == 1 ) {
          //  Serial.print("Push down"); Serial.println(pinPush);
      state = 3;
    // } else if (pinPush == 1 && state == 3 && prevP == 0 ) {
    } else if (pinPush == 1 && prevP == 0 ) {
      state = 4;
      //  Serial.print("Push up"); Serial.println(pinPush);
    }
    
    prevA = pinA;
    prevB = pinB;
    prevP = pinPush;
  }
  return state;
}
