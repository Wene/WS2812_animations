#include "FastSPI_LED2.h"
#include "keypad.h"
#include "animation.h"
#include "rainbow.h"        //animation 0
#include "colorcircle.h"    //animation 1

// define the number of LEDs
#define NUM_LEDS 237

CRGB leds[NUM_LEDS];
Keypad Keys(8,9,11,10,6,7);
Animation *Anim;
int currentAnimation = 0;
int iBrightness = 100;
int iSpeed = 10;
bool bStandBy = false;

void setup() {
    //setting maximum brightness
    LEDS.setBrightness(iBrightness);

    LEDS.addLeds<WS2811, 12, GRB>(leds, NUM_LEDS); //GRB for the WS2812 color order

    //Rainbow *Ani = new Rainbow(leds, NUM_LEDS);
    Anim = new Rainbow(leds, NUM_LEDS);

    //reset all the LEDs
    memset(leds, 0,  NUM_LEDS * sizeof(struct CRGB));
    LEDS.show();
}

void loop()
{
    for(int i = 0; i < iSpeed; i++)
    {
        Keypad::key currentKey = Keys.checkKeys();
        switch(currentKey)
        {
        case Keypad::Next:
            delete Anim;
            currentAnimation++;
            if(currentAnimation > 1)    //reset
            {
                currentAnimation = 0;
            }
            switch(currentAnimation)
            {
            case 0:
                Anim = new Rainbow(leds, NUM_LEDS);
                break;
            case 1:
                Anim = new ColorCircle(leds, NUM_LEDS);
                break;
            }
            break;
        case Keypad::DimUp:
            if(iBrightness < 245)
            {
                iBrightness += 10;
                LEDS.setBrightness(iBrightness);
            }
            break;
        case Keypad::DimDown:
            if(iBrightness > 20)
            {
                iBrightness -= 10;
                LEDS.setBrightness(iBrightness);
            }
            break;
        case Keypad::Faster:
            if(iSpeed > 2)
            {
                iSpeed--;
            }
            break;
        case Keypad::Slower:
            if(iSpeed < 20)
            {
                iSpeed++;
            }
            break;
        case Keypad::OnOff:
            if(bStandBy)
            {
                bStandBy = false;
            }
            else
            {
                bStandBy = true;
            }
            break;
        }
        delay(10);
    }

    if(bStandBy)
    {
        memset(leds, 0,  NUM_LEDS * sizeof(struct CRGB));
        LEDS.show();
        Keys.blink();
    }
    else
    {
        Anim->doNextStep();
        LEDS.show();
    }
}
