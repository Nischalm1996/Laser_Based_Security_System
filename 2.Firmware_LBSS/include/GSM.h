/*
Member functions
1.GSM
*/

#ifndef _GSM_H
#define _GSM_H
#include "Arduino.h"
#include <SoftwareSerial.h>
#include <Sim800L.h>
#include "LASER.h"

#define RX_GSM 3
#define TX_GSM 4
char PHONE[21] = "919060344544";

Sim800L GSM(RX_GSM, TX_GSM);
LASER laser(LASER_PIN);
class Gsm
{
public:
    void begin()
    {
        laser.begin();
        laser.laserOn();
        Serial.begin(9600);
        GSM.begin(4800);
        GSM.delAllSms(); // this is optional
        while (!GSM.prepareForSmsReceive())
        {
            delay(1000);
        }
    }
    void readMessageAndRespond()
    {
        byte index = GSM.checkForSMS();
        String sms;
        if (index != 0)
        {
            sms = GSM.readSms(index);
        }
        if (sms.equals("ON"))
        {
            // Send SMS saying Laser is alread on if Switched on else switch it on.
            if (LASER_STATUS)
            {
                //send message saying already on
                sendMessage("Laser Security System Already ON!", PHONE);
            }
            else
            {
                laser.laserOn();
                sendMessage("Laser Security System Turned ON!", PHONE);
            }
        }
        else if (sms.equals("OFF"))
        {
            if (!LASER_STATUS)
            {
                //send message saying already off
                sendMessage("Laser Security System Already OFF!", PHONE);
            }
            else
            {
                laser.laserOff();
                sendMessage("Laser Security System Turned OFF!", PHONE);
            }
        }
        else
        {
            //send sms saying didnt understand.send ON or OFF for operations.
        }
        //delete all SMS on 800L
        deleteSMS();
    }
    void deleteSMS()
    {
        return (GSM.delAllSms());
    }
    void sendMessage(char* text, char* number)
    {
        GSM.begin(4800);
        GSM.sendSms(number, text);
    }
};

#endif