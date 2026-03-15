#include "utils.h"

void initSolenoidLock() {
    pinMode(SOLENOID_LOCK1_RELAY);
    pinMode(SOLENOID_LOCK2_RELAY);
}

// open duration is in milliseconds
void openSolenoidLock(int solenoid_pin_number, float open_duration){
    digitalWrite(solenoid_pin_number, HIGH); //opens
    delay(constrain(open_duration, 500, MAXIMUM_OPEN_DURATION));
    digitalWrite(solenoid_pin_number, LOW); //closes
}