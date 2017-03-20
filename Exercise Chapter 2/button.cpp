#include <LPC17xx.h>
#include "button.h"

Button::Button() {
  LPC_PINCON->PINMODE1 |= 3; // Enabling the pull-down instead of the pull-up resistor
  LPC_GPIO0->FIODIR &= ~(1 << 16); // Configuring the pin as output
	LPC_GPIO0->FIOMASK &= ~(1 << 16);
}

Button::~Button() {
  LPC_GPIO0->FIOMASK &= 0;
}

bool Button::read() {
  return (LPC_GPIO0->FIOPIN >> 16) & 1;
}
