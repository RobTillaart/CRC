
[![Arduino CI](https://github.com/RobTillaart/CRC/workflows/Arduino%20CI/badge.svg)](https://github.com/marketplace/actions/arduino_ci)
[![Arduino-lint](https://github.com/RobTillaart/CRC/actions/workflows/arduino-lint.yml/badge.svg)](https://github.com/RobTillaart/CRC/actions/workflows/arduino-lint.yml)
[![JSON check](https://github.com/RobTillaart/CRC/actions/workflows/jsoncheck.yml/badge.svg)](https://github.com/RobTillaart/CRC/actions/workflows/jsoncheck.yml)
[![License: MIT](https://img.shields.io/badge/license-MIT-green.svg)](https://github.com/RobTillaart/CRC/blob/master/LICENSE)
[![GitHub release](https://img.shields.io/github/release/RobTillaart/CRC.svg?maxAge=3600)](https://github.com/RobTillaart/CRC/releases)


# CRC

Arduino library with CRC8, CRC12, CRC16, CRC32 and CRC64 functions.


## Description

Goal of this library is to have a flexible and portable set of generic
CRC functions and classes.

The CRCx classes have a number of added values.
Most important is that they allow one to verify intermediate CRC values.
This is useful if one sends a "train of packets" which include a CRC so far.
This detects both errors in one single packet but also optional missing packets,
or even injected packets.

Another trick one can do with the class CRCx is to change the polynome or
the reverse flag runtime during the process. This makes it harder to imitate.

Furthermore the class allows to add values in single steps and continue too.

Finally the class version gives more readable code (IMHO) as the parameters
are explicitly set.


**Note** the classes have same names as the static functions, except the class
is UPPER case. So **CRC8** is a class and **calcCRC8()** is the function.

Deeper tech info - https://en.wikipedia.org/wiki/Cyclic_redundancy_check
and many other websites.

#### Related

- https://github.com/RobTillaart/Adler
- https://github.com/RobTillaart/CRC
- https://github.com/RobTillaart/Fletcher
- https://github.com/RobTillaart/LUHN



## Interface CRC classes

The interfaces are very similar for CRC8, CRC12, CRC16, CRC32 and CRC64 class.
The only difference is the data type for polynome, start- and end-mask,
and the returned CRC.


#### Base

Use **\#include "CRC8.h"**

- **CRC8(polynome, initial, xorOut, reverseIn, reverseOut)** Constructor to set all parameters at once.
- **void reset()** set all internals to defaults of the **CRC8()** parameterless constructor.
- **void restart()** reset internal CRC and count only;
reuse values for other e.g polynome, XOR masks and reverse flags.
- **uint8_t calc()** returns CRC calculated so far. This allows to check the CRC of
a really large stream at intermediate moments, e.g. to link multiple packets.
- **crc_size_t count()** returns number of values added so far. Default 0.
- **void add(value)** add a single value to CRC calculation.
- **void add(array, length)** add an array of values to the CRC.
In case of a warning/error for the array type, use casting to (uint8_t \*).
- **void add(array, length, yieldPeriod)** as CRC calculations of large blocks can take serious time (in milliseconds),
the classes call **yield()** after every **yieldPeriod** calls to keep RTOS environments happy. The call allows to add values with
**yield()** to get optimal performance. The risk is missing context switching to handle interrupts etc. So use at own risk.

#### Parameters

The parameters do not have defaults so the user must set them explicitly.

- **void setPolynome(polynome)** set polynome, note reset sets a default polynome.
- **void setInitial(initial)** set start-mask, default 0.
- **void setXorOut(xorOut)** set end-mask, default 0.
- **void setReverseIn(reverseIn)** reverse the bit pattern of input data (MSB vs LSB).
- **void setReverseOut(reverseOut)** reverse the bit pattern of CRC (MSB vs LSB).
- **uint8_t getPolynome()** return parameter set above or default.
- **uint8_t getInitial()** return parameter set above or default.
- **uint8_t getXorOut()** return parameter set above or default.
- **bool getReverseIn()** return parameter set above or default.
- **bool getReverseOut()** return parameter set above or default.

### Example snippet

A minimal usage only needs:
- the constructor, the add() function and the calc() function.

```cpp
#include "CRC32.h"
...

CRC32 crc;
  ...
  while (Serial.available())
  {
    int c = Serial.read();
    crc.add(c);
  }
  Serial.println(crc.calc());
```


## Interface static functions

Use **\#include "CRC.h"**

Most functions have a default polynome, same start and end masks, and default there is no reversing.
However these parameters allow one to tweak the CRC in all aspects known.
In all the examples encountered the reverse flags were set both to false or both to true.
For flexibility both parameters are kept available.

- **uint8_t calcCRC8(array, length)** idem with default polynome.
- **uint16_t calcCRC12(array, length)** idem with default polynome.
- **uint16_t calcCRC16(array, length)** idem with default polynome.
- **uint32_t calcCRC32(array, length)** idem with default polynome.
- **uint64_t calcCRC64(array, length)** - experimental version, no reference found except on Wikipedia.


The static functions **calcCRC..()** in this library also support yield.

The static CRC functions use fast reverse functions that can be also be
used outside CRC context. Their usage is straightforward.

- **uint8_t reverse8bits(uint8_t in)** idem.
- **uint16_t reverse16bits(uint16_t in)** idem.
- **uint16_t reverse12bits(uint16_t in)** idem.
- **uint32_t reverse32bits(uint32_t in)** idem.
- **uint64_t reverse64bits(uint64_t in)** idem.

reverse12bits is based upon reverse16bits, with a final shift.
Other reverses can be created in similar way.


## CrcParameters.h

Since version 1.0.0 the file CrcParameters.h is added to hold symbolic names for certain parameters (polynomes, etc..).
These can be used in your code too to minimize the number of "magic HEX codes".
If standard polynomes are missing, please open an issue and report, with reference.


## Operational

See examples.


## Links

- https://en.wikipedia.org/wiki/Cyclic_redundancy_check - generic background.
- http://zorc.breitbandkatze.de/crc.html - online CRC calculator (any base up to 64 is supported.)
- https://crccalc.com/ - online CRC calculator to verify.
- https://www.lddgo.net/en/encrypt/crc - online CRC calculator
- http://www.sunshine2k.de/coding/javascript/crc/crc_js.html - online CRC calculator

## Future

#### Must


#### Should

- add examples.
  - example showing multiple packages of data linked by their CRC.
    sort of "blockchain"


#### Could

- table versions for performance?  (performance - memory discussion).
- stream version - 4 classes class?
- **setCRC(value)** to be able to pick up where one left ?
  - can be done with **setStartXOR()**
  - needs **getRawCRC()**  without reverse and end mask
- Think about default parameters for constructor **CRC8(polynome, XORstart, XORend, reverseIn, reverseOut)**
  - same as reset so constructors merge? Note the CRC-functions do have defaults too.


#### Exotic CRC's ?

- **CRC1()** // parity :)
- **CRC4()** nibbles?
  - default polynome 0x03  ITU
- One CRC() with #bits as parameter?
  - up to 64 bit for all missing ones?
  - performance penalty
- One CRC() template class?


#### Won't

- add a dump(Stream = Serial) to see all the settings at once.
  user can access parameters, so no need.


