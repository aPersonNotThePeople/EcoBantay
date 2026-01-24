#include <Arduino.h>
#include "utils.h"

void setup() {
  Serial.begin(115200);
  delay(1000);
  
  Serial.println("\n=== TASK 1: Motor Control Test ===");
  
  initMotorSystem();
}

void loop() {
  if (Serial.available() > 0) {
        motorRight(200);
        stopMotor();
        motorLeft(200);
        stopMotor();
        testMotors();
    }
}