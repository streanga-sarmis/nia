/*
 * File: nia_vertex.h
 * Project: Nia
 * File created on March-01-2019
 * Author: Streanga Sarmis-Stefan (streangasarmis@gmail.com)
 * 
 * Copyright (C) 2019 Streanga Sarmis-Stefan, All Rights Reserved
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * Proprietary and confidential
 */

#ifndef _NIA_VERTEX_H_
#define _NIA_VERTEX_H_

#include "nia_general.h"

NIA_STRUCT niaBasicVertex{
    union {
        r32 attrs[6];
        struct {
            union {
                r32 vert[3];
                struct {
                    r32 x;
                    r32 y;
                    r32 z;
                };
            };

            union {
                r32 cols[3];
                struct {
                    r32 r;
                    r32 g;
                    r32 b;
                };
            };
        };
    };
} niaBasicVertex;

NIA_STRUCT niaBasicUVVertex{
    union {
        r32 attrs[6];
        struct {
            union {
                r32 vert[3];
                struct {
                    r32 x;
                    r32 y;
                    r32 z;
                };
            };

            union {
                r32 cols[3];
                struct {
                    r32 r;
                    r32 g;
                    r32 b;
                };
            };

            union {
                r32 uv[2];
                struct {
                    r32 u;
                    r32 v;
                };
            };
        };
    };
} niaBasicUVVertex;

//
//  coords   color     normals   tex
//  4 * 3    4 * 3     4 * 3    4 * 2   = 44 bytes / vertex, could be better
//|-------||-------||----------||----| 
// x, y, z, r, g, b, nx, ny, nz, u, v
//

NIA_STRUCT niaVertex{
    union {
        r32 attrs[11];
        struct {
            union {
                r32 vert[3];
                struct {
                    r32 x;
                    r32 y;
                    r32 z;
                };
            };

            union {
                r32 cols[3];
                struct {
                    r32 r;
                    r32 g;
                    r32 b;
                };
            };

            union {
                r32 norms[3];
                struct {
                    r32 nx;
                    r32 ny;
                    r32 nz;
                };
            };

            union {
                r32 uv[2];
                struct {
                    r32 u;
                    r32 v;
                };
            };
        };
    };
} niaVertex;

#endif //_NIA_VERTEX_H_