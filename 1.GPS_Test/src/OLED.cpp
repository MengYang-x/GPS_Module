/*
 * 0.96寸OLED数据显示
 */
#include "NE0-6M.h"
#include <U8g2lib.h>
#include <Wire.h>

static const uint8_t scl = 15;
static const uint8_t sda = 4;

Location GPS_Location;
Date GPS_Date;

U8G2_SSD1306_128X64_NONAME_F_SW_I2C u8g2(U8G2_R0, /*clock=*/scl, /*data=*/sda, /*reset=*/U8X8_PIN_NONE);

void OLED_Init()
{
    u8g2.begin();
    u8g2.enableUTF8Print();
    u8g2.setFont(u8g2_font_wqy12_t_gb2312b);
}

void updateGPS_Data()
{
    GetLocation(GPS_Location);
    GetDate(GPS_Date);
}

void Display_GPS()
{
    updateGPS_Data();

    u8g2.clearBuffer();
    u8g2.setCursor(0, 10);
    u8g2.print("Lat:");
    u8g2.print(GPS_Location.lat, 6);

    u8g2.setCursor(0, 28);
    u8g2.print("Lng:");
    u8g2.print(GPS_Location.lng, 6);

    u8g2.setCursor(0, 46);
    u8g2.print("Date:");
    u8g2.print(GPS_Date.year);
    u8g2.print("-");
    u8g2.print(GPS_Date.month);
    u8g2.print("-");
    u8g2.print(GPS_Date.day);

    u8g2.setCursor(0, 64);
    u8g2.print(GPS_Date.hour);
    u8g2.print(":");
    u8g2.print(GPS_Date.minute);
    u8g2.print(":");
    u8g2.print(GPS_Date.minute);

    u8g2.sendBuffer();
}