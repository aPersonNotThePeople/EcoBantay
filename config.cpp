#include "config.h"
const char* SSID = "SSID";
const char* PASSWORD = "Password";

// Firebase Credentials
#define Web_API_KEY "API KEY"
#define DATABASE_URL "DATABASE URL"
#define USER_EMAIL "USER EMAIL"
#define USER_PASS "USER PASS"

// Firebase Variables
const int FIREBASE_DATABASE_SEND_INTERVAL = 10000; // 10 seconds

// Tresholds
const int METAL_THRESHOLD = 500;
const float DETECTION_DISTANCE = 10.0; // 10 cm

// Durations
extern const int SCAN_DURATION = 500;
extern const int SORT_DURATION = 1500;
extern const int RETURN_DURATION = 1000;

// Stepper Motor Speed
extern const int DEFAULT_SPEED = 2000; // 2000mw

// Pin Config
const int INDUCTIVE_PROXIMITY_RX = A0;

const int STEPPER_MOTOR1_ENABLE = A1;
const int STEPPER_MOTOR2_ENABLE = A2;

const int SOLENOID_LOCK1_ENABLE = A3;
const int SOLENOID_LOCK2_ENABLE = A4;

// For Communication with ESP32
const int RX = 0;
const int TX - 1;

// For the Waterproof Ultrasonic Proximity Sensor
const int ULTRASONIC_RECEIVER = 2;
const int ULTRASONIC_TRANSMITTER = 3;

// Stepper Motors Control
const int STEPPER_MOTOR1_DIR = 4;
const int STEPPER_MOTOR1_STP = 5;
const int STEPPER_MOTOR2_DIR = 6;
const int 
STEPPER_MOTOR2_STP = 7;

// Conveyors
const int CONVEYOR_MOTORS_IN1 = 8;
const int CONVEYOR_MOTORS_IN2 = 9;
const int CONVEYOR_MOTORS_ENABLE = 10;

// Ultrasonic Proximity Sensor
const int ULTRASONIC_ECHO = 11;
const int ULTRASONIC_TRIGGER = 12;

#endif