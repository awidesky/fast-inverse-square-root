#include "../src/fast_sqrt.h"

float (*fast_sqrt_f) (float) = fast_sqrtf;
double (*fast_sqrt_d) (double) = fast_sqrtd;

/**
 * Nothing to do in runtime. Linking is done in compile time.
 */
void setup() {}
void cleanup() {}

#include "./testMain.h"