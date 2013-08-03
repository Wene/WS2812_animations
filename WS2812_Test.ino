// Uncomment this line if you have any interrupts that are changing pins - this causes the library to be a little bit more cautious
// #define FAST_SPI_INTERRUPTS_WRITE_PINS 1

// Uncomment this line to force always using software, instead of hardware, SPI (why?)
// #define FORCE_SOFTWARE_SPI 1

// Uncomment this line if you want to talk to DMX controllers
// #define FASTSPI_USE_DMX_SIMPLE 1

#include "FastSPI_LED2.h"

#define NUM_LEDS 120

CRGB leds[NUM_LEDS];

void setup() {
  // sanity check delay - allows reprogramming if accidently blowing power w/leds
  delay(1000);

  // For safety (to prevent too high of a power draw), the test case defaults to
  // setting brightness to 50% brightness
  LEDS.setBrightness(127);

  LEDS.addLeds<WS2811, 13>(leds, NUM_LEDS);
  
  //reset all the LEDs
  memset(leds, 0,  NUM_LEDS * sizeof(struct CRGB));
  LEDS.show();
}

void loop()
{
  for(int i = 0; i < NUM_LEDS; i++)
  {
    memset(leds, 0,  NUM_LEDS * sizeof(struct CRGB));
    
    int pos = i;
    for(int j = 0; j < 10; j++)
    {
      if(pos - j >= 0)
      {
        leds[pos - j].g = 128 - (j * 10);
      }
      else
      {
        leds[pos + NUM_LEDS - j].g = 128 - (j * 10);
      }
    }
    
    pos = pos + (NUM_LEDS / 6);
    if(pos >= NUM_LEDS)
    {
      pos = pos - NUM_LEDS;
    }

    for(int j = 0; j < 10; j++)
    {
      if(pos - j >= 0)
      {
        leds[pos - j].r = 128 - (j * 10);
      }
      else
      {
        leds[pos + NUM_LEDS - j].r = 128 - (j * 10);
      }
    }
  
    pos = pos + (NUM_LEDS / 6);
    if(pos >= NUM_LEDS)
    {
      pos = pos - NUM_LEDS;
    }

    for(int j = 0; j < 10; j++)
    {
      if(pos - j >= 0)
      {
        leds[pos - j].b = 128 - (j * 10);
      }
      else
      {
        leds[pos + NUM_LEDS - j].b = 128 - (j * 10);
      }
    }
    
    pos = pos + (NUM_LEDS / 6);
    if(pos >= NUM_LEDS)
    {
      pos = pos - NUM_LEDS;
    }

    for(int j = 0; j < 10; j++)
    {
      if(pos - j >= 0)
      {
        leds[pos - j].g = 128 - (j * 10);
        leds[pos - j].r = 128 - (j * 10);
      }
      else
      {
        leds[pos + NUM_LEDS - j].g = 128 - (j * 10);
        leds[pos + NUM_LEDS - j].r = 128 - (j * 10);
      }
    }

    pos = pos + (NUM_LEDS / 6);
    if(pos >= NUM_LEDS)
    {
      pos = pos - NUM_LEDS;
    }
    
    for(int j = 0; j < 10; j++)
    {
      if(pos - j >= 0)
      {
        leds[pos - j].r = 128 - (j * 10);
        leds[pos - j].b = 128 - (j * 10);
      }
      else
      {
        leds[pos + NUM_LEDS - j].r = 128 - (j * 10);
        leds[pos + NUM_LEDS - j].b = 128 - (j * 10);
      }
    }

    pos = pos + (NUM_LEDS / 6);
    if(pos >= NUM_LEDS)
    {
      pos = pos - NUM_LEDS;
    }
    
    for(int j = 0; j < 10; j++)
    {
      if(pos - j >= 0)
      {
        leds[pos - j].b = 128 - (j * 10);
        leds[pos - j].g = 128 - (j * 10);
      }
      else
      {
        leds[pos + NUM_LEDS - j].b = 128 - (j * 10);
        leds[pos + NUM_LEDS - j].g = 128 - (j * 10);
      }
    }

  
    LEDS.show();
    delay(100);
  }
}
