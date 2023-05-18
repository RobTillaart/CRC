#pragma once
#include "CrcParameters.h"
#include <Arduino.h>

class FastCRC32
{
public:
  FastCRC32();

  void restart();
  uint32_t calc() const;
  size_t count() const;
  void add(uint8_t value);
  void add(const uint8_t *array, size_t length);
  void add(const uint8_t *array, size_t length, size_t yieldPeriod);

private:
  uint32_t _crc;
  size_t _count;
};
