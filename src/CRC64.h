#pragma once
#include "CrcFastReverse.h"
#include "CrcParameters.h"
#include <Arduino.h>

class CRC64
{
public:
  CRC64(const uint64_t polynome = CRC64_POLYNOME,
        const uint64_t initial  = CRC64_INITIAL,
        const uint64_t xorOut   = CRC64_XOR_OUT,
        const bool reverseIn    = CRC64_REF_IN,
        const bool reverseOut   = CRC64_REF_OUT);

  void reset();
  
  void add(uint8_t value);
  void add(const uint8_t * array, size_t length);
  void yieldAdd(uint8_t value);
  void yieldAdd(const uint8_t * array, size_t length);

  uint64_t getCRC() const;
  size_t count() const;

private:
  const uint64_t _polynome;
  const uint64_t _initial;
  const uint64_t _xorOut;
  const bool _reverseIn;
  const bool _reverseOut;
  uint64_t _crc;
  size_t _count;
};
