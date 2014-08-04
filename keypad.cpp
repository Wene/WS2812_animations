#include "keypad.h"
#include "Arduino.h"

Keypad::Keypad(int up, int down, int onOff, int next, int faster, int slower)
{
    bDimDown = false;
    bDimUp = false;
    bFaster = false;
    bNext = false;
    bOnOff = false;
    bSlower = false;
    iLongPress = 0;

    setLedPin(13);  //default LED pin
    setKeyPins(up, down, onOff, next, faster, slower);
}

void Keypad::setKeyPins(int up, int down, int onOff, int next, int faster, int slower)
{
    keyDimUp = up;
    keyDimDown = down;
    keyOnOff = onOff;
    keyNext = next;
    keyFaster = faster;
    keySlower = slower;

    pinMode(keyNext, INPUT_PULLUP);
    pinMode(keyDimUp, INPUT_PULLUP);
    pinMode(keyDimDown, INPUT_PULLUP);
    pinMode(keyOnOff, INPUT_PULLUP);
    pinMode(keyFaster, INPUT_PULLUP);
    pinMode(keySlower, INPUT_PULLUP);
}

void Keypad::setLedPin(int pin)
{
    ledPin = pin;
    pinMode(ledPin, OUTPUT);
}

Keypad::key Keypad::checkKeys()    //returns the pressed key.
{
    if(digitalRead(keyDimUp) == LOW)
    {
        bDimUp = true;
        keyDown();
    }
    else
    {
        if(bDimUp)
        {
            bDimUp = false;
            if(iLongPress > 50)
            {
                returnValue = DimMax;
            }
            else
            {
                returnValue = DimUp;
            }
            keyUp();
            return returnValue;
        }
    }

    if(digitalRead(keyDimDown) == LOW)
    {
        bDimDown = true;
        keyDown();
    }
    else
    {
        if(bDimDown)
        {
            bDimDown = false;
            if(iLongPress > 50)
            {
                returnValue = DimMin;
            }
            else
            {
                returnValue = DimDown;
            }
            keyUp();
            return returnValue;
        }
    }

    if(digitalRead(keyOnOff) == LOW)
    {
        bOnOff = true;
        keyDown();
    }
    else
    {
        if(bOnOff)
        {
            bOnOff = false;
            if(iLongPress > 50)
            {
                returnValue = Debug;
            }
            else
            {
                returnValue = OnOff;
            }
            keyUp();
            return returnValue;
        }
    }

    if(digitalRead(keyNext) == LOW)
    {
        bNext = true;
        keyDown();
    }
    else
    {
        if(bNext)
        {
            bNext = false;
            keyUp();
            return Next;
        }
    }

    if(digitalRead(keyFaster) == LOW)
    {
        bFaster = true;
        keyDown();
    }
    else
    {
        if(bFaster)
        {
            bFaster = false;
            if(iLongPress > 50)
            {
                returnValue = Fastest;
            }
            else
            {
                returnValue = Faster;
            }
            keyUp();
            return returnValue;
        }
    }

    if(digitalRead(keySlower) == LOW)
    {
        bSlower = true;
        keyDown();
    }
    else
    {
        if(bSlower)
        {
            bSlower = false;
            if(iLongPress > 50)
            {
                returnValue = Slowest;
            }
            else
                returnValue = Slower;
            keyUp();
            return returnValue;
        }
    }

    return None;

}

void Keypad::blink()
{
    if(bBlinkOn)
    {
        bBlinkOn = false;
        digitalWrite(ledPin, LOW);
    }
    else
    {
        bBlinkOn = true;
        digitalWrite(ledPin, HIGH);
    }
}

void Keypad::keyDown()
{
    iLongPress++;
    if(iLongPress > 50)
    {
        digitalWrite(ledPin, LOW);
    }
    else
    {
        digitalWrite(ledPin, HIGH);
    }
}

void Keypad::keyUp()
{
    digitalWrite(ledPin, LOW);
    iLongPress = 0;
}
