#include <Arduino.h>
#include "utils.h"

void setup() {
  Serial.begin(115200);
  delay(1000);
  
  Serial.println("\n=== Trash Sorting System ===\n");
  
  initSortingMotor();
  initConveyorSystem();
  initUltrasonicSensor();
  initMetalDetector();
  
  Serial.println("\nAll modules initialized. Starting sorting system...\n");
}

void loop() {
  // run the state machine
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

  // print status every 1 second
  static unsigned long lastPrint = 0;
  if (millis() - lastPrint > 1000) {
    printStatus();
    lastPrint = millis();
  }

  // serial command: 's' to emergency stop everything
  if (Serial.available() > 0) {
    char cmd = Serial.read();
    if (cmd == 's') {
      conveyorStop();
      sortMotorStop();
      currentState = IDLE;
      Serial.println("\n>>> EMERGENCY STOP <<<\n");
    }
  }
}
