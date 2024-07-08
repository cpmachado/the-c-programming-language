/* Copyright © 2024 cpmachado */
#include <stdio.h>

unsigned getbits(unsigned x, int p, int n);
unsigned setbits(unsigned x, int p, int n, unsigned y);

int main(void) {
  unsigned x = ~0u;
  unsigned y = 30;
  printf("(%X, %X) - %X\n", x, y, setbits(x, 5, 5, y));
  return 0;
}

unsigned getbits(unsigned x, int p, int n) {
  return (x >> (p + 1 - n)) & ~(~0u << n);
}

unsigned setbits(unsigned x, int p, int n, unsigned y) {
  unsigned y_bits = getbits(y, p, n) << (p + 1 - n);
  unsigned mask = ~(~(~0u << n)) << (p + 1 - n);
  return (x & mask) | y_bits;
}
