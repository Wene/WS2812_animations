#include "waves.h"

//Constructor
Waves::Waves(CRGB *Leds, int iLeds) : Animation(Leds, iLeds)
{
    iGlobalPos = 0;
    iGlobalR = 200;
    iGlobalG = 0;
    iGlobalB = 0;
    iColorStep = 0;
    iColorSubStep = 0;
}

//animate next step
void Waves::doNextStep()
{
    memset(pLEDS, 0,  iLedCount * sizeof(struct CRGB)); //blank out for debugging

    iGlobalPos++;
    if(iGlobalPos >= iLedCount)
    {
        iGlobalPos = 0;
    }

    if(iColorSubStep < 200)
    {
        iColorSubStep++;
    }
    else
    {
        iColorSubStep = 0;
        iColorStep++;
        if(iColorStep > 5)
        {
            iColorStep = 0;
        }
    }
    switch(iColorStep)
    {
    case 0: //red to yellow
        iGlobalG++;
        break;
    case 1: //yellow to green
        iGlobalR--;
        break;
    case 2: //green to cyan
        iGlobalB++;
        break;
    case 3: //cyan to blue
        iGlobalG--;
        break;
    case 4: //blue to magenta
        iGlobalR++;
        break;
    case 5: //magenta to red
        iGlobalB--;
        break;
    }


    const int iStepCount = 10;
    const int iStepBase = 170;
    int iRest = iLedCount % (iStepCount*2);
    int iPos = iGlobalPos;
    CRGB Led;

    for(int iStep = 0; iStep < iStepCount; iStep++)
    {
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
        //Set cursor to the end of the current wave
        iPos += iWavePartLength + 1;  //+1 to reset the last iPos--.
        if(iPos >= iLedCount)
        {
            iPos -= iLedCount;
        }
    }
}
