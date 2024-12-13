/*
Even though it's not usual to put main function in a header,
this removes the duplicate code.
*/

/** setup function for each link_*.c */
void setup();
/** cleanup function for each link_*.c */
void cleanup();

extern float (*fast_sqrt_f) (float);
extern double (*fast_sqrt_d) (double);

#include <stdio.h>

int main() {
    setup();

    float f = 1.0;
    while(1) {
        printf("(1) Input a float number. To quit, enter a number equal or less than 0 : ");
        if(scanf("%f", &f) == EOF) break;
        if(f <= 0) break;
        printf("sqrt(%f) == %f\n", f, fast_sqrt_f(f));
    }
    printf("\n");

    double d = 1.0;
    while(1) {
        printf("(2) Input a double number. To quit, enter a number equal or less than 0 : ");
        if(scanf("%lf", &d) == EOF) break;
        if(d <= 0) break;
        printf("sqrt(%lf) == %lf\n", d, fast_sqrt_d(d));
    }

    cleanup();
    return 0;
}