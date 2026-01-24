#include "utils.h"

// Timing Configuration
const int SORT_DURATION = 2000;
const int RETURN_DURATION = 1000;
const int IDLE_DELAY = 500;

// Global Variables
SortState currentState = IDLE;
unsigned long sortStartTime = 0;
bool metalDetected = false;

void handleIdle() {
  int sensorValue = readProximitySensor();
  
  if (isMetalDetected(sensorValue)) {
    metalDetected = true;
    currentState = DETECTING;
    Serial.println("\n>>> METAL DETECTED <<<");
    delay(100);
  } else if (isObjectDetected(sensorValue)) {
    metalDetected = false;
    currentState = DETECTING;
    Serial.println("\n>>> NON-METAL DETECTED <<<");
    delay(100);
  }
}

void handleDetecting() {
  delay(200);
  int sensorValue = readProximitySensor();
  
  if (metalDetected && isMetalDetected(sensorValue)) {
    Serial.println("Confirmed: Sorting to METAL bin (RIGHT)");
    currentState = SORT_METAL;
    sortStartTime = millis();
    motorRight(getMotorSpeed());
  } else if (!metalDetected && isObjectDetected(sensorValue)) {
    Serial.println("Confirmed: Sorting to NON-METAL bin (LEFT)");
    currentState = SORT_NON_METAL;
    sortStartTime = millis();
    motorLeft(getMotorSpeed());
  } else {
    Serial.println("False detection - returning to IDLE");
    currentState = IDLE;
  }
}

void handleSortMetal() {
  if (millis() - sortStartTime >= SORT_DURATION) {
    stopMotor();
    Serial.println("Metal sorted successfully");
    currentState = RETURNING;
    sortStartTime = millis();
    motorLeft(getMotorSpeed());
  }
}

void handleSortNonMetal() {
  if (millis() - sortStartTime >= SORT_DURATION) {
    stopMotor();
    Serial.println("Non-metal sorted successfully");
    currentState = RETURNING;
    sortStartTime = millis();
    motorRight(getMotorSpeed());
  }
}

void handleReturning() {
  if (millis() - sortStartTime >= RETURN_DURATION) {
    stopMotor();
    Serial.println("Returned to center - Ready for next item\n");
    currentState = IDLE;
    delay(IDLE_DELAY);
  }
}

const char* getStateName(SortState state) {
  switch (state) {
    case IDLE: return "IDLE";
    case DETECTING: return "DETECTING";
    case SORT_METAL: return "SORT_METAL";
    case SORT_NON_METAL: return "SORT_NON_METAL";
    case RETURNING: return "RETURNING";
    default: return "UNKNOWN";
  }
}

void printStatus() {
  int sensorValue = readProximitySensor();
  Serial.print("Sensor: ");
  Serial.print(sensorValue);
  Serial.print(" | State: ");
  Serial.println(getStateName(currentState));
}