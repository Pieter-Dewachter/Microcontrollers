#include <LPC17xx.h>
#include "leds.h"

Leds::Leds(uint8_t myLed) {
  selectedLed = myLed;
  switch(myLed) {
    case 1:
      pin = 18;
      break;
    case 2:
      pin = 20;
      break;
    case 3:
      pin = 21;
      break;
    case 4:
      pin = 23;
      break;
  }
  LPC_GPIO1->FIODIR |= (1 << pin);
	LPC_GPIO1->FIOMASK &= ~(1 << pin);
}

Leds::~Leds() {
  LPC_GPIO1->FIOMASK &= 0;
}

void Leds::forceOff() {
  LPC_GPIO1->FIOCLR |= (1 << pin);
}

void Leds::forceOn() {
  LPC_GPIO1->FIOSET |= (1 << pin);
}
