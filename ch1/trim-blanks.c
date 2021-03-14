/* Copyright 2021 Carlos Pinto Machado */
/* See LICENSE for details */
#include <stdio.h>

int
main(void) {
    int c, p;

    /* previous char, to control space */
    p = EOF;

    while ((c = getchar()) != EOF) {
        if (c != ' ') {
            putchar(c);
        }
        if (c == ' ') {
            if (c != p) {
                putchar(c);
            }
        }
        p = c;
    }
    return 0;
}

