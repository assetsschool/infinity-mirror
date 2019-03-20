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
#define BRIGHTNESS 0

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
	Twinkle(0xff, 0, 0, 10, 100, false);
}

void Twinkle(byte red, byte green, byte blue, int Count, int SpeedDelay, boolean OnlyOne)
{
	strip.clear();

	for (int i = 0; i < Count; i++)
	{
		strip.setPixelColor(random(NUMPIXELS), red, green, blue);
		strip.show();
		delay(SpeedDelay);
		if (OnlyOne)
		{
			strip.clear();
		}
	}

	delay(SpeedDelay);
}