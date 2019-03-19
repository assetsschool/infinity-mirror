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
	Fire(55, 120, 15);
}

void Fire(int Cooling, int Sparking, int SpeedDelay)
{
	static byte heat[NUMPIXELS];
	int cooldown;

	// Step 1.  Cool down every cell a little
	for (int i = 0; i < NUMPIXELS; i++)
	{
		cooldown = random(0, ((Cooling * 10) / NUMPIXELS) + 2);

		if (cooldown > heat[i])
		{
			heat[i] = 0;
		}
		else
		{
			heat[i] = heat[i] - cooldown;
		}
	}

	// Step 2.  Heat from each cell drifts 'up' and diffuses a little
	for (int k = NUMPIXELS - 1; k >= 2; k--)
	{
		heat[k] = (heat[k - 1] + heat[k - 2] + heat[k - 2]) / 3;
	}

	// Step 3.  Randomly ignite new 'sparks' near the bottom
	if (random(255) < Sparking)
	{
		int y = random(7);
		heat[y] = heat[y] + random(160, 255);
		//heat[y] = random(160,255);
	}

	// Step 4.  Convert heat to LED colors
	for (int j = 0; j < NUMPIXELS; j++)
	{
		setPixelHeatColor(j, heat[j]);
	}

	strip.show();
	delay(SpeedDelay);
}

void setPixelHeatColor(int Pixel, byte temperature)
{
	// Scale 'heat' down from 0-255 to 0-191
	byte t192 = round((temperature / 255.0) * 191);

	// calculate ramp up from
	byte heatramp = t192 & 0x3F; // 0..63
	heatramp <<= 2;				 // scale up to 0..252

	// figure out which third of the spectrum we're in:
	if (t192 > 0x80)
	{ // hottest
		strip.setPixelColor(Pixel, 200, 255, heatramp);
	}
	else if (t192 > 0x40)
	{ // middle
		//strip.setPixelColor(Pixel, 255, heatramp, 0);
		strip.setPixelColor(Pixel, heatramp, 255, 0);
	}
	else
	{ // coolest
		// strip.setPixelColor(Pixel, heatramp, 0, 0);
		strip.setPixelColor(Pixel, 0, heatramp, 0);
	}
}

