#include <Arduino.h>
#include "Buzzer.h"
#include "LED.h"
#include "LDR.h"
#include "GSM_MODULE.h"
#include "LASER.h"

//7899302011 -- number to send SMS
//SIM CARD number: 7348982783
const char *PHONE = "+919060344544";

//Pin definitions to mind
#define BUZZER 8
#define LED 10
#define DETECT 2
#define DETECT1 7
//creating classes
Buzzer buzz(BUZZER);
Led ledObj(LED);
LDR ldrObj(DETECT);
GSM_MODULE gsmObj;
LASER laserobj(LASER_PIN);

void setup()
{
  // Setting up buzzer
  buzz.begin();
  buzz.beep(1000, 4000);

  // setting up LED
  ledObj.begin();
  ledObj.blinkLED(300, 10);

  // Setting up laser detection
  ldrObj.begin();

  // setting up laser transmission
  laserobj.begin();
  laserobj.laserOn();

  // setting up GSM Module
  gsmObj.sendMessage("LBSS Turned On!", PHONE);
  gsmObj.beginReadSMS();
}

void loop()
{
  //if laser goees off then led turns off
  if (LASER_STATUS)
  {
    if (ldrObj.readInput())
    {
      ledObj.ledOn();
    }
    else
    {
      ledObj.ledOff();
    }
  }

  gsmObj.readSMSAndAct();
}