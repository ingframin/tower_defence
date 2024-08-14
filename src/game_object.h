#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H
#include <stdbool.h>
#include <vec2.h>
#include "display.h"
#include "physics.h"

typedef enum objtype
{
    TOWER,
    ENEMY
}objtype;

typedef struct game_object
{

    objtype type;
    Graphics graphics;
    Physics physics;
    bool visible;
    bool active;
    
}GameObject;

void go_move(GameObject* go, const Path* current, const Path* next, uint64_t world_time);



#endif