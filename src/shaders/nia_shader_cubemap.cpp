/*
 * File: nia_shader_cubemap.cpp
 * Project: Nia
 * File created on April-29-2019
 * Author: Streanga Sarmis-Stefan (streangasarmis@gmail.com)
 * 
 * Copyright (C) 2019 Streanga Sarmis-Stefan, All Rights Reserved
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * Proprietary and confidential
 */

#include "shaders/nia_shader_cubemap.h"

#include <stdio.h>
#include <malloc.h>

NIA_STATIC char* basicCubeMapVertexShader = ""
NIA_GLSL_VERSION" \n""precision "
NIA_GLSL_PRECISION" float;\n"
"layout(location = 0) in vec3 pos;\n"

"out vec3 o_uv;\n"

"uniform mat4 mP;\n"
"uniform mat4 mV;\n"

"void main(){\n"
"   gl_Position = mP * mV * vec4(pos, 1.0);\n"
"   o_uv = pos;\n"
"}\n"
"";

NIA_STATIC char* basicCubeMapFragmentShader = ""
NIA_GLSL_VERSION" \n""precision "
NIA_GLSL_PRECISION" float;\n"

"out vec4 finalColor;\n"

"in  vec3 o_uv;\n"

"uniform samplerCube tex;\n"

"void main(){\n"
"   finalColor = texture(tex, -o_uv);\n"
"}\n"
"";

niaShaderCubeMap::niaShaderCubeMap(){
    vertexShader = loadBufferToShader(basicCubeMapVertexShader, GL_VERTEX_SHADER);
    fragmentShader = loadBufferToShader(basicCubeMapFragmentShader, GL_FRAGMENT_SHADER);

    compileShader(vertexShader);
    compileShader(fragmentShader);
    buildProgram(vertexShader, fragmentShader);
}

niaShaderCubeMap::~niaShaderCubeMap(){
    // TODO free source files loaded in memory after using them
    NIA_GL_CALL(glDeleteShader(vertexShader));
    NIA_GL_CALL(glDeleteShader(fragmentShader));
    NIA_GL_CALL(glDeleteProgram(program));
}
