#ifndef __SL_ISNALND_H__
#define __SL_ISNALND_H__

#include <stdint.h>
#include <cglm/cglm.h>

#include "cglm/types.h"
#include "sl_commons.h"
#include "sl_body.h"
#include "sl_transform.h"
#include "sl_collision.h"

#define SL_OBJECT_COUNT   25
#define SL_OBJECT_COUNT_SQUARED   (SL_OBJECT_COUNT * SL_OBJECT_COUNT) 

typedef struct sl_sIsland {
    // in island data
    bool                 is_in_use            [SL_OBJECT_COUNT];
    sl_eCollisionShapes  collider_shape       [SL_OBJECT_COUNT];
    bool                 is_static            [SL_OBJECT_COUNT];
    sl_sTransform        object_transforms    [SL_OBJECT_COUNT];
    float                inv_mass             [SL_OBJECT_COUNT];

    // Collisions in the current frame
    uint16_t             collision_count;
    sl_sCollision        in_frame_collisions  [SL_OBJECT_COUNT_SQUARED];
} sl_sIsland;

// Island methods
void SL_Island_init(sl_sIsland *island);
void SL_Island_update_speed(sl_sIsland *island, const double update);
void SL_Island_integrate_speed(sl_sIsland *island, const double update);
void SL_Island_detect_collisions(sl_sIsland *island);
void SL_Island_resolve_collisions(sl_sIsland *island);
void SL_Island_step(sl_sIsland *island, const double update);

uint16_t SL_Island_add_rigidbody(sl_sIsland *island, const vec3 position, const versor rotation, const sl_eCollisionShapes shape);

#endif