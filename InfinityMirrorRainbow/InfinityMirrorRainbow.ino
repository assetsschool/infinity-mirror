/*
 *  InfinityMirror.ino
 * 
 *  Created by Iain Moncrief
 *  Tuesday, March 12, 2019
 *  
 */

#include <Adafruit_DotStar.h>
#include <SPI.h>

// Compile time definitions
#define NUMPIXELS 286  // Pixel count for extended LED strip
#define DATAPIN 6	  // Green wire
#define CLOCKPIN 5	 // Blue wire
#define ANALOGPOTPIN 2 // Potentiometer pin
#define BRIGHTNESS 64

Adafruit_DotStar strip = Adafruit_DotStar(NUMPIXELS, DATAPIN, CLOCKPIN, DOTSTAR_BRG);

int head = 0;
int tail = -286;

uint32_t color = 0xFF0000; // Color (starts red)

int pot = 0; // Potentiometer variable

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
	rainbowCycle();
}

void rainbowCycle()
{
	byte *c;
	uint16_t i, j;

	for (j = 0; j < 256 * 5; j++)
	{
		for (i = 0; i < NUMPIXELS; i++)
		{
			c = Wheel(((i * 256 / NUMPIXELS) + j) & 255);
			strip.setPixelColor(i, *c, *(c + 1), *(c + 2));
		}
		strip.show();
	}
}

byte *Wheel(byte WheelPos)
{
	static byte c[3];

	if (WheelPos < 85)
	{
		c[0] = WheelPos * 3;
		c[1] = 255 - WheelPos * 3;
		c[2] = 0;
	}
	else if (WheelPos < 170)
	{
		WheelPos -= 85;
		c[0] = 255 - WheelPos * 3;
		c[1] = 0;
		c[2] = WheelPos * 3;
	}
	else
	{
		WheelPos -= 170;
		c[0] = 0;
		c[1] = WheelPos * 3;
		c[2] = 255 - WheelPos * 3;
	}

	return c;
}