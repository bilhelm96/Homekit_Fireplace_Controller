#include <Arduino.h>
#include <HomeSpan.h>
#include "DEV_Identify.h"
#include "DEV_Fireplace.h"


//////////////////////////////////////////
// Constants
//////////////////////////////////////////
#if defined ARDUINO_LOLIN_S2_MINI
  const uint8_t LED_PIN = 15;
#elif defined (ARDUINO_ESP32S2_THING_PLUS) || (ARDUINO_ESP32_THING_PLUS_C)
  const uint8_t LED_PIN = 13;
#else
 #error "Board not defined"
#endif
const uint8_t SWITCH_PIN = 34;
const byte RELAY_ADDR = 0x18;


///////////////////////////////
// Arduino setup and loop
///////////////////////////////
void setup() {
  Serial.begin(115200);
  homeSpan.setStatusPin(LED_PIN);
  homeSpan.begin(Category::Heaters, "Fireplace");

  new SpanAccessory();
    new DEV_Identify("Fireplace", "Heat-N-Glo", "Not Sure", "6000TVFL", "1.0", 4);
    new Service::HAPProtocolInformation();
      new Characteristic::Version("1.1.0");
    new DEV_Fireplace(SWITCH_PIN, RELAY_ADDR);

}

void loop() {
  homeSpan.poll();
}
