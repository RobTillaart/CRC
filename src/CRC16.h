#pragma once
#include "CrcParameters.h"
#include <Arduino.h>

class CRC16
{
public:
  CRC16(uint16_t polynome = CRC16_POLYNOME,
        uint16_t initial  = CRC16_INITIAL,
        uint16_t xorOut   = CRC16_XOR_OUT,
        bool reverseIn    = CRC16_REF_IN,
        bool reverseOut   = CRC16_REF_OUT);

  void restart();
  uint16_t getCRC() const;
  size_t count() const;
  void add(uint8_t value);
  void add(const uint8_t * array, size_t length);
  void yieldAdd(const uint8_t * array, size_t length, const size_t yieldPeriod = CRC_DEFAULT_YIELD_PERIOD);

private:
  uint16_t _polynome;
  uint16_t _initial;
  uint16_t _xorOut;
  bool _reverseIn;
  bool _reverseOut;
  uint16_t _crc;
  size_t _count;
};
