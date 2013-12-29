#include "waves.h"

//Constructor
Waves::Waves(CRGB *Leds, int iLeds) : Animation(Leds, iLeds)
{
    iGlobalPos = 0;
    iRed = 200;
    iGreen = 0;
    iBlue = 0;
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
        iColorSubStep = 1;
        iColorStep++;
        if(iColorStep > 5)
        {
            iColorStep = 0;
        }
    }
    switch(iColorStep)
    {
    case 0: //red to yellow
        iGreen++;
        break;
    case 1: //yellow to green
        iRed--;
        break;
    case 2: //green to cyan
        iBlue++;
        break;
    case 3: //cyan to blue
        iGreen--;
        break;
    case 4: //blue to magenta
        iRed++;
        break;
    case 5: //magenta to red
        iBlue--;
        break;
    }


    const int iStepCount = 10;
    const int iStepBase = 170;
    int iRest = iLedCount % (iStepCount*2);
    int iPos = iGlobalPos;
    CRGB Led;

    for(int iStep = 0; iStep < iStepCount; iStep++)
    {
        Led.setRGB(iRed, iGreen, iBlue);

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

        Led.setRGB(iRed, iGreen, iBlue);

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
