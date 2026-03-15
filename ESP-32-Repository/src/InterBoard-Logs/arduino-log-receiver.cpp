#include "arduino-log-receiver.h"

// TODO: Move UART2 instance selection into shared board configuration.
static HardwareSerial ArduinoLogSerial(2);
static String lineBuffer;

static void handleLogLine(const String& line) {
  if (!line.startsWith("LOG|")) {
    Serial.print("[R4 RAW] ");
    Serial.println(line);
    return;
  }

  int p1 = line.indexOf('|');
  int p2 = line.indexOf('|', p1 + 1);
  int p3 = line.indexOf('|', p2 + 1);
  int p4 = line.indexOf('|', p3 + 1);

  if (p1 < 0 || p2 < 0 || p3 < 0 || p4 < 0) {
    Serial.print("[R4 MALFORMED] ");
    Serial.println(line);
    return;
  }

  String timestamp = line.substring(p1 + 1, p2);
  String level = line.substring(p2 + 1, p3);
  String module = line.substring(p3 + 1, p4);
  String message = line.substring(p4 + 1);

  Serial.print("[R4 ");
  Serial.print(level);
  Serial.print("] t=");
  Serial.print(timestamp);
  Serial.print(" module=");
  Serial.print(module);
  Serial.print(" msg=");
  Serial.println(message);
}

void initArduinoLogReceiver(uint32_t baudRate, int rxPin, int txPin) {
  // TODO: Source UART RX/TX defaults from shared config instead of header defaults.
  ArduinoLogSerial.begin(baudRate, SERIAL_8N1, rxPin, txPin);
  lineBuffer.reserve(256);
}

void processArduinoLogReceiver() {
  while (ArduinoLogSerial.available() > 0) {
    char c = static_cast<char>(ArduinoLogSerial.read());

    if (c == '\r') {
      continue;
    }

    if (c == '\n') {
      if (lineBuffer.length() > 0) {
        handleLogLine(lineBuffer);
        lineBuffer = "";
      }
      continue;
    }

    if (lineBuffer.length() < 250) {
      lineBuffer += c;
    }
  }
}
