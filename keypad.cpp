#include "keypad.h"

KeyPad::KeyPad(padType type)
{
    switch(type)
    {
    case analog:
        padAnalog = new AnalogKeypad(509, 913, 0, 658, 955, 845, A0);
        activePad = analog;
        break;
    case digital:
        padDigital = new DigitalKeypad(8, 9, 11, 10, 6, 7);
        activePad = digital;
        break;
    }
}

key KeyPad::checkKeys()
{
    switch(activePad)
    {
    case analog:
        return padAnalog->checkKeys();
        break;
    case digital:
        return padDigital->checkKeys();
        break;
    }
}

void KeyPad::blink()
{
    switch (activePad) {
    case analog:
        padAnalog->blink();
        break;
    case digital:
        padDigital->blink();
        break;
    }
}
