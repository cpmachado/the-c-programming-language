/* Copyright © 2024 cpmachado */
#include <stdio.h>
#include <string.h>

int any(char *s1, char *s2);

int main(void) {
  char text[BUFSIZ];

  strcpy(text, "banana");
  printf("Let us find the first vowel in the string %s\n", text);
  printf("Result: %d\n", any(text, "aeiou"));
  return 0;
}

int any(char *s1, char *s2) {
  char *base = s1;

  while (*s1) {
    if (strchr(s2, *s1)) {
      return (int)(s1 - base);
    }
    s1++;
  }
  return -1;
}
