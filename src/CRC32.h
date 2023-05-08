#pragma once
#include "CrcFastReverse.h"
#include "CrcParameters.h"
#include <Arduino.h>

class CRC32
{
public:
  CRC32(const uint32_t polynome = CRC32_POLYNOME,
        const uint32_t initial  = CRC32_INITIAL,
        const uint32_t xorOut   = CRC32_XOR_OUT,
        const bool reverseIn    = CRC32_REF_IN,
        const bool reverseOut   = CRC32_REF_OUT);

  void reset();
  
  void add(uint8_t value);
  void add(const uint8_t * array, size_t length);

  uint32_t getCRC() const;
  size_t count() const;

private:
  const uint32_t _polynome;
  const uint32_t _initial;
  const uint32_t _xorOut;
  const bool _reverseIn;
  const bool _reverseOut;
  uint32_t _crc;
  size_t _count;
};


class YieldCRC32
{
public:
  YieldCRC32(const uint32_t polynome  = CRC32_POLYNOME,
             const uint32_t initial   = CRC32_INITIAL,
             const uint32_t xorOut    = CRC32_XOR_OUT,
             const bool reverseIn     = CRC32_REF_IN,
             const bool reverseOut    = CRC32_REF_OUT,
             const size_t yieldPeriod = DEFAULT_YIELD_PERIOD);


  void reset();
  
  void add(uint8_t value);
  void add(const uint8_t * array, size_t length);

  uint32_t getCRC() const;
  size_t count() const;

private:
  CRC32 _crc;
  const size_t _yieldPeriod;
};