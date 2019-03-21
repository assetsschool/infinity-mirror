/*
 *  InfinityMirrorRainbow.ino
 * 
 *  Created by Iain Moncrief
 *  Thursday, March 15, 2019
 *  
 */

#include <Adafruit_DotStar.h>
#include <SPI.h>

// Compile time definitions
#define NUMPIXELS 144 // Pixel count for extended LED strip
#define DATAPIN 6     // Green wire
#define CLOCKPIN 5    // Blue wire
#define MICPIN 0

#define BRIGHTNESS 25
#define SQUELCH 200

#define LOWESTLEDS 0 // Lowest on the strip the LED's can be

Adafruit_DotStar strip = Adafruit_DotStar(NUMPIXELS, DATAPIN, CLOCKPIN, DOTSTAR_BRG);

int micValue = 0;
int volumePercentage = 0;
void setup()
{

#if defined(__AVR_ATtiny85__) && (F_CPU == 16000000L)
    clock_prescale_set(clock_div_1); // Enable 16 MHz on Trinket
#endif

    strip.begin();

    if (BRIGHTNESS > 0)
    {
        strip.setBrightness(BRIGHTNESS);
    }

    strip.show(); // Clears the strip
}

void loop()
{

    micValue = map(analogRead(MICPIN), 0, 513, 0, NUMPIXELS);

    volumePercentage = map(micValue, 0, NUMPIXELS, 0, 100);

    for (int i = 0; i < NUMPIXELS; i++)
    {
        if (i < micValue)
        {
            if (volumePercentage >= 80)
            {
                strip.setPixelColor(i, 255, 0, 0);
            }
            else if (volumePercentage >= 50)
            {
                strip.setPixelColor(i, 255, 255, 0);
            }
            else if (volumePercentage >= 30)
            {
                strip.setPixelColor(i, 0, 255, 0);
            }
            else
            {
                strip.setPixelColor(i, 0, 0, 255);
            }
        }
        else
        {
            strip.setPixelColor(i, 0, 0, 0);
        }
    }

    strip.show();
    delay(500);
}