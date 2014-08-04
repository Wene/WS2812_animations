#ifndef KEYPAD_H
#define KEYPAD_H

class Keypad
{
public:
    Keypad(int up, int down, int onOff, int next, int faster, int slower);
    void setLedPin(int pin);
    void setKeyPins(int up, int down, int onOff, int next, int faster, int slower);
    void blink();
    enum key{None, DimUp, DimDown, OnOff, Next, Faster, Slower, Debug, DimMax, DimMin, Slowest, Fastest};
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
