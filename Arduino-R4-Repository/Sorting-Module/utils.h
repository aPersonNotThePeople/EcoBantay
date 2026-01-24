#ifndef UTILS_H
#define UTILS_H

#include <Arduino.h>

// States
enum SortState {
  IDLE,
  DETECTING,
  SORT_METAL,
  SORT_NON_METAL,
  RETURNING
};

// Global Variables
extern SortState currentState;
extern unsigned long sortStartTime;
extern bool metalDetected;

// Function Declarations - State Handlers
void handleIdle();
void handleDetecting();
void handleSortMetal();
void handleSortNonMetal();
void handleReturning();
void printStatus();
const char* getStateName(SortState state);

// Function Declarations - Motor Control
void initMotorSystem();
void motorRight(int speed);
void motorLeft(int speed);
void stopMotor();

// Function Declarations - Metal Detection
void initMetalDetector();
int readProximitySensor();
bool isMetalDetected(int sensorValue);
bool isObjectDetected(int sensorValue);

#endif