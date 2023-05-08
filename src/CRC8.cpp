#include "CRC8.h"

CRC8::CRC8(const uint8_t polynome,
           const uint8_t initial,
           const uint8_t xorOut,
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

void CRC8::reset()
{
  _crc = _initial;
  _count = 0u;
}

void CRC8::add(uint8_t value)
{
  _count++;

  if (_reverseIn) value = reverse8(value);
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

void CRC8::add(const uint8_t * array, size_t length)
{
  while (length--)
  {
    add(*array++);
  }
}

void CRC8::yieldAdd(uint8_t value)
{
  add(value);
  if ((_count & 0xFF) == 0) yield();
}

void CRC8::yieldAdd(const uint8_t * array, size_t length)
{
  while (length--)
  {
    yieldAdd(*array++);
  }
}

uint8_t CRC8::getCRC() const
{
  uint8_t rv = _crc;
  if (_reverseOut) rv = reverse8(rv);
  rv ^= _xorOut;
  return rv;
}

size_t CRC8::count() const
{
  return _count;
}
