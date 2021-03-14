/* function to run LASER on board.
Member functions
1. LASER(int pin)
2. laserOn
3.laserOff
 
*/

#ifndef _LASER_H
#define _LASER_H
#include "Arduino.h"
class LASER
{
public:
    int _pin;

    LASER(int x)
    {
        _pin = x;
        pinMode(_pin, OUTPUT);
    }
    void laserOn()
    {
        digitalWrite(_pin, HIGH);
    }
    void laserOff()
    {
        digitalWrite(_pin, LOW);
    }
};
#endif //LASER_H