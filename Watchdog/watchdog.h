#ifndef WATCHDOG_H
#define WATCHDOG_H

#include "LPC17xx.h"

class Timer {
  public:
    Watchdog();
    Stopwatch(int);
    ~Watchdog();
    void feed();
    bool reset();
};

#endif
