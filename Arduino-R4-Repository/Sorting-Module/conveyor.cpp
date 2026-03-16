#include "utils.h"

//conveyor pin definitions
const int CONV1_IN1 = 2;
const int CONV1_IN2 = 3;
const int CONV1_PWM = 5;

const int CONV2_IN1 = 4;
const int CONV2_IN2 = 7;
const int CONV2_PWM = 6;

const int CONV3_IN1 = A1;
const int CONV3_IN2 = A2;
const int CONV3_PWM = 11;  // fixed: was pin 12 which is NOT a PWM pin. Valid PWM pins: 3,5,6,9,10,11

const int CONVEYOR_SPEED = 180;

void initConveyorSystem() {
  pinMode(CONV1_IN1, OUTPUT);
  pinMode(CONV1_IN2, OUTPUT);
  pinMode(CONV1_PWM, OUTPUT);
  
  pinMode(CONV2_IN1, OUTPUT);
  pinMode(CONV2_IN2, OUTPUT);
  pinMode(CONV2_PWM, OUTPUT);
  
  pinMode(CONV3_IN1, OUTPUT);
  pinMode(CONV3_IN2, OUTPUT);
  pinMode(CONV3_PWM, OUTPUT);
  
  conveyorStop();
  
  Serial.println("Conveyor System: Initialized (3 motors)");
}

void conveyorStart() {
  digitalWrite(CONV1_IN1, HIGH);
  digitalWrite(CONV1_IN2, LOW);
  analogWrite(CONV1_PWM, CONVEYOR_SPEED);
  
  digitalWrite(CONV2_IN1, HIGH);
  digitalWrite(CONV2_IN2, LOW);
  analogWrite(CONV2_PWM, CONVEYOR_SPEED);
  
  digitalWrite(CONV3_IN1, HIGH);
  digitalWrite(CONV3_IN2, LOW);
  analogWrite(CONV3_PWM, CONVEYOR_SPEED);
}

void conveyorStop() {
  digitalWrite(CONV1_IN1, LOW);
  digitalWrite(CONV1_IN2, LOW);
  analogWrite(CONV1_PWM, 0);
  
  digitalWrite(CONV2_IN1, LOW);
  digitalWrite(CONV2_IN2, LOW);
  analogWrite(CONV2_PWM, 0);
  
  digitalWrite(CONV3_IN1, LOW);
  digitalWrite(CONV3_IN2, LOW);
  analogWrite(CONV3_PWM, 0);
}