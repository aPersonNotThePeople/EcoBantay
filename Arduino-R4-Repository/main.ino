#include <Arduino.h>
#include "utils.h"

void setup() {
  Serial.begin(115200);
  delay(1000);
  
  Serial.println("\n=== TASK 2: Sorting Motor + Metal Detection ===");
  
  initSortingMotor();
  initMetalDetector();
  
  Serial.println("\nSystem will automatically sort based on metal detection");
  Serial.println("Place objects near the sensor to test");
  Serial.println("\nCommands:");
  Serial.println("  s - STOP motor\n");
}

void loop() {
  //read sensor
  int sensorValue = readProximitySensor();
  
  //sort baesed on detection
  if (isMetalDetected(sensorValue)) {
    sortMotorRight(200);
  } else {
    sortMotorLeft(200);
  }
  
  //print status
  static unsigned long lastPrint = 0;
  if (millis() - lastPrint > 500) {
    Serial.print("Metal Sensor: ");
    Serial.print(sensorValue);
    Serial.println(isMetalDetected(sensorValue) ? " - METAL detected!" : " - Non-metal");
    lastPrint = millis();
  }
  
  //check for stop command
  if (Serial.available() > 0) {
    char cmd = Serial.read();
    if (cmd == 's') {
      sortMotorStop();
    }
  }
}