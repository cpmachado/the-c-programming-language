/* Copyright 2021 Carlos Pinto Machado */
/* See LICENSE for details */
#include <stdio.h>

#define ASCII_CHARACTERS 128

int
main(void) {
    int c;
    int i, j;
    int char_freq[ASCII_CHARACTERS]; /* array to characters frequency */

    for (i = 0; i < ASCII_CHARACTERS; i++) {
        char_freq[i] = 0;
    }

    while ((c = getchar()) != EOF) {
        char_freq[c]++;
    }

    printf("Histogram with character frequencies:\n");
    for (i = 0; i < ASCII_CHARACTERS; i++) {
        printf("%03d : ", i);
        for (j = 0; j < char_freq[i]; j++) {
            putchar('+');
        }
        printf(" -- %d\n", char_freq[i]);
    }
    return 0;
}

