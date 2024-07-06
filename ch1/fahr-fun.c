#include <stdio.h>

float fahrenheitToCelsius(float fahr) { return (5.0 / 9.0) * (fahr - 32.0); }

int main(void) {
  float fahr, celsius;
  int lower, upper, step;

  lower = 0;
  upper = 300;
  step = 20;

  fahr = lower;
  printf("  C|     F\n");
  printf("----------\n");
  while (fahr <= upper) {
    celsius = fahrenheitToCelsius(fahr);
    printf("%3.0f|%6.1f\n", fahr, celsius);
    fahr = fahr + step;
  }

  return 0;
}
