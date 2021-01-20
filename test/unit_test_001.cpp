//
//    FILE: unit_test_001.cpp
//  AUTHOR: Rob Tillaart
//    DATE: 2021-01-01
// PURPOSE: unit tests for the CRC library
//          https://github.com/RobTillaart/CRC
//          https://github.com/Arduino-CI/arduino_ci/blob/master/REFERENCE.md
//

// supported assertions
// ----------------------------
// assertEqual(expected, actual);               // a == b
// assertNotEqual(unwanted, actual);            // a != b
// assertComparativeEquivalent(expected, actual);    // abs(a - b) == 0 or (!(a > b) && !(a < b))
// assertComparativeNotEquivalent(unwanted, actual); // abs(a - b) > 0  or ((a > b) || (a < b))
// assertLess(upperBound, actual);              // a < b
// assertMore(lowerBound, actual);              // a > b
// assertLessOrEqual(upperBound, actual);       // a <= b
// assertMoreOrEqual(lowerBound, actual);       // a >= b
// assertTrue(actual);
// assertFalse(actual);
// assertNull(actual);

// // special cases for floats
// assertEqualFloat(expected, actual, epsilon);    // fabs(a - b) <= epsilon
// assertNotEqualFloat(unwanted, actual, epsilon); // fabs(a - b) >= epsilon
// assertInfinity(actual);                         // isinf(a)
// assertNotInfinity(actual);                      // !isinf(a)
// assertNAN(arg);                                 // isnan(a)
// assertNotNAN(arg);                              // !isnan(a)


#include <ArduinoUnitTests.h>


#include "Arduino.h"
#include "CRC.h"


unittest_setup()
{
}

unittest_teardown()
{
}


unittest(test_CRC8)
{
  fprintf(stderr, "VERSION: %s\n", CRC_LIB_VERSION);

  AssertEqual(0xF4, CRC8(data, 9, 0x07));
  AssertEqual(0xDA, CRC8(data, 9, 0x9B, 0xFF));
  AssertEqual(0x15, CRC8(data, 9, 0x39, 0x00, 0x00, true, true));
  AssertEqual(0xBC, CRC8(data, 9, 0xD5));
  AssertEqual(0x97, CRC8(data, 9, 0x1D, 0xFF, 0x00, true, true));
  AssertEqual(0x7E, CRC8(data, 9, 0x1D, 0xFD));
  AssertEqual(0xA1, CRC8(data, 9, 0x07, 0x00, 0x55));
  AssertEqual(0xA1, CRC8(data, 9, 0x31, 0x00, 0x00, true, true));
  AssertEqual(0xD0, CRC8(data, 9, 0x07, 0xFF, 0x00, true, true));
  AssertEqual(0x25, CRC8(data, 9, 0x9B, 0x00, 0x00, true, true));
}


unittest(test_CRC16)
{
  fprintf(stderr, "VERSION: %s\n", CRC_LIB_VERSION);

  AssertEqual(0x29B1, CRC16(data, 9, 0x1021, 0xFFFF, 0x0000, false, false ));
  AssertEqual(0xBB3D, CRC16(data, 9, 0x8005, 0x0000, 0x0000, true,  true  ));
  AssertEqual(0xE5CC, CRC16(data, 9, 0x1021, 0x1D0F, 0x0000, false, false ));
  AssertEqual(0xFEE8, CRC16(data, 9, 0x8005, 0x0000, 0x0000, false, false ));
  AssertEqual(0x4C06, CRC16(data, 9, 0xC867, 0xFFFF, 0x0000, false, false ));
  AssertEqual(0x9ECF, CRC16(data, 9, 0x8005, 0x800D, 0x0000, false, false ));
  AssertEqual(0x007E, CRC16(data, 9, 0x0589, 0x0000, 0x0001, false, false ));
  AssertEqual(0x007F, CRC16(data, 9, 0x0589, 0x0000, 0x0000, false, false ));
  AssertEqual(0xEA82, CRC16(data, 9, 0x3D65, 0x0000, 0xFFFF, true,  true  ));
  AssertEqual(0xC2B7, CRC16(data, 9, 0x3D65, 0x0000, 0xFFFF, false, false ));
  AssertEqual(0xD64E, CRC16(data, 9, 0x1021, 0xFFFF, 0xFFFF, false, false ));
  AssertEqual(0x44C2, CRC16(data, 9, 0x8005, 0x0000, 0xFFFF, true,  true  ));
  AssertEqual(0x6F91, CRC16(data, 9, 0x1021, 0xFFFF, 0x0000, true,  true  ));
  AssertEqual(0x63D0, CRC16(data, 9, 0x1021, 0xB2AA, 0x0000, true,  true  ));
  AssertEqual(0xD0DB, CRC16(data, 9, 0x8BB7, 0x0000, 0x0000, false, false ));
  AssertEqual(0x0FB3, CRC16(data, 9, 0xA097, 0x0000, 0x0000, false, false ));
  AssertEqual(0x26B1, CRC16(data, 9, 0x1021, 0x89EC, 0x0000, true,  true  ));
  AssertEqual(0xB4C8, CRC16(data, 9, 0x8005, 0xFFFF, 0xFFFF, true,  true  ));
  AssertEqual(0xBF05, CRC16(data, 9, 0x1021, 0xC6C6, 0x0000, true,  true  ));
  AssertEqual(0x2189, CRC16(data, 9, 0x1021, 0x0000, 0x0000, true,  true  ));
  AssertEqual(0x4B37, CRC16(data, 9, 0x8005, 0xFFFF, 0x0000, true,  true  ));
  AssertEqual(0x906E, CRC16(data, 9, 0x1021, 0xFFFF, 0xFFFF, true,  true  ));
  AssertEqual(0x31C3, CRC16(data, 9, 0x1021, 0x0000, 0x0000, false, false ));
}


unittest(test_CRC32)
{
  fprintf(stderr, "VERSION: %s\n", CRC_LIB_VERSION);

  AssertEqual(0xCBF43926, CRC32(data, 9, 0x04C11DB7, 0xFFFFFFFF, 0xFFFFFFFF, true, true));
  AssertEqual(0xFC891918, CRC32(data, 9, 0x04C11DB7, 0xFFFFFFFF, 0xFFFFFFFF, false, false));
  AssertEqual(0xE3069283, CRC32(data, 9, 0x1EDC6F41, 0xFFFFFFFF, 0xFFFFFFFF, true, true));
  AssertEqual(0x87315576, CRC32(data, 9, 0xA833982B, 0xFFFFFFFF, 0xFFFFFFFF, true, true));
  AssertEqual(0x0376E6E7, CRC32(data, 9, 0x04C11DB7, 0xFFFFFFFF, 0x00000000, false, false));
  AssertEqual(0x765E7680, CRC32(data, 9, 0x04C11DB7, 0x00000000, 0xFFFFFFFF, false, false));
  AssertEqual(0x3010BF7F, CRC32(data, 9, 0x814141AB, 0x00000000, 0x00000000, false, false));
  AssertEqual(0x340BC6D9, CRC32(data, 9, 0x04C11DB7, 0xFFFFFFFF, 0x00000000, true, true));
  AssertEqual(0xBD0BE338, CRC32(data, 9, 0x000000AF, 0x00000000, 0x00000000, false, false));
}


unittest(test_CRC64)
{
  fprintf(stderr, "VERSION: %s\n", CRC_LIB_VERSION);

  fprintf(stderr, "no reference yet\n");
  assertEqual(1, 1);
}


unittest_main()

// --------
