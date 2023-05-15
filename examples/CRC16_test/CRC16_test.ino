#include "CRC16.h"
#include "CRC.h"

char str[24] =  "123456789";

CRC16 crc;


void setup()
{
  Serial.begin(115200);
  Serial.println(__FILE__);

  // Serial.println("Verified with - http://zorc.breitbandkatze.de/crc.html \n");

  test();
}


void loop()
{
}


void test()
{
  Serial.println(crc16((uint8_t *) str, 9), HEX);
  
  crc.add((uint8_t*)str, 9);
  Serial.println(crc.getCRC(), HEX);

  crc.restart();
  for (int i = 0; i < 9; i++)
  {
    crc.add(str[i]);
  }
  Serial.println(crc.getCRC(), HEX);
  Serial.println(crc.count());
}
