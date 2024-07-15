/* Copyright © 2024 cpmachado */
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

extern char *optarg;

#define SPACES_PER_TAB_DEFAULT 4

#define BEFORE_START 1
#define AFTER_START 0

int main(int argc, char *argv[]) {
  int c;
  int i;
  int status = BEFORE_START;
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

  while ((c = getchar()) != EOF) {
    if (isblank(c) && status == BEFORE_START) {
      for (i = 0; isblank(c);) {
        if (c == ' ') {
          i++;
        } else {
          i += (spaces_per_tab - i % spaces_per_tab);
        }
        c = getchar();
      }
      while (i >= spaces_per_tab) {
        putchar('\t');
        i -= spaces_per_tab;
      }
      while (i > 0) {
        putchar(' ');
        i--;
      }
      status = AFTER_START;
    }
    putchar(c);
    if (c == '\n') {
      status = BEFORE_START;
    }
  }
  return 0;
}
