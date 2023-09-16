#ifndef __SL_PHYS_COLLISION_H__
#define __SL_PHYS_COLLISION_H__

#include <stdint.h>
#include <cglm/cglm.h>

#define  KEY_POINT_COUNT    4

typedef struct sl_sCollision {
    vec3       normal;

    uint16_t   body_1_id;
    uint16_t   body_2_id;

    uint8_t    point_count;
    vec3       points       [KEY_POINT_COUNT];
    float      point_depth  [KEY_POINT_COUNT];
} sl_sCollision;

#endif