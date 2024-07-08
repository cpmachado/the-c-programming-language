/* Copyright © 2024 cpmachado */
#include <stdio.h>
#include <string.h>

void squeeze(char *s1, char *s2);

int main(void) {
  char text[BUFSIZ];

  strcpy(text, "banana");
  printf("Let us try the string %s without vowels\n", text);
  squeeze(text, "aeiou");
  printf("Result: %s\n", text);
  return 0;
}

void squeeze(char *s1, char *s2) {
  char *w = s1;

  while (*s1) {
    if (!strchr(s2, *s1)) {
      *w = *s1;
      w++;
    }
    s1++;
  }
  *w = '\0';
}
