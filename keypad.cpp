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
        digitalWrite(ledPin, HIGH);
    }
    else
    {
        if(bDimUp)
        {
            bDimUp = false;
            digitalWrite(ledPin, LOW);
            return DimUp;
        }
    }

    if(digitalRead(keyDimDown) == LOW)
    {
        bDimDown = true;
        digitalWrite(ledPin, HIGH);
    }
    else
    {
        if(bDimDown)
        {
            bDimDown = false;
            digitalWrite(ledPin, LOW);
            return DimDown;
        }
    }

    if(digitalRead(keyOnOff) == LOW)
    {
        bOnOff = true;
        digitalWrite(ledPin, HIGH);
    }
    else
    {
        if(bOnOff)
        {
            bOnOff = false;
            digitalWrite(ledPin, LOW);
            return OnOff;
        }
    }

    if(digitalRead(keyNext) == LOW)
    {
        bNext = true;
        digitalWrite(ledPin, HIGH);
    }
    else
    {
        if(bNext)
        {
            bNext = false;
            digitalWrite(ledPin, LOW);
            return Next;
        }
    }

    if(digitalRead(keyFaster) == LOW)
    {
        bFaster = true;
        digitalWrite(ledPin, HIGH);
    }
    else
    {
        if(bFaster)
        {
            bFaster = false;
            digitalWrite(ledPin, LOW);
            return Faster;
        }
    }

    if(digitalRead(keySlower) == LOW)
    {
        bSlower = true;
        digitalWrite(ledPin, HIGH);
    }
    else
    {
        if(bSlower)
        {
            bSlower = false;
            digitalWrite(ledPin, LOW);
            return Slower;
        }
    }

    return None;

}
