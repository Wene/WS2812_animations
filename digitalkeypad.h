#ifndef DIGITAL_KEYPAD_H
#define DIGITAL_KEYPAD_H

#include "commontypes.h"

class DigitalKeypad
{
public:
    DigitalKeypad(int up, int down, int onOff, int next, int faster, int slower);
    void setLedPin(int pin);
    void setKeyPins(int up, int down, int onOff, int next, int faster, int slower);
    void blink();
    key checkKeys();

private:
    int ledPin;
    int keyDimUp, keyDimDown, keyOnOff, keyNext, keyFaster, keySlower;
    int iLongPress;
    bool bDimUp, bDimDown, bOnOff, bNext, bFaster, bSlower;
    bool bBlinkOn;
    key returnValue;

    void keyDown();
    void keyUp();
};

#endif
