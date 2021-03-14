/* Copyright 2021 Carlos Pinto Machado */
/* See LICENSE for details */
#include <stdio.h>

int
main(void) {
    long nb, nt, nn;  /* NOLINT(runtime/int) */
    int c;

    nb = 0;
    nt = 0;
    nn = 0;

    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            nb++;
        }
        if (c == '\t') {
            nt++;
        }
        if (c == '\n') {
            nn++;
        }
    }

    printf("blanks, tabs, newlines\n");
    printf("%ld, %ld, %ld\n", nb, nt, nn);

    return 0;
}

