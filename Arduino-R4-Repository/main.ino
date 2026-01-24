#include <Arduino.h>
#include "utils.h"

void setup() {
  Serial.begin(115200);
  delay(1000);
  
  Serial.println("\n=== Water Trash Collector - Sorting System ===");
  
  initMetalDetector();
  initMotorSystem();
  
  Serial.println("\nSystem Ready - Waiting for trash detection...\n");
}

void loop() {
  switch (currentState) {
    case IDLE:
      handleIdle();
      break;
      
    case DETECTING:
      handleDetecting();
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
  
  if (millis() % 500 < 10) {
    printStatus();
  }
}