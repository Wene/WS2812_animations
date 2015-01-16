#ifndef KEYPAD_H
#define KEYPAD_H

#include "Arduino.h"
#include "digitalkeypad.h"
#include "analogkeypad.h"

class Keypad
{

public:
    enum key{None, DimUp, DimDown, OnOff, Next, Faster, Slower, Debug, DimMax, DimMin, Slowest, Fastest};
    enum padType{analog, digital};
    key checkKeys();
    Keypad(padType type);

private:
    padType activePad;
    AnalogKeypad* padAnalog;
    DigitalKeypad* padDigital;
};

#endif
