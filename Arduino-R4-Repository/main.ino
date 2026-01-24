#include <Arduino.h>
#include "utils.h"

void setup() {
  Serial.begin(115200);
  delay(1000);
  
  Serial.println("\n=== TASK 1: Sorting Motor Test ===");
  
  initSortingMotor();
  
  Serial.println("\nCommands:");
  Serial.println("  r - Sort RIGHT (metal bin)");
  Serial.println("  l - Sort LEFT (non-metal bin)");
  Serial.println("  s - STOP motor");
  Serial.println("  t - Run motor TEST\n");
}

void loop() {
  if (Serial.available() > 0) {
        testSortingMotor();
    }
}