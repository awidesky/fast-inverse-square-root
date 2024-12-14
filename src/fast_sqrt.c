#include "fast_sqrt.h"
#include <stdint.h>

float fast_sqrtf(float f) {
	int32_t i = *(int32_t *)&f; //Evil floating-point bit level hacking
	//shift exponent to make it roughly sqrt(x),
	//and add magic number to adjust mantissa and exponent.
	//The magic number is found by minimising error, which is |sqrt(x) - (shift right of x)|
	i = (i >> 1) + 0x1fbb67ae;
	float f1 = *(float *)&i;
	return 0.5F * (f1 + f / f1); //Newton's method 
}

double fast_sqrtd(double d) {
	int64_t i = *(int64_t *)&d;
	i = (i >> 1) + 0x1ff76cf5d0b09954;
	double d1 = *(double *)&i;
	return 0.5F * (d1 + d / d1);
}