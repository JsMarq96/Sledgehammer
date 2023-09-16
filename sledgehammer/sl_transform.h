#ifndef __SL_TRANSFORM_H__
#define __SL_TRANSFORM_H__

#include <cglm/cglm.h>
#include <cglm/quat.h>

#include "sl_body.h"

typedef struct sl_sSpatialData {
    
} sl_sSpatialData;

typedef struct sl_sTransform {
    vec3        position;
    vec3        scale;
    versor      rotation;
    sl_sSpeed   speed;
} sl_sTransform;

void SL_Transform_init(sl_sTransform *transform);
void SL_Transform_integrate_speed(sl_sTransform *transform, const double delta_time);

#endif