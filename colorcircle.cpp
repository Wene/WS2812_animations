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
    int iRest = iLedCount % 6;
    const int iSector = iLedCount / 6;
    const int iColorLength = iSector - 5;

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

        for(int iColorPos = 0; iColorPos < iColorLength; iColorPos++)
        {
            if(iPos - iColorPos >= 0)
            {
                pLEDS[iPos - iColorPos] = curColor;
            }
            else
            {
                pLEDS[iPos + iLedCount - iColorPos] = curColor;
            }
            curColor.nscale8(200);
        }

        if(iRest > 0)
        {
            iPos++;
            iRest--;
        }

        iPos += iSector;
        if(iPos >= iLedCount)
        {
            iPos -= iLedCount;
        }
    }
}
