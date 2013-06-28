#include "SeeedGPRSController.h"

SeeedGPRSController::SeeedGPRSController(SeeedGPRSShield* pShield) {
  m_pShield = pShield;
  m_pResponse = NULL;
  m_pExpectation = NULL;
  m_waitUntil = MAXTIME;
}

seeed_gprs_event_type_t SeeedGPRSController::run() {
  if (m_pResponse == NULL) m_pResponse = m_pShield->readln();

  if (m_pResponse && m_pExpectation && strcmp(m_pResponse, m_pExpectation) != 0) m_pResponse = NULL;

  if (m_pResponse) {
    m_waitUntil = MAXTIME;
    return SEEED_GPRS_EVENT_RESPONSE;
  }

  if (millis() > m_waitUntil) {
    m_waitUntil = MAXTIME;
    return SEEED_GPRS_EVENT_TIMEOUT;
  }

  return SEEED_GPRS_EVENT_NONE;
}

void SeeedGPRSController::send(const char* pCommand) {
  m_pShield->print(pCommand);
  m_pShield->print("\r");
}

const char* SeeedGPRSController::receive() {
  const char* pResponse = m_pResponse;

  m_pResponse = NULL;

  return pResponse;
}

void SeeedGPRSController::expect(const char* pResponse, unsigned long timeout = MAXTIME) {
  m_pExpectation = pResponse;

  if (timeout == MAXTIME) {
    m_waitUntil = timeout;
  } else {
    wait(timeout);
  }
}

void SeeedGPRSController::wait(unsigned long time) {
  m_waitUntil = millis() + time;
}