/* function to run led on board.
Member functions
1. LED(int pin)
2. ledOn
3.ledOff
4. blinkLED(int duration,int iterations)
 
*/

#ifndef _LED_H
#define _LED_H
#include "Arduino.h"
class Led
{
public:
    int _pin;

    Led(int x)
    {
        _pin = x;
    }
    void begin()
    {
        pinMode(_pin, OUTPUT);
    }
    void ledOn()
    {
        digitalWrite(_pin, HIGH);
    }
    void ledOff()
    {
        digitalWrite(_pin, LOW);
    }
    void blinkLED(unsigned int duration, int iterations)
    {
        int i;

        for (i = 0; i <= iterations; i++)
        {
            unsigned long previousMillis = 0;
            boolean ledState = LOW;
            unsigned long currentMillis = millis();

            if ((ledState == HIGH) && (currentMillis - previousMillis >= duration))
            {
                ledState = LOW;                 // Turn it off
                previousMillis = currentMillis; // Remember the time
                digitalWrite(_pin, ledState);   // Update the actual LED
            }
            else if ((ledState == LOW) && (currentMillis - previousMillis >= duration))
            {
                ledState = HIGH;                // turn it on
                previousMillis = currentMillis; // Remember the time
                digitalWrite(_pin, ledState);   // Update the actual LED
            }
        }
    }
};

#endif //_LED_H