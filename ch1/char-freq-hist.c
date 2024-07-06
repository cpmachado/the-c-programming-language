#include <stdio.h>

int main(void) {
  int c;
  int counter[256] = {0};

  while ((c = getchar()) != EOF) {
    counter[c]++;
  }

  for (int i = 0; i < 256; i++) {
    printf("%3d |", i);
    for (int j = 0; j < counter[i]; j++) {
      putchar('*');
    }
    printf(" -- %d\n", counter[i]);
  }

  return 0;
}
