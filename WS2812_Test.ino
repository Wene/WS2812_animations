#include "FastSPI_LED2.h"
#include "colorcircle.h"
#include "rainbow.h"
#include "animation.h"

// define the number of LEDs
#define NUM_LEDS 100

CRGB leds[NUM_LEDS];
//ColorCircle Animation(leds, NUM_LEDS);
//Rainbow Animation(leds, NUM_LEDS);
Animation *Anim;
int counter = 0;

void setup() {
    // sanity check delay - allows reprogramming if accidently blowing power w/leds
    delay(1000);

    // setting brightness to 12%
    LEDS.setBrightness(20);

    LEDS.addLeds<WS2811, 13, GRB>(leds, NUM_LEDS); //GRB for the WS2812 color order

    //Rainbow *Ani = new Rainbow(leds, NUM_LEDS);
    Anim = new Rainbow(leds, NUM_LEDS);

    //reset all the LEDs
    memset(leds, 0,  NUM_LEDS * sizeof(struct CRGB));
    LEDS.show();
}

void loop()
{
    counter++;
    if(counter == 600)
    {
        delete Anim;
        Anim = new ColorCircle(leds, NUM_LEDS);
    }
    if(counter >= 1200)
    {
        delete Anim;
        Anim = new Rainbow(leds, NUM_LEDS);
        counter = 0;
    }
    Anim->doNextStep();
    LEDS.show();
    delay(100);
}
