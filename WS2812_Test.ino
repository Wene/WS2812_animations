#include "FastSPI_LED2.h"
#include "colorcircle.h"

// define the number of LEDs
#define NUM_LEDS 240

CRGB leds[NUM_LEDS];
ColorCircle Circle(leds, NUM_LEDS);

void setup() {
    // sanity check delay - allows reprogramming if accidently blowing power w/leds
    delay(1000);

    // setting brightness to 12%
    LEDS.setBrightness(31);

    LEDS.addLeds<WS2811, 13, GRB>(leds, NUM_LEDS); //GRB for the WS2812 color order

    //reset all the LEDs
    memset(leds, 0,  NUM_LEDS * sizeof(struct CRGB));
    LEDS.show();
}

void loop()
{
    Circle.doNextStep();
    LEDS.show();
    delay(50);
}
