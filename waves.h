#ifndef WAVES_H
#define WAVES_H
#include "FastSPI_LED2.h"
#include "animation.h"

class Waves : public Animation
{
private:
    int iGlobalPos;
    int iRed, iGreen, iBlue;
    int iColorStep, iColorSubStep;

//add functions for repeating steps...

public:
    Waves(CRGB *Leds, int iLeds);
    void doNextStep();
};

#endif
