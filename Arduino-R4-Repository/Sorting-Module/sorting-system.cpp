#include "utils.h"

const int SCAN_DURATION = 500;
const int SORT_DURATION = 1500;
const int RETURN_DURATION = 1000;

SortState currentState = IDLE;
unsigned long stateStartTime = 0;
bool metalDetected = false;

void handleIdle() {
  Serial.println("System IDLE - Starting conveyor");
  currentState = CONVEYOR_RUNNING;
  conveyorStart();
}

void handleConveyorRunning() {
  if (isTrashInPosition()) {
    Serial.println("\n>>> TRASH DETECTED <<<");
    conveyorStop();
    currentState = TRASH_DETECTED;
    delay(200);
  }
}

void handleTrashDetected() {
  Serial.println("Scanning for metal...");
  currentState = SCANNING_METAL;
  stateStartTime = millis();
  metalDetected = false;
}

void handleScanningMetal() {
  int sensorValue = readProximitySensor();
  
  if (isMetalDetected(sensorValue)) {
    metalDetected = true;
  }
  
  if (millis() - stateStartTime >= SCAN_DURATION) {
    if (metalDetected) {
      Serial.println(">>> METAL - Sorting RIGHT <<<");
      currentState = SORT_METAL;
      sortMotorRight(200);
    } else {
      Serial.println(">>> NON-METAL - Sorting LEFT <<<");
      currentState = SORT_NON_METAL;
      sortMotorLeft(200);
    }
    stateStartTime = millis();
  }
}

void handleSortMetal() {
  if (millis() - stateStartTime >= SORT_DURATION) {
    sortMotorStop();
    Serial.println("Metal sorted");
    currentState = RETURNING;
    stateStartTime = millis();
    sortMotorLeft(200);
  }
}

void handleSortNonMetal() {
  if (millis() - stateStartTime >= SORT_DURATION) {
    sortMotorStop();
    Serial.println("Non-metal sorted");
    currentState = RETURNING;
    stateStartTime = millis();
    sortMotorRight(200);
  }
}

void handleReturning() {
  if (millis() - stateStartTime >= RETURN_DURATION) {
    sortMotorStop();
    Serial.println("Ready for next item\n");
    currentState = CONVEYOR_RUNNING;
    conveyorStart();
    delay(1000);
  }
}

const char* getStateName(SortState state) {
  switch (state) {
    case IDLE: return "IDLE";
    case CONVEYOR_RUNNING: return "CONVEYOR";
    case TRASH_DETECTED: return "DETECTED";
    case SCANNING_METAL: return "SCANNING";
    case SORT_METAL: return "SORT_METAL";
    case SORT_NON_METAL: return "SORT_NON_METAL";
    case RETURNING: return "RETURNING";
    default: return "UNKNOWN";
  }
}

void printStatus() {
  Serial.print("Distance: ");
  Serial.print(readDistance());
  Serial.print("cm | Metal: ");
  Serial.print(readProximitySensor());
  Serial.print(" | State: ");
  Serial.println(getStateName(currentState));
}
