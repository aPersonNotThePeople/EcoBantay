#ifndef CONFIG
#define CONFIG

// Wifi Credentials
extern const char* SSID;
extern const char* PASSWORD;

// Firebase Credentials
#define Web_API_KEY "API KEY"
#define DATABASE_URL "DATABASE URL"
#define USER_EMAIL "USER EMAIL"
#define USER_PASS "USER PASS"

// Firebase Variables
extern const int FIREBASE_DATABASE_SEND_INTERVAL;

// Tresholds
extern const int METAL_THRESHOLD;
extern const float DETECTION_DISTANCE;

// Durations
extern const int SCAN_DURATION;
extern const int SORT_DURATION;
extern const int RETURN_DURATION;

// Stepper Motor Variables
extern const int DEFAULT_SPEED;
extern const int STEPS_PER_REVOLUTION;
extern const int ROTATE_DEGREE;

// Pin Config
extern const int INDUCTIVE_PROXIMITY_RX;

extern const int STEPPER_MOTOR1_ENABLE;
extern const int STEPPER_MOTOR2_ENABLE;

// Solenoid
extern const int SOLENOID_LOCK1_RELAY;
extern const int SOLENOID_LOCK2_RELAY;
extern const float MAXIMUM_OPEN_DURATION;

// For Communication with ESP32
extern const int RX;
extern const int TX;

// For the Waterproof Ultrasonic Proximity Sensor
extern const int ULTRASONIC_RECEIVER;
extern const int ULTRASONIC_TRANSMITTER;

// Stepper Motors Control
extern const int STEPPER_MOTOR1_DIR;
extern const int STEPPER_MOTOR1_STP;
extern const int STEPPER_MOTOR2_DIR;
extern const int 
STEPPER_MOTOR2_STP;

// Conveyors
extern const int CONVEYOR_MOTORS_IN1;
extern const int CONVEYOR_MOTORS_IN2;
extern const int CONVEYOR_MOTORS_ENABLE;

// Ultrasonic Proximity Sensor
extern const int ULTRASONIC_ECHO;
extern const int ULTRASONIC_TRIGGER;

#endif