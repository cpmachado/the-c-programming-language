/* Copyright © 2024 cpmachado */
#include <stdio.h>

unsigned rightrot(unsigned x, int n);

int main(void) {
  unsigned x = 0xFF0000FF;
  printf("%X - %X\n", x, rightrot(x, 16));
  return 0;
}

unsigned rightrot(unsigned x, int n) {
  unsigned n_bits = sizeof(unsigned) * 8;
  unsigned right = x >> n;
  unsigned left = x << (n_bits - n);
  return right | left;
}
