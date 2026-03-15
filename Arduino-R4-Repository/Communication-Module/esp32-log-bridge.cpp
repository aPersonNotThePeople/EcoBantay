#include "esp32-log-bridge.h"

// TODO: Move UART port selection (Serial1) into shared config.
static HardwareSerial* gLogPort = &Serial1;

void initEsp32LogBridge(uint32_t baudRate) {
  gLogPort->begin(baudRate);
}

void sendEsp32Log(const char* level, const char* module, const char* message) {
  if (level == nullptr || module == nullptr || message == nullptr) {
    return;
  }

  gLogPort->print("LOG|");
  gLogPort->print(millis());
  gLogPort->print('|');
  gLogPort->print(level);
  gLogPort->print('|');
  gLogPort->print(module);
  gLogPort->print('|');
  gLogPort->println(message);
}

void sendEsp32StatusLog(const char* stateName, float distanceCm, int metalValue) {
  if (stateName == nullptr) {
    return;
  }

  char message[96];
  snprintf(
    message,
    sizeof(message),
    "state=%s,distance=%.2f,metal=%d",
    stateName,
    distanceCm,
    metalValue
  );

  sendEsp32Log("INFO", "SORTING", message);
}
