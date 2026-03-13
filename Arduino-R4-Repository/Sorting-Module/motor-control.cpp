#include "utils.h"

void initSortingMotor() {
  pinMode(STEPPER_MOTOR1_ENABLE, OUTPUT);
  pinMode(STEPPER_MOTOR1_DIR, OUTPUT);
  pinMode(STEPPER_MOTOR1_STP, OUTPUT);

  pinMode(STEPPER_MOTOR2_ENABLE, OUTPUT);
  pinMode(STEPPER_MOTOR2_DIR, OUTPUT);
  pinMode(STEPPER_MOTOR2_STP, OUTPUT);

  digitalWrite(STEPPER_MOTOR2_DIR, HIGH);
  
  sortMotorStop();
  
  Serial.println("Sorting Motors: Initialized");
  Serial.print("  Default Speed: ");
  Serial.println(DEFAULT_SPEED);
}

void returnLeftMotor() {
  // Divded by four to spin 90 degrees 
  delay(1000);
  digitalWrite(STEPPER_MOTOR1_ENABLE, HIGH);
  for (int x = 0; x < STEPS_PER_REVOLUTION / (360/ROTATE_DEGREE); x++) {
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(DEFAULT_SPEED);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(DEFAULT_SPEED);
  }
  delay(2000);
  digitalWrite(STEPPER_MOTOR1_ENABLE, LOW)
}

void returnRightMotor() {
  // Divded by four to spin 90 degrees 
  delay(1000);
  digitalWrite(STEPPER_MOTOR2_ENABLE, HIGH);
  for (int x = 0; x < STEPS_PER_REVOLUTION / (360/ROTATE_DEGREE); x++) {
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(DEFAULT_SPEED);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(DEFAULT_SPEED);
  }
  delay(2000);
  digitalWrite(STEPPER_MOTOR2_ENABLE, LOW)
}

void sortMotorStop() {
  digitalWrite(STEPPER_MOTOR1_ENABLE, LOW);
  digitalWrite(STEPPER_MOTOR2_ENABLE, LOW);
  Serial.println("Sort Motor STOPPED");
}