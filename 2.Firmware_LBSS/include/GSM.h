/*
Member functions
1.GSM
*/

#ifndef _GSM_H
#define _GSM_H
#include "Arduino.h"
#include <SoftwareSerial.h>

class GSM
{
public:
    int _RX_pin, _TX_pin;
    GSM(int RX, int TX)
    {
        _RX_pin = RX;
        _TX_pin = TX;
    }
    begin()
    {
        SoftwareSerial mySerial(_TX_pin, _RX_pin); //SIM800L Tx & Rx
        mySerial.begin(9600);
    }
    void sendMessage(String number, String text)
    {
        String _number = "AT+CMGS=\+"+number+"\ ";
        this.mySerial.println("AT"); //Once the handshake test is successful, it will back to OK
        updateSerial();

        mySerial.println("AT+CMGF=1"); // Configuring TEXT mode
        updateSerial();
        mySerial.println(_number); //change ZZ with country code and xxxxxxxxxxx with phone number to sms
        updateSerial();
        mySerial.print(text); //text content
        updateSerial();
        mySerial.write(26);
    }
};

#endif