/*
Even though it's not usual to put main function in a header,
this removes the duplicate code.
*/

/** setup function for each link_*.c */
void setup();
/** cleanup function for each link_*.c */
void cleanup();

extern float (*inv_sqrt_f) (float);
extern double (*inv_sqrt_d) (double);

#include <stdio.h>

int main() {
    setup();

    float f = 1.0;
    while(1) {
        printf("(1) Input a float number. To quit, enter a number equal or less than 0 : ");
        if(scanf("%f", &f) == EOF) break;
        if(f <= 0) break;
        printf("1/sqrt(%f) == %f\n", f, inv_sqrt_f(f));
    }
    double d = 1.0;
    while(1) {
        printf("(2) Input a double number. To quit, enter a number equal or less than 0 : ");
        if(scanf("%lf", &d) == EOF) break;
        if(d <= 0) break;
        printf("1/sqrt(%lf) == %lf\n", d, inv_sqrt_d(d));
    }

    float x, y, z;
    while(1) {
        printf("(3) Input three float, and I'll normalize the vector.\n");
        printf("(3) To quit, enter either of 3 numbers equal or less than 0 : ");
        if(scanf("%f %f %f", &x, &y, &z) == EOF) break;
        if(x <= 0 || y <= 0 || z <= 0) break;
        float norm = inv_sqrt_f(x*x + y*y + z*z);
        printf("original   vector: (%f, %f, %f)\n", x, y, z);
        printf("normalized vector: (%f, %f, %f)\n", x/norm, y/norm, z/norm);
    }

    cleanup();
    return 0;
}