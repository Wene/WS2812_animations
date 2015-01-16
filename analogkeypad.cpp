#include "analogkeypad.h"
#include "Arduino.h"

AnalogKeypad::AnalogKeypad(int up, int down, int onOff, int next, int faster, int slower, int pin)
{
    bDimDown = false;
    bDimUp = false;
    bFaster = false;
    bNext = false;
    bOnOff = false;
    bSlower = false;
    iLongPress = 0;

    setLedPin(5);  //default LED pin
    setKeyValues(up, down, onOff, next, faster, slower, pin);
}

void AnalogKeypad::setKeyValues(int up, int down, int onOff, int next, int faster, int slower, int pin)
{
    minDimUp = up - 10;
    maxDimUp = up + 10;
    minDimDown = down - 10;
    maxDimDown = down + 10;
    minOnOff = onOff - 10;
    maxOnOff = onOff + 10;
    minNext = next - 10;
    maxNext = next + 10;
    minFaster = faster - 10;
    maxFaster = faster + 10;
    minSlower = slower - 10;
    maxSlower = slower + 10;

    KeyPin = pin;
}

void AnalogKeypad::setLedPin(int pin)
{
    ledPin = pin;
    pinMode(ledPin, OUTPUT);
}

AnalogKeypad::key AnalogKeypad::checkKeys()    //returns the pressed key.
{
    int keyValue = analogRead(KeyPin);

    if(keyValue > minDimUp && keyValue < maxDimUp)
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
                returnValue = Keypad::DimMax;
            }
            else
            {
                returnValue = Keypad::DimUp;
            }
            keyUp();
            return returnValue;
        }
    }

    if(keyValue > minDimDown && keyValue < maxDimDown)
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
                returnValue = Keypad::DimMin;
            }
            else
            {
                returnValue = Keypad::DimDown;
            }
            keyUp();
            return returnValue;
        }
    }

    if(keyValue > minOnOff && keyValue < maxOnOff)
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
                returnValue = Keypad::Debug;
            }
            else
            {
                returnValue = Keypad::OnOff;
            }
            keyUp();
            return returnValue;
        }
    }

    if(keyValue > minNext && keyValue < maxNext)
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
            return Keypad::Next;
        }
    }

    if(keyValue > minFaster && keyValue < maxFaster)
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
                returnValue = Keypad::Fastest;
            }
            else
            {
                returnValue = Keypad::Faster;
            }
            keyUp();
            return returnValue;
        }
    }

    if(keyValue > minSlower && keyValue < maxSlower)
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
                returnValue = Keypad::Slowest;
            }
            else
                returnValue = Keypad::Slower;
            keyUp();
            return returnValue;
        }
    }

    return None;

}

void AnalogKeypad::blink()
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

void AnalogKeypad::keyDown()
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

void AnalogKeypad::keyUp()
{
    digitalWrite(ledPin, LOW);
    iLongPress = 0;
}
