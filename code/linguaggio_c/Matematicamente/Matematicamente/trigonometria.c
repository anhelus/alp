#include "trigonometria.h"
#include <math.h>
#include <stdio.h>

float seno(float coseno) {
	float sin_quad = 1 - (coseno * coseno);
	printf("%f\n", sin_quad);
	return sqrtf(sin_quad);
}

float coseno(float seno) {
	float cos_quad = 1 - (seno * seno);
	return sqrtf(cos_quad);
}
