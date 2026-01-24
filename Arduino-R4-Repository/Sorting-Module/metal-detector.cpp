#include "utils.h"

//pin definitions
const int INDUCTIVE_PROXIMITY_SENSOR_PIN = A0;

//detection thresholds
const int METAL_THRESHOLD = 500;
const int OBJECT_THRESHOLD = 100;

void initMetalDetector() {
  pinMode(INDUCTIVE_PROXIMITY_SENSOR_PIN, INPUT);
  Serial.println("Metal Detector: Initialized");
  Serial.print("  Metal Threshold: ");
  Serial.println(METAL_THRESHOLD);
  Serial.print("  Object Threshold: ");
  Serial.println(OBJECT_THRESHOLD);
}

int readProximitySensor() {
  return analogRead(INDUCTIVE_PROXIMITY_SENSOR_PIN);
}

bool isMetalDetected(int sensorValue) {
  return sensorValue > METAL_THRESHOLD;
}

bool isObjectDetected(int sensorValue) {
  return sensorValue > OBJECT_THRESHOLD;
}