#include "utils.h"
#include <SoftwareSerial.h>

//pin definitions
const int TX_PIN = 9;
const int RX_PIN = 8;

const uint8_t HEADER_BYTE = 0xFF;
const uint16_t READ_TIMEOUT_MS = 200;
const int ERROR_DISTANCE = -1;  // Error return value

SoftwareSerial ultrasonicSensor(RX_PIN, TX_PIN);

//config
const float DETECTION_DISTANCE = 10.0;  //in cm

void initUltrasonicSensor() {
  ultrasonicSensor.begin(9600);
  
  Serial.println("Ultrasonic Sensor: Initialized");
  Serial.print("  Detection Distance: ");
  Serial.print(DETECTION_DISTANCE);
  Serial.println(" cm");
}

uint8_t readByte(uint8_t *buf, size_t len) {
  size_t offset = 0, left = len;
  uint8_t *buffer = buf;
  long curr = millis();
  while (left) {
    if (ultrasonicSensor.available()) {
      buffer[offset] = ultrasonicSensor.read();
      offset++;
      left--;
    }
    if (millis() - curr > READ_TIMEOUT_MS) {
      break;
    }
  }
  return offset;
}

float readDistanceFromUART() {
  uint8_t data[4] = { 0 };
  uint8_t receivedByte = 0;
  unsigned long startTime = millis();

  while (millis() - startTime < READ_TIMEOUT_MS) {                      // Check if timeout
    if (readByte(&receivedByte, 1) == 1 && receivedByte == HEADER_BYTE) {  // Find the header byte
      data[0] = receivedByte;
      if (readByte(&data[1], 3) == 3) {                     // Read the remaining 3 bytes
        uint8_t checksum = data[0] + data[1] + data[2];  // Checksum
        if (checksum == data[3]) {
          uint16_t distance = (data[1] << 8) | data[2];  // Calculate and return the distance
          return distance / 10; // convert distance from mm to cm
        }
      }
    }
    Serial.println("Error data");
  }
  Serial.println("Error Reading data timeout");
  return ERROR_DISTANCE;
}

float readDistance() {
  digitalWrite(ULTRASONIC_TRIGGER, LOW);
  delayMicroseconds(2);
  digitalWrite(ULTRASONIC_TRIGGER, HIGH);
  delayMicroseconds(10);
  digitalWrite(ULTRASONIC_TRIGGER, LOW);
  
  long duration = pulseIn(ULTRASONIC_ECHO, HIGH, 30000);
  
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
