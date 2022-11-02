#include <Wire.h>
#include "SparkFun_Qwiic_Relay.h"


struct DEV_Fireplace : Service::Switch {
    uint8_t switchPin;
    Qwiic_Relay relay;
    SpanCharacteristic *power;

  DEV_Fireplace(uint8_t switchPin, byte addr) : Service::Switch() {
    power = new Characteristic::On(false, true);
    Wire.begin();
    relay.begin(addr);
    this->switchPin = switchPin;

    Serial.print(F("Initializing Fireplace Controller\n"));
    Serial.print(F("Power Relay on I2C address: "));
    Serial.print(addr);
    Serial.print("\n");
    Serial.print(F("Power switch on pin: "));
    Serial.print(switchPin);
    Serial.print("\n");
    Serial.print(F("Initial power state: "));
    Serial.print(power->getVal());
    Serial.print("\n");
    
    new SpanButton(switchPin);
    relay.commandRelay(power->getVal());
  }

  boolean update() {
    LOG1(F("In update function new power state: "));
    LOG1(power->getNewVal());
    LOG1("\n");

    relay.commandRelay(power->getNewVal());
    return true;
  }

  void button(int pin, int pressType) override {
    if (pin == switchPin) {
      power->setVal(!(power->getVal()));
      LOG1(F("Power swich pressed: "));
      LOG1(F("New power state: "));
      LOG1(power->getVal());
      LOG1("\n");
      relay.commandRelay(power->getVal());
    }
  }
};