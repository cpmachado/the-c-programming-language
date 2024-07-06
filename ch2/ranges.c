#include <float.h>
#include <limits.h>
#include <stdio.h>

int main(void) {
  printf("INTEGER:\n");
  printf("signed char   = [%d, %d]\n", SCHAR_MIN, SCHAR_MAX);
  printf("unsigned char = [%d, %u]\n", 0, UCHAR_MAX);
  printf("signed short   = [%d, %d]\n", SHRT_MIN, SHRT_MAX);
  printf("unsigned short = [%d, %u]\n", 0, USHRT_MAX);
  printf("signed int   = [%d, %d]\n", INT_MIN, INT_MAX);
  printf("unsigned int = [%u, %u]\n", 0, UINT_MAX);
  printf("signed long   = [%ld, %ld]\n", LONG_MIN, LONG_MAX);
  printf("unsigned long = [%lu, %lu]\n", 0l, ULONG_MAX);

  printf("\nFLOATING POINT:\n");
  printf("float  = [%e, %e]\n", FLT_MIN, FLT_MAX);
  printf("double = [%e, %e]\n", DBL_MIN, DBL_MAX);

  return 0;
}
