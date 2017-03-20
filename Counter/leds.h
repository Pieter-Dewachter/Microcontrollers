#ifndef LEDS_H
#define LEDS_H

#include <stdint.h>

class Leds {
  private:
      uint8_t selectedLed, pin;
  public:
      Leds(uint8_t);
      ~Leds();
      void forceOff();
      void forceOn();
};

#endif
