#include <Arduino.h>
#include "Buzzer.h"
#include "LED.h"
#include "LDR.h"
#include "GSM_MODULE.h"
#include "LASER.h"

//7899302011 -- number to send SMS
//SIM CARD number: 7348982783
const String PHONE = "+919060344544";

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
  pinMode(13, OUTPUT);

  //LED Begin and turn ON and OFF
  ledObj.ledOn();
  delay(1500);
  ledObj.ledOff();

  //LASER System begin and ON
  laserobj.begin();
  laserobj.laserOn();
  delay(2500);
  laserobj.laserOff();

  //Buzzer check
  buzz.begin();
  buzz.beep(3000, 5000);
  laserobj.laserOn();
  //LDR begin
  ldrObj.begin();

  //GSM send message

  gsmObj.sendMessage("System initiated! \n Reply with 1.ON or 2.OFF to control system", PHONE);
  gsmObj.beginReadSMS();
}

void loop()
{
  int8_t count = 0;
  if (LASER_STATUS)
  {
    if (ldrObj.readInput())
    {
      ledObj.ledOn();
      buzz.beep(10, 4500);
      count++;
    }
    else
    {
      ledObj.ledOff();
    }
  }

  if (count > 2)
  {
    //send GSM Message
    gsmObj.sendMessage("INTRUDER DETECTED!!", PHONE);
    count = 0;
  }
  if (LASER_CONTROL)
  {
    laserobj.laserOn();
  }
  else
  {
    laserobj.laserOff();
  }

  gsmObj.readSMSAndAct();
}