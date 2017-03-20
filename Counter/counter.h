#ifndef COUNTER_H
#define COUNTER_H

#include <stdint.h>

class Counter {
  private:
      uint8_t value;
  public:
      Counter();
      Counter(uint8_t);
      ~Counter();
      void increment();
      void decrement();
      uint8_t getCurrentValue();
      void getCurrentValueBinary(bool[]);
};

#endif
