#include <dlfcn.h>
#include <stdio.h>
#include <stdlib.h>

#include "../src/fast_invsqrt.h"

float (*inv_sqrt_f) (float);
double (*inv_sqrt_d) (double);

static void* handle;
void setup() {
  char* error;
  handle = dlopen("../build/libfastInvsqrt.so", RTLD_LAZY);
  if (!handle) {
    fprintf(stderr, "%s\n", dlerror());
    exit(1);
  }
  inv_sqrt_f = dlsym(handle, "inv_sqrtf");
  inv_sqrt_d = dlsym(handle, "inv_sqrtd");
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