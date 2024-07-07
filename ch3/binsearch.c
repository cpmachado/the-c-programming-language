/* Copyright © 2024 cpmachado */
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N_ELEMS 1000000
#define N_SAMPLES 1000000

int book_binsearch(int x, int v[], int n);
int my_binsearch(int x, int v[], int n);
void gen_int_seq(int v[], int n);

int main(void) {
  int v[N_ELEMS], x, idx;
  clock_t t, book = 0, own = 0;
  int i;

  srand(time(NULL));
  gen_int_seq(v, N_ELEMS);
  printf("Testing %d samples on an array of %d elements\n", N_SAMPLES, N_ELEMS);
  for (i = 0; i < N_SAMPLES; i++) {
    x = rand() % N_ELEMS;
    t = clock();
    idx = book_binsearch(x, v, N_ELEMS);
    book += clock() - t;
    assert(idx == x);
    t = clock();
    idx = my_binsearch(x, v, N_ELEMS);
    own += clock() - t;
    assert(idx == x);
  }

  printf("On average book solution took %g\n", (double)book / N_SAMPLES);
  printf("On average own solution took %g\n", (double)own / N_SAMPLES);

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

void gen_int_seq(int v[], int n) {
  for (int i = 0; i < n; i++) {
    v[i] = i;
  }
}
