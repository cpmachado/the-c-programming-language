/* Copyright © 2024 cpmachado */
#include <ctype.h>
#include <stdio.h>

int htoi(char *s);

int main(void) {
  printf("0xFF = %d\n", htoi("0xFF"));
  printf("0xff = %d\n", htoi("0xff"));
  printf("ff = %d\n", htoi("ff"));
  printf("0XFf = %d\n", htoi("0XFf"));
  return 0;
}

int htoi(char *s) {
  char *ptr = s;
  int sum = 0;
  int val;

  if (*ptr == '0' && tolower(*(ptr + 1)) == 'x') {
    ptr += 2;
  }

  while ((val = tolower(*ptr))) {
    if (!isxdigit(val)) {
      return -1;
    }
    if (isdigit(val)) {
      val -= '0';
    } else {
      val += 10 - 'a';
    }
    sum = sum * 16 + val;
    ptr++;
  }
  return sum;
}
