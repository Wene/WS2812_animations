#ifndef ANALOG_KEYPAD_H
#define ANALOG_KEYPAD_H

#include "commontypes.h"

class AnalogKeypad
{
public:
    AnalogKeypad(int up, int down, int onOff, int next, int faster, int slower, int pin);
    void setLedPin(int pin);
    void setKeyValues(int up, int down, int onOff, int next, int faster, int slower, int pin);
    void blink();
    key checkKeys();

private:
    int ledPin;
    int KeyPin;
    int maxDimUp, minDimUp, maxDimDown, minDimDown, maxOnOff, minOnOff;
    int maxNext, minNext, maxFaster, minFaster, maxSlower, minSlower;
    int iLongPress;
    bool bDimUp, bDimDown, bOnOff, bNext, bFaster, bSlower;
    bool bBlinkOn;
    key returnValue;

    void keyDown();
    void keyUp();
};

#endif
