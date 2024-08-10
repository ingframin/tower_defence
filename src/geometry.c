#include <math.h>
#include <stdbool.h>
#include "vec2.h"
#include "geometry.h"


Triangle* new_triangle(vec2 A, vec2 B, vec2 C)
{
    Triangle* t = malloc(sizeof(Triangle));
    t->A = A;
    t->B = B;
    t->C = C;
    return t;
}

void delete_triangle(Triangle* t)
{
    free(t);   
}

float Tri_area(Triangle* t)
{
    float ABx = t->B.x - t->A.x;
    float ABy = t->B.y - t->A.y;
    float Axc = t->A.x * t->C.y - t->C.x * t->A.y;
    return fabs(ABy * t->C.x - ABx * t->C.y + Axc) / 2;
}

float Tri_perimeter(Triangle* t)
{
    float ABx = t->B.x - t->A.x;
    float ABy = t->B.y - t->A.y;   
    float Cax = t->C.x - t->A.x;
    float Cay = t->C.y - t->A.y;
    float BCx = t->C.x - t->B.x;
    float BCy = t->C.y - t->B.y;
    return sqrtf(ABx * ABx + ABy * ABy) + sqrtf(Cax * Cax + Cay * Cay) + sqrtf(BCx * BCx + BCy * BCy);
}

bool Tri_is_inside(Triangle* t, vec2 P)
{
    barycoords bc = v2_barycentric(t->A, t->B, t->C, P);
    return bc.alpha >= 0 && bc.beta >= 0 && bc.gamma >= 0;
}

barycoords v2_barycentric(vec2 A, vec2 B, vec2 C, vec2 P)
{
	barycoords bc;
	float ABx = B.x - A.x;
	float ABy = B.y - A.y;
	float Axc = A.x * C.y - C.x * A.y;
	float Cax = C.x - A.x;
	float Cay = C.y - A.y;
	float Px = P.x;
	float Py = P.y;

	bc.gamma = (ABy * Px + ABx * Py + Axc) / (ABy * C.x + ABx * C.y + Axc);
	bc.beta = (Cay * Px + Cax * Py + Axc) / (Cay * B.x + Cax * B.y + Axc);

	bc.alpha = 1 - bc.beta - bc.gamma;

	return bc;
}
