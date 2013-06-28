#include <SoftwareSerial.h>

#include <SeeedGPRSShield.h>

SeeedGPRSShield shield;

void setup() {
  Serial.begin(115200);
  Serial.println("Initializing...");
  shield.begin();
  Serial.println("Initialized");
}

char buffer[64];
size_t count = 0;

void loop() {
  if (Serial.available() > 0) {
    char c = Serial.read();
    if (c == '\r') {
      buffer[count] = '\0';
      count = 0;
      shield.print(buffer);
      shield.print("\r");
    } else if (c != '\n') {
      buffer[count++] = c;
    }
  }

  const char* pLine = shield.readln();

  if (pLine) Serial.println(pLine);
}

