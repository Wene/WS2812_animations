#include "swiss.h"

//Constructor
Swiss::Swiss(CRGB *Leds, int iLeds) : Animation(Leds, iLeds)
{
    iPos = 0;
    iCrossCount = 5;        //count of crosses
    iMaxPos = ((iLedCount / 3) / iCrossCount) * iCrossCount;    //strip the rest off
    iSpace = iMaxPos / iCrossCount;

}

//animate next step
void Swiss::doNextStep()
{
    memset(pLEDS, 0,  iLedCount * sizeof(struct CRGB)); //black out all LEDs

    iPos++;
    if(iPos >= iMaxPos)
    {
        iPos = 0;
    }

    for(int iLED = 0; iLED <= iMaxPos * 3; iLED++)
    {
        int iGlobalPos = iLED + iPos;
        if(iGlobalPos >= iMaxPos * 3)
        {
            iGlobalPos -= iMaxPos * 3;
        }

        if(iGlobalPos < iMaxPos || iGlobalPos >= 2 * iMaxPos) //top and bottom row
        {
            if(iLED % iSpace != 0)
            {
                pLEDS[iGlobalPos].setRGB(255,0,0); //set all LEDs which are not part of a cross to red
            }
            else
            {
                pLEDS[iGlobalPos].setRGB(255,255,255); //paint the cross white
            }
        }
        else //middle row
        {
            if((iLED - 1) % iSpace == 0 || iLED % iSpace == 0 || (iLED + 1) % iSpace == 0)
            {
                pLEDS[iGlobalPos].setRGB(255,255,255);
            }
            else
            {
                pLEDS[iGlobalPos].setRGB(255,0,0);
            }
        }
    }
}

