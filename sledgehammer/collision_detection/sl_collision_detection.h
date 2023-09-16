#ifndef __SL_COLLISION_DETECTION_H__
#define __SL_COLLISION_DETECTION_H__

#include <cglm/cglm.h>

#include "../sl_utils.h"
#include "../sl_transform.h"
#include "../sl_collision.h"

inline uint8_t SL_intersection_sphere_sphere(sl_sTransform *obj1, 
                                             sl_sTransform *obj2, 
                                             sl_sCollision *collision_manifold) {
    float intercenter_distance, collision_depth;
    vec3 tmp;

    glm_vec3_sub(obj1->position, 
                 obj2->position, 
                 collision_manifold->normal);

    intercenter_distance = glm_vec3_norm(collision_manifold->normal);
    
    // Normalize the normal!
    glm_vec3_divs(collision_manifold->normal, 
                  intercenter_distance, 
                  collision_manifold->normal);

    collision_depth = intercenter_distance - (obj1->scale[0] + obj2->scale[0]);

    if (collision_depth < SL_EPSILON) {
        return SL_FALSE;
    }


    // Should be one point, or two?
    collision_manifold->point_count = 1;
    glm_vec3_scale(collision_manifold->points[0], 
                   collision_depth, 
                   tmp);

    glm_vec3_add(obj1->position, 
                tmp, 
                collision_manifold->points[0]);

    return SL_TRUE;
}

#endif