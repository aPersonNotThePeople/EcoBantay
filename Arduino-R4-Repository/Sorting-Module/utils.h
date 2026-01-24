#ifndef UTILS_H
#define UTILS_H

#include <Arduino.h>

// Motor Control Functions
void initMotorSystem();
void motorRight(int speed);
void motorLeft(int speed);
void stopMotor();
void testMotors();

#endif