#ifndef RAINBOW_H
#define RAINBOW_H
#include "FastSPI_LED2.h"
#include "animation.h"

class Rainbow : public Animation
{
private:
    int iGlobalPos;

public:
    Rainbow(CRGB *Leds, int iLeds);
    void doNextStep();
};

#endif
