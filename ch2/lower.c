/* Copyright © 2024 cpmachado */
#include <stdio.h>

int lower(int ch);

int main(void) {
  printf("lower 'C': '%c'\n", lower('C'));
  return 0;
}

int lower(int ch) { return ch >= 'A' && ch <= 'Z' ? ch - 'A' + 'a' : ch; }
