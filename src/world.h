#ifndef WORLD_H
#define WORLD_H
#include <stdint.h>
#include <stdbool.h>
#include "vec2.h"

typedef enum{
    DEFAULT,
    WATER,
    GRASS,
    TREES,
    SAND,
    SNOW,
    ROAD

}GROUND_TYPE;



typedef struct{
    vec2 begin;
    vec2 end;
    float width;
    float speed_mod;
    GROUND_TYPE gnd_type;
}Segment;

typedef struct{
    vec2 position;
    bool free;
}BuildPoint;


typedef struct {
    float width;
    float height;
    
    vec2* entrances;
    int entrances_count;
    vec2* exits;
    int exits_count;

    Segment* path;
    int segment_count;
    
    BuildPoint* build_points;
    int build_points_count;    
} World;


#endif