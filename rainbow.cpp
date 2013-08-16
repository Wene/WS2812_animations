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

    const int iSector = iLedCount / 6;
    const int iStepSize = 255 / iSector;
    const int iMod = iLedCount % 6;

    //red to yellow
    for(int iCurPos = 0; iCurPos < iSector; iCurPos++)
    {
        int r = 255;
        int g = iStepSize * iCurPos;
        int b = 0;
        pLEDS[iCurPos] = CRGB(r,g,b);
    }
    //yellow to green
    for(int iCurPos = 0; iCurPos < iSector; iCurPos++)
    {
        int r = 255 - iStepSize * iCurPos;
        int g = 255;
        int b = 0;
        pLEDS[iCurPos + iSector] = CRGB(r,g,b);
    }
    //green to cyan
    for(int iCurPos = 0; iCurPos < iSector; iCurPos++)
    {
        int r = 0;
        int g = 255;
        int b = iStepSize * iCurPos;
        pLEDS[iCurPos + iSector * 2] = CRGB(r,g,b);
    }
    //cyan to blue
    for(int iCurPos = 0; iCurPos < iSector; iCurPos++)
    {
        int r = 0;
        int g = 255 - iStepSize * iCurPos;
        int b = 255;
        pLEDS[iCurPos + iSector * 3] = CRGB(r,g,b);
    }
    //blue to magenta
    for(int iCurPos = 0; iCurPos < iSector; iCurPos++)
    {
        int r = iStepSize * iCurPos;
        int g = 0;
        int b = 255;
        pLEDS[iCurPos + iSector * 4] = CRGB(r,g,b);
    }
    //magenta to red
    for(int iCurPos = 0; iCurPos < iSector + iMod; iCurPos++)
    {
        int r = 255;
        int g = 0;
        int b = 255 - iStepSize * iCurPos;
        pLEDS[iCurPos + iSector * 5] = CRGB(r,g,b);
    }

//    for(int color = 0; color < 6; color++)
//    {
//        CRGB curColor;
//        switch(color)
//        {
//        case 0:
//            curColor = CRGB(255,0,0);
//            break;
//        case 1:
//            curColor = CRGB(0,255,0);
//            break;
//        case 2:
//            curColor = CRGB(0,0,255);
//            break;
//        case 3:
//            curColor = CRGB(200,200,0);
//            break;
//        case 4:
//            curColor = CRGB(200,0,200);
//            break;
//        case 5:
//            curColor = CRGB(0,200,200);
//            break;
//        }

//        for(int j = 0; j < 10; j++)
//        {
//            if(iPos - j >= 0)
//            {
//                pLEDS[iPos - j] = curColor;
//            }
//            else
//            {
//                pLEDS[iPos + iLedCount - j] = curColor;
//            }
//            curColor.nscale8(180);
//        }

//        iPos = iPos + (iLedCount / 6);
//        if(iPos >= iLedCount)
//        {
//            iPos = iPos - iLedCount;
//        }
//    }
}
