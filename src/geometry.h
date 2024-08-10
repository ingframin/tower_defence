#ifndef GEOMETRY_H
#define GEOMETRY_H
#include <math.h>
#include "vec2.h"

typedef struct
{
  double alpha;
  double beta;
  double gamma;
} barycoords;

barycoords v2_barycentric(vec2 A, vec2 B, vec2 C, vec2 P);


#endif