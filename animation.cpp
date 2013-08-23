#include "animation.h"

Animation::Animation(CRGB *Leds, int iLeds)
{
    iLedCount = iLeds;
    pLEDS = Leds;
}
