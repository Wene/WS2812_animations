#ifndef SWISS_H
#define SWISS_H
#include "FastSPI_LED2.h"
#include "animation.h"

class Swiss : public Animation
{
private:
    int iPos;
    int iMaxPos;
    int iCrossCount;
    int iSpace;

public:
    Swiss(CRGB *Leds, int iLeds);
    void doNextStep();
};

#endif
