/* Copyright © 2024 cpmachado */
#include <assert.h>
#include <stdio.h>
#include <string.h>

#define STR_LEN 1024

void escape(char *s, char *t);
void unescape(char *s, char *t);

int main(void) {
  char buf[STR_LEN];
  char escaped[STR_LEN];
  char unescaped[STR_LEN];
  char *ptr = buf;
  char *end = buf + STR_LEN - 1;
  int c;

  while ((c = getchar()) != EOF && ptr < end) {
    *ptr = c;
    ptr++;
  }
  *ptr = '\0';
  escape(escaped, buf);
  printf("Escaped, it results in: %s\n", escaped);
  unescape(unescaped, escaped);
  printf("Unscaped again, it results in: %s\n", unescaped);
  assert(strcmp(unescaped, buf) == 0);

  return 0;
}

void escape(char *s, char *t) {
  while (*t) {
    switch (*t) {
    case '\n':
      *s = '\\';
      s++;
      *s = 'n';
      break;
    case '\t':
      *s = '\\';
      s++;
      *s = 't';
      break;
    default:
      *s = *t;
    }
    s++;
    t++;
  }
  *s = '\0';
}

void unescape(char *s, char *t) {
  char ch;
  while (*t) {
    switch (*t) {
    case '\\':
      ch = *(t + 1);
      if (ch == 'n' || ch == 't') {
        t++;
        if (ch == 'n') {
          *s = '\n';
        } else {
          *s = '\t';
        }
        break;
      }
      /* FALLTHROUGH */
    default:
      *s = *t;
    }
    s++;
    t++;
  }
  *s = '\0';
}
