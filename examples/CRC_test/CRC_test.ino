#include "CRC.h"
#include "printHelpers.h"  // for the 64 bit...

char str[24] =  "123456789";


void setup()
{
  Serial.begin(115200);
  Serial.println(__FILE__);

  uint8_t * data = (uint8_t *) &str[0];

  Serial.println("Verified with - https://crccalc.com/ \n");

  Serial.print("TEST:\t");
  Serial.println(str);
  Serial.print("CRC8:\t");
  Serial.println(crc8(data, 9), HEX);
  Serial.print("CRC16:\t");
  Serial.println(crc16(data, 9), HEX);
  Serial.print("CRC32:\t");
  Serial.println(crc32(data, 9), HEX);
//  Serial.print("*CRC64:\t");
//  uint64_t t = crc64(data, 9);
//  Serial.println(print64(t, HEX));
  
  Serial.println("\n\nDone...");
}


void loop()
{
}