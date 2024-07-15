#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

extern char *optarg;

#define SPACES_PER_TAB_DEFAULT 4

int main(int argc, char *argv[]) {
  int c;
  int i;
  int opt;
  int spaces_per_tab = SPACES_PER_TAB_DEFAULT;

  while ((opt = getopt(argc, argv, ":n:")) != -1) {
    switch (opt) {
    case 'n':
      spaces_per_tab = atoi(optarg);
      if (spaces_per_tab < 1) {
        printf("Invalid value: %s\n", optarg);
        exit(1);
      }
      break;
    default:
      printf("Invalid flag\n");
      exit(1);
    }
  }

  for (i = 0; (c = getchar()) != EOF;) {
    switch (c) {
    case '\t':
      for (i %= spaces_per_tab; i < spaces_per_tab; i++) {
        putchar(' ');
      }
      break;
    case '\n':
      putchar('\n');
      i = 0;
      break;
    default:
      putchar(c);
      i++;
      break;
    }
  }
  return 0;
}
