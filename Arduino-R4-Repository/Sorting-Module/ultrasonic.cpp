#include "utils.h"

//pin definitions
const int TRIG_PIN = 12;
const int ECHO_PIN = 13;

//detection config
const float TRASH_DISTANCE_THRESHOLD = 10.0; // cm

void initUltrasonicSensor() {
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  Serial.println("Ultrasonic Sensor: Initialized");
  Serial.print("  Trash threshold: ");
  Serial.print(TRASH_DISTANCE_THRESHOLD);
  Serial.println(" cm");
}

float readDistance() {
  //send trig pulse
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  //read echo duration
  long duration = pulseIn(ECHO_PIN, HIGH, 30000); //timeout duration

  if (duration == 0) {
    return 999.9; //if timeout
  }

  //sound formula for distance.
  float distance = (duration / 2.0) / 29.1;
  return distance;
}

bool isTrashInPosition() {
  float distance = readDistance();
  return distance < TRASH_DISTANCE_THRESHOLD;
}