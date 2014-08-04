#include "FastSPI_LED2.h"
#include "keypad.h"
#include "animation.h"
#include "rainbow.h"        //animation 0
#include "colorcircle.h"    //animation 1
#include "waves.h"          //animation 2
#include "swiss.h"          //animation 3

// define the number of LEDs
#define NUM_LEDS 236

CRGB leds[NUM_LEDS];
Keypad Keys(8,9,11,10,6,7);
Animation *Anim;
int currentAnimation = 0;
int iBrightness = 100;
int iSpeed = 10;
bool bStandBy = false;
bool bDebug = false;

void setup() {
    //setting maximum brightness
    LEDS.setBrightness(iBrightness);

    LEDS.addLeds<WS2811, 12, GRB>(leds, NUM_LEDS); //GRB for the WS2812 color order

    //Setup default (startup) animation
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
            if(bDebug && bStandBy)    //single step for debugging
            {
                Anim->doNextStep();
                LEDS.show();
            }
            else
            {
                delete Anim;
                currentAnimation++;
                if(currentAnimation > 3)    //reset
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
                case 2:
                    Anim = new Waves(leds, NUM_LEDS);
                    break;
                case 3:
                    Anim = new Swiss(leds, NUM_LEDS);
                    break;
                }
            }
            break;
        case Keypad::DimUp:
            if(iBrightness < 245)
            {
                iBrightness += 10;
                LEDS.setBrightness(iBrightness);
            }
            break;
        case Keypad::DimMax:
            iBrightness = 250;
            LEDS.setBrightness(iBrightness);
            break;
        case Keypad::DimDown:
            if(iBrightness > 20)
            {
                iBrightness -= 10;
                LEDS.setBrightness(iBrightness);
            }
            break;
        case Keypad::DimMin:
            iBrightness = 20;
            LEDS.setBrightness(iBrightness);
            break;
        case Keypad::Faster:
            if(iSpeed > 2)
            {
                iSpeed--;
            }
            break;
        case Keypad::Fastest:
            iSpeed = 2;
            break;
        case Keypad::Slower:
            if(iSpeed < 20)
            {
                iSpeed++;
            }
            break;
        case Keypad::Slowest:
            iSpeed = 20;
            break;
        case Keypad::OnOff:
            if(bStandBy)
            {
                bStandBy = false;
                bDebug = false;
            }
            else
            {
                bStandBy = true;
                memset(leds, 0,  NUM_LEDS * sizeof(struct CRGB));
                LEDS.show();
            }
            break;
        case Keypad::Debug:
            bDebug = true;
            bStandBy = true;
            break;
        }
        delay(10);
    }

    if(bStandBy)
    {
        Keys.blink();
    }
    else
    {
        Anim->doNextStep();
        LEDS.show();
    }
}
