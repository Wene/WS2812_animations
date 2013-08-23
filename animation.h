#ifndef ANIMATION_H
#define ANIMATION_H
#include "FastSPI_LED2.h"

class Animation
{
protected:
    CRGB *pLEDS;
    int iLedCount;

public:
    Animation(CRGB *Leds, int iLeds);
    virtual void doNextStep() = 0;
};
#endif
