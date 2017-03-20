#include "counter.h"

Counter::Counter() {
  value = 0;
}

Counter::Counter(uint8_t start) {
  value = start;
}

Counter::~Counter() {
  // Nothing needed here
}

void Counter::increment() {
  value = value < 15 ? value + 1 : 0;
}

void Counter::decrement() {
  value = value > 0 ? value - 1 : 15;
}

uint8_t Counter::getCurrentValue() {
  return value;
}

void Counter::getCurrentValueBinary(bool array[]) {
  array[0] = value%2 == 1 ? true : false;
  array[1] = value%4 >= 2 ? true : false;
  array[2] = value%8 >= 4 ? true : false;
  array[3] = value >= 8 ? true : false;
}
