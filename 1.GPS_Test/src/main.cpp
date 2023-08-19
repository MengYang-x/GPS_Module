#include <Arduino.h>
#include "OLED.h"
void setup()
{
  Serial.begin(115200);
  OLED_Init();
}

void loop()
{
  Display_GPS();
}
