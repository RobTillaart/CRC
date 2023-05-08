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

void CRC32::yieldAdd(uint8_t value)
{
  add(value);
  if ((_count & 0xFF) == 0) yield();
}

void CRC32::yieldAdd(const uint8_t * array, size_t length)
{
  while (length--)
  {
    yieldAdd(*array++);
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
