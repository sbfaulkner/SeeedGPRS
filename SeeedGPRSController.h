#ifndef __SEEED_GPRS_CONTROLLER_H__
#define __SEEED_GPRS_CONTROLLER_H__

#include "SeeedGPRSShield.h"

typedef enum SeeedGPRSEventType {
  SEEED_GPRS_EVENT_TIMEOUT = -1,
  SEEED_GPRS_EVENT_NONE = 0,
  SEEED_GPRS_EVENT_RESPONSE
} seeed_gprs_event_type_t;

#define MAXTIME ((unsigned long)-1)

class SeeedGPRSController {
public:
  SeeedGPRSController(SeeedGPRSShield* pShield);

protected:
  SeeedGPRSShield* m_pShield;
  const char* m_pResponse;
  const char* m_pExpectation;
  unsigned long m_waitUntil;

public:
  seeed_gprs_event_type_t run();

  void send(const char* pCommand);
  const char* receive();

  void expect(const char* pResponse, unsigned long timeout);
  void wait(unsigned long time);
};

#endif // __SEEED_GPRS_CONTROLLER_H__
