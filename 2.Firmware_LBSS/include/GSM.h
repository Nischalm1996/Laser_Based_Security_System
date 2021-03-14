/*
Member functions
1.GSM
*/

#ifndef _GSM_H
#define _GSM_H
#include "Arduino.h"
#include <SoftwareSerial.h>
#include <Sim800L.h>
#define RX_GSM 3
#define TX_GSM 4

Sim800L GSM(_RX_pin, _TX_pin);

class Gsm
{
public:
    
    void begin()
    {
        Serial.begin(9600);
        GSM.begin(4800);
        GSM.delAllSms(); // this is optional
        while (!GSM.prepareForSmsReceive())
        {
            delay(1000);
        }
    }
    void readMessage()
    {
        byte index = GSM.checkForSMS();
        if (index != 0)
        {
            String sms =  GSM.readSms(index);

        }
    }
    void deleteSMS()
    {
        return(delAllSms());
    }
    boolean sendMessage(String text,String number)
    {
        GSM.begin(4800);
        error = GSM.sendSms(number, text);
        return error;
    }
};

#endif