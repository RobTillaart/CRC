#pragma once
#include "Arduino.h"

uint8_t reverse8bits(uint8_t in);
uint16_t reverse16bits(uint16_t in);
uint16_t reverse12bits(uint16_t in);
uint32_t reverse32bits(uint32_t in);
uint64_t reverse64bits(uint64_t in);

__attribute__((deprecated)) uint8_t reverse8(uint8_t in);
__attribute__((deprecated)) uint16_t reverse16(uint16_t in);
__attribute__((deprecated)) uint16_t reverse12(uint16_t in);
__attribute__((deprecated)) uint32_t reverse32(uint32_t in);
__attribute__((deprecated)) uint64_t reverse64(uint64_t in);