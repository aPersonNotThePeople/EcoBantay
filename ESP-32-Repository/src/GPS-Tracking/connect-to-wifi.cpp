#include <Arduino.h>
#include <WiFi.h>
#include "utils.h"

bool scanWiFi(char* ssid, char* password) {
  Serial.println("scan wifi networks...");
  int network_count = WiFi.scanNetworks();

  if (network_count == 0) {
    Serial.println("no networks found");
    return false;
  } 
  
  Serial.printf("%d networks found:\n", network_count);
  bool target_found = false;
  
  for (int i = 0; i < network_count; i++) {
    if (WiFi.SSID(i) == String(ssid)) {
      target_found = true;
      Serial.printf("target WiFi '%s' found!\n", ssid);
    }
    
    delay(10);
  }
  return target_found;
}

bool connectWiFi(char* ssid, char* password) {
  Serial.printf("Connecting to %s", ssid);
  WiFi.begin(ssid, password);

  int connection_timeout = 0;
  const int MAX_CONNECTION_ATTEMPTS = 20;

  while (WiFi.status() != WL_CONNECTED && connection_timeout < MAX_CONNECTION_ATTEMPTS) {
    delay(500);
    Serial.print(".");
    connection_timeout++;
  }

  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("\nWiFi connected!");
    Serial.print("IP address: ");
    Serial.println(WiFi.localIP());
    return true;
  } else {
    Serial.println("\nConnection failed - timeout");
    return false;
  }
}