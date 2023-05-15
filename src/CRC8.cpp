#include "CRC8.h"
#include "CrcFastReverse.h"

CRC8::CRC8(uint8_t polynome,
           uint8_t initial,
           uint8_t xorOut,
           bool reverseIn,
           bool reverseOut) :
  _polynome(polynome),
  _initial(initial),
  _xorOut(xorOut),
  _reverseIn(reverseIn),
  _reverseOut(reverseOut),
  _crc(initial),
  _count(0u)
{}

void CRC8::reset(uint8_t polynome,
                 uint8_t initial,
                 uint8_t xorOut,
                 bool reverseIn,
                 bool reverseOut)
{
  _polynome = polynome;
  _initial = initial;
  _xorOut = xorOut;
  _reverseIn = reverseIn;
  _reverseOut = reverseOut;
  restart();
}

void CRC8::restart()
{
  _crc = _initial;
  _count = 0u;
}

uint8_t CRC8::getCRC() const
{
  uint8_t rv = _crc;
  if (_reverseOut) rv = reverse8bits(rv);
  rv ^= _xorOut;
  return rv;
}

size_t CRC8::count() const
{
  return _count;
}

void CRC8::add(uint8_t value)
{
  _count++;

  if (_reverseIn) value = reverse8bits(value);
  _crc ^= value;
  for (uint8_t i = 8; i; i--) 
  {
    if (_crc & (1 << 7))
    {
      _crc <<= 1;
      _crc ^= _polynome;
    }
    else
    {
      _crc <<= 1;
    }
  }
}

void CRC8::add(const uint8_t *array, size_t length)
{
  while (length--)
  {
    add(*array++);
  }
}

void CRC8::yieldAdd(const uint8_t *array, size_t length, size_t yieldPeriod)
{
  while (length--)
  {
    add(*array++);
    if ((_count % yieldPeriod) == 0) yield();
  }
}
