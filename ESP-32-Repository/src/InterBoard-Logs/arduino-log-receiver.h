#ifndef ARDUINO_LOG_RECEIVER_H
#define ARDUINO_LOG_RECEIVER_H

#include <Arduino.h>

// TODO: Move UART2 rxPin/txPin defaults into shared config.
void initArduinoLogReceiver(uint32_t baudRate = 115200, int rxPin = 16, int txPin = 17);
void processArduinoLogReceiver();

#endif
