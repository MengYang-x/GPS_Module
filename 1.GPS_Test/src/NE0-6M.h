#pragma once
#include <Arduino.h>

typedef struct
{
    double lat; // 经度
    double lng; // 纬度
} Location;

typedef struct
{
    uint16_t year;
    uint8_t month;
    uint8_t day;
    uint8_t hour;
    uint8_t minute;
    uint8_t second;
} Date;

void GetLocation(Location &location);
void GetDate(Date &date);