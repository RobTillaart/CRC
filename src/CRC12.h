#pragma once
#include "CrcParameters.h"
#include <Arduino.h>

class CRC12
{
public:
  CRC12(const uint16_t polynome = CRC12_POLYNOME,
        const uint16_t initial  = CRC12_INITIAL,
        const uint16_t xorOut   = CRC12_XOR_OUT,
        const bool reverseIn    = CRC12_REF_IN,
        const bool reverseOut   = CRC12_REF_OUT);

  void reset();
  uint16_t getCRC() const;
  size_t count() const;
  void add(uint8_t value);
  void add(const uint8_t * array, size_t length);
  void yieldAdd(const uint8_t * array, size_t length, const size_t yieldPeriod = CRC_DEFAULT_YIELD_PERIOD);

private:
  const uint16_t _polynome;
  const uint16_t _initial;
  const uint16_t _xorOut;
  const bool _reverseIn;
  const bool _reverseOut;
  uint16_t _crc;
  size_t _count;
};
