/* Copyright © 2024 cpmachado */
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

#define STR_LEN 1024

void reverse(char *s);
void itoa(int n, char *s, int pad);

int main(void) {
  char rep[STR_LEN];
  int i;

  for (i = 1; i <= 10; i++) {
    itoa(i, rep, 3);
    printf("%d = %s\n", i, rep);
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

void itoa(int n, char *s, int pad) {
  int count = 0;
  int sign = n < 0;
  char *base = s;
  do {
    *s = abs(n % 10) + '0';
    s++;
    count++;
  } while (abs(n /= 10) > 0);
  if (sign) {
    *s = '-';
    s++;
    n++;
  }
  while (count < pad) {
    *s = ' ';
    s++;
    count++;
  }
  *s = '\0';
  reverse(base);
}
