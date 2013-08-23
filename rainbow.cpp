#include "rainbow.h"

//Constructor
Rainbow::Rainbow(CRGB *Leds, int iLeds) : Animation(Leds, iLeds)
{
    iGlobalPos = 0;
}

//animate next step
void Rainbow::doNextStep()
{
    iGlobalPos++;
    if(iGlobalPos >= iLedCount)
    {
        iGlobalPos = 0;
    }

    const int iSectorSize = iLedCount / 6;
    int iRest = iLedCount % 6;

    for(int iSector = 0; iSector < 6; iSector++)
    {
        // add one step as long as rest is available. This may make the first gradients one longer than the last.
        int iCurSectorSize = iSectorSize;
        if(iRest > 0)
        {
            iRest--;
            iCurSectorSize++;
        }

        int iMaxColor = 140; //set maxColor lower than 255 to allow adding a ighting wave.
        int iStepSize = iMaxColor / iCurSectorSize;

        for(int iCurPos = 0; iCurPos < iCurSectorSize; iCurPos++)
        {
            int r = 0, g = 0, b = 0;
            int iColor = iStepSize * iCurPos;

            switch(iSector)
            {
            case 0: //red to yellow
                r = iMaxColor;
                g = iColor;
                break;
            case 1: //yellow to green
                r = iMaxColor - iColor;
                g = iMaxColor;
                break;
            case 2: //green to cyan
                g = iMaxColor;
                b = iColor;
                break;
            case 3: //cyan to blue
                g = iMaxColor - iColor;
                b = iMaxColor;
                break;
            case 4: //blue to magenta
                r = iColor;
                b = iMaxColor;
                break;
            case 5: //magenta to red
                r = iMaxColor;
                b = iMaxColor - iColor;
                break;
            }

            // set Position in relation to current rotation offset
            int iPos = iGlobalPos + (iCurPos + iSectorSize * iSector);
            if(iPos >= iLedCount)
            {
                iPos -= iLedCount;
            }

            pLEDS[iPos] = CRGB(r,g,b);
        }
    }
}
