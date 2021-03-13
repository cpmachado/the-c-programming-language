/* Copyright 2021 Carlos Pinto Machado */
/* See LICENSE for details */
#include <stdio.h>

int
main(void) {
    float fahr, celsius;
    int lower, upper, step;

    lower = 0;   /* lower */
    upper = 300; /* upper */
    step = 20;   /* step size */

    /* ----------------- */
    printf("%3s, %6s\n", "C", "F");
    /* ----------------- */
    celsius = lower;
    while (celsius <= upper) {
        fahr = (9.0 / 5.0) * celsius + 32.0;
        printf("%3.0f, %6.1f\n", celsius, fahr);
        celsius = celsius + step;
    }
    return 0;
}

