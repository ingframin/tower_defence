#ifndef GEOMETRY_H
#define GEOMETRY_H
#include <math.h>
#include <stdbool.h>
#include "vec2.h"

typedef struct
{
  float alpha;
  float beta;
  float gamma;
} barycoords;

typedef struct Triangle
{
  vec2 A;
  vec2 B;
  vec2 C;
} Triangle;

typedef struct{
  vec2 begin;
  vec2 end;
  float width;
  float length;
}Path;

Triangle* new_triangle(vec2 A, vec2 B, vec2 C);
void delete_triangle(Triangle* t);
float Tri_area(Triangle* t);
float Tri_perimeter(Triangle* t);
bool Tri_is_inside(Triangle* t, vec2 P);

barycoords v2_barycentric(vec2 A, vec2 B, vec2 C, vec2 P);


#endif