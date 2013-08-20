#include "rainbow.h"

//Constructor
Rainbow::Rainbow(CRGB *Leds, int iLeds = 120)
{
    iLedCount = iLeds;  
    iGlobalPos = 0;
    pLEDS = Leds;
}

//animate next step
void Rainbow::doNextStep()
{
//    iGlobalPos++;
//    if(iGlobalPos >= iLedCount)
//    {
//        iGlobalPos = 0;
//    }

//    int iPos = iGlobalPos;

    memset(pLEDS, 0, iLedCount * sizeof(struct CRGB));

    const int iSectorSize = iLedCount / 6;
    int iRest = iLedCount % 6;

    for(int iSector = 0; iSector < 6; iSector++)
    {
        int iCurSectorSize = iSectorSize;
        if(iRest > 0)
        {
            iRest--;
            iCurSectorSize++;
        }

        int iStepSize = 255 / iCurSectorSize;

        for(int iCurPos = 0; iCurPos < iCurSectorSize; iCurPos++)
        {
            int r = 0, g = 0, b = 0;
            int iColor = iStepSize * iCurPos;

            switch(iSector)
            {
            case 0: //red to yellow
                r = 255;
                g = iColor;
                break;
            case 1: //yellow to green
                r = 255 - iColor;
                g = 255;
                break;
            case 2: //green to cyan
                g = 255;
                b = iColor;
                break;
            case 3: //cyan to blue
                g = 255 - iColor;
                b = 255;
                break;
            case 4: //blue to magenta
                r = iColor;
                b = 255;
                break;
            case 5: //magenta to red
                r = 255;
                b = 255 - iColor;
                break;
            }
            pLEDS[iCurPos + iSectorSize * iSector] = CRGB(r,g,b);
        }
    }
}
