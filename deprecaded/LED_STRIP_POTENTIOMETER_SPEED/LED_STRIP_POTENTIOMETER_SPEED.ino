#include <Adafruit_NeoPixel.h>  //include the NeoPixel library

#define PIN         6 //variable for where you plug in your digital cable
#define NUMPIXELS   50 //how many pixels there are on your strip

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
// When we setup the NeoPixel library, we tell it how many pixels, and which pin to use to send signals.
// Note that for older NeoPixel strips you might need to change the third parameter--see the strandtest
// example for more information on possible values.

int potentiometer = A1; //// analog pin used to connect the potentiometer
int val;    // variable to read the value from the analog pin potentiometer

int delaytime = 1000; //variable for delaytime

void setup() 
{
  pixels.begin(); 
  // This initializes the NeoPixel library.
}

void loop() 
{

  for (int i = 0; i < 50; i++)
  {
    val = analogRead(potentiometer);  //read potentiometer values
    pixels.setPixelColor(i, pixels.Color(0,0,150)); 
    pixels.show();
    delay(val);  
  }

    for (int i = 0; i < 50; i++)
  {
    val = analogRead(potentiometer);
    pixels.setPixelColor(i, pixels.Color(0,0,0)); 
    pixels.show();
    delay(val);
  }
  
}
