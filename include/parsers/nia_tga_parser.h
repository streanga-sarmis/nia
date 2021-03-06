/*
 * File: nia_tga_parser.h
 * Project: Nia
 * File created on April-29-2019
 * Author: Streanga Sarmis-Stefan (streangasarmis@gmail.com)
 * 
 * Copyright (C) 2019 Streanga Sarmis-Stefan, All Rights Reserved
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * Proprietary and confidential
 */

#ifndef _NIA_TGA_PARSER_H_
#define _NIA_TGA_PARSER_H_

#include "nia_general.h"
#include "nia_texture_structures.h"

#pragma pack(push, 1)
typedef struct niaTGAHeader {
    u8 idLength;
    u8 colorMapType;
    u8 imageType;
    u8 colorMapSpecification[5];
    union {
        u8 imageSpecification[10];
        struct {
            u16 xOrigin;
            u16 yOrigin;
            u16 width;
            u16 height;
            u8 pixelDepth;
            u8 imageDesciptor;
        };
    };
} niaTGAHeader;
#pragma pack(pop)

typedef struct niaTGA{
    textureFormatDetails textureFormat;
    niaTGAHeader fileHeader;
    u8* fileData;
    u8* pixelData;
} niaTGA;


NIA_CLASS niaTgaParser {
private:
    niaTGA tgaData;

    void decodeFile();

public:
    NIA_CALL niaTgaParser(const char* filename);
    NIA_CALL ~niaTgaParser();

    void NIA_CALL loadFile(const char* filename);
    u32 NIA_CALL getWidth() const;
    u32 NIA_CALL getHeight() const;
    u8* NIA_CALL getPixelData() const;
    textureFormatDetails NIA_CALL getTextureFormat() const;

};

#endif //_NIA_TGA_PARSER_H_
