#include "../src/fast_invsqrt.h"

float (*inv_sqrt_f) (float) = inv_sqrtf;
double (*fast_sqrt_d) (double) = inv_sqrtd;

/**
 * Nothing to do in runtime. Linking is done in compile time.
 */
void setup() {}
void cleanup() {}

#include "./testMain.h"