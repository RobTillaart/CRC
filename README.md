
[![Arduino CI](https://github.com/RobTillaart/CRC/workflows/Arduino%20CI/badge.svg)](https://github.com/marketplace/actions/arduino_ci)
[![License: MIT](https://img.shields.io/badge/license-MIT-green.svg)](https://github.com/RobTillaart/CRC/blob/master/LICENSE)
[![GitHub release](https://img.shields.io/github/release/RobTillaart/CRC.svg?maxAge=3600)](https://github.com/RobTillaart/CRC/releases)


# CRC

Arduino library with CRC8, CRC16, CRC32 and CRC64 functions


## Description

Implements the generic CRC functions. 

Deeper tech info -https://en.wikipedia.org/wiki/Cyclic_redundancy_check
and many other websites.

Goal of this library is to have a flexible and portable set of functions.


## Interface

Most functions have a default polynome, same start and end masks, and default there is no reversing.
However these parameters allow one to tweak the CRC in all aspects known. 
In all the examples encountered the reverseflags were set both to false or both to true. 
For flexibility both parameters are kept available. 

- **uint8_t CRC8(array, length, polynome = 0xD5, start = 0, end = 0, reverseIn = false, reverseOut = false)** idem with default polynome
- **uint16_t CRC16(array, length, polynome = 0xA001, start = 0, end = 0, reverseIn = false, reverseOut = false)** idem with default polynome
- **uint16_t CRC16-CCITT(array, length)** fixed polynome **0x1021**, non zero start / end masks
- **uint32_t CRC32(array, length, polynome = 0x04C11DB7, start = 0, end = 0, reverseIn = false, reverseOut = false)** idem with default polynome
- **uint64_t CRC64(array, length, polynome, start, end, reverseIn, reverseOut)** - experimental version, no reference found except on Wikipedia 


There are many other CRC's but the most used ones can be handled with these functions.


## Future

- should become classes with both incremental and bulk options, baseclass CRC.
- table versions for perforrmane?
- stream version - 4 classes class?


#### Exotic CRC's ?

- **CRC1()** // parity :)
- **CRC4(array, length, polynome, start, end, reverseIN, reverseOut)**
  - default polynome 0x03


#### Magic \#defines for "common" polynomes? ?

  - \#define CRC_ISO64  0x000000000000001B
  - \#define CRC_ECMA64 0x42F0E1EBA9EA3693


## Operational

See examples. (to be extended)
