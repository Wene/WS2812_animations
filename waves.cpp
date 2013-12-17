#include "waves.h"

//Constructor
Waves::Waves(CRGB *Leds, int iLeds) : Animation(Leds, iLeds)
{
    iGlobalPos = 0;
}

//animate next step
void Waves::doNextStep()
{
    iGlobalPos++;
    if(iGlobalPos >= iLedCount)
    {
        iGlobalPos = 0;
    }

    const int iStepCount = 20;  //must be a even number!
    int iRest = iLedCount % iStepCount;
    int iPos = iGlobalPos;
    CRGB Led;
    bool bUp = false;

    for(int iStep = 0; iStep < iStepCount; iStep++)
    {
        if(iStep % 2 == 0)
        {
            if(!bUp)
            {
                Led.setRGB(10,10,10);   //reset color on direction change
            }
            bUp = true;
        }
        else
        {
            bUp = false;
        }

        int iWaveLength = iLedCount / iStepCount;
        if(iRest > 0)
        {
            iWaveLength++;
            iRest--;
        }
        int iStepSize = 240 / iWaveLength;  //variable step size depending on variable wave length

        for(int iCurPos = 0; iCurPos < iWaveLength; iCurPos++)
        {
            if(bUp)   //up
            {
                Led += iStepSize;
            }
            else    //down
            {
                Led -= iStepSize;
            }

            pLEDS[iPos] = Led;
            iPos++;
            if(iPos >= iLedCount)
            {
                iPos = 0;
            }
        }
    }
}
