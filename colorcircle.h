#ifndef COLORCIRCLE_H
#define COLORCIRCLE_H
#include "FastSPI_LED2.h"
#include "animation.h"

class ColorCircle : public Animation
{
private:
    int iGlobalPos;

public:
    ColorCircle(CRGB *Leds, int iLeds);
    void doNextStep();
};

#endif
