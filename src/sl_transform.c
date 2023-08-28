#include "sl_transform.h"

#include "cglm/quat.h"
#include "cglm/vec3.h"
#include "sl_utils.h"

void SL_Transform_init(sl_sTransform *transform) {
    glm_vec3_zero(transform->position);
    glm_vec3_zero(transform->scale);
    glm_quat_identity(transform->rotation);
    glm_vec3_zero(transform->speed.linear);
    glm_vec3_zero(transform->speed.angular);
}


void SL_Transform_integrate_speed(sl_sTransform *transform, const double delta_time) {
    
}