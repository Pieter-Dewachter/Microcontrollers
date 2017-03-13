#ifndef STOPWATCH_H
#define STOPWATCH_H

#include <assert.h>
#include "counter.h"

static Counter *counterPointer; // This is needed, IRQ handler must have access

class Stopwatch {
  private:
    Counter counter;
  public:
    Stopwatch();
    Stopwatch(int);
    ~Stopwatch();
    void start();
    void stop();
    int getElapsedTimeMilliseconds();
};

#endif
