#include <Arduino.h>
#include <TinyGPSPlus.h>
#include "gps-tracking.h"

void fetchLocation(HardwareSerial& gpsSerial, TinyGPSPlus& gps) {
    while (gpsSerial.available() > 0) {
        gps.encode(gpsSerial.read());
    }

    if (gps.location.isUpdated()) {
        // sample output but will be adjusted
        Serial.print("Latitude= ");
        Serial.print(gps.location.lat(), 6);
        Serial.print(" Longitude= ");
        Serial.println(gps.location.lng(), 6);
    }
}