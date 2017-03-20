#include "counter.h"

Counter::Counter() {
  value = 0;
}

Counter::Counter(int start) {
  value = start;
}

Counter::~Counter() {
  // Nothing needed here
}

void Counter::increment() {
  value++;
}

int Counter::getCurrentValue() {
  return value;
}

void Counter::convertValueToBinary(int value, bool array[]) {
  array[0] = value%2 == 1 ? true : false;
  array[1] = value%4 >= 2 ? true : false;
  array[2] = value%8 >= 4 ? true : false;
  array[3] = value >= 8 ? true : false;
}
