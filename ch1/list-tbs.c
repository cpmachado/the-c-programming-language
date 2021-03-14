/* Copyright 2021 Carlos Pinto Machado */
/* See LICENSE for details */
#include <stdio.h>

int
main(void) {
    int c, f;

    /* flag for char already printed */
    f = 0;

    while ((c = getchar()) != EOF) {
        if (c == '\t') {
            printf("\\t");
            f = 1;
        }
        if (c == '\b') {
            printf("\\b");
            f = 1;
        }
        if (c == '\\') {
            printf("\\\\");
            f = 1;
        }
        if (f == 0) {
            putchar(c);
        }
        f = 0;
    }
    return 0;
}

