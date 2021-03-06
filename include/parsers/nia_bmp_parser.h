/*
 * File: nia_bmp_parser.h
 * Project: Nia
 * File created on April-29-2019
 * Author: Streanga Sarmis-Stefan (streangasarmis@gmail.com)
 * 
 * Copyright (C) 2019 Streanga Sarmis-Stefan, All Rights Reserved
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * Proprietary and confidential
 */

#ifndef _NIA_BMP_PARSER_H_
#define _NIA_BMP_PARSER_H_

#include "nia_general.h"
#include "nia_texture_structures.h"

#define NIA_BMP_1_BIT 1
#define NIA_BMP_4_BIT 4
#define NIA_BMP_8_BIT 8
#define NIA_BMP_16_BIT 16
#define NIA_BMP_24_BIT 24
#define NIA_BMP_32_BIT 32

#define NIA_BMP_COMPRESSION_0 0
#define NIA_BMP_COMPRESSION_1 1
#define NIA_BMP_COMPRESSION_2 2
#define NIA_BMP_COMPRESSION_3 3

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;

#pragma pack(push, 1)

typedef struct niaBMPHeader{
    u8 type[2];
    u32 size;
    u16 reserved1;
    u16 reserved2;
    u32 offsetBits;
} niaBMPHeader;

typedef struct niaBMPImageHeader{
    u32 size;
    u32 width;
    u32 height;
    u16 planes;
    u16 bitCount;
    u32 compression;
    u32 sizeImage;
    u32 xppm;
    u32 yppm;
    u32 colorMapEntries;
    u32 significantColors;
} niaBMPImageHeader;

typedef struct niaBMP{
    textureFormatDetails textureFormat;
    niaBMPHeader fileHeader;  
    niaBMPImageHeader imageHeader;
    u8* fileData;
    u8* pixelData;
} niaBMP;

#pragma pack(pop)

NIA_CLASS niaBmpParser { // make a parser class
private:
    niaBMP bmpData;

    void decodeFile();

public:
    NIA_CALL niaBmpParser(const char* filename);
    NIA_CALL ~niaBmpParser();

    void NIA_CALL loadFile(const char* filename);
    u32 NIA_CALL getWidth() const;
    u32 NIA_CALL getHeight() const;
    u8* NIA_CALL getPixelData() const;
    u8 NIA_CALL getBitCount() const;
    textureFormatDetails NIA_CALL getTextureFormat() const;
};

#endif // _NIA_BMP_PARSER_H_