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
    int iCurrentPos;
    void setLed(bool up, CRGB &Led);

public:
    Waves(CRGB *Leds, int iLeds);
    void doNextStep();
};

#endif
