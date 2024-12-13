#include <dlfcn.h>
#include <stdio.h>
#include <stdlib.h>

#include "../src/fast_sqrt.h"

float (*fast_sqrt_f) (float);
double (*fast_sqrt_d) (double);

static void* handle;
void setup() {
  char* error;
  handle = dlopen("../build/libfastsqrt.so", RTLD_LAZY);
  if (!handle) {
    fprintf(stderr, "%s\n", dlerror());
    exit(1);
  }
  fast_sqrt_f = dlsym(handle, "fast_sqrtf");
  fast_sqrt_d = dlsym(handle, "fast_sqrtd");
  if ((error = dlerror()) != NULL) {
    fprintf(stderr, "%s\n", error);
    exit(1);
  }
}

void cleanup() {
  if (dlclose(handle) < 0) {
    fprintf(stderr, "%s\n", dlerror());
    exit(1);
  }
}

#include "./testMain.h"