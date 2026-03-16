#include "utils.h"

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
    } else {
      Serial.println(">>> NON-METAL - Sorting LEFT <<<");
      currentState = SORT_NON_METAL;
    }
    stateStartTime = millis();
  }
}

void handleSortMetal() {
  if (millis() - stateStartTime >= SORT_DURATION) {
    sortMotorStop();
    delay(500);
    openAndCloseSolenoidLock(SOLENOID_LOCK1_RELAY, 1000); // Opens lock, which drops the trapdoor
    returnTrapdoor(STEPPER_MOTOR1_ENABLE, STEPPER_MOTOR1_STP, SOLENOID_LOCK1_RELAY)
    Serial.println("Metal sorted");
    currentState = RETURNING;
    stateStartTime = millis();
  }
}

void handleSortNonMetal() {
  if (millis() - stateStartTime >= SORT_DURATION) {
    sortMotorStop();
    delay(500);
    openAndCloseSolenoidLock(SOLENOID_LOCK2_RELAY, 1000); // Opens lock, which drops the trapdoor
    returnTrapdoor(STEPPER_MOTOR2_ENABLE, STEPPER_MOTOR2_STP, SOLENOID_LOCK2_RELAY)
    Serial.println("Non-metal sorted");
    currentState = RETURNING;
    stateStartTime = millis();
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
