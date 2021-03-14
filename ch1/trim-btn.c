/* Copyright 2021 Carlos Pinto Machado */
/* See LICENSE for details */
#include <stdio.h>

#define MAXLINE 1000

int getline_book(char line[], int maxline);
int isBlankTabNewline(int c);
int trim(char line[], int len);

int
main(void) {
    int len;    /* current line length */
    char line[MAXLINE];         /* current input line */

    while ((len = getline_book(line, MAXLINE)) > 0) {
        if (trim(line, len) > 0) {
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

int
isBlankTabNewline(int c) {
    return c == ' ' || c == '\t' || c == '\n';
}

int trim(char s[], int len) {
    int i = len - 1;
    int hasNewl = 0;

    while (i >= 0 && isBlankTabNewline(s[i])) {
        if (s[i] == '\n') {
            hasNewl = 1;
        }
        s[i] = '\0';
        i--;
    }

    if (i < 0) {
        return 0;
    }

    if (hasNewl) {
        i++;
        s[i] = '\n';
    }

    return i;
}
