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

  void reset(uint16_t polynome = CRC16_POLYNOME,
             uint16_t initial  = CRC16_INITIAL,
             uint16_t xorOut   = CRC16_XOR_OUT,
             bool reverseIn    = CRC16_REF_IN,
             bool reverseOut   = CRC16_REF_OUT);

  void restart();
  uint16_t calc() const;
  size_t count() const;
  void add(uint8_t value);
  void add(const uint8_t *array, size_t length);
  void add(const uint8_t *array, size_t length, size_t yieldPeriod);

  void setPolynome(uint16_t polynome) { _polynome = polynome; }
  void setInitial(uint16_t initial) { _initial = initial; }
  void setXorOut(uint16_t xorOut) { _xorOut = xorOut; }
  void setReverseIn(bool reverseIn) { _reverseIn = reverseIn; }
  void setReverseOut(bool reverseOut) { _reverseOut = reverseOut; }

  uint16_t getPolynome() const { return _polynome; }
  uint16_t getInitial() const { return _initial; }
  uint16_t getXorOut() const { return _xorOut; }
  bool getReverseIn() const { return _reverseIn; }
  bool getReverseOut() const { return _reverseOut; }

  [[deprecated("Use calc() instead")]]
  uint8_t getCRC() const;

private:
  uint16_t _polynome;
  uint16_t _initial;
  uint16_t _xorOut;
  bool _reverseIn;
  bool _reverseOut;
  uint16_t _crc;
  size_t _count;
};
