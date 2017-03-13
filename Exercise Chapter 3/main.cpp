#include "leds.h"
#include "counter.h"
#include "button.h"
#include "stopwatch.h"

int main() {
  Leds myLeds[4] = { Leds(1), Leds(2), Leds(3), Leds(4) };
  Stopwatch stopwatch;
  Button button;

  bool pressing = false;
  bool array[4];

  while(true) {
    if(button.read()) {
      if(!pressing) {
        stopwatch.getElapsedTimeMilliseconds() > 0 ? stopwatch.stop() : stopwatch.start();
        pressing = true;
      }
    }
    else {
      pressing = false;
    }

    Counter::convertValueToBinary(stopwatch.getElapsedTimeMilliseconds()/1000, array);
    for(int i = 0; i < 4; i++) {
      array[i] ? myLeds[i].forceOn() : myLeds[i].forceOff();
    }
  }
}
