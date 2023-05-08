#include "CRC.h"

uint8_t crc8(const uint8_t *array, size_t length,
             const uint8_t polynome, const uint8_t initial, const uint8_t xorOut,
             const bool reverseIn, const bool reverseOut)
{
  CRC8 crc(polynome, initial, xorOut, reverseIn, reverseOut);
  crc.add(array, length);
  return crc.getCRC();
}

uint16_t crc12(const uint8_t *array, size_t length,
               const uint16_t polynome, const uint16_t initial, const uint16_t xorOut,
               const bool reverseIn, const bool reverseOut)
{
  CRC12 crc(polynome, initial, xorOut, reverseIn, reverseOut);
  crc.add(array, length);
  return crc.getCRC();
}

uint16_t crc16(const uint8_t *array, size_t length,
               const uint16_t polynome, const uint16_t initial, const uint16_t xorOut,
               const bool reverseIn, const bool reverseOut)
{
  CRC16 crc(polynome, initial, xorOut, reverseIn, reverseOut);
  crc.add(array, length);
  return crc.getCRC();
}

uint32_t crc32(const uint8_t *array, size_t length,
               const uint32_t polynome, const uint32_t initial, const uint32_t xorOut,
               const bool reverseIn, const bool reverseOut)
{
  CRC32 crc(polynome, initial, xorOut, reverseIn, reverseOut);
  crc.add(array, length);
  return crc.getCRC();
}

uint64_t crc64(const uint8_t *array, size_t length,
               const uint64_t polynome, const uint64_t initial, const uint64_t xorOut,
               const bool reverseIn, const bool reverseOut)
{
  CRC64 crc(polynome, initial, xorOut, reverseIn, reverseOut);
  crc.add(array, length);
  return crc.getCRC();
}

uint8_t yieldCrc8(const uint8_t *array, size_t length,
                  const uint8_t polynome, const uint8_t initial, const uint8_t xorOut,
                  const bool reverseIn, const bool reverseOut)
{
  CRC8 crc(polynome, initial, xorOut, reverseIn, reverseOut);
  crc.yieldAdd(array, length);
  return crc.getCRC();
}

uint16_t yieldCrc12(const uint8_t *array, size_t length,
                    const uint16_t polynome, const uint16_t initial, const uint16_t xorOut,
                    const bool reverseIn, const bool reverseOut)
{
  CRC12 crc(polynome, initial, xorOut, reverseIn, reverseOut);
  crc.yieldAdd(array, length);
  return crc.getCRC();
}

uint16_t yieldCrc16(const uint8_t *array, size_t length,
                    const uint16_t polynome, const uint16_t initial, const uint16_t xorOut,
                    const bool reverseIn, const bool reverseOut)
{
  CRC16 crc(polynome, initial, xorOut, reverseIn, reverseOut);
  crc.yieldAdd(array, length);
  return crc.getCRC();
}

uint32_t yieldCrc32(const uint8_t *array, size_t length,
                    const uint32_t polynome, const uint32_t initial, const uint32_t xorOut,
                    const bool reverseIn, const bool reverseOut)
{
  CRC32 crc(polynome, initial, xorOut, reverseIn, reverseOut);
  crc.yieldAdd(array, length);
  return crc.getCRC();
}

uint64_t yieldCrc64(const uint8_t *array, size_t length,
                    const uint64_t polynome, const uint64_t initial, const uint64_t xorOut,
                    const bool reverseIn, const bool reverseOut)
{
  CRC64 crc(polynome, initial, xorOut, reverseIn, reverseOut);
  crc.yieldAdd(array, length);
  return crc.getCRC();
}