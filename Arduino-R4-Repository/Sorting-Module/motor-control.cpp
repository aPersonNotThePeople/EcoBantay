#include "utils.h"

//pin definitions. can add more if needed
const int MOTOR_IN1 = 2;
const int MOTOR_IN2 = 3;
const int MOTOR_PWM = 5;

//speed config
const int DEFAULT_SPEED = 200;

void initMotorSystem() {
  pinMode(MOTOR_IN1, OUTPUT);
  pinMode(MOTOR_IN2, OUTPUT);
  pinMode(MOTOR_PWM, OUTPUT);
  
  stopMotor();
  
  Serial.println("Motor System: Initialized");
  Serial.print("  Default Speed: ");
  Serial.println(DEFAULT_SPEED);
}

void motorRight(int speed) {
  speed = constrain(speed, 0, 255);
  digitalWrite(MOTOR_IN1, HIGH);
  digitalWrite(MOTOR_IN2, LOW);
  analogWrite(MOTOR_PWM, speed);
  Serial.print("Motor RIGHT at speed: ");
  Serial.println(speed);
}

void motorLeft(int speed) {
  speed = constrain(speed, 0, 255);
  digitalWrite(MOTOR_IN1, LOW);
  digitalWrite(MOTOR_IN2, HIGH);
  analogWrite(MOTOR_PWM, speed);
  Serial.print("Motor LEFT at speed: ");
  Serial.println(speed);
}

void stopMotor() {
  digitalWrite(MOTOR_IN1, LOW);
  digitalWrite(MOTOR_IN2, LOW);
  analogWrite(MOTOR_PWM, 0);
  Serial.println("Motor STOPPED");
}