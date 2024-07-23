/* Copyright © 2024 cpmachado */
#include <stdio.h>

enum { IN_COMMENT, IN_STRING, NORMAL } States;

int main(void) {
  int c;
  int status = NORMAL;

  while ((c = getchar()) != EOF) {
    switch (status) {
    case NORMAL:
      if (c == '/') {
        if ((c = getchar()) == '*') {
          status = IN_COMMENT;
        } else {
          putchar('/');
        }
      } else if (c == '"') {
        status = IN_STRING;
      }
      if (status != IN_COMMENT && c != EOF) {
        putchar(c);
      }
      break;
    case IN_STRING:
      if (c == '"') {
        status = NORMAL;
      }
      putchar(c);
      break;
    case IN_COMMENT:
      if (c == '*' && (c = getchar()) == '/') {
        status = NORMAL;
      }
    }
  }
  return 0;
}
