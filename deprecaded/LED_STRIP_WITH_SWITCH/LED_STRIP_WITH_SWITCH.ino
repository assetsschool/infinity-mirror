#include <Adafruit_NeoPixel.h>  //include the NeoPixel library

#define PIN         6 //variable for where you plug in your digital cable
#define NUMPIXELS   50 //how many pixels there are on your strip

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
// When we setup the NeoPixel library, we tell it how many pixels, and which pin to use to send signals.
// Note that for older NeoPixel strips you might need to change the third parameter--see the strandtest
// example for more information on possible values.

int buttonA = 8; //variable for switchA
int buttonB = 9; //variable for switchB
int buttonC = 10; //variable for switchC

int delaytime = 100; //variable for delaytime

void setup() 
{
  pixels.begin(); 
  // This initializes the NeoPixel library.
  
  pinMode(buttonA, INPUT_PULLUP);  
  //set up buttonA as input
  pinMode(buttonB, INPUT_PULLUP); 
  //set up buttonB as input
  pinMode(buttonC, INPUT_PULLUP); 
  //set up buttonC as input
}

void loop() 
{

  if (digitalRead(buttonA) == LOW)
  {
    //this for-loop turns the lights blue
    for(int i=0;i<NUMPIXELS;i++)
    {
      pixels.setPixelColor(i, pixels.Color(0,0,150)); 
      // pixels.Color takes RGB values
      //from 0,0,0 up to 255,255,255
    
      pixels.show();
      // This sends the updated 
      //pixel color to the hardware.
    
      delay(delaytime);
      // Delay for how long
    }
  }

  else if (digitalRead(buttonB) == LOW)
  {
    //this for-loop turns the lights red
    for(int i=0;i<NUMPIXELS;i++)
    {
      pixels.setPixelColor(i, pixels.Color(0,150,0)); 
      // pixels.Color takes RGB values
      //from 0,0,0 up to 255,255,255
    
      pixels.show();
      // This sends the updated 
      //pixel color to the hardware.
    
      delay(delaytime);
      // Delay for how long
    }
  }

  else if (digitalRead(buttonC) == LOW)
  {
     //this for-loop turns the lights green
     for(int i=0;i<NUMPIXELS;i++)
    {
       pixels.setPixelColor(i, pixels.Color(150,0,0)); 
       // pixels.Color takes RGB values
       //from 0,0,0 up to 255,255,255
    
       pixels.show();
       // This sends the updated 
       //pixel color to the hardware.
    
       delay(delaytime);
       // Delay for how long
      }
   }
  
}
