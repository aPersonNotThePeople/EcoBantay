#ifndef UTILS_H
#define UTILS_H

# include "..\..\config.h"
#include <Arduino.h>

//system states
enum SortState {
  IDLE,
  CONVEYOR_RUNNING,
  TRASH_DETECTED,
  SCANNING_METAL,
  SORT_METAL,
  SORT_NON_METAL,
  RETURNING
};

//global
extern SortState currentState;
extern unsigned long stateStartTime;
extern bool metalDetected;

//ultrasonic
void initUltrasonicSensor();
float readDistanceFromUART();
float readDistance();
bool isTrashInPosition();

//metel detection
void initMetalDetector();
int readProximitySensor();
bool isMetalDetected(int sensorValue);

//conveyor motor
void initConveyorSystem();
void conveyorStart();
void conveyorStop();

//sorting motor
void initSortingMotor();
void returnTrapdoor(int stepper_motor_enable, int stepper_motor_stp, int solenoid_lock_pin);
void sortMotorStop();

// solenoid lock
void initSolenoidLock();
void openAndCloseSolenoidLock(int solenoid_pin_number, int open_duration);
void openSolenoidLock(int solenoid_lock_number);
void closeSolenoidLock(int solenoid_lock_number);

//sorting system
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
