#include <stdio.h>

#define IN 1
#define OUT 0

int main(void) {
  int c, state = OUT;

  while ((c = getchar()) != EOF) {
    if (c == '\n' || c == ' ' || c == '\t') {
      if (state == IN) {
        putchar('\n');
      }
      state = OUT;
    } else {
      state = IN;
      putchar(c);
    }
  }

  if (state == IN) {
    putchar('\n');
  }

  return 0;
}
