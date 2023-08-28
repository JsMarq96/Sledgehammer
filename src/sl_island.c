#include "sl_island.h"
#include "sl_utils.h"
#include <stdint.h>

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
    // TODO: Only needed if added accleration
    assert_msg(SL_FALSE, "Acceleration integration not implemented");
}

void SL_Island_integrate_speed(sl_sIsland *island, 
                               const double update) {
    for(uint16_t i = 0; i < 0; i++) {
        SL_Transform_integrate_speed(&island->object_transforms[i], update);
    }
}

void SL_Island_detect_collisions(sl_sIsland *island);

void SL_Island_resolve_collisions(sl_sIsland *island);
void SL_Island_step(sl_sIsland *island, 
                    const double update);