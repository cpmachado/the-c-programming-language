/* Copyright © 2024 cpmachado */
/* Tests through the whole range of number of elements */
#include <assert.h>
#include <stdio.h>
#include <time.h>

#define N_ELEMS 1000000
#define N_SAMPLES 1000000

int book_binsearch(int x, int v[], int n);
int my_binsearch(int x, int v[], int n);

int main(void) {
  int v[N_ELEMS], x, idx;
  clock_t t, book = 0, own = 0;
  int i;

  printf("Testing %d samples on an array of %d elements\n", N_SAMPLES, N_ELEMS);
  for (i = 0; i < N_ELEMS; i++) {
    x = i;
    t = clock();
    idx = book_binsearch(x, v, N_ELEMS);
    book += clock() - t;
    assert(idx == x);
    t = clock();
    idx = my_binsearch(x, v, N_ELEMS);
    own += clock() - t;
    assert(idx == x);
  }

  printf("On average book solution took %g\n", (double)book / N_ELEMS);
  printf("On average own solution took %g\n", (double)own / N_ELEMS);

  return 0;
}

int book_binsearch(int x, int v[], int n) {
  int low, high, mid;

  low = 0;
  high = n - 1;
  while (low <= high) {
    mid = (low + high) / 2;
    if (x < v[mid]) {
      high = mid - 1;
    } else if (x > v[mid]) {
      low = mid + 1;
    } else {
      return mid;
    }
  }

  return -1;
}

int my_binsearch(int x, int v[], int n) {
  int low, high, mid;

  low = 0;
  high = n - 1;
  while (low + 1 < high) {
    mid = (low + high) / 2;
    if (x < v[mid]) {
      high = mid - 1;
    } else {
      low = mid;
    }
  }
  if (v[low] == x) {
    return low;
  } else if (v[high] == x) {
    return high;
  }

  return -1;
}
