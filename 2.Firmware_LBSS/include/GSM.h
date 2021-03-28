/* member functions
1. */

#ifndef _GSM_H
#define _GSM_H
#include "Arduino.h"
#include <Sim800L.h>
#include <SoftwareSerial.h>

#define RX 4
#define TX 3
Sim800L GSM(RX, TX);

class Gsm
{
public:
    void beginRead()
    {
        GSM.delAllSms(); // this is optional
        while (!GSM.prepareForSmsReceive())
        {
            delay(1000);
        }
    }
    void sendMessage(char *text, char *number)
    {
        GSM.begin(4800);
        bool error = GSM.sendSms(number, text);
    }
    String readMessage()
    {
        byte index = GSM.checkForSMS();
        if (index != 0)
        {
            return (GSM.readSms(index));
        }
    }
};
#endif //_GSM_H