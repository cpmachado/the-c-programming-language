/* Copyright © 2024 cpmachado */
#include <stdio.h>

#define IN 1
#define OUT 0
#define MAXLEN 25

int main(void) {
  int c, k = 0, state = OUT;
  int counter[MAXLEN] = {0};

  while ((c = getchar()) != EOF) {
    if (c == '\n' || c == ' ' || c == '\t') {
      if (state == IN) {
        counter[k - 1]++;
        k = 0;
      }
      state = OUT;
    } else {
      state = IN;
      k++;
    }
  }

  if (state == IN) {
    counter[k - 1]++;
    k = 0;
  }

  for (k = 0; k < MAXLEN; k++) {
    if (k + 1 == MAXLEN) {
      printf("%3d+|", k + 1);
    } else {
      printf("%3d |", k + 1);
    }
    for (int j = 0; j < counter[k]; j++) {
      putchar('*');
    }
    printf(" -- %d\n", counter[k]);
  }

  return 0;
}
