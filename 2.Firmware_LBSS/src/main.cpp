#include <Arduino.h>
#include "Buzzer.h"
#include "LED.h"
#include "LDR.h"
#include "GSM.h"
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
Gsm gsmObj;
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
  laserobj.laserOn();
  delay(5000);
  laserobj.laserOff();

  // setting up GSM Module
  gsmObj.sendMessage("Laser Based Security System Turned On!", PHONE);
  gsmObj.beginRead();
}

void loop()
{
  //if laser goees off then led turns off
  if (ldrObj.readInput())
  {
    ledObj.ledOff();
  }
  else
  {
    ledObj.ledOn();
  }

//GSM reading message
  String mess = gsmObj.readMessage();
  if (mess.equals("ON"))
  {
    laserobj.laserOn();
  }
  else if (mess.equalsIgnoreCase("OFF"))
  {
    laserobj.laserOff();
  }

    if (LASER_STATUS)
    {
      if (ldrObj.readInput())
      {
        //send message
        //gsmObj.sendMessage("INTRUDER DETECTED!!",PHONE);
        // alert Buzzer
        buzz.beep(800, 300);
        // Blink LED
        ledObj.blinkLED(500, 2);
      }
    }
}