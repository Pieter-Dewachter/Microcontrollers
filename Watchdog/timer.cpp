#include "timer.h"

Timer::Timer(int timeToElapse)
{
  NVIC_EnableIRQ(TIMER0_IRQn);
  LPC_TIM0->MR0 = timeToElapse;
  LPC_TIM0->MCR = 3;
  LPC_TIM0->TCR = 1;
  hasElapsed = false;
}

Timer::~Timer()
{
  NVIC_DisableIRQ(TIMER0_IRQn);
}

bool Timer::hasTimeElapsed()
{
  return hasElapsed;
}

void Timer::reset()
{
  hasElapsed = false;
  LPC_TIM0->TCR = 0;
  LPC_TIM0->TCR = 1;
}

extern "C"{
  void TIMER0_IRQHandler() {
    hasElapsed = true;

    LPC_TIM0->IR |= 1 << 0;
    assert(LPC_TIM0->IR == 0) ;
  }
}
