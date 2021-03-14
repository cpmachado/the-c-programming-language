/* Copyright 2021 Carlos Pinto Machado */
/* See LICENSE for details */
#include <stdio.h>

#define MAXLINE 1000
#define THRESHOLD 80

int getline_book(char line[], int maxline);

int
main(void) {
    int len;    /* current line length */
    char line[MAXLINE]; /* current input line */

    while ((len = getline_book(line, MAXLINE)) > 0) {
        if (len >= THRESHOLD) {
            printf("%s", line);
        }
    }

    return 0;
}

int
getline_book(char s[], int lim) {
    int c, i;

    for (i = 0; (c = getchar()) != EOF && c != '\n'; i++) {
        if (i < lim - 1) {
            s[i] = c;
        }
    }

    if (c == '\n') {
        if (i < lim - 1) {
            s[i] = c;
        }
        ++i;
    }

    if (i < lim) {
        s[i] = '\0';
    } else {
        s[lim - 1] = '\0';
    }
    return i;
}

