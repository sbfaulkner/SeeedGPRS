#include <SoftwareSerial.h>

#include <SeeedGPRSController.h>

SeeedGPRSShield shield;
SeeedGPRSController controller(&shield);

enum { IDLE_STATE = 0, WAITING_STATE, SLEEPING_STATE, POWERON_STATE, WARMUP_STATE } state = IDLE_STATE;

void setup() {
  Serial.begin(115200);
  Serial.println("Initializing...");
  shield.begin();
  Serial.println("Shield initialized");
}

void loop() {
  seeed_gprs_event_type_t event = controller.run();

  switch (event) {
    case SEEED_GPRS_EVENT_NONE:
      if (state == IDLE_STATE) {
        controller.send("ATE0");
        controller.expect("OK", 1000);
        state = WAITING_STATE;
      }
      break;

    case SEEED_GPRS_EVENT_RESPONSE:
      if (state == WAITING_STATE) {
        Serial.print("Response received: ");
        Serial.println(controller.receive());
        controller.wait(3000);
        state = SLEEPING_STATE;
      } else {
        Serial.print("Unsolicited response received: ");
        Serial.println(controller.receive());
      }
      break;

    case SEEED_GPRS_EVENT_TIMEOUT:
      if (state == WAITING_STATE) {
        Serial.println("Response TIMEOUT!");
        shield.setPowerPin(HIGH);
        controller.wait(2000);
        state = POWERON_STATE;
      } else if (state == SLEEPING_STATE) {
        state = IDLE_STATE;
      } else if (state == POWERON_STATE) {
        shield.setPowerPin(LOW);
        controller.wait(3000);
        state = WARMUP_STATE;
      } else if (state == WARMUP_STATE) {
        state = IDLE_STATE;
      } else {
        Serial.println("Unexpected TIMEOUT!");
      }
      break;

    default:
      Serial.print("Unknown event: ");
      Serial.println(event);
      break;
  }
}

