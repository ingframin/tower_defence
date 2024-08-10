
/* 
Vocabs2 - velocity obstacle for drones simulator
Copyright (C) 2023  Franco Minucci

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#ifndef VEC2_H
#define VEC2_H
#include <stdint.h>
#include <stdlib.h>

typedef struct
{
  float x;
  float y;

} vec2;

typedef struct
{
  int64_t x;
  int64_t y;
} vec2i;


//convert from float to int
vec2i v2i_fromFloat(vec2 v);
//convert from int to float
vec2 v2_fromInt(vec2i v);


//module
float v2_mod(vec2 v);

//rotate
vec2 v2_rotate(vec2 v, float angle);

//rotate PI/2
vec2 v2_rotateLeftHalfPI(vec2 v);
vec2 v2_rotateRightHalfPI(vec2 v);

//rotate PI
vec2 v2_reverse(vec2 v);

//normalize
vec2 v2_normalize(vec2 v);

//Add and subtract
vec2 v2_add(vec2 v1, vec2 v2);
vec2 v2_diff(vec2 v1, vec2 v2);

//dot product
float v2_dot(vec2 v1, vec2 v2);

//add constant to both elements
vec2 v2_addK(vec2 v, float k);

//multiply both elements by k
vec2 v2_scale(vec2 v, float k);

//distance between 2 vectors
float v2_distance(vec2 v1, vec2 v2);

//linear interpolation between 2 points
vec2 v2_lerp(vec2 p1, vec2 p2, float t);

//Quadratic spline
vec2 v2_qspline(vec2 p1, vec2 p2,vec2 p3, float t);

//Cubic spline
vec2 v2_cspline(vec2 p1, vec2 p2, vec2 p3, vec2 p4, float t);

//N-points interpolation
//!!!! Modifies the array vs !!!!
vec2 v2_interpolate(vec2 vs[], size_t vs_len, float t);

//Angle between 2 vectors
float v2_angle_between(vec2 v1, vec2 v2);
#endif
