#ifndef UTILS_H
#define UTILS_H

#include <Arduino.h>

//system states
enum SortState {
  IDLE,
  SCANNING_METAL,
  SORT_METAL,
  SORT_NON_METAL,
  RETURNING
};

// Global Variables
extern SortState currentState;
extern unsigned long stateStartTime;
extern bool metalDetected;

//motor control module
void initSortingMotor();
void sortMotorRight(int speed);
void sortMotorLeft(int speed);
void sortMotorStop();

//conveyor modules
void initConveyorSystem();
void conveyorStart();
void conveyorStop();

//ultrasonic module
void initUltrasonicSensor();
float readDistance();
bool isTrashInPosition();

//metal detect module
void initMetalDetector();
int readProximitySensor();
bool isMetalDetected(int sensorValue);

//sorting system module
void handleIdle();
void handleConveyorRunning();
void handleTrashDetected();
void handleScanningMetal();
void handleSortMetal();
void handleSortNonMetal();
void handleReturning();
void printStatus();
const char* getStateName(SortState state);

#endif