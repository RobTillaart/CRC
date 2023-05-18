# 1 "/tmp/tmp3vzyqt8i"
#include <Arduino.h>
# 1 "/home/tsiselsk/Projects/private/CRC/examples/CRC32_test/CRC32_test.ino"
#include "CRC32.h"

char str[24] = "123456789";

CRC32 crc;
void setup();
void loop();
void test();
#line 8 "/home/tsiselsk/Projects/private/CRC/examples/CRC32_test/CRC32_test.ino"
void setup()
{
  Serial.begin(115200);
  Serial.println(__FILE__);



  test();
}


void loop()
{
}


void test()
{
  crc.add((uint8_t*)str, 9);
  Serial.println(crc.calc(), HEX);

  crc.restart();
  for (int i = 0; i < 9; i++)
  {
    crc.add(str[i]);
  }
  Serial.println(crc.calc(), HEX);
  Serial.println(crc.count());
}