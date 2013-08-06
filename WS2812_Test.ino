#include "FastSPI_LED2.h"

// define the number of LEDs
#define NUM_LEDS 120

CRGB leds[NUM_LEDS];

void setup() {
    // sanity check delay - allows reprogramming if accidently blowing power w/leds
    delay(1000);

    // setting brightness to 25%
    LEDS.setBrightness(63);

    LEDS.addLeds<WS2811, 13, GRB>(leds, NUM_LEDS); //GRB for the correct color order

    //reset all the LEDs
    memset(leds, 0,  NUM_LEDS * sizeof(struct CRGB));
    LEDS.show();
}

void loop()
{
    for(int i = 0; i < NUM_LEDS; i++)
    {
        memset(leds, 0,  NUM_LEDS * sizeof(struct CRGB));

        int pos = i;

        for(int color = 0; color < 6; color++)
        {
            CRGB curColor;
            switch(color)
            {
            case 0:
                curColor = CRGB(255,0,0);
                break;
            case 1:
                curColor = CRGB(0,255,0);
                break;
            case 2:
                curColor = CRGB(0,0,255);
                break;
            case 3:
                curColor = CRGB(200,200,0);
                break;
            case 4:
                curColor = CRGB(200,0,200);
                break;
            case 5:
                curColor = CRGB(0,200,200);
                break;
            }

            for(int j = 0; j < 10; j++)
            {
                if(pos - j >= 0)
                {
                    leds[pos - j] = curColor;
                }
                else
                {
                    leds[pos + NUM_LEDS - j] = curColor;
                }
                curColor.nscale8(180);
            }

            pos = pos + (NUM_LEDS / 6);
            if(pos >= NUM_LEDS)
            {
                pos = pos - NUM_LEDS;
            }
        }

        LEDS.show();
        delay(100);
    }
}
