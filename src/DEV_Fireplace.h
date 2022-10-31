#include <Wire.h>
#include "SparkFun_Qwiic_Relay.h"


struct DEV_Fireplace : Service::Switch {
    uint8_t switchPin;
    byte addr;
    Qwiic_Relay relay;
    SpanCharacteristic *power;

  DEV_Fireplace(uint8_t switchPin, byte addr) : Service::Switch() {
    power = new Characteristic::On(0, true);
    Wire.begin();
    relay.begin(addr);
    this->switchPin = switchPin;
    
    new SpanButton(switchPin);
    power->setVal(1-power->getVal());
  }

  boolean update() {
    if (power->getNewVal()) {
      relay.turnRelayOn();
    }
    else {
      relay.turnRelayOff();
    }
    return true;
  }

  void button(int pin, int pressType) override {
    if (pin == switchPin) {
      power->setVal(1-power->getVal());
    }
  }
};