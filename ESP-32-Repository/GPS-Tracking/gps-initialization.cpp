#include <Arduino.h>
#include "gps-tracking.h"

const int UART_NUM = 2; // UART number
const int BAUD_RATE = 9600; // BAUD rate
const int RX_PIN = 16; // GPIO pin for RX
const int TX_PIN = 17; // GPIO pin for TX

TinyGPSPlus gps;
HardwareSerial gpsSerial(UART_NUM);

bool initGPS() {
    gpsSerial.begin(BAUD_RATE, SERIAL_8N1, RX_PIN, TX_PIN);
    
    Serial.println("Neo6M GPS Initializing");
    unsigned long start = millis();
    while (millis() - start < 5000) { // wait for 5
        while (gpsSerial.available() > 0) {
            gps.encode(gpsSerial.read());
        }
        if (gps.location.isUpdated()) {
            return true;
        }
    }
    return false;
}