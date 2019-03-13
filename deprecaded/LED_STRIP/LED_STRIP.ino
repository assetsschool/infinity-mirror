#include <Adafruit_NeoPixel.h>  //include the NeoPixel library

#define PIN         6 //variable for where you plug in your digital cable
#define NUMPIXELS   50 //how many pixels there are on your strip

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
// When we setup the NeoPixel library, we tell it how many pixels, and which pin to use to send signals.
// Note that for older NeoPixel strips you might need to change the third parameter--see the strandtest
// example for more information on possible values.

int delaytime = 100; //variable for delaytime

void setup() 
{
  pixels.begin(); 
  // This initializes the NeoPixel library.
}

void loop() 
{
  //this for-loop turns the lights on
  for(int i=0;i<NUMPIXELS;i++)
  {
    pixels.setPixelColor(i, pixels.Color(255,255,0)); 
    // pixels.Color takes RGB values
    //from 0,0,0 up to 255,255,255
    
    pixels.show();
    // This sends the updated 
    //pixel color to the hardware.
    
    delay(100);
    // Delay for 0.1 second
  }

  //this for-loop turns the lights off
  for(int i=0;i<NUMPIXELS;i++)
  {
    pixels.setPixelColor(i, pixels.Color(0,0,0)); 
    // pixels.Color takes RGB values
    //from 0,0,0 up to 255,255,255
    
    pixels.show();
    // This sends the updated 
    //pixel color to the hardware.
    
    delay(delaytime);
    // Delay for 0.1 second
  }
  
}
