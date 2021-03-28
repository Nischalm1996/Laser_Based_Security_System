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

        for (i = 0; i <= (iterations * 2); i++)
        {
            unsigned long previousMillis = 0;
            unsigned long currentMillis = millis();
            int ledState = LOW;
            if (currentMillis - previousMillis >= duration)
            {
                // save the last time you blinked the LED
                previousMillis = currentMillis;

                // if the LED is off turn it on and vice-versa:
                if (ledState == LOW)
                {
                    ledState = HIGH;
                }
                else
                {
                    ledState = LOW;
                }

                // set the LED with the ledState of the variable:
                digitalWrite(_pin, ledState);
            }
        }
    }
};

#endif //_LED_H