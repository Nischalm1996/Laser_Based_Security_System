#include <Arduino.h>
#include "Buzzer.h"
#include "LED.h"
#include "LDR.h"
#include "GSM_MODULE.h"
#include "LASER.h"

//7899302011 -- number to send SMS
//SIM CARD number: 7348982783
const String PHONE = "+917899302011";

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
int8_t count = 0;

void setup()
{
  pinMode(13, OUTPUT);
  Serial.begin(9600);

  //LED Begin and turn ON and OFF
  ledObj.ledOn();
  delay(2000);
  ledObj.ledOff();
  Serial.println("LEd test Done!");
  //LASER System begin and ON
  laserobj.begin();
  laserobj.laserOn();
  delay(2500);
  laserobj.laserOff();
  Serial.println("Laser test Done!");

  //Buzzer check
  buzz.begin();
  buzz.beep(3000, 5000);
  Serial.println("Buzzer test Done!");
  //LDR begin
  ldrObj.begin();

  //GSM send message

  gsmObj.sendMessage("System initiated! Reply with ON or OFF to control system", PHONE);
  gsmObj.beginReadSMS();
}

void loop()
{

  if (LASER_CONTROL)
  {
    if (ldrObj.readInput())
    {
      ledObj.ledOn();
      buzz.beep(1, 4500);
      count++;
    }
    else
    {
      ledObj.ledOff();
    }
  }

  if (count >= 100)
  {
    Serial.println("INTRUDER!!!");
    //send GSM Message
    buzz.beep(10000, 3000);
    gsmObj.sendMessage("INTRUDER DETECTED!!", PHONE);
    delay(10000);
    count = 0;
  }
  Serial.println(count);
  if (LASER_CONTROL)
  {
    laserobj.laserOn();
    //Serial.println("Laser On");
  }
  else
  {
    laserobj.laserOff();
    //Serial.println("Laser Off");
  }

  gsmObj.readSMSAndAct();
}