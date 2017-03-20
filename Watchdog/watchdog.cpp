#include "watchdog.h"

Watchdog::Watchdog() : Watchdog(0xFF) {}

Watchdog::Watchdog(long interval)
{
  LPC_WDT->WDMOD &= 1;
  LPC_WDT->WDTC = interval;
  feed();
}

Watchdog::~Watchdog()
{
  LPC_WDT->WDMOD = 0;
}

void Watchdog::feed()
{
  LPC_WDT->WDFEED = 0xAA;
  LPC_WDT->WDFEED = 0x55;
}

bool Watchdog::reset()
{
  bool temp = (LPC_WDT->WDMOD >> 2) & 1;
  LPC_WDT->WDMOD &= (1 << 2);
  return temp;
}
