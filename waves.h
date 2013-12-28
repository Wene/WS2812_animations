#ifndef WAVES_H
#define WAVES_H
#include "FastSPI_LED2.h"
#include "animation.h"

class Waves : public Animation
{
private:
    int iGlobalPos;
    int iGlobalR, iGlobalG, iGlobalB;

public:
    Waves(CRGB *Leds, int iLeds);
    void doNextStep();
};

#endif
