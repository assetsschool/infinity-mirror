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

const int sampleWindow = 50; // Sample window width in mS (50 mS = 20Hz)
unsigned int sample;

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

    unsigned long startMillis = millis(); // Start of sample window
    unsigned int peakToPeak = 0;          // peak-to-peak level

    unsigned int signalMax = 0;
    unsigned int signalMin = 1024;

    // collect data for 50 mS
    while (millis() - startMillis < sampleWindow)
    {
        sample = analogRead(0);
        if (sample < 1024) // toss out spurious readings
        {
            if (sample > signalMax)
            {
                signalMax = sample; // save just the max levels
            }
            else if (sample < signalMin)
            {
                signalMin = sample; // save just the min levels
            }
        }
    }
    peakToPeak = signalMax - signalMin; // max - min = peak-peak amplitude
                                        //double volts = (peakToPeak * 5.0) / 1024;  // convert to volts

    micValue = map(peakToPeak, 0, 512, 0, NUMPIXELS);

    //micValue = map(analogRead(MICPIN), 0, 513, 0, NUMPIXELS);

    for (int i = 0; i < NUMPIXELS; i++)
    {
        volumePercentage = map(i, 0, NUMPIXELS, 0, 100);
        if (i < micValue)
        {
            if (volumePercentage >= 80)
            {
                strip.setPixelColor(i, 0, 255, 0);
            }
            else if (volumePercentage >= 50)
            {
                strip.setPixelColor(i, 255, 255, 0);
            }
            else if (volumePercentage >= 30)
            {
                strip.setPixelColor(i, 255, 0, 255);
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
    //delay(500);
}