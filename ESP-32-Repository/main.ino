#include <Arduino.h>
#include <WiFi.h>
#include "src/GPS-Tracking/utils.h"

const char* SSID     = "wifi_ssid";      // replace with wifi
const char* PASSWORD = "wifi_password";

void setup() {
    //onInit
  Serial.begin(115200);
  delay(1000);

  if (initGPS()) {
    Serial.println("GPS initialized successfully!");
  } else {
    Serial.println("GPS initialization failed - will keep trying");
  }

  // WiFi setup
  WiFi.mode(WIFI_STA);
  WiFi.disconnect(true);
  delay(500);

  if(scanWiFi(SSID, PASSWORD)) {
      connectWiFi(SSID, PASSWORD);
  }
  else {
      Serial.println("WiFI not found");
  }
}

void loop() {
    // onRun
  fetchLocation(gpsSerial, gps);
  delay(1000); // Read GPS every second
}