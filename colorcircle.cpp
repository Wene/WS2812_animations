#include "colorcircle.h"

//Constructor
ColorCircle::ColorCircle(CRGB *Leds, int iLeds) : Animation(Leds, iLeds)
{
    iGlobalPos = 0;
}

//animate next step
void ColorCircle::doNextStep()
{
    iGlobalPos++;
    if(iGlobalPos >= iLedCount)
    {
        iGlobalPos = 0;
    }

    int iPos = iGlobalPos;

    memset(pLEDS, 0,  iLedCount * sizeof(struct CRGB));

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
            if(iPos - j >= 0)
            {
                pLEDS[iPos - j] = curColor;
            }
            else
            {
                pLEDS[iPos + iLedCount - j] = curColor;
            }
            curColor.nscale8(180);
        }

        iPos = iPos + (iLedCount / 6);
        if(iPos >= iLedCount)
        {
            iPos -= iLedCount;
        }
    }
}
