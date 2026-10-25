#ifndef EXTENDED_FN_C
#define EXTENDED_FN_C

#include <stdio.h>
#define println(_string, ...){ \
  printf(_string, ##__VA_ARGS__); \
  printf("\n"); \
}

#endif