#include "FastSPI_LED2.h"
#include "animation.h"
#include "rainbow.h"        //animation 0
#include "colorcircle.h"    //animation 1

// define the number of LEDs
#define NUM_LEDS 240

CRGB leds[NUM_LEDS];
//ColorCircle Animation(leds, NUM_LEDS);
//Rainbow Animation(leds, NUM_LEDS);
Animation *Anim;
bool buttonPressed = false;
int ledPin = 13;
int buttonPin = 10;
int currentAnimation = 0;

void setup() {
    pinMode(ledPin, OUTPUT);
    pinMode(buttonPin, INPUT_PULLUP);
    digitalWrite(ledPin, HIGH);

    //sanity check delay - allows reprogramming if accidently blowing power w/leds
    delay(1000);

    //setting maximum brightness
    LEDS.setBrightness(45);

    LEDS.addLeds<WS2811, 12, GRB>(leds, NUM_LEDS); //GRB for the WS2812 color order

    //Rainbow *Ani = new Rainbow(leds, NUM_LEDS);
    Anim = new Rainbow(leds, NUM_LEDS);

    //reset all the LEDs
    memset(leds, 0,  NUM_LEDS * sizeof(struct CRGB));
    LEDS.show();
    digitalWrite(ledPin, LOW);
}

void loop()
{
    int buttonState = digitalRead(buttonPin);
    if(buttonState == LOW)
    {
        buttonPressed = true;
        digitalWrite(ledPin, HIGH);
    }
    else if(buttonState == HIGH)
    {
        if(buttonPressed)   //switch animation only if the button was pressed before
        {
            buttonPressed = false;
            delete Anim;
            currentAnimation++;
            if(currentAnimation > 1)    //reset
            {
                currentAnimation = 0;
            }
            switch(currentAnimation)
            {
            case 0:
                Anim = new Rainbow(leds, NUM_LEDS);
                break;
            case 1:
                Anim = new ColorCircle(leds, NUM_LEDS);
                break;
            }
        }
        digitalWrite(ledPin, LOW);
    }

    Anim->doNextStep();
    LEDS.show();
    delay(100);
}
