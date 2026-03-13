#include "utils.h"

void initSolenoidLock() {
    pinMode(SOLENOID_LOCK1_RELAY);
    pinMode(SOLENOID_LOCK2_RELAY);
}

// open duration is in milliseconds
void openSolenoidLock(int solenoid_lock_number, float open_duration){
    switch (solenoid_lock_number) {
        case 1: 
            digitalWrite(SOLENOID_LOCK1_RELAY, HIGH); //opens
            delay(constrain(open_duration, 500, MAXIMUM_OPEN_DURATION));
            (SOLENOID_LOCK1_RELAY, LOW); //closes
        case 2:
            digitalWrite(SOLENOID_LOCK2_RELAY, HIGH); //opens
            delay(constrain(open_duration, 500, MAXIMUM_OPEN_DURATION));
            (SOLENOID_LOCK2_RELAY, LOW); //closes
    }
}