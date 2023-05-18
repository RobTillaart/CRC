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

  void reset(uint32_t polynome = CRC32_POLYNOME,
             uint32_t initial  = CRC32_INITIAL,
             uint32_t xorOut   = CRC32_XOR_OUT,
             bool reverseIn    = CRC32_REF_IN,
             bool reverseOut   = CRC32_REF_OUT);

  void restart();
  uint32_t getCRC() const;
  size_t count() const;
  void add(uint8_t value);
  void add(const uint8_t *array, size_t length);
  void add(const uint8_t *array, size_t length, size_t yieldPeriod);

  void setPolynome(uint32_t polynome) { _polynome = polynome; }
  void setInitial(uint32_t initial) { _initial = initial; }
  void setXorOut(uint32_t xorOut) { _xorOut = xorOut; }
  void setReverseIn(bool reverseIn) { _reverseIn = reverseIn; }
  void setReverseOut(bool reverseOut) { _reverseOut = reverseOut; }

  uint32_t getPolynome() const { return _polynome; }
  uint32_t getInitial() const { return _initial; }
  uint32_t getXorOut() const { return _xorOut; }
  bool getReverseIn() const { return _reverseIn; }
  bool getReverseOut() const { return _reverseOut; }

private:
  uint32_t _polynome;
  uint32_t _initial;
  uint32_t _xorOut;
  bool _reverseIn;
  bool _reverseOut;
  uint32_t _crc;
  size_t _count;
};
