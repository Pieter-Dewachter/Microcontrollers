#ifndef COUNTER_H
#define COUNTER_H

class Counter {
  private:
      int value;
  public:
      Counter();
      Counter(int);
      ~Counter();
      void increment();
      int getCurrentValue();
      static void convertValueToBinary(int, bool[]);
};

#endif
