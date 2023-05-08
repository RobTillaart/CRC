#pragma once
#include "CrcFastReverse.h"
#include "CrcParameters.h"
#include <Arduino.h>

class CRC16
{
public:
  CRC16(const uint16_t polynome = CRC16_POLYNOME,
        const uint16_t initial  = CRC16_INITIAL,
        const uint16_t xorOut   = CRC16_XOR_OUT,
        const bool reverseIn    = CRC16_REF_IN,
        const bool reverseOut   = CRC16_REF_OUT);

  void reset();
  
  void add(uint8_t value);
  void add(const uint8_t * array, size_t length);
  void yieldAdd(uint8_t value);
  void yieldAdd(const uint8_t * array, size_t length);

  uint16_t getCRC() const;
  size_t count() const;

private:
  const uint16_t _polynome;
  const uint16_t _initial;
  const uint16_t _xorOut;
  const bool _reverseIn;
  const bool _reverseOut;
  uint16_t _crc;
  size_t _count;
};
