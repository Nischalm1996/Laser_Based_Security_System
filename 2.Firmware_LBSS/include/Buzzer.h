/*
Class for controlling buzzer
Member Funcions:
0.Buzzer(int pin)
1. begin() in void setup
2. beep()
3. shortBeep()
4. longBeep() 
5. errorBeep() 
6. OkBeep() 
*/
#ifndef _BUZZER_H
#define _BUZZER_H
#include "Arduino.h"

class Buzzer
{
public:
  int _pin;

  Buzzer(int x)
  {
    _pin = x;
  }
  void begin()
  {
    pinMode(_pin, OUTPUT);
  }

  void beep(int x, int freq)
  {
    tone(_pin, freq, x);
  }

  void shortBeep()
  {
    tone(_pin, 440, 30);
  }

  void longBeep()
  {
    tone(_pin, 440, 200);
  }

  void errorBeep()
  {
    unsigned long previousMillis = 0;
    int freq[] = {440, 1200};
    unsigned int duration[] = {20, 250};
    int i = 0;
    while (i < 2)
    {
      unsigned long currentMillis = millis();

      if (currentMillis - previousMillis > duration[i])
      {
        previousMillis = currentMillis;
        tone(_pin, freq[i], duration[i]);
        i++;
      }
    }
  }

  void OkBeep()
  {
    tone(_pin, 440, 30);
  }
};
#endif //_BUZZER_H