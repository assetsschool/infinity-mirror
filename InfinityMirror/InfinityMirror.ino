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
#define NUMPIXELS 144 // Pixel count
#define DATAPIN 6 // Green wire
#define CLOCKPIN 5 // Blue wire
#define ANALOGPOTPIN 2 // Potentiometer pin
#define COLORSTEP 8 // How much the color changes

Adafruit_DotStar strip = Adafruit_DotStar(NUMPIXELS, DATAPIN, CLOCKPIN, DOTSTAR_BRG);

int head = 0;
int tail = -143;

uint32_t color = 0xFF0000; // Color (starts red)

int pot = 0; // Potentiometer variable


void setup() {

#if defined(__AVR_ATtiny85__) && (F_CPU == 16000000L)
    clock_prescale_set(clock_div_1); // Enable 16 MHz on Trinket
#endif

    strip.begin();
    strip.show(); // Clears the strip
}

void loop() {

    strip.setPixelColor(head, color); // Sets head pixel to color
    strip.setPixelColor(tail, 0);     // Sets tail pixel to OFF
    strip.show();                     // Update strip

    pot = analogRead(ANALOGPOTPIN); // Reads the potentiometer

    pot = map(pot, 0, 1023, 0, 100); // Maps the reading to (0 - 100)
    delay(pot); // Delays for that many miliseconds

    if (++head >= NUMPIXELS) {

        head = 0;

        if ((color >>= COLORSTEP) == 0) {
            color = 0xFF0000;
        }
    }

    // Resets the head position to 0
    if (++tail >= NUMPIXELS) {
        tail = 0;
    }
}


// TEST AND IMPLEMENT ME

// const int step = 8; // Select this to be a power of two if you want the maximum brightness to be reachable
// for( int red = 0x00; red <= 0xFF; red += step ) {
//     for( int green = 0x00; green <= 0xFF; green += step ) {
//         for( int blue = 0x00; blue <= 0xFF; blue += step ) {
//             const int color = blue << 16 + green << 8 + red;
//             // Change the led settings here.
//         }
//     }
// } 