#include "leds.h"
#include "counter.h"
#include "button.h"

void approx_wait(uint32_t milliseconds) {
	for (uint32_t j = 0; j < milliseconds; j++) {
		for (volatile uint32_t i = 0; i < 7320; i++);
	}
}

// Running light implementation
/* int main() {
	Leds myLeds[4] = { Leds(1), Leds(2), Leds(3), Leds(4) };
	int currentLed = 0;
	int direction = 1;

  while(true) {
		for(int i = 0; i < 4; i++)
		{
			i == currentLed ? myLeds[i].forceOn() : myLeds[i].forceOff();
		}

    currentLed += direction;

		if(currentLed == -1 || currentLed == 4)
		{
			direction = -direction;
			currentLed += 2 * direction;
		}
		approx_wait(500);
  }
} */

// Counter implementation
/* int main() {
	Leds myLeds[4] = { Leds(1), Leds(2), Leds(3), Leds(4) };
	Counter myCounter;
	bool array[4];

	while(true) {
			myCounter.getCurrentValueBinary(array);
			for(int i = 0; i < 4; i++) {
					array[i] ? myLeds[i].forceOn() : myLeds[i].forceOff();
			}
			myCounter.increment();
			approx_wait(500);
	}
} */

// Button reading implementation
int main() {
	Leds myLeds[4] = { Leds(1), Leds(2), Leds(3), Leds(4) };
	Counter myCounter;
	Button myButton;
	bool array[4];
	bool wasOn = false;

	while(true) {
			myCounter.getCurrentValueBinary(array);
			for(int i = 0; i < 4; i++) {
					array[i] ? myLeds[i].forceOn() : myLeds[i].forceOff();
			}
			if(myButton.read() && !wasOn) {
				myCounter.increment();
				wasOn = true;
			}
			else if(!myButton.read()) {
				wasOn = false;
			}
	}
}
