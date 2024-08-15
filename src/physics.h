#ifndef PHYSICS_H
#define PHYSICS_H

#include <stdbool.h>
#include "vec2.h"
#include "geometry.h"


typedef struct{
    vec2 position;
    uint64_t enter_time;
    float speed;
    float radius;
    
}Physics;

void phy_move(Physics* phy, Path* path, uint64_t world_time, float time_scale);
bool phy_collide(Physics* phy, Physics* phy2);


#endif
