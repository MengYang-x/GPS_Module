/*
 * NE0-6M，GPS定位模块测试
 */
#include <Arduino.h>
#include <TinyGPS++.h>
#include <SoftwareSerial.h>
#include <NE0-6M.h>

static const uint8_t RXPin = 13;
static const uint8_t TXPin = 12;
static const uint16_t GPSBaud = 9600;

SoftwareSerial NEO_6M(RXPin, TXPin);
TinyGPSPlus gps;

void GPS_Init()
{
    NEO_6M.begin(GPSBaud);
}

void GetLocation(Location &location)
{
    Serial.print(F("Location: "));
    if (gps.location.isValid())
    {
        Serial.print(gps.location.lat(), 6);
        Serial.print(F(","));
        Serial.print(gps.location.lng(), 6);

        location.lat = gps.location.lat();
        location.lng = gps.location.lng();
    }
    else
    {
        Serial.print(F("Location INVALID"));
    }
}

void GetDate(Date &date)
{
    if (gps.time.isValid())
    {
        if (gps.time.hour() < 10)
            Serial.print(F("0"));
        Serial.print(gps.time.hour());
        Serial.print(F(":"));
        if (gps.time.minute() < 10)
            Serial.print(F("0"));
        Serial.print(gps.time.minute());
        Serial.print(F(":"));
        if (gps.time.second() < 10)
            Serial.print(F("0"));
        Serial.print(gps.time.second());
        Serial.print(F("."));
        if (gps.time.centisecond() < 10)
            Serial.print(F("0"));
        Serial.print(gps.time.centisecond());

        date.year = gps.date.year();
        date.month = gps.date.month();
        date.day = gps.date.day();
        date.hour = gps.time.hour();
        date.minute = gps.time.minute();
        date.second = gps.time.second();
    }
    else
    {
        Serial.print(F("Date INVALID"));
    }
}