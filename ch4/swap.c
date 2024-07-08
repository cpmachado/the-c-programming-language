/* Copyright © 2024 cpmachado */
#include <stdio.h>

#define swap(t, x, y)                                                          \
  {                                                                            \
    t aux = x;                                                                 \
    x = y;                                                                     \
    y = aux;                                                                   \
  }

int main(void) {
  int x = 1, y = 2;
  printf("(x, y) = (%d, %d)\n", x, y);
  swap(int, x, y);
  printf("(x, y) = (%d, %d)\n", x, y);
  swap(int, x, y);
  printf("(x, y) = (%d, %d)\n", x, y);
  return 0;
}
