/* Copyright © 2024 cpmachado */
#include <stdio.h>

unsigned invert(unsigned x, int p, int n);

int main(void) {
  unsigned x = 30;
  printf("%X - %X\n", x, invert(x, 15, 16));
  return 0;
}

unsigned invert(unsigned x, int p, int n) {
  unsigned mask = ~(~0u << n) << (p + 1 - n);
  return x ^ mask;
}
