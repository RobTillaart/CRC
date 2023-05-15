#pragma once
#include "CrcParameters.h"
#include <Arduino.h>

class CRC32
{
public:
  CRC32(uint32_t polynome = CRC32_POLYNOME,
        uint32_t initial  = CRC32_INITIAL,
        uint32_t xorOut   = CRC32_XOR_OUT,
        bool reverseIn    = CRC32_REF_IN,
        bool reverseOut   = CRC32_REF_OUT);

  void restart();
  uint32_t getCRC() const;
  size_t count() const;
  void add(uint8_t value);
  void add(const uint8_t * array, size_t length);
  void yieldAdd(const uint8_t * array, size_t length, const size_t yieldPeriod = CRC_DEFAULT_YIELD_PERIOD);

private:
  uint32_t _polynome;
  uint32_t _initial;
  uint32_t _xorOut;
  bool _reverseIn;
  bool _reverseOut;
  uint32_t _crc;
  size_t _count;
};
