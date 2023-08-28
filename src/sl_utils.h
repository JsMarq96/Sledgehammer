#ifndef __SL_UTILS_H__
#define __SL_UTILS_H__

#include <stdio.h>
#include <assert.h>

#define SL_TRUE 1
#define SL_FALSE 0

#define SL_EPSILON 0.001f

inline static void assert_msg(const bool condition, 
                       const char *msg) {
    if (condition) {
        printf("ASERT ERROR %s", msg);
        assert(false);
    }
}

#endif