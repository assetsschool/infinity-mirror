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
#define NUMPIXELS 144  // Pixel count
#define DATAPIN 6	  // Green wire
#define CLOCKPIN 5	 // Blue wire
#define ANALOGPOTPIN 2 // Potentiometer pin

Adafruit_DotStar strip = Adafruit_DotStar(NUMPIXELS, DATAPIN, CLOCKPIN, DOTSTAR_BRG);

int head = 0;
int tail = -144;

uint32_t color = 0xFF0000; // Color (starts red)

int pot = 0; // Potentiometer variable

void setup()
{

#if defined(__AVR_ATtiny85__) && (F_CPU == 16000000L)
	clock_prescale_set(clock_div_1); // Enable 16 MHz on Trinket
#endif

	strip.begin();
	strip.setBrightness(64);
	strip.show(); // Clears the strip
}

#define COLORSTEP 1	// How much the color changes

int r = 255;
int g = 0;
int b = 0;


void loop() {
    while (true) {

        // Update the intensity value
        if (r > 0 && b == 0){
			r = r - COLORSTEP;
			g = g + COLORSTEP;
		}
		if (g > 0 && r == 0){
			g = g - COLORSTEP;
			b = b + COLORSTEP;
		}
		if (b > 0 && g == 0){
			r = r + COLORSTEP;
			b = b - COLORSTEP;
		}

        // Set the color
		for (int currentPix = 0; currentPix <= NUMPIXELS; currentPix++) {
        	strip.setPixelColor(currentPix, r, g, b);
		}
		strip.show();    
    }
}