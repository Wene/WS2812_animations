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
    int iMaxColor = 120; //set maxColor lower than 255 to allow adding lighting waves.

    memset(pLEDS, 0,  iLedCount * sizeof(struct CRGB)); //set all LEDs to black (for debugging reasons)

    //set the curent color of each LED
    for(int iSector = 0; iSector < 6; iSector++)
    {
        //add one step as long as rest is available. This may make the first gradients one longer than the last.
        int iCurSectorSize = iSectorSize;
        if(iRest > 0)
        {
            iRest--;
            iCurSectorSize++;
        }

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

            // set position in relation to current rotation offset
            int iPos = iGlobalPos + (iCurPos + iCurSectorSize * iSector);
            if(iPos >= iLedCount)
            {
                iPos -= iLedCount;
            }

            pLEDS[iPos] = CRGB(r,g,b);
        }
    }

    //set the lighting waves
    for(int iWave = 0; iWave < 3; iWave++)
    {
        int iWavePos = (iGlobalPos * -1) + (iLedCount - 1) + iWave * (iLedCount / 3);

        for(int iWavePart = -3; iWavePart <= 3; iWavePart++)
        {
            int iPos = iWavePos + iWavePart;
            if(iPos >= iLedCount)
            {
                iPos -= iLedCount;
            }
            else if(iPos < 0)
            {
                iPos += iLedCount;
            }
            CRGB Led = pLEDS[iPos];
            int iFactor = iWavePart;
            if(iFactor < 0)
            {
                iFactor *= -1;
            }
            int iDiff = 255 - iMaxColor;
            int iStep = iDiff / 4;
            Led += iDiff - (iFactor * iStep);
            pLEDS[iPos] = Led;
        }
    }
}
