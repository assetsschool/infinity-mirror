/*
 *  MicrophoneLights.ino
 * 
 *  Created by Iain Moncrief
 *  Wednesday, March 20, 2019
 *  
 */

#define SQUELCH 200

#define LEDPIN 6
#define MICPIN 0

int micValue = 0;

void setup()
{
    Serial.begin(9600);

    pinMode(LEDPIN, OUTPUT);
}

void loop()
{

    micValue = map(analogRead(MICPIN), 0, 513, 0, 255);

    if (micValue > SQUELCH)
    {
        digitalWrite(LEDPIN, HIGH);
    }
    else
    {
        digitalWrite(LEDPIN, LOW);
    }

    // unsigned long startMillis = millis(); // Start of sample window
    // unsigned int peakToPeak = 0;          // peak-to-peak level

    // unsigned int signalMax = 0;
    // unsigned int signalMin = 1024;

    // // collect data for 50 mS
    // while (millis() - startMillis < sampleWindow)
    // {
    //     sample = analogRead(0);
    //     if (sample < FLATTOP) // toss out spurious readings
    //     {
    //         if (sample > signalMax)
    //         {
    //             signalMax = sample; // save just the max levels
    //         }
    //         else if (sample < signalMin)
    //         {
    //             signalMin = sample; // save just the min levels
    //         }
    //     }
    // }
    // peakToPeak = signalMax - signalMin;       // max - min = peak-peak amplitude
    // double volts = (peakToPeak * 5.0) / 1024; // convert to volts

    // Serial.println(volts);

    // if (volts > 2) {
    //     digitalWrite(LEDPIN, HIGH);
    // } else {
    //     digitalWrite(LEDPIN, LOW);
    // }
}