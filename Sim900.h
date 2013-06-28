//#ifndef __SIM900_H__
//#define __SIM900_H__
//
//#include "Sim900Shield.h"
//
//typedef enum Sim900PowerState {
//  SIM900_POWER_UNKNOWN = -1,
//  SIM900_POWER_OFF = 0,
//  SIM900_POWER_ON
//} sim900_power_state_t;
//
//typedef enum Sim900CommandState {
//  SIM900_COMMAND_IDLE = 0,
//  SIM900_COMMAND_SENT,
//  SIM900_COMMAND_RESPONSE_AVAILABLE
//} sim900_command_state_t;
//
//typedef enum Sim900EventType {
//  SIM900_EVENT_NONE = 0,
//  SIM900_EVENT_RESPONSE_AVAILABLE,
//  SIM900_EVENT_RESPONSE_TIMEOUT
//} sim900_event_type_t;
//
//class Sim900 : protected Sim900Shield
//{
//  public:
//    Sim900();
//  
//  public:
//    void begin();
//    sim900_event_type_t nextEvent();
//  
//  public:
//    void flushResponse();
//    const char* getResponse();
//  
//  //public:
//  //  inline size_t print(uint8_t c) { return m_ss.print(c); };
//  //  inline size_t print(const char* s) { return m_ss.print(s); };
//  //  inline uint8_t read() { return m_ss.read(); };
//  
//  protected:
//    SoftwareSerial m_ss;
//  
//    char m_responseBuffer[64];
//    char *m_pBuffer;
//  
//    sim900_power_state_t m_powerState;
//    sim900_command_state_t m_commandState;
//  
//    unsigned long m_waitUntil;
//  
//  protected:
//    void detectPower();
//    void togglePower();
//  
//    void sendCommand(const char* command);
//    sim900_event_type_t processResponse();
//};
//
//#endif // __SIM900_H__

