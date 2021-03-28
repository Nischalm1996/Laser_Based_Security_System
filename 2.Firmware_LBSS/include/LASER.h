/* function to run LASER on board.
Member functions
1. LASER(int pin)
2. laserOn
3.laserOff
 
*/
boolean LASER_STATUS = false;

#ifndef _LASER_H
#define _LASER_H
#include "Arduino.h"

#define LASER_PIN 5
#define LASER1_PIN 6

class LASER
{
public:
    int _pin;

    LASER(int x)
    {
        _pin = x;
        pinMode(_pin, OUTPUT);
    }
    void begin()
    {
        pinMode(_pin, OUTPUT);
    }
    void laserOn()
    {
        digitalWrite(_pin, HIGH);
        LASER_STATUS = true;
    }
    void laserOff()
    {
        digitalWrite(_pin, LOW);
        LASER_STATUS = false;
    }
};
#endif //LASER_H