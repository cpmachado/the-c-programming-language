/* Copyright © 2024 cpmachado */
#include <stdio.h>

unsigned bitcount(unsigned x);

int main(void) {
  unsigned x = 0xFF;
  printf("%X - %u\n", x, bitcount(x));
  return 0;
}

unsigned bitcount(unsigned x) {
  unsigned b = 0;

  while (x) {
    x &= x - 1;
    b++;
  }
  return b;
}
