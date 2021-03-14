/* Copyright 2021 Carlos Pinto Machado */
/* See LICENSE for details */
#include <stdio.h>

float
fahrToCelsius(float fahr) {
    return (5.0 / 9.0) * (fahr - 32.0);
}

int
main(void) {
    float fahr, celsius;
    int lower, upper, step;

    lower = 0;   /* lower */
    upper = 300; /* upper */
    step = 20;   /* step size */

    /* ----------------- */
    printf("%3s, %6s\n", "F", "C");
    /* ----------------- */
    fahr = lower;
    while (fahr <= upper) {
        celsius = fahrToCelsius(fahr);
        printf("%3.0f, %6.1f\n", fahr, celsius);
        fahr = fahr + step;
    }
    return 0;
}

