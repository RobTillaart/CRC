#pragma once
//
//    FILE: polynomes.h
//  AUTHOR: Rob Tillaart
// PURPOSE: defines for standard CRC polynomes
//     URL: https://github.com/RobTillaart/CRC
//
// Polynomes from
//          https://en.wikipedia.org/wiki/Cyclic_redundancy_check#Polynomial_representations_of_cyclic_redundancy_checks


// CRC 4
#define CRC4_POLYNOME               0x03
#define CRC4_ITU_POLYNOME           0x03


// CRC 8
#define CRC8_POLYNOME               0x07
#define CRC8_DVB_S2_POLYNOME        0xD5
#define CRC8_AUTOSAR_POLYNOME       0x2F
#define CRC8_BLUETOOTH_POLYNOME     0xA7
#define CRC8_CCITT_POLYNOME         0x07
#define CRC8_DALLAS_MAXIM_POLYNOME  0x31                // oneWire
#define CRC8_DARC_POLYNOME          0x39
#define CRC8_GSM_B_POLYNOME         0x49
#define CRC8_SAEJ1850_POLYNOME      0x1D
#define CRC8_WCDMA_POLYNOME         0x9B


// CRC 12
#define CRC12_POLYNOME              0x080D
#define CRC12_CCITT_POLYNOME        0x080F
#define CRC12_CDMA2000_POLYNOME     0x0F13
#define CRC12_GSM_POLYNOME          0x0D31


// CRC 16
#define CRC16_POLYNOME              0x1021
#define CRC16_CHAKRAVARTY_POLYNOME  0x2F15
#define CRC16_ARINC_POLYNOME        0xA02B
#define CRC16_CCITT_POLYNOME        0x1021
#define CRC16_CDMA2000_POLYNOME     0xC867
#define CRC16_DECT_POLYNOME         0x0589
#define CRC16_T10_DIF_POLYNOME      0x8BB7
#define CRC16_DNP_POLYNOME          0x3D65
#define CRC16_IBM_POLYNOME          0x8005
#define CRC16_OPENSAFETY_A_POLYNOME 0x5935
#define CRC16_OPENSAFETY_B_POLYNOME 0x755B
#define CRC16_PROFIBUS_POLYNOME     0x1DCF


// CRC 32
#define CRC32_POLYNOME              0x04C11DB7
#define CRC32_ISO3309_POLYNOME      0x04C11DB7
#define CRC32_CASTAGNOLI_POLYNOME   0x1EDC6F41
#define CRC32_KOOPMAN_POLYNOME      0x741B8CD7
#define CRC32_KOOPMAN_2_POLYNOME    0x32583499
#define CRC32_Q_POLYNOME            0x814141AB


// CRC 64
#define CRC64_POLYNOME              0x42F0E1EBA9EA3693
#define CRC64_ECMA64_POLYNOME       0x42F0E1EBA9EA3693
#define CRC64_ISO64_POLYNOME        0x000000000000001B
