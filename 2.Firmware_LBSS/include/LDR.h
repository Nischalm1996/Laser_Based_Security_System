/*
Member Functions
1. LDR(int x) sets the pin to use
2.boolean readInput()
*/
#ifndef _LDR_H
#define _LDR_H
#include "Arduino.h"

class LDR
{
public:
    int _pin;
    LDR(int x)
    {
        _pin = x;
        pinMode(_pin, INPUT);
    }
    boolean readInput()
    {
        boolean state = digitalRead(_pin);
        return (state);
    }
};

#endif