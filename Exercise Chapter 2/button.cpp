#include <LPC17xx.h>
#include "button.h"

Button::Button() {
  LPC_GPIO0->FIODIR |= (1 << 16);
	LPC_GPIO0->FIOMASK &= ~(1 << 16);
}

Button::~Button() {
  LPC_GPIO0->FIOMASK &= 0;
}

bool Button::read() {
  return (LPC_GPIO0->FIOPIN >> 16) & 1;
}
