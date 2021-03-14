/* Copyright 2021 Carlos Pinto Machado */
/* See LICENSE for details */
#include <stdio.h>

#define IN  1   /* inside a word */
#define OUT 0   /* outside a word */

#define MAX_WORD_LENGTH 25

int
main(void) {
    int c, state;
    int i, j;
    int word_lengths[MAX_WORD_LENGTH]; /* array to store lengths */
    int len;

    state = OUT;
    len = 0;

    for (i = 0; i < MAX_WORD_LENGTH; i++) {
        word_lengths[i] = 0;
    }

    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t') {
            if (state == IN) {
                if (len > MAX_WORD_LENGTH) {
                    len = MAX_WORD_LENGTH;
                }
                word_lengths[len - 1]++;
            }
            len = 0;
            state = OUT;
        } else {
            len++;
            state = IN;
        }
    }

    printf("Histogram with word lengths:\n");
    for (i = 0; i < MAX_WORD_LENGTH; i++) {
        if (i < MAX_WORD_LENGTH - 1) {
            printf("%02d  : ", i + 1);
        } else {
            printf("%02d+ : ", i + 1);
        }

        for (j = 0; j < word_lengths[i]; j++) {
            putchar('+');
        }
        printf(" -- %d\n", word_lengths[i]);
    }
    return 0;
}

