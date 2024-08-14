#include <math.h>
#include <stdint.h>
#include <stdbool.h>
#include "vec2.h"
#include "geometry.h"
#include "physics.h"

void phy_move(Physics* phy, const Path* path, uint64_t world_time, float time_scale){
    //dt is the time difference between the current global time and the time the object entered the path
    //time scale is the unit time in seconds and it depends on the framerate.
    //v2_diff(path->end,path->begin) is the direction. Maybe I can precalculate it?
    //All the checks regarding the current path are done in the move function of GameObject
    float dt = (world_time-phy->enter_time)*time_scale;
    vec2 diff_position = v2_scale(v2_diff(path->end,path->begin),dt*phy->speed);
    phy->position = v2_add(phy->position,diff_position);

}
bool phy_collide(Physics* phy, Physics* phy2);