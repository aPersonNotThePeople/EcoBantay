#include "utils.h"

//pin definitions
const int SORT_MOTOR_IN1 = 8;
const int SORT_MOTOR_IN2 = 9;
const int SORT_MOTOR_PWM = 10;

//speed config
const int DEFAULT_SPEED = 200;

void initSortingMotor() {
  pinMode(SORT_MOTOR_IN1, OUTPUT);
  pinMode(SORT_MOTOR_IN2, OUTPUT);
  pinMode(SORT_MOTOR_PWM, OUTPUT);
  
  sortMotorStop();
  
  Serial.println("Sorting Motor: Initialized");
  Serial.print("  Default Speed: ");
  Serial.println(DEFAULT_SPEED);
}

void sortMotorRight(int speed) {
  speed = constrain(speed, 0, 255);
  digitalWrite(SORT_MOTOR_IN1, HIGH);
  digitalWrite(SORT_MOTOR_IN2, LOW);
  analogWrite(SORT_MOTOR_PWM, speed);
  Serial.print("Sort Motor RIGHT at speed: ");
  Serial.println(speed);
}

void sortMotorLeft(int speed) {
  speed = constrain(speed, 0, 255);
  digitalWrite(SORT_MOTOR_IN1, LOW);
  digitalWrite(SORT_MOTOR_IN2, HIGH);
  analogWrite(SORT_MOTOR_PWM, speed);
  Serial.print("Sort Motor LEFT at speed: ");
  Serial.println(speed);
}

void sortMotorStop() {
  digitalWrite(SORT_MOTOR_IN1, LOW);
  digitalWrite(SORT_MOTOR_IN2, LOW);
  analogWrite(SORT_MOTOR_PWM, 0);
  Serial.println("Sort Motor STOPPED");
}