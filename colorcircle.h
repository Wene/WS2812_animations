#include "FastSPI_LED2.h"

class ColorCircle
{
private:
    CRGB *pLEDS;
    int iGlobalPos;
    int iLedCount;

public:
    ColorCircle(CRGB *Leds, int iLeds);
    void doNextStep();
};
