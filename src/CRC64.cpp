#include "CRC64.h"

CRC64::CRC64(const uint64_t polynome,
             const uint64_t initial,
             const uint64_t xorOut,
             const bool reverseIn,
             const bool reverseOut) :
  _polynome(polynome),
  _initial(initial),
  _xorOut(xorOut),
  _reverseIn(reverseIn),
  _reverseOut(reverseOut),
  _crc(initial),
  _count(0u)
{}

void CRC64::reset()
{
  _crc = _initial;
  _count = 0u;
}

uint64_t CRC64::getCRC() const
{
  uint64_t rv = _crc;
  if (_reverseOut) rv = reverse64(rv);
  rv ^= _xorOut;
  return rv;
}

size_t CRC64::count() const
{
  return _count;
}

void CRC64::add(uint8_t value)
{
  _count++;

  if (_reverseIn) value = reverse8(value);
  _crc ^= ((uint64_t)value) << 56;
  for (uint8_t i = 8; i; i--) 
  {
    if (_crc & (1ULL << 63))
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

void CRC64::add(const uint8_t * array, size_t length)
{
  while (length--)
  {
    add(*array++);
  }
}

void CRC64::yieldAdd(const uint8_t * array, size_t length, const size_t yieldPeriod)
{
  while (length--)
  {
    add(*array++);
    if ((_count % yieldPeriod) == 0) yield();
  }
}
