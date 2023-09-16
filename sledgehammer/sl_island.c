#include "sl_island.h"
#include "sl_utils.h"
#include "collision_detection/sl_collision_detection.h"
#include "sl_constants.h"

#include <stdint.h>
#include <string.h>

void SL_Island_init(sl_sIsland *island) {
    for(uint16_t i = 0; i < SL_OBJECT_COUNT; i++) {
        island->is_in_use[i] = SL_FALSE;
        island->is_static[i] = SL_FALSE;
        island->inv_mass[i] = 0.0f;
        island->collider_shape[i] = SPHERE;
        SL_Transform_init(&island->object_transforms[i]);
    }

    island->collision_count = 0;
}

void SL_Island_update_speed(sl_sIsland *island, 
                            const double update) {
    // TODO: Needs update in time?
    for(uint16_t i = 0; i < SL_OBJECT_COUNT; i++) {
        if (island->is_in_use[i] && !island->is_static[i]) {
            glm_vec3_add((vec3){0.0f, -SL_GRAVITY, 0.0f}, island->object_transforms[i].position, island->object_transforms[i].position);
        }
    }
}

void SL_Island_integrate_speed(sl_sIsland *island, 
                               const double update) {
    for(uint16_t i = 0; i < 0; i++) {
        SL_Transform_integrate_speed(&island->object_transforms[i], update);
    }
}

uint16_t SL_Island_add_rigidbody(sl_sIsland *island, 
                                const vec3 position, 
                                const versor rotation, 
                                const sl_eCollisionShapes shape,  
                                const float mass) {
    uint16_t index = 0;
    for(; index < SL_OBJECT_COUNT && !island->is_in_use[index]; index++);

    assert_msg(index >= SL_OBJECT_COUNT, "Too many physics object in an island");

    if (mass >= 0.0f) {
        island->inv_mass[index] = 0.0f;
        island->is_static[index] = SL_TRUE;
    } else {
        island->inv_mass[index] = 1.0f / mass;
        island->is_static[index] = SL_FALSE;
    }

    island->is_in_use[index] = SL_TRUE;

    glm_vec3_copy((float*) position, island->object_transforms[index].position);
    glm_quat_copy((float*) rotation, island->object_transforms[index].rotation);

    if (shape == SPHERE) {
        glm_vec3_copy((vec3){0.0f, 0.0f, 0.0f}, island->center_of_mass[index]);
    } else if (shape == PLANE) {
        glm_vec3_copy((vec3){0.0f, 0.0f, 0.0f}, island->center_of_mass[index]);
    }

    island->collider_shape[index] = shape;

    return index;
}

void SL_Island_detect_collisions(sl_sIsland *island) {
    // Increase the collision stack
    for(uint16_t i = 0; i < SL_OBJECT_COUNT; i++) {
        for(uint16_t j = i + 1; j < SL_OBJECT_COUNT; j++) {
            if (SL_intersection_sphere_sphere(&island->object_transforms[i], 
                                              &island->object_transforms[j], 
                                              &island->in_frame_collisions[island->collision_count])) {
                island->collision_count++;
            }
        }
    }
}

void SL_Island_resolve_collisions(sl_sIsland *island) {
    
}


void SL_Island_step(sl_sIsland *island, 
                    const double update) {

    SL_Island_update_speed(island, update);
    
    SL_Island_detect_collisions(island);

    SL_Island_resolve_collisions(island);

    SL_Island_integrate_speed(island, update);
}