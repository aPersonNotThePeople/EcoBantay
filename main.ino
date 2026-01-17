#include <Arduino.h>
#include <WiFi.h>
#include "GPS-Tracking/utils.h"

const char* SSID     = "wifi_ssid";      // replace with wifi
const char* PASSWORD = "wifi_password";

void setup() {
    // onStart
  Serial.begin(115200);
  delay(1000);

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
}