/*
 * File: nia_shader_batch.h
 * Project: Nia
 * File created on April-29-2019
 * Author: Streanga Sarmis-Stefan (streangasarmis@gmail.com)
 * 
 * Copyright (C) 2019 Streanga Sarmis-Stefan, All Rights Reserved
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * Proprietary and confidential
 */

#ifndef _NIA_SHADER_BATCH_H_
#define _NIA_SHADER_BATCH_H_

#include "shaders/nia_shader.h"
#include "nia_general.h"

NIA_CLASS niaShaderBatch : public niaShader{
public:
    NIA_CALL niaShaderBatch();
    NIA_CALL ~niaShaderBatch();
};

#endif //_NIA_SHADER_QUAD_H_