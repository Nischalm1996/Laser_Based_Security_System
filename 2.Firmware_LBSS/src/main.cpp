#include <Arduino.h>
#include "Buzzer.h"
#include "LED.h"
#include "LDR.h"
#include "LASER.h"
//7899302011 -- number to send SMS

//Pin definitions to mind
#define LASER_PIN 5
#define LASER1_PIN 6
#define BUZZER 8
#define LED 10
#define DETECT 2
#define DETECT1 7
#define RX_GSM 3
#define TX_GSM 4

//creating classes
Buzzer buzz(BUZZER);
Led ledObj(LED);
LDR ldrObj(DETECT);
LASER laserObj(LASER_PIN);

void setup()
{
  // Setting up buzzer
  buzz.longBeep();
  // setting up LED
  ledObj.ledOn();
  delay(1000);
  ledObj.ledOff();

  // setting up GSM Module
  // Setting up laser detection
  laserObj.laserOn();
  delay(20);
  laserObj.laserOff();
  delay(20);
  laserObj.laserOn();
  delay(20);
  laserObj.laserOff();
  delay(20);
  laserObj.laserOn();
  delay(20);
  laserObj.laserOn();

  // setting up laser transmission
}

void loop()
{
  if(ldrObj.readInput())
  {
    ledObj.ledOff();
  }
  else {
    ledObj.ledOn();
  }
}