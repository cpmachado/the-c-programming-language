/* Copyright © 2024 cpmachado */
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

#define STR_LEN 1024

void reverse(char *s);
void itob(int n, char *s, int b);

int main(void) {
  char rep[STR_LEN];
  int i;

  for (i = 2; i < 17; i++) {
    itob(INT_MIN, rep, i);
    printf("%d = %s (%d)\n", INT_MIN, rep, i);
    itob(INT_MAX, rep, i);
    printf("%d = %s (%d)\n", INT_MAX, rep, i);
  }

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

void itob(int n, char *s, int b) {
  int sign = n < 0, r;
  char *base = s;
  do {
    r = abs(n % b);
    if (r > 9) {
      *s = r - 10 + 'A';
    } else {
      *s = r + '0';
    }
    s++;
  } while (abs(n /= b) > 0);
  if (sign) {
    *s = '-';
    s++;
  }
  *s = '\0';
  reverse(base);
}
