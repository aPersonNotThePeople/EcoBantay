#include "utils.h"

const int MOTOR_IN1 = 2; //motor pin definitions
const int MOTOR_IN2 = 3;
const int MOTOR_PWM = 5;
//can add if more

const int SORT_SPEED = 200; //motor speed for sorting

void initMotorSystem() {
  pinMode(MOTOR_IN1, OUTPUT);
  pinMode(MOTOR_IN2, OUTPUT);
  pinMode(MOTOR_PWM, OUTPUT);
  
  stopMotor();
  
  Serial.println("Motor System: Initialized");
  Serial.print("Sort Speed: ");
  Serial.println(SORT_SPEED);
}

void motorRight(int speed) {
  speed = constrain(speed, 0, 255);
  digitalWrite(MOTOR_IN1, HIGH);
  digitalWrite(MOTOR_IN2, LOW);
  analogWrite(MOTOR_PWM, speed);
}

void motorLeft(int speed) {
  speed = constrain(speed, 0, 255);
  digitalWrite(MOTOR_IN1, LOW);
  digitalWrite(MOTOR_IN2, HIGH);
  analogWrite(MOTOR_PWM, speed);
}

void stopMotor() {
  digitalWrite(MOTOR_IN1, LOW);
  digitalWrite(MOTOR_IN2, LOW);
  analogWrite(MOTOR_PWM, 0);
}