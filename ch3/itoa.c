/* Copyright © 2024 cpmachado */
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

#define STR_LEN 1024

void reverse(char *s);
void itoa(int n, char *s);

int main(void) {
  char rep[STR_LEN];

  itoa(INT_MIN, rep);
  printf("%d = %s\n", INT_MIN, rep);

  itoa(INT_MAX, rep);
  printf("%d = %s\n", INT_MAX, rep);

  return 0;
}

void reverse(char *s) {
  char *ptr = s;
  char aux;
  while (*ptr) {
    ptr++;
  }
  ptr--;
  while (s < ptr) {
    aux = *s;
    *s = *ptr;
    *ptr = aux;
    s++;
    ptr--;
  }
}

void itoa(int n, char *s) {
  int sign = n < 0;
  char *base = s;
  do {
    *s = abs(n % 10) + '0';
    s++;
  } while (abs(n /= 10) > 0);
  if (sign) {
    *s = '-';
    s++;
  }
  *s = '\0';
  reverse(base);
}
