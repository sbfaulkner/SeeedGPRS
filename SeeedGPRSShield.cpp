#include "SeeedGPRSShield.h"

#define RX_PIN    7
#define TX_PIN    8
#define POWER_PIN 9

SeeedGPRSShield::SeeedGPRSShield() : m_ss(RX_PIN, TX_PIN) {
  m_count = 0;
}

void SeeedGPRSShield::begin() {
  pinMode(POWER_PIN, OUTPUT);
  m_ss.begin(19200);
  // SEND ATE0
  // WAIT FOR OK
  // IF TIMEOUT
  //   TOGGLE POWER
  //   RETRY
}

const char* SeeedGPRSShield::readln() {
  while (m_ss.available() > 0) {
    char c = m_ss.read();

    if (c == '\r') {
      m_buffer[m_count] = '\0';
      m_count = 0;
      return m_buffer;
    }

    if (c != '\n') m_buffer[m_count++] = c;
  }

  return NULL;
}

size_t SeeedGPRSShield::print(const char* s) {
  return m_ss.print(s);
}

void SeeedGPRSShield::setPowerPin(uint8_t value = HIGH) {
  digitalWrite(POWER_PIN, value);
}
