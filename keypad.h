#ifndef KEYPAD_H
#define KEYPAD_H

#include "Arduino.h"
#include "commontypes.h"

#include "digitalkeypad.h"
#include "analogkeypad.h"

class KeyPad
{

public:
    enum padType{analog, digital};
    key checkKeys();
    KeyPad(padType type);
    void blink();

private:
    padType activePad;
    AnalogKeypad* padAnalog;
    DigitalKeypad* padDigital;
};

#endif
