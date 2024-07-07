/* Copyright © 2024 cpmachado */
#include <ctype.h>
#include <stdio.h>

#define STR_LEN 1024

void expand(char *s, char *t);

int main(void) {
  char buf[STR_LEN];
  char expanded[26 * STR_LEN];

  while (fgets(buf, STR_LEN, stdin)) {
    expand(expanded, buf);
    printf("%s", expanded);
  }

  return 0;
}

void expand(char *s, char *t) {
  char *base = t;
  char start, end;

  while ((*s = *t)) {
    if (*t == '-' && t != base) {
      end = *(t + 1);
      if ((islower(start) && islower(end)) ||
          (isupper(start) && isupper(end)) ||
          (isdigit(start) && isdigit(end))) {
        for (start++; start <= end; start++) {
          *s = start;
          s++;
        }
        s--;
        t++;
      }
    }
    start = *t;
    s++;
    t++;
  }
}
