#include "CRC32.h"

CRC32::CRC32(const uint32_t polynome,
             const uint32_t initial,
             const uint32_t xorOut,
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

void CRC32::reset()
{
  _crc = _initial;
  _count = 0u;
}

void CRC32::add(uint8_t value)
{
  _count++;

  if (_reverseIn) value = reverse8(value);
  _crc ^= ((uint32_t)value) << 24;
  for (uint8_t i = 8; i; i--) 
  {
    if (_crc & (1UL << 31))
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

void CRC32::add(const uint8_t * array, size_t length)
{
  while (length--)
  {
    add(*array++);
  }
}

uint32_t CRC32::getCRC() const
{
  uint32_t rv = _crc;
  if (_reverseOut) rv = reverse32(rv);
  rv ^= _xorOut;
  return rv;
}

size_t CRC32::count() const
{
  return _count;
}

YieldCRC32::YieldCRC32(const uint32_t polynome,
                       const uint32_t initial,
                       const uint32_t xorOut,
                       const bool reverseIn,
                       const bool reverseOut,
                       const size_t yieldPeriod) :
  _crc(polynome, initial, xorOut, reverseIn, reverseOut),
  _yieldPeriod(yieldPeriod)
{}

void YieldCRC32::reset()
{
  _crc.reset();
}

void YieldCRC32::add(uint8_t value)
{
  _crc.add(value);
  if ((_crc.count() % _yieldPeriod) == 0) yield();
}

void YieldCRC32::add(const uint8_t * array, size_t length)
{
  while (length--)
  {
    add(*array++);
  }
}

uint32_t YieldCRC32::getCRC() const
{
  return _crc.getCRC();
}

size_t YieldCRC32::count() const
{
  return _crc.count();
}