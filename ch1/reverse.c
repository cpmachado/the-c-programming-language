/* Copyright 2021 Carlos Pinto Machado */
/* See LICENSE for details */
#include <stdio.h>

#define MAXLINE 1000

int getline_book(char line[], int maxline);
void reverse(char line[], int len);

int
main(void) {
    int len;    /* current line length */
    char line[MAXLINE];         /* current input line */

    while ((len = getline_book(line, MAXLINE)) > 0) {
        reverse(line, len - 1);
        printf("%s", line);
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

void reverse(char s[], int len) {
    int i = len - 1;
    int j;
    int c;

    for (j = 0; j < i; j++) {
        c = s[j];
        s[j] = s[i];
        s[i] = c;
        i--;
    }
}

