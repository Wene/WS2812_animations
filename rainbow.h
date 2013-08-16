#include "FastSPI_LED2.h"

class Rainbow
{
private:
    CRGB *pLEDS;
    int iGlobalPos;
    int iLedCount;

public:
    Rainbow(CRGB *Leds, int iLeds);
    void doNextStep();
};
