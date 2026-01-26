#include <Arduino.h>
#include "utils.h"

void setup() {
  Serial.begin(115200);
  delay(1000);

  initSortingMotor();
  
  Serial.println("Init Sorting Motor Test");
}

void loop() {
  if (Serial.available() > 0) {
    testSortingMotors();
  }
}
