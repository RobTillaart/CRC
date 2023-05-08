#pragma once
#include "CrcParameters.h"
#include <Arduino.h>

class FastCRC32
{
public:
  FastCRC32();

  void reset();
  uint32_t getCRC() const;
  size_t count() const;
  void add(uint8_t value);
  void add(const uint8_t * array, size_t length);
  void yieldAdd(const uint8_t * array, size_t length, const size_t yieldPeriod = CRC_DEFAULT_YIELD_PERIOD);

private:
  uint32_t _crc;
  size_t _count;
};
