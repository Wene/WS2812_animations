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
    int iRest = iLedCount % (iStepCount*2);
    iCurrentPos = iGlobalPos;
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
        for(int iCurPos = 0; iCurPos < iWavePartLength; iCurPos++)
        {
            setLed(true, Led);
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
        iCurrentPos += iWavePartLength - 1;
        if(iCurrentPos >= iLedCount)
        {
            iCurrentPos -= iLedCount;
        }
        for(int iCurPos = 0; iCurPos < iWavePartLength; iCurPos++)
        {
            setLed(false, Led);
        }
        //Set cursor to the end of the current wave
        iCurrentPos += iWavePartLength + 1;  //+1 to reset the last iPos--.
        if(iCurrentPos >= iLedCount)
        {
            iCurrentPos -= iLedCount;
        }
    }
}

void Waves::setLed(bool up, CRGB &Led)
{

    Led.nscale8(200);
    pLEDS[iCurrentPos] = Led;
    if(up)
    {
        iCurrentPos++;
        if(iCurrentPos >= iLedCount)
        {
            iCurrentPos = 0;
        }
    }
    else
    {
        iCurrentPos--;
        if(iCurrentPos < 0)
        {
            iCurrentPos = iLedCount - 1;
        }
    }
}
