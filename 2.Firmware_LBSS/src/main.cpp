#include <Arduino.h>
#include "Buzzer.h"
#include "LED.h"
#include "LDR.h"
#include "GSM.h"

//7899302011 -- number to send SMS
//SIM CARD number: 7348982783

//Pin definitions to mind
#define BUZZER 8
#define LED 10
#define DETECT 2
#define DETECT1 7

//creating classes
Buzzer buzz(BUZZER);
Led ledObj(LED);
LDR ldrObj(DETECT);
Gsm gsmObj;
void setup()
{
  // Setting up buzzer
  buzz.begin();
  buzz.longBeep();
  // setting up LED
  ledObj.begin();
  ledObj.blinkLED(300,10);
  // setting up GSM Module
  gsmObj.begin();
  // Setting up laser detection
  ldrObj.begin();
  // setting up laser transmission
}

void loop()
{
  gsmObj.readMessageAndRespond();
  if(LASER_STATUS)
  {
    if(ldrObj.readInput())
    {
      //send message
      gsmObj.sendMessage("INTRUDER DETECTED!!",PHONE);
      // alert Buzzer
      buzz.errorBeep();
      // Blink LED
      ledObj.blinkLED(500,5);
    }
  }
}