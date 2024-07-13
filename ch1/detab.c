#include <stdio.h>

#define N 4

int main(void) {
  int c;
  int i;

  while ((c = getchar()) != EOF) {
    if (c == '\t') {
      for (; i < N; i++) {
        putchar(' ');
      }
      i = 0;
    } else {
      putchar(c);
    }
    if (c == '\n') {
      i = 0;
    } else {
      i = (i + 1) % N;
    }
  }
  return 0;
}
