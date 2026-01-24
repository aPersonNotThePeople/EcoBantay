#ifndef UTILS_H
#define UTILS_H

#include <Arduino.h>

//motor controls
void initMotorSystem();
void motorRight(int speed);
void motorLeft(int speed);
void stopMotor();

//metal detector
void initMetalDetector();
int readProximitySensor();
bool isMetalDetected(int sensorValue);
bool isObjectDetected(int sensorValue);

#endif