#ifndef ESP32_LOG_BRIDGE_H
#define ESP32_LOG_BRIDGE_H

#include <Arduino.h>

void initEsp32LogBridge(uint32_t baudRate = 115200);
void sendEsp32Log(const char* level, const char* module, const char* message);
void sendEsp32StatusLog(const char* stateName, float distanceCm, int metalValue);

#endif
