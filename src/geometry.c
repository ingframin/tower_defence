#include <math.h>
#include "vec2.h"
#include "geometry.h"

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
