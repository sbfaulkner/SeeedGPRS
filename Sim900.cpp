//#include "Sim900.h"
//#include <Arduino.h>
//
//#define RX_PIN    7
//#define TX_PIN    8
//#define POWER_PIN 9
//
//#define MAXTIME   ((unsigned long)-1)
//
//Sim900::Sim900() : m_ss(RX_PIN, TX_PIN)
//{
//  m_powerState = SIM900_POWER_UNKNOWN;
//  m_commandState = SIM900_COMMAND_IDLE;
//  flushResponse();
//  m_waitUntil = MAXTIME;
//}
//
//void Sim900::begin()
//{
//  pinMode(POWER_PIN, OUTPUT);
//
//  m_ss.begin(19200);
//}
//
//sim900_event_type_t Sim900::nextEvent()
//{
//  switch (m_powerState)
//  {
//    case SIM900_POWER_UNKNOWN:
////      Serial.println("POWER: unknown");
//      detectPower();
//      break;
//
//    case SIM900_POWER_OFF:
//      Serial.println("POWER: off");
//      togglePower();
//      break;
//
//    case SIM900_POWER_ON:
//      if (m_commandState == SIM900_COMMAND_SENT)
//        return processResponse();
//
//      break;
//  }
//
//  return SIM900_EVENT_NONE;
//}
//
//sim900_event_type_t Sim900::processResponse()
//{
//  if (m_commandState != SIM900_COMMAND_RESPONSE_AVAILABLE)
//  {
//    if (millis() > m_waitUntil)
//    {
//      m_commandState = SIM900_COMMAND_IDLE;
//      return SIM900_EVENT_RESPONSE_TIMEOUT;
//    }
//
//    if (m_ss.available() > 0)
//    {
//      Serial.println("RESPONSE: data available");
//      char c = m_ss.read();
//      if (c == '\r')
//      {
//        *m_pBuffer++ = '\0';
//        if (m_responseBuffer[0])
//        {
//          m_commandState = SIM900_COMMAND_RESPONSE_AVAILABLE;
//          m_waitUntil = MAXTIME;
//        }
//        else
//        {
//          flushResponse();
//        }
//      }
//      else if (c != '\n')
//      {
//        Serial.print("RESPONSE: ");
//        Serial.println(c);
//        *m_pBuffer++ = c;
//      }
//    }
//  }
//
//  if (m_commandState == SIM900_COMMAND_RESPONSE_AVAILABLE)
//    return SIM900_EVENT_RESPONSE_AVAILABLE;
//
//  return SIM900_EVENT_NONE;
//}
//
//void Sim900::flushResponse()
//{
//  m_pBuffer = &m_responseBuffer[0];
//}
//
//const char* Sim900::getResponse()
//{
//  flushResponse();
//  m_commandState = SIM900_COMMAND_IDLE;
//  return m_responseBuffer;
//}
//
//void Sim900::detectPower()
//{
//  switch (m_commandState)
//  {
//    case SIM900_COMMAND_IDLE:
//      sendCommand("ATE0");
//      break;
//
//    case SIM900_COMMAND_SENT:
//      switch (processResponse())
//      {
//        case SIM900_EVENT_RESPONSE_AVAILABLE:
//          m_powerState = SIM900_POWER_ON;
//          break;
//
//        case SIM900_EVENT_RESPONSE_TIMEOUT:
//          m_powerState = SIM900_POWER_OFF;
//          break;
//      }
//      break;
//  }
//}
//
//void Sim900::togglePower()
//{
//  Serial.println("POWER: toggle");
//  digitalWrite(POWER_PIN, HIGH);
//  delay(2000);
//  digitalWrite(POWER_PIN, LOW);
//  delay(3000);
//  m_powerState = SIM900_POWER_UNKNOWN;
//}
//
//void Sim900::sendCommand(const char* command)
//{
//  Serial.print("SEND: ");
//  Serial.println(command);
//  m_ss.write(command);
//  m_ss.write('\r');
//  m_waitUntil = millis() + 1000;
//  m_commandState = SIM900_COMMAND_SENT;
//}

