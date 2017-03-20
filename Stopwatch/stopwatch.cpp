#include "LPC17xx.h"
#include "stopwatch.h"

Stopwatch::Stopwatch() : Stopwatch(0) {}

Stopwatch::Stopwatch(int startOffset) : counter(startOffset) {
  NVIC_EnableIRQ(TIMER0_IRQn);
  LPC_TIM0->MR0 = 24000;
  LPC_TIM0->MCR = 3;

  counterPointer = &counter;
}

Stopwatch::~Stopwatch() {
  NVIC_DisableIRQ(TIMER0_IRQn);
}

void Stopwatch::start() {
  LPC_TIM0->TCR = 1;
}

void Stopwatch::stop() {
  LPC_TIM0->TCR = 0;
}

int Stopwatch::getElapsedTimeMilliseconds() {
  return counter.getCurrentValue();
}

// Where to put this?
extern "C"{
  void TIMER0_IRQHandler() {
    (*counterPointer).increment();

    LPC_TIM0->IR |= 1 << 0;
    assert(LPC_TIM0->IR == 0) ;
  }
}
