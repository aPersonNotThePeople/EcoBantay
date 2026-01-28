#include <Arduino.h>
#include "utils.h"

void setup() {
  Serial.begin(115200);
  delay(1000);
  
  Serial.println("\n=== TASK 4: Complete Water Trash Collector ===");
  
  initSortingMotor();
  initMetalDetector();
  initUltrasonicSensor();
  initConveyorSystem();
  
  Serial.println("\nComplete Flow:");
  Serial.println("  1. Conveyor runs");
  Serial.println("  2. Ultrasonic detects trash");
  Serial.println("  3. Conveyor stops");
  Serial.println("  4. Metal scan");
  Serial.println("  5. Sort left/right");
  Serial.println("  6. Return & repeat\n");
  
  delay(2000);
}

void loop() {
  switch (currentState) {
    case IDLE:
      handleIdle();
      break;
    case CONVEYOR_RUNNING:
      handleConveyorRunning();
      break;
    case TRASH_DETECTED:
      handleTrashDetected();
      break;
    case SCANNING_METAL:
      handleScanningMetal();
      break;
    case SORT_METAL:
      handleSortMetal();
      break;
    case SORT_NON_METAL:
      handleSortNonMetal();
      break;
    case RETURNING:
      handleReturning();
      break;
  }
  
  static unsigned long lastPrint = 0;
  if (millis() - lastPrint > 1000) {
    printStatus();
    lastPrint = millis();
  }
}
