#include "waves.h"

//Constructor
Waves::Waves(CRGB *Leds, int iLeds) : Animation(Leds, iLeds)
{
    iGlobalPos = 0;
    iGlobalR = 200;
    iGlobalG = 0;
    iGlobalB = 0;
}

//animate next step
void Waves::doNextStep()
{
    iGlobalPos++;
    if(iGlobalPos >= iLedCount)
    {
        iGlobalPos = 0;
    }

    const int iStepCount = 10;
    const int iStepBase = 170;
    int iRest = iLedCount % (iStepCount*2);
    int iPos = iGlobalPos;
    CRGB Led;

    for(int iStep = 0; iStep < (iStepCount*2); iStep++)
    {
        memset(pLEDS, 0,  iLedCount * sizeof(struct CRGB)); //blank out for debugging

        Led.setRGB(iGlobalR, iGlobalG, iGlobalB);

        //Down
        int iWavePartLength = iLedCount / (iStepCount*2);
        if(iRest > 0)
        {
            iWavePartLength++;
            iRest--;
        }
        int iStepSize = iStepBase / iWavePartLength;  //variable step size depending on variable wave length
        for(int iCurPos = 0; iCurPos < iWavePartLength; iCurPos++)
        {
            Led -= iStepSize;
            pLEDS[iPos] = Led;
            iPos++;
            if(iPos >= iLedCount)
            {
                iPos = 0;
            }
        }

        Led.setRGB(iGlobalR, iGlobalG, iGlobalB);

        //Up
        iWavePartLength = iLedCount / (iStepCount*2);
        if(iRest > 0)
        {
            iWavePartLength++;
            iRest--;
        }
        //Reverse direction to ensure the brightness gets allways decreased
        iPos += iWavePartLength;
        if(iPos >= iLedCount)
        {
            iPos -= iLedCount;
        }
        iStepSize = iStepBase / iWavePartLength;  //variable step size depending on variable wave length
        for(int iCurPos = 0; iCurPos < iWavePartLength; iCurPos++)
        {
            Led -= iStepSize;
            pLEDS[iPos] = Led;
            iPos--;
            if(iPos < 0)
            {
                iPos = iLedCount - 1;
            }
        }
        //Restore the former position
        iPos -= iWavePartLength;
        if(iPos < 0)
        {
            iPos = iLedCount - 1;
        }
    }
}
