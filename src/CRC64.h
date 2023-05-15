#pragma once
#include "CrcParameters.h"
#include <Arduino.h>

class CRC64
{
public:
  CRC64(uint64_t polynome = CRC64_POLYNOME,
        uint64_t initial  = CRC64_INITIAL,
        uint64_t xorOut   = CRC64_XOR_OUT,
        bool reverseIn    = CRC64_REF_IN,
        bool reverseOut   = CRC64_REF_OUT);

  void reset(uint64_t polynome = CRC64_POLYNOME,
             uint64_t initial  = CRC64_INITIAL,
             uint64_t xorOut   = CRC64_XOR_OUT,
             bool reverseIn    = CRC64_REF_IN,
             bool reverseOut   = CRC64_REF_OUT);

  void restart();
  uint64_t getCRC() const;
  size_t count() const;
  void add(uint8_t value);
  void add(const uint8_t * array, size_t length);
  void yieldAdd(const uint8_t * array, size_t length, const size_t yieldPeriod = CRC_DEFAULT_YIELD_PERIOD);

  void setPolynome(uint64_t polynome) { _polynome = polynome; }
  void setInitial(uint64_t initial) { _initial = initial; }
  void setXorOut(uint64_t xorOut) { _xorOut = xorOut; }
  void setReverseIn(bool reverseIn) { _reverseIn = reverseIn; }
  void setReverseOut(bool reverseOut) { _reverseOut = reverseOut; }

  uint64_t getPolynome() const { return _polynome; }
  uint64_t getInitial() const { return _initial; }
  uint64_t getXorOut() const { return _xorOut; }
  bool getReverseIn() const { return _reverseIn; }
  bool getReverseOut() const { return _reverseOut; }

private:
  uint64_t _polynome;
  uint64_t _initial;
  uint64_t _xorOut;
  bool _reverseIn;
  bool _reverseOut;
  uint64_t _crc;
  size_t _count;
};
