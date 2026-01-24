#include <Arduino.h>
#include "utils.h"

void setup() {
  Serial.begin(115200);
  delay(1000);
  
  Serial.println("\n=== TASK 2: Motor + Metal Detector Test ===");
  
  initMotorSystem();
  initMetalDetector();
}

void loop() {
  //read sensor
  int sensorValue = readProximitySensor();
  
  static unsigned long lastPrint = 0;
  if (millis() - lastPrint > 500) {
    Serial.print("Sensor: ");
    Serial.print(sensorValue);
    
    if (isMetalDetected(sensorValue)) {
      Serial.println(" - METAL detected! Moving RIGHT");
      motorRight(200);
    } else if (isObjectDetected(sensorValue)) {
      Serial.println(" - NON-METAL detected! Moving LEFT");
      motorLeft(200);
    } else {
      Serial.println(" - No object");
      stopMotor();
    }
    
    lastPrint = millis();
  }
  
  //stop command for testing
  if (Serial.available() > 0) {
    char cmd = Serial.read();
    if (cmd == 's') {
      stopMotor();
    }
  }
}