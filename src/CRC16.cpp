#include "CRC16.h"
#include "CrcFastReverse.h"

CRC16::CRC16(const uint16_t polynome,
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

void CRC16::reset()
{
  _crc = _initial;
  _count = 0u;
}

uint16_t CRC16::getCRC() const
{
  uint16_t rv = _crc;
  if (_reverseOut) rv = reverse16bits(rv);
  rv ^= _xorOut;
  return rv;
}

size_t CRC16::count() const
{
  return _count;
}

void CRC16::add(uint8_t value)
{
  _count++;

  if (_reverseIn) value = reverse8bits(value);
  _crc ^= ((uint16_t)value) << 8;
  for (uint8_t i = 8; i; i--) 
  {
    if (_crc & (1UL << 15))
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

void CRC16::add(const uint8_t * array, size_t length)
{
  while (length--)
  {
    add(*array++);
  }
}

void CRC16::yieldAdd(const uint8_t * array, size_t length, const size_t yieldPeriod)
{
  while (length--)
  {
    add(*array++);
    if ((_count % yieldPeriod) == 0) yield();
  }
}
