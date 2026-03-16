#include "utils.h"

void initConveyorSystem() {
  pinMode(CONVEYOR_MOTOR_IN1, OUTPUT);
  pinMode(CONVEYOR_MOTOR_IN2, OUTPUT);
  pinMode(CONVEYOR_MOTOR_ENABLE, OUTPUT);
  conveyorStop();
  
  Serial.println("Conveyor System: Initialized (1 motor)");
}

void conveyorStart() {
  digitalWrite(CONVEYOR_MOTOR_IN1, HIGH);
  digitalWrite(CONVEYOR_MOTOR_IN2, LOW);
  analogWrite(CONVEYOR_MOTOR_ENABLE, MAXIMUM_CONVEYOR_SPEED);
}

void conveyorStop() {
  digitalWrite(CONVEYOR_MOTOR_IN1, LOW);
  digitalWrite(CONVEYOR_MOTOR_IN2, LOW);
  analogWrite(CONVEYOR_MOTOR_ENABLE, 0);
}