#include "CrcFastReverse.h"

uint8_t reverse8(uint8_t in)
{
  return reverse8bits(in);
}

uint16_t reverse12(uint16_t in)
{
  return reverse12bits(in);
}

uint16_t reverse16(uint16_t in)
{
  return reverse16bits(in);
}

uint32_t reverse32(uint32_t in)
{
  return reverse32bits(in);
}

uint64_t reverse64(uint64_t in)
{
  return reverse64bits(in);
}
