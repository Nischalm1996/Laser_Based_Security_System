#include <Arduino.h>
#include "Buzzer.h"
//7899302011 -- number to send SMS

//Pin definitions to mind
#define LASER 5
#define LASER1 6
#define BUZZER 8
#define LED 10
#define DETECT 2
#define DETECT1 7
#define RX_GSM 3
#define TX_GSM 4

void setup()
{
  // Setting up buzzer
  Buzzer buzz(BUZZER);
  buzz.longBeep();
  // setting up LED
  Led ledObj(LED);
  ledObj.blinkLED(500, 3);
  // setting up GSM Module
  // Setting up laser detection
  // setting up laser transmission
}

void loop()
{
}