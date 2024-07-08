/* Copyright © 2024 cpmachado */
#include <stdio.h>
#include <string.h>

int strrindex(char *s, char *t);

int main(void) {
  char *text = "Ah Love! could you and I with Fate conspire would?";
  char *pattern = "ould";
  printf("%d\n", strrindex(text, pattern));
  return 0;
}

int strrindex(char *s, char *t) {
  int n = strlen(s);
  int nt = strlen(t);
  int i, j;

  if (nt == 0) {
    return n - 1;
  }

  for (i = n - nt; i >= 0; i--) {
    for (j = 0; j < nt && s[i + j] == t[j]; j++) {
    }
    if (j == nt) {
      return i;
    }
  }

  return -1;
}
