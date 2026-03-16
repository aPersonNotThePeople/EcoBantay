#include "utils.h"

void initSortingMotor() {
  pinMode(STEPPER_MOTOR1_ENABLE, OUTPUT);
  pinMode(STEPPER_MOTOR1_DIR, OUTPUT);
  pinMode(STEPPER_MOTOR1_STP, OUTPUT);

  pinMode(STEPPER_MOTOR2_ENABLE, OUTPUT);
  pinMode(STEPPER_MOTOR2_DIR, OUTPUT);
  pinMode(STEPPER_MOTOR2_STP, OUTPUT);

  digitalWrite(STEPPER_MOTOR2_DIR, HIGH);
  
  sortMotorStop();
  
  Serial.println("Sorting Motors: Initialized");
  Serial.print("  Default Speed: ");
  Serial.println(DEFAULT_SPEED);
}

void returnTrapdoor(int stepper_motor_enable, int stepper_motor_stp, int solenoid_lock_pin) {
  // Divded by four to spin 90 degrees 
  openSolenoidLock(solenoid_lock_pin);
  digitalWrite(stepper_motor_enable, HIGH);
  for (int x = 0; x < STEPS_PER_REVOLUTION / (360/ROTATE_DEGREE); x++) {
    digitalWrite(stepper_motor_stp, HIGH);
    delayMicroseconds(DEFAULT_SPEED);
    digitalWrite(stepper_motor_stp, LOW);
    delayMicroseconds(DEFAULT_SPEED);
  }
  delay(500);
  closeSolenoidLock(solenoid_lock_pin);
  digitalWrite(stepper_motor_enable, LOW)
}


void sortMotorStop() {
  digitalWrite(STEPPER_MOTOR1_ENABLE, LOW);
  digitalWrite(STEPPER_MOTOR2_ENABLE, LOW);
  Serial.println("Sort Motor STOPPED");
}