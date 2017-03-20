#ifndef TIMER_H
#define TIMER_H

#include "LPC17xx.h"

bool hasElapsed;

class Timer {
  public:
    Timer(int);
    ~Timer();
    bool hasTimeElapsed();
    void reset();
};

#endif
