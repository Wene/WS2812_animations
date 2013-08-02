// Uncomment this line if you have any interrupts that are changing pins - this causes the library to be a little bit more cautious
// #define FAST_SPI_INTERRUPTS_WRITE_PINS 1

// Uncomment this line to force always using software, instead of hardware, SPI (why?)
// #define FORCE_SOFTWARE_SPI 1

// Uncomment this line if you want to talk to DMX controllers
// #define FASTSPI_USE_DMX_SIMPLE 1

#include "FastSPI_LED2.h"

#define NUM_LEDS 240

CRGB leds[NUM_LEDS];

void setup() {
	// sanity check delay - allows reprogramming if accidently blowing power w/leds
   	delay(2000);

   	// For safety (to prevent too high of a power draw), the test case defaults to
   	// setting brightness to 25% brightness
   	LEDS.setBrightness(64);

   	LEDS.addLeds<WS2811, 13>(leds, NUM_LEDS);
}

void loop()
{
  //Test LED for LED in red
  for(int i = 0; i < NUM_LEDS; i++)
  {
    memset(leds, 0,  NUM_LEDS * sizeof(struct CRGB));
    leds[i].g = 128;
    LEDS.show();
    delay(250);
  }
  //Test LED for LED in green
  for(int i = 0; i < NUM_LEDS; i++)
  {
    memset(leds, 0,  NUM_LEDS * sizeof(struct CRGB));
    leds[i].r = 128;
    LEDS.show();
    delay(250);
  }
  //Test LED for LED in blue
  for(int i = 0; i < NUM_LEDS; i++)
  {
    memset(leds, 0,  NUM_LEDS * sizeof(struct CRGB));
    leds[i].b = 128;
    LEDS.show();
    delay(250);
  }
}
