#include "fast_invsqrt.h"
#include <stdint.h>

float fast_sqrtf(float f) {
	int32_t i = *(int32_t *)&f;
	i = (i >> 1) + 0x1fbb67ae;
	float f1 = *(float *)&i;
	return 0.5F * (f1 + f / f1); //TODO : more comment
}

double fast_sqrtd(double d) {
	int64_t i = *(int64_t *)&d;
	i = (i >> 1) + 0x1ff76cf5d0b09954;
	double d1 = *(double *)&i;
	return 0.5F * (d1 + d / d1);
}