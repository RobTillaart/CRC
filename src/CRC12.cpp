#include "CRC12.h"
#include "CrcFastReverse.h"

CRC12::CRC12(const uint16_t polynome,
             const uint16_t initial,
             const uint16_t xorOut,
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

void CRC12::reset()
{
  _crc = _initial;
  _count = 0u;
}

uint16_t CRC12::getCRC() const
{
  uint16_t rv = _crc;
  if (_reverseOut) rv = reverse12bits(rv);
  rv ^= _xorOut;
  return rv & 0x0FFF;
}

size_t CRC12::count() const
{
  return _count;
}

void CRC12::add(uint8_t value)
{
  _count++;

  if (_reverseIn) value = reverse8bits(value);
  _crc ^= ((uint16_t)value) << 4;
  for (uint8_t i = 8; i; i--) 
  {
    if (_crc & (1 << 11))
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

void CRC12::add(const uint8_t * array, size_t length)
{
  while (length--)
  {
    add(*array++);
  }
}

void CRC12::yieldAdd(const uint8_t * array, size_t length, const size_t yieldPeriod)
{
  while (length--)
  {
    add(*array++);
    if ((_count % yieldPeriod) == 0) yield();
  }
}
