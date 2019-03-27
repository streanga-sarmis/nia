#ifndef _NIA_SCENE_H_
#define _NIA_SCENE_H_

#include "nia_general.h"

#define NIA_DIFFUSE_LIGHT_POSITION  0x00000000
#define NIA_DIFFUSE_LIGHT_COLOR     0x00000001

#define NIA_SPECULAR_LIGHT_POSITION  0x00000002
#define NIA_SPECULAR_LIGHT_COLOR     0x00000004

#define NIA_VIEW    0x00000001

#include "nia_vector.h"
#include "nia_matrix.h"
#include "nia_shader.h"
#include "nia_renderer.h"
#include "nia_constants.h"

NIA_CLASS niaScene {
protected:
    niaVector3<r32> diffuseLightColor;
    niaVector3<r32> diffuseLightPosition;

    niaVector3<r32> specularLightPosition;
    niaVector3<r32> specularLightColor;

    niaMatrix4 view;

    NIA_CALL void setAttributeVec2(u32 attribute, const niaVector2<r32>& vector);
    NIA_CALL void setAttributeVec3(u32 attribute, const niaVector3<r32>& vector);
    NIA_CALL void setAttributeMat4(u32 attribute, const niaMatrix4& matrix);

public:
    NIA_CALL niaScene();
    NIA_CALL ~niaScene();

    NIA_CALL void bind(niaRenderer* renderer);
    NIA_CALL void unbind(niaRenderer* renderer);
};


#endif // _NIA_SCENE_H_