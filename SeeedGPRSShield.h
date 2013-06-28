#ifndef __SEEED_GPRS_SHIELD_H__
#define __SEEED_GPRS_SHIELD_H__

#include <SoftwareSerial.h>
#include <Arduino.h>

class SeeedGPRSShield {
public:
  SeeedGPRSShield();

protected:
  SoftwareSerial m_ss;
  char m_buffer[64];
  size_t m_count;

public:
  void begin();

public:
  const char* readln();
  size_t print(const char* s);

public:
  void setPowerPin(uint8_t value);
};

#endif // __SEEED_GPRS_SHIELD_H__

