#include "CRC.h"

uint8_t crc8(const uint8_t *array, size_t length,
             uint8_t polynome, uint8_t initial, uint8_t xorOut,
             bool reverseIn, bool reverseOut, size_t yieldPeriod)
{
  CRC8 crc(polynome, initial, xorOut, reverseIn, reverseOut);
  yieldPeriod == CRC_YIELD_DISABLED ?
    crc.add(array, length) :
    crc.add(array, length, yieldPeriod);
  return crc.getCRC();
}

uint16_t crc12(const uint8_t *array, size_t length,
               uint16_t polynome, uint16_t initial, uint16_t xorOut,
               bool reverseIn, bool reverseOut, size_t yieldPeriod)
{
  CRC12 crc(polynome, initial, xorOut, reverseIn, reverseOut);
  yieldPeriod == CRC_YIELD_DISABLED ?
    crc.add(array, length) :
    crc.add(array, length, yieldPeriod);
  return crc.getCRC();
}

uint16_t crc16(const uint8_t *array, size_t length,
               uint16_t polynome, uint16_t initial, uint16_t xorOut,
               bool reverseIn, bool reverseOut, size_t yieldPeriod)
{
  CRC16 crc(polynome, initial, xorOut, reverseIn, reverseOut);
  yieldPeriod == CRC_YIELD_DISABLED ?
    crc.add(array, length) :
    crc.add(array, length, yieldPeriod);
  return crc.getCRC();
}

uint32_t crc32(const uint8_t *array, size_t length,
               uint32_t polynome, uint32_t initial, uint32_t xorOut,
               bool reverseIn, bool reverseOut, size_t yieldPeriod)
{
  CRC32 crc(polynome, initial, xorOut, reverseIn, reverseOut);
  yieldPeriod == CRC_YIELD_DISABLED ?
    crc.add(array, length) :
    crc.add(array, length, yieldPeriod);
  return crc.getCRC();
}

uint64_t crc64(const uint8_t *array, size_t length,
               uint64_t polynome, uint64_t initial, uint64_t xorOut,
               bool reverseIn, bool reverseOut, size_t yieldPeriod)
{
  CRC64 crc(polynome, initial, xorOut, reverseIn, reverseOut);
  yieldPeriod == CRC_YIELD_DISABLED ?
    crc.add(array, length) :
    crc.add(array, length, yieldPeriod);
  return crc.getCRC();
}
