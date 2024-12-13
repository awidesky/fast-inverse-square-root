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
#include <math.h>
#include <time.h>
#include <stdint.h>

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
    printf("\n");

    float start, end;
    printf("(3) SpeedTest. it'll loop test sqrt and fast_sqrt with every\n");
    printf("(3) floating point numbers in range of start <= f < end will tested.\"\n");
    printf("(3) Please enter start, end : ");
    int scanret = scanf("%f %f", &start, &end);
    if(scanret == EOF || !(start < end)) {
        printf("(3) Invalid input!\n");
        return 1;
    }

    clock_t begin, timeend;
    float max; // for test
    begin = clock();
    for (int32_t i = *(int32_t*) &start ; i < *(int32_t*) &end ; i++) {
        float re = sqrtf(*(float*) &i);
		if(max < re) max = re;
    }
    timeend = clock();
    printf("%f\n", max);
    double t1 = (double)(timeend - begin) / CLOCKS_PER_SEC;

    begin = clock();
    for (int32_t i = *(int32_t*) &start ; i < *(int32_t*) &end ; i++) {
        float re = fast_sqrt_f(*(float*) &i);
		if(max < re) max = re;
    }
    timeend = clock();
    printf("%f\n", max);
    double t2 = (double)(timeend - begin) / CLOCKS_PER_SEC;

    printf("math.h sqrtf : %lfseconds\n", t1);
    printf("fast   sqrtf : %lfseconds\n", t2);

    cleanup();
    return 0;
}