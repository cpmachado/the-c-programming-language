/* Copyright 2021 Carlos Pinto Machado */
/* See LICENSE for details */
#include <stdio.h>

#define MAXLINE 1000

int getline_book(char line[], int maxline);
void copy(char to[], char from[]);

int
main(void) {
    int len;    /* current line length */
    int max;    /* maximum length seen so far */
    char line[MAXLINE];         /* current input line */
    char longest[MAXLINE];  /* longest line saved here */

    max = 0;
    while ((len = getline_book(line, MAXLINE)) > 0) {
        if (len > max) {
            max = len;
            copy(longest, line);
        }
    }

    if (max > 0) {
        printf("max length: %d\n", max);
        printf("longest: %s", longest);
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

void copy(char to[], char from[]) {
    int i;

    i = 0;
    while ((to[i] = from[i]) != '\0') {
        ++i;
    }
}

