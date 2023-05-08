#pragma once
#include "CrcParameters.h"
#include <Arduino.h>

class CRC8
{
public:
  CRC8(const uint8_t polynome = CRC8_POLYNOME,
       const uint8_t initial  = CRC8_INITIAL,
       const uint8_t xorOut   = CRC8_XOR_OUT,
       const bool reverseIn   = CRC8_REF_IN,
       const bool reverseOut  = CRC8_REF_OUT);

  void reset();
  uint8_t getCRC() const;
  size_t count() const;
  void add(uint8_t value);
  void add(const uint8_t * array, size_t length);
  void yieldAdd(const uint8_t * array, size_t length, const size_t yieldPeriod = CRC_DEFAULT_YIELD_PERIOD);

private:
  const uint8_t _polynome;
  const uint8_t _initial;
  const uint8_t _xorOut;
  const bool _reverseIn;
  const bool _reverseOut;
  uint8_t _crc;
  size_t _count;
};
