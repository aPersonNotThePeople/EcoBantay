<<<<<<< HEAD
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
=======
#include "utils.h"

//pin definitions
const int TRIG_PIN = 8;
const int ECHO_PIN = 9;

//config
const float DETECTION_DISTANCE = 10.0;  //in cm

void initUltrasonicSensor() {
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  
  Serial.println("Ultrasonic Sensor: Initialized");
  Serial.print("  Detection Distance: ");
  Serial.print(DETECTION_DISTANCE);
  Serial.println(" cm");
}

float readDistance() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  
  long duration = pulseIn(ECHO_PIN, HIGH, 30000);
  
  if (duration == 0) {
    return 999.0;
  }
  
  float distance = duration * 0.034 / 2;
  return distance;
}

bool isTrashInPosition() {
  float distance = readDistance();
  return (distance < DETECTION_DISTANCE && distance > 0);
}
>>>>>>> 0777700fb52d18640d2a6c12064bb87a4df791c3
