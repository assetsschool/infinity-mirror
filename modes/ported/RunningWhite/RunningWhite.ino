/*
 *  InfinityMirrorRainbow.ino
 * 
 *  Created by Iain Moncrief
 *  Monday, March 18, 2019
 *  
 */

#include <Adafruit_DotStar.h>
#include <SPI.h>

// Compile time definitions
#define NUMPIXELS 144  // Pixel count for extended LED strip
#define DATAPIN 6	  // Green wire
#define CLOCKPIN 5	 // Blue wire
#define ANALOGPOTPIN 2 // Potentiometer pin
#define BRIGHTNESS 30

Adafruit_DotStar strip = Adafruit_DotStar(NUMPIXELS, DATAPIN, CLOCKPIN, DOTSTAR_BRG);

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
	  RunningLights(0,0,0xff, 0);        // red
}

void RunningLights(byte red, byte green, byte blue, int WaveDelay)
{
	int Position = 0;

	for (int j = 0; j < NUMPIXELS * 2; j++)
	{
		Position++; // = 0; //Position + Rate;
		for (int i = 0; i < NUMPIXELS; i++)
		{
			// sine wave, 3 offset waves make a rainbow!
			//float level = sin(i+Position) * 127 + 128;
			//setPixel(i,level,0,0);
			//float level = sin(i+Position) * 127 + 128;
			strip.setPixelColor(i, ((sin(i + Position) * 127 + 128) / 255) * red,
					 ((sin(i + Position) * 127 + 128) / 255) * green,
					 ((sin(i + Position) * 127 + 128) / 255) * blue);
		}

		strip.show();
		delay(WaveDelay);
	}
}